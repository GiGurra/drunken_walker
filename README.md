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
* make (or open the generated VS solution if that's your thing)


## Build Dependencies
* [CMake](https://cmake.org/) >= 3.1
Then:
* On Windows: Builds on Visual Studio 2015 without any external dependencies 
* On Ubuntu: Install dependencies listed in deps/ubuntu.sh
* Others: Check CMakelists.txt & contents of deps/ubuntu.sh to figure out what you need
