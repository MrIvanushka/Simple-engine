mkdir _BUILD
cd _BUILD

cmake -G "Visual Studio 17 2022" -A x64 ../..

pause
start ENGINE.sln