/*
  ==============================================================================

    RoutingComponent.h
    Created: 10 Apr 2023 1:20:55pm
    Author:  dunte

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RoutingComponent  : public juce::AudioAppComponent
{
public:
    RoutingComponent();
    ~RoutingComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

private:

    juce::ComboBox compSlot1;
    juce::ComboBox compSlot2;
    juce::ComboBox compSlot3;
    juce::ComboBox compSlot4;
    juce::ComboBox compSlot5;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RoutingComponent)
};
