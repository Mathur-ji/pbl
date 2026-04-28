#ifndef HOSPITAL_H
#define HOSPITAL_H
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct doctor{
    int id;
    char name[30];
    char spez[30];
 }doctor;
typedef struct patient{
    int id;
    char name[30];
 }pat;
typedef struct date{
   int d;
   int m;
   int y;
}date;
typedef struct time1{
   int hrs;
   int mins;
}time1;
typedef struct appointment{
   int ref_no; 
   int doc_id;
   int patient_id;
   date d;
   time1 t;
}app;

int captcha();

#endif
