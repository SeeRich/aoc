# Build Instructions:
* Need at least LLVM >= 17
* CMake 3.28
* Ninja
* ccache (optional)
* fmt C++ library (brew install fmt)

## Building CMake
* Download and unarchive
```
cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -G Ninja
ninja -C build
sudo ninja -C build install
```