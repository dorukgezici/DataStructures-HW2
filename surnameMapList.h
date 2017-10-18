//
//  surnameMapList.h
//  Data HW - 2
//
//  Created by Doruk Gezici on 17.10.2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#ifndef surnameMapList_h
#define surnameMapList_h

#include "surnameMap.h"

struct surnameMapList {
    // Circular Linked List
    surnameMap *head;
    int count;
    // Functions
    void createList();
    void insertAll(std::string file_name);
    void insertNewRecord(std::string name, std::string surname);
    void deleteStudent();
    void deleteSurnameNode();
    void updateList();
    void writeToFile();
    void sort();
};

#endif /* surnameMapList_h */
