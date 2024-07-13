// Q1) Leetcode 1343
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v={2,2,2,2,5,5,5,8};
    int k=3, threshold=4, n=v.size(), i, j, sum=0 , count=0;
    for(i=0;i<k;i++) sum+=v[i];
    if(sum/k>=threshold) count++;
    i=1,j=k;
    while(j<n){
        sum=sum-v[i-1]+v[j];
        if(sum/k>=threshold) count++;
        i++,j++;
    }
    cout<<count;
}



// Q2) Leetcode 2302
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>nums={2,1,4,3,5};
    int k=10,n=nums.size(),i,j,sum=0,mul,count=0;
        for(i=0;i<n;i++){
           sum+=nums[i];
           if(sum*(i+1)>=k) break; 
        }
           if(i==n) j=i;
           else     j=i+1;
           i=0;
        while(j<=n && i!=n){
            mul=sum*(j-i);
            if(mul<k && j!=n){
                sum+=nums[j];
                j++;
            }
            else if(mul<k && j==n){
                count+=j-i;
                i++;
            }
            else if(mul>=k){
                count+=j-i-1;
                sum-=nums[i];
                i++;
            }
        }
        cout<<count;
}