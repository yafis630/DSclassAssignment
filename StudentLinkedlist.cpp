#include <iostream>
using namespace std;

class Node
{
    private:
        char name[30];
        int age;
        float marks;
        Node *next;

    public:
        void get_name() { cout << name << endl;}
        void set_name() { cout << "Enter name: "; cin >> name; }
        void get_age() { cout << age << endl;}
        void set_age() { cout << "Enter age: "; cin >> age; }
        void get_marks() { cout << marks << endl;}
        void set_marks() { cout << "Enter marks: "; cin >> marks; }
        Node* get_next() { return next; }
        void set_next(Node *next) { this->next = next; }
};

class StudentLinkedList
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
                cout << "ENTER DETAILS OF STUDENT " << i+1 << endl;
                temp->set_name();
                temp->set_age();
                temp->set_marks();
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
            int i = 0;
            while (p != NULL)
            {
                cout << "SHOWING DETAILS OF STUDENT " << i + 1 << endl;
                cout << "Name: ";
                p->get_name();
                cout << "Age: ";
                p->get_age();
                cout << "Marks: ";
                p->get_marks();
                p = p->get_next();
                i++;
            }
                
        }
};


int main()
{
    StudentLinkedList l;
    int flag = 0;
    while (true)
    {
        int ch;
        cout << "Enter 1 to create a list of students.\n2 to display it.\n3 to exit." << endl;
        cin >> ch;
        if (ch == 2 && flag == 0) cout << "Please create the list first!" << endl;
        else if (ch == 1)
        {
            int size;
            cout << "Enter the number of students: ";
            cin >> size;
            l.create(size);
            flag = 1;
        }
        else if (ch == 2) l.show();
        else if (ch == 3) return 0;
        else continue;

    }
}
