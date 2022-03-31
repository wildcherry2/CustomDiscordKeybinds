# CustomDiscordKeybinds
## Description
Plugin spawns an executable and connects via pipe. The executable adds a system-level listener for pressing the END key, which signals to the plugin to instantly leave the voice chat you're in, meaning that regardless of whether or not you have the Discord overlay enabled or in a fullscreen application, the keybind will activate. I plan on making the keybind customizable, but for now this is a good solution. Why leaving a voice chat isn't an available keybind is beyond me, but sometimes you need to get out quick

## Installation
Simply drop dbind.exe and BindLeaveVC.plugin.js into your plugin folder. Get files from Releases.

## Usage
Use JS's execFile to spawn the exe and listen for button presses.

## Note about headers
The Keybind.h and Dispatcher.h headers can be used to implement 1 or more custom keybinds at a time that can be clipped onto a BD plugin, the experimental branch currently has an example of how to register multiple keybinds.
