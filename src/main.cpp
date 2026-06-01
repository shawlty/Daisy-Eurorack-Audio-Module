#include "daisy_seed.h"          // Main Daisy library

using namespace daisy;           // Use Daisy classes without daisy::

DaisySeed hw;                    // Create Daisy hardware object

static float volume = 0.50f;     // 50% volume for safer first audio test

// Audio callback runs continuously
static void AudioCallback(AudioHandle::InputBuffer in,
                          AudioHandle::OutputBuffer out,
                          size_t size) // Number of samples in block
{
    for(size_t i = 0; i < size; i++) // Process every sample
    {
        out[0][i] = in[0][i] * volume; // Left input -> left output

        out[1][i] = in[1][i] * volume; // Right input -> right output
    }
}

int main(void)
{
    hw.Configure(); // Load default hardware settings

    hw.Init();      // Initialize CPU, codec, memory, clocks

    hw.SetAudioBlockSize(48); // Process 48 samples at a time

    hw.SetAudioSampleRate(
        SaiHandle::Config::SampleRate::SAI_48KHZ
    ); // 48,000 samples/sec

    hw.StartAudio(AudioCallback); // Start audio engine

    while(1) // Infinite loop
    {
        // Future:
        // Read pots
        // Update OLED
        // Read encoder
        // Change effects
    }
}