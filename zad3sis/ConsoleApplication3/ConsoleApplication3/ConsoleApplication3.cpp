// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct WeatherInfo
{
    float temperature;
    float humidity;
    float windSpeed;
};

void analyzeWeather(const WeatherInfo& weather) {
    if (weather.temperature > 30) {
        cout << "Сейчас жарко. Не рекомендуем находиться на солнце." << endl;
    }
    else if (weather.temperature > 20) {
        cout << "Температура удовлетворительная." << endl;
    }
    else {
        cout << "На улице холодно, надо одеться потеплее." << endl;
    }

    if (weather.humidity > 70) {
        cout << "Высокая влажность. Ожидаются дожди." << endl;
    }
    else {
        cout << "Влажность нормальная." << endl;
    }

 
    if (weather.windSpeed > 15) {
        cout << "Ветер сильный, Будьте осторожны" << endl;
    }
    else {
        cout << "Ветер в пределах нормы." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    WeatherInfo todayWeather;
    cout << "Введите температуру";
    cin >> todayWeather.temperature;
    cout << "Введите влажность";
    cin >> todayWeather.humidity;
    cout << "Введите скорость ветра";
    cin >> todayWeather.windSpeed;
    analyzeWeather(todayWeather);
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
