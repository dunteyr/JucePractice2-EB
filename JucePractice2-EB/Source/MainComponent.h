#pragma once

#include <JuceHeader.h>
#include "HeaderComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

    struct ColorPalette
    {
        juce::Colour normalColour = juce::Colour::Colour(60, 179, 113);
        juce::Colour overColour = juce::Colour::Colour(40, 159, 93);
        juce::Colour downColour = juce::Colour::Colour(20, 139, 73);

    }colorPalette;
private:
    
    //HeaderComponent header;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
