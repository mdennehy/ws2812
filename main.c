#include <xc.h>
#include <pic18.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ws2812.h"

// subsystem structs
ws2812_ptr          led;


void main() {
    led.r = 0;
    led.g = 255;
    led.b = 255;
    
    while(1) {
        CLRWDT();
        // timing on the WS2812B is very precise. turn off interrupts before talking
        GIE = 0; while (GIE);
        ws2812_send(&led);
        GIE = 1; while (!GIE);
    }
}