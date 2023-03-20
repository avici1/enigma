#include <stdio.h>

int startPosition = 0;
char alphabets[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char rotors [5][26] = {
    {'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'J'},
    {'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E'},
    {'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O'},
    {'E', 'S', 'O', 'V', 'P', 'Z', 'J', 'A', 'Y', 'Q', 'U', 'I', 'R', 'H', 'X', 'L', 'N', 'F', 'T', 'G', 'K', 'D', 'C', 'M', 'W', 'B'},
    {'V', 'Z', 'B', 'R', 'G', 'I', 'T', 'Y', 'U', 'P', 'S', 'D', 'N', 'H', 'L', 'X', 'A', 'W', 'M', 'J', 'Q', 'O', 'F', 'E', 'C', 'K'}
    };

int ringPosition = 20;
int ringPositionForDecryption = 20;

/// @brief uses the given letter and finds it's index before returning the character representing the mapping
/// @param entryLetter: char
/// @return New integer value representing the position of the encrypted character.
char rotorEntrySubstitution(char entryLetter, int rotorNumber) {

for (int j=0; j<26; j++){
    printf("%c", rotors[rotorNumber][26 - j]);
    char currentLetter = rotors[rotorNumber][j];
    char currentAlphabet = alphabets[j];
    char selectedLetter = entryLetter;
    char index = j;
        if (alphabets[j] == entryLetter) {
            // int newIndex = i + ringPosition;
            // ringPosition +=1;
            // if (newIndex > 25) {
            //     newIndex = newIndex - 25;
            //     return newIndex;
            // }
            // return newIndex;
            char newValue = rotors[rotorNumber][j];
            int x = 0;
            return rotors[rotorNumber][j];
        }
    }
}

int main() {
   for (int i = 0; i<15; i++) {
    char encrypt = 0;
    printf("Enter a value");
    scanf("%c", &encrypt);
    char newChar = rotorEntrySubstitution(encrypt, 1);
    printf("%c", newChar);
   }
    return 0;
}