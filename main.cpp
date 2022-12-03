#include "include/Dsp.h"

#include <iostream>

#define NUMBER_SAMPLES 2000
#define NUMBER_CHANNELS 2

using namespace std;

int main() {
    float *audioChannels[NUMBER_CHANNELS];

    for (int i = 0; i < NUMBER_CHANNELS; ++i) {
        audioChannels[i] = new float[NUMBER_SAMPLES];
    }

    // the difference here is that we don't go through a pointer.
    Dsp::SmoothedFilterDesign<Dsp::RBJ::Design::LowPass, 2> f(1024);
    Dsp::Params params;
    params[0] = 44100; // sample rate
    params[1] = 4000;  // cutoff frequency
    params[2] = 1.25;  // Q
    f.setParams(params);
    f.process(NUMBER_SAMPLES, audioChannels);

    // Dsp::SimpleFilter <Dsp::ChebyshevI::BandStop <3>, 2> f;
    // f.setup (3,    // order
    //         44100,// sample rate
    //         4000, // center frequency
    //         880,  // band width
    //         1);   // ripple dB
    // f.process (NUMBER_SAMPLES, audioChannels);

    return 0;
}
