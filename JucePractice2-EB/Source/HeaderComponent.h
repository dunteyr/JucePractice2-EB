/*
  ==============================================================================

    HeaderComponent.h
    Created: 24 Mar 2023 3:54:48pm
    Author:  dunte

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColorPalette.h"
#include "SamplePlayerComponent.h"

//==============================================================================
/*
*/
class HeaderComponent  : public juce::Component
{
public:
    HeaderComponent(const ProjectColors::ColorPalette & colorPalette, SamplePlayerComponent & mainSamplePlayer);
    ~HeaderComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    std::unique_ptr<juce::FileChooser> chooser;

    SamplePlayerComponent & samplePlayer;

    const ProjectColors::ColorPalette & headerColors;

    juce::TextButton openButton;
    juce::TextButton clearButton;
    juce::TextButton settingsButton;

    void openButtonClicked();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
