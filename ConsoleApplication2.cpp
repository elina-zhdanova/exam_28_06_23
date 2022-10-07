#include <iostream>
#include <string>
using namespace std;


/*long double fact(int N)
{
    if (N < 0)
        return 0; 
    if (N == 0) 
        return 1; 
    else 
        return N * fact(N - 1); 
}*/

double bcd(int n, int k)
{
    if (k > n / 2) k = n - k;
    if (k == 1)  return n;
    if (k == 0)  return 1;
    double r = 1;
    for (int i = 1; i <= k; ++i) {
        r *= n - k + i;
        r /= i;
    }
    return r;
}


void task1()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << j;
        cout<<'\n';
    }
}

void task2()
{
    int n, c;
    cout << "Enter the number : ";
    cin >> n;
    for (int k=0; k<=n;k++)
    {
        for (int i = 0; i <= k; i++) 
            cout << bcd(k, i) << " ";
        cout << '\n';
    }
    
}

void task3()
{
    cout << "Push . to stop programm \n";
    string a;
    int i = 0;
    double sum = 0;
    while (true)
    {
        cin >> a;
        if (a == ".")
        {
            if (i == 0) break;
            cout << sum / i << endl;
            break;
        }
        else
        {
            i++;
            sum += stoll(a);
        }
    }
    
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
