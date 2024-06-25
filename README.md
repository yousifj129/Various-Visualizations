# Various Visualizations

This program demonstrates algorithms, math concepts, physics phenomena etc.

## Demonstration
https://github.com/sebe324/Various-Visualizations/assets/58781463/09f0a35e-2213-4f29-bb1a-632a0f3df8a9

## How to build
### Qt Creator
- Download Qt Creator: (https://www.qt.io/download-open-source).
- Clone the repository.
- Open the project in the creator.

### With Command line

- Download CMake
- Download Qt libraries (they come together with Qt Creator)
- Download Ninja
- Change the `set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64")` to match your Qt location
- Go to the Qt folder. Go to [version]->mingw_64->bin and add this folder to PATH
- Also add the compiler that comes with Qt to PATH. For example Qt\Tools\mingw1120_64\bin.
- Clone the repository
- In console in the project's directory do:
   `cmake -g "Ninja" .`
   `ninja`


## Technologies used:
  - C++
  - Qt
  - CMake

  
