#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    /*
    int stop_cnt=stops.size();
    int i=0,min_dist;
    while(i<=stop_cnt)
    {
        min_dist=tank;
        if(stops[i+1]-stops[i]>tank)
            return -1;
        else
        {

            while(min_dist>=stop[i]-stop[i-1])
            {
                min_dist-=stop[i]-stop[i-1];
                i=i+1;
            }

        }

    }
    return -1;
    */
    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
