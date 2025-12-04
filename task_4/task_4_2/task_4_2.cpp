#include <iostream>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

void printStudentInfo() {
   setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Студент: Чекушин Максим Артемович" << endl;
    cout << "Группа: М10-137БВ-25" << endl;
    cout << "Задание: task_2" << endl;
    cout << "------------------------" << endl;
}

struct BankAccount {
    string accountNumber;
    string owner;
    double balance;
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесено: $" << amount << endl;
            cout << "Новый баланс: $" << balance << endl;
        } else {
            cout << "Неверная сумма пополнения!" << endl;
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Снято: $" << amount << endl;
                cout << "Новый баланс: $" << balance << endl;
            } else {
                cout << "Недостаточно средств! Текущий баланс: $" << balance << endl;
            }
        } else {
            cout << "Неверная сумма снятия!" << endl;
        }
    }
    
    void printSummary() const {
        cout << "Информация о счёте:" << endl;
        cout << "  Номер счёта: " << accountNumber << endl;
        cout << "  Владелец: " << owner << endl;
        cout << "  Баланс: $" << balance << endl;
    }
};

int main() {
    printStudentInfo();
    
    
    BankAccount account = {"PMS-666", "Богдан Бобылёв", 900000000000.0};
    
    cout << "Начальное состояние счёта:" << endl;
    account.printSummary();
    cout << endl;
    
    
    cout << "Пополнение на $78999900..." << endl;
    account.deposit(78999900.0);
    cout << endl;
    
    
    cout << "Снятие $6000000..." << endl;
    account.withdraw(6000000.0);
    cout << endl;
    
    
    cout << "Попытка снять $9000..." << endl;
    account.withdraw(9000.0);
    cout << endl;
    
    
    cout << "Итоговое состояние счёта:" << endl;
    account.printSummary();
    
   cout << "Для продолжения нажмите любую клавишу . . .";
    cin.ignore();
    cin.get();
    
    return 0;
}