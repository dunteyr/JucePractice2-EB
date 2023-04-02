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
    playButton(juce::ShapeButton("SamplePlayButton", componentColors.normalColour, componentColors.overColour, componentColors.downColour))
{
    addAndMakeVisible(playButton);
    playButton.setShape(makePlayButtonShape(true), false, true, false);
    addAndMakeVisible(sampleStatusText);
    sampleStatusText.setText("No sample opened");
    sampleStatusText.setJustification(juce::Justification::centredLeft);
    sampleStatusText.setColour(juce::Colour::fromRGB(255, 255, 255));
    
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

    int buttonPadding = 16;
    int textPadding = 50;
    

    auto buttonArea = area.removeFromLeft(getWidth() / 6); //button takes left sixth of component
    playButton.setBounds(buttonArea.withSizeKeepingCentre(buttonArea.getWidth() - buttonPadding, buttonArea.getHeight() - buttonPadding)); //shrink size by padding amount

    //text takes up remaining space in component with padding
    sampleStatusText.setBounds(area.withSizeKeepingCentre(area.getWidth() - textPadding, area.getHeight() - textPadding));

    /*The text isn't actually drawn to fill the bounds. It is drawn to fill a bounding box that is inside the bounds
    and the bounding box is a parallelogram instead of a rectangle. You can make a parallelogram with a rectangle but it has to be
    of type rectangle<float> where the text componenent bounds are a rectangle<int>. So I made rectangle<float> from the rectangle<int> in order 
    to make the Parallelogram to set the bounding box to the same size as the bounds. Ugh.*/
    sampleStatusText.setBoundingBox
    (
        juce::Parallelogram
        (
            juce::Rectangle<float>
            (
                sampleStatusText.getBounds().getX(), 
                sampleStatusText.getBounds().getY(), 
                sampleStatusText.getWidth(), 
                sampleStatusText.getHeight()
            )
        )
    );

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
