#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>

#define WIN32_LEAN_AND_MEAN

#include <windows.h>


struct Appointment { //by zaayed
    int appointment_id;
    //char appointment_date[10]; //31/12/1999 format
    int patient_id;
    int doctor_id;
    int serialNo;
    char day[10]; //SAT,12PM format

};

struct User_Patient { //by zaayed
    int patient_id;
    char name[50],
            phone[20],
            username[100],
            password[100];

};
struct User_Doctor { //by zaayed
    int doctor_id;
    char name[50],
            phone[20],
            username[100],
            password[100];
    char speciality[30];
    int maxAppointments;
    char day[10]; //sat,sun.mon.tue,wed,thr,fri
    //char time[4]; // 7AM,12PM
    // only 1 visiting hour per doc.other wise well need to loop through time array,unnecessary hassle
};
struct User_Volunteer { //by zaayed
    int volunteer_id;
    char name[50],
            phone[20],
            username[100],
            password[100];
    char bloodGroup[5];
    char location[100];

};

struct ambulance {
    int ambId;
    char ward[20];
    char thana[20];
    char ambulance_phone[20];
};

struct bloodDonor {
    int BloodDid;
    char ward[20];
    char thana[20];
    char first_name[20];
    char last_name[20];
    char blood_group[10];
    char contact_number[20];
};


int numberOfPatient = 0, numberOfDoctor = 0, numberOfVolunteer = 0, numberOfAppointment = 0, currentSerial = 0, numberOfAmbulance = 0, numberOfBloodDonor = 0;

struct User_Patient patientList[10000];
struct User_Doctor doctorList[10000];
struct User_Volunteer volunteerList[10000];
struct Appointment appointments[10000];

struct ambulance ambulanceList[10000];
struct bloodDonor bloodDonorList[10000];

struct User_Patient loggedInPatient;
struct User_Doctor loggedInDoctor;
struct User_Volunteer loggedInVolunteer;

void delay_print(char *str, unsigned int milliseconds);

void createFiles(); //by zaayed

void readFilePatient(); //by zaayed

void writeFilePatient(); //by zaayed

void readFileDoctor(); //by zaayed

void writeFileDoctor(); //by zaayed

void readFileVolunteer();

void writeFileVolunteer();

void readFileAppointment();//z

void writeFileAppointment();//z

void signUpPatient();

bool loginPatient(); //by zaayed

void updatePatientInfo(); /// By Kafi

void menuPatientSection(int takeID); /// By Kafi

int showPatientSection(); /// By Kafi

void updateDoctorInfo(); /// By Kafi

void menuDoctorSection(int takeID); /// By Kafi

int showDoctorSection(); /// By Kafi

void menuDoctorPortalLoggedIn();

int ShowMenuDoctorPortalLoggedIn();


void signUpDoctor();

bool loginDoctor(); //by zaayed

void signUpVolunteer();

bool loginVolunteer();

void loginAdmin();

void signUp();

char *getHiddenPassword(); //by zaayed

int ShowMenuMain(); //by zaayed

void menuMain(); //by zaayed

int ShowMenuEmergencyServices();

void menuEmergencyServices();

int ShowMenuPatientPortal(); //by zaayed

void menuPatientPortal(); //by zaayed

//v2 start
int ShowMenuPatientPortalLoggedIn();//z

void menuPatientPortalLoggedIn();//z

int ShowMenuMakeAppointment();//z

void menuMakeAppointment();//z

bool AppointmentConfirmation(char *);//z

void ShowAllAppointmentsPatient();

int ShowMenuDoctorsPortal(); //by zaayed

void menuDoctorsPortal(); //by zaayed

void ShowAllAppointmentsDoctor();

int SHowMenuVolunteerPortal();

void menuVolunteerPortal();

int ShowMenuAdminPortal();

void menuAdminPortal();

int ShowMenuAbout();

void menuAbout();

void test();

//by abdul ahad
void callAmbulance();

void bloodBank();

void admin();

void adminAmbulance();

void adminBloodBank();

void readFileAmbulance();

void writeFileAmbulance();

void readFileBloodDonor();

void writeFileBloodDonor();

void takeBloodDonorData();

void takeAmbulanceData();

int main() {
     delay_print("Welcome To Hilful Fudul,Your Trusted Medical Service Provider", 80);
    Sleep(200);
    printf("\nPress any key to enter\n");
    _getch();
    createFiles(); //if !exist
    menuMain();
    //test();
    return 0;
}

int ShowMenuMain() {
    int option;
    printf("------Main Menu-----\n");
    printf(" 1: Emergency Services\n");
    printf(" 2: Patient Portal\n");
    printf(" 3: Doctors Portal\n");
    printf(" 4: About\n");
    printf(" 5: Exit\n");
    printf(" Enter choice: ");
    scanf("%d", &option);
    return option;
}

void menuMain() {
    while (1) {
        system("cls");
        int m = ShowMenuMain();
        if (m == 5) {
            delay_print("Thank you for using our service", 80);
            break;
        }
        if (m == 1) {
            menuEmergencyServices();
        } else if (m == 2) {
            menuPatientPortal();
        } else if (m == 3) {
            menuDoctorsPortal();
        } else if (m == 4) {
            delay_print("Credits \n", 60);
            delay_print("Kafi C241036\n", 60);
            delay_print("Abdul Ahad C241008\n", 60);
            delay_print("Zaayed C241289\n\n", 60);
            delay_print("Special Thanks to\n", 60);
            delay_print("Jamil As-ad Sir\n", 60);

            printf("press any key and enter to go back\n");
//            char temp;
//            scanf("%c", &temp);
            _getch();

        } else printf("Please Enter a valid option\n");
    }
}

int ShowMenuPatientPortal() {
    int option;
    printf("----Authentication Menu----\n");
    printf(" 1. Sign Up\n");
    printf(" 2. Login\n");
    printf(" 3. Back\n");
    printf("Enter choice:");
    scanf("%d", &option);
    return option;

}

void menuPatientPortal() {
    while (1) {
        system("cls");
        int option = ShowMenuPatientPortal();
        if (option == 1) {
            signUpPatient();
        } else if (option == 2) {
            while (1) {

                if (loginPatient()) break;
                else printf("Login Unsuccessful\n");
            }
            menuPatientPortalLoggedIn();
        } else if (option == 3) {
            break;//does this break work or we need return?
        } else printf("Please Enter a valid option\n");
    }
}

int ShowMenuPatientPortalLoggedIn() {
    int option;
    printf("------Patient Portal-----\n");
    printf(" 1. Make an Appointment\n");
    printf(" 2. Show All Appointments\n");
    printf(" 3. Update User Info\n");
    printf(" 4. Logout\n");
    printf("Enter choice:");
    scanf("%d", &option);
    return option;
}

void menuPatientPortalLoggedIn() {
    while (1) {
        system("cls");
        int option = ShowMenuPatientPortalLoggedIn();
        if (option == 1) {
            menuMakeAppointment();
        } else if (option == 2) {
            ShowAllAppointmentsPatient();


//            char temp;
//            scanf("%c", temp);
        } else if (option == 3) {
            updatePatientInfo();
        } else if (option == 4) {
            break;
        } else printf("Please Enter a valid option\n");
    }
}

int ShowMenuMakeAppointment() {
    int option;
    printf("------Select Doctor Speciality-----\n");
    printf(" 1. Medicine\n");
    printf(" 2. Dental\n");
    printf(" 3. Orthopedics\n");
    printf(" 4. Gynaecology\n");
    printf(" 5. Neurology\n");
    printf(" 6. ENT\n");
    printf(" 7. Eye\n");
    printf(" 8. Back\n");
    printf("Enter choice:");
    scanf("%d", &option);
    return option;
}

void menuMakeAppointment() {
    while (1) {
        system("cls");
        int option = ShowMenuMakeAppointment();
        readFileDoctor();

        if (option == 1) {
            if (!AppointmentConfirmation("Medicine")) break;
        } else if (option == 2) {
            if (!AppointmentConfirmation("Dental")) break;
        } else if (option == 3) {
            if (!AppointmentConfirmation("Orthopedics")) break;
        } else if (option == 4) {
            if (!AppointmentConfirmation("Gynaecology")) break;
        } else if (option == 5) {
            if (!AppointmentConfirmation("Neurology")) break;
        } else if (option == 6) {
            if (!AppointmentConfirmation("ENT")) break;
        } else if (option == 7) {
            if (!AppointmentConfirmation("Eye")) break;
        } else if (option == 8) {
            break;
        } else printf("Please Enter a valid option\n");
    }
}

bool AppointmentConfirmation(char *speciality) {
    printf("Showing Doctors from %s speciality\n", speciality);
    printf("Doctor's ID     Doctor's Name     Appointment Time\n ");
    //printf("debug %d",numberOfDoctor);
    //printf("Debug %s",doctorList[0].name);

    for (int i = 0; i < numberOfDoctor; i++) {
        if ((stricmp(speciality, doctorList[i].speciality) == 0)) {
            printf("%*d", -9, doctorList[i].doctor_id);
            printf("     ");
            printf("%*s", -13, doctorList[i].name);
            printf("     ");
            printf("%*s\n", -16, doctorList[i].day);
            printf(" ");
            //printf("%s\n", doctorList[i].time);
        }
    }
    printf("\nEnter Doctor ID:\n");
    int doctorID;
    scanf("%d", &doctorID);


    printf("The Fee is 500tk.\n");
    printf("1. Confirm\n");
    printf("2. Go Back\n");
    printf("Enter choice:");
    int optn;
    scanf("%d", &optn);
    if (optn == 1) {
        readFileAppointment();//read all data,put into array
        if (numberOfAppointment == 0) { appointments[numberOfAppointment].appointment_id = 100; }
        else
            appointments[numberOfAppointment].appointment_id =
                    appointments[numberOfAppointment - 1].appointment_id +
                    1; //-1 cause last one in the array-2 is the previous entry

        appointments[numberOfAppointment].patient_id = loggedInPatient.patient_id;
        appointments[numberOfAppointment].doctor_id = doctorID;
        for (int i = 0; i < numberOfDoctor; i++) {
            if (doctorList[i].doctor_id == doctorID) {
                strcpy(appointments[numberOfAppointment].day,
                       doctorList[i].day);
            }
        }
        ///int currentSerial = 0;
        if (numberOfAppointment == 0) appointments[numberOfAppointment].serialNo = 1;
        else {
            for (int i = 0; i < numberOfAppointment; i++) { /// numberOfAppointment - 1 to numberOfAppointment
                if (doctorID == appointments[i].doctor_id)
                    currentSerial = appointments[i].serialNo;

            }
            appointments[numberOfAppointment].serialNo = currentSerial + 1;
        }

        numberOfAppointment++;
        writeFileAppointment();//all info updated in array,so we write into file
        return true;
    } else return false;
}

void ShowAllAppointmentsPatient() {

    //system("cls");
    readFileAppointment();
    readFileDoctor();
    printf("Appointment ID     Doctor Name     Appointment Time\n ");
//    printf("%d",numberOfAppointment);
    for (int i = 0; i < numberOfAppointment; i++) {
        if (loggedInPatient.patient_id == appointments[i].patient_id) {
            printf("%-7d", appointments[i].appointment_id);
            printf("     ");
            for (int j = 0; j < numberOfDoctor; j++) {
                if (appointments[i].doctor_id == doctorList[j].doctor_id) {
                    printf("%-7s", doctorList[j].name); /// doctorList[i].name ---> doctorList[j].name
                    break;
                }
            }
            printf("     ");
            printf("%-7s\n", appointments[i].day);

        }

    }
    printf("Press any key to go back.\n");
    _getch();
}

int showPatientSection() /// By Kafi
{
    int option;
    printf(" Which Info Do you want to Update? : \n");
    printf(" 1. Name.\n");
    printf(" 2. Phone.\n");
    printf(" 3. Back.\n");
    printf(" Enter Choice: ");
    scanf("%d", &option);

    return option;
}

void menuPatientSection(int takeID) /// By Kafi
{
    while (1) {
        system("cls");
        int option = showPatientSection();
        if (option == 3)
            return;
        else if (option == 1) {
            readFilePatient();
            char name[50];
            printf("Enter New Name: ");
            scanf(" %[^\n]s", name);
            for (int i = 0; i < numberOfPatient; i++) {
                if (takeID == patientList[i].patient_id) {
                    strcpy(patientList[i].name, name);
                    printf("Name changed successfully\n");
                    writeFilePatient();
                }
                Sleep(80);
                break;
            }
        } else {
            char phone[20];
            printf("Enter New Phone Number: ");
            scanf(" %s", phone);
            for (int i = 0; i < numberOfPatient; i++) {
                if (takeID == patientList[i].patient_id) {
                    strcpy(patientList[i].phone, phone);
                    writeFilePatient();
                }
                Sleep(10);
                break;
            }
        }
    }
}

void updatePatientInfo() /// By Kafi
{
    int takeID = loggedInPatient.patient_id;
    while (1) {
        system("cls");
        menuPatientSection(takeID);
        break;
    }
}

//doc

int ShowMenuDoctorsPortal() //by zaayed
{
    int option;
    printf("----Authentication Menu----\n");
    printf(" 1. Sign Up\n");
    printf(" 2. Login\n");
    printf(" 3. Back\n");
    printf("Enter choice:");
    scanf("%d", &option);
    return option;
}

void menuDoctorsPortal() //by zaayed
{
    while (1) {
        system("cls");
        int option = ShowMenuDoctorsPortal();
        if (option == 1) {
            signUpDoctor();

        } else if (option == 2) {
            while (1) {
                if (loginDoctor())
                    break;
                else printf("Login Unsuccessful\n");
            }

            menuDoctorPortalLoggedIn();

        } else if (option == 3) {
            break;//does this break work or we need return?
        } else printf("Please Enter a valid option\n");
    }
}


int ShowMenuDoctorPortalLoggedIn() {
    int option;
    printf("------Doctors Portal-----\n");
    printf(" 1. Show All Appointments\n");
    printf(" 2. Update User Info\n");
    printf(" 3. Logout\n");
    printf("Enter choice:");
    scanf("%d", &option);
    return option;
}


void menuDoctorPortalLoggedIn() {
    while (1) {
        system("cls");
        int option = ShowMenuDoctorPortalLoggedIn();
        if (option == 1) {
            ShowAllAppointmentsDoctor();
        } else if (option == 2) {
            updateDoctorInfo();
        } else if (option == 3) {
            break;
        } else printf("Please Enter a valid option\n");
    }
}

void ShowAllAppointmentsDoctor() {
    readFileAppointment();
    readFilePatient();
    printf("______________________________________\n");
    for (int i = 0; i < numberOfAppointment; i++) {
        if (appointments[i].doctor_id == loggedInDoctor.doctor_id) {
            printf("Appointment ID: %d\n", appointments[i].appointment_id);
            printf("Serial: %d\n", appointments[i].serialNo);
            for (int j = 0; j < numberOfPatient; j++) {
                if (appointments[i].patient_id == patientList[j].patient_id)
                    printf("Patient Name: %s\nPatient's Contact Number: %s\n", patientList[j].name, patientList[j].phone);
                ///break;
            }
            printf("______________________________________\n");
        }
    }
    printf("Press any key to continue\n");
//    char temp;
//    scanf("%c", temp);
//    printf("Press any key to go back.\n");
    _getch();
}


int showDoctorSection() /// By Kafi
{
    int option;
    printf(" Which Info Do you want to Update? : \n");
    printf(" 1. Name.\n");
    printf(" 2. Phone.\n");
    printf(" 3. Back.\n");
    printf(" Enter Choice: ");
    scanf("%d", &option);

    return option;
}

void menuDoctorSection(int takeID) /// By Kafi
{
    while (1) {
        system("cls");
        int option = showDoctorSection();
        if (option == 3)
            return;
        else if (option == 1) {
            readFileDoctor();
            char name[50];
            printf("Enter New Name: ");
            scanf(" %[^\n]s", name);
            for (int i = 0; i < numberOfDoctor; i++) {
                if (takeID == doctorList[i].doctor_id) {
                    strcpy(doctorList[i].name, name);
                    printf("Name changed successfully\n");
                    writeFileDoctor();
                }
                Sleep(100);
                break;
            }
        } else {
            char phone[20];
            printf("Enter New Phone Number: ");
            scanf(" %s", phone);
            for (int i = 0; i < numberOfDoctor; i++) {
                if (takeID == doctorList[i].doctor_id) {
                    strcpy(doctorList[i].phone, phone);
                    writeFileDoctor();
                    printf("Number changed successfully\n");
                }
                Sleep(100);
                break;
            }
        }
    }
}

void updateDoctorInfo() /// By Kafi
{
    int takeID = loggedInDoctor.doctor_id;
    while (1) {
        system("cls");
        menuDoctorSection(takeID);
        break;
    }
}


void createFiles() {
    //create files if !exist
    FILE *input = fopen("patientDB.txt", "r");
    if (input == 0) {
        input = fopen("patientDB.txt", "w");
    }
    fclose(input);

    input = fopen("doctorDB.txt", "r");
    if (input == 0) {
        input = fopen("doctorDB.txt", "w");
    }
    fclose(input);

    input = fopen("volunteerDB.txt", "r");
    if (input == 0) {
        input = fopen("volunteerDB.txt", "w");
    }
    fclose(input);

    input = fopen("appointmentDB.txt", "r");
    if (input == 0) {
        input = fopen("appointmentDB.txt", "w");
    }
    fclose(input);

    input = fopen("bloodDonor_info.txt", "r");
    if (input == 0) {
        input = fopen("bloodDonor_info.txt", "w");
    }
    fclose(input);

    input = fopen("ambulance_info.txt", "r");
    if (input == 0) {
        input = fopen("ambulance_info.txt", "w");
    }
    fclose(input);

}

void readFilePatient() {
    FILE *input = fopen("patientDB.txt", "r");
    int i = 0;
    while (fscanf(input, "%d ", &patientList[i].patient_id) == 1) {
        fscanf(input, " %[^\n]", patientList[i].name);
        fscanf(input, " %s", patientList[i].phone);
        fscanf(input, " %s", patientList[i].username);
        fscanf(input, " %s", patientList[i].password);

        i++;
    }
    numberOfPatient = i;
    fclose(input);
}

void writeFilePatient() {
    FILE *input = fopen("patientDB.txt", "w");
    for (int i = 0; i < numberOfPatient; i++) {
        fprintf(input, "%d\n", i + 1); /// Update The Process of Writing patient_id
        //fprintf(input, "%d\n", patientList[i].patient_id);
        fprintf(input, "%s\n", patientList[i].name);
        fprintf(input, "%s\n", patientList[i].phone);
        fprintf(input, "%s\n", patientList[i].username);
        fprintf(input, "%s\n", patientList[i].password);
    }
    fclose(input);
}

void readFileVolunteer() {
    FILE *input = fopen("volunteerDB.txt", "r");
    int i = 0;
    while (fscanf(input, "%d ", &volunteerList[i].volunteer_id) == 1) {
        fscanf(input, " %[^\n]", volunteerList[i].name);
        fscanf(input, " %s", volunteerList[i].phone);
        fscanf(input, " %s", volunteerList[i].username);
        fscanf(input, " %s", volunteerList[i].password);
        i++;
    }
    numberOfVolunteer = i;
    fclose(input);
}

void writeFileVolunteer() {
    FILE *input = fopen("volunteerDB.txt", "w");
    for (int i = 0; i < numberOfVolunteer; i++) {
        fprintf(input, "%d\n", i + 1); /// Update The Process of Writing volunteer_id
        //fprintf(input, "%d\n", volunteerList[i].volunteer_id);
        fprintf(input, "%s\n", volunteerList[i].name);
        fprintf(input, "%s\n", volunteerList[i].phone);
        fprintf(input, "%s\n", volunteerList[i].username);
        fprintf(input, "%s\n", volunteerList[i].password);
    }
    fclose(input);
}

void readFileDoctor() {
    FILE *input = fopen("doctorDB.txt", "r");
    int i = 0;
    while (fscanf(input, "%d ", &doctorList[i].doctor_id) == 1) {
        fscanf(input, " %[^\n]", doctorList[i].name);
        fscanf(input, " %s", doctorList[i].phone);
        fscanf(input, " %s", doctorList[i].username);
        fscanf(input, " %s", doctorList[i].password);
        fscanf(input, " %s", doctorList[i].speciality);
        fscanf(input, "%d ", &doctorList[i].maxAppointments);
        fscanf(input, " %[^\n]s", doctorList[i].day);
        i++;
    }
    numberOfDoctor = i;
    fclose(input);
}

void writeFileDoctor() {
    FILE *input = fopen("doctorDB.txt", "w");
    for (int i = 0; i < numberOfDoctor; i++) {
        fprintf(input, "%d\n", i + 1); /// Update The Process of Writing doctor_id
        //fprintf(input, "%d\n", doctorList[i].doctor_id);
        fprintf(input, "%s\n", doctorList[i].name);
        fprintf(input, "%s\n", doctorList[i].phone);
        fprintf(input, "%s\n", doctorList[i].username);
        fprintf(input, "%s\n", doctorList[i].password);
        fprintf(input, "%s\n", doctorList[i].speciality);
        fprintf(input, "%d\n", doctorList[i].maxAppointments);
        fprintf(input, "%s\n", doctorList[i].day);
    }
    fclose(input);
}

void readFileAppointment() {
    FILE *input = fopen("appointmentDB.txt", "r");
    int i = 0;
    while (fscanf(input, "%d ", &appointments[i].appointment_id) == 1) {
        //fscanf(input, "%s", appointments[i].appointment_date);
        fscanf(input, "%d", &appointments[i].patient_id);
        fscanf(input, "%d", &appointments[i].doctor_id);
        fscanf(input, "%d", &appointments[i].serialNo);
        fscanf(input, " %[^\n]s", appointments[i].day);
        i++;
    }
    numberOfAppointment = i;
    fclose(input);
}

void writeFileAppointment() {
    FILE *input = fopen("appointmentDB.txt", "w");
    for (int i = 0; i < numberOfAppointment; i++) {
        fprintf(input, "%d\n", i + 1); /// Update The Process of Writing appointment_id
        ///fprintf(input, "%d\n", appointments[i].appointment_id);
        //fprintf(input, "%s\n", appointments[i].appointment_date);
        fprintf(input, "%d\n", appointments[i].patient_id);
        fprintf(input, "%d\n", appointments[i].doctor_id);
        fprintf(input, "%d\n", appointments[i].serialNo);
        fprintf(input, "%s\n", appointments[i].day);

    }
    fclose(input);
}



void signUpPatient() /// By Kafi
{
    readFilePatient();
    printf("------Signup Menu-----\n");
    printf("Enter Name: \n");
    scanf(" %[^\n]s", patientList[numberOfPatient].name);
    printf("Enter Phone Number: \n");
    scanf(" %s", patientList[numberOfPatient].phone);
    printf("Enter Username: \n");
    scanf(" %s", patientList[numberOfPatient].username);
    printf("Enter Password: \n");
    scanf(" %s", patientList[numberOfPatient].password);

    numberOfPatient++;
    writeFilePatient();
}

void signUpDoctor() /// By Kafi
{
    readFileDoctor();
    printf("------Signup Menu-----\n");
    printf(" Please Enter Your Name: \n");
    scanf(" %[^\n]s", doctorList[numberOfDoctor].name);
    printf(" Enter Phone Number: \n");
    scanf(" %s", doctorList[numberOfDoctor].phone);
    printf(" Enter Your Specialty: \n");
    scanf(" %s", doctorList[numberOfDoctor].speciality);
    printf(" Enter a User name: \n");
    scanf(" %s", doctorList[numberOfDoctor].username);
    printf(" Enter Password: \n");
    scanf(" %s", doctorList[numberOfDoctor].password);

    numberOfDoctor++;
    writeFileDoctor();
}

void signUpVolunteer() /// By Kafi
{
    readFileVolunteer();
    printf("------Signup Menu-----\n");
    printf(" Please Enter Your Name: \n");
    scanf(" %[^\n]s", volunteerList[numberOfVolunteer].name);
    printf(" Enter Phone Number: \n");
    scanf(" %s", volunteerList[numberOfVolunteer].phone);
    printf(" Enter Your Blood Group: \n");
    scanf(" %s", volunteerList[numberOfVolunteer].bloodGroup);
    printf(" Enter Your Location: \n");
    scanf(" %s", volunteerList[numberOfVolunteer].location);
    printf(" Enter a User name: \n");
    scanf(" %s", volunteerList[numberOfVolunteer].username);
    printf(" Enter Password: \n");
    scanf(" %s", volunteerList[numberOfVolunteer].password);

    numberOfVolunteer++;
    writeFileVolunteer();
}

bool loginPatient() {
    readFilePatient();
    char username[100];
    char *password; //pointer so that we can use hiddenPass function and handle return
    printf("Enter Username:\n ");
    scanf("%s", username);

    for (int i = 0; i < numberOfPatient; i++) {
        if (strcmp(username, patientList[i].username) == 0) {
            password = getHiddenPassword();
            if (strcmp(password, patientList[i].password) == 0) {
                printf("Login successful\n");
                loggedInPatient.patient_id = patientList[i].patient_id;
                strcpy(loggedInPatient.username, patientList[i].username);
                return true;
            } else {
                printf("Password didn't match\n");
                return false;
            }
        }

        if (i == numberOfPatient - 1) {
            printf("Username not found\n");
            return false;
        }
    }
}

bool loginDoctor() {
    readFileDoctor();
    char username[100];
    char *password; //pointer so that we can use hiddenPass function and handle return
    printf("Enter Username:\n ");
    scanf("%s", username);

    for (int i = 0; i < numberOfDoctor; i++) {
        if (strcmp(username, doctorList[i].username) == 0) {
            password = getHiddenPassword();
            if (strcmp(password, doctorList[i].password) == 0) {
                printf("Login successful\n");
                loggedInDoctor.doctor_id = doctorList[i].doctor_id;
                strcpy(loggedInDoctor.username, doctorList[i].username);
                return true;
            } else {
                printf("Password didn't match\n");
                return false;
            }
        }

        if (i == numberOfDoctor - 1) {
            printf("Username not found\n");
            return false;
        }
    }
}

bool loginVolunteer() {
    readFileVolunteer();
    char username[100];
    char *password; //pointer so that we can use hiddenPass function and handle return
    printf("Enter Username:\n ");
    scanf("%s", username);

    for (int i = 0; i < numberOfVolunteer; i++) {
        if (strcmp(username, volunteerList[i].username) == 0) {
            password = getHiddenPassword();
            if (strcmp(password, volunteerList[i].password) == 0) {
                printf("Login successful\n");
                loggedInVolunteer.volunteer_id = volunteerList[i].volunteer_id;
                strcpy(loggedInVolunteer.username, volunteerList[i].username);
                return true;
            } else {
                printf("Password didn't match\n");
                return false;
            }
        }

        if (i == numberOfVolunteer - 1) {
            printf("Username not found\n");
            return false;
        }
    }
}


char *getHiddenPassword() { //done
    static char password[100]; // Static array to hold the password

    printf("Enter password:\n");
    int p = 0;
    do {
        password[p] = getch(); // getch() takes input from terminal without echo. meaning it doesnt show the chars user writes in the terminal. it might not work properly in all os .
        if (password[p] != '\r') {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');
    password[p - 1] = '\0'; //puts \0 and Terminate the string
    printf("\n");
    return password;
}

void test() {
    loginPatient();
    readFileDoctor();
    readFileAppointment();
    menuMakeAppointment();
    ShowAllAppointmentsPatient();

}

void delay_print(char *str, unsigned int milliseconds) {
    for (; *str; str++) {
        putchar(*str);
        fflush(stdout);
        Sleep(milliseconds);
    }
}

/// by Abdul Ahad

void menuEmergencyServices() {

    int choice = 0;
    while(1)
    {
        system("cls");
        printf("=====Emergency Services=====\n");
        printf("1. Call Ambulance\n");
        printf("2. Blood Donors \n");
        printf("3. Admin\n");
        printf("4. exit\n");
        printf("_________________________\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 4)
            break;
        else if(choice == 1)
        {
            callAmbulance();
            printf("Press any key to continue\n");
            _getch();
        }
        else if(choice == 2)
        {
            bloodBank();
            printf("Press any key to continue\n");
            _getch();
        }
        else
        {
//            printf("Press any key to continue\n");
//            getchar(); // to consume the newline character left by scanf
//            getchar(); // to wait for the user to press a key
            admin();
        }
    }
}

void readFileAmbulance()
{
    FILE* input = fopen("ambulance_info.txt", "r");
    int i = 0;
    while(fscanf(input, "%d", &ambulanceList[i].ambId) == 1)
    {
        fscanf(input, " %[^\n]s", ambulanceList[i].ward);
        fscanf(input, " %[^\n]s", ambulanceList[i].thana);
        fscanf(input, " %s", ambulanceList[i].ambulance_phone);
        i++;
    }
    numberOfAmbulance = i;
    fclose(input);
}

void writeFileAmbulance()
{
    FILE* input = fopen("ambulance_info.txt", "w");

    for(int i = 0; i < numberOfAmbulance; i++)
    {
        fprintf(input, "%d\n", i + 1);
        fprintf(input, "%s\n", ambulanceList[i].ward);
        fprintf(input, "%s\n", ambulanceList[i].thana);
        fprintf(input, "%s\n", ambulanceList[i].ambulance_phone);
    }
    fclose(input);
}

void readFileBloodDonor()
{
    FILE* input = fopen("bloodDonor_info.txt", "r");
    int i = 0;
    while(fscanf(input, "%d", &bloodDonorList[i].BloodDid) == 1)
    {
        fscanf(input, " %[^\n]s", bloodDonorList[i].first_name);
        fscanf(input, " %[^\n]s", bloodDonorList[i].last_name);
        fscanf(input, " %[^\n]s", bloodDonorList[i].blood_group);
        fscanf(input, " %[^\n]s", bloodDonorList[i].ward);
        fscanf(input, " %[^\n]s", bloodDonorList[i].thana);
        fscanf(input, " %[^\n]s", bloodDonorList[i].contact_number);
        i++;
    }
    numberOfBloodDonor = i;
    fclose(input);
}

void writeFileBloodDonor()
{
    FILE* input = fopen("bloodDonor_info.txt", "w");
    for(int i = 0; i < numberOfBloodDonor; i++)
    {
        fprintf(input, "%d\n", i + 1);
        fprintf(input, "%s\n", bloodDonorList[i].first_name);
        fprintf(input, "%s\n", bloodDonorList[i].last_name);
        fprintf(input, "%s\n", bloodDonorList[i].blood_group);
        fprintf(input, "%s\n", bloodDonorList[i].ward);
        fprintf(input, "%s\n", bloodDonorList[i].thana);
        fprintf(input, "%s\n", bloodDonorList[i].contact_number);
    }
    fclose(input);
}

void callAmbulance() {
    readFileAmbulance();

    printf("======All Ambulance Hotlines======\n");

    printf("__________________________________\n");

    for(int i = 0; i < numberOfAmbulance; i++)
    {
        printf("Location : %s, %s\n", ambulanceList[i].ward, ambulanceList[i].thana);
        printf("Ambulance Station Hot line : %s\n", ambulanceList[i].ambulance_phone);
        printf("______________________________\n");
    }
}

void bloodBank() {
    readFileBloodDonor();

    printf("======All Donors Information======\n");

    printf("__________________________________\n");

    for(int i = 0; i < numberOfBloodDonor; i++)
    {
        printf("Name : %s %s\n", bloodDonorList[i].first_name, bloodDonorList[i].last_name);
        printf("Blood group : %s\n", bloodDonorList[i].blood_group);
        printf("Contact number : %s\n", bloodDonorList[i].contact_number);
        printf("Present address : %s, %s\n", bloodDonorList[i].ward, bloodDonorList[i].thana);
        printf("______________________________\n");
    }

}

void admin() {

    int choice;
    while (1) {
        system("cls");
        printf("1. Add Ambulance Data\n");
        printf("2. Add Blood Donor\n");
        printf("3. Exit\n");
        printf("__________________________\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        if(choice == 3)
            break;
        else if(choice == 1)
        {
            takeAmbulanceData();
        }
        else
        {
            takeBloodDonorData();
        }
    }
}

void takeAmbulanceData()
{
    readFileAmbulance();
    char another;
    do
    {
        printf("======Add Ambulance info======\n\n\n");
        printf("Enter Ward : \n");
        scanf(" %s", ambulanceList[numberOfAmbulance].ward);
        printf("Enter Thana: \n");
        scanf(" %s", ambulanceList[numberOfAmbulance].thana);
        printf("Enter Ambulance Number: \n");
        scanf(" %s", ambulanceList[numberOfAmbulance].ambulance_phone);

        printf("______________________\n");

        printf("Record stored successfully\n");

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &another);
    } while (another == 'y' || another == 'Y');

    numberOfAmbulance++;

    writeFileAmbulance();
}

void takeBloodDonorData()
{
    readFileBloodDonor();
    char another;
    do
    {
        printf("======Add Donor Info======\n\n\n");
        printf("Enter first Name : \n");
        scanf(" %s", bloodDonorList[numberOfBloodDonor].first_name);
        printf("Enter last Name : \n");
        scanf(" %s", bloodDonorList[numberOfBloodDonor].last_name);
        printf("Enter your blood group : \n");
        scanf(" %s", bloodDonorList[numberOfBloodDonor].blood_group);
        printf("Enter your present address : \n");
        printf("\tWard : ");
        scanf(" %s", bloodDonorList[numberOfBloodDonor].ward);
        printf("\tThana : ");
        scanf(" %s", bloodDonorList[numberOfBloodDonor].thana);

        printf("Enter contact number : \n");
        scanf(" %s", bloodDonorList[numberOfBloodDonor].contact_number);

        printf("______________________\n");

        printf("Record stored successfully\n");

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &another);

    } while (another == 'y' || another == 'Y');

    numberOfBloodDonor++;

    writeFileBloodDonor();
}
