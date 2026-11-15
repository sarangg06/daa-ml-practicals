#include <iostream>
using namespace std;

// Recursive approach
int fibRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Non-recursive (Iterative) approach
int fibIterative(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n = 10; // Find 10th Fibonacci number
    cout << "Iterative Fibonacci of " << n << " is: " << fibIterative(n) << endl;
    cout << "Recursive Fibonacci of " << n << " is: " << fibRecursive(n) << endl;
    return 0;
}