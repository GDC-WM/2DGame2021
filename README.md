## DESCRIPTION
* Uses C++ and the SFML graphics library
* Class hierarchy: 
```
main <- StateController <-> State
                            |- StateMenu
                            |- StatePlaying <-------------- Entity
                            |               <- View <-------|
                            |                  |- AIView  |- Character
                            |                               |  |- Enemy
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
