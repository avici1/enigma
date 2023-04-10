//
// Created by alain on 07/04/2023.
//

#include "plugboard.h"

char cipher [26] = {'Z', 'P', 'H', 'N', 'M', 'S','W', 'C', 'I', 'Y', 'T', 'Q','E', 'D', 'O', 'B', 'L','R','F', 'K', 'U', 'V', 'G', 'X','J', 'A'};
char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X','Y', 'Z'};

char plugboard(char letter) {
    char returnValue;
    for (int i = 0; i < 25; ++i) {
        if (alphabet[i] == letter) {
            returnValue = cipher[i];
            break;
        }
    }
    return returnValue;
}