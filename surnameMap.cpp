//
//  surnameMap.cpp
//  Data HW - 2
//
//  Created by Doruk Gezici on 17.10.2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "surnameMap.h"
#include "studentInfo.h"
#include <iostream>

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
