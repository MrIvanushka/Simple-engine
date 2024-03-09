#include "OgreGraphicsProcessor.h"

#include <SDL.h>
#include <Ogre.h>

#ifdef _WINDOWS
#include <SDL_syswm.h>
#endif

using namespace OgreImpl;
using namespace Engine;

void OgreSdlProcessor::initializeGraphics()
{
	// Инициализация видео подсистемы SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Установка видеорежима и одновременное создание окошка 800x600@16 с получением контекста OpenGL
	SDL_Window* screen = SDL_CreateWindow("My Game Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_MINIMIZED | SDL_WINDOW_OPENGL);
	auto context = SDL_GL_CreateContext(screen);

	// Начинаем инициализацию OGRE с создания объекта Root
	Ogre::Root* root = new Ogre::Root();
	// Загружаем плагин-визуализатор OpenGL из текущей папки (или из другого места)
#ifdef _WINDOWS
	root->loadPlugin("./RenderSystem_GL.dll");
#else
	root->loadPlugin("./RenderSystem_GL.so");
#endif
	// Создаём сам визуализатор
	Ogre::RenderSystem* rs = root->getRenderSystemByName("OpenGL Rendering Subsystem");
	// ... делаем его текущим
	root->setRenderSystem(rs);
	// ... и настраиваем видео-режим
	rs->setConfigOption("Full Screen", "no");
	rs->setConfigOption("Video Mode", "800 x 600 16-bit colour");
	// Инициализируем OGRE, но без автоматического создания окна
	root->initialise(false);

	// Устанавливаем параметры создания окна OGRE.
	// Фактически никакого окна не создаётся. Мы просто указываем OGRE, куда
	// ему производить визуализацию
	Ogre::NameValuePairList params;
#ifdef _WINDOWS
	SDL_SysWMinfo info;
	SDL_VERSION(&info.version);
	SDL_GetWindowWMInfo(screen, &info);
	params["externalWindowHandle"] = Ogre::StringConverter::toString(reinterpret_cast<size_t>(screen));
	params["externalGLContext"] = Ogre::StringConverter::toString(reinterpret_cast<size_t>(context));
	params["externalGLControl"] = Ogre::String("True");
#else
	// Под Linux чуть проще
	params["currentGLContext"] = Ogre::String("True");
#endif

	// Создание "виртуального" окна с выбранными параметрами
	Ogre::RenderWindow* wnd = root->createRenderWindow("Main window", 800, 600, false, &params);
	wnd->setVisible(true);

	// Сюда будем складывать очередное событие для обработки
	SDL_Event evt;
	// Да, цикл должен продолжаться
	bool running = true;
	// Основной цикл визуализации
	while (running)
	{
		// Читаем поступившие со времени предыдущего кадра системные события и события ввода
		while (SDL_PollEvent(&evt))
		{
			// Если юзер закрыл окно, прекращаем цикл
			if (evt.type == SDL_QUIT)
				running = false;
		}
		// Отрисовываем один кадр
		root->renderOneFrame();

		// Почему-то необходимость вызывать SDL_GL_SwapBuffers(); есть только в Windows.
		// В Linux прекрасно работает без этого и глючит, если это использовать.
#ifdef _WINDOWS
		SDL_GL_SwapWindow(screen);
#endif
	}
	//in the end
	// 
	// 
	// Удаляем главный объект OGRE, освобождая тем самым все используемые движком ресурсы
	delete root;
	// Закрываем SDL
	SDL_Quit();
}