#include "mbed.h"

// Initialise D2 as an OPEN DRAIN output
// It can be used in the same way as a normal DigitalOut
DigitalInOut sig(D2, PIN_OUTPUT, OpenDrain, 0);

int main()
{
    while(true) {
        for (int pulseWidth = 1000; pulseWidth < 2000; pulseWidth += 10) {
            // Send servo pulse
            sig = true;
            wait_us(pulseWidth);
            sig = false;
            
            // Wait for approx. 20ms
            thread_sleep_for(20);
        }
    }
}
