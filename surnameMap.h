//
//  surnameMap.h
//  Data HW - 2
//
//  Created by Doruk Gezici on 17.10.2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#ifndef surnameMap_h
#define surnameMap_h

#include <string>
#include "studentInfo.h"

struct surnameMap {
    std::string surname;
    surnameMap *next;
    // Doubly Linked List (same surname)
    studentInfo *head;
    studentInfo *tail;
    int count;
    // Functions
    void createInfoList();
    void insert(std::string name, std::string surname);
};

#endif /* surnameMap_h */
