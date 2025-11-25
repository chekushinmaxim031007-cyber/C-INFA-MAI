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

template<typename T>
vector<T> operator+(const vector<T>& vec1, const vector<T>& vec2) {
    vector<T> result = vec1;
    result.insert(result.end(), vec2.begin(), vec2.end());
    return result;
}

int main() {
    printStudentInfo();

    vector<int> vec1 = { 1, 2, 3 };
    vector<int> vec2 = { 4, 5, 6 };

    cout << "First vector:" << endl;
    printVector(vec1);
    cout << endl;

    cout << "Second vector:" << endl;
    printVector(vec2);
    cout << endl;

    vector<int> result = vec1 + vec2;

    cout << "Combined vector (vec1 + vec2):" << endl;
    printVector(result);
    cout << endl;

    vector<string> strVec1 = { "Mazda", "Toyota" };
    vector<string> strVec2 = { " Nissan", "Subaru" };

    cout << "First string vector:" << endl;
    printVector(strVec1);
    cout << endl;

    cout << "Second string vector:" << endl;
    printVector(strVec2);
    cout << endl;

    vector<string> strResult = strVec1 + strVec2;

    cout << "Combined string vector:" << endl;
    printVector(strResult);

    system("pause");

    return 0;
}