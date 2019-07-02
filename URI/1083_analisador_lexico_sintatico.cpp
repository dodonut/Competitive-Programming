#include <iostream>
#include <stack>
#include <map>
#include <set>

using namespace std;

map<char, int> prec = {
    {'^', 6}, {'*', 5}, {'/', 5}, {'+', 4}, {'-', 4}, {'<', 3}, {'>', 3}, {'=', 3}, {'#', 3}, {'.', 2}, {'|', 1}};

enum prevChar
{
    NIL,
    OPERAND,
    OPERATOR,
    OPEN_PAREN,
    CLOSE_PAREN
};

set<char> alphabet;
bool isOperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '<':
    case '>':
    case '=':
    case '#':
    case '.':
    case '|':
    case '^':
        return true;
    }
    return false;
}

bool hasHigherPrec(char c, char v)
{
    return prec[c] >= prec[v];
}

bool isOpenParen(char c)
{
    return c == '(';
}

bool isCloseParen(char c)
{
    return c == ')';
}

bool isParen(char c)
{
    return isOpenParen(c) || isCloseParen(c);
}

bool isOperand(char c)
{
    return !(isOperator(c) || isParen(c));
}

bool isRecognized(char c)
{
    return alphabet.count(c) > 0;
}

string infix_to_postfix(const string &exp)
{
    stack<char> s;
    int paren = 0, opd = 0;
    string ans = "";
    prevChar prev = NIL;

    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '\\')
            printf("aqui");
        if (!isRecognized(exp[i]))
            return "Lexical Error!";

        if (isOperand(exp[i]))
        {
            if (prev == OPERAND)
                return "Syntax Error!";

            opd++;
            ans += exp[i];
            prev = OPERAND;
        }
        else if (isOperator(exp[i]))
        {
            opd--;
            if (prev == OPERATOR || prev == OPEN_PAREN || prev == NIL)
                return "Syntax Error!";
            prev = OPERATOR;
            while (!s.empty() && hasHigherPrec(s.top(), exp[i]) && !isParen(exp[i]))
            {
                ans += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
        else if (isOpenParen(exp[i]))
        {
            prev = OPEN_PAREN;
            s.push(exp[i]);
            paren++;
        }
        else if (isCloseParen(exp[i]))
        {
            paren--;
            if (prev == OPERATOR || prev == OPEN_PAREN || paren < 0)
                return "Syntax Error!";
            while (!s.empty() && !isOpenParen(s.top()))
            {
                ans += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
    }
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    if (paren || (opd < 0 || opd > 1) || prev == OPERATOR)
        return "Syntax Error!";
    
    return ans;
}

int main()
{
    string rec = "()<>=#^+-*/.|abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < rec.size(); i++)
        alphabet.insert(rec[i]);
        
    string line;
    while (getline(cin, line))
    {
        cout << infix_to_postfix(line) << "\n";
    }
}
