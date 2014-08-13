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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "FilePlayerEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FilePlayerEditor::FilePlayerEditor (FilePlayerProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (play_pause = new TextButton ("play_pause"));
    play_pause->setButtonText (TRANS("play"));
    play_pause->addListener (this);
    play_pause->setColour (TextButton::buttonColourId, Colours::white);
    play_pause->setColour (TextButton::buttonOnColourId, Colour (0xff909090));

    addAndMakeVisible (loop = new ToggleButton ("loop"));
    loop->addListener (this);

    addAndMakeVisible (load_sample = new TextButton ("load_sample"));
    load_sample->setButtonText (TRANS("load sample"));
    load_sample->addListener (this);
    load_sample->setColour (TextButton::buttonColourId, Colours::white);
    load_sample->setColour (TextButton::buttonOnColourId, Colour (0xff909090));

    addAndMakeVisible (bypass = new ToggleButton ("bypass"));
    bypass->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 150);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    loop->setEnabled(false);
    play_pause->setEnabled(false);
    //[/Constructor]
}

FilePlayerEditor::~FilePlayerEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    play_pause = nullptr;
    loop = nullptr;
    load_sample = nullptr;
    bypass = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FilePlayerEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FilePlayerEditor::resized()
{
    play_pause->setBounds (8, 56, 184, 40);
    loop->setBounds (16, 104, 80, 24);
    load_sample->setBounds (8, 8, 184, 40);
    bypass->setBounds (104, 104, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FilePlayerEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    FilePlayerProcessor* filePlayerProcessor = getProcessor();

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == play_pause)
    {
        //[UserButtonCode_play_pause] -- add your button handler code here..
        filePlayerProcessor->togglePlayState();
        //[/UserButtonCode_play_pause]
    }
    else if (buttonThatWasClicked == loop)
    {
        //[UserButtonCode_loop] -- add your button handler code here..
        filePlayerProcessor->setLoop(buttonThatWasClicked->getToggleState());
        //[/UserButtonCode_loop]
    }
    else if (buttonThatWasClicked == load_sample)
    {
        //[UserButtonCode_load_sample] -- add your button handler code here..
        WildcardFileFilter wildcardFilter ("*.wav", String::empty, "Select Sample");

        FileBrowserComponent browser (FileBrowserComponent::openMode|FileBrowserComponent::canSelectFiles,
                                      File::getSpecialLocation(File::userHomeDirectory),
                                      &wildcardFilter,
                                      nullptr);

        FileChooserDialogBox dialogBox ("select your sample",
                                        "choose a sample to test your DSP-Code on",
                                        browser,
                                        false,
                                        Colours::lightgrey);

        if (dialogBox.show())
        {
            File selectedFile = browser.getSelectedFile (0);
            filePlayerProcessor->setFile(selectedFile);
            play_pause->setEnabled(true);
            loop->setEnabled(true);
        }

        //[/UserButtonCode_load_sample]
    }
    else if (buttonThatWasClicked == bypass)
    {
        //[UserButtonCode_bypass] -- add your button handler code here..
        filePlayerProcessor->setParameter(FilePlayerProcessor::Bypass, (buttonThatWasClicked->getToggleState()) ? 1.0f : 0.0f);
        //[/UserButtonCode_bypass]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void FilePlayerEditor::timerCallback()
{
    //FilePlayerProcessor* ourProcessor = getProcessor();
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
}

void FilePlayerEditor::setPlayState(bool state) {
    if (state == true) {
        play_pause->setButtonText("pause");
    } else {
        play_pause->setButtonText("play");
    }
}

void FilePlayerEditor::setLoopState(bool state) {
    loop->setToggleState(state, dontSendNotification);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FilePlayerEditor" componentName=""
                 parentClasses="public AudioProcessorEditor, public Timer" constructorParams="FilePlayerProcessor* ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="200" initialHeight="150">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="play_pause" id="8793480182d1e5df" memberName="play_pause"
              virtualName="" explicitFocusOrder="0" pos="8 56 184 40" bgColOff="ffffffff"
              bgColOn="ff909090" buttonText="play" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="loop" id="2a149b60e2d18533" memberName="loop" virtualName=""
                explicitFocusOrder="0" pos="16 104 80 24" buttonText="loop" connectedEdges="0"
                needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="load_sample" id="837c9b236ae3dc9f" memberName="load_sample"
              virtualName="" explicitFocusOrder="0" pos="8 8 184 40" bgColOff="ffffffff"
              bgColOn="ff909090" buttonText="load sample" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="bypass" id="79d755d9c735f898" memberName="bypass" virtualName=""
                explicitFocusOrder="0" pos="104 104 80 24" buttonText="bypass"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
