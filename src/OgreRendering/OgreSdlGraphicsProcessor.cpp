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
	// ������������� ����� ���������� SDL
	SDL_Init(SDL_INIT_VIDEO);

	// ��������� ����������� � ������������� �������� ������ 800x600@16 � ���������� ��������� OpenGL
	SDL_Window* screen = SDL_CreateWindow("My Game Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_MINIMIZED | SDL_WINDOW_OPENGL);
	auto context = SDL_GL_CreateContext(screen);

	// �������� ������������� OGRE � �������� ������� Root
	Ogre::Root* root = new Ogre::Root();
	// ��������� ������-������������ OpenGL �� ������� ����� (��� �� ������� �����)
#ifdef _WINDOWS
	root->loadPlugin("./RenderSystem_GL.dll");
#else
	root->loadPlugin("./RenderSystem_GL.so");
#endif
	// ������ ��� ������������
	Ogre::RenderSystem* rs = root->getRenderSystemByName("OpenGL Rendering Subsystem");
	// ... ������ ��� �������
	root->setRenderSystem(rs);
	// ... � ����������� �����-�����
	rs->setConfigOption("Full Screen", "no");
	rs->setConfigOption("Video Mode", "800 x 600 16-bit colour");
	// �������������� OGRE, �� ��� ��������������� �������� ����
	root->initialise(false);

	// ������������� ��������� �������� ���� OGRE.
	// ���������� �������� ���� �� ��������. �� ������ ��������� OGRE, ����
	// ��� ����������� ������������
	Ogre::NameValuePairList params;
#ifdef _WINDOWS
	SDL_SysWMinfo info;
	SDL_VERSION(&info.version);
	SDL_GetWindowWMInfo(screen, &info);
	params["externalWindowHandle"] = Ogre::StringConverter::toString(reinterpret_cast<size_t>(screen));
	params["externalGLContext"] = Ogre::StringConverter::toString(reinterpret_cast<size_t>(context));
	params["externalGLControl"] = Ogre::String("True");
#else
	// ��� Linux ���� �����
	params["currentGLContext"] = Ogre::String("True");
#endif

	// �������� "������������" ���� � ���������� �����������
	Ogre::RenderWindow* wnd = root->createRenderWindow("Main window", 800, 600, false, &params);
	wnd->setVisible(true);

	// ���� ����� ���������� ��������� ������� ��� ���������
	SDL_Event evt;
	// ��, ���� ������ ������������
	bool running = true;
	// �������� ���� ������������
	while (running)
	{
		// ������ ����������� �� ������� ����������� ����� ��������� ������� � ������� �����
		while (SDL_PollEvent(&evt))
		{
			// ���� ���� ������ ����, ���������� ����
			if (evt.type == SDL_QUIT)
				running = false;
		}
		// ������������ ���� ����
		root->renderOneFrame();

		// ������-�� ������������� �������� SDL_GL_SwapBuffers(); ���� ������ � Windows.
		// � Linux ��������� �������� ��� ����� � ������, ���� ��� ������������.
#ifdef _WINDOWS
		SDL_GL_SwapWindow(screen);
#endif
	}
	//in the end
	// 
	// 
	// ������� ������� ������ OGRE, ���������� ��� ����� ��� ������������ ������� �������
	delete root;
	// ��������� SDL
	SDL_Quit();
}