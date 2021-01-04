#include <iostream>
#include <vector>
#include <algorithm>
//using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {

    int n = numbers.size();
    int max1=-1,max2=-1;
    for (int first = 0; first < n; first++) {
        if((max1==-1) || (numbers[max1]<numbers[first]))
        {

            max1=first;
        }
    }
    /*std::cout<<max1<<"    ";
    std::cout<<max2<<"  ";*/
    for (int first = 0; first < n; first++) {
        if((max1!=first) && ((max2 == -1) || (numbers[max2]<numbers[first])))
        {
            //std::cout<<first<<"  "<<max2<<"  "<<"\n";
            max2=first;
        }
    }
    /*std::cout<<max1<<"    ";
    std::cout<<max2<<"  ";*/
    



    return ((long long)(numbers[max1])) * numbers[max2];

}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers)<< "\n";
    return 0;
}
