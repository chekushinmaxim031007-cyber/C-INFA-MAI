#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

void printStudentInfo() {
    cout << "Student: Чекушин Максим Артемович" << endl;
    cout << "Group: М10-137БВ-25" << endl;
    cout << "Task_3_4" << endl;
    cout << "---------------------" << endl;
}

void waitForEnter() {
    cout << "\nPress Enter to exit..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int countWords(const string& line) {
    stringstream ss(line);
    string word;
    int count = 0;
    
    while (ss >> word) {
        count++;
    }
    
    return count;
}

int main() {
    // Set console to UTF-8 for proper character display
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif
    
    printStudentInfo();
    
    string filename;
    cout << "Enter the name of the text file (e.g., input.txt): ";
    cin >> filename;
    
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error opening file '" << filename << "'!" << endl;
        waitForEnter();
        return 1;
    }
    
    int lineCount = 0;
    int wordCount = 0;
    string line;
    
    while (getline(inputFile, line)) {
        lineCount++;
        wordCount += countWords(line);
    }
    inputFile.close();
    
    // Display results
    cout << "\nFile Analysis Results:" << endl;
    cout << "======================" << endl;
    cout << "Total lines: " << lineCount << endl;
    cout << "Total words: " << wordCount << endl;
    
    // Write results to report.txt
    ofstream reportFile("report.txt");
    if (!reportFile.is_open()) {
        cout << "Error creating file 'report.txt'!" << endl;
        waitForEnter();
        return 1;
    }
    
    reportFile << "File Analysis Report" << endl;
    reportFile << "====================" << endl;
    reportFile << "Filename: " << filename << endl;
    reportFile << "Total lines: " << lineCount << endl;
    reportFile << "Total words: " << wordCount << endl;
    reportFile.close();
    
    cout << "\nReport saved to 'report.txt'" << endl;
    
    waitForEnter();
    return 0;
}