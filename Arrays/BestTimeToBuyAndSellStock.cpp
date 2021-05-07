#include <bits/stdc++.h>
using namespace std;

// Example:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

int maxProfit(vector<int> &prices)
{

    int minBuy = INT32_MAX, maxSell=0;

    for(int i=0; i<prices.size(); i++){

        if(minBuy>prices[i]){
            minBuy = prices[i];
        }
        else if(prices[i]-minBuy>maxSell){
            maxSell = prices[i]-minBuy;
        }
    } 
    
    return maxSell;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    //vector<int> prices = {7,6,4,3,1};
    cout<<"Max Profit: "<<maxProfit(prices);
    return 0;
}