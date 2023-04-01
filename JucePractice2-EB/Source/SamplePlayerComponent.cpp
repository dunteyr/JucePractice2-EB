/*
  ==============================================================================

    SamplePlayerComponent.cpp
    Created: 1 Apr 2023 3:31:22pm
    Author:  dunte

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SamplePlayerComponent.h"

//==============================================================================
SamplePlayerComponent::SamplePlayerComponent(ProjectColors::ColorPalette componentColors) : 
    playButton(juce::ShapeButton("SamplePlayButton", componentColors.normalColour, componentColors.normalColour, componentColors.normalColour))
{
    addAndMakeVisible(playButton);
    playButton.setShape(makePlayButtonShape(true), true, true, false);
    addAndMakeVisible(sampleStatusText);
    sampleStatusText.setText("No sample opened");
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SamplePlayerComponent::~SamplePlayerComponent()
{
}

void SamplePlayerComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

}

void SamplePlayerComponent::resized()
{
    auto area = getLocalBounds();
    

    playButton.setBounds(area.removeFromLeft(getWidth() / 4)); //button takes left quarter of component
    sampleStatusText.setBounds(area); //text takes up remaining space in component

}

juce::Path SamplePlayerComponent::makePlayButtonShape(bool playShape)
{
    //makes triangle play shape
    if (playShape) 
    {
        juce::Path shape;

        shape.addTriangle(0.0, 0.0, 0.0, 4.0, 3.0, 2.0);

        juce::Path roundedShape = shape.createPathWithRoundedCorners(0.5);

        return roundedShape;
    }

    //makes square stop shape
    else if (!playShape)
    {
        juce::Path shape;

        shape.addRectangle(0.0, 0.0, 4.0, 4.0);

        juce::Path roundedShape = shape.createPathWithRoundedCorners(0.5);

        return roundedShape;      
    }
    
}
