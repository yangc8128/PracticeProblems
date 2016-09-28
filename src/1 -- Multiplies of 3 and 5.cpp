/*
Multiples of 3 and 5
*/

#include <iostream>

using namespace std;

int main()
{
   int max = 1000 -1;

   int i = max/3;
   int j = max/5;
   int k = max/15;

   int sum3 = 3*(i*(i+1))/2;
   int sum5 = 5*(j*(j+1))/2;;
   int sum15 = 15*(k*(k+1))/2;;

   cout << sum3 + sum5 - sum15 << endl;

   return 0;
}
