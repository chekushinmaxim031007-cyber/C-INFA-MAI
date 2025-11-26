#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printStudentInfo() {
    cout << "Student:Чекушин Максим Артемович " << endl;
    cout << "Group:М10-137БВ-25 " << endl;
    cout << "Task: 2" << endl;
    cout << "------------------------" << endl;
}

void readAndDisplayBooks() {
    ifstream file("books.txt");
    if (!file.is_open()) {
        cout << "Error opening books.txt file!" << endl;
        cout << "Please make sure books.txt exists in the current directory." << endl;
        return;
    }
    
    string line;
    cout << "Contents of books.txt:" << endl;
    cout << "======================" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    printStudentInfo();
    readAndDisplayBooks();
    return 0;
}