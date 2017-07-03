#include<iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};

class List
{
	private:
	node* head;
	node* tail;
	
	public:
	List()
	{
		head=NULL;
		tail=NULL;
	}
	
	node* get_head()
	{
		return head;
	}
	
	void set_head(node* h)
	{
		head=h;
	}
	
	void insert(int value)
	{
    	node *temp = new node;
    	temp->data = value;

		if (head == NULL)
		{
		    head=temp;
		}
    	else
    	{
        	node *temp1 = head;
		    while (temp1->next!=NULL)
		    {
		        temp1=temp1->next;
		    }
		    temp1->next=temp; 
    	}
	}
	
	void display()
	{
		int count=0;
		node* temp=new node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
			count++;
		}
		cout<<"\n";
		cout<<"Count is : "<<count<<"\n";
	}
	
	void delAlt()
	{
		node* curr=new node;
		curr=head;
		node* prev=new node;
		prev=head;
		curr=curr->next;
		while(curr!=NULL&&prev!=NULL)
		{
			prev->next=curr->next;
			curr->NULL;
			delete curr;
			prev=prev->next;
        	if (prev!=NULL)
            	curr=prev->next;
		}
	}
};

int main()
{
	List ll;
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	ll.insert(6);
	ll.insert(7);
	ll.insert(8);
	ll.display();
	ll.delAlt();
	ll.display();
}
