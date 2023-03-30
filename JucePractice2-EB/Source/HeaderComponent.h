/*
  ==============================================================================

    HeaderComponent.h
    Created: 24 Mar 2023 3:54:48pm
    Author:  dunte

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MainComponent.h"
#include "ColorPalette.h"

//==============================================================================
/*
*/
class HeaderComponent  : public juce::Component
{
public:
    HeaderComponent(ProjectColors::ColorPalette colorPalette);
    ~HeaderComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
