#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

int main(void)
{
        vector<int> v1;
        for(int i=0; i<10000000; i++)
                v1.push_back(rand());
        sort(v1.begin(),v1.end());
        return 0;
}
