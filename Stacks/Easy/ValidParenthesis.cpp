#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

bool IsBalanced(string& s)
{
    stack<char> st;

    for(char c : s)
    {
        if(c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
        else if(c == ')' || c == '}' || c == ']')
        {
            if(st.empty())
                return false;

            char top = st.top();

            if((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                 (c == ']' && top != ']')
               )
                {
                    return false;
                }
          return true;
        }

    }

}


int main()
{
    cout << "Program is running"<<endl;

    string s="[()()]{";
    cout<<(IsBalanced(s)?"true":"false");


    return 0;
}

