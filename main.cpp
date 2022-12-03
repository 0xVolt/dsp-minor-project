#include "include/Common.h"

#include <iostream>

#define NUMBER_SAMPLES 2000
#define NUMBER_CHANNELS 2

using namespace std;

int main() {
    float *audioChannels[NUMBER_CHANNELS];

    for (int i = 0; i < NUMBER_CHANNELS; ++i) {
        audioChannels[i] = new float[NUMBER_SAMPLES];
    }

    return 0;
}
