#include<stdio.h>
#include"hospital.h"

   void add_doc(){
   
    doctor *dptr;
    int n;
    printf("Enter no of doctors: \n");
    scanf("%d", &n);
    dptr = (doctor*)malloc(n * sizeof(doctor));
    if (dptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    FILE *f1 = fopen("doctor.txt", "a+");
    for (int i = 0; i < n; i++) {
        printf("ENTER ID NO:\n");
        scanf("%d", &dptr[i].id);
        getchar();
        printf("ENTER DOCTOR'S NAME:\n");
        fgets(dptr[i].name, 40, stdin);
        dptr[i].name[strcspn(dptr[i].name, "\n")] = '\0';
        fprintf(f1, "D-%d %s\n", dptr[i].id, dptr[i].name);
    }
    fclose(f1);
    free(dptr);
}
   void add_pat(){
   pat *mptr;
   FILE *f2;
   printf("ENTER PATIENT'S ID: \n");
   f2 = fopen("patient.txt","a+");
   mptr=(pat*)malloc(sizeof(pat));
   scanf("%d",&(mptr)->id);
   getchar();
   fgets((mptr)->name,40,stdin);
   (mptr)->name[strcspn((mptr)->name,"\n")]='\0';
   fprintf(f2,"P-%d %s",(mptr)->id,(mptr)->name);
   fclose(f2);
   free(mptr);
}
/*void bookapp(){
   
   app a1[50];
   a1[0].ref_no=00001;
   
   FILE *f3;
   f3=fopen("appointment.txt","a");
   printf("ENTER REF ID,PATIENT ID,DOCTOR ID,DATE(dd-mm-yyyy) AND TIME(hh:mm)\n");
   scanf("%d%d%d",&a1.ref_no,&a1.doc_id,&a1.patient_id);
   scanf("%d-%d-%d",&a1.d.d,&a1.d.m,&a1.d.y);
   scanf("%d:%d",&a1.t.hrs,&a1.t.mins);
   fprintf(f3,"%d %d %d ",a1.ref_no,a1.doc_id,a1.patient_id);
   fprintf(f3,"%d-%d-%d ",a1.d.d,a1.d.m,a1.d.y);
   fprintf(f3,"%d:%d",a1.t.hrs,a1.t.mins);
   fclose(f3);
   
}*/
void main(){
     int z=captcha();
     if(z==1){
     printf("1.ADD DOCTOR.\n2.ADD PATIENT.\n3.BOOK APPOINTMENT.\n4.CANCEL APPOINTMENT.\n5.VIEW APPOINTMENT.\n6.EXIT.\n");
     printf("ENTER SERVICE NO :\n");
     int n;
     scanf("%d",&n);
     getchar();
     switch(n){
         case 1: add_doc();
         break;
         case 2: add_pat();
         break;
         /*case 3: bookapp();
         break;
         /*case 4: canapp();
         break;
         case 5 : viewapp();
         break;
         case 6 : exit(0);
         break;*/
         default : printf("Inavlid\n");
         break;
      }
   }
   else
   exit(0);
}
