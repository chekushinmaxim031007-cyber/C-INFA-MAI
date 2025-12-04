#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
   
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Чекушин Максим Артемович" << endl;
    cout << "Группа: М10-137БВ-25" << endl;
    cout << "Задание: task_3" << endl;
    cout << "------------------------" << endl;
}
const double PI = 3.14159265358979323846;

struct Square {
    string name;
    double side;
    
    double getPerimeter() const {
        return 4 * side;
    }
    
    double getArea() const {
        return side * side;
    }
    
    double getAngle() const {
        return 90.0; 
    }
    
    void display() const {
        cout << "Фигура: " << name << endl;
        cout << "  Сторона: " << side << endl;
        cout << "  Периметр: " << getPerimeter() << endl;
        cout << "  Площадь: " << getArea() << endl;
        cout << "  Углы: " << getAngle() << " градусов (все 4 угла)" << endl;
    }
};

struct RectangleShape {
    string name;
    double length;
    double width;
    
    double getPerimeter() const {
        return 2 * (length + width);
    }
    
    double getArea() const {
        return length * width;
    }
    
    double getAngle() const {
        return 90.0; 
    }
    
    void display() const {
        cout << "Фигура: " << name << endl;
        cout << "  Длина: " << length << ", Ширина: " << width << endl;
        cout << "  Периметр: " << getPerimeter() << endl;
        cout << "  Площадь: " << getArea() << endl;
        cout << "  Углы: " << getAngle() << " градусов (все 4 угла)" << endl;
    }
};

struct RightTriangle {
    string name;
    double leg1;
    double leg2;
    double hypotenuse;
    
    RightTriangle(string n, double a, double b) : name(n), leg1(a), leg2(b) {
        hypotenuse = sqrt(a * a + b * b);
    }
    
    double getPerimeter() const {
        return leg1 + leg2 + hypotenuse;
    }
    
    double getArea() const {
        return 0.5 * leg1 * leg2;
    }
    
    void getAngles(double& angle1, double& angle2, double& rightAngle) const {
        rightAngle = 90.0;
        angle1 = atan(leg2 / leg1) * 180.0 / PI;
        angle2 = 90.0 - angle1;
    }
    
    void display() const {
        cout << "Фигура: " << name << endl;
        cout << "  Катет 1: " << leg1 << ", Катет 2: " << leg2 << ", Гипотенуза: " << hypotenuse << endl;
        cout << "  Периметр: " << getPerimeter() << endl;
        cout << "  Площадь: " << getArea() << endl;
        double a1, a2, a3;
        getAngles(a1, a2, a3);
        cout << "  Углы: " << a1 << ", " << a2 << ", " << a3 << " градусов" << endl;
    }
};

struct Circle {
    string name;
    double radius;
    
    double getPerimeter() const {
        return 2 * PI * radius;
    }
    
    double getArea() const {
        return PI * radius * radius;
    }
    
    double getAngle() const {
        return 360.0; 
    }
    
    void display() const {
        cout << "Фигура: " << name << endl;
        cout << "  Радиус: " << radius << endl;
        cout << "  Периметр (Длина окружности): " << getPerimeter() << endl;
        cout << "  Площадь: " << getArea() << endl;
        cout << "  Полный угол: " << getAngle() << " градусов" << endl;
    }
};

struct RegularHexagon {
    string name;
    double side;
    
    double getPerimeter() const {
        return 6 * side;
    }
    
    double getArea() const {
        return (3 * sqrt(3) / 2) * side * side;
    }
    
    double getAngle() const {
        return 120.0; 
    }
    
    void display() const {
        cout << "Фигура: " << name << endl;
        cout << "  Сторона: " << side << endl;
        cout << "  Периметр: " << getPerimeter() << endl;
        cout << "  Площадь: " << getArea() << endl;
        cout << "  Внутренний угол: " << getAngle() << " градусов (все 6 углов)" << endl;
    }
};

int main() {
    printStudentInfo();
    
    cout << "Демонстрация геометрических фигур" << endl;
    cout << "=====================================" << endl << endl;
    
    
    Square square = {"Квадрат", 5.0};
    square.display();
    cout << endl;
    
    
    RectangleShape rect = {"Прямоугольник", 8.0, 4.0};
    rect.display();
    cout << endl;
    
    
    RightTriangle triangle("Прямоугольный треугольник", 3.0, 4.0);
    triangle.display();
    cout << endl;
    
    
    Circle circle = {"Круг", 7.0};
    circle.display();
    cout << endl;
    
    
    RegularHexagon hexagon = {"Правильный шестиугольник", 6.0};
    hexagon.display();
    
     cout << "Для продолжения нажмите любую клавишу . . .";
    cin.ignore();
    cin.get();
    
    return 0;
}