# drunken_walker

### Stuff left todo.. mvp

..all done..


### Future stuff that's nice to have
 * Walk to the left :)
 * More intelligent decision making on when to 'change lifted leg'
 * Smoother vertical leg movement (perhaps a simple sine instead of current bang-bang)
 * Jumping
 * Obstacles for jumping
 * Some text/ui on screen
 * Modern OpenGL
 * Full screen?
 * More user control
 * More dynamic camera
 * sound effects? :)
 * Finish line vs flappy bird :S
 * Auto-create more terrain on demand


## Build Instructions

* clone the repo
* create a directory inside named target/ 
* cd target
* cmake ../src/
* make on linux || open the generated VS solution on windows


## Build Dependencies
* [CMake](https://cmake.org/) >= 3.1
* make + g++ on linux || vs2015 on windows
Then:
* On Windows: Builds on Visual Studio 2015 without any external dependencies 
* On Ubuntu: Install dependencies listed in deps/ubuntu.sh
* Others: Check CMakelists.txt & contents of deps/ubuntu.sh to figure out what you need

## Bundled Dependencies
* [GLFW](http://www.glfw.org/) for creating an OpenGL capable window
* [GLM](https://github.com/g-truc/glm) for some vector math
* [Easylogging](https://github.com/easylogging/easyloggingpp) for logging
