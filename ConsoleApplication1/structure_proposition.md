# Structure Proposition

`Main.cpp` is the entry point of the engine
```cpp
void main()
```

## Singletons
`idTime.cpp` has various methods and attributes to measure time
```cpp
float delta
float getElapsedSeconds(bool reset = false)
float getElapsedMs(bool reset = false)
```
`idDisplay.cpp` is in charge of displaying anything in the console
```cpp
int offsetX, offsetY
void Update()
void Clear(int color = 0)
void DrawPixel(int x, int y, int color)
```
`idInput.cpp` can register keys and record their states
```cpp
void Update()
void AddKey(int keyCode)
void RemoveKey(int keyCode)
```
~~`idPhysics.cpp` can be used to detect collisions~~ To be defined
```cpp
```

## Objects
`idSprite.cpp` to load images and draw them in the console
```cpp
void Draw(idDisplay& display, int x, int y, int frame = 0)
```
`idCollider.cpp` to test collisions with other objects
```cpp
bool Collide(idCollider& other, float x, float y, float otherX, float otherY)
```

---
### Notes

Here are some ideas for other objects that would use directly the functionnalities of the ones specified before:
- **Entity**: Has a sprite and a collider. Made to be inherited to add more functionnalities to it
- **Tilemap**: Has a single Sprite and Collider. Uses the spritesheet functionnality of the Sprite to have different tiles, changes the position of the Collider to test for collisions