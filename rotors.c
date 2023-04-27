//
// Created by alain on 12/04/2023.
//

#include "rotors.h"
#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

char alphabets[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                       'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char rotors[5][26] = {
        {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'},
        {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'},
        {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'},
        {'E', 'S', 'O', 'V', 'P', 'Z', 'J', 'A', 'Y', 'Q', 'U', 'I', 'R', 'H', 'X', 'L', 'N', 'F', 'T', 'G', 'K', 'D', 'C', 'M', 'W', 'B'},
        {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}
};


char getCharacter(int index, bool isForward, int rotorNumber);
int getIndex(char value, bool isForward, int rotorNumber);

int getW(char value, bool isForward, int rotorNumber){
    // W is the current index
    for (int i = 0; i < 26; i++) {
        if(isForward) {
            if(alphabets[i] == value) return i;
        } else {
            if(rotors[rotorNumber][i] == value) return i;
        }
    }
}

char getCharacter(int index, bool isForward, int rotorNumber) {
        return isForward ? alphabets[index] : rotors[rotorNumber][index];
}

int getIndex(char value, bool isForward, int rotorNumber) {
    for (int i = 0; i < 26; i++) {
        if(isForward) {
            if(alphabets[i] == value) return i;
        } else {
            if(rotors[rotorNumber][i] == value) return i;
        }
    }
}

char getZ(int y, bool isForward, int rotorNumber) {
    // Z is the character at the index of y in the current reference.
    return getCharacter(y, !isForward, rotorNumber);
}
int getI(char z, bool isForward, int rotorNumber) {
   return getIndex(z, isForward, rotorNumber);
}

int getT(int i, int offset, bool isForward) {
    int T = (i-offset)%26;
    if (T < 0) {
        T+=26;
    }
    return T;
}

char getR(int index, bool isForward, int rotorNumber) {
    return getCharacter(index, isForward, rotorNumber);
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
    if (shouldRotate == true) {
        currentPosition_ += 1;
    }

    char b = inputChar;
    int c = currentPosition_;
    char adjustedInput = (char)(((int) b - 65 + c) % 26 + 65);
    int w = getW(adjustedInput, isForward, rotorNumber);
    int T = (w-currentPosition_);
    if (T < 0) {
        T+=26;
    }
    char outputChar = !isForward ? alphabets[T] : rotors[rotorNumber][T];
    response* returnValue = malloc(sizeof (struct response));
    returnValue->shouldRotate = (currentPosition_ == turnover);
    returnValue->outputChar = outputChar;
    returnValue->newPosition = currentPosition_;
    return returnValue;
}

struct response* rotor_forward(
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
    if (shouldRotate == true) {
        currentPosition_ += 1;
    }
    int w = getW(inputChar, isForward, rotorNumber);
    int y = (w + currentPosition_) % 26;
    char z = getZ(y, isForward, rotorNumber);
    int I = getI(z, isForward, rotorNumber);
    int T = getT(I, currentPosition_, isForward);

    char outputChar = getR(T, isForward, rotorNumber);
    printf("%c === %d\n", outputChar, rotorNumber);
    response* returnValue = malloc(sizeof (struct response));
    returnValue->shouldRotate = (currentPosition_ == turnover);
    returnValue->outputChar = outputChar;
    returnValue->newPosition = currentPosition_;
    return returnValue;
}