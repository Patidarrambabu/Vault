List<int> sortedSquaredArray(List<int> array) {
  int start = 0;
  int end = array.length - 1;
  int sortedIndex = array.length - 1;
  List<int> answer = List.filled(array.length, 0);

  while (end >= start) {
    if (array[start].abs() > array[end].abs()) {
      answer[sortedIndex] = array[start] * array[start];
      start += 1;
    } else {
      answer[sortedIndex] = array[end] * array[end];
      end -= 1;
    }
    sortedIndex -= 1;
  }

  return answer;
}

bool twoSum(List<int> nums, int target) {
  Map<int, int> seen = {};
  for (int index = 0; index < nums.length; ++index) {
    int number = nums[index];

    int complement = target - number;
    if (seen.containsKey(complement)) {
      return true;
    } else {
      seen[number] = index;
    }
  }
  return false;
}

bool checkIsSubSequence(List<int> array, List<int> sequence) {
  if (array.isEmpty) {
    return false;
  }

  if (sequence.isEmpty) {
    return true;
  }
  int arrayIndex = 0;
  int sequenceIndex = 0;

  while (sequenceIndex < sequence.length && arrayIndex < array.length) {
    if (sequence[sequenceIndex] == array[arrayIndex]) {
      sequenceIndex += 1;
    }
    arrayIndex += 1;
  }
  return sequenceIndex == sequence.length;
}