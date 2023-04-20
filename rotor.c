#include <stdio.h>
#include "rotor.h"
int startPosition = 0;
char alphabets_[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                       'H', 'I', 'J', 'K', 'L', 'M', 'N',
                       'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                       'V', 'W', 'X', 'Y', 'Z' };
char rotors_ [5][26] = {
        {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'},
        {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'},
        {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'},
        {'E', 'S', 'O', 'V', 'P', 'Z', 'J', 'A', 'Y', 'Q', 'U', 'I', 'R', 'H', 'X', 'L', 'N', 'F', 'T', 'G', 'K', 'D', 'C', 'M', 'W', 'B'},
        {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}
};

char getNewValueIndex(int rotorNumber, bool isItForward, char newValue, int newIndex, int c) {
    if (isItForward) {
        if(alphabets_[c] == newValue) {
            // Position of the letter after adjusting the offset.
            int currentPosition = c - newIndex;
            if (currentPosition < 25) {
                newIndex = 25 + currentPosition;
            }
            newValue = alphabets_[newIndex];
        }
    } else {
        if(rotors_[rotorNumber][c] == newValue) {
            int currentPosition = c + newIndex;
            if (currentPosition > 25) {
                newIndex = 25 - currentPosition;
            }
            newValue = rotors_[rotorNumber][newIndex];
        }
    }
    return newValue;
}

/// @brief uses the given letter and finds it's index before returning the character representing the mapping
/// @param entryLetter: char
/// @param rotorNumber: int
/// @param notchPosition: int
/// @param shouldRotate: bool
/// @return rotorResponse include the status 0 or 1
struct rotorResponse rotorEntrySubstitution(
        char entryLetter,
        int rotorNumber,
        int notchPosition,
        bool shouldRotate,
        int startPosition,
        bool isItForward
        ) {

    for (int j=0; j<26; j++){
        char currentLetter = isItForward ? rotors_[rotorNumber][j] : alphabets_[j];
        char currentAlphabet = alphabets_[j];
        char selectedLetter = entryLetter;
        char index = j;
        char newValue;
        struct rotorResponse returnValue;
        // Look for the letter in the alphabet
        if (currentLetter == entryLetter) {
            if (startPosition == 25) {
                startPosition = 0;
            } else if(shouldRotate == 1) {
                startPosition +=1;
            }
            // Adjust letter position with offset.
            int newIndex = (j + startPosition) % 26;
            // Get the new value based on orientation of the game i.e. forward or backwards.
            newValue = isItForward ? rotors_[rotorNumber][newIndex] : alphabets_[newIndex];
            // If the rotor has done a full cycle.
//            for(int c = 0; c < 26; c++) {
//                if (isItForward) {
//                    if(alphabets_[c] == newValue) {
//                        // Position of the letter after adjusting the offset.
//                        int currentPosition = c - newIndex;
//                        if (currentPosition < 25) {
//                            newIndex = 25 + currentPosition;
//                        }
//                        newValue = alphabets_[newIndex];
//                        break;
//                    }
//                } else {
//                    if(rotors_[rotorNumber][c] == newValue) {
//                        // Position of the letter after adjusting the offset.
//                        int currentPosition = c + newIndex;
//                        if (currentPosition > 25) {
//                            newIndex = 25 - currentPosition;
//                        }
//                        newValue = rotors_[rotorNumber][newIndex];
//                        break;
//                    }
//                }
//            }
            if(newIndex == notchPosition) {
                returnValue.letter = newValue;
                returnValue.status = 1;
                return returnValue;
            }
//            currentLetter = newValue;
            returnValue.letter = newValue;
            returnValue.status = 0;
            return returnValue;
        }
    }
}