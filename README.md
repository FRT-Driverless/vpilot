# VPILOT

Virtual representation of a steering wheel board for a Formula SAE car.

## Building from source

> [!IMPORTANT]
> IT MAY ASK YOU TO INSTALL SOME OTHER DEPENDENCIES

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
- VSYNC -> ON | OFF
