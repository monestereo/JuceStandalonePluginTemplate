/*
  ==============================================================================

    FilePlayerProcessor.h
    Created: 11 Aug 2014 11:24:31am
    Author:  marc

  ==============================================================================
*/

#ifndef FILEPLAYERPROCESSOR_H_INCLUDED
#define FILEPLAYERPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class FilePlayerProcessor  : public AudioProcessor, public drow::AudioFilePlayer::Listener
{
public:
    //==============================================================================
    FilePlayerProcessor();
    ~FilePlayerProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();
    
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    
    //==============================================================================
    bool hasEditor() const;
    
    //==============================================================================
    const String getName() const;
    
    int getNumParameters();
    
    float getParameter (int index);
    void setParameter (int index, float newValue);
    
    const String getParameterName (int index);
    const String getParameterText (int index);
    
    void togglePlayState();
    void setLoop(bool status);
    void setFile(const File &file);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;
    
    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;
    
    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    //==============================================================================
    void fileChanged (drow::AudioFilePlayer* player);
    void playerStoppedOrStarted (drow::AudioFilePlayer* player);
    
    AudioProcessorEditor* createEditor();
private:
    //==============================================================================
    drow::AudioFilePlayer *audioFilePlayer;
    void removePlayer();
    bool playNonLoop = false;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilePlayerProcessor)
    
};

#endif  // FILEPLAYERPROCESSOR_H_INCLUDED
