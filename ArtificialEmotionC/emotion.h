//
//  Header.h
//  ArtificialEmotionC
//
//  Created by Zane Lassiter on 5/5/15.
//  Copyright (c) 2015 Zane Lassiter. All rights reserved.
//

#ifndef ArtificialEmotionC_Header_h
#define ArtificialEmotionC_Header_h

typedef struct emotion {
    double sad;
    double joyful;
    double powerful;
    double peaceful;
    double mad;
    double scared;
} EMOTION;

typedef struct webOfEmotions {
    //S A D B L O C K L1
    double bashful;
    double stupid;
    double miserable;
    double inadequate;
    double inferior;
    double apathetic;
    
    //S A D B L O C K L2
    double guilty;
    double ashamed;
    double depressed;
    double lonely;
    double bored;
    double sleepy;
    
    //Joyful Block L1
    double daring;
    double fascinating;
    double stimulating;
    double amused;
    double extravagant;
    double delightful;
    
    //Joyful Block L2
    double excited;
    double sexy;
    double energetic;
    double playful;
    double creative;
    double aware;
    
    //Powerful Block L1
    double confident;
    double intelligent;
    double worthwhile;
    double valuable;
    double satisfied;
    double cheerful;
    
    //Powerful Block L2
    double faithful;
    double important;
    double hopeful;
    double appreciated;
    double respected;
    double proud;
    
    //Peaceful Block L1
    double pensive;
    double relaxed;
    double responsive;
    double serene;
    double sentimental;
    double thankful;
    
    //Peaceful Block L2
    double content;
    double thoughtful;
    double intimate;
    double loving;
    double trusting;
    double nurturing;
    
    //Mad Block L1
    double skeptical;
    double irratated;
    double furious;
    double frustrated;
    double selfish;
    double jealous;
    
    //Mad Block L2
    double critical;
    double hateful;
    double rage;
    double angry;
    double hostile;
    double hurt;
    
    //Scared Block L1
    double bewildered;
    double discouraged;
    double insignificant;
    double weak;
    double foolish;
    double embarrassed;
    
    //Scared Block L2
    double rejected;
    double confused;
    double helpful;
    double submissive;
    double insecure;
    double anxious;
    
    //I genuinely didn't think there were this many feels,
   //nor did I think that there could be so many functions
} TRUE_EMOTION;

typedef struct responses {
    int responseBool;
    //Add more bools for each possible query
    int timeBool;
    int fiboBool;
    //Query bool end
    int joyBool;
    int madBool;
    int sadBool;
    int scareBool;
    int peaceBool;
    int powerBool;
    
    
    int debugBool;
} RESPONSES;
//Actual Companion struct declaration
struct Companion {
    char       *name;
    EMOTION      currentEmotion;
    TRUE_EMOTION currentTrueEmotion;
    RESPONSES    allResponses;
} *Companion;

//Creating ("Waking Up") the Companion
struct Companion *wakeUp (char *name,
                          EMOTION currentEmotion,
                          TRUE_EMOTION currentTrueEmotion,
                          RESPONSES allResponses) {
    struct Companion *who = calloc(3, sizeof(*Companion));
    assert(who != NULL);

    who -> name               = strdup(name);
    who -> currentEmotion     = currentEmotion;
    who -> currentTrueEmotion = currentTrueEmotion;

    return who;
}

void shutDown(struct Companion *who) {
    assert(who != NULL);

    free(who -> name);

    free(who);
}

//FUNCTION PROTOTYPES BEGIN
//============================================================================
//EMOTION MOD BLOCK BEGIN
void raiseSad   (struct Companion *test);
void lowerSad   (struct Companion *test);

void raiseJoy   (struct Companion *test);
void lowerJoy   (struct Companion *test);

void raiseMad   (struct Companion *test);
void lowerMad   (struct Companion *test);

void raisePeace (struct Companion *test);
void lowerPeace (struct Companion *test);

void raiseScared(struct Companion *test);
void lowerScared(struct Companion *test);

void raisePower (struct Companion *test);
void lowerPower (struct Companion *test);
//EMOTION MOD BLOCK END


//EMOTION/QUERY SEARCH FUNCTION BLOCK BEGIN
int checkQuery(struct Companion *test, char *response, struct Companion *assist);

int checkJoy    (const char *emotionTriggersJoy,        int nTwo, char *response, struct Companion *assist);
int checkSad    (const char *emotionTriggersSad,        int nTwo, char *response, struct Companion *assist);
int checkMad    (const char *emotionTriggersMad,        int nTwo, char *response, struct Companion *assist);
int checkScared (const char *emotionTriggersScared,     int nTwo, char *response, struct Companion *assist);
int checkPower  (const char *emotionTriggersPowerful,   int nTwo, char *response, struct Companion *assist);
int checkPeace  (const char *emotionTriggersPeaceful,   int nTwo, char *response, struct Companion *assist);
//EMOTION/QUERY FUNCTION BLOCK END

//SPECIALIZED FUNCTIONS BLOCK BEGIN
int fibonacci(int i);
//SPECIALIZED FUNCTIONS BLOCK END
//============================================================================
//FUNCTION PROTOTYPES END

//FUNCTION DECLARATIONS BEGIN
//============================================================================
//SPECIALIZED FUNCTIONS BLOCK BEGIN
int fibonacci(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    return fibonacci(i - 1) + fibonacci(i - 2);
}
//SPECIALIZED FUNCTIONS BLOCK END

//EMOTION/QUERY FUNCTION BLOCK BEGIN
int checkMad(const char *emotionTriggersMad, int nTwo, char *response, struct Companion *assist) {
    int madBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcasecmp(&emotionTriggersMad[i], response) == 0) {
            assist -> allResponses.madBool = 1;
        } 
    }
    return madBool;
}

int checkSad(const char *emotionTriggersSad, int nTwo, char *response, struct Companion *assist) {
    int sadBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcasecmp(&emotionTriggersSad[i], response) == 0) {
            assist -> allResponses.sadBool = 1;
        }
    }
    return sadBool;
}

int checkJoy(const char *emotionTriggersJoy, int nTwo, char *response, struct Companion *assist) {
    int joyBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcasecmp(&emotionTriggersJoy[i], response) == 0) {
            assist -> allResponses.joyBool = 1;
        }
    }
    return joyBool;
}

//TODO Make a more elegant system than "Compare each query to the response and return a different number
//Seriously. It works but its weird, get on that
int checkQuery(struct Companion *test, char *response, struct Companion *assist) {
    int responseBool = 0;
    if ((strstr(response, "Time") != NULL) || (strstr(response, "time") != NULL)) {
        assist -> allResponses.timeBool = 1;
    }
    if ((strstr(response, "Fibonacci") != NULL || (strstr(response, "fibonacci") != NULL))) {
        assist -> allResponses.fiboBool = 1;
    }
    if ((strstr(response, "Debug") != NULL || (strstr(response, "debug") != NULL))) {
        assist -> allResponses.debugBool = 1;
    }
    return responseBool;
}

int checkScared(const char *emotionTriggersScared, int nTwo, char *response, struct Companion *assist) {
    int scaredBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcasecmp(&emotionTriggersScared[i], response) == 0) {
            assist -> allResponses.scareBool = 1;
        }
    }
    return scaredBool;
}

int checkPower(const char *emotionTriggersPowerful, int nTwo, char *response, struct Companion *assist) {
    int powerBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcasecmp(&emotionTriggersPowerful[i], response) == 0) {
            assist -> allResponses.powerBool = 1;
        }
    }
    return powerBool;
}

int checkPeace(const char *emotionTriggersPeaceful, int nTwo, char *response, struct Companion *assist) {
    int peaceBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcasecmp(&emotionTriggersPeaceful[i], response) == 0) {
            assist -> allResponses.peaceBool = 1;
        }
    }
    return peaceBool;
}
//EMOTION/QUERY FUNCTION BLOCK END


//EMOTION MOD FUNCTION BLOCK BEGIN
void raiseSad(struct Companion *test) {
    test -> currentEmotion.sad      += 1;
    test -> currentEmotion.scared   += 0.1;
    test -> currentEmotion.joyful   -= 0.6;
    test -> currentEmotion.powerful -= 0.2;
}

void lowerSad(struct Companion *test) {
    test -> currentEmotion.sad      -= 1;
    test -> currentEmotion.scared   -= 0.1;
    test -> currentEmotion.joyful   += 0.4;
    test -> currentEmotion.powerful += 0.1;
    test -> currentEmotion.peaceful += 0.6;
}



void raiseJoy(struct Companion *test) {
    test -> currentEmotion.joyful   += 1;
    test -> currentEmotion.sad      -= 0.6;
    test -> currentEmotion.mad      -= 0.2;
    test -> currentEmotion.powerful += 0.1;
    test -> currentEmotion.peaceful += 0.2;
    test -> currentEmotion.scared   -= 0.2;
}

void lowerJoy(struct Companion *test) {
    test -> currentEmotion.joyful   -= 1;
    test -> currentEmotion.sad      -= 0.7;
    test -> currentEmotion.mad      += 0.1;
    test -> currentEmotion.scared   += 0.1;
}



void raiseMad(struct Companion *test) {
    test -> currentEmotion.mad      += 1;
    test -> currentEmotion.peaceful -= 1;
    test -> currentEmotion.joyful   -= 0.4;
    test -> currentEmotion.scared   += 0.2;
}

void lowerMad(struct Companion *test) {
    test -> currentEmotion.mad      -= 1;
    test -> currentEmotion.peaceful += 1;
    test -> currentEmotion.joyful   += 0.4;
}



void raisePeace(struct Companion *test) {
    test -> currentEmotion.peaceful += 1;
    test -> currentEmotion.mad      -= 1;

    if (test -> currentEmotion.joyful        > 0.5) {
        test -> currentEmotion.joyful        -= 0.5;
    } else if (test -> currentEmotion.joyful < 0) {
        test -> currentEmotion.joyful        += 0.7;
    }

    if (test -> currentEmotion.powerful      > 0.5) {
        test -> currentEmotion.powerful      -= 0.5;
    } else if (test -> currentEmotion.joyful < 0) {
        test -> currentEmotion.joyful        += 0.7;
    }

    if (test -> currentEmotion.scared        > 0.5) {
        test -> currentEmotion.scared        -= 0.5;
    } else if (test -> currentEmotion.scared < 0) {
        test -> currentEmotion.scared        += 0.7;
    }
}

void lowerPeace(struct Companion *test) {
    test -> currentEmotion.peaceful -= 1;
    test -> currentEmotion.mad      += 1;
}

void raisePower (struct Companion *test) {
    test -> currentEmotion.powerful += 1;
    test -> currentEmotion.scared   -= 1;
    test -> currentEmotion.joyful   += 0.5;
    test -> currentEmotion.peaceful -= 0.5;
}

void lowerPower (struct Companion *test) {
    test -> currentEmotion.powerful -= 1;
    test -> currentEmotion.scared   += 1;
    test -> currentEmotion.joyful   -= 0.4;
}

void raiseScared (struct Companion *test) {
    test -> currentEmotion.scared   += 1;
    test -> currentEmotion.peaceful -= 1.5;
    test -> currentEmotion.mad      -= 0.2;
    test -> currentEmotion.joyful   -= 0.2;
    test -> currentEmotion.sad      += 0.2;
}

void lowerScared (struct Companion *test) {
    test -> currentEmotion.scared   -= 1;
    test -> currentEmotion.peaceful += 0.7;
    test -> currentEmotion.sad      -= 0.2;
}
#endif
