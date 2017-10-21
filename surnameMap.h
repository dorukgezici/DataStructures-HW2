/* @Author
 * Student Name: Ali Doruk Gezici
 * Student ID : 150150301
 * Date: 17.10.2017
 */

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
    studentInfo* operator[](int i);
    void createInfoList();
    void insert(std::string name, std::string surname);
    void sort(int left, int right);
    studentInfo* getStudent(std::string name, std::string surname);
};

#endif /* surnameMap_h */
