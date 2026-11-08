#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

// Function declarations
void registration_page();
void display();
void search();
void update();
void delete_record();

// Define structure to hold student information
struct Student {
    string fname, mname, lname, sex, region, woreda, kebele;
    int age;
};
int main(){
    system("color AC");
    cout<<"     MIZAN TEPI UNIVERSITY\n";
    cout<<"     SCHOOL OF COMPUTING AND INFORMATICS\n";
	cout<<"     DEPARTMENT OF SOFTWARE ENGINEERING\n";
	cout<<" PRODICT TITIE: STUDENT REGISTRATION\n";
    cout << "   WELL COME TO STUDENT REGISTRATION" << endl;
    cout << "             GROUP 4        " << endl;
    cout << "          GROUP MEMBER" << endl;
    cout << " *************************************" << endl;
    cout << " * NAME                      ID      *" << endl;
    cout << " * DESSALEGN ASEMAMAW        4188/16 *" << endl;
    cout << " * KEFTA     GEDEFAW         4365/16 *" << endl;
    cout << " * RAHEL     WOLED           4530/16 *" << endl;
    cout << " * SOLOMON   BIRHANU         4592/16 *" << endl;
    cout << " * KATWECH    KOANG          4284/16 *" << endl;
    cout << " *************************************" << endl;
    cout<<"   press 1 continue:-";
    int n;
    cin>>n;
    system("cls");
	  
    string choice;
    do {
        cout << "PRESS=>1 TO REGISTER\n";
        cout << "PRESS=>2 TO DISPLAY ALL\n";
        cout << "PRESS=>3 TO UPDATE\n";
        cout << "PRESS=>4 TO DELETE\n";
        cout << "PRESS=>5 TO SEARCH\n";
        cout << "PRESS=>0 TO EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if(choice == "1")
            registration_page();
        else if(choice == "2")
            display();
        else if(choice == "3")
            update();
        else if(choice == "4")
            delete_record();
        else if(choice == "5")
            search();
        else if(choice == "0")
            cout << "You are out of the program\n";
        else
            cout << "You have entered an invalid choice. Please choose correctly\n";

    } while(choice != "0");

    return 0;
}


// Function to register a student
void registration_page() {
	    system("color A0");
    ofstream a;
    a.open("student_registration", ios::app);
    Student student;

    cout << "Enter your first name: ";
    cin >> student.fname;
    system("cls");

    cout << "Enter your middle name: ";
    cin >> student.mname;
    system("cls");

    cout << "Enter your last name: ";
    cin >> student.lname;
    system("cls");

    cout << "Choose your gender\n";
    string g;
    do {
        cout << "PRESS=>1 FOR MALE\n";
        cout << "PRESS=>2 FOR FEMALE\n";
        cout << "PRESS=>0 TO EXIT\n";
        cin >> g;
        system("cls");

        if(g == "1")
            student.sex = "male";
        else if(g == "2")
            student.sex = "female";
        else if(g == "0")
            cout << "You are out of the program\n";
        else
            cout << "You have entered an invalid choice. Please choose correctly\n";
    } while(g != "1" && g != "2" && g != "0");

    cout << "Enter your age: ";
    cin >> student.age;
    system("cls");

    cout << "Enter your region: ";
    cin >> student.region;
    system("cls");

    cout << "Enter your woreda: ";
    cin >> student.woreda;
    system("cls");

    cout << "Enter your kebele: ";
    cin >> student.kebele;
    system("cls");

    cout << "REGISTRATION COMPLETE" << endl;
    
    a << student.fname << "  " << student.mname << "  " << student.lname << "  " << student.sex << "  " << student.age << "  " << student.region << "  " << student.woreda << "  " << student.kebele << "\n";
    a.close();
}

// Function to display all students
void display() {
	    system("color 0C");
    ifstream a;
    a.open("student_registration");
    //display only managers our password A1B2C3
    string pass;
    cout<<"enter password:-";
    cin>>pass;
        system("cls");

    Student student;
        cout <<"first name         midel name           last name            gender           AGE              REGION              WOREDA                 KEBELE \n";
    while(a >> student.fname >> student.mname >> student.lname >> student.sex >> student.age >> student.region >> student.woreda >> student.kebele)
        cout << student.fname << "               " << student.mname << "                  " << student.lname << "                 " << student.sex << "               " << student.age << "                  " << student.region << "              " << student.woreda << "                  " << student.kebele << "\n";

    a.close();
}

// Function to search for a student by first name
void search() {
    int c = 0;
    string fn;

    ifstream a;
    a.open("student_registration");

    Student student;
    do {
        cout << "PRESS=>0 TO BACK TO MENU\n";
        cout << "Enter first name to search: ";
        cin >> fn;
        system("cls");
        a.clear();
        a.seekg(0, ios::beg);

        while(a >> student.fname >> student.mname >> student.lname >> student.sex >> student.age >> student.region >> student.woreda >> student.kebele){
            if(fn == student.fname) {
                c++;
                 cout <<"first name         midel name           last name            gender           AGE              REGION              WOREDA                 KEBELE \n";
        cout << student.fname << "               " << student.mname << "                  " << student.lname << "                 " << student.sex << "               " << student.age << "              " << student.region << "          " << student.woreda << "               " << student.kebele << "\n";
                break;
            }
        }

        if(c == 0)
            cout << "There is no data\n";

    } while(fn != "0");

    a.close();
}

// Function to update a student record
void update() {
	    system("color bC");
    string fn;
    ifstream a;
    ofstream b;
    a.open("student_registration");
    b.open("temp", ios::app);  // Open temp file in append mode

    Student student;

    cout << "Enter first name to update: ";
    cin >> fn;
    a.clear();
    a.seekg(0, ios::beg);

    while(a >> student.fname >> student.mname >> student.lname >> student.sex >> student.age >> student.region >> student.woreda >> student.kebele){
        if(fn == student.fname){
            // Update student details
            cout << "Enter your new first name: ";
            cin >> student.fname;
            system("cls");

            cout << "Enter your new middle name: ";
            cin >> student.mname;
            system("cls");

            cout << "Enter your new last name: ";
            cin >> student.lname;
            system("cls");

            cout << "Choose your new gender\n";
            string g;
            do {
                cout << "PRESS=>1 FOR MALE\n";
                cout << "PRESS=>2 FOR FEMALE\n";
                cout << "PRESS=>0 TO EXIT\n";
                cin >> g;
                system("cls");

                if(g == "1")
                    student.sex = "male";
                else if(g == "2")
                    student.sex = "female";
                else if(g == "0")
                    cout << "You are out of the program\n";
                else
                    cout << "You have entered an invalid choice. Please choose correctly\n";
            } while(g != "1" && g != "2" && g != "0");

            cout << "Enter your new age: ";
            cin >> student.age;
            system("cls");

            cout << "Enter your new region: ";
            cin >> student.region;
            system("cls");

            cout << "Enter your new woreda: ";
            cin >> student.woreda;
            system("cls");

            cout << "Enter your new kebele: ";
            cin >> student.kebele;
            system("cls");
            cout << "SUCCESSFULLY UPDATED"<<endl;
        }


        b << student.fname << "  " << student.mname << "  " << student.lname << "  " << student.sex << "  " << student.age << "  " << student.region << "  " << student.woreda << "  " << student.kebele << "\n";
    }

    a.close();
    b.close();

        remove("student_registration");
        rename("temp", "student_registration");
}

// Function to delete a student record
void delete_record() {
	    system("color AC");
    string fn;
    ifstream a;
    ofstream b;
    a.open("student_registration");
    b.open("temp", ios::app);

    Student student;

    cout << "Enter first name to delete: ";
    cin >> fn;

    a.clear();
    a.seekg(0, ios::beg);

    while(a >> student.fname >> student.mname >> student.lname >> student.sex >> student.age >> student.region >> student.woreda >> student.kebele){
        if(fn != student.fname){
            b << student.fname << "  " << student.mname << "  " << student.lname << "  " << student.sex << "  " << student.age << "  " << student.region << "  " << student.woreda << "  " << student.kebele << "\n";
        }
    }

    a.close();
    b.close();
    remove("student_registration");
    rename("temp", "student_registration");
}

