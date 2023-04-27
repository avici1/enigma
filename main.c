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

char inputString [100];

int rotorSelection[3];

int startPositions[3];

int reflector;

void setup() {
    for (int i = 2; i >= 0; i--) {
        printf("Select rotor %d from 0 - 4 \n", i+1);
        scanf("%d", &rotorSelection[i]);
        printf("Select a starting position from 0 - 25 \n");
        scanf("%d", &startPositions[i]);
    }
    printf("Select a reflector 0(UKW-B) - 1(UKW-C) \n");
    scanf("%d", &reflector);

    printf("Provide a string in all caps\n");
    scanf("%s", inputString);
}


int main () {

    /**
     * @brief Call setup method to configure plug-board choice and rotor selection as well as starting position*/
    setup();
    for (int i = 0; i < 18; ++i) {
        char valueFromPlugBoard = plugboard(inputString[i], true);
        /*
         * Path: Forward*/

        char reflectedLetter = forwardPath(valueFromPlugBoard);

        /*
         * Path: Backwards */

        char valueFromPlugBoard_back = backwardPath(reflectedLetter);
        printf("\n input: %c result: %c \n", inputString[i], valueFromPlugBoard_back);

    }
    return 0;
}

char forwardPath(char valueFromPlugBoard) {
    struct response* response1;
    struct response* response2;
    struct response* response3;


    //Rotor 3
    response3 = rotor_forward(
            valueFromPlugBoard,
            true,
            IS_ROTOR_3_STARTING,
            9,
            startPositions[2],
            currentPositionRotor3,
            rotorSelection[2],
            true
    );
    IS_ROTOR_3_STARTING = false;
    currentPositionRotor3 = response3->newPosition;
    // Rotor 2
    response2 = rotor_forward(
            response3->outputChar,
            response3->shouldRotate,
            IS_ROTOR_2_STARTING,
            21,
            startPositions[1],
            currentPositionRotor2,
            rotorSelection[1],
            true
    );

    IS_ROTOR_2_STARTING = false;
    currentPositionRotor2 = response2->newPosition;


    //Rotor 1
    response1 = rotor_forward(
            response2->outputChar,
            response2->shouldRotate,
            IS_ROTOR_1_STARTING,
            4,
            startPositions[0],
            currentPositionRotor1,
            rotorSelection[0],
            true
    );
    IS_ROTOR_1_STARTING = false;
    currentPositionRotor1 = response1->newPosition;
    // Reflector
    char reflectedLetter = reflected(response1->outputChar, reflector);
    return reflectedLetter;
}

char backwardPath(char reflectedLetter) {


    // Rotor 3
    struct response* response3;
    struct response* response2;
    struct response* response1;

    response1 = rotor(
            reflectedLetter,
            false,
            IS_ROTOR_1_STARTING,
            4,
            startPositions[0],
            currentPositionRotor1,
            rotorSelection[0],
            false
    );
    IS_ROTOR_1_STARTING = false;
    currentPositionRotor1 = response1->newPosition;

    // Rotor 2
    response2 = rotor(
            response1->outputChar,
            false,
            IS_ROTOR_2_STARTING,
            21,
            startPositions[1],
            currentPositionRotor2,
            rotorSelection[1],
            false
    );
    IS_ROTOR_2_STARTING = false;
    currentPositionRotor2 = response2->newPosition;

    // Rotor 3
    response3 = rotor(
            response2->outputChar,
            false,
            IS_ROTOR_3_STARTING,
            9,
            startPositions[2],
            currentPositionRotor3,
            rotorSelection[2],
            false
    );
    IS_ROTOR_3_STARTING = false;
    currentPositionRotor3 = response3->newPosition;





    // Plugboard.
    char valueFromPlugBoard_back = plugboard(response3->outputChar, false);
    return valueFromPlugBoard_back;
}


