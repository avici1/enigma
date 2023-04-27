#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <stdio.h>
#include <stdbool.h>

typedef struct rotorResponse { bool status; char letter };
struct rotorResponse rotorEntrySubstitution(char entryLetter, int rotorNumber, int notchPosition);

#endif