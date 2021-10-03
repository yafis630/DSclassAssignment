#include <iostream>

using namespace std;

void if_prime(int);

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
        int len;
    
    public:
        void create(int length)
        {
            
            len = length;
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
            else if (head->get_next() == NULL) cout << "Insertion not possible as element was not found!" << endl;
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

        void remove(int element)
        {
            Node *pres = head, *prev;
            if (pres->get_data() == element)
            {
                head = pres->get_next();
                delete(pres);
            }
            else
            {
                while (pres->get_data() != element && pres->get_next() != NULL)
                {
                    prev = pres;
                    pres = pres->get_next();
                }
                if (pres->get_data() == element)
                {
                    prev->set_next(pres->get_next());
                    if (pres == tail) tail = prev;
                    delete pres;
                }
                else cout << "Element not found!" << endl;
            }

        }

        void remove_all(int element)
        {
            Node *pres = head, *prev;
            bool flag = false;
            while (true)
            {
                if (pres->get_data() == element)
                {
                    flag = true;
                    if (pres == head)
                    {
                        head = pres->get_next();
                        delete pres;
                        pres = head;
                        if (head == NULL)
                        {
                            cout << "All instances deleted!" << endl;
                            break;
                        }
                        continue;
                    }
                    else
                    {
                        prev->set_next(pres->get_next());
                        if (pres == tail) tail = prev;
                        delete pres;
                        pres = prev;
                    }

                }
                prev = pres;
                pres = pres->get_next();
                if (pres == NULL)
                {
                    if (flag) cout << "All instances deleted!" << endl;
                    else cout << "Element not found!" << endl;
                    break;
                }

            }


        }


        void even()
        {
            Node *p = head;
            while (p != NULL)
            {
                if (p->get_data() % 2 == 0)  cout << p->get_data() << " ";
                p = p->get_next();
            }
            cout << endl;
        }

        void odd()
        {
            Node *p = head;
            while (p != NULL)
            {
                if (p->get_data() % 2 != 0)  cout << p->get_data() << " ";
                p = p->get_next();
            }
            cout << endl;
        }
        
        void is_prime()
        {
            Node *p = head;
            while (p != NULL)
            {
                int check = p->get_data();
                if_prime(check);
                p = p->get_next();
            }
            cout << endl;
        }

        void freq(int data)
        {
            Node *p = head;
            int times = 0;
            while (p != NULL)
            {
                if (p->get_data() == data) times++;
                p = p->get_next();
            }
            cout << times << endl;
        }

        void max_min()
        {
            Node *p = head;
            int max = p->get_data(), min = p->get_data();
            while (p != NULL)
            {
                if (p->get_data() > max) max = p->get_data();
                if (p->get_data() < min) min = p->get_data();
                p = p->get_next(); 
            }
            cout << "Max: " << max << endl << "Min: " << min << endl;
        }

        void b_sort(int option)
        {
            if (option == 1)
            {
                for (int i = 0; i < len; i++)
                {
                    Node *p = head;
                    while (p != tail)
                    {
                        if (p->get_data() > p->get_next()->get_data())
                        {
                            int temp = p->get_data();
                            p->set_data(p->get_next()->get_data());
                            p->get_next()->set_data(temp);
                        }
                        p = p->get_next();
                    }
                }
            }
            else if (option == 2)
            {
                for (int i = 0; i < len; i++)
                {
                    Node *p = head;
                    while (p != tail)
                    {
                        if (p->get_data() < p->get_next()->get_data())
                        {
                            int temp = p->get_data();
                            p->set_data(p->get_next()->get_data());
                            p->get_next()->set_data(temp);
                        }
                        p = p->get_next();
                    }
                }
            }
        }

        void create_sorted(int length)
        {
            len = length;
            for (int i = 0; i < length; i++)
            {
                int data;
                cout << "Enter element: ";
                cin >> data;
                Node *temp = new Node;
                temp->set_data(data);
                temp->set_next(NULL);
                if (i == 0)
                {
                    head = temp;
                    tail = temp;
                }
                else
                {
                    Node *pres = head, *prev;
                    while (pres != NULL && pres->get_data() < data)
                    {
                        prev = pres;
                        pres = pres->get_next();
                    }
                    if (pres == head)
                    {
                        temp->set_next(head);
                        head = temp;
                    }
                    else if (pres == NULL)
                    {
                        tail->set_next(temp);
                        tail = temp;
                    }
                    else
                    {
                        temp->set_next(pres);
                        prev->set_next(temp);
                    }

                }
            }
        }


};

void if_prime(int n)
{
    if (n < 2) return;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return;
        
    }
    cout << n << " ";
}

int main()
{
    int flag = 0;
    LinkedList l;
    while (true)
    {
        int ch;
        cout << "Enter 1 to create a new list.\n2 to show the list." << 
        "\n3 to insert after a node.\n4 to insert before a node.\n5 to delete an element.\n" <<
        "6 to delete all instances of an element.\n7 to sort." << "\n8 to display even numbers.\n" << 
        "9 to display odd numbers\n10 to display prime numbers\n11 to display frequency of an element.\n" << 
        "12 to find max and min.\n13 to create a sorted list.\n14 to exit.\n";
        cin >> ch;
        if (ch == 14) return 0;
        else if (flag == 0 && (ch != 1 && ch != 13)) 
        {
            cout << "Please create the list first!" << endl;
            continue;
        }
        else
        {
            
            if (ch == 1 || ch == 13)
            {
                int len;
                cout << "Enter the length of the list: ";
                cin >> len;
                if (ch == 1) l.create(len);
                else if (ch == 13) l.create_sorted(len);
                flag = 1;
            }
            else if (ch == 2) l.show();

            else
            {
                int element;
                if (ch == 3)
                {
                    cout << "Enter the element to insert after: ";
                    cin >> element;
                    l.insert_after(element);
                }
                else if (ch == 4)
                {
                    cout << "Enter the element to insert before: ";
                    cin >> element;
                    l.insert_before(element);
                }
                else if (ch == 5)
                {
                    cout << "Enter the element to delete: ";
                    cin >> element;
                    l.remove(element);
                }
                else if (ch == 6)
                {
                    cout << "Enter the element to delete: ";
                    cin >> element;
                    l.remove_all(element);
                }
                else if (ch == 7)
                {
                    int sort_by;
                    cout << "Enter 1 to sort ascendingly or 2 to sort descendingly: ";
                    cin >> sort_by;
                    if (sort_by == 1) l.b_sort(1);
                    else if (sort_by == 2) l.b_sort(2);
                }

                else if (ch == 8) l.even();

                else if (ch == 9) l.odd();

                else if (ch == 10) l.is_prime();

                else if (ch == 11)
                {
                    cout << "Enter the element: ";
                    cin >> element;
                    l.freq(element);
                }
                else if (ch == 12) l.max_min();


            }

        }


        
    }


}
