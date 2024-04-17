# Various Visualizations

This program demonstrates algorithms, math concepts, physics phenomena etc.
The project is currently in it's early stages.

## Demonstration
https://github.com/sebe324/Various-Visualizations/assets/58781463/09f0a35e-2213-4f29-bb1a-632a0f3df8a9

## How to build
### Qt Creator - easy way
- Download Qt Creator: (https://www.qt.io/download-open-source).
- Clone the repository.
- Open the project in the creator.
### With Command line
This can get a bit complicated, but here is a short guide.

- Download CMake
- Download Qt libraries (they come together with Qt Creator)
- Download Ninja
- Change the `set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/mingw_64")` to match your Qt location
- Make sure to use the correct compiler.
- Go to the Qt folder. Go to [version]->mingw_64->bin and add this folder to PATH
- Also add the compiler that comes with Qt to PATH. For example Qt\Tools\mingw1120_64\bin.
- Clone the repository
- In console in the project's directory do:
   `cmake -g "Ninja" .`
   `ninja`
- If everything worked correctly it should work!
## To-do list
- #### Sorting algorithms:
  - Bubble sort ✔️
  - Insertion sort ✔️
  - Selection sort ✔️
  - Merge sort ✔️
  - Quick sort ✔️
- #### Collision detection:
  - Axis Aligned Bounding Box ❌
  - Separated Axis Theorem ❌
  - Circle vs Circle ❌
  - Circle vs Edges ❌
- #### Shortest way
  - Dijkstra ❌
  - A* ❌
  - Bellman-Ford ❌
  - Floyd-Warshall ❌
- #### Function graphing
  - f(x) function ❌
  - f(x,y) function ❌
  - Quadratic function ❌
- #### And much more!
## Technologies used:
  - C++
  - Qt
  - CMake
## Contributing:
  There are many algorithms to implement, a lot of code to improve and documentation to add, that's why your help is needed!
  If you'd like to contribute, checkout this project's contributing guidelines. (They don't exist yet lol)
  In case you noticed a bug please open an issue so it can be fixed.
  
  
