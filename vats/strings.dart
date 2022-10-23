bool stringCompare(String string, String subString) {
  if (subString.isEmpty) {
    return false;
  }

  List<int> pattern =
      new List<int>.generate(subString.length, (int index) => -1);

  int i = 1;
  int j = 0;

  while (i < subString.length) {
    if (subString[i] == subString[j]) {
      pattern[i] = j;
      i++;
      j++;
    } else if (j > 0) {
      j = pattern[j - 1] + 1;
    } else {
      i++;
    }
  }

  return stringCompareHelper(string, subString, pattern);
}

bool stringCompareHelper(String string, String subString, List<int> pattern) {
  int i = 0;
  int j = 0;

  while (i + subString.length - j <= string.length) {
    if (string[i] == subString[j]) {
      if (j == subString.length - 1) {
        return true;
      }
      i++;
      j++;
    } else if (j > 0) {
      j = pattern[j - 1] + 1;
    } else {
      i++;
    }
  }
  return false;
}


String removeDups(String s) {
  var arr = new List.filled(256, 0);
  String l = '';
  int i = 0;
  for (i = 0; i < s.length; i++) {
    if (arr[s.codeUnitAt(i)] == 0) {
      l += s[i];
      arr[s.codeUnitAt(i)]++;
    }
  }
  return l;
}

String reverseStringWords(String s) {
  String res = "";
  int m = s.length;
  int j = m - 1;
  for (int i = m - 1; i >= 0; i--) {
    if (s[i] == '.') {
      for (int j1 = i + 1; j1 <= j; j1++) {
        res += s[j1];
      }
      res += s[i];
      j = i - 1;
    } else if (i == 0) {
      for (int j1 = i; j1 <= j; j1++) {
        res += s[j1];
      }
    }
  }
  return res;
}

String reverseString(String str) {
  return str.split('').reversed.join();
}

/**
 * Second way to reverses the string
 */
String reverseString2(String str) {
  String reversed = "";
  for (int i = str.length - 1; i >= 0; i--) reversed += str[i];
  return reversed;
}