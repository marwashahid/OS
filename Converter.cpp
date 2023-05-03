#include<iostream>
#include<unistd.h>
#include<cstdlib>

using namespace std;
int converter(int n)
{
    int b = 1, dec = 0, rem = 0;
    while (n > 0)
    {
        rem = n % 10;
        dec = dec + rem * b;
        b *= 2;
        n /= 10;
    }
    return dec;
}
int main()
{
    int num;
    cout << "Enter the binary number : ";
    cin >> num;    
    sleep(2);
    cout << "The decimal equivalent of " << num << " is " << converter(num)<<endl;

   std::cin.get();
    std::cin.get();
    return 0;
}
