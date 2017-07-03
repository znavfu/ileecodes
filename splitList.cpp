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


    	// CHECK HERE, REMEMBER TO DO THIS
    	temp->next = NULL;

		if (head == NULL)
		{
		    head = temp;
		}
    	else
    	{
        	node *temp1 = head;
		    while (temp1->next != NULL)
		    {
		        temp1 = temp1->next;
		    }
		    temp1->next = temp; 
    	}
	}
	
	void display()
	{
		int count = 0;
		
		// A CHANGE HERE TOOOOOOOOOO
		node* temp = head;
		
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
			count++;
		}
		cout<<"\n";
		cout<<"Count is : "<<count<<"\n";
	}
};

List split(List oldList)
{
	List newList;

	node* cur1 = oldList.get_head();
	
	// if no elements or only one element
	if (cur1 == NULL || cur1->next == NULL)
	{
		return newList;
	}

	node* cur2 = cur1->next;

	// make new list head point to 2nd element
	newList.set_head(cur2);

	// stop when they're at the last two elements
	while (cur1->next != NULL && cur2->next != NULL)
	{
		// make current node point to next of next and then make cur1 go to that node
		cur1->next = cur1->next->next;
		cur1 = cur1->next;

		// do the same with cur2
		cur2->next = cur2->next->next;
		cur2 = cur2->next;
	}

	// make the first list point null at the end instead of last element of newList
	cur1->next = NULL;

	return newList;
}

int main()
{
	List ll,c;
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	ll.insert(5);
	ll.insert(6);
	ll.insert(7);
	ll.insert(8);
	ll.display();
	
	c = split(ll);
	
	ll.display();
	c.display();
}
