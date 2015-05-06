//
//  main.c
//  ArtificialEmotionC
//
//  Created by Zane Lassiter on 4/29/15.
//  Copyright (c) 2015 Zane Lassiter. All rights reserved.
//

//System Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>

//Personal headers
#include "emotion.h"
/* Included in Header:
 
 EMOTION Type

 STATE Type

 Companion Struct and underlying functions
 
 EMOTION Mod functions

 TODO: Add STATE Mod functions

*/

#define MAX_SIZE 1028

//MAIN FUNCTION BEGIN
int main(int argc, const char * argv[]) {
    
    //Number of arguements in Emotion Triggers array, KEEP UP TO DATE WITH ARRAY
    int nOne = 2;
    const char *queries[MAX_SIZE] = {"Test", "potato"};
    
    //TODO: Add query banks for all emotion triggers and actual functionality to emotions
    //All Trigger banks need to be a uniform length to prevent seg faults
    int nTwo = 1;
    const char *emotionTriggersJoy[MAX_SIZE] = {"Happy"};
    const char *emotionTriggersSad[MAX_SIZE] = {"Sad"};
    const char *emotionTriggersMad[MAX_SIZE] = {"Mad"};
    const char *emotionTriggersScared[MAX_SIZE] = {"Scared"};
    const char *emotionTriggersPeace[MAX_SIZE] = {"Peaceful"};
    const char *emotionTriggerPowerful[MAX_SIZE] = {"Powerful"};
    
    STATE testState = {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
           0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    };
    EMOTION testEmotion = {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    };
    
    int joyBool;
    int madBool;
    int sadBool;
    int responseBool;
    int scaredBool;
    int powerBool;
    int peaceBool;
    
    char response[256];
    struct Companion *test = wakeUp("Test", testState, testEmotion);
    
    printf("Loading...\n");
    //sleep(2);
    printf("Hello my name is %s\n", test -> name);
    //TODO Add an atual input loop
    
    scanf("%255[^\n]", response);
    
    responseBool = checkQuery(*queries, nOne, response);
    
    joyBool = checkJoy(*emotionTriggersJoy, nTwo, response);
    sadBool = checkSad(*emotionTriggersSad, nTwo, response);
    madBool = checkMad(*emotionTriggersMad, nTwo, response);
    scaredBool = checkScared(*emotionTriggersScared, nTwo, response);
    powerBool = checkPower(*emotionTriggerPowerful, nTwo, response);
    peaceBool = checkPeace(*emotionTriggersPeace, nTwo, response);
    
    if (joyBool == 1) {
        raiseJoy(test);
    } else if (madBool == 1) {
        raiseMad(test);
    } else if (sadBool == 1) {
        raiseSad(test);
    } else if (scaredBool == 1) {
        raiseScared(test);
    } else if (powerBool == 1) {
        //TODO Add raisePower function
    } else if (peaceBool == 1) {
        raisePeace(test);
    }
    printf("Loop Succeeded");
    
    //TODO Add emotional state dependant regex
    
    shutDown(test);
    return 0;
}
//MAIN FUNCTION END