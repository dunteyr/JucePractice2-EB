/*
  ==============================================================================

    SamplePlayerComponent.h
    Created: 1 Apr 2023 3:31:22pm
    Author:  dunte

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColorPalette.h"

//==============================================================================
/*
*/
class SamplePlayerComponent  : public juce::AudioAppComponent, public juce::ChangeListener
{
public:
    SamplePlayerComponent(ProjectColors::ColorPalette componentColors);
    ~SamplePlayerComponent() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void setSampleStatusText(juce::String newText);

    juce::AudioFormatManager formatManager{};
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    juce::AudioTransportSource transportSource;

private:

    //Enum for the state of audio transport
    enum TransportState
    {
        Stopped,
        Starting,
        Playing,
        Stopping
    };

    TransportState currentState;

    juce::ShapeButton playButton;
    juce::DrawableText sampleStatusText;

    TransportState state;

    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

    juce::Path makePlayButtonShape(bool playShape);
    void onPlayButtonClick();
    void changeState(TransportState newState);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplePlayerComponent)
};
