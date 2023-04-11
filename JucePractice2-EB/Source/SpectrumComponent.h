/*
  ==============================================================================

    SpectrumComponent.h
    Created: 11 Apr 2023 2:03:09pm
    Author:  dunte

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SpectrumComponent  : public juce::Component
{
public:
    SpectrumComponent();
    ~SpectrumComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectrumComponent)
};
