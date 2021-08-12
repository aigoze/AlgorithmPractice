//
//  DynamicProgramming.cpp
//  algo
//
//  Created by Jiandong Huang on 2021/8/3.
//

#include "DynamicProgramming.hpp"

int helper(std::vector<int>& memo, int n){
    if (n == 1 || n == 2) {
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    memo[n] = helper(memo, n -1) + helper(memo, n -2);
    //std::cout << "memo [" << n << "]: " << memo[n] << std::endl;
    return memo[n];
}

int fib(int N){
    if (N < 1) {
        return 0;
    }
    std::vector<int> memo(N + 1, 0);
    int ret = helper(memo, N);
    return ret;
}

int fib_forward(int N){
    std::vector<int> dp(N+1, 0);
    dp[2] = dp[1] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}

int fib_speed(int N){
    if (N == 1 || N ==2) {
        return 1;
    }
    int prev = 1, curr = 1;
    for (int i =3; i <= N; i ++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

int LengthOfLIS(std::vector<int> &nums){
    std::cout << "length of input seq: " << nums.size() << std::endl;
    //for (int i = 0 ; i < nums.size(); i ++) {
    //    std::cout << "value of nums: " << nums[i] << std::endl;
    //}
    std::vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0 ; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
                //std::cout << dp[i] << std::endl;
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < dp.size(); i ++) {
        res = std::max(res, dp[i]);
    }
    return res;
}



int main(){
    std::cout << "Dynamic Programming test start " << std::endl;
    std::cout << "fib ret " << fib(100) << std::endl;
    
}
