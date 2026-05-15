cd ..
echo "Removing pre-existing build folder..."
rm -rf build
echo "=======Configuring CMake========"
cmake -B build
echo "Building Targets"
cmake --build build


#Running the example program that I made
cd build/demo
./Demo
