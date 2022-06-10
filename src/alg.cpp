// Copyright 2021 DegtyarevPaul
int countPairs1(int* arr, int len, int value) {
  int c = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (arr[i] + arr[j] == value && i !=j)
        c++;
    }
  }
  return c / 2;
}

int countPairs2(int* arr, int len, int value) {
  int i = 0;
  int j = len - 1;
  int c = 0;
  for (i = 0; i < len; i++) {
    for (j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value)
        c++;
    }
  }
  return c;
}

int countPairs3(int* arr, int len, int value) {
  int c = 0;
  for (int i = 0; i < len - 1; i++) {
    int l = i;
    int h = len;
    while (l < h - 1) {
      int mid = (l + h) / 2;
      if (arr[i] + arr[mid] == value) {
        c++;
        int j = mid + 1;
        while (arr[i] + arr[j] == value && j < h) {
          c++;
          j++;
        }
        j = mid - 1;
        while (arr[i] + arr[j] == value && j > l) {
          c++;
          j--;
        }
        break;
      }
      if (arr[i] + arr[mid] < value) l = mid;
      if (arr[i] + arr[mid] > value) h = mid;
    }
  }
  return c;
}
