# Shadertoy

This project is a ShaderToy clone created for learning and practicing shaders. 
It features hot reloading, allowing you to see changes to the shader in real time without needing to restart the program. This project serves as an interactive way to experiment with GLSL shaders and explore different visual effects.

## Features

* **Real-time shader updates**: Hot reloading allows you to see changes instantly in the shader without restarting the program.
* **Custom shader editing**: Easily modify shaders to test new effects and learn GLSL syntax.
* **Simple setup**: Minimal configuration to get started, with just a few steps.

<p align="center">
  <img src="https://github.com/user-attachments/assets/16a61033-e2b1-49b2-b18b-04d0e778fb02">
</p>

## Setup

### Clone the repository

Open your terminal and run the following command:

```bash
git clone https://github.com/sengeki1/shadertoy-project.git
```

### Install dependencies

Ensure you have the necessary dependencies installed. For this project, you'll need:

* GLFW: For windowing and input handling.
* GLAD: For loading OpenGL extensions.
* GLM: For math operations.
  
If you’re using a package manager like vcpkg or brew, you can install these libraries with:

```bash
vcpkg install glfw3 glad glm
```

### Open the project in VS Code

Launch VS Code and open the project folder you just cloned.

### Modify the shader

Navigate to the **default.frag** file inside the project folder at the directory **Shaders**. This file contains the default fragment shader.

* Modify the shader code inside the **main()** function to see the effects in real time.
* When you make changes to **default.frag**, the shader will automatically reload, and you’ll see the updates immediately in the running program.

### Run the program

You can compile and run the project directly from **VS Code**. Use the integrated terminal to run the build commands:

```bash
mkdir build
cd build
cmake ..
make
./shadertoy
```

This will compile the project and run the executable. The window will display your shader, and any changes you make to **default.frag** will be reflected instantly.

# Contributing

Feel free to fork the repository, make your changes, and create a pull request! If you have any questions or suggestions, open an issue and I’ll be happy to help.
