#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
using namespace std;
struct Course {
    string name;
    float creditHour;
    float mark;
    string grade; 
};
struct Student {
    int ID;
    string fname;
    string lname;
    string sex;
    int age;
    int year;
    string semester;
    string department; 
    float CGPA;
    int numCourses;    
    Course *courses;   
};
void CreateStudentRecord(Student students[], int &n);
void SearchStudentRecord(Student students[], int n);
void DisplayAllStudentRecords(Student students[], int n);
void DeleteStudentRecord(Student students[], int &n);
void ModifyStudentRecord(Student students[], int &n);
void SaveToFile(Student students[], int n);
void LoadFromFile(Student students[], int &n);
bool IsDuplicateID(Student students[], int n, int id); 
string CalculateGrade(float mark) {
    if (mark >= 90 && mark<=100) return "A+";
    else if (mark >= 85) return "A";
    else if (mark >= 80) return "A-";
    else if (mark >= 75) return "B+";
    else if (mark >= 70) return "B";
    else if (mark >= 65) return "B-";
    else if (mark >= 60) return "C+";
    else if (mark >= 50) return "C";
    else if (mark >= 45) return "C-";
    else if (mark >= 40) return "D+";
    else if (mark >= 30) return "D";
    else return "F";
}
void CalculateCGPA(Student &student) {
    float totalGradePoints = 0;
    float totalCreditHours = 0;
    for (int i = 0; i < student.numCourses; i++) {
        if (student.courses[i].grade == "A+") totalGradePoints += 4.0 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "A") totalGradePoints += 4.0 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "A-") totalGradePoints += 3.75 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "B+") totalGradePoints += 3.5 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "B") totalGradePoints += 3.0 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "B-") totalGradePoints += 2.75 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "C+") totalGradePoints += 2.5 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "C") totalGradePoints += 2.0 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "C-") totalGradePoints += 1.75 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "D+") totalGradePoints += 1.5 * student.courses[i].creditHour;
        else if (student.courses[i].grade == "D") totalGradePoints += 1.0 * student.courses[i].creditHour;
        else totalGradePoints += 0.0 * student.courses[i].creditHour;
        totalCreditHours += student.courses[i].creditHour;
    }
    student.CGPA = totalGradePoints / totalCreditHours;
}
void DisplayHeader() {
   }
int main() {
    Student students[100];
    int n = 0;
    int choice;
{
    cout << "=========================================================\n";
    cout << "===         MIZAN TEPI UNIVERSITY                     ===\n";
    cout << "===               TEPI CAMPUS                         ===\n";
    cout << "=== COLLEGE OF COMPUTING AND INFORMATICS              ===\n";
    cout << "=== DEPARTEMANT: INFORMATION TECHNOLOGY               ===\n";
    cout << "=== COURSE TITLE: FUNDAMENTALS OF PROGRAMMING ||      ===\n";
    cout << "=== COURESE CODE: ITec2041                            ===\n";
    cout << "===      GROUP THREE(3) ASSIGNMENT                    ===\n";
    cout << "=== ASSIGNMENT TITLE: STUDENT GRADE REPORT SYSTEM     ===\n";
    cout << "===          SECTION: A                               ===\n";
    cout << "=== NAME                                  ID NO/      ===\n";
    cout << "=== AFRANO KINATO                      MTUUR/8919/17  ===\n";
    cout << "=== AMANUEL DERIGISA                   MTUUR/8970/17  ===\n";
    cout << "=== BAYE ASNAKE                        MTUUR/8832/17  ===\n";
    cout << "=== BEWKET ABIE                        MTUUR/7822/17  ===\n";
    cout << "=== BEZAWIT PETROS                     MTUUR/7776/17  ===\n";
    cout << "=== HUSSEN OMERE                       MTUUR/7787/17  ===\n";
    cout << "=========================================================\n";
    cout << "                    SUBMITTED TO Mr. Abraham D           \n";
    cout << "                    SUMMATION DATE  24/04/2018           \n";
}
    LoadFromFile(students, n); 
    do {
        DisplayHeader();
        cout << "1. Create Student Record\n";
        cout << "2. Search Student Record by ID\n";
        cout << "3. Display All Student Records\n";
        cout << "4. Delete Student Record\n";
        cout << "5. Modify Student Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                CreateStudentRecord(students, n);
                SaveToFile(students, n); 
                break;
            case 2:
                SearchStudentRecord(students, n);
                break;
            case 3:
                DisplayAllStudentRecords(students, n);
                break;
            case 4:
                DeleteStudentRecord(students, n);
                SaveToFile(students, n);
                break;
            case 5:
                ModifyStudentRecord(students, n);
                SaveToFile(students, n); 
                break;
            case 6:
                SaveToFile(students, n); 
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    for (int i = 0; i < n; i++) {
        delete[] students[i].courses;
    }
    return 0;
}
void CreateStudentRecord(Student students[], int &n) {
    if (n >= 100) {
        cout << "Cannot add more students. Limit reached.\n";
        return;
    }
    Student &student = students[n];
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    if (IsDuplicateID(students, n, id)) {
        cout << "Student with this ID already exists. Please enter a different ID.\n";
        return;
    }
    student.ID = id;
    cout << "Enter first name: ";
    cin >> student.fname;
    cout << "Enter last name: ";
    cin >> student.lname;
    cout << "Enter sex: ";
    cin >> student.sex;
    cout << "Enter age: ";
    cin >> student.age;
    cout << "Enter year(only in number): ";
    cin >> student.year;
    cout << "Enter semester: ";
    cin >> student.semester;
    cout << "Enter department: ";
    cin >> student.department;
    cout << "Enter the number of courses: ";
    cin >> student.numCourses;
    student.courses = new Course[student.numCourses];
    for (int i = 0; i < student.numCourses; i++) {
        cout << "Enter course " << i + 1 << " name: ";
        cin >> student.courses[i].name;
        cout << "Enter course " << i + 1 << " credit hour: ";
        cin >> student.courses[i].creditHour;
        cout << "Enter course " << i + 1 << " mark: ";
        cin >> student.courses[i].mark;
        student.courses[i].grade = CalculateGrade(student.courses[i].mark);
    }
    CalculateCGPA(student);
    n++;
    cout << "Student record created successfully!\n";
}
bool IsDuplicateID(Student students[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (students[i].ID == id) {
            return true;
        }
    }
    return false;
}
void SearchStudentRecord(Student students[], int n) {
    int id;
    cout << "Enter student ID to search: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].ID == id) {
            cout << "\nStudent found:\n";
            cout << "--------------------------------------------\n";
            cout << "ID: " << students[i].ID << "\n";
            cout << "Name: " << students[i].fname << " " << students[i].lname << "\n";
            cout << "Sex: " << students[i].sex << "\n";
            cout << "Age: " << students[i].age << "\n";
            cout << "Year: " << students[i].year << "\n";
            cout << "Semester: " << students[i].semester << "\n";
            cout << "Department: " << students[i].department << "\n";
            cout << "CGPA: " << fixed << setprecision(2) << students[i].CGPA << "\n";
            cout << "Courses:\n";
            for (int j = 0; j < students[i].numCourses; j++) {
                cout << "  " << students[i].courses[j].name << " (Credit: " << students[i].courses[j].creditHour
                     << ", Mark: " << students[i].courses[j].mark << ", Grade: " << students[i].courses[j].grade << ")\n";
            }
            cout << "--------------------------------------------\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
void DisplayAllStudentRecords(Student students[], int n) {
    if (n == 0) {
        cout << "No student records found.\n";
        return;
    }
    cout << "\nAll Student Records:\n";
    cout << "==================================================================================================================================\n";
    cout << setw(5) << "ID" << setw(15) << "Name" << setw(10) << "Sex" << setw(5) << "Age" << setw(10) << "Year" << setw(10) << "Semester" << setw(20) << "Department" << setw(10) << "CGPA" << "\n";
    cout << "==================================================================================================================================\n";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << students[i].ID
             << setw(15) << students[i].fname + " " + students[i].lname
             << setw(10) << students[i].sex
             << setw(5) << students[i].age
             << setw(10) << students[i].year
             << setw(10) << students[i].semester
             << setw(20) << students[i].department
             << setw(10) << fixed << setprecision(2) << students[i].CGPA << "\n";
    }
    cout << "==================================================================================================================================\n";
}
void DeleteStudentRecord(Student students[], int &n) {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].ID == id) {
            delete[] students[i].courses;
            for (int j = i; j < n - 1; j++) {
                students[j] = students[j + 1];
            }
            n--;
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
void ModifyStudentRecord(Student students[], int &n) {
    int id;
    cout << "Enter student ID to modify: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (students[i].ID == id) {
            cout << "Enter new first name: ";
            cin >> students[i].fname;
            cout << "Enter new last name: ";
            cin >> students[i].lname;
            cout << "Enter new sex: ";
            cin >> students[i].sex;
            cout << "Enter new age: ";
            cin >> students[i].age;
            cout << "Enter new year: ";
            cin >> students[i].year;
            cout << "Enter new semester: ";
            cin >> students[i].semester;
            cout << "Enter new department: ";
            cin >> students[i].department;
            cout << "Enter the number of courses: ";
            cin >> students[i].numCourses;
            delete[] students[i].courses;
            students[i].courses = new Course[students[i].numCourses];
            for (int j = 0; j < students[i].numCourses; j++) {
                cout << "Enter course " << j + 1 << " name: ";
                cin >> students[i].courses[j].name;
                cout << "Enter course " << j + 1 << " credit hour: ";
                cin >> students[i].courses[j].creditHour;
                cout << "Enter course " << j + 1 << " mark: ";
                cin >> students[i].courses[j].mark;
                students[i].courses[j].grade = CalculateGrade(students[i].courses[j].mark);
            }
            CalculateCGPA(students[i]);
            cout << "Student record modified successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
void SaveToFile(Student students[], int n) {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        file << students[i].ID << " "
             << students[i].fname << " "
             << students[i].lname << " "
             << students[i].sex << " "
             << students[i].age << " "
             << students[i].year << " "
             << students[i].semester << " "
             << students[i].department << " "
             << students[i].CGPA << " "
             << students[i].numCourses << " ";
        for (int j = 0; j < students[i].numCourses; j++) {
            file << students[i].courses[j].name << " "
                 << students[i].courses[j].creditHour << " "
                 << students[i].courses[j].mark << " "
                 << students[i].courses[j].grade << " ";
        }
        file << "\n";
    }
    file.close();
}
void LoadFromFile(Student students[], int &n) {
    ifstream file("students.txt");
    if (!file) {
        cout << "No existing student records found.\n";
        return;
    }
    while (file >> students[n].ID
                >> students[n].fname
                >> students[n].lname
                >> students[n].sex
                >> students[n].age
                >> students[n].year
                >> students[n].semester
                >> students[n].department
                >> students[n].CGPA
                >> students[n].numCourses) {
        students[n].courses = new Course[students[n].numCourses];
        for (int j = 0; j < students[n].numCourses; j++) {
            file >> students[n].courses[j].name
                 >> students[n].courses[j].creditHour
                 >> students[n].courses[j].mark
                 >> students[n].courses[j].grade;
        }
        n++;
    }
    file.close();
}