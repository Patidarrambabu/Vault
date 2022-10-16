#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

void printDP(vector<vector<bool>> dp,int n,int W){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
}
//// subset sum problem
void subsetSum(int ar[],int n,int W){
	//// O(N*W)

	// vector<vector<bool>> dp(n+1,vector<bool>(W+1,false));

	// for(int i=0;i<=n;i++)
	// 	dp[i][0] = true;

	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=W;j++){
	// 		if(j>=ar[i-1]){
	// 			dp[i][j] = dp[i-1][j] || dp[i-1][j-ar[i-1]];
	// 		}else
	// 		dp[i][j] = dp[i-1][j];
	// 	}
	// }

	// cout<<dp[n][W];	
	// printDP(dp,n,W);


	//// optimized for space,
	vector<bool> dp(W+1,false);
	dp[0] = true;

	for(int i=0;i<=n;i++){
		for(int j=W;j>=0;j--){
			if(j>=ar[i-1]){
				dp[j] = dp[j] || dp[j-ar[i-1]];
			}else
			dp[j] = dp[j];
		}
	}
	cout<<dp[W]<<endl;
	// for(auto a:dp)
	// 	cout<<a<<" ";
}

vector<vector<int>> dp(2000,vector<int>(2000));

//// recursive subset sum
int recr(int ar[],int n,int W){
	if(W==0)
		return 1;
	if(n<=0)
		return 0;

	if(dp[n][W]!=-1)
		return dp[n][W];

	if(W>=ar[n-1])
		return dp[n][W] = recr(ar,n-1,W) || recr(ar,n-1,W-ar[n-1]);
	else
		return dp[n][W] = recr(ar,n-1,W);
}

/** equal subset sum 
 * 
 * find total sum
 * if odd return false
 * if even
 * 	find subsetsum for W = sum/2
 * 
**/

//// count of subsets with sum W
void countSubsetSum(int ar[],int n,int W){
	int dp[W+1];
	
	dp[0] = 1;
	for(int i=1;i<=W;i++)
		dp[i] = 0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(j>=ar[i-1])
				dp[j] = dp[j] + dp[j-ar[i-1]];
			else dp[j] = dp[j];
		}
	}

	cout<<dp[W]<<endl;
}

////minimum subset sum difference
void subsetSumDiff(int ar[],int n,int W){
    vector<vector<bool>> dp(n+1,vector<bool>(W+1,false));

	for(int i=0;i<=n;i++)
		dp[i][0] = true;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(j>=ar[i-1]){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-ar[i-1]];
			}else
			dp[i][j] = dp[i-1][j];
		}
	}

	int ans = INT_MAX;
	for(int i=0;i<=W/2;i++){
		cout<<dp[n][i]<<" ";
		if(dp[n][i] == true){
			ans = min(ans,W-2*i);
		}
	}
	cout<<endl<<ans<<endl;
}

/** count the no of subset with given difference
 * 	s1-s2 = W
 *  s1+s2 = T
 * 
 * 	count of subset with sum s1 = (W+T)/2
 * 
 **/

/**target sum
 * 
 * same as above problem statment in a different way
 * a1+a2-a3-a4+a5-a6....
 * seperate positive and negative subset 
 * s1 - s2
 * 
**/

//// Unbounded knapsack
void rodCut(){
	int ar[] = {1,2,3,4,5,6,7,8};
	int p[] = {1,5,8,9,10,17,17,20};
	int W = 8;
	int n = 8;
	
	int dp[n+1][W+1];

	for(int i=0;i<=n;i++)
		dp[i][0] = 0;

	for(int i=1;i<=W;i++)
		dp[0][i] = 0;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=W;j++){
			if(j>=ar[i-1])
				dp[i][j] = max(dp[i-1][j],dp[i][j-ar[i-1]]+p[i-1]);
			else
				dp[i][j] = dp[i-1][j];
		 }
	}

	for(int i=0;i<=n;i++){
		for(int j=0;j<=W;j++){
			cout<<dp[i][j]<<" ";
		 }cout<<endl;
	}cout<<endl;

	cout<<dp[n][W];
}
//// coin change
void coinChange(){
	int ar[] = {1,2,3};
	int W  = 5;
	int n = 3;

	// int dp[n+1][W+1];

	// 	for(int i=0;i<=n;i++)
	// 	dp[i][0] = 1;

	// for(int i=1;i<=W;i++)
	// 	dp[0][i] = 0;

	// for(int i=1;i<=n;i++){
	// 	for(int j=0;j<=W;j++){
	// 		 if(j>=ar[i-1]){
	// 			dp[i][j] = dp[i-1][j]+dp[i][j-ar[i-1]];
	// 		}else{
	// 			dp[i][j] = dp[i-1][j];
	// 		}
	// 	}
	// }

	// for(int i = 0;i<=n;i++){
	// 	for(int j=0;j<=W;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}cout<<endl;
	// }


	//space optimiation

	int dp[W+1];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=W;j++){
			 if(j>=ar[i-1]){
				dp[j] = dp[j]+dp[j-ar[i-1]];
			}else{
				dp[j] = dp[j];
			}
		}
	}

		for(int j=0;j<=W;j++){
			cout<<dp[j]<<" ";
		}
}

//// recr code for coin change
int coinChangeRecr(int ar[],int n,int W){
	if(W==0)
		return 1; 
	if(W<0)
		return 0;  

	if(n<=0 && W>0)
		return 0;

	if(dp[n][W]!=-1)
		return dp[n][W];
					  //	   exclude						// include				
	return dp[n][W] = coinChangeRecr(ar,n-1,W) + coinChangeRecr(ar,n,W-ar[n-1]);
}

//// min coins problem
void minCoins(){
	int ar[] = { 1, 2, 3 };
    int n = sizeof(ar) / sizeof(ar[0]);
    int W = 6;

    // int dp[n+1][W+1];

    // for(int i=0;i<=W;i++){
    // 	dp[0][i] = INT_MAX-1;
    // }

    // for(int i=1;i<=n;i++){
    // 	dp[i][0] = 0;
    // }
    
    // for(int i=1;i<=n;i++){
    // 	for(int j=1;j<=W;j++){
    // 		// if(j%ar[i-1]==0){
    // 		// 	dp[i][j] = j%ar[i-1];
    // 		// }else
    // 		 if(j>=ar[i-1]){
    // 			dp[i][j] = min(dp[i-1][j],dp[i][j-ar[i-1]]+1);
    // 		}else{
    // 			dp[i][j] = dp[i-1][j];
    // 		}
    // 	}
    // }

    // for(int i=0;i<=n;i++){
    // 	for(int j=0;j<=W;j++){
    // 		cout<<dp[i][j]<<" ";
    // 	}cout<<endl;
    // }
    int dp[W+1];

    dp[0] = 0;
    for(int i=1;i<=W;i++){
    	dp[i] = INT_MAX-1;
    }
    
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=W;j++){
    		 if(j>=ar[i-1]){
    			dp[j] = min(dp[j],dp[j-ar[i-1]]+1);
    		}else{
    			dp[j] = dp[j];
    		}
    	}
    }

    	for(int j=0;j<=W;j++){
    		cout<<dp[j]<<" ";
    	}cout<<endl;
}

int minCoinsRecr(int ar[],int n,int W){
	if (W<=0)
		return 0;
	if(n<=0)
		return INT_MAX-1;

	if(dp[n][W] != -1)
		return dp[n][W];

	return dp[n][W] = min(minCoinsRecr(ar,n-1,W),minCoinsRecr(ar,n,W-ar[n-1])+1);

	return dp[n][W] = minCoinsRecr(ar,n-1,W);
}

int lCSrecr(string s1,string s2,int i,int j){
	// // bottom up
	// if(i==0 || j==0)
	// 	return 0;

	// if(dp[i][j]!=-1)
	// 	return dp[i][j];

	// if(s1[i-1] == s2[j-1]){
	// 	return dp[i][j] = 1 + lCSrecr(s1,s2,i-1,j-1);
	// }
	// return dp[i][j] = max(lCSrecr(s1,s2,i,j-1),lCSrecr(s1,s2,i-1,j));


	// top-down
	if(i==s1.length() || j ==s2.length())
		return 0;

	if(s1[i] == s2[j])
		return 1+lCSrecr(s1,s2,i+1,j+1);

	return max(lCSrecr(s1,s2,i+1,j),lCSrecr(s1,s2,i,j+1));
}

void lcs(string s1,string s2){
	int dp[s1.length()+1][s2.length()+1];

	for(int i=0;i<=s1.length();i++)
		dp[i][0] = 0;

	for(int i=1;i<=s2.length();i++)
		dp[0][i] = 0;

	for(int i=1;i<=s1.length();i++){
		for(int j=1;j<=s2.length();j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}

	for(int i=0;i<=s1.length();i++){
		for(int j=0;j<=s2.length();j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}

	int i = s1.length(), j = s2.length();
	string s3 = "";
	while(i>0 || j>0){
		if(s1[i-1] == s2[j-1]){
			s3 = s1[i-1]+s3;
			i--;
			j--;
		}else{
			if( dp[i-1][j]>dp[i][j-1] ){
				// s3 = s1[i-1]+s3;   //// to print superseq
				i--;
			}else{
				// s3 = s2[j-1]+s3;  //// to print superseq
				j--;
			}
		}
	}

	cout<<s3<<endl;
}

void lcsub(string s1,string s2){
	int dp[s1.length()+1][s2.length()+1];

	for(int i=0;i<=s1.length();i++)
		dp[i][0] = 0;

	for(int i=1;i<=s2.length();i++)
		dp[0][i] = 0;

	for(int i=1;i<=s1.length();i++){
		for(int j=1;j<=s2.length();j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = 0;
			}
		}
	}

	for(int i=0;i<=s1.length();i++){
		for(int j=0;j<=s2.length();j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
}

/**
 * shortest common supersequence
 *  geek,eke ===> geeke
 * 
 * find length of lcs
 * output = len(s1) + len(s2) - lcsLength
 * 
 **/
	
/**
 * Longest palindromic subsequence
 * 
 * lcs(s1, s1.reverse)
 * 
 **/

//// longest common repeating common subseq
void lcrs(string s1){
	int dp[s1.length()+1][s1.length()+1];

	for(int i=0;i<=s1.length();i++)
		dp[i][0] = 0;

	for(int i=1;i<=s1.length();i++)
		dp[0][i] = 0;

	for(int i=1;i<=s1.length();i++){
		for(int j=1;j<=s1.length();j++){
			if(i!=j && s1[i-1]==s1[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}

	for(int i=0;i<=s1.length();i++){
		for(int j=0;j<=s1.length();j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
}

// int count(vector<int> v,int n,int W){
// 	if(W<=0)
// 		return 0;
// 	if(n<=0)
// 		return INT_MAX - 1;

// 	if(W>=v[n-1])
// 		return min(count(v,n-1,W),count(v,n,W - v[n-1])+1);
// 	return count(v,n-1,W);
// }

// int sqSum(int n){
// 	vector<int> v;
// 	for(int i=1;i*i<=n;i++)
// 		v.push_back(i*i);

// 	return count(v,v.size(),n);
// }

int main(){

int ar[] = {1,2,7};
int n = 3;
int W = 9;

// subsetSum(ar,n,W);
// memset(dp,-1,sizeof(dp));
// recr(ar,n,W);
// countSubsetSum(ar,n,W);

W=0;
for(int i=0;i<n;i++)
	W+=ar[i];
subsetSumDiff(ar,n,W);


// rodCut();
// coinChange();
// int ar[] = { 1, 2, 3 };
// int m = sizeof(ar) / sizeof(ar[0]);

// cout<<coinChangeRecr(ar,m,5);
// minCoins();
// cout<<minCoinsRecr(ar,m,3);

// string s1 = "acbcf";
// string s2 = "abcdaf";

// cout<<lCSrecr(s1,s2,s1.length(),s2.length());
// cout<<lCSrecr(s1,s2,0,0);
// lcs(s1,s2);
// lcsub(s1,s2);
// lcrs("aabebcddn");



	return 0;
}