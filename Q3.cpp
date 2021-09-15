#include <iostream>
#include <vector>

using namespace std;

void bin2(int n)
{
    static int b = false;
    if (n == 0) 
    {   
        if (!b) cout << "0";
        return;

    }
    else
    {
        b = true;
        bin2(n / 2);
        cout << n % 2;
    }
}

void bin(int n)
{
    static vector<int> bin_rep;
    static vector<int>::reverse_iterator itr;
    if (n == 0)
    {
        if (bin_rep.size() == 0) cout << "0";
        else
        {
            for (itr = bin_rep.rbegin(); itr != bin_rep.rend(); itr++) cout << *itr;
        }
        
        cout << endl;
    }
    else
    {
        bin_rep.push_back(n % 2);
        bin(n / 2);

    }
}

int main()
{
    bin2(1);
}
