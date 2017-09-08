# lrdynamicarray
A simple implementation of a dynamic array in C

1. Clone repo
2. If using Clion open the repo as a new project. If not then create an empty build directory in the repo folder and run "cmake .." from there
3. Run 'make' from within the build folder. The library will be output as lrdynamicarray.a and the test executable will be testexec.
   Alternatively CLion users can run "Build All" and specify the testexec as the executable

Instructions for use

Currently you cannot delete nodes, you can set them to null using insert but be sure to lrdynamicarray_get the contents and free() before doing so.
The array is implemented with void pointers for flexibility

For sample usage check the test.c file.