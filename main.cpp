#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char* arr = new char[n * n + 1];
    int number_of_combinations = 0;

    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        for (int j = 1; j <= n; j++)
        {
            int index = ((n * i) + j);
            cin >> arr[index];
            if (arr[index] == 'c')
            {
                counter++;
                number_of_combinations += counter - 1;
            }
        }
    }
    for (int j = 1; j <= n; j++)
    {
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[(n * i) + j] == 'c')
            {
                counter++;
                number_of_combinations += counter - 1;
            }
        }
    }
    cout << number_of_combinations << '\n';
}