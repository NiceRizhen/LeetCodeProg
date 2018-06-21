int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int minnum = INT_MAX;
    int i=0, j=0;
    for(i = 0; i < pricesSize; i++)
    {
        if(prices[i] >= minnum) continue;
        minnum = prices[i];
        
        for(j = i+1; j < pricesSize; j++)
        {
            if(prices[i] < prices[j])
            {
                if((prices[j] - prices[i] > max)) max = prices[j] - prices[i];
            }
        }
    }
    
    return max;
}