#include <iostream>

using std::string;
using std::cout;
using std::endl;

/*
// Static Binding / Static Polymorphism
// -> This will call the function in the base class 
class Student
{
        public:
                string name;

        // Constructor
                Student(string name) 
                        : name(name) {};

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
                :   speciality(speciality), Student(name) {};
        
                void print() 
                {
                        cout << name << ": " << speciality << endl;
                }
};
*/

/*
 * Dynamic Binding / Dynamic Polymorphism
 * use of virtual keyword means the function in the subclass is called instead
 * virtual means the decision of which member function to call is made a runtime 
 */
class Student
{
        public:
                string name;

        // Constructor
                Student(string name) 
                        : name(name) {};

                virtual void print() override 
                {
                        cout << name << endl;
                }
};

class MedicalStudent : public Student
{
        public:
                string speciality;

                MedicalStudent(string name, string speciality)
                :   speciality(speciality), Student(name) {};
        
                void print() 
                {
                        cout << name << ": " << speciality << endl;
                }
};

int main(int argc, char *argv[])
{
        Student *students[] = 
        {
                new Student("Kevin"),
                new Student("Mary"),
                new Student("Kulvindar"),

                new MedicalStudent("Alice", "Psycholog"),
                new MedicalStudent("Angron", "Radiology"),
                new MedicalStudent("Bill", "Pediactrics"),
        };

        for (int i = 0; i < 6; ++i)
        {
                students[i]->print();
        }

        for (int i = 0; i < 6; ++i)
        {
                delete students[i];
        }
}
