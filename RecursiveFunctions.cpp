#include <iostream>
#include <unordered_map>

using namespace std;

int power(int a, int b);
void dec_to_binary(int n);
int fib(int n);
void tower(int n, int a, int b, int c);

int main()
{
    cout << power(2, 0) << endl;
    dec_to_binary(4);
    cout << endl;
    cout << fib(10) << endl;
    tower(5, 1,2,3);
}

int power(int a, int b)
{
    if (b == 0) return 1;
    else
    {
        return a * power(a, b - 1);
    }
}

void dec_to_binary(int n)
{
    if (n == 0) cout << "0";
    else
    {
        dec_to_binary(n / 2);
        cout << n % 2;
    }
}

int fib(int n)
{
    static unordered_map<int, int> vals;
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else
    {
        if (vals[n] != 0) return vals[n];
        else
        {
            vals[n] = fib(n - 2) + fib(n - 1);
            return vals[n];
        }

    }
}

void tower(int n, int a, int b, int c)
{
    if (n > 0)
    {
        tower(n - 1, a, c, b);
        cout << a << " to " << c << endl;
        tower(n - 1, b, a, c);
    }
}
