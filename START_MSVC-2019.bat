mkdir _BUILD
cd _BUILD

cmake -G "Visual Studio 16 2019" -A x64 ../..

pause
start ENGINE.sln