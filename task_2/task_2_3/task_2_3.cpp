#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printStudentInfo() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Student: Чекушин Максим Артемович" << std::endl;
    std::cout << "Group: М10-137БВ-25" << std::endl;
    std::cout << "Task: task_1" << std::endl;
}

template<typename T>
void printVector(const vector<T>& vec) {
    cout << "My vector has " << vec.size() << " of these elements:" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "[" << i << "] -> " << vec[i] << endl;
    }
}

int main() {
    printStudentInfo();

    vector<int> intVec = { 1, 2, 3, 4, 5 };
    vector<double> doubleVec = { 1.1, 2.2, 3.3 };
    vector<string> stringVec = { "Mazda", "Toyota", "Nissan", "Subaru" };
   
    cout << "Integer vector:" << endl;
    printVector(intVec);
    cout << endl;

    cout << "Double vector:" << endl;
    printVector(doubleVec);
    cout << endl;

    cout << "String vector:" << endl;
    printVector(stringVec);

    system("pause");

    return 0;
}