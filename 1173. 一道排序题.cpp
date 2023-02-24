// 1173. 一道排序题.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<class elemType>
void quickSort(elemType* a, int start, int end);

template <class elemType>
void quickSort(elemType* a, int n);


template<class elemType>
void quickSort(elemType *a, int start, int end)
{
    int i, j, hole;
    elemType temp;

    if (end <= start) return;

    temp = a[start];
    hole = start;
    i = start;
    j = end;
    
    while (i < j)
    {
        while ((j > i) and (a[j] >= temp)) j--;
        if (j == i) break;
        a[hole] = a[j];
        hole = j;

        while ((i < j) and (a[i] < temp)) i++;
        if (j == i) break;
        a[hole] = a[i];
        hole = i;


    }
    a[hole] = temp;
    quickSort(a, start, hole - 1);
    quickSort(a, hole + 1, end);
}
template <class elemType>
void quickSort(elemType *a, int n)
{
    quickSort(a, 0, n - 1);
}

int main()
{
    int num;
    cin >> num;
    long long* a;
    long long* b;
    a = new long long[num];
    b = new long long[num];
    for (int i = 0;i < num;i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i < num;i++)
    {
        cin >> b[i];
    }
    
    quickSort(a, num);
    quickSort(b, num);
    
    long long min = 0;
    long long max = 0;
    
  


    for (int i = 0;i < num;i++)
    {
        max += a[i] * b[i];
        min += a[i] * b[num - 1 - i];
    }
    cout << max << ' ' << min<<endl;
    


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
