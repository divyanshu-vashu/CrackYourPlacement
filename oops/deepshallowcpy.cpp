#include<iostream>

using namespace std;

class Student{
    public:
        string name;
        double* cgpaptr;
        int regno;

        Student(Student &obj){
            this->name=obj.name;
            cgpaptr = new double;
            *cgpaptr = *obj.cgpaptr;
            this->regno=obj.regno;
        }
        Student (string name,double cgpa,int regno){
            this->name=name;
            cgpaptr = new double; // Allocate memory for cgpaptr
            *cgpaptr = cgpa;
            this->regno=regno;
        }

        void getinfo(){
            cout<<name<<endl;
            cout<<*cgpaptr<<endl;
            cout<<regno<<endl;
        }

        ~Student() {
            cout<<"destructor is running ..."<<endl;
            delete cgpaptr;
        }

};

int main(){
    Student s1("divyanshu",8.67,2021120243);
    Student s2(s1);
    s1.getinfo();
    *(s2.cgpaptr)=9.2;
    s2.getinfo();
    return 0;
}