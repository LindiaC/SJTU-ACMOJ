#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE
    {
        // TODO
        int data;
        NODE* next;
        NODE* prior;
        // DONE
    };

    NODE* head = nullptr, * tail = nullptr;
    int len = 0;

    void Pre()
    {
        // TODO
        head = new NODE;
        tail = new NODE;
        head->next = tail;
        head->prior = NULL;
        tail->prior = head;
        tail->next = NULL;
        head->data = -1;
        tail->data = -1;
    }
    NODE* move(int i)
    {
        // TODO
        if (i < 0 or i >= len) return NULL;
        if (i == 0) return head;
        int j = 0;
        NODE* p = head;
        while(p->next and j<i)
        {
            j++;
            p = p->next;
        }
        return p;
    }
    void insert(int i, int x)
    {
        // TODO
        if (i > len or i < 0)return;
        if (len == 0)//插入第一个数据
        {
            head->data = x;
            len++;
            return;
        }
        if (len == 1)
        {
            if (i == 0)//在第一个数据前插入数据
            {
                tail->data = head->data;
                head->data = x;
                len++;
                return;
            }
            if (i == 1)//在第一个数据后插入数据
            {
                tail->data = x;
                len++;
                return;
            }

        }
        if (i == 0)//插入新的head
        {
            NODE* now = new NODE;
            now->data = x;
            head->prior = now;
            now->next = head;
            now->prior = NULL;
            head = now;
            len++;
            return;
        }
        if (i == len)//插入新的tail
        {
            NODE* now = new NODE;
            now->data = x;
            tail->next = now;
            now->next = NULL;
            now->prior = tail;
            tail = now;
            len++;
            return;
        }


        NODE* former = LIST::move(i - 1);
        NODE* latter = LIST::move(i);
        NODE* now = new NODE;
        now->data = x;
        now->next = latter;
        now->prior = former;
        former->next = now;
        latter->prior = now;

        len++;
    }
    void remove(int i)
    {
        // TODO
        if (len == 1)//删除最后一个数
        {
            head->data = -1;
            tail->data = -1;
            len--;
            return;
        }
        if (len == 2)
        {
            if (i == 0)//删除最后两个数的前一个
            {
                head->data = tail->data;
                tail->data = -1;
                len--;
                return;
            }
            if (i == 1)//删除最后两个数的后一个
            {
                tail->data = -1;
                len--;
                return;
            }

        }
        if (i >= len) return;
        NODE* former, * now, *latter;
        if (i == 0)
        {
            NODE* first = head;
            head = head->next;
            head->prior = NULL;
            delete first;
            len--;
            return;
        }
        if (i == len - 1)
        {
            NODE* last=tail;
            tail = tail->prior;
            tail->next = NULL;
            delete last;
            len--;
            return;
        }

        former = LIST::move(i - 1);
        now = LIST::move(i);
        latter = LIST::move(i + 1);
        former->next = latter;
        latter->prior = former;
        delete now;
        len--;
    }
    int Get_length()
    {
        // TODO
        return len;
    }
    int Query(int i)
    {
        // TODO
        if (i >= len or i < 0)
        {
            return -1;
        }
        return LIST::move(i)->data;
    }

    void Print()
    {
        // TODO
        if (len == 0)
        {
            cout<< -1<<endl;
            return;
        }
        for (int i = 0;i < len;i++)
        {
            cout << LIST::move(i)->data << " ";
        }
        cout << endl;
    }

    void Clear()
    {
        // TODO
        if (len == 0 or len==1 or len==2)
        {
            delete head, tail;
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
        delete p, q, head;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p, ans;
    LIST::Pre();
    for (int _ = 0;_ < n;++_)
    {
        cin >> op;
        switch (op)
        {
        case 0:
            ans = LIST::Get_length();
            cout << ans << endl;
            break;
        case 1:
            cin >> p >> x;
            LIST::insert(p, x);
            break;
        case 2:
            cin >> p;
            ans = LIST::Query(p);
            cout << ans << endl;
            break;
        case 3:
            cin >> p;
            LIST::remove(p);
            break;
        case 4:
            LIST::Print();
            break;
        }
    }
    LIST::Clear();
    return 0;
}