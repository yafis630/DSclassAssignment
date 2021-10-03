#include <iostream>

using namespace std;

class Node
{
    private:
        int data;
        Node *next;
    
    public:
        int get_data() { return data; }
        void set_data(int n) { data = n; }
        Node* get_next() { return next; }
        void set_next(Node* n) {next = n; }
};

class LinkedList
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
                if (i == 0)
                {
                    head = temp;
                    tail = temp;
                }
                else
                {
                    tail->set_next(temp);
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

        void insert_after(int element)
        {
            int n_data;
            cout << "Enter the new integer: ";
            cin >> n_data;
            Node *new_node = new Node;
            new_node->set_data(n_data);
            Node *temp = head;
            while (temp->get_data() != element && temp != tail) temp = temp->get_next();
            if (temp->get_data() == element)
            {
                new_node->set_next(temp->get_next());
                temp->set_next(new_node);
                if (temp == tail) tail = new_node;
            }
            else cout << "Insertion not possible as element was not found!" << endl;

        }
        
        void insert_before(int element)
        {
            int n_data;
            cout << "Enter the new integer: ";
            cin >> n_data;
            Node *new_node = new Node;
            new_node->set_data(n_data);
            Node *temp = head;
            if (temp->get_data() == element) 
            {
                new_node->set_next(temp);
                head = new_node;
            }
            else if (temp->get_next() == NULL) cout << "Insertion not possible as element was not found!" << endl;
            else
            {
                while (temp->get_next()->get_data() != element && temp->get_next() != tail) temp = temp->get_next();
                if (temp->get_next()->get_data() == element)
                {
                    new_node->set_next(temp->get_next());
                    temp->set_next(new_node);
                }
                else cout << "Insertion not possible as element was not found!" << endl;
            }


        }

};

int main()
{
    int i = 0;
    LinkedList l;
    while (true)
    {
        int ch;
        cout << "Enter 1 to create a new list.\n2 to show the list." << 
        "\n3 to insert after a node.\n4 to insert before a node.\n5 to exit.\n";
        cin >> ch;
        if (ch == 5) return 0;
        else if (i == 0 && ch != 1) 
        {
            cout << "Please create the list first!" << endl;
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
                i = 1;
            }
            else if (ch == 2) l.show();
            else if (ch == 3)
            {
                int element;
                cout << "Enter the element to insert after: ";
                cin >> element;
                l.insert_after(element);
            }
            else if (ch == 4)
            {
                int element;
                cout << "Enter the element to insert before: ";
                cin >> element;
                l.insert_before(element);
            }
        }


        
    }


}
