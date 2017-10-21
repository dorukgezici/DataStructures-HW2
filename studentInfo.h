/* @Author
 * Student Name: Ali Doruk Gezici
 * Student ID : 150150301
 * Date: 17.10.2017
 */

#ifndef studentInfo_h
#define studentInfo_h

#include <string>

struct studentInfo {
    std::string name;
    std::string surname;
    std::string email;
    studentInfo *next;
    studentInfo *prev;
    // Functions
    void generateEmail(int surnameCount);
    std::string toLowercase(std::string str);
};

#endif /* studentInfo_h */
