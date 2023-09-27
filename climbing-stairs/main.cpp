#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 3)
        {
            return n;
        }
        else
        {
            return climbStairs(n - 1) + climbStairs(n - 2);
        }
    }
};

int main()
{
    
    return 0;
}