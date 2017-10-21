/* @Author
 * Student Name: Ali Doruk Gezici
 * Student ID : 150150301
 * Date: 17.10.2017
 */

#include <iostream>
#include <string>
#include "studentInfo.h"
#include "surnameMap.h"
#include "surnameMapList.h"

using namespace std;

int get_choice();
void execute_choice(int choice, surnameMapList *surnames);
void list_students(surnameMapList *surnames);

int main() {
    // Linked lists
    surnameMapList surnames;
    surnames.createList();
    // Menu
    int choice = 1;
    while (choice != 0) {
        choice = get_choice();
        execute_choice(choice, &surnames);
    }; return 0;
}

void execute_choice(int choice, surnameMapList *surnames) {
    switch (choice) {
        case 0: {
            cout << "Exiting..." << endl;
            break;
        }
        case 1: {
            cout << "Creating surnameMapList..." << endl;
            surnames->createList();
            break;
        } case 2: {
            string file_name = "dataset_wOutTurkishChars.txt";
            char c;
            cout << "Dou you want to enter the file name manually? (y/n): ";
            cin >> c;
            switch (c) {
                case 'y': case 'Y':
                    cout << endl << "Enter file name: ";
                    cin >> file_name;
                    break;
                case 'n': case 'N':
                    cout << endl << "Using " << file_name << "..." << endl;
                    break;
                default:
                    cout << endl << "Wrong option. Please try again..." << endl;
                    break;
            }
            surnames->insertAll(file_name);
            list_students(surnames);
            break;
        } case 3: {
            string name, surname;
            cout << "Name of the student you want to add: ";
            cin >> name;
            cout << endl << "Surname: ";
            cin >> surname;
            surnames->insertNewRecord(name, surname);
            break;
        } case 4: {
            string name, surname;
            cout << "Name of the student you want to delete: ";
            cin >> name;
            cout << endl << "Surname: ";
            cin >> surname;
            surnames->deleteStudent(name, surname);
            break;
        } case 5: {
            string surname;
            cout << "Surname you want to delete: ";
            cin >> surname;
            surnames->deleteSurnameNode(surname);
            break;
        } case 6: {
            break;
        } case 7: {
            cout << "Writing to file emailList.txt..." << endl;
            surnames->writeToFile();
            break;
        } case 8: {
            list_students(surnames);
            break;
        } default: {
            cout << "Wrong choice, please try again!" << endl;
            break;
        }
    }
    return;
}

int get_choice() {
    cout << endl << "e-mail Address Program" << endl;
    cout << "0) Exit" << endl;
    cout << "1) Create" << endl;
    cout << "2) Insert All" << endl;
    cout << "3) Insert New Record" << endl;
    cout << "4) Delete Student" << endl;
    cout << "5) Delete Surname Node" << endl;
    cout << "6) Update" << endl;
    cout << "7) Write to File" << endl;
    cout << "8) Print List" << endl;
    cout << endl << "Enter a choice: ";
    int choice;
    cin >> choice;
    return choice;
}

void list_students(surnameMapList *surnames) {
    surnameMap *ptr = surnames->head;
    for (int i = 0; i < surnames->count; i++) {
        cout << "SURNAME: " << ptr->surname << endl;
        studentInfo *ptr2 = ptr->head;
        for (int j = 0; j < ptr->count; j++) {
            cout << '\t' << ptr2->name << " " << ptr2->surname << " - " << ptr2->email << endl;
            ptr2 = ptr2->next;
        }
        cout << "--------------------------------------" << endl;
        ptr = ptr->next;
    }
}
