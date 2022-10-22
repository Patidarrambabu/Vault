#include<bits/stdc++.h>
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

	//space optimiation

	int dp[W+1] = {0};
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

	return dp[n][W] = minCoinsRecr(arn,n-1,W);
}

int lCSrecr(string s1,string s2,int i,int j){

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

int mcm(int ar[],int i,int j){
		if(i>=j)
		return 0;

	int ans = INT_MAX;
	for(int k = i;k<j;k++){
		int temp = mcm(ar,i,k) + mcm(ar,k+1,j) + ar[i-1]*ar[k]*ar[j];
		ans = min(ans,temp);
	}
	return ans;
}

int dp[200][200];

int mcmRecr(int ar[],int i,int j){

	if(i>=j)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int ans = INT_MAX;
	for(int k = i;k<j;k++){
		int temp = mcm(ar,i,k) + mcm(ar,k+1,j) + ar[i-1]*ar[k]*ar[j];
		ans = min(ans,temp);
	}
	return dp[i][j] = ans;
}

bool isPalindrome(string s,int i,int j){
	while(j>i){
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}

	return true;
}

//// palindrome partition
int pal(string s,int i,int j){
	if(i>=j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	if(isPalindrome(s,i,j) == true)
		return 0;

	int ans = INT_MAX;
	for(int k=i;k<j;k++){
		int temp = pal(s,i,k) + pal(s,k+1,j) + 1;
		ans = min(temp,ans);
	}

	return dp[i][j] = ans;
}

int boolpar(string s,int i,int j ,bool isTrue){
	if(i>j)
		return 0;
	if(i==j){
		if(isTrue == true)
			return s[i]=='T'?1:0;
		else
			return s[i]=='F'?1:0;
	}

	int ans = 0;
	for(int k=i+1;k<j;k=k+2){
		int lt = boolpar(s,i,k-1,true);
		int lf = boolpar(s,i,k-1,false);
		int rt = boolpar(s,k+1,j,true);
		int rf = boolpar(s,k+1,j,false);

		if(s[k]=='&'){
			if(isTrue == true)
				ans+=lt*rt;
			else
				ans+=lf*rt + lt*rf + lf*rf;
		}

		else if(s[k]=='|'){
			if(isTrue == true)
				ans+=lt*rt +lf*rt + lt*rf;
			else
				ans+= lf*rf;
		}else{
			if(isTrue == true)
				ans+= lf*rt + lt*rf;
			else
				ans+= lf*rf + lt*rt;
		}

	}

    return ans;
}

map<string,bool> mp;

bool scram(string a,string b){
	if(a.compare(b) == 0)
		return true;

	if(a.length()<=1)
		return false;

	string key = a + " " + b;
	if(mp.find(key) != mp.end())
		return mp[key];

	int n = a.length();
	bool flag = false;


	for(int i=1;i<n;i++){
		if(
			(	scram(a.substr(0,i),b.substr(n-i,i)) == true 
				&&
		   		scram(a.substr(i,n-i),b.substr(0,i)) == true	
			) || (
			    scram(a.substr(0,i),b.substr(0,i)) == true
			    &&
			    scram(a.substr(i,n-i),b.substr(i,n-i)) == true)
		){
			flag = true;
			break;
		}
	}

	return mp[key] = flag;
}


int eggDrop(int e,int f){
	if(f==0 || f==1)
		 return f;
	if(e==1)
		return f;

	if(dp[e][f] != -1)
		return dp[e][f];

	int mn = INT_MAX,l,h;
	for(int k=1;k<=f;k++){

    if(dp[e-1][k-1]!=-1)
    	return dp[e-1][k-1];
    else
    	 l = dp[e-1][k-1] = eggDrop(e-1,k-1);

    if(dp[e][f-k]!=-1)
    	return dp[e][f-k];
    else
    	 h = dp[e][f-k] = eggDrop(e,f-k);


		mn = min(mn ,  1 + max(l,h) );
	}

	return dp[e][f] = mn;
}


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
 return 0;
}