#include "functions.h"

//Variables
<<<<<<< HEAD
uint16_t speedDelay = 20; // Sætter hastigheden på stepper motoren (Ved at lave et delay) 
uint8_t state = 1; // Skifter tilstanden brugt af stepper motoren. 1/A = Full, 2/S = Half, 3/D = Wave
uint8_t direction = 0; // Gemmer den nuværende retning. 0 = Stoppet, 1 = Fremad, 2 = Baglæns
=======
uint16_t speedDelay = 20; // SÃ¦tter Stepper Motorens hastighed med et delay 
uint8_t state = 1; // Skifter kÃ¸rsels-type. FÃ¸lgende notation: 1/A = Full, 2/S = Half, 3/D = Wave
uint8_t direction = 0; // Gemmer den nuvÃ¦rende kÃ¸rselsretning. 0 = Stoppet, 1 = Fremad, 2 = BaglÃ¦ns
>>>>>>> 7732126a72d51834f12cb5dd2bb041f56f542d8e

uint16_t getDirection(void) {
    return direction;
}

uint8_t getState(void) {
    return state;    
}

// Funktionen bliver kaldt fra main filen idet UARTen modtager et tegn.
// Her finder den ud af hvilken funktion der, baseret pÃ¥ det modtagne, skal kaldes.
void run(char byte) {
    switch(byte)
    {
        case 'q' :
        {
            decreaseSpeed(); // Sænker farten
        }
        break;
        case 'w' :
        {
            increaseSpeed(); // Hæver farten
        }
        break;
        
        case 'e' :
        {
            runOnceForward(); // En enkelt rotation
        }
        break;
        
        case 'r' :
        {
            runOnceBackwards(); // En enkelt baglæns rotation
        }
        break;
        
        case '1' :
        {
            driveForwards(); // Kontinuerligt fremad kørsel
        }
        break;
        
        case '2' :
        {
            driveBackwards(); // Kontinuerligt baglæns kørsel
        }
        break;
        
        case '0' :
        {
            stop(); // Stopper motoren
        }
        break;
        
<<<<<<< HEAD
        // Ændrer til full step
=======
        // Skifter kÃ¸rsels-type til full step
>>>>>>> 7732126a72d51834f12cb5dd2bb041f56f542d8e
        case 'a' :
        {
            changeState(1);
        }
        break;
        
<<<<<<< HEAD
        // Ændrer til half step
=======
       // Skifter kÃ¸rsels-type til half step
>>>>>>> 7732126a72d51834f12cb5dd2bb041f56f542d8e
        case 's' :
        {
            changeState(2);
        }
        break;
        
<<<<<<< HEAD
        // Ændrer til wave-drive
=======
        // Skifter kÃ¸rsels-type til wave-drive
>>>>>>> 7732126a72d51834f12cb5dd2bb041f56f542d8e
        case 'd' :
        {
            changeState(3);
        }
        break;
        default :
        {
            // Nothing
        }
        break;
    }
}

<<<<<<< HEAD
// Ændrer stepper motorens tilstand
=======
// Gemmer den nuvÃ¦rende kÃ¸rsels-type 
>>>>>>> 7732126a72d51834f12cb5dd2bb041f56f542d8e
void changeState(int stateNumb) {
    state = stateNumb;
}

void decreaseSpeed()
{
    if(speedDelay < 100) { // Sikrer, at delayet pÃ¥ motorens hastighed ikke bliver for lavt
        speedDelay += 2;   
    } else {
        UART_1_PutString("Motor cannot go slower\r\n");
    }
}

void increaseSpeed()
{
    if(speedDelay > 2) { // Sikrer, at delayet pÃ¥ motorens hastighed ikke bliver for hÃ¸j
        speedDelay -= 2;   
    } else {
        UART_1_PutString("Motor cannot go faster\r\n");
    }
}

void driveForwards()
{
    direction = 1;
}

void driveBackwards()
{
    direction = 2;
}

// Alle de nedenstÃ¥ende sekvenser er fundet i databladet pÃ¥ step moteren 
void stop()
{
    direction = 0;
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0);
}

void driveForwardsHalf() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
                
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
                
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
                
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay);  
    
}
void driveForwardsFull() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);

}
void driveForwardsWave() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
}

void driveBackwardsHalf() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay);  
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0); 
    CyDelay(speedDelay); 
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
}
void driveBackwardsFull() {
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
    
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
   
}
void driveBackwardsWave() {

    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(1);
    CyDelay(speedDelay);
     
    A1_Green_Write(0);
    A2_Orange_Write(1);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);

    A1_Green_Write(0);
    A2_Orange_Write(0);
    B1_Purple_Write(1);
    B2_White_Write(0);
    CyDelay(speedDelay);
    
    A1_Green_Write(1);
    A2_Orange_Write(0);
    B1_Purple_Write(0);
    B2_White_Write(0);
    CyDelay(speedDelay);

}

void runOnceForward() {
    
    for (uint32_t i = 0; i < 12; i++){ // Se udregning af antal gentagelser i journalen
        switch(state) {
            
            // Full step
            case 1 : 
            {
                driveForwardsFull(); 
            }
            break;
            
            // Half step
            case 2 : 
            {
                driveForwardsHalf();
            }
            break;
            
            // Wave step
            case 3 : 
            {
                driveForwardsWave();
            }
            break;
            
            default : 
            {
                //Nothing
            }
            break;
        }     
    }
    
    
    direction = 0; // Stop
}
void runOnceBackwards() {
    
    for (uint32_t i = 0; i < 12; i++){ // Se udregning af antal gentagelser i journalen
        switch(state) {
            // Full step
            case 1 : 
            {
                driveBackwardsFull(); 
            }
            break;
            
            // Half step
            case 2 : 
            {
                driveBackwardsHalf();
            }
            break;
            
            // Wave step
            case 3 : 
            {
                driveBackwardsWave();
            }
            break;
            
            default : 
            {
                //Nothing
            }
            break;
        }     
    }
    direction = 0; // Stop    
    
}
