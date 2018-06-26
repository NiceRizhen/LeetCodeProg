int maxProfit(int* prices, int pricesSize) {
    
    int reward = 0;
    int i = 0;
    int cur = prices[0];
    
    for(i = 1; i < pricesSize; i++)
    {

        if(prices[i] > cur){
            reward += prices[i] - cur;
            cur = prices[i];
        }
        
        if(prices[i] < cur)
        {
            cur = prices[i];
        }
    }
    
    return reward;
}