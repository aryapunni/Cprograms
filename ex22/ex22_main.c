#include "dbg.h"
#include "ex22.h"

const char * MY_NAME = "Arya P Unni";

void scope_demo(int count)
{
  log_info("count is: %d", count);

  if(count > 10)
  {
    int number = 100;

    log_info("count in this scope is: %d", count);
    log_info("number is: %d", number);
  }

  log_info("count is at exit: %d", count);

  count = 3000;

  log_info("count after assign: %d", count);
}

int main(int argc, char *argv[])
{
  //Test out THE_AGE accessors
  struct State state_new;

  state_new.age = 30;
  state_new.size = 1000;
  log_info("My name: %s, age: %d", MY_NAME, get_age(&state_new));

  set_age(100, &state_new);

  log_info("My age is now: %d", get_age(&state_new));

  //Test out THE_SIZE extern
  log_info("THE_SIZE is: %d", state_new.size);
  print_size(&state_new);

  set_size(9, &state_new);

  log_info("THE_SIZE is now: %d", state_new.size);

  //Test the update_ratio function statistics
  log_info("ratio at first: %f", update_ratio(2.0));
  log_info("ratio again: %f", update_ratio(10.0));
  log_info("ratio once more: %f", update_ratio(300.0));

  //test the scope demo
  int count = 4;
  scope_demo(count);
  scope_demo(count*20);
  log_info("count after calling scope_demo: %d", count);
  return 0;
}
