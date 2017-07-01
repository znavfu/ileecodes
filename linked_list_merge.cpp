#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class List
{
	private:
	node *head;
	node *tail;		
	public:

	node* get_head()
	{
		return head;
	}

	List()
	{
		head=NULL;
		tail=NULL;	
	}
	void display()
	{
		int count=0;
		node *temp=new node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
			count++;
		}
		cout<<"\n";
		cout<<"Count is: "<<count<<"\n";
	}
	
	void insert(int value)
	{
		node *temp=new node;
		temp->data=value;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
};

List merge(List list1, List list2)
{
	List combinedList;
	
	node* head1 = list1.get_head();
	node* head2 = list2.get_head();

    while (head1 != NULL && head2 != NULL)
    {
    	if (head1->data < head2->data)
    	{
    		combinedList.insert(head1->data);
    		head1 = head1->next;
    	}
    	else
    	{
    		combinedList.insert(head2->data);
    		head2 = head2->next;
    	}
    }

    while (head1 != NULL)
    {
    	combinedList.insert(head1->data);
    	head1 = head1->next;
    }

	while (head2 != NULL)
    {
    	combinedList.insert(head2->data);
    	head2 = head2->next;
    }

    return combinedList;
}

int main()
{
	List a,b,c;
	b.insert(1);
	a.insert(2);
	b.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(6);
	b.insert(7);
	b.insert(8);
	b.insert(9);
	b.insert(15);
	a.display();
	b.display();
	
	c = merge(a,b);
	
	c.display();
}