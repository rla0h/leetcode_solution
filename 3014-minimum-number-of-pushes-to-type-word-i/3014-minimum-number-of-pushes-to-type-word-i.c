#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b)
{
  int x = *(int*)a;
  int y = *(int*)b;

  if (x > y) return -1;
  if (x < y) return 1;
  return 0;
}
int minimumPushes(char* word) 
{
  int words[26] = {0};

  for (int i = 0; word[i] != '\0'; i++)
  {
    words[word[i] - 'a']++;
  }

  int arr[26];
  int size = 0;
  for (int i = 0; i < 26; i++)
  {
    if (words[i] > 0)
    {
      arr[size++] = words[i];
    }
  }

  qsort(arr, size, sizeof(int), compare);

  int result = 0;
  
  for (int i = 0; i < size; i++)
  {
    int press = (i / 8) + 1;
    result += arr[i] * press;
  }

  return result;
}