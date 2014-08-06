Juce Audio Plugin & Standalone Template
=========

A Template for a Juce Audio Plugin Quickstart

Supported Platforms
-----
Currently this Template was only tested on OSX Mavericks.
This should also work on other Versions of OSX.

Linux support will follow!

Features
-----
  - Quickly Create Audio Plugins (currently supports VST and AU)
  - Fast development-workflow with Standalone Application

Getting Started
-----

1. clone this repository with submodules `git clone --recursive https://github.com/monestereo/JuceStandalonePluginTemplate`
2. download the VST3 Sdk from [Steinberg](http://www.steinberg.net/nc/en/company/developers/sdk_download_portal.html) (you need to register as a developer.. unfortunately I may not redistribute the SDK due to their restrictive license) and place it in `External/VST3SDK` (remove the whitespace)
3. if you are on OSX run the `tools/installCoreAudioUtilityClasses` Script (check the source before. it will ask for your system-password for sym-linking to XCode. never trust a script from the internet)
4. Build the Introjucer with `tools/buildAndInstallIntrojucer` and move it to your Applications Directory

Building the Standalone Version
-----
testing your plugin in a DAW is possible but not really fast, because you have to restart your DAW after every change.

For this you can develop and run the Standalone Application.

For this, simply open the "MyPluginStandalone/Standalone.jucer" file in the Introjucer

the Standalone Application currently expects a `sample.wav` in your home-directory, which it will play in an endless loop to test your dsp code in the `PluginProcessor.cpp`

Building the Plugins
----

Open the `MyPlugin/Plugin.jucer` file in the Introjucer.
From there, start XCode and run your Build.

thats it... your plugins will be moved to the standard plugin-locations.
