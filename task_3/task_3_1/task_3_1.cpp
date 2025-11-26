#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void printStudentInfo() {
    cout << "Student: Чекушин Максим Артемович" << endl;
    cout << "Group: М10-137БВ-25" << endl;
    cout << "Task_3_1" << endl;
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
    
    // Create or overwrite books.txt file
    ofstream file("books.txt");
    
    if (!file.is_open()) {
        cout << "Error creating file!" << endl;
        waitForEnter();
        return 1;
    }
    
    // Write 5 book records
    file << "1. Name: To Kill a Mockingbird" << endl;
    file << "   Author: Harper Lee" << endl;
    file << "   Year: 1960" << endl;
    file << "   ----------" << endl;
    
    file << "2. Name: 1984" << endl;
    file << "   Author: George Orwell" << endl;
    file << "   Year: 1949" << endl;
    file << "   ----------" << endl;
    
    file << "3. Name: Pride and Prejudice" << endl;
    file << "   Author: Jane Austen" << endl;
    file << "   Year: 1813" << endl;
    file << "   ----------" << endl;
    
    file << "4. Name: The Great Gatsby" << endl;
    file << "   Author: F. Scott Fitzgerald" << endl;
    file << "   Year: 1925" << endl;
    file << "   ----------" << endl;
    
    file << "5. Name: Moby Dick" << endl;
    file << "   Author: Herman Melville" << endl;
    file << "   Year: 1851" << endl;
    file << "   ----------" << endl;
    
    file.close();
    cout << "File 'books.txt' created successfully with 5 book records!" << endl;
    
    waitForEnter();
    return 0;
}