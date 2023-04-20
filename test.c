//
// Created by alain on 14/04/2023.
//
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct {
    char mappedAlphabet[ALPHABET_SIZE];
    int permutation[ALPHABET_SIZE];
    int permutationInverse[ALPHABET_SIZE];
    int startPosition;
    int currentPosition;
    int notchPosition;
} Rotor;

void initializeRotor(Rotor* rotor, char* mapping, int startPosition, int notchPosition) {
    // Copy the mapped alphabet from the input array
    memcpy(rotor->mappedAlphabet, mapping, ALPHABET_SIZE);

    // Initialize the permutation and inverse permutation arrays
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        rotor->permutation[i] = (mapping[i] - 'A') % ALPHABET_SIZE;
        rotor->permutationInverse[rotor->permutation[i]] = i;
    }

    rotor->startPosition = startPosition;
    rotor->currentPosition = startPosition;
    rotor->notchPosition = notchPosition;
}

char forwardPath(Rotor* rotor, char inputChar) {
    // Convert the input character to an index in the rotor's mapped alphabet
    int inputIndex = inputChar - 'A';

    // Apply the rotor's permutation to obtain the output index
    int outputIndex = (rotor->permutation[(inputIndex + rotor->currentPosition) % ALPHABET_SIZE] - rotor->currentPosition + ALPHABET_SIZE) % ALPHABET_SIZE;

    // Map the output index to the corresponding character in the rotor's mapped alphabet
    char outputChar = rotor->mappedAlphabet[outputIndex];

    // Update the rotor's position
    rotor->currentPosition = (rotor->currentPosition + 1) % ALPHABET_SIZE;
    if (rotor->currentPosition == rotor->notchPosition) {
        // Trigger the next rotor to rotate
        return 1;
    } else {
        return 0;
    }
}

char backwardPath(Rotor* rotor, char inputChar) {
    // Convert the input character to an index in the rotor's mapped alphabet
    int outputIndex = inputChar - 'A';

    // Apply the inverse of the rotor's permutation to obtain the input index
    int inputIndex = (rotor->permutationInverse[(outputIndex + rotor->currentPosition) % ALPHABET_SIZE] - rotor->currentPosition + ALPHABET_SIZE) % ALPHABET_SIZE;

    // Map the input index to the corresponding character in the rotor's mapped alphabet
    inputChar = rotor->mappedAlphabet[inputIndex];

    // Update the rotor's position
    rotor->currentPosition = (rotor->currentPosition + 1) % ALPHABET_SIZE;
    if (rotor->currentPosition == rotor->notchPosition) {
        // Trigger the next rotor to rotate
        return 1;
    } else {
        return 0;
    }
}
