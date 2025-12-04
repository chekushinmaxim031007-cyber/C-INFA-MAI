#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

void printStudentInfo()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "Student: Chekushin Maxim Artemovich" << endl;
    cout << "Group: M10-137BV-25" << endl;
    cout << "Task: task_5" << endl;
    cout << endl;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        os << vec[i];
        if (i < vec.size() - 1)
        {
            os << ", ";
        }
    }
    return os;
}

template<typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& myMap)
{
    os << "My map has " << myMap.size() << " of keys and has these pairs:" << endl;
    for (const auto& pair : myMap)
    {
        os << "[" << pair.first << "] -> {" << pair.second << "}" << endl;
    }
    return os;
}

int main()
{
    printStudentInfo();

    map<string, int> simpleMap =
    {
        {"apple", 10},
        {"banana", 20},
        {"cherry", 30}
    };

    cout << simpleMap;

    map<string, vector<int>> mapWithVector =
    {
        {"scores1", {85, 90, 78}},
        {"scores2", {92, 88, 95}},
        {"scores3", {76, 85, 80}}
    };

    cout << endl;
    cout << mapWithVector;

    map<vector<int>, string> mapWithVectorKey =
    {
        {{1, 2, 3}, "first"},
        {{4, 5}, "second"},
        {{6, 7, 8, 9}, "third"}
    };

    cout << endl;
    cout << mapWithVectorKey;

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}