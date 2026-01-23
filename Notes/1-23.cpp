//* ASYMPTOTIC NOTATIONS
//* Big-O Notation:
   // upper bound of running time for an algorithm (worst-case time complexity)
   // If f(n) describes running time of an algorithm:
      // f(n) is O(g(n)) if there exists a positive constant C and n_0 such that, 
      // 0 ≤ f(n) ≤ Cg(n) for all n ≥ n_0
   // O(1) - constant time
   // O(log n) - binary search tree
   // O(n) - loops (for i in n, while (i < n))
   // O(n^2) - nested loops (for i in n, for j in n)
      // could be order O(nm) (for i in n, for j in m)
   // O(2^n) - exponential growth (e.g. Fibonacci)

//* Omega Notation (Ω-Notation):
   // lower bound of running time for an algoritm (best-case time complexity)
   // Ω(g(n)) = {f(n): there exists positive constants C and n_0 such that,
      // 0 ≤ C*g(n) ≤ f(n) for all n ≥ n_0}

//* Theta Notation (Θ-Notation):
   // encloses the function from above and below (average-case time complexity)
   // Θ(g(n)) = {f(n): there exists positive constants C_1, C_2 and n_0 such that,
      // 0 ≤ C_1 * g(n) ≤ f(n) ≤ C_2 * g(n) for all n ≥ n_0}

#include <iostream>
using namespace std;

int fib_M(int n);
int fib3(int n);

int main(int argc, char* argv[]) {
   int ans, ans2;
   ans = fib_M(6);
   cout << ans << endl;
   ans2 = fib3(6);
   cout << ans2 << endl;
   return 0;
}
// Memoization
// a = array of size n
// n = nth Fibonacci number
// a(1) = 0; a(2) = 1
// fib_M(a, n)

int fib_M(int n) { // Time = O(n), Space = O(n)
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int a[n + 1]; // Size n+1 to accommodate index n
    a[0] = 0; a[1] = 1;
    for (int i = 2; i <= n; i++) { a[i] = a[i - 1] + a[i - 2]; }
    return a[n];
}

int fib3(int n) { // Time = O(n), Space = O(1)
   if (n <= 0) return 0;
   if (n == 1) return 1;

   int p1 = 0; // fib(i-2)
   int p2 = 1; // fib(i-1)
   int fib = 0;

   for (int i = 2; i <= n; i++) {
      fib = p1 + p2;
      p1 = p2;
      p2 = fib;
   }
   return fib;
}