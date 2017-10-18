//
//  main.cpp
//  Data HW - 2
//
//  Created by Doruk Gezici on 17.10.2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include <iostream>
#include <string>
#include "studentInfo.h"
#include "surnameMap.h"
#include "surnameMapList.h"

using namespace std;

int get_choice();
void apply_choice(int choice, surnameMapList *surnames);

int main() {
    // Linked lists
    surnameMapList surnames;
    surnames.createList();
    // Menu
    int choice = 1;
    while (choice != 0) {
        choice = get_choice();
        apply_choice(choice, &surnames);
    }; return 0;
}

void apply_choice(int choice, surnameMapList *surnames) {
    switch (choice) {
        case 1: {
            surnames->createList();
            break;
        } case 2: {
            surnames->insertAll("newStudentsList.txt");
            break;
        } case 3: {
            string name, surname;
            cin >> name >> surname;
            surnames->insertNewRecord(name, surname);
            break;
        } case 4: {
            break;
        } case 5: {
            break;
        } case 6: {
            break;
        } case 7: {
            break;
        } case 8: {
            surnameMap *ptr = surnames->head;
            for (int i = 0; i < surnames->count; i++) {
                cout << "SURNAME: " << ptr->surname << endl;
                studentInfo *ptr2 = ptr->head;
                for (int j = 0; j < ptr->count; j++) {
                    cout << '\t' << ptr2->name << " " << ptr2->surname << endl;
                    cout << "Email: " << ptr2->email << endl;
                    ptr2 = ptr2->next;
                }
                cout << "--------------------------------------" << endl;
                ptr = ptr->next;
            }
            break;
        } default: {
            cout << "Wrong choice, please try again!" << endl;
            break;
        }
    }
    return;
}

int get_choice() {
    cout << "e-mail Address Program" << endl;
    cout << "0) Exit" << endl;
    cout << "1) Create" << endl;
    cout << "2) Insert All" << endl;
    cout << "3) Insert New Record" << endl;
    cout << "4) Delete Student" << endl;
    cout << "5) Delete Surname Node" << endl;
    cout << "6) Update" << endl;
    cout << "7) Write to File" << endl;
    cout << "8) Print" << endl;
    cout << endl << "Enter a choice: ";
    int choice;
    cin >> choice;
    return choice;
}
