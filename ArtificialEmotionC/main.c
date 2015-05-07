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
#include <limits.h>

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
#define nOne 2
#define nTwo 1
//MAIN FUNCTION BEGIN
int main(int argc, const char * argv[]) {
    //Prep for Time command
    time_t rawtime;
    time (&rawtime);

    struct tm *info;
    info = localtime (&rawtime);

    //Number of arguements in Emotion Triggers array, KEEP UP TO DATE WITH ARRAY
    //int nOne = 2;
    const char *queries[nOne] = {"Time", "Test"};

    //TODO: Add query banks for all emotion triggers and actual functionality to emotions
    //All Trigger banks need to be a uniform length to prevent seg faults
    //int nTwo = 1;
    const char *emotionTriggersJoy      [nOne] = {"Happy"};
    const char *emotionTriggersSad      [nOne] = {"Sad"};
    const char *emotionTriggersMad      [nOne] = {"Mad"};
    const char *emotionTriggersScared   [nOne] = {"Scared"};
    const char *emotionTriggersPeace    [nOne] = {"Peaceful"};
    const char *emotionTriggerPowerful  [nOne] = {"Powerful"};

    STATE testState = { //Yeah this isn't currently being used, but 1. This took a while to type and 2. I intend to implement it later
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
           0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    };
    EMOTION testEmotion = { //The grossly oversimplified version of STATE; EMOTION
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    };

    int joyBool      = 0;
    int madBool      = 0;
    int sadBool      = 0;
    int responseBool = 0;
    int scaredBool   = 0;
    int powerBool    = 0;
    int peaceBool    = 0;
    int timeBool     = 0;

    char *response;
    response = (char *) malloc(256);

    struct Companion *test = wakeUp("Test", testState, testEmotion);

    printf("Loading...\n");
    sleep(1);
    printf("Hello my name is %s\n", test -> name);
    //TODO Add an atual input loop

    fgets(response, 256, stdin);
    response[strcspn(response, "\n")] = 0;

    responseBool = checkQuery(*queries, nOne, response);

    joyBool = checkJoy(*emotionTriggersJoy, nTwo, response);
    sadBool = checkSad(*emotionTriggersSad, nTwo, response);
    madBool = checkMad(*emotionTriggersMad, nTwo, response);
    scaredBool = checkScared(*emotionTriggersScared, nTwo, response);
    powerBool = checkPower(*emotionTriggerPowerful, nTwo, response);
    peaceBool = checkPeace(*emotionTriggersPeace, nTwo, response);

    if (responseBool == 1) {
        if (strcasecmp(queries[0], response) == 0) {
            timeBool = 1;
        }
    }
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

    if (timeBool == 1) {
        printf("The current time is: %s", asctime(info));
    }
    printf("Loop Succeeded");

    //TODO Add emotional state dependant regex

    shutDown(test);
    free(response);
    return 0;
}
//MAIN FUNCTION END
