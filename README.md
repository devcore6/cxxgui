![Logo](cxxgui.png "Logo")

Making GUIs sucks, and I got tired of it. Either you're relying on stupid low-level APIs which are ancient, awful to work with and OS dependent, or you choose to use one of the 10000 ancient GUI libraries which all look like they were made for the 1980s (I'm looking at you, GTK), or you're using Electron, which means a. you're stuck with using HTML & node.js and b. you can say good bye to any performance to speak of.

And thus, CXXGUI was born. The goal was to make something **simple to use**, **powerful** and with great **cross-platform** support, without having to rely on different APIs for each system.

The end goal is to make something incredibly intuitive to work with, while remaining incredibly powerful. The syntax and design was somewhat inspired by [SwiftUI](https://developer.apple.com/xcode/swiftui/), while removing a lot of the limitations I encountered while messing around with SwiftUI.

# Why OpenGL and SDL?

OpenGL and SDL are convenient and easy to work with when getting started, which is why I am using both of them for the beginning, while the library is still heavily under development. Eventually, CXXGUI will transition to Vulkan and Metal.

# Devices support?

The goal of CXXGUI is to work on **every** platform, or at least on MOST of the common platforms. Currently there is Windows, Linux and macOS support, but as the library progresses I will add support for iOS, watchOS, tvOS, and eventually even Android. Is it necessary to add support for these mobile devices? Probably not, as there are already good app development frameworks for them (at least on the Apple side, I have no idea about the Android development side), but I still believe it would be convenient to be able to have the exact same code for your app on every device.

# Documentation

Documentation coming in the future once the project has progressed farther.

## Colors

CXXGUI comes with a wide array of predefined colors to make it easier for you to come up with your own unique color scheme. You can of course also use any custom color you want.

![Colors](colors.svg "Colors")

## Symbols

There are currently 128 symbols, but more will be added as development continues. Each symbol can be customized in color, size, thickness and rendering mode.

### Current symbols list

![ui_base](ui_base.png "ui_base")
![ui_devices](ui_devices.png "ui_devices")
![media_controls](media_controls.png "media_controls")

## Inputs

Currently, there are 2 input methods, with more under development.

The currently working input methods are:

 - Toggle switches
 - Steppers

Input methods that still need to be implemented:

 - Pickers
 - Sliders
 - Date pickers
 - Color pickers
 - Text fields
 - Secure text fields
 - Text editors

![inputs](inputs.png "inputs")

# Notes for macOS users

M1 support is coming - currently, I'm waiting for SDL2_image and SDL2_ttf to be ported to M1, if this doesn't happen soon I will port them myself.

# Notes for Linux users

Since Linux doesn't have a standardized system font across all distros, and since I am not going to use a different font library just to accomodate Linux users better, CXXGUI uses DejaVu Sans and DejaVu Sans Mono on Linux as default font (this is also the default font on Ubuntu), as such, you're going to have to install those two fonts if you don't have them.

Alternatively, I'd just reccomend downloading [SF Pro Text](https://devimages-cdn.apple.com/design/resources/download/SF-Pro.dmg) and [SF Mono](https://devimages-cdn.apple.com/design/resources/download/SF-Mono.dmg) from [Apple's Website](https://developer.apple.com/fonts/) as they are honestly better fonts, and come in all weights. They come in DMG images, which can easily be mounted on Linux and the fonts can then be extracted from the .pkg inside, which is a XAR archive, which then contains the .otf fonts.
