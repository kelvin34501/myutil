#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

bool cmp(const int &a, const int &b)
{
        if(a<=b)
                return true;
        else
                return false;
}

int main(void)
{
        vector<int> v1;
        for(int i=0; i<10000000; i++)
                v1.push_back(rand());
        sort(v1.begin(),v1.end(),cmp);
        return 0;
}
