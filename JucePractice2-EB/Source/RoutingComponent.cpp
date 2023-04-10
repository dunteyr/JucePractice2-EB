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
    initCompSlot(compSlot1);
    initCompSlot(compSlot2);
    initCompSlot(compSlot3);
    initCompSlot(compSlot4);
    initCompSlot(compSlot5);

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
    auto area = getLocalBounds();

    //chop off upper tenth for padding
    //auto upperPadding = area.removeFromTop(getHeight() / 4);

    //amount to shrink each compSlots bounds by
    int reductionX = (area.getWidth() / 5) / 10;
    int reductionY = (area.getHeight() / 5);

    //for every component slot, give it an equal portion of space. Then shrink it down slightly
    compSlot1.setBounds(area.removeFromLeft(area.getWidth() / 5));
    compSlot1.setBounds(compSlot1.getBounds().reduced(reductionX, reductionY));
    compSlot2.setBounds(area.removeFromLeft(area.getWidth() / 4));
    compSlot2.setBounds(compSlot2.getBounds().reduced(reductionX, reductionY));
    compSlot3.setBounds(area.removeFromLeft(area.getWidth() / 3));
    compSlot3.setBounds(compSlot3.getBounds().reduced(reductionX, reductionY));
    compSlot4.setBounds(area.removeFromLeft(area.getWidth() / 2));
    compSlot4.setBounds(compSlot4.getBounds().reduced(reductionX, reductionY));
    compSlot5.setBounds(area.removeFromLeft(area.getWidth()));
    compSlot5.setBounds(compSlot5.getBounds().reduced(reductionX, reductionY));



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

void RoutingComponent::initCompSlot(juce::ComboBox & slot)
{
    addAndMakeVisible(slot);

    slot.addItem("None", 1);
    slot.addItem("Filter", 2);
    slot.addItem("Reverb", 3);
    slot.addItem("Phaser", 4);
    slot.addItem("Chorus", 5);
    slot.addItem("Compressor", 6);
}
