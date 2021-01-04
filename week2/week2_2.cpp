#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int get_fibonacci_last_digit(int n){

    if(n<=1)
        return n;

    int prev=0;
    int curr=1;
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        tmp = prev;
        prev = curr;
        curr = tmp + curr;
        curr = curr % 10;
    }
    return curr;

}

int main() {
    int n;
    std::cin >> n;
    //int b = get_fibonacci_last_digit_naive(n);
    //std::cout << b << '\n';

    int c = get_fibonacci_last_digit(n);
    std::cout << c << '\n';
}
