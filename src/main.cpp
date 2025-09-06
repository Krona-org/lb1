#include <iostream>
#include <locale>
#include <vector>
#include <random>
#include <string>

struct Student 
{
    std::string name;
    int age;
    double score;
};

class StudentManager 
{
public:
    void addStudent(const std::string& name, int age, double score) 
    {
        students.push_back({name, age, score});
    }

    void displayStudents() const 
    {
        for (const auto& student : students) 
        {
            std::cout << "Name: " << student.name 
                      << ", Age: " << student.age 
                      << ", Score: " << student.score << std::endl;
        }
    }

void findStudentByName(const std::string& name) const
{
    bool found = false;
    for (const auto& student : students)
    {
        // проверяем, что имя начинается с введённой строки
        if (student.name.find(name) == 0)
        {
            std::cout << "Found: " 
                      << student.name
                      << ", Age: " << student.age
                      << ", Score: " << student.score
                      << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No students found starting with \"" 
                  << name << "\"." << std::endl;
    }
}


private:
    std::vector<Student> students;
};

int main() 
{
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> age_dist(18, 30);

    StudentManager manager;
    manager.addStudent("Алиса", age_dist(gen), 85.5);
    manager.addStudent("боб", age_dist(gen), 90.0);
    manager.addStudent("брат", age_dist(gen), 92.3);
    manager.addStudent("Charlie", age_dist(gen), 78.0);

    std::cout << "All апвап:\n";
    manager.displayStudents();

    std::cout << "\nSearching for \"li\":\n";
    manager.findStudentByName("li"); // найдёт Alice и Charlie

    std::cout << "\nSearching for \"Bob\":\n";
    manager.findStudentByName("б"); // найдёт Bob

    std::cout << "\nSearching for \"Zoe\":\n";
    manager.findStudentByName("Zoe"); // никого не найдёт

    return 0;
}
