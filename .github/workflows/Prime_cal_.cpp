#include <iostream>
#include <fstream>
#include<math.h>
using namespace std;
int main()
{   
    //Q Program to find prime numbers in a range save them in file.
    ofstream Prime;
	int num1,num2;
    int fnd=0,ctr=0;
    cout << "\n\n Find prime number within a range:\n";
	cout << " Input number for starting range: ";
	cin>> num1;
	cout << " Input number for ending range: ";
	cin>> num2;		
    
    Prime.open("Testprimenumber.txt");
    Prime << "\nThe prime numbers between "<<num1<<" and "<<num2<<" are:"<<endl;
    for(int i=num1;i<=num2;i++)
       {
           for(int j=2;j<=sqrt(i);j++)
               {
               if(i%j==0)
                  ctr++;
               }
               if(ctr==0&&i!=1)
               { fnd++;
                 Prime<<i<<" ";
               }
               ctr=0;
       }
    Prime.close();
 return 1;
}
