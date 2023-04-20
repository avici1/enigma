//
// Created by alain on 12/04/2023.
//

#ifndef ENIGMA_ROTORS_H
#define ENIGMA_ROTORS_H

#include "stdbool.h"

typedef struct response { char outputChar; bool shouldRotate; int newPosition } response;
struct response* rotor(
        char inputChar,
        bool shouldRotate,
        bool IS_ROTOR_STARTING,
        int turnover,
        int startPosition,
        int currentPosition,
        int rotorNumber,
        bool isForward
        );

#endif //ENIGMA_ROTORS_H
