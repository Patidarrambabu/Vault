int minNumberOfCoins(int targetAmount, List<int> coinDenoms) {
  List<int> amounts =
      new List<int>.generate(targetAmount + 1, (int index) => 1000000000000);

  amounts[0] = 0;

  for (int currentCoin in coinDenoms) {
    for (int amount = currentCoin; amount <= targetAmount; amount++) {
      amounts[amount] = min(amounts[amount], amounts[amount - currentCoin] + 1);
    }
  }
  if (amounts[targetAmount] != 1000000000000) {
    return amounts[targetAmount];
  }
  return -1;
}

int kadanesAlgorithm(List<int> array) {
  int maxEndingHere = array[0];
  int maxSoFar = array[0];

  for (int num in array.sublist(1, array.length)) {
    maxEndingHere = max(maxEndingHere + num, num);
    maxSoFar = max(maxSoFar, maxEndingHere);
  }
  return maxSoFar;
}

int longestCommonSubsequence(String text1, String text2) {
  int m = text1.length;
  int n = text2.length;

  // BottomUp Tabulation
  List<List<int>> dp = List.generate(m + 1, (_) => List<int>.filled(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (text1[i - 1] == text2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        continue;
      }
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[m][n];
}

int minimumNumberOfJumps(List<int> array) {
  List<int> jumps = List.generate((array.length), (index) => 1000000000000);
  jumps[0] = 0;
  int length = array.length;
  for (int i = 1; i < length; i++) {
    for (int j = 0; j < i; j++) {
      if (array[j] + j >= i) {
        jumps[i] = min(jumps[j] + 1, jumps[i]);
      }
    }
  }
  return jumps[length - 1];
}

