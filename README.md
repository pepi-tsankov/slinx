slinx
=====

Slinx is an attempt to make a decent 3D game. It uses C++ and the SDL library.

Installation of SDL
-------------------

SDL is a cross-platform library, however, its installation and linkage for Windows is far from complicated so we are going straight to the Linux part.

In order to get SDL for Linux, head to [the official website](https://www.libsdl.org/hg.php). 

Firstly, because we need to download the latest version, we're going to install ```Mercurial```. To do so, we will use the default package manager in Linux. 

```sudo apt-get install mercurial```

Secondly, you have to clone it:

```hg clone http://hg.libsdl.org/SDL```

Finally, in order to build it from the source type the following commands:

```
cd SDL
./configure
make
make install
````

Once this is done you are ready to check it out by yourself.

Compiling the game
------------------

#### Dependencies: SDL_TTF
##### SDL_TTF Installation

```
hg clone https://hg.libsdl.org/SDL_ttf/
cd SDL_TTF
./autogen.sh
./configure
make
make install
```

### Building it

At this stage of the project, the compilation is rather simple.

Once you've acquired the SDL library:

```
g++ main.cpp mainWindow.cpp -o slinx -lSDL2 -lSDL2_ttf
```

If you're presented with an error such as

> error while loading shared libraries: libSDL2-2.0.so.0: cannot open shared object file: No such file or directory

make sure the dynamic linkers finds the library. A quick workaround is to simply do:

```sudo /sbin/ldconfig -v```

this should fix the issue. For further info about what ldconfig does, ```man ldconfig```.

Later on, when the project develops, it is highly likely that this method will be replaced by a ```Makefile```, ```CMake``` or by similar approach.