#include <iostream>
using namespace std;



class Node 
{
 public:
 // Data 
 int data;
 // Pointer to the next Node
 Node * next;
 // Construct that makes the ptr to NULL
 Node()
	{
        next = NULL;
        }

};

class LinkedList
{
 // Head + Circles inside linked with each other
 public:
 // Head -> Node type ptr
 Node * head;
 Node * tail;

 // Construct
 LinkedList()
	    {
 		head = NULL;
  		tail = NULL;
    	    } 
 // Circles inside linked with each other
 // Rules how circles will be linked

 // Insert
 void insert(int value)
		      {
       			// If 1st Node is added
       			Node * temp = new Node; 
       			// Insert value in the node
       			temp->data = value;
       			// 1st Node only.
       			if(head == NULL)
					{
            					head = temp;
       					}
       			// Any other Node only.
       			else
					{
            					tail->next = temp;
       					}
       			tail = temp;
    			} 

 void insertAt(int pos, int value)
				  {
        				// Reach the place before the pos
        				Node * current = head;
        				int i =1;
        				while(i < pos-1)
							{
            							i++;
           							 current = current->next;
								if(current==NULL)
										{
											cout << "Linkedlist elements are more than the limit" << endl;
											cout << "use insert funtion for increasing the no. of elements" << endl;
                                                                                        return;
			                                                         }
						        }

                                        // Create a node
                                        Node * temp = new Node;
                                        temp -> data = value;


                                        // Moving ptrs like magic ! if not head
                                        temp->next = current->next;
                                        current->next = temp;
        
                                        // Update the code for 1st position

                                  }
 // Deletion of last element
    void delet()
               {
        	// store the tail in temp
        	Node * temp = tail;
       		 // before tail has to point to null
       		 Node * current = head;
        	while(current->next != tail)
					   {
    					        current = current->next;
        				   }
        	current->next = NULL; 

	        // update tail
	        tail = current;
	        // delete temp
	         delete temp;
	        }
 //delete an element at a given position
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

				// if user tries to delete at undefined/"not made" position
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
		                  //assigning the value of pointers
				   current->next = temp->next;
					delete temp;

}



    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }
};


int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.display();
    l1.delet();
    l1.display();
    l1.insertAt(2,7);
    l1.display();
    return 0;
}
