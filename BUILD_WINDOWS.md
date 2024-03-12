# Simple-engine Windows build guide

 1.	Build this project and all submodules like here https://www.youtube.com/watch?v=5Hi24WnbU-s&t=883s
 2.	(optional) $env:path += ";C:\Program Files\cmake\bin"
 3.	cd ogre/_BUILD
 4.	cmake --build . --config Release
 5.	cmake --install . --config Release --prefix C:\Packages\ogre-release\
 6.	cd ../../reactphysics3d/_BUILD
 7.	cmake --build . --config Release
 8.	cmake --install . --config Release --prefix C:\Packages\reactphysics3d-release\

