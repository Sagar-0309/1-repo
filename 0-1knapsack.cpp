#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {

            if (wt[i - 1] <= w)

                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

int main()
{
    cout<<"Enter number of items: ";
    int n;
    cin>>n;
    cout<<endl;
    int profit[n];
    int weight[n];
    cout<<"Enter profits: ";
    for(int i = 0;i<n;i++){
        cin >> profit[i];
    }
    cout<<endl;
    cout<<"Enter corresponding weights: ";
    for(int i = 0;i<n;i++){
           cin>>weight[i];
    }
    cout<<"Enter Weight: " ;
    int W ;
    cin>>W;
    cout<<endl;
    cout << knapSack(W, weight, profit, n);
    return 0;
}
