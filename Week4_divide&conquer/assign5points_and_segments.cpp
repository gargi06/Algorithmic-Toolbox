#include <iostream>
#include <vector>
#include<algorithm>
using std::vector;

int binary_search(const vector<int> &a, int get)
{
    int low=0;
    int high=a.size();
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
    return low;


}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    //write your code here
    /*
    for(int i=0;i<points.size();i++)
    {
        std::cout<<cnt[i]<<"\t";
    }
    std::cout<<"\n";
    */
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    for(int i=0;i<points.size();i++)
    {
        int l=binary_search(starts,points[i]);
        int r=binary_search(ends,points[i]);
        int z;
        if(starts[l]==points[i])
        {
            for(z=l+1;z<starts.size();z++)
            {
                if(starts[z]!=points[i])
                {
                    break;
                }
            }
            l=z;

        }
        if(ends[r]==points[i])
        {
           for(z=r-1;z>=0;z--)
            {
                if(ends[z]!=points[i])
                {
                    break;
                }
            }
            r=z+1;

        }

        int cnti=l-r;
        /*
        cnti is equavilant to no of start point less than or qual to point[i] - no of end points less than point[i].
        */
        cnt[i]=cnti;
    }
    //std::cout<<"cnt ="<<cnt[2];
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  //std::cout<<"Binary Search : "<<binary_search(points,3)<<"\n";

  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {

    std::cout << cnt[i] << ' ';
  }
}
