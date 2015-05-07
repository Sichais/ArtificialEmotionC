//
//  Header.h
//  ArtificialEmotionC
//
//  Created by Zane Lassiter on 5/5/15.
//  Copyright (c) 2015 Zane Lassiter. All rights reserved.
//

#ifndef ArtificialEmotionC_Header_h
#define ArtificialEmotionC_Header_h

typedef struct state {
    char    state;
    //PEACE BLOCK BEGIN
    double  trusting;
    double  loving;
    double  relaxed;
    double  pensive;
    double  responsive;
    double  serene;
    double  secure;
    double  thankful;
    //PEACE BLOCK END

    //POWER BLOCK BEGIN
    double  proud;
    double  important;
    double  hopeful;
    double  cheerful;
    double  satisfied;
    double  valuable;
    double  worthwhile;
    double  intelligent;
    double  confident;
    //POWER BLOCK END

    //JOY BLOCK BEGIN
    double  excited;
    double  energetic;
    double  creative;
    double  aware;
    double  daring;
    double  stimulating;
    double  amused;
    double  extravagent;
    double  delightful;
    //JOY BLOCK END

    //SAD BLOCK BEGIN
    double  sleepy;
    double  bored;
    double  lonely;
    double  depressed;
    double  ashamed;
    double  guilty;
    double  miserable;
    double  bashful;
    double  stupid;
    //SAD BLOCK END

    //MAD BLOCK BEGIN
    double  hurt;
    double  hostile;
    double  angry;
    double  hateful;
    double  critical;
    double  jealous;
    double  selfish;
    double  frustrated;
    double  skeptical;
    //MAD BLOCK END

    //SCARE BLOCK BEGIN
    double  rejected;
    double  confused;
    double  helpless;
    double  submissive;
    double  insecure;
    double  anxious;
    double  embarrassed;
    //SCARE BLOCK END
} STATE;

typedef struct emotion {
    double sad;
    double joyful;
    double powerful;
    double peaceful;
    double mad;
    double scared;
} EMOTION;


//Actual Companion struct declaration
struct Companion {
    char    *name;
    STATE    currentState;
    EMOTION  currentEmotion;
} *Companion;

//Creating ("Waking Up") the Companion
struct Companion *wakeUp (char *name, STATE currentState, EMOTION currentEmotion) {
    struct Companion *who = calloc(3, sizeof(*Companion));
    assert(who != NULL);

    who -> name             = strdup(name);
    who -> currentState     = currentState;
    who -> currentEmotion   = currentEmotion;

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
int checkQuery(const char *queries, int nOne, char *response);

int checkJoy    (const char *emotionTriggersJoy,        int nTwo, char *response);
int checkSad    (const char *emotionTriggersSad,        int nTwo, char *response);
int checkMad    (const char *emotionTriggersMad,        int nTwo, char *response);
int checkScared (const char *emotionTriggersScared,     int nTwo, char *response);
int checkPower  (const char *emotionTriggersPowerful,   int nTwo, char *response);
int checkPeace  (const char *emotionTriggersPeaceful,   int nTwo, char *response);
//EMOTION/QUERY FUNCTION BLOCK END
//============================================================================
//FUNCTION PROTOTYPES END

//FUNCTION DECLARATIONS BEGIN
//============================================================================
//EMOTION/QUERY FUNCTION BLOCK BEGIN
int checkMad(const char *emotionTriggersMad, int nTwo, char *response) {
    int madBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcmp(&emotionTriggersMad[i], response) == 0) {
            madBool = 1;
        } else {
            madBool = 0;
        }
    }
    return madBool;
}

int checkSad(const char *emotionTriggersSad, int nTwo, char *response) {
    int sadBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcmp(&emotionTriggersSad[i], response) == 0) {
            sadBool = 1;
        } else {
            sadBool = 0;
        }
    }
    return sadBool;
}

int checkJoy(const char *emotionTriggersJoy, int nTwo, char *response) {
    int joyBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcmp(&emotionTriggersJoy[i], response) == 0) {
            joyBool = 1;
        } else {
            joyBool = 0;
        }
    }
    return joyBool;
}

int checkQuery(const char *queries, int nOne, char *response) {
    int responseBool = 0;

    for (int i = 0; i < nOne; i++) {
        if (strcmp(&queries[i], response) == 0) {
            responseBool = 1;
        } else {
            responseBool = 0;
        }
    }
    return responseBool;
}

int checkScared(const char *emotionTriggersScared, int nTwo, char *response) {
    int scaredBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcmp(&emotionTriggersScared[i], response) == 0) {
            scaredBool = 1;
        } else {
            scaredBool = 0;
        }
    }
    return scaredBool;
}

int checkPower(const char *emotionTriggersPowerful, int nTwo, char *response) {
    int powerBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcmp(&emotionTriggersPowerful[i], response) == 0) {
            powerBool = 1;
        } else {
            powerBool = 0;
        }
    }
    return powerBool;
}

int checkPeace(const char *emotionTriggersPeaceful, int nTwo, char *response) {
    int peaceBool = 0;

    for (int i = 0; i < nTwo; i++) {
        if (strcmp(&emotionTriggersPeaceful[i], response) == 0) {
            peaceBool = 1;
        } else {
            peaceBool = 0;
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
    test -> currentEmotion.mad -= 1;

    if (test -> currentEmotion.joyful > 0.5) {
        test -> currentEmotion.joyful -= 0.5;
    } else if (test -> currentEmotion.joyful < 0) {
        test -> currentEmotion.joyful += 0.7;
    }

    if (test -> currentEmotion.powerful > 0.5) {
        test -> currentEmotion.powerful -= 0.5;
    } else if (test -> currentEmotion.joyful < 0) {
        test -> currentEmotion.joyful += 0.7;
    }

    if (test -> currentEmotion.scared > 0.5) {
        test -> currentEmotion.scared -= 0.5;
    } else if (test -> currentEmotion.scared < 0) {
        test -> currentEmotion.scared += 0.7;
    }
}

void lowerPeace(struct Companion *test) {
    test -> currentEmotion.peaceful -= 1;
    test -> currentEmotion.mad      += 1;
}

void raisePower (struct Companion *test) {
    test -> currentEmotion.powerful += 1;
    test -> currentEmotion.scared -= 1;
    test -> currentEmotion.joyful += 0.5;
    test -> currentEmotion.peaceful -= 0.5;
}

void lowerPower (struct Companion *test) {
    test -> currentEmotion.powerful -= 1;
    test -> currentEmotion.scared += 1;
    test -> currentEmotion.joyful -= 0.4;
}

void raiseScared (struct Companion *test) {
    test -> currentEmotion.scared += 1;
    test -> currentEmotion.peaceful -= 1.5;
    test -> currentEmotion.mad -= 0.2;
    test -> currentEmotion.joyful -= 0.2;
    test -> currentEmotion.sad += 0.2;
}

void lowerScared (struct Companion *test) {
    test -> currentEmotion.scared -= 1;
    test -> currentEmotion.peaceful += 0.7;
    test -> currentEmotion.sad -= 0.2;
}
#endif
