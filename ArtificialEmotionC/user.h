//
//  user.h
//  ArtificialEmotionC
//
//  Created by Zane Lassiter on 5/8/15.
//  Copyright (c) 2015 Zane Lassiter. All rights reserved.
//

#ifndef ArtificialEmotionC_user_h
#define ArtificialEmotionC_user_h

struct User {
    char *username;
    char *password;
} *User;

struct User *establishUsers (char *username, char *password) {
    struct User *pastUsers = calloc(3, sizeof(*User));
    assert(pastUsers != NULL);
    
    pastUsers -> username = strdup(username);
    pastUsers -> password = strdup(password);
    
    return pastUsers;
}

void clearPastUsers (struct User *pastUsers) {
    assert(pastUsers != NULL);
    
    free(pastUsers -> username);
    free(pastUsers -> password);
    
    free(pastUsers);
}

struct User *createUser (char *username, char *password) {
    struct User *what = calloc(3, sizeof(*User));
    assert(what != NULL);
    
    what -> username = strdup(username);
    what -> password = strdup(password);
    
    return what;
}

void logOut (struct User *what) {
    assert(what != NULL);
    
    free(what -> username);
    free(what -> password);
    
    free(what);
}

int logIn (struct User *user, struct User *past) {
    int logBool = 0;
    int compUser = strcmp(user -> username, past -> username);
    int compPass = strcmp(user -> password, past -> password);
    
    if (compUser == 0 && compPass == 0) {
        logBool = 1;
    }
    return logBool;
}
#endif
