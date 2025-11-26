#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void printStudentInfo() {
    cout << "Student: Чекушин Максим Артемович" << endl;
    cout << "Group: М10-137БВ-25" << endl;
    cout << "Task_3_2" << endl;
    cout << "---------------------" << endl;
}

void waitForEnter() {
    cout << "\nPress Enter to exit..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    // Set console to UTF-8 for proper character display
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    
    printStudentInfo();
    
    ifstream file("books.txt");
    
    if (!file.is_open()) {
        cout << "Error opening file 'books.txt'!" << endl;
        waitForEnter();
        return 1;
    }
    
    string line;
    cout << "Contents of books.txt:" << endl;
    cout << "======================" << endl;
    
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
    
    waitForEnter();
    return 0;
}