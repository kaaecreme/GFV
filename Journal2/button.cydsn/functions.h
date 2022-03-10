#include "project.h"

// Erklær variablerne som externe, så de kan bruges i både functions.c og main.c
extern uint8_t emptyData;
extern uint8_t onData;
extern uint8_t offData; 
extern uint8_t buttonData;
extern uint8_t recievedData; 

void handleByteReceived(uint8_t byteReceived);