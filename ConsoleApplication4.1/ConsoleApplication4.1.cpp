#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

void input(char* text) 
{ 
	cout << "Введите строку: " << '\n';
	cin.ignore();
	std::cin.getline(text, 256);
}

bool palindrom(char* str)
{
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        if (str[i] == ' ') i++;
        if (str[j] == ' ')j--;
        if (tolower(str[i]) != tolower(str[j])) 
        {
            return 0;
        }
    }
}

int find_substring1(const char* str_for_search_in, const char* substring, int start_position)
{
	int pos = -1;
	for (int i = start_position; i < strlen(str_for_search_in); i++) {
		if (tolower(str_for_search_in[i]) == tolower(substring[0])) {
			pos = i;
			i++;
			for (int j = 1; j < strlen(substring); j++, i++) {
				if (tolower(str_for_search_in[i]) != tolower(substring[j])) {
					pos = -1;
					break;
				}
			}
			if (pos != -1) return pos;
		}
	}
	return pos;
}

void find_substring2(char* str_for_search, char* substring) { //Ввод строки, подстроки, ведется поиск всех вхождений подстроки в строке
    int arr[256];
    int counter = 0;
    int start = 0;
    char str_for_search_in[256];
    strcpy_s(str_for_search_in, str_for_search);
    while (start != -1) {
        for (int i = 0; i < start; i++) str_for_search_in[i] = '.';
        if (int(strstr(str_for_search_in, substring)) > 0) {
            start = strlen(str_for_search) - strlen((strstr(str_for_search_in, substring))) + 1;
            arr[counter] = start;
            counter++;
        }
        else {
            start = -1;
        }
    }
    for (int i = 0; i < counter; i++) cout << arr[i] - 1 << " ";
    cout << "\n";
}

void encrypt(char* str_for_encrypt, int key)
{
	for (int i = 0; i < strlen(str_for_encrypt); i++)
	{
		str_for_encrypt[i] = char(int(str_for_encrypt[i]) + key);
	}
}

void search(char* str)
{
	bool flag = false;
	for (int i = 0; i < strlen(str); i++)
	{
		if (flag = true and str[i] != '"') cout << str[i];
		else
			if (flag = false and str[i] == '"') flag = true;
			else {
				flag = false;
				cout << ' ';
			}
	}
	cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choise;
    char cstr1[256] = " ";
    int key;
    int a = 0;
    char sub[256] = " ";
    int start;
    while (a == 0)
    {
        std::cout << "Что вы хотите выполнить?" "\n" << "1. Ввод" "\n" << "2. задание 1" "\n" << "3. задание 2.1" "\n" << "4. задание 2.2" "\n" << "5. Задание 3" "\n" "6. Задание 4" "\n" "7. Выход" "\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
            input(cstr1);
            break;
        case 2:
            cout << bool(palindrom(cstr1)) << '\n';
            break;
        case 3:
            cout << "Введите подстроку "; cin >> sub;
            cout << "Введите позицию начала "; cin >> start;
            find_substring1(cstr1, sub, start);
            cout << start << "\n";
            break;
        case 4:
            cout << "Введите подстроку "; cin >> sub;
            find_substring2(cstr1, sub);
            break;
        case 5:
            cout << "Введите ключ "; cin >> key;
            encrypt(cstr1, key);
            cout << "\n" << cstr1;
            break;
        case 6:
            search(cstr1);
            break;
        case 7:
            cout << "Всего хорошего";
            a++;
        default:
            break;
        }
    }
    return 0;
}