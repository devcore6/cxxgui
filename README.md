# CXXGUI

Making GUIs sucks, and I got tired of it. Either you're relying on stupid low-level APIs which are ancient, awful to work with and OS dependent, or you choose to use one of the 10000 ancient GUI libraries which all look like they were made for the 1980s (I'm looking at you, GTK), or you're using Electron, which means a. you're stuck with using HTML & node.js and b. you can say good bye to any performance to speak of.

And thus, CXXGUI was born. The goal was to make something **simple to use**, **powerful** and with great **cross-platform** support, without having to rely on different APIs for each system.

The cross-platform goal is what drove the decision of using OpenGL since it has the best cross-platform support (since Vulkan is still not natively supported on macOS and I wasn't going to make a special version in Metal just for macOS).
