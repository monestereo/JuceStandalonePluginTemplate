/*
  ==============================================================================

    FilePlayerProcessor.cpp
    Created: 11 Aug 2014 11:24:31am
    Author:  marc

  ==============================================================================
*/

#include "FilePlayerProcessor.h"

FilePlayerProcessor::FilePlayerProcessor()
{
    audioFilePlayer = new drow::AudioFilePlayer();
}

FilePlayerProcessor::~FilePlayerProcessor()
{
    audioFilePlayer->releaseResources();
    delete audioFilePlayer;
}

//==============================================================================
const String FilePlayerProcessor::getName() const
{
    return "FilePlayerProcessor";
}

int FilePlayerProcessor::getNumParameters()
{
    return 0;
}

float FilePlayerProcessor::getParameter (int index)
{
    return 0.0f;//invalid index
}

void FilePlayerProcessor::setParameter (int index, float newValue)
{
    return;
}

const String FilePlayerProcessor::getParameterName (int index)
{
    return String::empty;
}

const String FilePlayerProcessor::getParameterText(int index)
{
    return String::empty;}

const String FilePlayerProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String FilePlayerProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool FilePlayerProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool FilePlayerProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool FilePlayerProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool FilePlayerProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool FilePlayerProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double FilePlayerProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FilePlayerProcessor::getNumPrograms()
{
    return 0;
}

int FilePlayerProcessor::getCurrentProgram()
{
    return 0;
}

void FilePlayerProcessor::setCurrentProgram (int index)
{
}

const String FilePlayerProcessor::getProgramName (int index)
{
    return String::empty;
}

void FilePlayerProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FilePlayerProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    initPlayer();
    audioFilePlayer->prepareToPlay(samplesPerBlock, sampleRate);

    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void FilePlayerProcessor::initPlayer() {
    File audioFile ("~/sample.wav");
        
    audioFilePlayer->setFile( audioFile );
    audioFilePlayer->setLooping(true);
    
    audioFilePlayer->start();
}

void FilePlayerProcessor::removePlayer() {
    if (audioFilePlayer != nullptr) {
        audioFilePlayer->stop();
    }
}

void FilePlayerProcessor::releaseResources()
{
    audioFilePlayer->releaseResources();
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void FilePlayerProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    AudioSourceChannelInfo channelInfo(buffer);
    //printf("%f\n", audioFilePlayer->getCurrentPosition());
    if (audioFilePlayer->isPlaying()) {
        audioFilePlayer->getNextAudioBlock(channelInfo);
    } else {
        buffer.clear();
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
bool FilePlayerProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

//==============================================================================
void FilePlayerProcessor::getStateInformation (MemoryBlock& destData)
{
}

void FilePlayerProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

AudioProcessorEditor* FilePlayerProcessor::createEditor() {
    return 0;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createFilePlayerProcessor()
{
    return new FilePlayerProcessor();
}
