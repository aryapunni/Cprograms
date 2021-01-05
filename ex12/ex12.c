#include <stdio.h>

int main(int argc, char *argv[])
{
  int areas[] = {10, 12, 13, 14, 20};
  // char name[] = "Arya";
  char name[10] = "Arya";
  printf("name[]:");
  for(int i = 0;i < 10; i++)
  {
    printf("%d\n", name[i]);
  }
  printf("\n");
  char full_name[] = {'A', 'r', 'y', 'a',
                      ' ', 'P', ' ',
                    'U', 'n', 'n', 'i', '\0'};

  printf("The size of double: %ld\n", sizeof(double));
  printf("The size of float: %ld\n", sizeof(float));
  printf("The size of short int: %ld\n", sizeof(short));
  printf("The size of long: %ld\n", sizeof(long));

  printf("The size of an int: %ld\n", sizeof(int));
  printf("The size of areas (int[]): %ld\n", sizeof(areas));
  printf("The number of ints in areas: %ld\n", sizeof(areas)/sizeof(int));
  printf("The first area is %d, 2nd %d. \n", areas[0], areas[1]);

  printf("The sizeof char: %ld\n", sizeof(char));
  printf("The size of name (char[]): %ld\n", sizeof(name));
  printf("The number of chars in name: %ld\n", sizeof(name)/sizeof(char));

  printf("The size of full name (char[]): %ld\n", sizeof(full_name));
  printf("The number of chars in full name: %ld\n", sizeof(full_name)/sizeof(char));
  printf("name = \"%s\" and full name = \"%s\"\n", name, full_name);

  return 0;
}
