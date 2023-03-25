#include<iostream>
using namespace std;
template<class t>
class linkedlist
{
private:
struct node
{
int data;
node *link;
}*p;
public:
linkedlist();
void append(t num);
void addatbeg(t num);
void addafter(int loc,t num);
void display();
void del(t num);
};
template<class t>
linkedlist<t>::linkedlist()
{
p=NULL;
}
template<class t>
void linkedlist<t>::append(t num)
{
node *temp,*r;
if(p==NULL)
{
p=new node;
p->data=num;
p->link=NULL;
}
else
{
temp=p;
while(temp->link!=NULL)
temp=temp->link;
r=new node;
r->data=num;
r->link=NULL;
temp->link=r;
}
}
template<class t>
void linkedlist<t>::addatbeg(t num)
{
node *temp;
temp=new node;
temp->data=num;
temp->link=p;
p=temp;
}
template<class t>
void linkedlist<t>::addafter(int loc,t num)
{
node *temp,*r;
temp=p;
for(int i=1;i<loc;i++)
{
temp=temp->link;
if(temp==NULL)
{
cout<<"There are less than "<<loc<<" elements in the list\n";
}
}
r=new node;
r->data=num;
r->link=temp->link;
temp->link=r;
}
template<class t>
void linkedlist<t>::display()
{
node *temp=p;
cout<<endl;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->link;
}
}
template<class t>
void linkedlist<t>::del( t num)
{
node *old,*temp;
temp=p;
while(temp!=NULL)
{
if(temp->data==num)
{
if(temp==p)
p=temp->link;
else
old->link=temp->link;
delete temp;
}
else
{
old=temp;
temp=temp->link;
}
}
}
int main()
{
linkedlist<int> l;
l.append(14);
l.append(30);
l.append(25);
l.append(42);
cout<<"\n\n Elements in the linked list are :\n\n";
l.display();
l.addatbeg(999);
l.addatbeg(888);
l.addatbeg(777);
cout<<"\n\n Elements in the linked list after addition at the beginning are :\n\n";
l.display();
l.addafter(7,0);
l.addafter(2,1);
cout<<"\n\n Elements in the linked list after addition at given position are:\n\n";
l.display();
l.del(999);
cout<<"\n\n Elements in the list after deletion are:\n\n";
l.display();
return 0;
}
