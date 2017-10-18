//
//  studentInfo.cpp
//  Data HW - 2
//
//  Created by Doruk Gezici on 17.10.2017.
//  Copyright © 2017 Doruk Gezici. All rights reserved.
//

#include "studentInfo.h"
#include <string>
#include <sstream>

std::string studentInfo::toLowercase(std::string str) {
    std::stringstream result;
    for (int i = 0; i < str.length(); i++) {
        std::string new_c;
        new_c += tolower(str[i]);
        result << new_c;
    }
    return result.str();
}

void studentInfo::generateEmail(int surnameCount) {
    std::stringstream ss;
    ss << toLowercase(surname);
    std::string lower_name = toLowercase(name);
    for (int i = 0; i < surnameCount; i++) {
        ss << lower_name[i];
    }
    ss << "@itu.edu.tr";
    email = ss.str();
    return;
}
