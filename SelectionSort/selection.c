#include <stdio.h>

// prints in this format: {1, 2, 3, 4}
void print_int_array(int *list, int n) {

  int i = 0;
  printf("{");
  for (i = 0; i < n; i++) {

    if (i == n - 1) {
      printf("%d}\n", list[i]);
    }

    else {
      printf("%d, ", list[i]);
    }
  }
}

// bubble sorts an array by reference
void selection(int *list, int n) {

  print_int_array(list, n);
  int i = 0;
  for (i = 0; i < n; i++) {

    int min = list[i];
    int j = i;
    int index = -1;
    for (j = i; j < n; j++) {

      if (list[j] < min) {
	min = list[j];
	index = j;
      }
    }

    // this means the original min was not the actual min
    if (index != -1) {
      int temp = list[i];
      list[i] = list[index];
      list[index] = temp;
    }
    
    print_int_array(list, n);
  }
}

int main() {

  printf("Test 1: Completely Reversed Array\n");
  int n = 5;
  int list[] = {5, 4, 3, 2, 1};
  selection(list, n);
  
  printf("\nTest 2: Array Already Sorted\n");
  int list1[] = {1, 2, 3, 4, 5};
  selection(list1, n);

  printf("\nTest 3: Arbritrary Order\n");
  int list2[] = {4, 3, 2, 1, 5};
  selection(list2, n);

  printf("\nTest 4: Array Containing Repeats\n");
  int list3[] = {4, 5, 3, 3, 4};
  selection(list3, n);
  
  printf("\nTest 5: Array of All the Same Numbers\n");
  int list4[] = {1, 1, 1, 1, 1};
  selection(list4, n);

  printf("\nTest 6: Contains Negative Numbers\n");
  int list5[] = {-1, -2, 3, -4, -5};
  selection(list5, n);
  return 0;
}
