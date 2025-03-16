Congratulations! You have already learned how to define variables in C++
and how to interact with the user of the program through the terminal. 
In this lesson, you will continue to study the C++ language
and will learn the following topics:

* Basic control-flow operators: conditionals, switches, and loops.
* Arrays and iteration over their elements.  
* Custom data types: structures and enums.
* Decomposition of programs using functions.

You will learn these concepts by developing a simple 2D game
based on the [SFML](https://www.sfml-dev.org/) graphics library (Simple and Fast Multimedia Library).
But first, you have to install this library on your system.
Please find the installation instructions for your system below.
After installation of the library, you might need to re-load the project.
To do so, please select __File | Reload CMake Project__.

In order to check that you have successfully installed the library, run the program attached to this step. 
You should see a new application window displaying a small planet in the large cosmic space!

To run the game, wait until the `Loading CMake project`
action is completed and then push the `Run` button
(a green triangle button located in the top-right corner).
Please make sure the correct [run configuration](https://www.jetbrains.com/help/clion/run-debug-configuration.html) 
is selected.
You need the "WarmUp-MovingOn-StartTheGame-run" configuration.

### Windows

On Windows, you do not have to do anything — 
the library is going to be installed along with this course itself. 
The library is build from the source code right on your system using the compiler 
[bundled](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html#MinGW) 
with the CLion IDE.
The script to download the sources and build the library is included in the course.

### MacOS

On macOS, please use the [brew](https://brew.sh/) package manager 
to install the `sfml@2` library.

```shell
brew install sfml@2
```

### Ubuntu

On Ubuntu, please use the [apt](https://ubuntu.com/server/docs/package-management) package manager 
to install the `libsfml-dev` library.

```shell
sudo apt install libsfml-dev
```

### Other Linux distributions

Please use the package manager of you distribution to install the SFML library.
