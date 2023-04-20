//
// Created by alain on 12/04/2023.
//

#include "rotors.h"
#include "stddef.h"
#include "stdlib.h"

char alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                       'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char rotors[5][26] = {
        {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'},
        {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'},
        {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'},
        {'E', 'S', 'O', 'V', 'P', 'Z', 'J', 'A', 'Y', 'Q', 'U', 'I', 'R', 'H', 'X', 'L', 'N', 'F', 'T', 'G', 'K', 'D', 'C', 'M', 'W', 'B'},
        {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}
};


char getCharacter(bool isForward, int rotorNumber);

char getW(char input, bool isForward, int rotorNumber){
    // W is the current index
    return getCharacter(isForward, rotorNumber);
}

char getCharacter(bool isForward, int rotorNumber) {
    for (int i=0; i < 26; i++) {
        return isForward ? alphabets[i] : rotors[rotorNumber][i];
    }
}

int getY(int w, int offset) {
    // Y is the adjusted index of the current letter;
    return w + offset;
}

char getZ(int y, bool isForward, int rotorNumber) {
    // Z is the character at the index of y in the current reference.
    return getCharacter(isForward, rotorNumber);
}

struct response* rotor(
        char inputChar,
        bool shouldRotate,
        bool IS_ROTOR_STARTING,
        int turnover,
        int startPosition,
        int currentPosition,
        int rotorNumber,
        bool isForward
        ) {
    int currentPosition_ = IS_ROTOR_STARTING ? startPosition : currentPosition;
    int outputIndex;
    if (shouldRotate == true) {
        currentPosition_ += 1;
    }
    for(int i =0; i<26; i++) {
        if (rotors[rotorNumber][i] == inputChar) {
            outputIndex = isForward ? (i+currentPosition_) % 26 : (currentPosition_ - i) %26;
        }
    }
    char outputChar = rotors[rotorNumber][outputIndex];
    response* returnValue = malloc(sizeof (struct response));
    returnValue->shouldRotate = (currentPosition_ == turnover);
    returnValue->outputChar = outputChar;
    returnValue->newPosition = currentPosition_;
    return returnValue;
}