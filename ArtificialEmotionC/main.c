//
//  main.c
//  ArtificialEmotionC
//
//  Created by Zane Lassiter on April 29th, 2015
//
//  LAST EDITED:                September 25th, 2015
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
#include <termios.h>

//Personal headers
#include "emotion.h"
#include "user.h"
/* Included in Header:

 EMOTION Type

 STATE Type

 Companion Struct and underlying functions

 EMOTION Mod functions

 TODO: Add STATE Mod functions

*/

#define MAX_SIZE 1028
#define MAX_RESPONSE_SIZE 64
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
    //const char *queries[nOne] = {"Time", "Test"};

    //TODO: Add query banks for all emotion triggers and actual functionality to emotions
    //All Trigger banks need to be a uniform length to prevent seg faults
    //int nTwo = 1;
    const char *emotionTriggersJoy      [nOne] = {"Happy"};
    const char *emotionTriggersSad      [nOne] = {"Sad"};
    const char *emotionTriggersMad      [nOne] = {"Mad"};
    const char *emotionTriggersScared   [nOne] = {"Scared"};
    const char *emotionTriggersPeace    [nOne] = {"Peaceful"};
    const char *emotionTriggerPowerful  [nOne] = {"Powerful"};
    
    char *response = malloc(MAX_RESPONSE_SIZE);
    char username[64];
    char password[64];
    char firstChoice[8];
    int  breakOut = 0;
    
    /*
     Reads input for Username value
     
     Password input is hidden
     */
    struct termios oflags, nflags;
    printf("Would you like to log in? y/n: ");
    while (breakOut == 0) {
        scanf("%s", firstChoice);
        
        switch (firstChoice[0]) {
            case 'Y': {
                breakOut = 1;
            }
            case 'y': {
                
                //Doesnt hide user input for username
                printf("Enter your username here: ");
                scanf("%63s", username);
                getchar();
        
                //Password input
                tcgetattr(fileno(stdin), &oflags);
                nflags = oflags;
                nflags.c_lflag &= ~ECHO;
                nflags.c_lflag |= ECHONL;
                
                if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
                    perror("tcsetattr");
                    return EXIT_FAILURE;
                }
                
                printf("Enter Password: ");
                
                fgets(password, sizeof(password), stdin);
                if ((strlen(password) > 0) && (password[strlen(password) - 1] == '\n')) {
                    password [strlen(password) - 1] = '\0';
                }
                
                if (tcsetattr(fileno(stdin), TCSANOW, &oflags)) {
                    perror("tcsetattr");
                    return EXIT_FAILURE;
                }
                breakOut = 1;
                break;
            }
            case 'N': {
                
            }
            case 'n': {
                printf("Logging out...");
                exit(1);
            }
            default: {
                printf("\nInvalid input\n"
                       "Would you like to log in? y/n ");
                break;
            }
        }
    }
    breakOut = 0;
    
    EMOTION testEmotion = { //The grossly oversimplified version of STATE; EMOTION
        0.0, //Sad
        0.0, //Joy
        0.0, //Power
        0.0, //Peace
        0.0, //Mad
        0.0, //Scare
    };
    
    RESPONSES testResponses = {
        0, //response
        0, //time (query)
        0, //joy
        0, //mad
        0, //sad
        0, //scare
        0, //peace
        0, //power
    };
    struct User *past = establishUsers("Sichais", "password");
    struct User *user = createUser(username, password);
    struct Companion *assist = wakeUp("\0", testEmotion, testResponses);
    
    int logBool = logIn(user, past);
    
    if (logBool == 0) {
        printf("Invalid credentials, exitting program");
        exit(1);
    }
    
    printf("Loading...\n");
    sleep(1);
    printf("Welcome %s"
           "\n\n"
           "Please enter the name of your assistant: ", user -> username);
    
    fgets(assist -> name, MAX_RESPONSE_SIZE, stdin);
    if ((strlen(assist -> name) > 0) && (assist -> name[strlen(assist -> name) - 1])) {
        assist -> name[strlen(assist -> name) -1] = '\0';
    }
    
    printf("Hello my name is %s\n", assist -> name);
    //TODO Add an atual input loop

    printf("Please enter a command, Or say 'Log out' to exit\n");
    int responseEnd1 = strcasecmp("Log Out", response);
    while (responseEnd1 != 0) {
        printf(">");
        
        fgets(response, MAX_RESPONSE_SIZE, stdin);
        if ((strlen(response) > 0) && (response[strlen(response) - 1] == '\n')) {
            response [strlen(response) - 1] = '\0';
        }

        assist -> allResponses.responseBool = checkQuery(assist, response, assist);

        checkJoy    (*emotionTriggersJoy,     nTwo, response, assist);
        checkSad    (*emotionTriggersSad,     nTwo, response, assist);
        checkMad    (*emotionTriggersMad,     nTwo, response, assist);
        checkScared (*emotionTriggersScared,  nTwo, response, assist);
        checkPower  (*emotionTriggerPowerful, nTwo, response, assist);
        checkPeace  (*emotionTriggersPeace,   nTwo, response, assist);
        
        if (assist -> allResponses.joyBool == 1) {
            raiseJoy(assist);
        } else if (assist -> allResponses.madBool == 1) {
            raiseMad(assist);
        } else if (assist -> allResponses.sadBool == 1) {
            raiseSad(assist);
        } else if (assist -> allResponses.scareBool == 1) {
            raiseScared(assist);
        } else if (assist -> allResponses.powerBool == 1) {
            //TODO Add raisePower function
        } else if (assist -> allResponses.peaceBool == 1) {
            raisePeace(assist);
        }

        if (assist -> allResponses.timeBool == 1) {
            printf("The current time is: %s", asctime(info));
            assist -> allResponses.timeBool = 0;
        }
        if (assist -> allResponses.fiboBool == 1) {
            int i = 0;
            int fiboLimit = 0;
            printf("Alright, how far do you want the sequence to go: ");
            scanf("%d", &fiboLimit);
            for (i = 0; i < fiboLimit; i++) {
                printf("%d \n", fibonacci(i));
            }
            assist -> allResponses.fiboBool = 0;
        }
        responseEnd1 = strcasecmp("Log Out", response);
        //TODO Add emotional state dependant regex
    }
    printf("Shutting down...");
    shutDown(assist);
    
    //curl_global_cleanup();
    
    return 0;
}
//MAIN FUNCTION END
