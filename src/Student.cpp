#include "Student.h"

void Student::setName(const string f_name)
{
    name = f_name;
    func_fullName();
}
void Student::setLastName(const string f_name)
{
    lastName = f_name;
    func_fullName();
}
void Student::setPatronymic(const string f_name)
{
    patronymic = f_name;
    func_fullName();
}
void Student::setCourse(const int f_num)
{
    course = f_num;
}

string Student::getFullName()
{
    return fullName;
}

void Student::printInfo()
{
    cout << name << '\n' << lastName << '\n' << patronymic << '\n' << course << endl;
}

void Student::func_fullName()
{
    fullName = name + " " + lastName + " " + patronymic;
}
