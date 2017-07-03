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

	void set_head(node* h)
	{
		head = h;
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

// pass by reference
void merge(List &combinedList, node* head1, node* head2)
{
	// both lists are exhausted
	if (head1 == NULL && head2 == NULL)
	{
		return;
	}

	// store value of next element to add to combined list
	int temp;

	// if only list2 has elements
	if (head1 == NULL)
	{
		temp = head2->data;
		head2 = head2->next;
	}
	// if only list1 has elements
	else if (head2 == NULL)
	{
		temp = head1->data;
		head1 = head1->next;
	}
	// if list1 has smaller element
	else if (head1->data < head2->data)
	{
		temp = head1->data;
		head1 = head1->next;
	}
	// if list2 has smaller element
	else
	{
		temp = head2->data;
		head2 = head2->next;
	}

	combinedList.insert(temp);

	merge(combinedList, head1, head2);
}

// Hello Ileesha
// Hello Manish

int main()
{
	List a,b;
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
	
	node* head1 = a.get_head();
	node* head2 = b.get_head();

	List combinedList;

	merge(combinedList, head1, head2);

	combinedList.display();
}