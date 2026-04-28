#ifndef AUTH_H
#define AUTH_H
struct user {
    char username[50];
    char password[50];
};
int login();
void signup();
#endif
