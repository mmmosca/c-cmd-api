#include "cmd-api.h"


void test_longopt_missedarg_error()
{
	char* arr[] = {"exe", "-opt1", "-opt2", "val2"};
	optarg_t* optarg;
  
	while ((optarg = getoptW(4, arr, "opt1:|opt2:|")) != NULL);
}

int main()
{
  test_longopt_missedarg_error();
  return 0;
}
