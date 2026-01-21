#include <iostream>
using namespace std;

//* WHAT IS AN ALGORITHM?
// Pseudocode for Fibonacci sequence:
int fib(int n);

int main(int argc, char* argv[]) {
   int ans;
   ans = fib(1);
   cout << ans << endl;
   return 0;
}

int fib(int n) {
   if (n = 0) return 0; // O(1)
   if (n = 1) return 1; // O(1)
   else return fib(n-1) + fib(n-2);
   //           T(n-1) + T(n-2)
}
/*
0 | 1 | 1 | 2 | 3 | 5 | . . . 
fib(n)
    if n is 0, fib(n) = 0
    if n is 1, fib(n) = 1
    else fib(n) = fib(n-1) + fib(n-2)
*/

//* Checklist for Algorithms
//? Is it correct? 
   // Yes, by definition
//? How long does it take?
   // O(2^n) complexity
   // f(n) = T(n-1) + T(n-2) + O(3) [one more for the addition] = O(2^n)
//? Can we do better?
