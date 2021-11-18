## r40

- Flipped the colors of volume_0 to match everything else

## r39

- Added way more symbols
- Added hierarchical symbol rendering mode
- Made symbol weight customizable to any value
- Changed symbols aspect ratio from 1:1 to 3:2
- Redrawn all symbols to match new aspect ratio
- Periodically check for dark mode / accent color updates
- Removed some old symbols temporarily, these will be brought back soon in the new aspect ratio

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
