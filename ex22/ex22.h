#ifndef _ex22_h
#define _ex22_h

//Makes THE_SIZE in ex22.c available to other .c files

struct  State{
  int size;
  int age;
};


int get_size();
void set_size(int size, struct State *state);

//gets and sets an internal static variable in ex22.c

int get_age();
void set_age(int age, struct State *state);

//updates a static variable that's inside update ratio
double update_ratio(double new_ratio);

void print_size();

#endif
