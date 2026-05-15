cd ..
rmdir build
cmake -B build
cmake --build build
cd build\demo\Debug
Demo.exe
pause
