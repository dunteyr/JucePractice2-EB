#pragma once

#include <JuceHeader.h>
#include "HeaderComponent.h"
#include "ColorPalette.h"
#include "SamplePlayerComponent.h"
#include "RoutingComponent.h"
#include "SpectrumComponent.h"

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


private:

    ProjectColors::ColorPalette colorPalette;
    HeaderComponent header;
    SpectrumComponent spectrumComp;
    SamplePlayerComponent samplePlayer;
    RoutingComponent routingComp;
    

    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
