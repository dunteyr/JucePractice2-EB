/*
  ==============================================================================

    SpectrumComponent.h
    Created: 11 Apr 2023 2:03:09pm
    Author:  dunte

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SpectrumComponent  : public juce::Component, public juce::Timer
{
public:
    SpectrumComponent();
    ~SpectrumComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void pushNextSampleIntoFifo(float sample);
    void timerCallback() override;
    void setFPS(int newFPS);
    void startSpectrum();

    enum
    {
        fftOrder = 11,
        fftSize = 1 << fftOrder,
        scopeSize = 512
    };

private:

    juce::dsp::FFT forwardFFT; //performs the fft
    juce::dsp::WindowingFunction<float> window; //multiplied by audio data to avoid spectral leakage

    float fifo[fftSize]{};
    float fftData[2 * fftSize]{};
    int fifoIndex = 0;                              
    bool nextFFTBlockReady = false;                 
    float scopeData[scopeSize]{};

    int spectrumUpdateFPS = 30;

    void getNextFrameOfSpectrum();
    void drawFrame(juce::Graphics& g);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SpectrumComponent)
};
