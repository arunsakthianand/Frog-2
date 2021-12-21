#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N,K;
    vector<long long int> h;
    vector<long long int> cost;

    cin>>N>>K;
    
    for (int i=0 ; i<N ; i++)
    {
        int temp;
        cin>>temp;
        h.push_back(temp);
    }

    cost.push_back(0);
    cost.push_back(abs(h[0]-h[1]));
    
    for(int i=3 ; i<=N ; i++)
    {
        vector<long long int> k;
        for (int j=1 ; j<=K ; j++)
        {
            if (i > j)
            {
                long long int temp;
                temp = cost[i-j-1] + abs(h[i-1]-h[i-j-1]);
                k.push_back(temp);
            }
        }
        cost.push_back(*min_element(k.begin(), k.end()));
    }
    
    cout<<cost[N-1];
    return 0;
}