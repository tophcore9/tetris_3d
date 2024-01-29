tetris3D
---
A simple well-known game: Tetris made in 3D style with Raylib.

---
## How to bulid
### Windows
+ First of all you must have a CMake https://cmake.org/download (at least 3.20 but you can experement with earlier versions in CMakeLists.txt);
+ Next you need to install a compiler (mine is MinGW w64 https://www.mingw-w64.org/downloads/#mingw-builds and I recommend it for this project);
+ Go to the directory with sources;
+ Create a build directory ```mkdir build```;
+ Go to this directory ```cd build```;
+ Set up the CMake project ```cmake -G "<your compiler>" ..```;
+ Build the project ```cmake --build .```;
+ Run the executable and enjoy!

---
## Demo

![2024-01-29-08-00-18](https://github.com/tophcore9/tetris_3d/assets/131613795/18b53f46-92ac-4fff-a0ae-726059ff9740)

---
## Controls
+ ### Game:
  + **Move the figure to the left:** ←
  + **Move the figure to the right:** →
  + **Rotate the figure:** ↑ 
+ ### General:
  + **Quit:** Esc
  + **Pause:** Space

---
## License
This project was developed under the BSD-3-Clause license.
