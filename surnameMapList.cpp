//
//  surnameMapList.cpp
//  Data HW - 2
//
//  Created by Doruk Gezici on 17.10.2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "surnameMapList.h"
#include "surnameMap.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void surnameMapList::createList() {
    head = nullptr;
    count = 0;
    return;
}

void surnameMapList::insertAll(string file_name) {
    ifstream file(file_name, ios_base::in);
    if (!file.is_open()) return;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        string surname;
        getline(ss, name, '\t');
        getline(ss, surname);
        insertNewRecord(name, surname);
    }; file.close();
    return;
}

void surnameMapList::insertNewRecord(string name, string surname) {
    if (count == 0) {
        head = new surnameMap;
        head->createInfoList();
        head->surname = surname;
        head->insert(name, surname);
        head->next = head;
        count++;
    } else {
        surnameMap *ptr = head;
        for (int i = 0; i < count; i++) {
            if (ptr->surname == surname) {
                ptr->insert(name, surname);
                return;
            } else ptr = ptr->next;
        }
        surnameMap *s = new surnameMap;
        s->createInfoList();
        s->surname = surname;
        s->insert(name, surname);
        s->next = head;
        surnameMap *tmp = head;
        while (tmp->next != head) tmp = tmp->next;
        tmp->next = s;
        count++;
    }
    return;
}

void surnameMapList::deleteStudent() {
    return;
}

void surnameMapList::deleteSurnameNode() {
    return;
}

void surnameMapList::updateList() {
    return;
}

void surnameMapList::writeToFile() {
    return;
}
