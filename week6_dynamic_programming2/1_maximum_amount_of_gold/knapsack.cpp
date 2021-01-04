#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {

    vector<vector<int>> vec(w.size()+1, vector<int>(W+1,0));

    for(int i=1;i<=w.size();i++)
    {
        for(int j=1;j<=W;j++)
        {
            int weight1=vec[i-1][j];
            int weight2=-2147483647;
            if(w[i-1]<=j)
            {
                weight2=vec[i-1][j-w[i-1]] + w[i-1];
            }
            vec[i][j]=std::max(weight1,weight2);

        }
    }

    return vec[w.size()][W];;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
