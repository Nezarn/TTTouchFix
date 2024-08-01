# TTTouchFix
A simple universal mod to disable broken touch screen support in Traveller's Tales Lego games that causes stutter.

What this does:
- Disables Touch screen detection

## How to Install
1. Download latest [release](https://github.com/Nezarn/TTTouchFix/releases)
2. Extract dll next to the game's exe (depending on game you need to use x86 or x64 version)

## Building from source
x64:
```
git clone https://github.com/Nezarn/TTTouchFix
cd TTTouchFix
mkdir build && cd build
cmake .. -A x64
cmake --build . --config Release
```
x86:
```
git clone https://github.com/Nezarn/TTTouchFix
cd TTTouchFix
mkdir build && cd build
cmake .. -A Win32
cmake --build . --config Release
```