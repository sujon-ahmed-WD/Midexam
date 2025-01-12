#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    head->next = newnode;
    newnode->prev = head;
    head = newnode;
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void insert_at_any(Node *&head, Node *&tail, int idx, int val)
{
    Node *newnode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i < idx; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next->next;
    tmp->next->next->prev = newnode;
    tmp->next = newnode;
    newnode->prev = tmp;
}

void froward_Print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << "l->" << tmp->val << " ";
        tmp = tmp->next;
    }
}
void backword_print(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << "R->" << tmp->val << " ";
        tmp = tmp->prev;
    }
}
int size(Node *head)
{
    int sz = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        sz++;
        tmp = tmp->next;
    }
    return sz;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (cin >> val && val != -1)
    {
        insert_at_tail(head, tail, val);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, tail, val);
            froward_Print(head);
        }

    }

    return 0;
}