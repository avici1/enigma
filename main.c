//
// Created by avici1 on 21/03/2023.
//
#include <stdio.h>
#include "rotor.h"


int main () {
    char letter = 'Z';
    printf("Provide a letter\n");
    scanf("%c", &letter);
    char newValue = rotorEntrySubstitution(letter, 2);
    printf("Decrypted value is %c %c", letter, newValue);
    return 0;
}