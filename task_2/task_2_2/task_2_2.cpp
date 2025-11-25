#include <iostream>
#include <map>
#include <string>

using namespace std;

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: Чекушин Максим Артемович" << std::endl;
    std::cout << "Group: М10-137БВ-25" << std::endl;
    std::cout << "Task: task_1" << std::endl;
}

void addStudent(map<string, bool>& students, const string& name, bool hasLicense) {
    students[name] = hasLicense;
    cout << "Added: " << name << " -> " << (hasLicense ? "Has license" : "No license") << endl;
}

void removeStudent(map<string, bool>& students, const string& name) {
    auto it = students.find(name);
    if (it != students.end()) {
        students.erase(it);
        cout << "Removed: " << name << endl;
    }
    else {
        cout << "Student " << name << " not found!" << endl;
    }
}

void printMap(const map<string, bool>& students) {
    cout << "Current students with driver licenses:" << endl;
    for (const auto& student : students) {
        cout << student.first << " -> " << (student.second ? "Yes" : "No") << endl;
    }
    cout << "------------------------" << endl;
}

int main() {
    printStudentInfo();

    map<string, bool> students;

    cout << "Demonstrating add function:" << endl;
    addStudent(students, "McLovin", true);
    addStudent(students, "Prigozhin", false);
    addStudent(students, "Sidorovich", true);
    addStudent(students, "Zhmyshenko", false);

    printMap(students);

    cout << "Demonstrating remove function:" << endl;
    removeStudent(students, "Ronaldo");
    removeStudent(students, "Mirzonatnatria");

    printMap(students);

    cout << "Adding more students:" << endl;
    addStudent(students, "Hawking", true);
    addStudent(students, "Macan", false);

    printMap(students);

    system("pause");
    
    return 0;
}