slinx
=====

Slinx is an attempt to make a decent 3D game. It uses C++ and the SDL library.

Installation of SDL
===================

SDL is a cross-platform library, however, its installation and linkage for Windows is far from complicated so we are going straight to the Linux part.

In order to get SDL for Linux, head to [the official website](https://www.libsdl.org/hg.php). 

Firstly, because we need to download the latest version, we're going to install ```Mercurial```. To do so, we will use the default package manager in Linux. 

```sudo apt-get install mercurial```

Secondly, you have to clone it:

```hg clone http://hg.libsdl.org/SDL```

Finally, in order to build it from the source type the following commands:

```
./configure
make
make install
````

Once this is done you are ready to check it out by yourself.
