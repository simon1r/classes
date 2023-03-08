#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

class Student {

    string name;
    string surname;
    string album_number;
    vector<float> grades;

public:
    Student(){}

    Student(string n, string s, string a, vector<float> g){
        name = n;
        surname = s;
        album_number = a;
        grades = g;
    }

    void set_name(string n){
        name = n;
    }

    void set_surname(string s){
        surname = s;
    }

    void set_album_number(string a){
        if(a.length() >= 5 && a.length() <= 6){
            album_number = a;
        }
        else {
            cout << "Invalid album number " << endl;
        }
    }

    string get_name(){
        return name;
    }

    string get_surname(){
        return surname;
    }

    string get_album_number(){
        return album_number;
    }

    float calculate_grade() {
        cout << "calculating grade for: " << name << endl;
        float sum = accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    void print() {
        cout << name << " " << surname << " (" << album_number << "): ";
        for (auto grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }

    bool add_grade(float grade) {
        if (grade >= 2.0 && grade <= 5.0) {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    bool passed_semester() {
        int count_twos = count(grades.begin(), grades.end(), 2.0);
return count_twos <= 1;
    }
};

int main()
{
    vector<float> grades{2, 3, 4, 5, 3};
    Student student{"Some", "Student", "12345", grades};
    student.print();

    student.set_name("Simon");
    student.set_surname("Lundin");
    student.set_album_number("1234567");

    student.add_grade(4.5);
    student.add_grade(5);

    student.print();

    float mean_grade = student.calculate_grade();
    cout << "Mean grade: " << mean_grade << endl;

    if (student.passed_semester()) {
        cout << "Student passed the semester" << endl;
    } else {
        cout << "Student did not pass the semester" << endl;
    }


    return 0;
}
