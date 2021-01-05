#include <stdio.h>
#include "dbg.h"
#include "ex22.h"

int get_size(struct State *state)
{
  return state->size;
}

void set_size(int size, struct State *state)
{
  state->size = size;
}

int get_age(struct State * state)
{
  return state->age;
}

void set_age(int age, struct State *state)
{
  state->age = age;
}

double update_ratio(double new_ratio)
{
  static double ratio = 1.0;

  double old_ratio = ratio;
  ratio = new_ratio;

  return old_ratio;
}

void print_size(struct State * state)
{
  log_info("I think the size is %d", state->size);
}
