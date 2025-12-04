#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
  setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Чекушин Максим Артемович" << endl;
    cout << "Группа: М10-137БВ-25" << endl;
    cout << "Задание: task_1" << endl;
    cout << "------------------------" << endl;
}

struct Book {
    string title;
    string author;
    int year;
    int pages;
    
    void display() const {
        cout << "Название: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Год издания: " << year << endl;
        cout << "Количество страниц: " << pages << endl;
    }
    
    bool isModern() const {
        return year > 2000;
    }
};

int main() {
    printStudentInfo();
    
    
    vector<Book> library(5);
    
    library[0] = {"Герой нашего времени", "Михаил Лермонтов", 1840, 224};
    library[1] = {"Отцы и дети", "Иван Тургенев", 1862, 288};
    library[2] = {"Доктор Живаго", "Борис Пастернак", 1957, 480};
    library[3] = {"Обитель", "Захар Прилепин", 2014, 752};
    library[4] = {"Тихий Дон", "Михаил Шолохов", 1928, 1200};
    
    cout << "Каталог библиотеки:" << endl;
    cout << "==================" << endl << endl;
    
    for (size_t i = 0; i < library.size(); i++) {
        cout << "Книга #" << (i + 1) << ":" << endl;
        library[i].display();
        cout << "Современная (после 2000): " << (library[i].isModern() ? "Да" : "Нет") << endl;
        cout << endl;
    }
    
    cout << "Для продолжения нажмите любую клавишу . . .";
    cin.ignore();
    cin.get();
    
    return 0;
}