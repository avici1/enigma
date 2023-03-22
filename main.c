//
// Created by avici1 on 21/03/2023.
//
#include <stdio.h>
#include "rotor.h"


int main () {
    char letter = 'Z';
    char values[7];
    printf("Provide a letter\n");
    scanf("%c", &letter);
    struct rotorResponse response1 = rotorEntrySubstitution(letter, 2, 0);
    printf("\n%d %c\n", response1.status, response1.letter);
    struct rotorResponse response2;
    if(response1.status == 1) {
        response2 = rotorEntrySubstitution(response1.letter, 3, 1);
        printf("\n%c", response2.letter);
    }
    printf("\nDecrypted value is %c\n", response2.letter);
    return 0;
}