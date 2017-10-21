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

void surnameMapList::deleteStudent(string name, string surname) {
    surnameMap *map = getSurnameMap(surname);
    if (!map) return;
    if (map->count == 1) {
        deleteSurnameNode(surname);
    } else {
        studentInfo *ptr = map->getStudent(name, surname);
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
        count--;
        return;
    }
}

void surnameMapList::deleteSurnameNode(string surname) {
    return;
}

void surnameMapList::updateList() {
    return;
}

void surnameMapList::writeToFile() {
    ofstream file("emailList.txt", ios_base::out);
    surnameMap *ptr = head;
    for (int i = 0; i < count; i++) {
        studentInfo *ptr2 = ptr->head;
        for (int j = 0; j < ptr->count; j++) {
            file << ptr2->email << endl;
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    file.close();
    return;
}

void surnameMapList::sort(int left, int right) {
//    int i = left, j = right;
//    surnameMap* tmp;
//    int k = static_cast<int>((left + right) / 2);
//    surnameMap *pivot = operator[](k);
//    /* partition */
//    while (i <= j) {
//        while (operator[](i)->surname < pivot->surname)
//            i++;
//        while (operator[](j)->surname > pivot->surname)
//            j--;
//        if (i <= j) {
//            if (i == 0) {
//                surnameMap *ptr = operator[](0);
//                operator[](j)->next = operator[](1);
//                head = operator[](j);
//                operator[](j - 1)->next = ptr;
//                ptr->next = operator[](j);
//            } else {
//                
//            }
//            tmp = operator[](i);
//            operator[](i)->next->prev = operator[](j);
//            
//            operator[](j)->surname = tmp;
//            i++;
//            j--;
//        }
//    };
//    /* recursion */
//    if (left < j)
//        sort(left, j);
//    if (i < right)
//        sort(i, right);
    return;
}

surnameMap* surnameMapList::getSurnameMap(string surname) {
    surnameMap *ptr = head;
    for (int i = 0; i < count; i++) {
        if (ptr->surname == surname) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}
