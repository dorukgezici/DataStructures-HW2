/* @Author
 * Student Name: Ali Doruk Gezici
 * Student ID : 150150301
 * Date: 17.10.2017
 */

#include "surnameMap.h"
#include "studentInfo.h"
#include <iostream>

studentInfo* surnameMap::operator[](int i) {
    studentInfo *ptr = head;
    for (int j = 1; j <= count; j++) ptr = ptr->next;
    return ptr;
}

void surnameMap::createInfoList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
    return;
}

void surnameMap::insert(std::string name, std::string surname) {
    if (!head) {
        head = new studentInfo;
        head->name = name;
        head->surname = surname;
        head->generateEmail(count);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    } else {
        studentInfo *s = new studentInfo;
        s->name = name;
        s->surname = surname;
        s->generateEmail(count);
        s->prev = tail;
        s->next = nullptr;
        tail->next = s;
        tail = s;
    }; count++;
    return;
}

studentInfo* surnameMap::getStudent(std::string name, std::string surname) {
    studentInfo *ptr = head;
    for (int i = 0; i < count; i++) {
        if (ptr->name == name && ptr->surname == surname) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}
