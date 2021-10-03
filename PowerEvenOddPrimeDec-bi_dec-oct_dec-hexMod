#include <iostream>
#include <vector>

using namespace std;

int power(int a, int b);
string even_odd(int n);
bool prime(int n);
void dec_bi(int n);
void dec_oct(int n);
void dec_hex(int n);
int mod(int n);

int main()
{
    cout << power(2, 5) << endl;
    cout << even_odd(5) << endl;
    cout << prime(23) << endl; // 0 means not prime and 1 means prime
    dec_bi(10);
    dec_oct(20);
    dec_hex(10);
    cout << mod(-10) << endl;
}

int power(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c *= a;
    }
    return c;
}

string even_odd(int n)
{
    return n % 2 == 0 ? "even" : "odd";
}

bool prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void dec_bi(int n)
{
    if (n == 0) cout << '0';
    vector<int> res;
    vector<int>::reverse_iterator p; 
    while (n != 0)
    {
        res.push_back(n % 2);
        n /= 2;
    }
    for (p = res.rbegin(); p != res.rend(); p++)
    {
        cout << *p;
    }
    cout <<  endl;
}

void dec_oct(int n)
{
    if (n == 0) cout << '0';
    vector<int> res;
    vector<int>::reverse_iterator p; 
    while (n != 0)
    {
        res.push_back(n % 8);
        n /= 8;
    }
    for (p = res.rbegin(); p != res.rend(); p++)
    {
        cout << *p;
    }
    cout <<  endl;
}

void dec_hex(int n)
{
    if (n == 0) cout << '0';
    char symbs[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> res;
    vector<int>::reverse_iterator p; 
    while (n != 0)
    {
        res.push_back(n % 16);
        n /= 16;
    }
    for (p = res.rbegin(); p != res.rend(); p++)
    {
        cout << symbs[*p];
    }
    cout <<  endl;
}

int mod(int n)
{
    return n < 0 ? -1 * n : n;
}
