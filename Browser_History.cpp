#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
    Node *prev;
    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_tail(Node *&head, Node *&tail, string val)
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
Node *preseant = NULL;
string visit(Node *head, string val)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->val == val)
        {
            preseant = tmp;
            return preseant->val;
        }
        tmp = tmp->next;
    }
    return "Not Available";
};

string next()
{
    if (preseant && preseant->next)
    {
        preseant = preseant->next;
        return preseant->val;
    }
    return "Not Available";
};
string prev()
{
    if (preseant && preseant->prev)
    {
        preseant = preseant->prev;
        return preseant->val;
    }
    return "Not Available";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string val;
    while (cin >> val && val != "end")
    {
        insert_at_tail(head, tail, val);
    }
    int q;
    cin >> q;
    string command;

    while (q--)
    {

        cin >> command;

        if (command == "visit")
        {
            string adress;
            cin >> adress;
            cout << visit(head, adress) << endl;
        }
        else if  (command == "prev")
        {
           cout<<prev()<<endl;
        }
        else if  (command == "next")
        {
           cout<<next()<<endl;
        }

           
             
    }

    return 0;
}