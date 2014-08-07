/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyPluginAudioProcessor::MyPluginAudioProcessor()
{
    UserParams[ExampleParam]=0.0f; //default
    UIUpdateFlag=true; //Request UI update
}

MyPluginAudioProcessor::~MyPluginAudioProcessor()
{
}

//==============================================================================
const String MyPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int MyPluginAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float MyPluginAudioProcessor::getParameter (int index)
{
    switch(index)
    {
        case ExampleParam://example nothing special
            return UserParams[ExampleParam];
        default:
            return 0.0f;//invalid index
    }
}

void MyPluginAudioProcessor::setParameter (int index, float newValue)
{
    switch(index)
    {
        case ExampleParam:
            UserParams[ExampleParam]=newValue;
            break;
        default:
            return;
    }
    UIUpdateFlag=true;//Request UI update -- Some OSX hosts use alternate editors, this updates ours
}

const String MyPluginAudioProcessor::getParameterName (int index)
{
    switch(index)
    {
        case ExampleParam:
            return "Example Param";
        default:
            return String::empty;
    }
}

const String MyPluginAudioProcessor::getParameterText(int index)
{
    if(index >= 0 && index < totalNumParams) {
        return String(UserParams[index]); //return parameter value as string
    } else {
        return String::empty;
    }
}

const String MyPluginAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String MyPluginAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool MyPluginAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool MyPluginAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool MyPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MyPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MyPluginAudioProcessor::silenceInProducesSilenceOut() const
{
    return true;
}

double MyPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MyPluginAudioProcessor::getNumPrograms()
{
    return 0;
}

int MyPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MyPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String MyPluginAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void MyPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MyPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MyPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void MyPluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);
        
        // ..do something to the data...
        for (int i = 0; i < buffer.getNumSamples(); i++) {
            // .. this loop is for iterating over all samples
        }
    }

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool MyPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MyPluginAudioProcessor::createEditor()
{
    return new MyPluginPluginEditor(this);
}

//==============================================================================
void MyPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    XmlElement root("Root");
    XmlElement *el;
    el = root.createNewChildElement("ExampleParam");
    el->addTextElement(String(UserParams[ExampleParam]));
    copyXmlToBinary(root,destData);
}

void MyPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    XmlElement* pRoot = getXmlFromBinary(data,sizeInBytes);
    if(pRoot != NULL)
    {
        forEachXmlChildElement((*pRoot),pChild)
        {
            if(pChild->hasTagName("ExampleParam")) {
                String text = pChild->getAllSubText();
                setParameter(ExampleParam, text.getFloatValue());
            }
        }
        delete pRoot;
        UIUpdateFlag=true; //Request UI update
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyPluginAudioProcessor();
}
