/*
  ==============================================================================

    RoutingComponent.cpp
    Created: 10 Apr 2023 1:20:55pm
    Author:  dunte

  ==============================================================================
*/

#include <JuceHeader.h>
#include "RoutingComponent.h"

//==============================================================================
RoutingComponent::RoutingComponent()
{
    addAndMakeVisible(compSlot1);
    addAndMakeVisible(compSlot2);
    addAndMakeVisible(compSlot3);
    addAndMakeVisible(compSlot4);
    addAndMakeVisible(compSlot5);

}

RoutingComponent::~RoutingComponent()
{
}

void RoutingComponent::paint(juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour(juce::Colours::grey);
    g.drawRect(getLocalBounds(), 1);   // draw an outline around the component

}

void RoutingComponent::resized()
{


}

void RoutingComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{

}

void RoutingComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{

}

void RoutingComponent::releaseResources()
{

}
