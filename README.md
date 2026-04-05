# Terrain Generator

A procedural terrain generation tool written in C++. This project demonstrates core Object-Oriented Programming (OOP) concepts by encapsulating Perlin noise generation and map management logic, utilizing a custom `Makefile` for streamlined compilation.

## 🏗️ Project Structure

The codebase is modularized to separate the mathematical noise generation from the map handling:

* **`main.cpp`**: The entry point of the program.
* **`Perlin_Noise.h` & `.cpp`**: Contains the core algorithm and state for generating 2D Perlin noise.
* **`Map_gen.h` & `.cpp`**: Handles the logic for utilizing the generated noise to create, scale, and output the final terrain map.
* **`Makefile`**: Compilation rules to build the executable efficiently without manual linking.

## ⚙️ Building the Project

Since the project uses a `Makefile`, compiling it from source is straightforward. 

1. Ensure you have a standard C++ compiler (e.g., `g++` or `clang++`) and `make` installed on your system.
2. Clone the repository and open your terminal in the project directory.
3. Run the build command:

    ```bash
    make
    ```

This will compile the `.cpp` files into object files and link them into a final executable.

## 🚀 Usage

After a successful build, run the generated binary. *(Note: If your Makefile defines a specific output name like `terrain_gen`, use that instead of `main`)*.

```bash
./main
