#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}
/*
int binarySearch(int arr[], int x)
{
    int l=0,r=a.size()-1;
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
*/

int binary_search(const vector<int> &a, int get)
{
    int low=0;
    int high=a.size()-1;
    int mid;
    while(low<=high){
        mid=low +(high-low)/2;
        //std::cout<<"mid = "<<mid<<"\n";
        if(a[mid]==get)
            return mid;
        else if(a[mid]>get)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;


}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    std::cout << binary_search(a, b[i]) << ' ';
    //std::cout<<"\n";
  }
}
