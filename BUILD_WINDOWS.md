# Simple-engine Windows build guide

 1.	git clone https://github.com/MrIvanushka/Simple-engine.git
 2.	cd Simple-engine
 3.	git submodule init
 4.	git submodule update
 5.	(optional) $env:path += ";C:\Program Files\cmake\bin"
 6.	mkdir ogre/_BUILD
 7.	cd ogre/_BUILD
 8.	cmake ../
 9.	cmake --build . --config Release
 10.	cmake --install . --config Release --prefix C:\Packages\ogre-release\
 11.	mkdir ../../reactphysics3d/_BUILD
 12.	cd ../../reactphysics3d/_BUILD
 13.	cmake --build . --config Release
 14.	cmake --install . --config Release --prefix C:\Packages\reactphysics3d-release\
 15.	mkdir ../../glm/_BUILD
 16.	cd ../../glm/_BUILD
 17.	cmake --build . --config Release
 18.	cmake --install . --config Release --prefix C:\Packages\glm-release\
 19.	mkdir ../../cegui/_BUILD
 20. add path to libs
 21.	cd ../../cegui/_BUILD
 22.	cmake --build . --config Release
 23.	cmake --install . --config Release --prefix C:\Packages\cegui-release\


