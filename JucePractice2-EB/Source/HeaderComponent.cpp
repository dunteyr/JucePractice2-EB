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
    //setting outline colour from the default lookandfeel
    getLookAndFeel().setColour(juce::ComboBox::ColourIds::outlineColourId, headerColors.normalColour);

    addAndMakeVisible(openButton);
    openButton.setButtonText("Open");
    openButton.setColour(juce::TextButton::ColourIds::buttonColourId, headerColors.normalColour);
    openButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, headerColors.normalColour);
    openButton.setConnectedEdges(juce::Button::ConnectedEdgeFlags::ConnectedOnLeft + juce::Button::ConnectedEdgeFlags::ConnectedOnRight);
    openButton.setToggleable(false);
    addAndMakeVisible(clearButton);
    clearButton.setButtonText("Clear");
    clearButton.setColour(juce::TextButton::ColourIds::buttonColourId, headerColors.normalColour);
    clearButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, headerColors.normalColour);
    clearButton.setConnectedEdges(juce::Button::ConnectedEdgeFlags::ConnectedOnLeft + juce::Button::ConnectedEdgeFlags::ConnectedOnRight);
    clearButton.setToggleable(false);
    addAndMakeVisible(settingsButton);
    settingsButton.setButtonText("Settings");
    settingsButton.setColour(juce::TextButton::ColourIds::buttonColourId, headerColors.normalColour);
    settingsButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, headerColors.normalColour);
    settingsButton.setConnectedEdges(juce::Button::ConnectedEdgeFlags::ConnectedOnLeft + juce::Button::ConnectedEdgeFlags::ConnectedOnRight);
    settingsButton.setToggleable(false);

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
    int buttonWidth = 64;

    openButton.setBounds(leftPadding, 0, buttonWidth, getHeight());
    clearButton.setBounds(openButton.getBounds().getRight(), 0, buttonWidth, getHeight());
    settingsButton.setBounds(clearButton.getBounds().getRight(), 0, buttonWidth, getHeight());
    // This method is where you should set the bounds of any child
    // components that your component contains..

}


