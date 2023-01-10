#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;

int main() {

    map <string, string> p;
    list <string> data;
    //Это структура данных, которая построена на двусвязных списках. 
    //Это значит, что любой элемент знает только о предыдущем и о следующем элементах.
    string line;

    cout << "Enter the group number, space, surname: \n";
    getline(cin, line);
    while (line != "-") {
        if (p.find(line.substr(0, line.find(' '))) != p.end()) { //есть ли такая группа
            //find проверяет, есть ли в data такая строка
            //p.end - возврат итератора после конца.
            auto num = ++find(data.begin(), data.end(), p[line.substr(0, line.find(' '))]);//auto слово объявляет переменную, 
            //тип которой определяется из выражения инициализации в объявлении. здесь в листе нет как такового номера элемента
            //find(начало, конец, что ищем)-позиция
            //мы ищем номер ищем группы в листе,
            data.insert(num, line); //добавляем в список под нужным номером
            //меняем последнюю строку
            p[line.substr(0, line.find(' '))] = line;
        }
        else {
            //если слова нет
            data.push_back(line);
            p.insert(pair<string, string>(line.substr(0, line.find(' ')), line));
            //pair потому что p-map, надо добавлять пару: ключ и значение
        }
        cout << "Enter the group number, space, surname: \n";
        getline(cin, line);
    }

    cout << "\nresult:\n";
    for (auto i = data.begin(); i != data.end(); i++) {
        cout << *i << '\n';
    }
}
