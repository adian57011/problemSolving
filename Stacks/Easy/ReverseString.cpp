#include<iostream>
#include<stack>

using namespace std;

string reverseString(string& s)
{
    stack<char> st;

    for(char c : s)
    {
        st.push(c);
    }

    string res;
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    cout << "Program started!!!"<< endl;

    string x = "ITISFUNCWITHCSTRINGS";

    cout << reverseString(x) << endl;
    return 0;
}
