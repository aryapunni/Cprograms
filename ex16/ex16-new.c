#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct person
{
  char *name;
  int age;
  int height;
  int weight;
};

void print_struct(struct person *p)
{
  printf("name: %s\n", p->name);
  printf("age: %d\n", p->age);
  printf("height: %d\n", p->height);
  printf("weight: %d\n", p->weight);
}

void person_create(struct person *p, char *name, int age, int height, int weight)
{
  p->name = name;
  p->age = age;
  p->height = height;
  p->weight = weight;
}

void change_age(struct person *p, int new_age)
{
  p->age = new_age;
  print_struct(p);
}

int main(int argc, char *argv[])
{
  struct person joe;
  person_create(&joe, "joe", 29, 149, 58);
  struct person arya;
  person_create(&arya, "arya", 22, 160, 50);
  struct person jyothis;
  person_create(&jyothis, "jyothis", 28, 149, 70);
  printf("updated struct person is: \n");
  change_age(&arya, 29);
  printf("updated struct person is: \n");
  change_age(&jyothis, 35);

  return 5;
}
