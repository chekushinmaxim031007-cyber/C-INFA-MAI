#include <iostream>
#include <cmath>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
     setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Чекушин Максим Артемович" << endl;
    cout << "Группа: М10-137БВ-25" << endl;
    cout << "Задание: task_4" << endl;
    cout << "------------------------" << endl;
}

struct MyRectangle {
    int x1, y1; 
    int x2, y2; 
    
    double calculateArea() const {
        int width = abs(x2 - x1);
        int height = abs(y2 - y1);
        return width * height;
    }
    
    double calculatePerimeter() const {
        int width = abs(x2 - x1);
        int height = abs(y2 - y1);
        return 2 * (width + height);
    }
    
    void move(int dx, int dy) {
        cout << "Перемещение прямоугольника на dx=" << dx << ", dy=" << dy << endl;
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }
    
    bool isSquare() const {
        int width = abs(x2 - x1);
        int height = abs(y2 - y1);
        return width == height;
    }
    
    void display() const {
        cout << "Координаты прямоугольника:" << endl;
        cout << "  Верхняя левая: (" << x1 << ", " << y1 << ")" << endl;
        cout << "  Нижняя правая: (" << x2 << ", " << y2 << ")" << endl;
        cout << "  Ширина: " << abs(x2 - x1) << endl;
        cout << "  Высота: " << abs(y2 - y1) << endl;
        cout << "  Площадь: " << calculateArea() << endl;
        cout << "  Периметр: " << calculatePerimeter() << endl;
        cout << "  Является квадратом: " << (isSquare() ? "Да" : "Нет") << endl;
    }
};

int main() {
    printStudentInfo();
    
    cout << "Демонстрация прямоугольника" << endl;
    cout << "============================" << endl << endl;
    
    
    MyRectangle rect1 = {12, 35, 7, 0};
    
    cout << "Начальный прямоугольник:" << endl;
    rect1.display();
    cout << endl;
    
    
    rect1.move(1, -7);
    cout << "\nПосле перемещения:" << endl;
    rect1.display();
    cout << endl;
    
    
    MyRectangle square = {1, 9, 5, 2};
    
    cout << "\nПример квадрата:" << endl;
    square.display();
    cout << endl;
    
    
    square.move(-7, 7);
    cout << "\nПосле перемещения квадрата:" << endl;
    square.display();
    
   cout << "Для продолжения нажмите любую клавишу . . .";
    cin.ignore();
    cin.get();
    
    
    return 0;
}