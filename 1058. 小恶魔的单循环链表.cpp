#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        // TODO
        int data;
        NODE* next;
        // DONE
    };

    NODE* head = nullptr;
    int len = 0;

    void init() {
        // TODO
        head = new NODE;
        head->next = head;
        // DONE
    }

    NODE* move(int i) {
        // TODO
        // 返回第i个节点
        if (i < 0 or i>=len) return NULL;
        if (i == 0) return head;
        int j = 0;
        NODE* p = head;
        do
        {
            j++;
            p = p->next;
        } while (p != head and j < i);
        return p;
    }

    void insert(int i, int x) {
        // TODO
        // case 1:在位置i插入一个数。注意这里是指插入的数在插入后处于位置i，即插入在现在位置i数字的前面；
        if (i > len or i < 0)return;
        if (len == 0)
        {
            head->data = x;
            len++;
            return;
        }
        NODE* former = (i == 0) ? LIST::move(len - 1) : LIST::move(i - 1);
        NODE* now=new NODE;
        now->data = x;
        now->next = former->next;
        former->next = now;
        if (i == 0) head = now;
        len++;
        // DONE
    }
    void remove(int i) {
        // TODO
        // case 3:删除位置i的数，整个链表长度减1；
        if (i >= len) return;
        NODE* former, * now;
        if (i == 0)
        {
            NODE* first = head;
            head = head->next;
            delete first;
            LIST::move(len - 2)->next = head;
            len--;
            return;
        }
        former = LIST::move(i - 1);
        now = LIST::move(i);
        former->next = now->next;
        delete now;
        len--;
        //DONE
        
    }
    void remove_insert(int i) {
        //TODO
        //case 4:删除位置i的数并将它插入至链表的尾端；
        if (len == 0 or len == 1 or i >= len - 1 or i < 0) return;
        if (i == 0)
        {
            head = LIST::move(1);
            return;
        }

        //删除
        NODE* former, * now, * last;
        last = LIST::move(len - 1);
        former = LIST::move(i - 1);
        now = LIST::move(i);
        former->next = now->next;

        //插入尾端
        now->next = head;
        last->next = now;

        return;
        // DONE
    }

    void get_length() {
        // TODO
        // case 0:输出一个整数，表示链表长度；
        cout << len << endl;
    }

    void query(int i) {

        // TODO
        // case 2: 输出位置i的数。如果i超出链表长度，请输出-1
        if (i >= len or i < 0)
        {
            cout << -1 << endl;
            return;
        }
        cout << LIST::move(i)->data << endl;
        // DONE
    }

    void get_max() {
        // TODO
        //case 5: 输出链表中最大的数。如果表为空请输出 - 1；
        if (len == 0)
        {
            cout << -1 << endl;
            return;
        }
        int i = 0, max = head->data;
        for (i = 1;i < len;i++)
        {
            int now = LIST::move(i)->data;
            max = (now > max) ? now : max;
        }
        cout << max << endl;
    }

    void clear() {
        // TODO
        if (len == 0)
        {
            delete head;
            return;
        }
        NODE* p, * q;
        p = head->next;
        head->next = NULL;
        while (p)
        {
            q = p->next;
            delete p;
            p = q;
        }
        delete p,q,head;
    }
        //DONE

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch (op) {
        case 0:
            LIST::get_length();
            break;
        case 1:
            cin >> p >> x;
            LIST::insert(p, x);
            break;
        case 2:
            cin >> p;
            LIST::query(p);
            break;
        case 3:
            cin >> p;
            LIST::remove(p);
            break;
        case 4:
            cin >> p;
            LIST::remove_insert(p);
            break;
        case 5:
            LIST::get_max();
            break;
        }
    }
    LIST::clear();
    return 0;
}
/*
0 返回链表长度；
1 在位置ii插入一个数。注意这里是指插入的数在插入后处于位置ii，即插入在现在位置ii数字的前面；
2 输出位置ii的数。如果ii超出链表长度，请输出-1；
3 删除位置ii的数，整个链表长度减1；
4 删除位置ii的数并将它插入至链表的尾端；
5 输出链表中最大的数。如果表为空请输出-1；
*/