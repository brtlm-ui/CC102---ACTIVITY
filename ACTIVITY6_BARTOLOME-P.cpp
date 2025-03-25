#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student {
    int studentID;
    string firstName;
    string lastName;
    string course;
    float GPA;
};

const int MAX_STUDENTS = 100;
Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void editStudent();
void deleteStudent();
void viewStudents();
void displayStudentData(int index);

int main() {
    int choice;
    do {
        cout << "--Menu--\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Delete Student\n";
        cout << "4. View Students\n";
        cout << "5. Exit Program\n";
        cout << "Select an option: ";
        cin >> choice;

        system("cls");

        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: viewStudents(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student list is full!\n";
        return;
    }

    Student s;
    cout << "Enter Student ID: ";
    cin >> s.studentID;
    cout << "Enter First Name: ";
    cin >> s.firstName;
    cout << "Enter Last Name: ";
    cin >> s.lastName;
    cout << "Enter Course: ";
    cin >> s.course;
    cout << "Enter GPA: ";
    cin >> s.GPA;

    bool FoundDuplicate = false;
    do {
        FoundDuplicate = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == s.studentID) {
                cout << "Duplicate ID Found\n";
                cout << "Enter new Student ID: ";
                cin >> s.studentID;
                FoundDuplicate = true;
            }
        }
    } while (FoundDuplicate);

    students[studentCount++] = s;
    cout << "Student added successfully!\n";
}

void editStudent() {
    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }

    int id, index = -1;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Found no such record for this student id.\n";
        return;
    }

    displayStudentData(index);

    Student data;
    cout << "Enter New Student ID: ";
    cin >> data.studentID;
    cout << "Enter New First Name: ";
    cin >> data.firstName;
    cout << "Enter New Last Name: ";
    cin >> data.lastName;
    cout << "Enter New Course: ";
    cin >> data.course;
    cout << "Enter New GPA: ";
    cin >> data.GPA;

    bool FoundDuplicate = false;
    do {
        FoundDuplicate = false;
        for (int i = 0; i < studentCount; i++) {
            if (students[i].studentID == data.studentID) {
                cout << "Duplicate ID Found\n";
                cout << "Enter new Student ID: ";
                cin >> data.studentID;
                FoundDuplicate = true;
            }
        }
    } while (FoundDuplicate);

    students[index] = data;
    cout << "Student details updated successfully!\n";
}

void deleteStudent() {
    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }

    int id, index = -1;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Found no such record for this student id.\n";
        return;
    }

    displayStudentData(index);

    char option;
    cout << "Do you want to delete this student record? (y/n): ";
    cin >> option;

    if (option == 'y' || option == 'Y') {
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        cout << "Student deleted successfully!\n";
    }
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }

    cout << left << setw(10) << "ID" << setw(15) << "First Name" << setw(15) << "Last Name"
         << setw(15) << "Course" << setw(5) << "GPA" << endl;
    for (int i = 0; i < studentCount; i++) {
        displayStudentData(i);
    }
}

void displayStudentData(int index) {
    cout << left << setw(10) << students[index].studentID << setw(15) << students[index].firstName
         << setw(15) << students[index].lastName << setw(15) << students[index].course
         << setw(5) << students[index].GPA << endl;
}
