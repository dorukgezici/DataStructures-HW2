/* @Author
 * Student Name: Ali Doruk Gezici
 * Student ID : 150150301
 * Date: 17.10.2017
 */

#ifndef surnameMapList_h
#define surnameMapList_h

#include "surnameMap.h"

struct surnameMapList {
    // Circular Linked List
    surnameMap *head;
    int count;
    // Functions
    surnameMap* operator[](int i);
    void createList();
    void insertAll(std::string file_name);
    void insertNewRecord(std::string name, std::string surname);
    void deleteStudent(std::string name, std::string surname);
    void deleteSurnameNode(std::string surname);
    void updateList(std::string name, std::string surname);
    void writeToFile();
    void sort(int left, int right);
    surnameMap* getSurnameMap(std::string surname);
};

#endif /* surnameMapList_h */
