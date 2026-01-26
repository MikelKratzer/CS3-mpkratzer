//* ALGORITHMS WITH NUMBERS

// - FACTORING: Given a number N, express it as a product of its prime factors
// - PRIMALITY: Determine whether N is prime
// - While factoring is hard (exponential time), can efficiently test if N is prime

//* Addition:
    // - If x and y are n digits long, total running time is c_0 + c_1*n, or just O(n)
    // - Focus on bit complexity of algorithm (number of elementary operations on individual bits)

//* Multiplication and Division
    // - If x and y are both n bits, there are n rows, with lengths up to 2n bits
    // - Takes O(n^2) time, quadratic in size of inputs

    //? easy multiply(x,y)
    // INPUT: n-bit integers x and y, n = 2^k
    // OUTPUT: z = xy
    // x_L = first n/2 bits of x, x_R = last n/2 bits of x } O(n)
    // y_L = first n/2 bits of y, x_R = last n/2 bits of y }
    // A = easy multiply (x_L, y_L); B = easy multiply (x_R, y_R); } 4*T(n/2) -> O(n^2)
    // C = easy multiply (x_L, y_R); D = easy multiply (x_R, y_L); }
    // z = (2^n)*A + 2^(n/2)*(C+D) + B <- O(n)

    //? fast multiply(x,y)
    // A = fast multiply(x_L,y_L)               }
    // B = fast multiply(x_R,y_R)               } 3*T(n/2) -> O(n^log_2(3)) ≈ O(n^1.59)
    // C = fast multiply(x_L + x_R, y_L + y_R)  }
    // z = (2^n)*A + 2^(n/2)*(C-A-B) + B <- O(n)
    // return z <- O(1)

//! Al Khwarizmi's Algorithm:
#include <iostream>
using namespace std;

long long int multiply(long long int, long long int);
void divide(long long int, long long int, long long int&, long long int&);

int main(int argc, char* argv[]) {
    long long int ans = multiply(6,7);
    cout << "ANS: " << ans << endl;
    long long int q = 0;
    long long int r = 0;
    divide(43, 7, q, r);
    cout << "QUOTIENT: " << q << " REMAINDER: " << r << endl;
    return 0;
}
// multiply by repeating halvings: same as binary multiplication
long long int multiply(long long int x, long long int y) {
    if (y == 0) return 0;
    long long int z = multiply(x, floor(y/2));
    if (y % 2 == 0) return 2*z;
    else return x + 2*z;
}
// FIGURE 1.2: x = yq + r
void divide(long long int x, long long int y, long long int& q, long long int& r) {
    if (x == 0) { q = 0; r = 0; return; }
    divide(floor(x/2), y, q, r);
    q = 2*q; r = 2*r;
    if (x % 2 == 1) r++;
    if (r >= y) { r = r - y; q++; }
    return;
}