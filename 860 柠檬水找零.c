bool lemonadeChange(int* bills, int billsSize) {
    int i = 0;
    
    int five = 0;
    int ten = 0;
    int n = 0;
    for(i = 0; i < billsSize; i++)
    {
        if(bills[i] == 5) five++;
        if(bills[i] == 10)
        {
            if(--five < 0) return false;
            ten++;
        }
        if(bills[i] == 20)
        {
            if(ten >= 1)
            {
                if(five >= 1){
                    five--;
                    ten--;
                }
                else return false;
            }
            else{
                if(five < 3) return false;
                else five -= 3;
            }
        }
    }
    return true;
}