## DESCRIPTION
* Uses C++ and the SFML graphics library
* Class hierarchy: 
```
main <- StateController <- State
                           |- StateMenu
                           |- StatePlaying <-------------- Actor
                           |               <- View <-------|
                           |                  |- UserView  |- Character
                           |                  |- AIView    |  |- Enemy
                           |                               |  |- Player
                           |                               |- Wall
                           |                               |- Item
                           |- StatePaused
```

## BUILD/RUN:
* Install dependencies: `make`, `cmake`, `gcc`, `sfml`
* Run:
```shell
git clone https://github.com/GDC-WM/2DGame2021.git
mkdir 2DGame2021/Debug
cd 2DGame2021/Debug
cmake ..
make
./main
```
