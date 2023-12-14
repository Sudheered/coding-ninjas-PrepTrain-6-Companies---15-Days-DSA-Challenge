
//First non repeating character
#include <bits/stdc++.h> 
char firstNonRepeatingCharacter(string str) {

  // Write your code here
  map<char,int>m;
  for(auto it:str){
    m[it]++;
  }
  for(int i=0;i<str.size();i++){
    if(m[str[i]]==1)return str[i];
  }
  return str[0];
}




//Majority element

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int maxi=INT_MIN;
	int curr=0;
	int pre=INT_MIN;
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		if(pre==arr[i]){
			curr++;
		}
		else{
			curr=1;
			pre=arr[i];
		}
		if(curr>maxi){
			ans=arr[i];
			maxi=curr;
		}
	}
	curr=0;
	for(int i=0;i<n;i++){
		if(arr[i]==ans)curr++;
	}
	if(curr>(n/2))return ans;
	return -1;
}




// Maximum subarray

#include <bits/stdc++.h> 
vector<int> maximumsumSubarray(vector<int> &arr , int n)
{
    //Write your code here
    int curr=0;
    int mini=INT_MAX;
    int ans=INT_MIN;
    int s=0;
    int ps=-1;
    int pe=-1;
    for(int i=0;i<arr.size();i++){
        curr+=arr[i];
        if(curr>=ans){
            ans=curr;
            ps=0;
            pe=i+1;
        }
        if(mini!=INT_MAX&&curr-mini>=ans){
            if(curr-mini==ans){
                if(pe-ps<i+1-s){
                    ps=s;
                    pe=i+1;
                }
            }
            else{
                ans=curr-mini;
                ps=s;
                pe=i+1;
            }
        }
        if(mini>curr){
            mini=curr;
            s=i+1;
        }
    }
    vector<int> res;
    for(int i=ps;i<pe;i++)res.push_back(arr[i]);
    return res;
}




// Merge Two Sorted Linked Lists

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* ans=new Node<int>(-1);
    Node<int>* temp=ans;
    while(first!=NULL&&second!=NULL){
        if(first->data>second->data){
            temp->next=second;
            second=second->next;
            temp=temp->next;
            temp->next=NULL;
        }
        else{
            temp->next=first;
            first=first->next;
            temp=temp->next;
            temp->next=NULL;
        }
    }
    if(first)temp->next=first;
    if(second)temp->next=second;
    return ans->next;
}




// Next Greater Element

#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top()<=arr[i])st.pop();
        int curr=arr[i];
        arr[i]=-1;
        if(st.size())arr[i]=st.top();
        st.push(curr);
    }
    return arr;
}



// Longest Palindromic Substring


bool ispal(vector<vector<int>>& dp,int l,int r,string& str){
    if(l>=r)return true;
    if(dp[l][r]!=-1)return dp[l][r];
    if(str[l]==str[r]&&ispal(dp,l+1,r-1,str)){
        dp[l][r]=1;
        return true;
    }
    dp[l][r]=0;
    return false;
}

string longestPalinSubstring(string str) {
    // Write your code here.
    int n=str.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int l=0;
    int r=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(ispal(dp,i,j,str)&&j-i>r-l){
                l=i;
                r=j;
            }
        }
    }
    return str.substr(l,r+1-l);
}



//Reverse Linked List

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *pre=NULL;
    LinkedListNode<int> *curr=head;
    LinkedListNode<int> *nxt;
    while(curr){
        nxt=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nxt;
    }
    return pre;
}



// Minimum Cost to Destination

#include <queue>
#include <limits.h>
int row[4]={-1,0,0,1};
int col[4]={0,-1,1,0};
int help(vector<vector<int>>& dp,int ** matrix,int n,int m,int tx,int ty,int i,int j){
    if(i<0||i>=n||j<0||j>=m)return INT_MAX;
    if(i==tx&&j==ty)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    else if(matrix[i][j]==0)return INT_MAX;
    matrix[i][j]=0;
    int ans=INT_MAX;
    for(int p=0;p<4;p++){
        int ci=i+row[p];
        int cj=j+col[p];
        int pro=0;
        if(row[p]!=0)pro++;
        int curr=help(dp,matrix,n,m,tx,ty,ci,cj);
        if(curr!=INT_MAX)ans=min(ans,curr+pro);
    }
    return dp[i][j]=ans;
}
int minCostToDestination(int **matrix, int n, int m, int tx, int ty)
{
    //  Write your code here
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans=help(dp,matrix,n,m,tx,ty,0,0);
    if(ans==INT_MAX)return -1;
    return ans;
}



// Maximum Size Rectangle Sub-matrix With All 1's

#include<stack>
int help(vector<int>& heights) {
        vector<int> ls(heights.size());
        int n=heights.size();
        vector<int> rs(heights.size());
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top().first>=heights[i])st.pop();
            if(st.empty())ls[i]=0;
            else{
                ls[i]=st.top().second+1;
            }
            st.push({heights[i],i});
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top().first>=heights[i])st.pop();
            if(st.empty())rs[i]=n-1;
            else{
                rs[i]=st.top().second-1;
            }
            st.push({heights[i],i});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int curr=rs[i]-ls[i]+1;
            curr*=heights[i];
            ans=max(ans,curr);
        }
        return ans;
    }
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
	vector<int> heights(m);
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mat[i][j])heights[j]++;
			else heights[j]=0;
		}
		ans=max(ans,help(heights));
	}
	return ans;
}



// Reverse Words In A String

#include <stack>
string reverseString(string &str){
	// Write your code here.
	stack<string>st;
	string curr="";
	for(auto it:str){
		if(it!=' '){
			curr.push_back(it);
		}
		else{
			if(curr!=""){
				st.push(curr);
				curr="";
			}
		}
	}
	if(curr!="")st.push(curr);
	string ans="";
	bool fir=true;
	while(!st.empty()){
		if(fir){
			fir=false;
		}
		else ans+=" ";
		ans+=st.top();
		st.pop();
	}
	return ans;
}



// Time complexity




// Maximum Subarray Sum

long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long maxi=INT_MIN;
    long long curr=0;
    for(int i=0;i<arr.size();i++){
        curr+=arr[i];
        if(curr<0)curr=0;
        if(curr>maxi)maxi=curr;
    }
    return maxi;
}



 //Best Time to Buy and Sell Stock

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int cp=prices[0];
    int profit=0;
    for(int i=1;i<prices.size();i++){
        profit=max(profit,prices[i]-cp);
        cp=min(cp,prices[i]);
    }
    return profit;
}



// Shortest path in an unweighted graph

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	queue<int>q;
	vector<int>par(n+1,-1);
	vector<int>vis(n+1,0);
	vector<vector<int>>adj(n+1);
	for(auto it:edges){
		adj[it.first].push_back(it.second);
		adj[it.second].push_back(it.first);
	}
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto it:adj[node]){
			if(!vis[it]){
				vis[it]=1;
				q.push(it);
				par[it]=node;
			}
		}
	}
	vector<int> ans;
	int curr=t;
	while(curr!=-1){
		ans.push_back(curr);
		curr=par[curr];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}




// Detect and Remove Loop

Node *removeLoop(Node *head)
{
    // Write your code here.
    Node* ans=head;
    Node* fast=head;
    Node* slow=head;
    do{
        if(fast==NULL||fast->next->next==NULL)return head;
        fast=fast->next->next;
        slow=slow->next;
    }while(fast!=slow);
    int k=0;
    do{
        k++;
        fast=fast->next;
    }while(fast!=slow);
    fast=head;
    slow=head;
    for(int i=0;i<k;i++){
        fast=fast->next;
    }
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    while(slow->next!=fast)slow=slow->next;
    slow->next=NULL;
    return head;
}

// The Celebrity Problem

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int>st;
	for(int i=0;i<n;i++){
		st.push(i);
	}
	int curr=-1;
	while(true){
		int a=st.top();
		st.pop();
		if(st.empty()){
			curr=a;
			break;
		}
		int b=st.top();
		st.pop();
		if(knows(a,b)){
			st.push(b);
		}
		else{
			st.push(a);
		}
	}
	for(int i=0;i<n;i++){
		if(i!=curr&&(knows(curr,i)||!knows(i,curr))){
			return -1;
		}
	}
	return curr;
}



// Boundary Traversal of Binary Tree

bool left(TreeNode<int>*root){
    if(!root->left&&!root->right)return true;
    return false;
}
void getleft(vector<int>& res,TreeNode<int>* root){
    TreeNode<int>* temp=root->left;
    while(temp&&!left(temp)){
        res.push_back(temp->data);
        if(temp->left)temp=temp->left;
        else temp=temp->right;
    }
}
void getright(vector<int>& res,TreeNode<int>* root){
    vector<int> pro;
    TreeNode<int>*temp=root->right;
    while(temp&&!left(temp)){
        pro.push_back(temp->data);
        if(temp->right)temp=temp->right;
        else temp=temp->left;
    }
    for(int i=pro.size()-1;i>=0;i--){
        res.push_back(pro[i]);
    }
}
void getbot(vector<int>& res,TreeNode<int>* root){
    if(!root)return ;
    if(left(root)){
        res.push_back(root->data);
    }
    getbot(res,root->left);
    getbot(res,root->right);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> res;
    if(!root)return res;
    res.push_back(root->data);
    getleft(res,root);
    getbot(res,root);
    getright(res,root);
    return res;
}




// Maximum of minimum for every window size

#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<pair<int,int>> st;
    vector<int> l(n,0);
    vector<int> r(n,n);
    for(int i=0;i<n;i++){
        while(!st.empty()&&st.top().first>=a[i])st.pop();
        if(!st.empty())l[i]=st.top().second+1;
        st.push({a[i],i});
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&st.top().first>=a[i])st.pop();
        if(!st.empty())r[i]=st.top().second;
        st.push({a[i],i});
    }
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++){
        int size=r[i]-l[i]-1;
        ans[size]=max(ans[size],a[i]);
    }
    int maxi=ans[n-1];
    for(int i=n-2;i>=0;i--){
        ans[i]=max(maxi,ans[i]);
        maxi=max(ans[i],maxi);
    }
    return ans;
}



// Valid Parentheses

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char>st;
    for(auto it:s){
        if(it=='{'||it=='('||it=='[')st.push(it);
        else {
          if (it == '}'){
              if(!st.empty()&&st.top()=='{')st.pop();
              else return false;
          }
          else if(it==')'){
              if(!st.empty()&&st.top()=='(')st.pop();
              else return false;
          }
          else if(it==']'){
              if(!st.empty()&&st.top()=='[')st.pop();
              else return false;
          }
        }
    }
    if(st.empty())return true;
    return false;
}



// Check Identical Trees

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    if(!root1&&!root2)return true;
    if(!root1||!root2)return false;
    if(root1->data!=root2->data)return false;
    if(identicalTrees(root1->left,root2->left)&&identicalTrees(root1->right,root2->right)){
        return true;
    }
    return false;
}



//Maximum In Sliding Windows Of Size K

#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    priority_queue<pair<int,int>>q;
    for(int i=0;i<k-1;i++){
        q.push({nums[i],i});
    }
    vector<int> ans;
    for(int i=k-1;i<nums.size();i++){
        q.push({nums[i],i});
        while(q.top().second<=i-k)q.pop();
        ans.push_back(q.top().first);
    }
    return ans;
}



// Delete Kth Node From End

int size(Node* head){
    Node* temp=head;
    int siz=0;
    while(temp){
        temp=temp->next;
        siz++;
    }
    return siz;
}
Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int s=size(head);
    int curr=s-K;
    Node* dummy=new Node(-1);
    dummy->next=head;
    Node* temp=dummy;
    while(curr--){
        temp=temp->next;
    }
    Node* del=temp->next;
    temp->next=temp->next->next;
    delete(del);
    return dummy->next;
}


 //Longest Consecutive Sequence

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int curr=1;
    int maxi=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]||arr[i]==arr[i-1]+1){
           if(arr[i]==arr[i-1]+1) curr++;
        }
        else curr=1;
        maxi=max(maxi,curr);
    }
    return maxi;
}



// Merge Intervals

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/   
bool sortcol1(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] > v2[1];
}
bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end(),sortcol1);
    sort(arr.begin(),arr.end(),sortcol);
    int a=arr[0][0];
    int b=arr[0][1];
    vector<vector<int>>ans;
    for(int i=1;i<arr.size();i++){
        int ca=arr[i][0];
        int cb=arr[i][1];
        if(ca<=b){
            a=min(ca,a);
            b=max(cb,b);
        }
        else{
            ans.push_back({a,b});
            a=ca;
            b=cb;
        }
    }
    ans.push_back({a,b});
    return ans;
}




// Longest Increasing Path In A 2D Matrix

#include <bits/stdc++.h> 
int row[4]={-1,0,0,1};
int col[4]={0,-1,1,0};
int help(vector<vector<int>>& dp,vector<vector<int>>& mat,int n,int m,int i,int j){
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    for(int p=0;p<4;p++){
        int cr=row[p]+i;
        int cc=col[p]+j;
        if(cr>=0&&cc>=0&&cr<n&&cc<m&&mat[cr][cc]>mat[i][j]){
            ans=max(ans,help(dp,mat,n,m,cr,cc));
        }
    }
    return dp[i][j]=ans+1;
}
int longestIncreasingPath(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    vector<vector<int>> dp(n,vector<int> (m,-1));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,help(dp,mat,n,m,i,j));
        }
    }
    return ans;
}



// Intersection of Two Linked Lists

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int fl=0;
    int sl=0;
    Node* temp=firstHead;
    while(temp){
        temp=temp->next;
        fl++;
    }
    temp=secondHead;
    while(temp){
        temp=temp->next;
        sl++;
    }
    temp=firstHead;
    Node* temp2=secondHead;
    if(fl>sl){
        fl-=sl;
        while(fl--)temp=temp->next;
    }
    else{
        sl-=fl;
        while(sl--){
            temp2=temp2->next;
        }
    }
    while(temp&&temp2&&temp!=temp2){
        temp=temp->next;
        temp2=temp2->next;
    }
    if(temp==temp2)return temp;
    return NULL;
}




// Level Order Traversal


#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    vector<int> ans;
    if(!root)return ans;
    while(!q.empty()){
        BinaryTreeNode<int> *node=q.front();
        q.pop();
        ans.push_back(node->val);
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
    return ans;
}



// Anagram Pairs


#include<map>
bool isAnagram(string str1, string str2)
{
    //Write your code here
    map<char,int> m1;
    map<char,int> m2;
    for(auto it:str1)m1[it]++;
    for(auto it:str2)m2[it]++;
    if(m1==m2)return true;
    return false;
}



// Right View

vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    vector<int> ans;
    if(!root)return ans;
    while(!q.empty()){
        int size=q.size();
        int curr=-1;
        while (size--) {
          BinaryTreeNode<int> *node = q.front();
          q.pop();
          curr=node->data;
          if (node->left)
            q.push(node->left);
          if (node->right)
            q.push(node->right);
        }
        ans.push_back(curr);
    }
    return ans;
}
