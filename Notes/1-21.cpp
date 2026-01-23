#include <iostream>
using namespace std;

//* WHAT IS AN ALGORITHM?
// Pseudocode for Fibonacci sequence:
int fib(int n);

int main(int argc, char* argv[]) {
   int ans;
   ans = fib(6);
   cout << ans << endl;
   return 0;
}
// Fibonacci numbers grow almost as fast as the powers of two: F_n ≈ 2^(0.694n)
// Recursive: O(2^n) time, O(n) stack space
int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
    //      '-> T(n-1) + T(n-2) [T(n) - number of computer steps to compute fib(n)]
}     
/*
0 | 1 | 1 | 2 | 3 | 5 | . . . 
fib(n) 
    if n is 0, fib(n) = 0
    if n is 1, fib(n) = 1
    else fib(n) = fib(n-1) + fib(n-2)

T(n) <= 2 for n <= 1
*/

//* Checklist for Algorithms
//? Is it correct? 
   // Yes, by definition
//? How much time does it take, as a function of n?
   // O(2^n) complexity
   // T(n) = T(n-1) + T(n-2) + O(3) [one more for the addition] >= F_n
   // T(n) is exponential in n -> impractically slow
//? Can we do better?