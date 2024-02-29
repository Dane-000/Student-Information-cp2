#include <iostream>
#include <string>
#include <cstdlib> // for system("cls") or system("clear")
using namespace std;
const int Max_Students = 100;
struct Student {
    string firstName;
    string lastName;
    string section;
    int year;
    string course;
};
void DisplayMenu();
void ClearInputBuffer();
void AddStudent(Student students[], int& studentCount);
void ShowStudents(Student students[], int studentCount);
void DisplayMenu() {
    cout << "\nStudent Information\n";
    cout << "-------------------\n";
    cout << "Menu:\n";
    cout << "1. Add\n";
    cout << "2. Show\n";
    cout << "Enter your choice: ";
}
void ClearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void AddStudent(Student students[], int& studentCount) {
    if (studentCount < Max_Students) {
        cout << "Enter first name: ";
        cin.ignore();
        getline(cin, students[studentCount].firstName);
        cout << "Enter last name: ";
        getline(cin, students[studentCount].lastName);
        cout << "Enter section: ";
        getline(cin, students[studentCount].section);
        cout << "Enter year: ";
        cin >> students[studentCount].year;
        ClearInputBuffer();
        cout << "Enter course: ";
        cin.ignore();
        getline(cin, students[studentCount].course);
        studentCount++;
        system("cls"); // or system("clear")
    }
    else {
        cout << "Maximum number of students reached.\n";
    }
}
void ShowStudents(Student students[], int studentCount) {
    const int STUDENTS_PER_PAGE = 5;
    int totalPages = (studentCount - 1) / STUDENTS_PER_PAGE + 1;
    int currentPage = 0;
    char option;
    do {
        system("cls"); // or system("clear")
        cout << "Page " << currentPage + 1 << " of " << totalPages << "\n";
        for (int i = currentPage * STUDENTS_PER_PAGE; i < min((currentPage + 1) * STUDENTS_PER_PAGE, studentCount); ++i) {
            cout << "\nStudent " << i + 1 << "\n"
                << "First Name: " << students[i].firstName << "\n"
                << "Last Name: " << students[i].lastName << "\n"
                << "Course: " << students[i].course << "\n"
                << "Year: " << students[i].year << "\n";
        }
        cout << "N - Next Page, P - Previous Page, E - Exit to Main Menu\n";
        cout << "Enter option: ";
        cin >> option;
        switch (option) {
        case 'N':
        case 'n':
            if (currentPage < totalPages - 1) {
                currentPage++;
            }
            break;
        case 'P':
        case 'p':
            if (currentPage > 0) {
                currentPage--;
            }
            break;
        }
    } while (option != 'E' && option != 'e');
}
int main() {
    Student students[Max_Students];
    int studentCount = 0;
    int choice;
    do {
        DisplayMenu();
        cin >> choice;
        if (choice != 1 && choice != 2) {
            ClearInputBuffer();
            continue;
        }
        switch (choice) {
        case 1:
            AddStudent(students, studentCount);
            break;
        case 2:
            ShowStudents(students, studentCount);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}
