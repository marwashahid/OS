#include<iostream>
#include<unistd.h>
#include<cstdlib>
using namespace std;
int main()
{
    int n, i, j, temp;
    int* arr;
    cout << "Enter the Size: ";
    cin >> n;
    arr = new int[n];
    for (i = 0; i < n; i++)
    {   cout << "Enter the value [" << i + 1 << "] =";
    cin >> arr[i];
}
    sleep(2); 
    cout << "Old Array [";
    for (i = 0; i < n; i++)
    {   cout << arr[i];
    if (i < n - 1)
        cout << ",";
}
    cout <<"]" << endl;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    sleep(2); 
    cout << "\nArray Sorted Successfully!\n";
    cout << "\nThe New Array is: [";
    for (i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << "]" << endl;

    std::cin.get();
    std::cin.get();  
    return 0;
}
