#include <iostream>
using namespace std;
#include <stdlib.h>

void bubble(int n, int* m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - (i + 1); j++)
		{
			if (m[j] > m[j + 1])
			{
				int p = m[j];
				m[j] = m[j + 1];
				m[j + 1] = p;
			}

		}
}

void symbols(char* m, int len)
{
    int n = 26, j = 0;
    int key[26] = { 0 };
    char s[26] = { 'a', 'b', 'c', 'd', 'e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 26; j++) {
            if (m[i] == s[j]) {
                key[j]++;
            }

        }
    }
    int countr = 0;
    for (int i = 0; i < 26; i++) {
        while (key[i] > 0)
        {
            m[countr] = s[i];
            countr++;
            key[i]--;

        }
    }
}
void sort(int* a, int l, int r)
{
    if (l == r) return; // границы сомкнулись ???
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    sort(a, l, mid);
    sort(a, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    int* mas = (int*)malloc(r * sizeof(int)); // доп массив
    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if (((j > r) || (i <= mid) && (a[i] < a[j])))
        {
            mas[step] = a[i];
            i++;
        }
        else
        {
            mas[step] = a[j];
            j++;
        }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; step++)
        a[l + step] = mas[step];
}
void task1()
{
	int* mas;
	int len=0;
	cin >> len;
    mas = new int[len];
    for (int i = 0; i < len; i++)
        cin >> mas[i];
    bubble(len, mas);
    for (int i = 0; i < len; i++)
        cout << mas[i] << ' ';
    cout <<'\n';
    delete [] mas;
}

void task2()
{
    char* mas;
    int len = 0;
    cin >> len;
    mas = new char[len];
    for (int i = 0; i < len; i++)
        cin >> mas[i];
    symbols(mas, len);
    for (int i = 0; i < len; i++)
        cout << mas[i] << ' ';
    cout << '\n';
    delete[] mas;
}

void task3()
{
    int* mas;
    int len = 0;
    cin >> len;
    mas = new int[len];
    for (int i = 0; i < len; i++)
        cin >> mas[i];
    sort(mas, 0, len - 1);
    for (int i = 0; i < len; i++)
        cout << mas[i] << ' ';
    cout << '\n';
    delete[] mas;


}


int main()
{
    int choice = 0;
    while (true) {
        cout << "Choice? \n"
            << "1 task \n"
            << "2 task \n"
            << "3 task \n"
            << "4 task \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            task1();
            break;
        }
        case 2:
        {
            task2();
            break;
        }
        case 3:
        {
            task3();
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            return 0;
        }
        }
    }
}