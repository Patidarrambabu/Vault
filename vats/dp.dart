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