#include <iostream>
#include <string>
#include<fstream>
using namespace std;
#include <windows.h>
#include <vector>

class Number
{
public:
    string name;
    string number;
    Number(const Number& v) :
        name(v.name),
        number(v.number) {}

    Number() {}

    const Number& operator=(const Number& v)
    {
        name = v.name;
        number = v.number;
        return v;
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream f("file.txt");
    vector <Number> telBook;
    if (f.is_open()) {
        Number t;
        while (f >> t.name >> t.number)
        {
            // cout << t.name << " " << t.number << std::endl;
            telBook.push_back(t);
        }
    }

    f.close();



    setlocale(LC_ALL, "ru");

    string path = "file.txt";

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open()) {

        cout << "Ошибка открытия файла!" << endl;
    }
    else {
        string msg;
        string phone;

        int value;
        cout << "Тел книга открыта!" << endl;
        cout << "Введите 1 для записи контакта:" << endl;
        cout << "Введите 2 для просмотра всех контактов:" << endl;
        cout << "Введите 3 для поиска контактов или выхода:" << endl;

        cin >> value;
        if ((value != 1) && (value != 2) && (value != 3)) {
            cout << "Enter 1 or 2 or 3" << endl;
        }
        if (value == 1) {

            cout << "Введите имя !" << endl;
            SetConsoleCP(1251);
            cin >> msg;
            cout << "Введите номер !" << endl;
            cin >> phone;
            fs << msg << " " << phone << "\n";
            cout << "Данные записаны!" << endl;
            SetConsoleCP(866);
        }

        if (value == 2) {

            cout << "Просмотр всех контактов!" << endl;
            while (!fs.eof()) {

                msg = "";
                fs >> msg;
                cout << msg << endl;
            }
        }
        if (value == 3) {

            while (true)
            {
                cout << "Введите имя для поиска (или stop для выхода)";
                string name;
                cin >> name;
                if (name == "stop")
                    break;
                for (int i = 0; i < telBook.size(); ++i)
                {
                    if (telBook[i].name == name)
                        cout << name << " " << telBook[i].number << endl;
                }
            }
        }

    }
    fs.close();

    return 0;
}
