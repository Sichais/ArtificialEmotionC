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

void logIn (struct User *what) {
    
}
#endif
