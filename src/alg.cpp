// Copyright 2021 DegtyarevPaul
int countPairs1(int *arr, int len, int value) {
int c = 0;
for (int i = 0; i <= len; i++) {
for (int j = 0; j <= len; j++) {
if (*(arr + i) + *(arr+j) == value && i != j)
c++;
}
}
return c / 2;
}

int countPairs2(int *arr, int len, int value) {
int i = 0;
int j = len - 1;
int c = 0;
for (i = 0; i < len; i++) {
for (j = len - 1; j > i; j--) {
if (*(arr+i) + *(arr+j) == value)
c++;
}
}
return c;
}

int countPairs3(int* arr, int len, int value) {
int h = len - 1;
int l = 0;
int mid;
int c = 0;
for (int i = 0; i < len; i++) {
l = i + 1;
h = len - 1;
while (l <= h) {
mid = (l + h) / 2;
if (value == *(arr + mid) + *(arr + i)) {
while (value == *(arr + mid) + *(arr + i) && mid <= h) {
c++;
mid++;
}
mid = (l + h) / 2 - 1;
while (value == *(arr + mid) + *(arr + i) && mid >= l) {
c++;
mid--;
}
break;
} else if (value > *(arr + mid) + *(arr + i)) {
l = mid + 1;
} else if (value < *(arr + mid) + *(arr + i)) {
h = mid - 1;
}
}
}
return c;
}
