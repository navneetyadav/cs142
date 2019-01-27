#include<iostream>
using namespace std;

class Node
		{
		public:
		//for entering the data
		int data;
		//pointer for mooving to next and the previous nodes
		Node* next;
		Node* prev;
		//makinh ptr to null using constructor
		Node()
			{
			next = NULL;
			prev = NULL;
			}
	
		};

class DLL
	{
		public:
		//Head + Nodes inside linked with each other		
		Node* head;
		Node* tail;
		
		//Construct
		DLL()
			{
			head = NULL;
			tail = NULL;
			}
		// Circles inside linked with each other
		// Rules how circles will be linked
		//insert
		void insert(int value)
					{
					//If 1st node is added
					Node* temp = new Node;
					// Insert value in the node
					temp->data = value;
					// 1st Node only
					if(head==NULL)
							{
								head = temp;
							}
		
					// Any other Node
					else
							{
								tail->next = temp;
								temp->prev = tail;
							}
					tail = temp;
		
					}
	
		void insertAt(int pos, int value)
						{
						// Reach the place before the pos
						Node* current = head;
						int i =1;
						while(i<pos-1)
								{
								i++;
								current = current->next;
								if(current==NULL)
										{
										cout <<  "Linkedlist elements are more than the limit" << endl;
										cout << "Insert function might help you in this case." << endl;
										return;
										}
								}
		
						//Create a node
						Node* temp = new Node;
						//Storing the data
						temp-> data = value;
						if(pos!=1)
							{
							
							temp->next = current->next;	
							current->next = temp;
							temp->next->prev = temp;
							temp->prev = current;
							}
						// Update the code for 1st position
						else
							{
								temp->next = head;
								head->prev = temp;
								head = temp;
							}
						}

		/deletion at a given point
		void deleteAt(int pos)
					{
					// Reach the place before the pos
					Node* current = head;
					int i =1;
					while(i<pos-1)
							{
							i++;
							current = current->next;	
							}
					// delete an element at a given position
					Node* temp = head;
					int j =1;
					while(j<pos)
							{
								j++;
								temp = temp->next;
								if(temp==NULL)
										{
										cout <<  "Linkedlist elements are more than the limit" << endl;
										cout << "Insert function might help you in this case." << endl;
										return;
							}
					}
					//
					current->next = temp->next;
					current->next->prev = current;
					delete temp;

			}

	//if user tries to delete at undefined/"not made" position
	void del()
		{
		//store tail in temp
		Node* temp = tail;
		//Node before tail has to point to NULL
		Node* current = tail->prev;
		
		current->next = NULL;

		//update tail
		tail = current;

		//delete temp
		delete temp;
		}

	//element counter loop
	void countItems()	
			{
			// Writing a loop to count
			int count = 0;
			Node* curr=head; 
			while(curr != NULL)	
						{
						count++;
						curr = curr->next;
						}
			cout << "Number of items in list = " << count << endl;
			}
	
	//Display
	void display()
  			{
			Node* current = head;
			cout << "NULL" << "<->";
			while(current != NULL)
						{
						cout << current->data << "<->";
						current = current->next;
						}
			cout << "NULL" << endl;
			}

	//reverse dislpay of the elements using recursion
	
	void Revdisp()
			{
			cout << "NULL";
			Revdisp2(tail);
			cout << "<->" << "NULL" << endl;
			}

	// true functional funtional"not like the previous one"
	void Revdisp2(Node* current)
				{
				//in reverse direction
				while(current != NULL)
							{
							cout << "<->" << current->data;
							current = current->prev;
							}
				}

	//reversing the linked list
	void revDLL()
			{
			revDLL2(head);
			//using loop to change the value of head
			while(head->prev!=NULL)
						{
						head = head->prev;
						}
			//doing same with the tail
			while
				{
				(tail->next!=NULL);
				}
			tail = tail->next;
				
			}
	
	void revDLL2(Node* current)
					{
					//condition to end the loop
					if(current==NULL)
							{
							return;
							}
					//recursive function
					revDLL2(current->next);
					Node* temp = current->next;
					current->next = current->prev;
					current->prev = temp;
					}

};

int main()
	{
	DLL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	l1.insert(8);
	l1.insert(9);
	l1.display();
	l1.Revdisp();
	l1.revDLL();
	l1.display();
	l1.deleteAt(8);
	l1.display();
	l1.countItems();
	l1.insertAt(2,1);
	l1.display();
	l1.del();
	l1.display();
	
return 0;

	}
