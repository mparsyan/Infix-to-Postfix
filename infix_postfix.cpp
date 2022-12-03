#include <iostream>
#include<stack>
#include<string>

int priority(char ch)
{
     if( ch == '-' || ch == '+')
     {
        return 1;
     }
     if( ch == '*' || ch == '/')
     {
        return 2;
     }
     else
     {
        return -1;
     }
}

bool operand(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string intfix_postfix(std::string infix)
{
    int n = infix.size();
    std::stack<char> my_char;
    std::string expression;
    for (int i = 0; i < n; i++)
    {
        if (operand(infix[i]))
        {
            expression.push_back(infix[i]);
        }
        else if(infix[i] == '(')
        {
            my_char.push('(');
        }
        else if(infix[i] == ')')
        {
            while( my_char.top() != '(' )
            {
                expression.push_back(my_char.top());
                my_char.pop();
            }       
            my_char.pop();
        }
        else
        {
            while(!my_char.empty() && my_char.top() != '(' && priority(my_char.top()) >= priority(infix[i]))
            {
                expression.push_back(my_char.top());
                my_char.pop();
            }
            my_char.push(infix[i]);
        }
    }
    
    while (!my_char.empty())
    {
        expression.push_back(my_char.top());
        my_char.pop();
    }
    return expression;
}
int main() 
{
    std::string infix = "A*(H+J+K)+L*M";
    std::string expression = intfix_postfix(infix);
    std::cout << "Postfix expression : " << expression << std::endl;
    return 0;
}  