#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
    char username[50];
    char password[50];
};

int login() {
    FILE *fp;
    struct user u;
    char uname[50], pass[50];
    int found = 0;

    fp = fopen("users.dat", "rb");
    if (fp == NULL) {
        printf("No users found. Please sign up first.\n");
        return 0;
    }

    printf("Enter username: ");
    fgets(uname,50,stdin);
    uname[strcspn(uname,"\n")] = '\0';

    printf("Enter password: ");
    fgets(pass,50,stdin);
    pass[strcspn(pass,"\n")] = '\0';

    while (fread(&u, sizeof(u), 1, fp)) {
        if (strcmp(u.username, uname) == 0 && strcmp(u.password, pass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid credentials.\n");
        return 0;
    }
}

void signup() {
    FILE *fp;
    struct user u, temp;
    int exists;

    while (1) {
        exists = 0;

        printf("Create username: ");
        fgets(u.username, 50, stdin);
        u.username[strcspn(u.username, "\n")] = '\0';

        // Open file in read mode to check duplicates
        fp = fopen("users.dat", "rb");
        if (fp != NULL) {
            while (fread(&temp, sizeof(temp), 1, fp)) {
                if (strcmp(temp.username, u.username) == 0) {
                    exists = 1;
                    break;
                }
            }
            fclose(fp);
        }

        if (exists) {
            printf("USERNAME ALREADY TAKEN. Try again.\n\n");
        } else {
            break;  // username is unique → exit loop
        }
    }

    // Now take password
    printf("Create password: ");
    fgets(u.password, 50, stdin);
    u.password[strcspn(u.password, "\n")] = '\0';

    // Open file in append mode to save user
    fp = fopen("users.dat", "ab");
    if (fp == NULL) {
        printf("File error!\n");
       exit(0);
    }

    fwrite(&u, sizeof(u), 1, fp);
    fclose(fp);

    printf("Signup successful!\n");
}
