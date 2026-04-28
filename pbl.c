#include<stdio.h>
#include"hospital.h"
#include"auth.h"

void add_doc(){
   doctor d;
   int n;
   printf("Enter no of doctors : ");
   scanf("%d", &n);
   fflush(stdin);
   FILE *f1 = fopen("doctor.txt", "a+");
   for (int i = 0; i < n; i++) {
      printf("ENTER ID NO : ");
      scanf("%d", &d.id);
      getchar();
      printf("ENTER DOCTOR'S NAME(in caps) : ");
      fgets(d.name, 40, stdin);
      d.name[strcspn(d.name, "\n")] = '\0';
      fprintf(f1, "D-%d %s\n", d.id, d.name);
    }
    fclose(f1);
   }
   void add_pat(){
   pat p;
   FILE *f2;
   f2 = fopen("patient.txt","a+");
   printf(" KINDLY ENTER PATIENT'S ID : ");
   scanf("%d",&p.id);
   getchar();
   printf(" PLEASE ENTER PATIENT'S NAME(IN CAPS): ");
   fgets(p.name,40,stdin);
   p.name[strcspn(p.name,"\n")]='\0';
   fprintf(f2,"\nP-%d %s",p.id,p.name);
   fclose(f2);
}
void bookapp(){
   app a1;
   FILE *f3;
   f3=fopen("appointment.txt","a+");
   printf("ENTER REFERENCE/APPOINTMENT ID : ");
   scanf("%d",&a1.ref_no); 
   fprintf(f3,"\nA-%d",a1.ref_no);
   printf("ENTER PATIENT ID : ");
   scanf("%d",&a1.patient_id);
   fprintf(f3," Patient_id : P-%d",a1.patient_id);
   printf("ENTER DOCTOR ID : ");
   scanf("%d",&a1.doc_id);
   fprintf(f3," Doctor_id : D-%d",a1.doc_id);
   printf("ENTER DATE(dd-mm-yyyy) : ");
   scanf("%d-%d-%d",&a1.d.d,&a1.d.m,&a1.d.y);
   fprintf(f3," Date : %d-%d-%d",a1.d.d,a1.d.m,a1.d.y);
   printf("ENTER TIME (hh:mm) : ");
   scanf("%d:%d",&a1.t.hrs,&a1.t.mins);
   fprintf(f3," Time : %d:%d",a1.t.hrs,a1.t.mins);
   fclose(f3);
}
void viewapp() {
    FILE *f3;
    char ch;

    f3 = fopen("appointment.txt", "r");
    if (f3 == NULL) {
        printf("File error\n");
        exit(0);
    }

    while ((ch = fgetc(f3)) != EOF) {
        printf("%c", ch);
    }

    fclose(f3);
}

void main(){
    system("cls");
    printf("\t                 ===============================\n");
    printf("\t                             +++++\n");
    printf("\t                             +++++\n");
    printf("\t                    +++++++++++++++++++++++++\n");
    printf("\t                    +        WELCOME        +\n");
    printf("\t                    +    CITY HOSPITAL ERP  +\n");
    printf("\t                    +++++++++++++++++++++++++\n");
    printf("\t                             +++++\n");
    printf("\t                             +++++\n");
    printf("\t                ===============================\n");
    printf("\v\tPRESS ANY KEY TO START\n");
    getchar();
    system("cls");
    int choice, z, flag = 0;

    printf("\n--- HOSPITAL MANAGEMENT SYSTEM ---\n");
    printf("1. Sign In\n2. Sign Up\nEnter choice: ");
    scanf("%d", &choice);
    while(getchar() != '\n');

    if (choice == 1) {
        if (login()) {
            flag = 1;
        }
    } else if (choice == 2) {
        signup();
        printf("\nAccount created! Please login to continue.\n");
        if (login()) flag = 1;
    }

    // Only move to Captcha and Menu if logged in
    if (flag) {
    int z;
        z = captcha(); // Ensure this returns 1 on success!
        if (z == 1) {
            int n, t;
            do {
                printf("1.ADD DOCTOR.\n2.ADD PATIENT.\n3.BOOK APPOINTMENT.\n4.VIEW APPOINTMENT.\n5.EXIT.\n");
                printf("ENTER SERVICE NO: ");
                scanf("%d", &n);
              fflush(stdin);
                
                switch(n) {
                    case 1: add_doc(); break;
                    case 2: add_pat(); break;
                    case 3: bookapp(); break;
                    case 4: viewapp(); break;
                    case 5: exit(0);
                    default: printf("Invalid choice.\n");
                }
                printf("\nPress 1 to continue or 0 to exit: ");
                scanf("%d", &t);
                fflush(stdin);
            } while(t==1);
            printf("\n ........THANK YOU FOR CHOOSING US........");
        } else {
            printf("\nCaptcha Failed! Access Denied.\n");
        }
    } else {
        printf("\nLogin Required. Thank you!\n");
    }
}
