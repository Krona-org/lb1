#include <iostream>
#include <Windows.h>

#include "Student.h"

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Student st;
    st.setName("имя");
    st.setLastName("фамилия");
    st.setPatronymic("отчество");
    st.setCourse(2);
    string fn = st.getFullName();
    cout << fn << '\n';

    return 0;
}