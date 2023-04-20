//
// Created by avici1 on 21/03/2023.
//
#include <stdio.h>
#include "plugboard.h"
#include "reflector.h"
#include "rotors.h"

char forwardPath(char valueFromPlugBoard);

char backwardPath(char reflectedLetter);

bool IS_ROTOR_1_STARTING = true;

bool IS_ROTOR_2_STARTING = true;

bool IS_ROTOR_3_STARTING = true;

int currentPositionRotor1 = 0;

int currentPositionRotor2 = 0;

int currentPositionRotor3 = 0;

int main () {
    char letter = 'Z';
    char values[7];
    printf("Provide a letter\n");
    scanf("%c", &letter);
    char valueFromPlugBoard = plugboard(letter, true);
    /*
     * Path: Forward*/

    char reflectedLetter = forwardPath(valueFromPlugBoard);

    /*
     * Path: Backwards */

    char valueFromPlugBoard_back = backwardPath(reflectedLetter);

    printf("\n value from rotor 3 %c", valueFromPlugBoard);

    printf("\n Final value %c", valueFromPlugBoard_back);

    return 0;
}

char forwardPath(char valueFromPlugBoard) {
    struct response* response1;
    struct response* response2;
    struct response* response3;
    //Rotor 1
    response1 = rotor(
            valueFromPlugBoard,
            1,
            IS_ROTOR_1_STARTING,
            4,
            0,
            0,
            1,
            true
            );
    printf("%c ==== 1 ", response1->outputChar);
    IS_ROTOR_1_STARTING = false;
    currentPositionRotor1 = response1->newPosition;

    //Rotor 2

    response2 = rotor(
            response1->outputChar,
            response1->shouldRotate,
            IS_ROTOR_2_STARTING,
            21,
            10,
            0,
            2,
            true
            );

    IS_ROTOR_2_STARTING = false;
    currentPositionRotor2 = response2->newPosition;
    printf("\n%c ==== 2", response2->outputChar);

    //Rotor 3
    response3 = rotor(
            response2->outputChar,
            response2->shouldRotate,
            IS_ROTOR_3_STARTING,
            9,
            12,
            0,
            3,
            true
    );
    IS_ROTOR_3_STARTING = false;
    currentPositionRotor3 = response3->newPosition;
    printf("\n%c === 3", response3->outputChar);

    // Reflector
    char reflectedLetter = reflected(response3->outputChar, 0);
    printf("\n%c reflected", reflectedLetter);
    return reflectedLetter;
}

char backwardPath(char reflectedLetter) {

//    // Rotor 3
    struct response* response3;
    struct response* response2;
    struct response* response1;
    response3 = rotor(
            reflectedLetter,
            false,
            IS_ROTOR_3_STARTING,
            9,
            12,
            0,
            3,
            false
    );
    IS_ROTOR_3_STARTING = false;
    currentPositionRotor3 = response3->newPosition;
    printf("\n%c === 3", response3->outputChar);

    // Rotor 2
    response2 = rotor(
            response3->outputChar,
            false,
            IS_ROTOR_2_STARTING,
            21,
            10,
            0,
            2,
            false
    );
    IS_ROTOR_2_STARTING = false;
    currentPositionRotor2 = response2->newPosition;
    printf("\n%c === 2", response2->outputChar);

    response1 = rotor(
            response2->outputChar,
            false,
            IS_ROTOR_2_STARTING,
            4,
            0,
            0,
            1,
            false
    );
    IS_ROTOR_1_STARTING = false;
    currentPositionRotor1 = response1->newPosition;
    printf("\n%c === 1", response1->outputChar);

    // Plugboard.
    char valueFromPlugBoard_back = plugboard(response1->outputChar, false);
//    printf("\nDecrypted value is %c\n", valueFromPlugBoard_back);
    return valueFromPlugBoard_back;
}


