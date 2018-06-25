
bool isValid(char* s) {
    char stack[1000000];
    int top = -1;
    int i = 0;
    
    while(s[i])
    {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            stack[++top] = s[i];
        }
        else
        {
            if(top<0) return false;
            if(s[i] == '}' && stack[top--] != '{') return false;
            if(s[i] == ')' && stack[top--] != '(') return false;
            if(s[i] == ']' && stack[top--] != '[') return false;
        }
        i++;
    }
    
    if(top >= 0) return false;
    return true;
}