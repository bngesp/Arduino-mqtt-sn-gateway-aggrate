///home/bele/git/SmartWateringWatererPlatformIO
// Created by bele on 09.12.16.
//

#ifndef GATEWAY_GLOBAL_DEFINES_H
#define GATEWAY_GLOBAL_DEFINES_H

#include <stdint.h>

struct device_address {
    uint8_t bytes[6];  // mac
    device_address(){
        bytes[0] = 0x0;
        bytes[1] = 0x0;
        bytes[2] = 0x0;
        bytes[3] = 0x0;
        bytes[4] = 0x0;
        bytes[5] = 0x0;
    }

    device_address(uint8_t zero,
                   uint8_t one,
                   uint8_t two,
                   uint8_t three,
                   uint8_t four,
                   uint8_t five) {
            bytes[0] = zero;
            bytes[1] = one;
            bytes[2] = two;
            bytes[3] = three;
            bytes[4] = four;
            bytes[5] = five;
    }
};
#endif //GATEWAY_GLOBAL_DEFINES_H
