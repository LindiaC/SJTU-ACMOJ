#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    int a, b, d;
};

bool cmp(Student s1, Student s2) {
    return s1.d < s2.d;
}

int main() {
    int n;
    cin >> n;
    Student s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i].a >> s[i].b;
        s[i].d = s[i].b - s[i].a;
    }
    sort(s, s + n, cmp);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].d <= 0) {
            sum += s[i].d;
            if (sum < 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i].d == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
