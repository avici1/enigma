#include <stdio.h>

int startPosition = 0;
char alphabets [25] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char rotors [5][26] = {
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
    "VZBRGITYUPSDNHLXAWMJQOFECK"
    };

int ringPosition = 20;
int ringPositionForDecryption = 20;

/// @brief uses the given letter and finds it's index before returning the character representing the mapping
/// @param entryLetter: char
/// @return New integer value representing the position of the encrypted character.
char rotorEntrySubstitution(char entryLetter, int rotorNumber) {

for (int j=0; j<25; j++){
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
   for (int i = 0; i<5; i++) {
    char encrypt = 0;
    printf("Enter a value\n");
    scanf("%c", &encrypt);
    char newChar = rotorEntrySubstitution(encrypt, 1);
    printf("%c", newChar);
   }
    return 0;
}