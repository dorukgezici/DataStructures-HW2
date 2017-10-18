//
//  studentInfo.h
//  Data HW - 2
//
//  Created by Doruk Gezici on 17.10.2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

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
