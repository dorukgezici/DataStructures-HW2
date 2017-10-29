/* @Author
 * Student Name: Ali Doruk Gezici
 * Student ID : 150150301
 * Date: 17.10.2017
 */

#include "surnameMapList.h"
#include "surnameMap.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

surnameMap* surnameMapList::operator[](int i) {
    if (i >= count) return nullptr;
    surnameMap* ptr = head;
    for (int j = 1; j <= i; j++) ptr = ptr->next;
    return ptr;
}

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
        getline(ss, surname, '\r');
        insertNewRecord(name, surname);
    }; file.close();
    sort();
    return;
}

void surnameMapList::insertNewRecord(string name, string surname) {
    if (count == 0) {
        head = new surnameMap;
        head->createInfoList();
        head->surname = surname;
        head->insert(name);
        head->next = head;
        count++;
    } else {
        surnameMap *ptr = head;
        for (int i = 0; i < count; i++) {
            if (ptr->surname == surname) {
                ptr->insert(name);
                return;
            } else ptr = ptr->next;
        }
        surnameMap *s = new surnameMap;
        s->createInfoList();
        s->surname = surname;
        s->insert(name);
        s->next = head;
        surnameMap *tmp = head;
        while (tmp->next != head) tmp = tmp->next;
        tmp->next = s;
        count++;
    }
    sort();
    return;
}

void surnameMapList::deleteStudent(string name, string surname) {
    surnameMap *map = getSurnameMap(surname);
    if (!map) return;
    if (map->count == 1) {
        deleteSurnameNode(surname);
    } else {
        studentInfo *ptr = map->getStudent(name);
        if (map->head == ptr) {
            map->head = ptr->next;
            map->head->prev = nullptr;
        } else if (map->tail == ptr) {
            map->tail = ptr->prev;
            map->tail->next = nullptr;
        } else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        delete ptr;
        map->count--;
        return;
    }
}

void surnameMapList::deleteSurnameNode(string surname) {
    surnameMap *map = getSurnameMap(surname);
    if (!map) return;
    studentInfo* ptr = map->head;
    for (int i = 0; i < map->count; i++) {
        studentInfo *tmp = ptr->next;
        delete ptr;
        ptr = tmp;
    }
    surnameMap *prev = head;
    while (prev->next != map) prev = prev->next;
    if (map == head) head = map->next;
    prev->next = map->next;
    delete map;
    count--;
    sort();
    return;
}

void surnameMapList::updateList(string name, string surname) {
    surnameMap *map = getSurnameMap(surname);
    if (!map) return;
    studentInfo *ptr = map->getStudent(name);
    if (!ptr) return;
    string new_name, new_surname;
    cout << "Enter the student's new name: ";
    cin >> new_name;
    cout << "New surname: ";
    cin >> new_surname;
    if (surname != new_surname) {
        deleteStudent(name, surname);
        insertNewRecord(new_name, new_surname);
    } else {
        ptr->name = new_name;
        ptr->email = "";
        ptr->generateEmail(map->getEmailCount(new_name));
    }
    sort();
    return;
}

void surnameMapList::writeToFile() {
    ofstream file("emailList.txt", ios_base::out);
    surnameMap *ptr = head;
    for (int i = 0; i < count; i++) {
        file << "SURNAME: " << ptr->surname << endl;
        studentInfo *ptr2 = ptr->head;
        for (int j = 0; j < ptr->count; j++) {
            file << '\t' << ptr2->name << " " << ptr2->surname << " - " << ptr2->email << endl;
            ptr2 = ptr2->next;
        }
        file << "--------------------------------------" << endl;
        ptr = ptr->next;
    }
    file.close();
    return;
}

void surnameMapList::sort() {
    int j = 0;
    bool working = true;
    while (working) {
        j++;
        working = false;
        for (int i = 0; i < count - j; i++) {
            surnameMap *ptr = operator[](i);
            surnameMap *ptr2 = operator[](i + 1);
            if (ptr->surname > ptr2->surname) {
                ptr->getPrev()->next = ptr2;
                surnameMap *tmp = ptr2->next;
                ptr2->next = ptr->next;
                ptr2->getPrev()->next = ptr;
                ptr->next = tmp;
                if (i == 0) head = ptr2;
                working = true;
            }
        }
    }
}

surnameMap* surnameMapList::getSurnameMap(string surname) {
    surnameMap *ptr = head;
    for (int i = 0; i < count; i++) {
        if (ptr->surname == surname) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}
