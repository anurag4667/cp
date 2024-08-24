#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    /*
    to use queries use 
    //node,start,end,range_start,range_end
    --> queryxxx(1,0,arr.size()-1,l,r)
    
    to use update
    //node,start,end,point,point,val
    --> update(1,0,arr.size()-1,p,p,val)
    //dont use this function for range update
    */

    public:
    int n;
    vector<int> treemax,treemin,treesum;
    
    vector<int> arr;
    SegmentTree(vector<int> arr){
        this->arr = arr;
        n = arr.size();
        treemax.resize(4*n);
        treemin.resize(4*n);
        treesum.resize(4*n);
        build(1,0,n-1);
    }

    //build tree
    void build(int ind,int s,int e){
        if(s == e){
            treemax[ind] = arr[s];
            treemin[ind] = arr[s];
            treesum[ind] = arr[s];
        }        
        else{
            int mid = (s+e)/2;
            int left = ind*2;
            int right = ind*2 + 1;
            build(left,s,mid);
            build(right,mid+1,e);
            treemin[ind] = min(treemin[left],treemin[right]);
            treemax[ind] = max(treemax[left],treemax[right]);
            treesum[ind] = treesum[left] + treesum[right];
        } 
    }

    //min range query
    int querymin(int node,int s,int e,int l,int r){
        if(e < l || s > r) return INT_MAX;
        
        if(s == e) return treemin[node];
        else if(l <= s && e <= r){
            return treemin[node];
        }
        else {
            int mid = (s+e )/2;
            int left = querymin(node*2,s,mid,l,r);
            int right = querymin(node*2+ 1,mid+1,e,l,r);
            
            return min(left,right);
        }
    }

    //max range query
    int querymax(int node,int s,int e,int l,int r){
        if(e < l || s > r) return INT_MIN;
        
        if(s == e) return treemax[node];
        else if(l <= s && e <= r){
            return treemax[node];
        }
        else {
            int mid = (s+e )/2;
            int left = querymax(node*2,s,mid,l,r);
            int right = querymax(node*2+ 1,mid+1,e,l,r);
            
            return max(left,right);
        }
    }

    //sum range query
    int querysum(int node,int s,int e,int l,int r){
        if(e < l || s > r) return 0;
        
        if(s == e) return treesum[node];
        else if(l <= s && e <= r){
            return treesum[node];
        }
        else {
            int mid = (s+e )/2;
            int left = querysum(node*2,s,mid,l,r);
            int right = querysum(node*2+ 1,mid+1,e,l,r);
            
            return left + right;
        }
    }

    //range update array query
    void update(int node,int s,int e,int l,int r,int val){
        
        if(e < l || s > r) return ;
        
        if(s == e){
            arr[s] = val;
            treemin[node] = val;
            treemax[node] = val;
            treesum[node] = val;
            return ;
        }
        else {
            int mid = (s+e )/2;
            update(node*2,s,mid,l,r,val);
            update(node*2+ 1,mid+1,e,l,r,val);
            treemin[node] = min(treemin[node*2],treemin[node*2+ 1]);
            treemax[node] = max(treemax[node*2],treemax[node*2+ 1]);
            treesum[node] = treesum[node*2] + treesum[node*2 + 1];
        }
    }
};

int main()
{
    vector<int> arr = {3,2,67,4,2,10,45,22};
    SegmentTree st(arr);
    st.update(1,0,arr.size()-1,1,1,89);
    cout << st.querysum(1,0,arr.size()-1,2,4);
}
