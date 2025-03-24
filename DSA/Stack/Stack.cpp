#include <bits/stdc++.h>
using namespace std;


//implementing a queue using stacks

class Queue{
public:
    stack<int> s1,s2;

    void en(int x)
    {
        //to enqueue we must store the values in stack 2 from stack 1

        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // after stack is empty we push the data.
        s1.push(x);

        //then we refill the stack 1 again.

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue()
    {
        if(s1.empty())
            return -1;

        int data = s1.top();
        s1.pop();
        return data;
    }

};

bool knows(int a, int b, vector<vector<int>> &matrix)
{
    return matrix[a][b];
}

int findCelebrity(int n,vector<vector<int> > &matrix)
{
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        s.push(i);
    }

    int a = 0, b = 0;

    while(s.size() != 1)
    {
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();

        if(knows(a,b,matrix) == 1)
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    int potential_celebrity = s.top(), coloumn_zero = 0;
    bool isCeleb_row = true;
    bool isCeleb_coloumn = false;

    for(int i = 0; i < n; i++)
    {
        if(matrix[potential_celebrity][i] != 0)
            isCeleb_row = false; break;
    }

    for(int i = 0; i < n; i++)
    {
        if(matrix[i][potential_celebrity] == 1)
            coloumn_zero ++;
    }

    if(coloumn_zero == n-1)
        isCeleb_coloumn = true;

    if(isCeleb_row && isCeleb_coloumn)
            return potential_celebrity;

    return -1;
}


int main()
{
        int n = 4;
    vector<vector<int> > matrix = { { 0, 0, 1, 0 },
                                    { 0, 0, 1, 0 },
                                    { 0, 0, 0, 0 },
                                    { 0, 0, 1, 0 } };

    int id = findCelebrity(n, matrix);
    if (id == -1)
        cout << "No celebrity";
    else
        cout << "Celebrity ID " << id;


    Queue q;
    q.en(1);
    q.en(2);
    q.en(3);

    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';

    return 0;

}
