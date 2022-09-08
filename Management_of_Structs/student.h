//  student.h
//  Management of Structs
//
//  Created by Nathanael Moody on 3/9/22.
//
//  Struct Declaration 

enum standing {freshman, sophomore, junior, senior};

struct student
{
    char name[50];
    int studentId;
    char major[50];
    enum standing level;
    int zip;
};

