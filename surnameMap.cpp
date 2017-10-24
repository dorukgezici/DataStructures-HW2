/* @Author
 * Student Name: Ali Doruk Gezici
 * Student ID : 150150301
 * Date: 17.10.2017
 */

#include "surnameMap.h"
#include "studentInfo.h"

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

void surnameMap::insert(std::string name) {
    if (!head) {
        head = new studentInfo;
        head->name = name;
        head->surname = surname;
        head->generateEmail(getEmailCount(name));
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    } else {
        studentInfo *s = new studentInfo;
        s->name = name;
        s->surname = surname;
        s->generateEmail(getEmailCount(name));
        s->prev = tail;
        s->next = nullptr;
        tail->next = s;
        tail = s;
    }; count++;
    return;
}

studentInfo* surnameMap::getStudent(std::string name) {
    studentInfo *ptr = head;
    for (int i = 0; i < count; i++) {
        if (ptr->name == name && ptr->surname == surname) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

int surnameMap::getEmailCount(std::string name) {
    studentInfo *ptr = head;
    int highest_n = 0;
    for (int i = 0; i < count; i++) {
        int n = 0;
        for (int j = 0; j < ptr->email.length() - 11; j++) {
            char a = ptr->email[surname.length() + j];
            char b = tolower(name[j]);
            if (a == '@') { // First name in surnameMap
                n++;
                break;
            } else if (a == b) n++;
            else if (!b) n++; // If name's length isn't enough, add numbers in studentInfo::generateEmail
            else break;
        }
        if (n > highest_n) highest_n = n;
        ptr = ptr->next;
    }
    return highest_n;
}
