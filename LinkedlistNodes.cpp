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
        void set_next(Node* n) { next = n; }  
};

int main()
{
    Node n1, n2, n3, n4, n5;
    n1.set_data(1);
    n2.set_data(2);
    n3.set_data(3);
    n4.set_data(4);
    n5.set_data(5);
    n1.set_next(&n2);
    n2.set_next(&n3);
    n3.set_next(&n4);
    n4.set_next(&n5);
    n5.set_next(NULL);
    cout << "Accessing from the previous node: ";
    cout << n1.get_data() << " " << n1.get_next()->get_data() << " " << n2.get_next()->get_data() 
    << " " << n3.get_next()->get_data() << " " << n4.get_next()->get_data() << endl;
    cout << "Accessing from the first node: ";
    cout << n1.get_data() << " " << n1.get_next()->get_data() << " " << n1.get_next()->get_next()->get_data() << " "
    << n1.get_next()->get_next()->get_next()->get_data() << " " << n1.get_next()->get_next()->get_next()->get_next()->get_data() << endl;
}
