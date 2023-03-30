/*
  ==============================================================================

    ColorPalette.h
    Created: 30 Mar 2023 3:54:33pm
    Author:  dunte

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace ProjectColors 
{
    struct ColorPalette
    {
        juce::Colour normalColour = juce::Colour::Colour(60, 179, 113);
        juce::Colour overColour = juce::Colour::Colour(40, 159, 93);
        juce::Colour downColour = juce::Colour::Colour(20, 139, 73);

    };
}

