//
// Created by alain on 07/04/2023.
//

#include "plugboard.h"

char cipher [26] = {'Z', 'P', 'H', 'N', 'M', 'S','W', 'C', 'I', 'Y', 'T', 'Q','E', 'D', 'O', 'B', 'L','R','F', 'K', 'U', 'V', 'G', 'X','J', 'A'};
char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F','G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X','Y', 'Z'};

char plugboard(char letter, bool isItFoward) {
    char returnValue;
    for (int i = 0; i <= 25; i++) {
        char currentValue = isItFoward ? alphabet[i] : cipher[i];
        if (currentValue == letter) {
            returnValue = isItFoward ? cipher[i] : alphabet[i];
            break;
        }
    }
    return returnValue;
}Z