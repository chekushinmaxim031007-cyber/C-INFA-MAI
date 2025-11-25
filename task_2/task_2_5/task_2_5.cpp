#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>

using namespace std;

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: Чекушин Максим Артемович" << std::endl;
    std::cout << "Group: М10-137БВ-25" << std::endl;
    std::cout << "Task: task_1" << std::endl;
}

int main() {
    printStudentInfo();

    map<string, vector<int>> students;
    int studentCount = 10;
    int gradesCount = 5;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(2, 5);

    cout << "Enter " << studentCount << " student names:" << endl;

    for (int i = 0; i < studentCount; ++i) {
        string name;
        cout << "Student " << i + 1 << ": ";
        getline(cin, name);

        vector<int> grades;
        for (int j = 0; j < gradesCount; ++j) {
            grades.push_back(dis(gen));
        }

        students[name] = grades;
    }

    cout << "\nStudent list with grades:" << endl;
    cout << "=========================" << endl;

    for (const auto& student : students) {
        cout << student.first << ": ";
        for (int grade : student.second) {
            cout << grade << " ";
        }
        cout << endl;
    }
    system("pause");

    return 0;
}