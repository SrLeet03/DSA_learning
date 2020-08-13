

#include <bits/stdc++.h>

using namespace std;
int FirstsmallerToLeft(int a[] , int n , int k){ 
    stack <int> s;
    vector<int > v;
    for(int i=0 ; i<n ; i++){
        if(s.size()==0){
            v.push_back(-1);
        }else if(s.size()>0 && s.top()<a[i]){
            v.push_back(s.top());
        }else if(s.size()>0 && s.top()>=a[i]){
            while(s.size()>0 && s.top()>=a[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(a[i]);
    }
    
    return v[k-1];
}
int FirstsmallerToRight(int a[] , int n , int k){
    stack <int> s;
    vector<int > v;
    for(int i=n-1 ; i>=0 ; i--){
        if(s.size()==0){
            v.push_back(-1);
        }else if(s.size()>0 && s.top()<a[i]){
            v.push_back(s.top());
        }else if(s.size()>0 && s.top()>=a[i]){
            while(s.size()>0 && s.top()>=a[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }else{
                v.push_back(s.top());
            }
        }
        s.push(a[i]);
    }
    
    return v[k-1];
}
int FindMaxAreaOfHistrogram(int a[] , int n) {
    // width = difffrence betn inces of first samller to left and right 
    // height = valuue of current i 
    // area = of i index if h into w ;
    // return maxm of  this areq arrray !
}
int FindMaxAreaOfBinaryMatrix (int a[] , int n , int m){
    // 0 1 0 1 1
    // 0 1 1 1 1
    // 1 1 1 1 1
    // 1 1 1 0 0      -> max area from a[i][j]==1 if 8 ;
} 
int main()
{
    cout<<"Hello World"<<endl;
    int a[5] = { 1 , 5 , 10 , 12 , 4};
    cout<<FirstsmallerToLeft(a , 5 , 2)<<endl;
    cout<<FirstsmallerToRight(a ,5 , 2 )<<endl;

    return 0;
}
