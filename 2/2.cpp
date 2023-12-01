#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
    ofstream out;
    out.open("out.txt"); //УСІ ДАНІ ТУТ!!!
    srand(time(NULL));
    const int k = 300;
    int arr[k];
    out << "7:\nПочатковий масив:\n";
    for (int i = 0; i < k; i++)
    {
        arr[i] = rand() % 251 - 100;
        out << arr[i] << " ";
    }
    out << "\nРезультат:\n";
    for (int i = 1, l = 1; i < k; i++)
    {
        if (arr[i - 1] * arr[i] < 0)
            l++;
        else
        {
            if (l > 1)
                out << l << " " << i - l + 1 << endl;
            l = 1;
        }
    }
    return 0;
}
