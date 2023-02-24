// 1301. Bubbling bubbles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

const int N =1e6+1+1;
int n, k; 
int a[N];
int mo[N]={0};
unordered_map<int, int> h1,h2;
//unordered_map<int, int> mo;
void read_input_data() {
    cin >> n ;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h1.emplace(a[i], i);
        //mo.emplace(a[i], 0);
        
    }

}//end read_input_data

void merge_sort(int a[], int total, int l, int r)
{
    //total=r-l+1
    if (total == 1) return; //只有一个数时直接返回
    if (total == 2)
    {
        if (a[l] < a[r]) return;
        mo[a[r]] += 1;
        swap(a[l], a[r]);
        return;
    }

    int mid = (l + r) / 2;
    merge_sort(a, mid - l + 1, l, mid);
    merge_sort(a, r - mid, mid + 1, r);

    //对于右半部分的数，更新他们左边有几个数更大


    int temp = l, end=r+1;
    for (int i = mid + 1;i <= r;i++)
    {
        if (a[mid] < a[i])
        {
            end = i;
            break;
        }
        for (int j = temp;j <= mid;j++)
        {
            if (a[j] > a[i])
            {
                mo[a[i]] += mid - j + 1;
                temp = j;
                break;
            }
        }
    }

    inplace_merge(a + l, a + mid + 1, a + end);

    /*
    int p1 = l, p2 = mid + 1;
    queue<int> q;
    while (1)
    {
        int t = a[p1] < a[p2] ? a[p1] : a[p2];
        q.push(t);

        bool flag;
        if (a[p1] < a[p2]) flag = 0;
        else flag = 1;


        if (!flag)//上一轮是左边进队列
        {
            if (p1 == mid)//左边最后一个数进去了，则右边的数全部进队列
            {
                for (int i = p2;i <= r;i++) q.push(a[i]);
                for (int i = l;i <= r;i++)
                {
                    a[i] = q.front();
                    q.pop();
                }
                break;
            }
            p1++;
        }

        if (flag)//上一轮是右边进队列
        {
            if (p2 == r)//右边最后一个数进去了，则左边的数全部进队列
            {
                for (int i = p1;i <= mid;i++) q.push(a[i]);
                for (int i = l;i <= r;i++)
                {
                    a[i] = q.front();
                    q.pop();
                }
                break;
            }
            p2++;
        }
 
    }
    */

}




int main()
{
    read_input_data();
    /*
    for (int i = 0; i < n;i++)
    {
        for (int j = i+1;j < n;j++)
        {
            if (a[i] > a[j])
            {
                h1[a[i]] += 1;
                h1[a[j]] += 1;
            }
        }
    }
    for (int i = 1;i <=n ;i++)
    {
        cout << h1[i] << " ";
    }
    */
    


    //从左往右扫描，找每个数左边有几个比它大的数
    

    merge_sort(a, n, 0, n - 1);

    for (int i = 1;i <= n;i++)
    {
        cout << mo[i]+i-1-(h1[i]-mo[i]) << " ";
    }
    
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
