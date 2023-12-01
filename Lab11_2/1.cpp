#include <iostream>
#include <Windows.h>
#include <utility>
#include <algorithm>
using namespace std;

template <typename T>
void print(T* a, int n)
{
    cout << "\nМассив-результат:" << endl;
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << "; ";
    cout << a[n - 1] << endl;
}

template <typename T>
void init(T* a, int n)
{
    cout << "\nВведіть массив з " << n << " елементів:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "12:\nВведіть номер завдання: ";
    int a;
    cin >> a;
    cout << "\nРозмір масиву = ";
    int k;
    cin >> k;
    switch (a)
    {
    case 1:
    {
        int* arr = new int[k];
        int* amax = nullptr, * amin = nullptr;
        init(arr, k);
        for (int i = 0; i < k; i++)
        {
            if (i == 0)
                amin = amax = &arr[0];
            else
            {
                if (*amin > arr[i])
                    amin = &arr[i];
                else if (*amax < arr[i])
                    amax = &arr[i];
            }
        }
        swap(*amin, *amax);
        print(arr, k);
        break;
    }
    case 2:
    {
        int* arr = new int[k];
        init(arr, k);
        for (int i = 0, pos1 = 0, pos2 = k - 1; i <= pos2; )
        {
            if (arr[i] == 1)
                i++;
            else if (arr[i] == 0)
            {
                if (i == pos1)
                {
                    i++;
                    pos1++;
                    continue;
                }
                swap(arr[pos1], arr[i]);
                pos1++;
            }
            else
            {
                swap(arr[pos2], arr[i]);
                pos2--;
            }
        }
        print(arr, k);
        break;
    }
    case 3:
    {
        double* arr = new double[k];
        init(arr, k);
        double sum = (arr[0] > 0) * arr[0], mult = 1;
        int posmax = 0, posmin = 0;
        for (int i = 1; i < k; i++)
        {
            if (abs(arr[i]) > abs(arr[posmax]))
                posmax = i;
            else if (abs(arr[i]) < abs(arr[posmin]))
                posmin = i;
            if (arr[i] > 0)
                sum += arr[i];
        }
        for (int i = min(posmin, posmax) + 1; i < max(posmin, posmax); i++)
            mult *= arr[i];
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = 0; j < k - 1 - i; j++)
            {
                if (arr[j] < arr[j + 1])
                    swap(arr[j], arr[j + 1]);
            }
        }
        cout << "\nsum=" << sum << "\nmultiplay=" << mult << endl;
        print(arr, k);
        break;
    }
    case 4:
    {
        double* arr = new double[k];
        init(arr, k);
        int posmin = 0;
        double sumabs = 0;
        bool bl = false;
        for (int i = 0; i < k; i++)
        {
            if (abs(arr[posmin]) > abs(arr[i]))
                posmin = i;
            if (bl)
                sumabs += abs(arr[i]);
            else if (arr[i] < 0)
                bl = true;
        }
        double a, b;
        cout << "a=";
        cin >> a;
        cout << "b=";
        cin >> b;
        int n = 0;
        for (int i = 0; i < k; i++)
        {
            if (!(a <= arr[i] && arr[i] <= b))
            {
                arr[n] = arr[i];
                n++;
            }
        }
        for (int i = n; i < k; i++)
            arr[i] = 0;
        cout << "\nposmin=" << posmin + 1 << "\nsum=" << sumabs << endl;
        print(arr, k);
        break;
    }
    case 5:
    {
        double* arr = new double[k];
        init(arr, k);
        int posmax = 0;
        double sumabs = 0;
        bool bl = false;
        for (int i = 0; i < k; i++)
        {
            if (abs(arr[posmax]) < abs(arr[i]))
                posmax = i;
            if (bl)
                sumabs += abs(arr[i]);
            else if (arr[i] > 0)
                bl = true;
        }
        double a, b;
        cout << "a=";
        cin >> a;
        cout << "b=";
        cin >> b;
        for (int i = 0, n = 0; i < k; i++)
        {
            if (a <= (int)arr[i] && (int)arr[i] <= b)
            {
                double temp = arr[i];
                for (int j = i; j >= n + 1; j--)
                    arr[j] = arr[j - 1];
                arr[n] = temp;
                n++;
            }
        }
        cout << "\nposmax=" << posmax + 1 << "\nsum=" << sumabs << endl;
        print(arr, k);
        break;
    }
    case 6:
    {
        double* arr = new double[k];
        init(arr, k);
        int num = 0, posmax = 0;
        double mult = 1;
        for (int i = 0; i < k; i++)
        {
            if (abs(arr[posmax]) < abs(arr[i]))
                posmax = i;
            if (arr[i] > 3)
                num++;
        }
        for (int i = posmax + 1; i < k; i++)
            mult *= arr[i];
        for (int i = 0, n = 0; i < k; i++)
        {
            if (arr[i] < 0)
            {
                double temp = arr[i];
                for (int j = i; j > n; j--)
                    arr[j] = arr[j - 1];
                arr[n] = temp;
                n++;
            }
        }
        cout << "\nk=" << num << "\nmultiplay=" << mult << endl;
        print(arr, k);
        break;
    }
    }
    cin.ignore();
    return 0;
}
