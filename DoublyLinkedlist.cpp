#include <iostream>

using namespace std;

class Node
{
    private:
        int data;
        Node *next;
        Node *prev;
    public:
        int get_data() { return data; }
        void set_data(int n) { data = n; }
        Node* get_next() { return next; }
        void set_next(Node* n) {next = n; }
        Node* get_prev() { return prev; }
        void set_prev(Node* n) { prev = n; }
};

class DoublyLinkedList
{
    private:
        Node* head = NULL;
        Node* tail = NULL;
    public:
        void create(int length)
        {
            
            for (int i = 0; i < length; i++)
            {
                Node* temp = new Node;
                int n;
                cout << "Enter the element: ";
                cin >> n;
                temp->set_data(n);
                temp->set_next(NULL);
                temp->set_prev(NULL);
                if (i == 0)
                {
                    head = temp;
                    tail = temp;
                }
                else
                {
                    tail->set_next(temp);
                    temp->set_prev(tail);
                    tail = temp;
                }
            }

 
        }
        void show()
        {
            Node* p = head;
            cout << "Displaying items: ";
            while (p != NULL)
            {
                cout << p->get_data() << " ";
                p = p->get_next();
            }
            cout << endl;
                
        }

        void insert(int element)
        {
            Node *p = head;
            while (p->get_data() != element && p != NULL) p = p->get_next();
            if (p != NULL)
            {
                Node *new_node = new Node;
                int data;
                cout << "Enter the new element: ";
                cin >> data;
                new_node->set_data(data);
                if (p == tail)
                {
                    new_node->set_prev(tail);
                    new_node->set_next(NULL);
                    tail->set_next(new_node);
                    tail = new_node;
                }
                else
                {
                    new_node->set_next(p->get_next());
                    new_node->set_prev(p);
                    p->get_next()->set_prev(new_node);
                    p->set_next(new_node);
                }
            }
            else
            {
                cout << "Element not found." << endl;
            }

        }

        void del(int element)
        {
            Node *p = head;
            while (p->get_data() != element && p != NULL) p = p->get_next();
            if (p != NULL)
            {
                if (p == head)
                {
                    head = p->get_next();
                    delete p;
                    if (head != NULL) head->set_prev(NULL);
                }
                else if (p == tail)
                {
                    tail = p->get_prev();
                    delete p;
                    tail->set_next(NULL);
                }
                else
                {
                    p->get_next()->set_prev(p->get_prev());
                    p->get_prev()->set_next(p->get_next());
                    delete p;
                }
            }
            else
            {
                cout << "Element not found." << endl;
            }

        }
};

int main()
{
    int flag = 0;
    DoublyLinkedList l;
    while (true)
    {
        int ch;
        cout << "Enter 1 to create a new list.\n2 to show the list.\n3 for insertion.\n4 to delete an element.\n5 to exit.\n";
        cin >> ch;
        if (flag == 0 && (ch != 1))
        {
            cout << "Please create the list first!";
            continue;
        }
        else
        {
            
            if (ch == 1)
            {
                int len;
                cout << "Enter the length of the list: ";
                cin >> len;
                l.create(len);
                flag = 1;
            }
            else if (ch == 2) l.show();
            else
            {
                int elem;
                if (ch == 3)
                {
                    cout << "Enter the element to insert after: ";
                    cin >> elem;
                    l.insert(elem);
                }
                else if (ch == 4)
                {
                    cout << "Enter the element you wanna delete: ";
                    cin >> elem;
                    l.del(elem);
                }
    
            }
        }
        if (ch ==5) return 0;


        
    }
}
