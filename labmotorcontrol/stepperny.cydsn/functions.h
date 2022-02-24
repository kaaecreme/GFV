#pragma once
#include <stdint.h>
#include "project.h"

uint16_t getDirection(void); // Bruges til at sende den nuv�rende retning
uint8_t getState(void); // Finder den nuv�rende tilstand (Frem / tilbage)

void changeState(int);

void run(char);

void decreaseSpeed(void);
void increaseSpeed(void);
void driveForwards(void);
void driveBackwards(void);
void stop(void);

void driveForwardsHalf(void);
void driveForwardsFull(void);
void driveForwardsWave(void);

void driveBackwardsHalf(void);
void driveBackwardsFull(void);
void driveBackwardsWave(void);

void runOnceForward(void);
void runOnceBackwards(void);