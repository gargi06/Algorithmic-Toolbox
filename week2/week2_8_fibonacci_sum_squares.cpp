#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_sum_squares(long long n) {
    if (n%60 <= 2)
        return n%60;

    long long previous = 1;
    long long current  = 1;
    long long sum      = 2;

    for (long long i = 3; i <= n%60; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current=current%10;
        sum += current * current;
        sum=sum%10;
    }

    return sum % 10;
}

int main() {
    /*long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);*/

    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);

    /*int sum=0;
    for(int i=0;i<60;i++)
    {
        sum=sum+fibonacci_sum_squares(i);
        //std::cout << fibonacci_sum(i)<<"\n";
    }
    std::cout << sum<<"\n";
    */
}
