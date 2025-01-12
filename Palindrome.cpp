#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node*prev;
    Node(int val)
    {
       this->val=val;
       this->next=NULL;
       this->prev=NULL;


    }
};

 
void at_tail(Node*&head,Node*&tail,int val)
{
     Node* newnode= new Node(val);

     if(head==NULL)
     {
        head=newnode;
        tail=newnode;
        return;
     }
     tail->next=newnode;
     newnode->prev=tail;
     tail=newnode;


}
bool pal(Node*head,Node*tail)
{
    for(Node* i=head, *j=tail; i!=j&&i->prev!=j; i=i->next,j=j->prev)
    {
        if(i->val!=j->val)
        {
            return false;
        }
    }
    return true;
}
void print(Node*head)
{
    Node*tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
}
int main()
{
    Node*head=NULL;
    Node*tail=NULL;
    int val;
    while(cin>>val && val!=-1)
    {
         at_tail(head,tail,val);
    }
    if(pal(head,tail))
    {
        cout<<"YES";
    } 
    else
    {
        cout<<"NO";
    }
    return 0;
}