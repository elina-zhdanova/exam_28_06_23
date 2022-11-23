#include <iostream>
using namespace std;

long long int kolvo(int num)
{
    int result = 0;
    while (num != 0) {
        num /= 10;
        result++;
    }
    return result;
}


int sumchet(int a)
{
    long long int s=0;
    int k=1;
    while (a>0) {
        if (k % 2 == 0)
        {
            s += (a % 10);
            a /= 10;
        }
        else
        {
            a /= 10;
        }
        k++;
    }

    return s;
}

void task1(int* mas, int len)
{
    for (int i = 0; i < len; i++)
        cin >> mas[i];
}

void task2(int *mas, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << mas[i] << " ";
    }
    cout << "\n";
}

void task3(int *mas, int len)
{
    int s = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - i - 1; j++)
        {
            if ( (sumchet(mas[j]) > sumchet(mas[j + 1])) || ((sumchet(mas[j]) == sumchet(mas[j + 1]) && (mas[j] > mas[j + 1]))) )
            {
                int p = mas[j];
                mas[j]=mas[j+1];
                mas[j + 1] = p;
            }
        }

    for (int i = 0; i < len; i++)
        cout << mas[i] << " ";
}





void task4(int* mas, int len)
{
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - i - 1; j++)
        {
            if (((mas[j]%10)>(mas[j+1]%10)) || ((mas[j]%10)==(mas[j+1]%10) && (mas[j]<mas[j+1])))
            {
                int p = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = p;
            }
        }

    for (int i = 0; i < len; i++)
        cout << mas[i] << " ";
}

int* create(int& size) {
    while (true) {
        cin >> size;
        if (size > 0 && size <= 1000) break;
        else cout << "False\n";
    }
    int* mas = new int[size];
    return mas;
}

void free(int* mas) {
    delete[] mas;
}

int main()
{
    int choice = 0;
    int len;
    int* mas = NULL;
    while (true)
    {
        cout << "Choice? \n"
            << "1 task \n"
            << "2 task \n"
            << "3 task \n"
            << "4 task \n"
            << "stop \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            mas = create(len);
            task1(mas, len);
            break;
        }
        case 2:
        {
            task2(mas,len);
            break;
        }
        case 3:
        {
            task3(mas, len);
            break;
        }
        case 4:
        {
            task4(mas, len);
            break;
        }
        case 5:
        {
            free(mas);
            return 0;
        }
        default:
        {
            break;
        }
        }
    }
    delete[] mas;
    return 0;
}