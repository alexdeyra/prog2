// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Client{
private:
    std::string name;  // Имя клиента
    double balance;    // Баланс клиента

public:
    // Конструктор для инициализации клиента
    Client(const std::string& clientName, double initialBalance)
        : name(clientName), balance(initialBalance) {}

    // Метод для зачисления средств на счет
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;  // Увеличиваем баланс
            std::cout << "Зачислено " << amount << " на счет " << name << ".\n";
        }
 else {
  std::cout << "Некорректная сумма для зачисления.\n";
}
}

    // Метод для списания средств со счета
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;  // Уменьшаем баланс
            std::cout << "Списано " << amount << " со счета " << name << ".\n";
            return true;
        }
 else {
  std::cout << "Некорректная сумма для списания или недостаточно средств.\n";
  return false;
}
}

    // Метод для отображения информации о клиенте
    void display() const {
        std::cout << "Клиент: " << name << ", Баланс: " << balance << "\n";
    }

    // Метод для получения имени клиента
    const std::string& getName() const {
        return name;
    }
};

class Bank {
private:
    std::vector<Client> clients;  // Вектор для хранения клиентов

public:
    // Метод для открытия нового счета
    void openAccount(const std::string& clientName, double initialBalance) {
        clients.emplace_back(clientName, initialBalance);  // Добавляем нового клиента
        std::cout << "Счет открыт для " << clientName << " с балансом " << initialBalance << ".\n";
    }

    // Метод для зачисления средств на счет клиента
    void depositToAccount(const std::string& clientName, double amount) {
        for (auto& client : clients) {
            if (client.getName() == clientName) {  // Ищем клиента по имени
                client.deposit(amount);  // Зачисляем средства
                return;
            }
        }
        std::cout << "Клиент " << clientName << " не найден.\n";
    }

    // Метод для списания средств со счета клиента
    void withdrawFromAccount(const std::string& clientName, double amount) {
        for (auto& client : clients) {
            if (client.getName() == clientName) {  // Ищем клиента по имени
                client.withdraw(amount);  // Списываем средства
                return;
            }
        }
        std::cout << "Клиент " << clientName << " не найден.\n";
    }

    // Метод для отображения всех клиентов
    void displayClients() const {
        for (const auto& client : clients) {
            client.display();  // Выводим информацию о каждом клиенте
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");
    Bank bank;  // Создаем объект банка
    int choice;  // Переменная для выбора действия
    std::string name;  // Переменная для имени клиента
    double amount;  // Переменная для суммы

    do {
        // Выводим меню
        std::cout << "\nМеню:\n";
        std::cout << "1. Открыть новый счет\n";
        std::cout << "2. Зачислить средства\n";
        std::cout << "3. Списать средства\n";
        std::cout << "4. Показать всех клиентов\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;  // Получаем выбор пользователя

        switch (choice) {
        case 1:  // Открытие нового счета
            std::cout << "Введите имя клиента: ";
            std::cin >> name;  // Вводим имя клиента
            std::cout << "Введите начальный баланс: ";
            std::cin >> amount;  // Вводим начальный баланс
            bank.openAccount(name, amount);  // Открываем счет
            break;
        case 2:  // Зачисление средств
            std::cout << "Введите имя клиента: ";
            std::cin >> name;  // Вводим имя клиента
            std::cout << "Введите сумму для зачисления: ";
            std::cin >> amount;  // Вводим сумму
            bank.depositToAccount(name, amount);  // Зачисляем средства
            break;
        case 3:  // Списание средств
            std::cout << "Введите имя клиента: ";
            std::cin >> name;  // Вводим имя клиента
            std::cout << "Введите сумму для списания: ";
            std::cin >> amount;  // Вводим сумму
            bank.withdrawFromAccount(name, amount);  // Списываем средства
            break;
        case 4:  // Показать всех клиентов
            bank.displayClients();  // Отображаем всех клиентов
            break;
        case 5:  // Выход
            std::cout << "Выход из программы.\n";
            break;
        default:  // Некорректный выбор
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);  // Продолжаем, пока не выберем выход

    return 0;  // Завершаем программу
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
