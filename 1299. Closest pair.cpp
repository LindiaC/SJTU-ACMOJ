// 1299. Closest pair.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct point
{
    long long x;
    long long y;
};

long long dist(point p, point q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool cmpx(point p, point q)
{
    return p.x < q.x;
}

bool cmpy(point p, point q)
{
    return p.y < q.y;
}

const int N = 4e5 + 1;
point a[N];
int n;
void read_input_data() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
}

long long closest(point v[], int l, int r)
{
    if (l == r) return 0;
    if (l + 1 == r) return dist(v[l], v[r]);

    int mid = (l + r) / 2;

    long long dl = closest(v, l, mid);
    long long dr = closest(v, mid + 1, r);
    long long delta = -1;
    if (dl == 0) delta = dr;
    if (dr == 0) delta = dl;
    if (dl and dr) delta = min(dl, dr);


    vector<point> S;

    for (int i = mid;i <= r;i++)
    {
        if (abs(v[i].x - v[mid].x) > sqrt(delta)) break;
        S.push_back(v[i]);
    }
    for (int i = mid - 1;i >= l;i--)
    {
        if (abs(v[i].x - v[mid].x) > sqrt(delta)) break;
        S.push_back(v[i]);
    }

    if (S.size() == 0 or S.size() == 1) return delta;
    if (S.size() == 2) return min(delta, dist(S[0], S[1]));

    sort(S.begin(), S.end(), cmpy);
       
    for (int i = 0;i < S.size();i++)
    {
        for (int j = i + 1;j < S.size() and j<i+8;j++)
        {
            if (abs(S[i].y - S[j].y) >= sqrt(delta)) break;
            delta = min(delta, dist(S[i], S[j]));
        }
    }

    return delta;
}









int main()
{

    read_input_data();
    sort(a, a + n, cmpx);
    cout << closest(a, 0, n - 1);
}





/*
const int N = 4e5 + 1;
int n, k;
vector<vector<long long>> a;
void read_input_data() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x,y});
    }
}

bool cmpx(const vector<long long>& p, const vector<long long>& q)
{
    return p[0] < q[0];
}
bool cmpy(const vector<long long>& p, const vector<long long>& q)
{
    return p[1] < q[1];
}

long long dist(const vector<long long>& p, const vector<long long>& q)
{
    return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
}

long long brute(const vector<vector<long long>>& v, int l, int r)
{
    long long m = dist(v[0], v[1]);
    for (int i = 0;i < r;i++)
    {
        for (int j = i + 1;j <= r;j++)
        {
            m = min(m, dist(v[i], v[j]));
        }
    }
    return m;
}

long long singlebrute(const vector<vector<long long>>& v, int l, int r)
{
    long long m = dist(v[0], v[1]);
    for (int i = 0;i < r-1;i++)
    {
        m = min(m, dist(v[i], v[i + 1]));
    }
    return m;
}

long long closest(vector<vector<long long>> v, int l, int r)
{
    if (l == r) return pow(2,64);
    if (r == l + 1) return dist(v[l], v[r]);
    if (r - l + 1 <= 7) return brute(v, l, r);

    //sort(v.begin()+l, v.begin()+r+1, cmpx);
    int mid = (l + r) / 2;
    int line = (v[mid][0] + v[mid + 1][0]) / 2;
    long long dl = closest(v, l, mid);
    long long dr = closest(v, mid + 1, r);
    long long delta = min(dl, dr);

    vector<vector<long long>> S;
    for (int i = mid;i <= r;i++)
    {
        if (abs(v[i][0] - line) > sqrt(delta)) break;
        S.push_back(v[i]);
    }
    for (int i = mid-1;i >=l;i--)
    {
        if (abs(v[i][0] - line) > sqrt(delta)) break;
        S.push_back(v[i]);
    }

    if (S.size() == 0 or S.size() == 1) return delta;

    long long smin=dist(S[0],S[1]);
    if (S.size() <= 7)
    {
        smin = brute(S,0,S.size()-1);
        return min(delta, smin);
    }


    //以下情况S中至少有7个数
    sort(S.begin(), S.end(), cmpy);
    int end = 0;
    for (int i = 0; i <= S.size()-7;i++)
    {
        smin = singlebrute(S, i, i + 6);
    }

    return min(delta, smin);
}
*/