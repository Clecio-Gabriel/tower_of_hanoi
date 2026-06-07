# How to compile using CMake:

- [ 1 ] Depending on your system, you'll need to use this command in
the terminal:
```bash
cmake --preset windows/linux
```

- [ 2 ] Create a build directory using this command in the terminal:
```bash
cmake -S . -B build
```

- [ 3 ] After the build folder is created, to compile, you input this
command in the terminal:
```bash
cmake --build build
```

- [ 4 ] After that, you'll only need to execute the _bin_ file, using
this commmand:
```
./build/hanoi_bin
```