//
// Created by avici1 on 21/03/2023.
//
#include <stdio.h>
#include "rotor.h"
#include "plugboard.h"
#include "reflector.h"

int main () {
    char letter = 'Z';
    char values[7];
    printf("Provide a letter\n");
    scanf("%c", &letter);
    char valueFromPlugBoard = plugboard(letter);
    /*
     * Path: Forward*/

    //Rotor 1
    struct rotorResponse response1 = rotorEntrySubstitution(valueFromPlugBoard, 2, 0, 1, 25, true);
    printf("\n%d %c\n", response1.status, response1.letter);

    //Rotor 2
    struct rotorResponse response2 = rotorEntrySubstitution(response1.letter, 3, 1, response1.status, 25, true);
    printf("\n%c", response2.letter);

    //Rotor 3
    struct rotorResponse response3 = rotorEntrySubstitution(response2.letter, 1, 1, response2.status, 25, true);
    printf("\n%c", response3.letter);

    // Reflector
    char reflectedLetter = reflected(response3.letter, 0);
    printf("\n%c", reflectedLetter);

    /*
     * Path: Backwards */

    // Rotor 3
    struct rotorResponse response3_back = rotorEntrySubstitution(reflectedLetter, 1, 1, 0, 25, false);
    printf("\n%c", response3_back.letter);

    // Rotor 2
    struct rotorResponse response2_back = rotorEntrySubstitution(response3_back.letter, 3, 1, 0, 25, false);
    printf("\n%c", response2_back.letter);

    // Rotor 3
    struct rotorResponse response1_back = rotorEntrySubstitution(response2_back.letter, 2, 0, 0, 25,false);
    printf("\n%c", response1_back.letter);

    // Plugboard.
    printf("==================== %c ===================", reflectedLetter);
    char valueFromPlugBoard_back = plugboard(response1_back.letter);
    printf("\nDecrypted value is %c\n", valueFromPlugBoard_back);
    return 0;
}