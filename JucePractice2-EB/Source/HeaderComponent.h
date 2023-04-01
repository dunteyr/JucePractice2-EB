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

//==============================================================================
/*
*/
class HeaderComponent  : public juce::Component
{
public:
    HeaderComponent(const ProjectColors::ColorPalette & colorPalette);
    ~HeaderComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    const ProjectColors::ColorPalette & headerColors;

    juce::TextButton openButton;
    juce::TextButton clearButton;
    juce::TextButton settingsButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
