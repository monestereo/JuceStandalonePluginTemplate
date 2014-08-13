/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_17ABA01F7C81AEB0__
#define __JUCE_HEADER_17ABA01F7C81AEB0__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "FilePlayerProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FilePlayerEditor  : public AudioProcessorEditor,
                          public Timer,
                          public ButtonListener
{
public:
    //==============================================================================
    FilePlayerEditor (FilePlayerProcessor* ownerFilter);
    ~FilePlayerEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    FilePlayerProcessor* getProcessor() const
    {return static_cast <FilePlayerProcessor*>(getAudioProcessor());}

    void setPlayState(bool state);
    void setLoopState(bool state);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> play_pause;
    ScopedPointer<ToggleButton> loop;
    ScopedPointer<TextButton> load_sample;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilePlayerEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_17ABA01F7C81AEB0__
