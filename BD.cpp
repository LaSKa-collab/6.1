#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
void save(map<std::string, string> BD)
{
    ofstream fout("BDT.txt", ios_base::out);
    string out;
    for (auto elem : BD)
    {
        const char* first = elem.first.c_str();
        const char* second = elem.second.c_str();
        for (int i = 0; i <= strlen(first); i++)
        {
            fout << first[i];
        }
        fout << " ";
        for (int i = 0; i <= strlen(second); i++)
        {
            fout << second[i];
        }
        fout << endl;
    }
    fout.close();

}
void return_BD(map<std::string, string> BD)
{
    for (auto elem : BD)
    {
        cout << elem.first << elem.second << endl;
    }
}
void vvod_BD(map<std::string, string> BD)
{
    string INN;
    cout << "Введите новый ИНН" << endl;
    cin >> INN;
    if (BD.count(INN) == 0)
    {
        cout << "Введите фамилию, имя, отчество, данные паспорта, год рождения и сумму налога через нижнее подчеркивание" << endl;
        cin >> BD[INN];
    }
    else
    {
        cout << "Такой ИНН уже есть";
    }
    save(BD);
}
void search(map<std::string, string> BD)
{
    string INN;
    cout << "Введите искомый ИНН" << endl;
    cin >> INN;
    if (BD.count(INN) != 0)
    {
        cout << INN << " " << BD[INN] << endl;
    }
    else
    {
        cout << "Такого ИНН нет в базе данных";
    }
}
void redact(map<std::string, string> BD)
{
    string INN;
    cout << "Введите редактируемый ИНН" << endl;
    cin >> INN;
    if (BD.count(INN) != 0)
    {
        string data;
        cout << "Введите новые Фамилия, Имя, Отчество, Паспортные данные, Год рождения, Сумму налога" << endl;
        cin >> data;
        BD[INN] = data;
    }
    save(BD);
}

int main()
{
    setlocale(0, "");
    ifstream fin("BDT.txt", ios_base::in);
    string line;
    map<std::string, string> BD;
    while (getline(fin, line))
    {
        BD[line.substr(0, 12)] = line.substr(12);
    }
    fin.close();
    int vvo;
    cout << "0 - Выход из программы;\n1 - Просмотр всей бд;\n2 - Ввод новых данных;\n3 - Поиск и отображение записи;\n4 - Редактирование записи;\n5 - Сохранение БД." << endl;
    while(true)
    {
        cin >> vvo;
        switch (vvo)
        {
        case 0:
        {
            return 1;
        }
        case 1:
        {
            return_BD(BD);
            break;
        }
        case 2:
        {
            vvod_BD(BD);
            break;
        }
        case 3:
        {
            search(BD);
            break;
        }
        case 4:
        {
            redact(BD);
            break;
        }
        case 5:
        {
            save(BD);
        }
        default:
        {
            return 0;
        }
        }
    }
}
