#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    Student(): name(""), lastName(""), patronymic(""), course(NULL) {}; // конструктор по умолчанию

    void setName(const string f_name);

    void setLastName(const string f_name);

    void setPatronymic(const string f_name);

    void setCourse(const int f_num);

    string getFullName();

    void printInfo();

private:
    void func_fullName();

    string name;
    string lastName;
    string patronymic; // отчество
    string fullName;
    int course;
};

#endif