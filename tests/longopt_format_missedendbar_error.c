#include "cmd-api.h"


void test_longopt_format_missedendbar_error()
{
	char* arr[] = {"exe", "-opt1", "val1", "-opt2"};
	optarg_t* optarg;
  
	while ((optarg = getoptW(4, arr, "opt1:|opt2")) != NULL);
}

int main()
{
  test_longopt_format_missedendbar_error();
  return 0;
}
