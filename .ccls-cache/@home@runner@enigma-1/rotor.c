#include <stdio.h>
#include "rotor.h"
int startPosition = 0;
char alphabets[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char rotors [5][26] = {
        {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'},
        {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'},
        {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'},
        {'E', 'S', 'O', 'V', 'P', 'Z', 'J', 'A', 'Y', 'Q', 'U', 'I', 'R', 'H', 'X', 'L', 'N', 'F', 'T', 'G', 'K', 'D', 'C', 'M', 'W', 'B'},
        {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}
};

int ringPosition = 25;
/// @brief uses the given letter and finds it's index before returning the character representing the mapping
/// @param entryLetter: char
/// @param rotorNumber: int
/// @param notchPosition: int
/// @return rotorResponse include the status 0 or 1
struct rotorResponse rotorEntrySubstitution(char entryLetter, int rotorNumber, int notchPosition) {

    for (int j=0; j<26; j++){
        char currentLetter = rotors[rotorNumber][j];
        char currentAlphabet = alphabets[j];
        char selectedLetter = entryLetter;
        char index = j;
        char newValue;
        struct rotorResponse returnValue;
        if (alphabets[j] == entryLetter) {
            int newIndex = j + ringPosition;
            ringPosition +=1;
            if (newIndex >= 25) {
                newIndex = newIndex - 25;
                ringPosition = 0;
                newValue = rotors[rotorNumber][newIndex];
                printf("\n%c", newValue);
                returnValue.letter = newValue;
                returnValue.status = 1;
                return returnValue;
            }
            newValue = rotors[rotorNumber][newIndex];
            if(newIndex == notchPosition) {
                returnValue.letter = newValue;
                returnValue.status = 1;
                return returnValue;
            }
            returnValue.letter = newValue;
            returnValue.status = 0;
            return returnValue;
        }
    }
}