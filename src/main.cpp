#include "daisy_seed.h"          // Main Daisy library

using namespace daisy;           // Use Daisy classes without daisy::

DaisySeed hw;                    // Create Daisy hardware object


// Audio callback runs continuously
static void AudioCallback(AudioHandle::InputBuffer in,
                          AudioHandle::OutputBuffer out,
                          size_t size) // Number of samples in block
{
    for(size_t i = 0; i < size; i++) // Process every sample
    {
        out[0][i] = in[0][i]; // Left input -> Left output

        out[1][i] = in[1][i]; // Right input -> Right output
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