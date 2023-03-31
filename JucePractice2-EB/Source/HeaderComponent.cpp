/*
  ==============================================================================

    HeaderComponent.cpp
    Created: 24 Mar 2023 3:54:48pm
    Author:  dunte

  ==============================================================================
*/

#include "HeaderComponent.h"

//==============================================================================
HeaderComponent::HeaderComponent(const ProjectColors::ColorPalette & colorPalette) : 
    headerColors(colorPalette),
    openButton("OpenButton", headerColors.normalColour, headerColors.overColour, headerColors.downColour),
    clearButton("OpenButton", headerColors.normalColour, headerColors.overColour, headerColors.downColour),
    settingsButton("OpenButton", headerColors.normalColour, headerColors.overColour, headerColors.downColour)
{
    addAndMakeVisible(openButton);
    openButton.setShape(makeButtonShape(), true, true, false);
    addAndMakeVisible(clearButton);
    clearButton.setShape(makeButtonShape(), true, true, false);
    addAndMakeVisible(settingsButton);
    settingsButton.setShape(makeButtonShape(), true, true, false);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

HeaderComponent::~HeaderComponent()
{
}

void HeaderComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (headerColors.normalColour);

    g.setColour (headerColors.normalColour);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

}

void HeaderComponent::resized()
{
    int leftPadding = 16;
    int buttonWidth = 48;

    openButton.setBounds(leftPadding, 0, buttonWidth, getHeight());
    clearButton.setBounds(openButton.getBounds().getRight(), 0, buttonWidth, getHeight());
    settingsButton.setBounds(clearButton.getBounds().getRight(), 0, buttonWidth, getHeight());
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

juce::Path HeaderComponent::makeButtonShape()
{
    juce::Path shape;

    shape.addRectangle(0.0, 0.0, 4.0, 4.0);

    return shape;
}
