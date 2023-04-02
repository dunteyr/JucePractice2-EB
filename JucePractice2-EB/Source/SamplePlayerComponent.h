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
class SamplePlayerComponent  : public juce::Component
{
public:
    SamplePlayerComponent(ProjectColors::ColorPalette componentColors);
    ~SamplePlayerComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    bool isPlaying = false;

    juce::ShapeButton playButton;
    juce::DrawableText sampleStatusText;

    juce::Path makePlayButtonShape(bool playShape);
    void onPlayButtonClick();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SamplePlayerComponent)
};
