#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : colorPalette(), header(HeaderComponent(colorPalette)), samplePlayer(SamplePlayerComponent(colorPalette))
{

    addAndMakeVisible(header);
    addAndMakeVisible(samplePlayer);
    //ProjectColors::ColorPalette colorPalette;
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{

    /*juce::LookAndFeel_V4::ColourScheme colourScheme;
    colourScheme.setUIColour(juce::LookAndFeel_V4::ColourScheme::defaultFill, juce::Colour::Colour(60, 179, 113));
    colourScheme.setUIColour(juce::LookAndFeel_V4::ColourScheme::highlightedFill, juce::Colour::Colour(40, 159, 93));

    juce::LookAndFeel_V4 *lookFeel;
    lookFeel->setColourScheme(colourScheme);
    setLookAndFeel(lookFeel);*/

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    auto area = getLocalBounds();

    int headerHeight = 48;


    header.setBounds(area.removeFromTop(headerHeight)); //Add header to very top

    //split remaining area into 3
    auto leftArea = area.removeFromLeft(getWidth() / 3);
    auto centerArea = area.removeFromLeft(getWidth() / 2);
    auto &rightArea = area;

    samplePlayer.setBounds(leftArea.removeFromTop(getHeight() / 6)); //divide left side into 6 slots and add player at top
}
