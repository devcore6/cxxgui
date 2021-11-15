## r38

- Updated shuffle symbol
- Fixed click/hover area position bug

## r37

- Redrawn most symbols to have unified proportions
- Added steppers
- Added method to modify text after creation
- Made destructors free up any remaining textures
- Click/hover/leave handlers now pass relative mouse position too
- Made new test project to showcase all symbols and to showcase how steppers can be used
- Fixed an error that resulted in the destructor of the base view class being called instead of the one of the derived classes

## r36

- Made window flags optional

## r35

- Minor touch ups here and there

## r34

- Massively reduced VRAM usage of symbols.
- Massively reduced compilation time by removing amount of headers included in each file.

## r33

- Fixed a bug in how horizontal and vertical stacks are rendered which resulted in bounding boxes being offset on subsequent items
- Fixed spacing of toggle button (internal circle was overlapping the edges)
- Moved toggle buttons code out of the header file

## r32

- Animations
- Toggle switches
- Added a few more symbols

## r31

- Centered warning symbol
- Fixed size of checkmark symbol
- Fixed font-weight 100 and 200 being inverted
- Added pastel colors
- Slightly altered primary purple
- Redrawed render.1
