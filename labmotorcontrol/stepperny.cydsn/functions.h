#pragma once
#include <stdint.h>
#include "project.h"

uint16_t getDirection(void);
uint8_t getState(void);

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