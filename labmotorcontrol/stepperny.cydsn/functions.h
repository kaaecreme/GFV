#pragma once
#include <stdint.h>
#include "project.h"

<<<<<<< HEAD
uint16_t getDirection(void); // Bruges til at sende den nuv�rende retning
uint8_t getState(void); // Finder den nuv�rende tilstand (Frem / tilbage)
=======
uint16_t getDirection(void); // Returnerer den nuværende rotationsretning
uint8_t getState(void); // Returnerer den nuværende kørselsretning
>>>>>>> 7732126a72d51834f12cb5dd2bb041f56f542d8e

void changeState(int); // Gemmer en modtaget kørsels-retning

void run(char); // Kalder en kommando i functions.c, modtaget fra UARTen i main.c (Den modtager alt hvad der kommer fra UARTen!)

void decreaseSpeed(void); // Sænker hastigheden
void increaseSpeed(void); // Hæver hastigheden
void driveForwards(void); // Ændrer retning til fremad
void driveBackwards(void); // Ændrer retning til baglæns
void stop(void); // Bringer motoren til standsning

void driveForwardsHalf(void); // Skifter kørsels-type til Half-Step i fremadgående retning
void driveForwardsFull(void); // Skifter kørsels-type til Full-Step i fremadgående retning
void driveForwardsWave(void); // Skifter kørsels-type til Wave-Drive  i fremadgående retning

void driveBackwardsHalf(void); // Skifter kørsels-type til Half-Step i bagudgående retning
void driveBackwardsFull(void); // Skifter kørsels-type til Full-Step i bagudgående retning
void driveBackwardsWave(void); // Skifter kørsels-type til Wave-Drive i bagudgående retning

void runOnceForward(void); // Laver en rotation i fremadgående retning
void runOnceBackwards(void); // Laver en rotation i bagudgående retning