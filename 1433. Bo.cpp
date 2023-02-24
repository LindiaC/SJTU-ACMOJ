// 1433. Bo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MinHeap {
public:
	MinHeap(long long size);
	~MinHeap();
	void Insert(long long number); //insert a number into the heap
	long long pop(); //pop a number from the heap
	void swap(long long& a, long long& b) { long long temp = a; a = b; b = temp; }
	long long getMin();
	long long GetNum() { return count - 1; } //get the number of elements from the heap
	void printHeap(); //print the elements from the heap


private:
	long long* p; //pointer of the array
	long long count; //number of elements in the min-heap
	long long  maxsize; //how many numbers the heap can hold at most
};

MinHeap::MinHeap(long long size)
{
	maxsize = size;
	p = new long long[maxsize + 1];
	if (p == nullptr) { cout << ' '; exit(-1); }
	count = 1;
}

MinHeap::~MinHeap()
{
	if (p != nullptr) delete[] p;
}

void MinHeap::Insert(long long number)
{
	if (count > maxsize)
	{
		cout << ' ' << endl;
		return;
	}
	p[count] = number;
	long long current = count;
	while (current / 2)
	{
		if (p[current] < p[current / 2]) swap(p[current], p[current / 2]);
		current /= 2;
	}
	count++;
}

long long MinHeap::pop()
{
	long long current = 1;
	long long num = GetNum();
	long long top = p[current];
	p[current] = p[num];
	p[num] = 0;

	while (2 * current <= num - 1)
	{
		if (p[current] > p[2 * current]) swap(p[current], p[2 * current]);
		if (2 * current + 1 <= num - 1 and p[current] > p[2 * current + 1]) swap(p[current], p[2 * current + 1]);
		current *= 2;
	}

	count--;

	return top;
}

long long MinHeap::getMin()
{
	return p[1];
}

void MinHeap::printHeap()
{
	cout << "Begin printing: ";
	for (int i = 1; i < count;++i)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}






int main()

{	

	long long  days;
	long long profit = 0;
	cin >> days;
	priority_queue<int, vector<int>, greater<int>> stockprice;
	for (int d = 0;d < days;d++)
	{
		long long price;
		cin >> price;
		stockprice.emplace(price);
		long long q = stockprice.top();
		if (q < price)
		{
			profit += price - q;
			stockprice.pop();
			stockprice.emplace(price);
		}

	}
	cout << profit;
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
