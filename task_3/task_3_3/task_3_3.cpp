#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void printStudentInfo() {
    cout << "Student: Чекушин Максим Артемович" << endl;
    cout << "Group: М10-137БВ-25" << endl;
    cout << "Task_3_3" << endl;
    cout << "---------------------" << endl;
}

void waitForEnter() {
    cout << "\nPress Enter to exit..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

struct Book {
    string name;
    string author;
    string year;
};

vector<string> splitBookData(const vector<string>& lines) {
    vector<Book> books;
    Book currentBook;
    
    for (const auto& line : lines) {
        if (line.find("Name:") != string::npos) {
            currentBook.name = line.substr(line.find("Name:") + 6);
        } else if (line.find("Author:") != string::npos) {
            currentBook.author = line.substr(line.find("Author:") + 8);
        } else if (line.find("Year:") != string::npos) {
            currentBook.year = line.substr(line.find("Year:") + 6);
        } else if (line.find("----------") != string::npos) {
            books.push_back(currentBook);
            currentBook = Book();
        }
    }
    
    // Shuffle data
    srand(time(0));
    for (size_t i = 0; i < books.size(); i++) {
        size_t swapWith = rand() % books.size();
        
        // Swap names
        swap(books[i].name, books[swapWith].name);
        
        // Swap authors with different book
        swapWith = rand() % books.size();
        swap(books[i].author, books[swapWith].author);
        
        // Swap years with different book
        swapWith = rand() % books.size();
        swap(books[i].year, books[swapWith].year);
    }
    
    // Convert back to lines
    vector<string> result;
    for (size_t i = 0; i < books.size(); i++) {
        result.push_back(to_string(i + 1) + ". Name: " + books[i].name);
        result.push_back("   Author: " + books[i].author);
        result.push_back("   Year: " + books[i].year);
        result.push_back("   ----------");
    }
    
    return result;
}

int main() {
    // Set console to UTF-8 for proper character display
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    
    printStudentInfo();
    
    // Read original file
    ifstream inputFile("books.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file 'books.txt'!" << endl;
        waitForEnter();
        return 1;
    }
    
    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    
    // Process and shuffle data
    vector<string> shuffledLines = splitBookData(lines);
    
    // Write to new file
    ofstream outputFile("incorrect_books.txt");
    if (!outputFile.is_open()) {
        cout << "Error creating file 'incorrect_books.txt'!" << endl;
        waitForEnter();
        return 1;
    }
    
    for (const auto& shuffledLine : shuffledLines) {
        outputFile << shuffledLine << endl;
    }
    outputFile.close();
    
    cout << "File 'incorrect_books.txt' created with shuffled book data!" << endl;
    
    waitForEnter();
    return 0;
}