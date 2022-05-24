#include<bits/stdc++.h>
using namespace std;
 struct fenwick
{
  vector<int>fn;
  int n;
  fenwick(){}
  fenwick(int n){
   init(n); 
    }
   void init(int _n){
   n=_n+10;
   fn.clear();
   fn.resize(n,0);
}
  void add(int x,int val){
   x++;
   while(x<n){
      fn[x]+=val;
      x +=x & (-x);
   }
  }
  int sum(int x){
    x++;int sum=0;
   while(x){
     sum+=fn[x];
     x-=x&(-x);
   }
   return sum;
  }
  int sum(int l,int r){
   return sum(r)-sum(l-1);
  }
};
int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    int t;
    cin>>t;
    while(t--){
   int n;
   cin>>n;
   pair<int,int> a[n];
   for(int i=0;i<n;i++){
      cin>>a[i].first;
      a[i].second=i;
   }
   sort(a,a+n);
   fenwick tree(n);
   int inv_cnt=0;
   for(int i=0;i<n;i++){
      int idx=a[i].second;
      inv_cnt+=tree.sum(idx+1,n-1);
      tree.add(idx,1);
   }
    cout<<inv_cnt<<endl;
 }
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
