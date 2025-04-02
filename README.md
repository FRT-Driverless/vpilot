# VPILOT

Virtual representation of a steering wheel board for a Formula SAE car.

## Building from source

```
mkdir build
cd build
cmake -DRENDERER=Raylib ..
cmake --build .
```

Renderers available:
- Raylib
- SDL2

If `SDL2`:
Options:
- VSYNC -> ON | OFF

`IT MAY ASK YOU TO INSTALL SOME OTHER DEPENDENCIES`
