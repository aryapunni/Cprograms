#include <stdio.h>

int main(int argc, char *argv[])
{
  int ages[] = {23, 43, 12, 82, 2};
  char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

  printf("names: %p, *names: %p\n", names, *names);

  int count = sizeof(ages)/sizeof(int);
  int i = 0;

  for(i = 0; i < count; i++)
  {
    printf("%s has %d years alive. \n", names[i], ages[i]);
  }

  printf("-------------------------\n");

  int *cur_age = ages;
  char **cur_name = names;

  for(i = 0; i < count; i++)
  {
    printf("%s is %d years old. \n", *(cur_name + i), *(cur_age + i));
  }

  printf("-------------------------\n");

  for(i = 0; i < count; i++)
  {
    printf("%s is %d years old. \n", cur_name[i], cur_age[i]);
  }

  printf("-------------------------\n");

  for(cur_age = ages, cur_name = names; (cur_age - ages) < count; cur_age++, cur_name++)
  {
    printf("%s lives %d years so far\n", *cur_name, *cur_age);
  }

  return 0;
}
