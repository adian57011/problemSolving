#include<iostream>
#include<vector>
using namespace std;


bool isEven(int number)
{
    if(number % 2 == 1)
    {
       cout << number << " is odd" << endl;
       return false;
    }

    else
    {
        cout << number << " is even" << endl;
        return true;
    }
}

void multiplicationTable(int number)
{
    for(int i = 1; i < 11; i++)
    {
        cout << number * i << endl;
    }
}

void sum_of_number_naive(int number)
{
    int sum = 0;
    for(int i = 0; i <= number; i++)
    {
        sum += i;
    }

    cout << "Total sum: " << sum << endl;
}

int sum_of_number_recursion(int number)
{
    if(number == 1)
        return 1;

    return number + sum_of_number_recursion(number-1);
}

void count_even_odd(vector<int>& arr)
{
    int even = 0, odd = 0;
    for(int i = 0; i < arr.size();i++)
    {
        if(arr[i] % 2 == 1)
            odd++;
        else
            even++;

    }

    cout << odd << " " <<  even << endl;
}

double avg_arr(vector<int>& arr)
{
    double avg = 0;int sum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    return sum / arr.size();
}

int main()
{
    cout<< "Hello World" <<endl;

    vector<int> arr = {2, 3, 4, 5, 6};

    vector<int> arr2 = {10, 2, 3, 4, 5, 6, 7, 8, 9};
    count_even_odd(arr);

    cout << avg_arr(arr2) << endl;

    return 0;
}
