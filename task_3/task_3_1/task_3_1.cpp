#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printStudentInfo() {
    cout << "Student: Чекушин Максим Артемович" << endl;
    cout << "Group: М10-137БВ-25" << endl;
    cout << "Task: 1" << endl;
    cout << "------------------------" << endl;
}

void createBooksFile() {
    ofstream file("books.txt");
    if (!file.is_open()) {
        cout << "Error creating books.txt file!" << endl;
        return;
    }
    
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
    cout << "File books.txt created successfully with 5 book entries!" << endl;
}

int main() {
    printStudentInfo();
    createBooksFile();
    return 0;
}