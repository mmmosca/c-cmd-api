#include "cmd-api.h"


void test_longopt_format_missedbar_error()
{
	char* arr[] = {"exe", "-opt1", "-opt2", "val2"};
	optarg_t* optarg;
  
	while ((optarg = getoptW(5, arr, "opt1opt2:|")) != NULL);
}

int main()
{
  test_longopt_format_missedbar_error();
  return 0;
}
