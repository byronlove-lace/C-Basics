#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Student
{
        public:
                string name;

                // Constructor
                Student(string name) : name(name) {}

                void print()
                {
                        cout << name << endl;
                }

};

class MedicalStudent : public Student
{
        public:
                string speciality;

        MedicalStudent(string name, string speciality) 
                : speciality(speciality), Student(name) {} // Why Student(name)

        // Overload 
        void print()
        {
                cout << name << " " << speciality << endl;
        }
}


int main()
{
        Student* students[] = 
        {
                new Student("Kevin");
                new Student("Mary");
                new Student("Kulvinder");
        }

        for (int i = 0; i < 3; ++i)
        {
                students[i]->print();
        }

        for (int i = 0; i < 3; ++i)
        {
                delete students[i];
        }

        return 0;
}
