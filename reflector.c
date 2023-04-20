//
// Created by alain on 07/04/2023.
//
#include "reflector.h"

char reflectors[2][26] = {
        {
            'Y', 'R', 'U', 'H', 'Q', 'S',
              'L', 'D', 'P', 'X', 'N', 'G',
              'O', 'K', 'M', 'I', 'E', 'B',
              'F', 'Z', 'C', 'W', 'V', 'J',
              'A', 'T'
              },
              {
            'F', 'V', 'P', 'J', 'I', 'A',
              'O', 'Y', 'E', 'D', 'R', 'Z',
              'X', 'W', 'G', 'C', 'T', 'K',
              'U', 'Q', 'S', 'B', 'N', 'M',
              'H', 'L'
              }
};

char reflectorAlphabets [26] = { 'A', 'B', 'C', 'D', 'E', 'F',
                            'G', 'H', 'I', 'J', 'K', 'L',
                            'M', 'N', 'O', 'P', 'Q', 'R',
                            'S', 'T', 'U', 'V', 'W', 'X',
                            'Y', 'Z'
};

char reflected(char letter, int reflector) {
    char reflectedLetter = '\0';
    for (int i = 0; i < 25; ++i) {
        if (reflectorAlphabets[i] == letter) {
          reflectedLetter = reflectors[reflector][i];
            break;
        }
    }
    return reflectedLetter;
}