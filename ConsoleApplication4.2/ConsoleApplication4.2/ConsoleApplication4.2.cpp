#include <iostream>
#include <cstring>
#include <string> 
#include <fstream> 
#include <bitset>
using namespace std;

string file_format(const string file_path_full) // по введенному полному расположению файла выводит расширение
{
	int n;
	string abc;
	n = file_path_full.find_last_of('.');
	abc = file_path_full.substr(n, file_path_full.size() - n); //позиция и длина
	return abc;
}

string file_name(const string file_path_full)// по введенному полному расположению файла получить название
{
	string abc;
	int n, n1;
	n = file_path_full.find_last_of('\\');
	n1 = file_path_full.find_last_of('.');
	int lenght = n - n1 - 1;
	abc = file_path_full.substr(n + 1, lenght);
	return abc;
}

string file_path(const string file_path_full) //по введенному полному расположению файла получить расположение
{
	int num;
	string abc;
	num = file_path_full.find_last_of("\\");
	abc = file_path_full.substr(0, num);
	return abc;
}


char file_disk(const string file_path_full) //по введенному полному расположению файла получить название диска
{
	/*string abc;
	int pos;
	pos = file_path_full.find(':', 0);
	abc = file_path_full.substr(pos-1, 2);
	return abc;*/
	return file_path_full.at(0);// выведет нулевую позицию - букву диска
}


string file_rename(string file_path_full) //по введенному полному расположению файла и новому имени  переименовать файл
{
	string new_name;
	cin >> new_name;
	string abc;
	abc = (file_path_full.substr(0, file_path_full.find_last_of("\\") + 1)) + new_name + file_format(file_path_full);
	return abc;
}


bool file_copy(const string file_path_full) //по введенному полному расположению файла создать 
//копию файла(имя копии получается приписыванием  «_copy» к имени файла)
{
	int n = file_path_full.find_first_of('.');
	string abc;
    fstream fs;
    fs.open(file_path_full, fstream::in /*считывание, а это | fstream::out - на запись + app - добавление параметров в конец*/); 
    //in - возможность открыть файл для чтения, а вообще в open - второй пармаетр режим открытия файла

    if (!fs.is_open())//проверка на открытие файла
    {
        cout << "false"<<endl;
    }
    else
    {
        cout << "file is open" << endl;
    }

    fstream out;
    out.open(file_path_full.substr(0, n) + "_copy" + file_path_full.substr(n, file_path_full.size() - n), fstream::out);

    string str;
    while (!fs.eof()) //пока не наступит конец файла - работает. 
    {
        fs >> str;
        out << str << '\n';
    }

    fs.close();
    out.close();

    return 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string file_path_name;
    int a = 0;
    int choise;
    while (a == 0) {
        cout << "Что вы хотите выполнить?" "\n" << "1. Ввод" "\n" << "2. задание 1" "\n" << "3. задание 2" "\n" << "4. задание 3" "\n" << "5. Задание 4" "\n" "6. Задание 5" "\n" "7. Задание 6"  "\n" "8. Выход" "\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "Введите расположение файла без пробелов "; cin >> file_path_name;
            break;
        case 2:
            cout << file_format(file_path_name) << '\n';
            break;
        case 3:
            cout << file_name(file_path_name) << "\n";
            break;
        case 4:
            cout << file_path(file_path_name) << "\n";
            break;
        case 5:
            cout << file_disk(file_path_name) << "\n";
            break;
        case 6:
            cout << file_rename(file_path_name) << "\n";
            break;
        case 7:
            file_copy(file_path_name);
            break;
        case 8:
            cout << "Всего хорошего";
            a++;
        default:
            break;
        }


    }
}