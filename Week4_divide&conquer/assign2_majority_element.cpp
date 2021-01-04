#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
/*
vector<int> & get_majority_element(vector<int> &a, int left, int right) {
    if (right==-1) return -1;
    vector<int> temp;
    if (left == right)
    {
        //vector<int> temp;
        temp.push_back(a[left]);
        temp.push_back(1);
    }
    return a[left];
    //write your code here

    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = left+(right-left)/2;

        // Sort first and second halves
        vector<int> &lmajority=get_majority_element(a, left, mid);
        vector<int> &rmajority=get_majority_element(a, mid+1, right);

        if(lmajority==rmajority)
        {
            temp.push_back(lmajority);
            temp.push_back(lmajority[1]+rmajority[1])
            return temp;
        }
        else if(lmajority[0] == -1 || rmajority[0]==-1)
        {
            return lmajority;
        }
        else
        {
            if(lmajority[1]>rmajority[1])
            {
                temp.push_back(lmajority);
                temp.push_back(lmajority[1])
                return temp;
            }
            else if(lmajority[1]>rmajority[1])
            else
            {
                temp.push_back(-1);
                //temp.push_back(lmajority[1]+rmajority[1])
                return temp;
            }
        }
    }
    return -1;
}
*/
int merge(vector<int> &a, int left, int mid, int right, int lmajority, int rmajority)
{

    int lcnt=0,rcnt=0;
    for(int i=left;i<=right;i++)
    {
        if(a[i]==lmajority)
            lcnt++;
    }
    for(int i=left;i<=right;i++)
    {
        if(a[i]==rmajority)
            rcnt++;
    }
    if(lcnt>rcnt)
        return lmajority;
    else if(lcnt<rcnt)
        return rmajority;
    else
        return -1;

}


int get_majority_element(vector<int> &a, int left, int right) {
    if (right==-1) return -1;
    if (left == right)
    {
        return a[left];
    }
    //write your code here

    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = left+(right-left)/2;

        // Sort first and second halves
        int lmajority=get_majority_element(a, left, mid);
        int rmajority=get_majority_element(a, mid+1, right);

        if(lmajority==rmajority)
            return lmajority;
        else if(lmajority==-1)
            return rmajority;
        else if(rmajority==-1)
            return lmajority;
        else{
            int majority=merge(a,left,mid,right,lmajority,rmajority);
            return majority;
        }
    }
    return -1;
}
int check_majority(vector<int> &a, int left, int right)
{
    int majority=get_majority_element(a, left, right);
    int cnt=0;
    if(majority==-1)
        return majority;
    else
    {
        for(int i=0;i<=right;i++)
        {
                if(a[i]==majority)
                    cnt++;
        }
        int size=(right+1)/2;
        if(cnt>size)
            return majority;
        else
            return -1;
    }

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (check_majority(a, 0, a.size()-1) != -1) << '\n';
}
