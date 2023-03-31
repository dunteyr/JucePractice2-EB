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
    headerColors(colorPalette)
{
    //addAndMakeVisible(headerPanel);
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
    //headerPanel.setBounds(0, 0, getWidth(), getHeight());
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
