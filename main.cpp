#include <bits/stdc++.h>

using namespace std;

// Compute sum of proper divisors of n (excluding n itself)
unsigned long long sum_proper_divisors(unsigned long long n) {
    if (n <= 1) return 0ULL;
    unsigned long long sum = 1ULL; // 1 is always a proper divisor for n>1
    unsigned long long limit = sqrt((long double)n);
    for (unsigned long long d = 2; d <= limit; ++d) {
        if (n % d == 0) {
            unsigned long long other = n / d;
            if (d == other) {
                sum += d; // perfect square, add only once
            } else {
                sum += d + other;
            }
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;
    for (int i = 0; i < m; ++i) {
        unsigned long long n;
        cin >> n;
        unsigned long long s = sum_proper_divisors(n);
        cout << (s == n ? 1 : 0) << '\n';
    }
    return 0;
}

