/*
  ==============================================================================

    SpectrumComponent.cpp
    Created: 11 Apr 2023 2:03:09pm
    Author:  dunte

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SpectrumComponent.h"

//==============================================================================
SpectrumComponent::SpectrumComponent() : 
    forwardFFT(fftOrder),
    window(fftSize, juce::dsp::WindowingFunction<float>::hann) //TODO: Make the windowing function be choosable by user
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SpectrumComponent::~SpectrumComponent()
{
}

void SpectrumComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
    
    g.setColour(getLookAndFeel().findColour(juce::ComboBox::ColourIds::outlineColourId));
    drawFrame(g);
}

void SpectrumComponent::drawFrame(juce::Graphics& g)
{
    for (int i = 1; i < scopeSize; ++i)
    {
        auto width = getLocalBounds().getWidth();
        auto height = getLocalBounds().getHeight();

        //draw line from each sample to the previous one
        g.drawLine({ (float)juce::jmap(i - 1, 0, scopeSize - 1, 0, width),
                              juce::jmap(scopeData[i - 1], 0.0f, 1.0f, (float)height, 0.0f),
                      (float)juce::jmap(i,     0, scopeSize - 1, 0, width),
                              juce::jmap(scopeData[i],     0.0f, 1.0f, (float)height, 0.0f) });
    }
}

void SpectrumComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void SpectrumComponent::timerCallback()
{
    if (nextFFTBlockReady)
    {
        getNextFrameOfSpectrum();
        nextFFTBlockReady = false;
        repaint();
    }
}

void SpectrumComponent::startSpectrum()
{
    int interval = 1000 / spectrumUpdateFPS;
    startTimer(interval);
}

void SpectrumComponent::setFPS(int newFPS)
{
    if (spectrumUpdateFPS != newFPS)
    {
        spectrumUpdateFPS = newFPS;
    }    
}

void SpectrumComponent::pushNextSampleIntoFifo(float sample)
{
    // if the fifo contains enough data, set a flag to say
    // that the next frame should now be rendered..
    if (fifoIndex == fftSize)               
    {
        if (!nextFFTBlockReady)            
        {
            juce::zeromem(fftData, sizeof(fftData)); //clear fftData
            memcpy(fftData, fifo, sizeof(fifo)); //transfer data from fifo to fftData
            nextFFTBlockReady = true; //data can be drawn
        }

        fifoIndex = 0;
    }

    fifo[fifoIndex++] = sample;
}

void SpectrumComponent::getNextFrameOfSpectrum()
{
    // first apply a windowing function to our data
    window.multiplyWithWindowingTable(fftData, fftSize);

    // then render our FFT data..
    forwardFFT.performFrequencyOnlyForwardTransform(fftData);  

    auto mindB = -100.0f;
    auto maxdB = 0.0f;

    for (int i = 0; i < scopeSize; ++i)                         
    {
        auto skewedProportionX = 1.0f - std::exp(std::log(1.0f - (float)i / (float)scopeSize) * 0.2f); //gets logarithmic scale to skew X
        auto fftDataIndex = juce::jlimit(0, fftSize / 2, (int)(skewedProportionX * (float)fftSize * 0.5f)); //constrains X scale of data to log skew I think
        //constrains Y scale of data between 0 and 1 I think
        auto level = juce::jmap(juce::jlimit(mindB, maxdB, juce::Decibels::gainToDecibels(fftData[fftDataIndex])
            - juce::Decibels::gainToDecibels((float)fftSize)),
            mindB, maxdB, 0.0f, 1.0f);

        //feeds data to scope data
        scopeData[i] = level;                                   
    }
}
