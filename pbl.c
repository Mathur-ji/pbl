/* flow of the program :  Patient → selects Doctor → chooses time → appointment confirmed

In doctor details :
Doctor Name
Specialization (e.g., Cardiology, ENT)
Available time (optional)

Doctor ID: 101
Name: Dr. Sharma
Specialization: Cardiology 
Doctor ID (unique)

In patient details :
//Typical Patient Details:

Patient ID (unique)
Patient Name
Age
Gender / Phone (optional)

steps :
Choose patient (by ID)
Choose doctor (by ID)
Choose date
Choose time
Check if doctor is free at that time

If free → confirm appointment

If not free → show “Slot not available”

*/
/*Menu for program : 
1. Add Doctor
2. Add Patient
3. Book Appointment
4. Cancel Appointment
5. View Appointments
6. Exit
*/

/* 3 structures doctor,patient,appointment
 and 5 options in menu either solvable by functions .*/
 #include<stdio.h>
 #include<string.h>
  
typedef struct doctor{
    int id;
    char name[30];
 }doctor;
 typedef struct patient{
    int id;
    char name[30];
 }pat;
 typedef struct appointment{
    int ref_no; 
    int doc_id;
     int patient_id;
     date d;
     time t;
}app;
 typedef struct date{
    int d;
    int m;
    int y;
}date;
typedef struct time{
    int hrs;
    int mins;
}time;
void main(){
}
