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
};

int main()
{
    int i = 0;
    LinkedList l;
    while (true)
    {
        int ch;
        cout << "Enter 1 to create a new list.\n2 to show the list.\n3 to exit.\n";
        cin >> ch;
        if (i == 0 && ch == 2) 
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
                i = 1;
            }
            else if (ch == 2) l.show();
            else return 0;
        }


        
    }
}
