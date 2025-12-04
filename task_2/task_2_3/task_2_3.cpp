#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void printStudentInfo() {
    cout << "Student: Chekushin Maxim Artemovich " << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: 3" << endl;
    cout << endl;
}


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "My vector has " << vec.size() << " of these elements: ";
    for (size_t i = 0; i < vec.size(); i++) {
        os << "[" << i << "] -> " << vec[i];
        if (i < vec.size() - 1) os << ", ";
    }
    return os;
}

int main() {
    printStudentInfo();
    
    vector<int> intVec = {1, 2, 3, 4, 5};
    vector<string> strVec = {"apple", "banana", "cherry"};
    vector<double> doubleVec = {1.1, 2.2, 3.3, 4.4};
    vector<char> charVec = {'A', 'B', 'C', 'D'};
    
    cout << "Integer vector:" << endl;
    cout << intVec << endl;
    
    cout << "\nString vector:" << endl;
    cout << strVec << endl;
    
    cout << "\nDouble vector:" << endl;
    cout << doubleVec << endl;
    
    cout << "\nChar vector:" << endl;
    cout << charVec << endl;
    
    cout << "\nPress Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    
    return 0;
}