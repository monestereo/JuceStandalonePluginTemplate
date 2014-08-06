Juce Audio Plugin & Standalone Template
=========

A template for a Juce audio-plugin quickstart

Supported Platforms
-----
Currently this template was only tested on OSX Mavericks.
This should also work on other versions of OSX.

Linux (and maybe Windows) support will follow!

Features
-----
  - quickly create audio-plugins (currently supports VST and AU)
  - fast development workflow with standalone-application

Getting Started
-----

1. clone this repository with submodules `git clone --recursive https://github.com/monestereo/JuceStandalonePluginTemplate`
2. download the VST3 SDK from [Steinberg](http://www.steinberg.net/nc/en/company/developers/sdk_download_portal.html) (you need to register as a developer.. unfortunately I may not redistribute the SDK due to their restrictive license) and place it in `External/VST3SDK` (remove the whitespace)
3. if you are on OSX run `tools/installCoreAudioUtilityClasses` (check the source beforehand. it will ask for your system password for sym-linking to XCode. never trust a script from the Internet)
4. build the Introjucer with `tools/buildAndInstallIntrojucer` and move it to your `/Applications` directory

Building the Standalone Version
-----
Testing your plugin in a DAW is possible but not really fast, as you have to restart your DAW after every change.

For this, you can develop your plugin in the Standalone environment, which shares the source code with the plugin.

To build, simply open the `MyPluginStandalone/Standalone.jucer` file in the Introjucer.

The standalone application currently expects a `sample.wav` in your home directory, which it will play in an endless loop to test your dsp code in the `PluginProcessor.cpp`.

Building the Plugins
----

Open the `MyPlugin/Plugin.jucer` file in the Introjucer.
From there, start XCode and run your build.

thats it... your plugins will be moved to the standard plugin-locations.
