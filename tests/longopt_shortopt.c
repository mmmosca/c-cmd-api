#include "cmd-api.h"
#include "assert.h"


void test_longopt_shortopt_error()
{
	char* arr[] = {"exe", "-o", "val1", "-opt2", "val2"};
	optarg_t* optarg;
  
	while ((optarg = getoptW(5, arr, "o:|opt2:|")) != NULL) {
		if (strcmp(optarg->opt, "o") == 0) {
      		assert(strcmp(optarg->arg, "val1") == 0);
			continue;
		}
		if (strcmp(optarg->opt, "opt2") == 0) {
      		assert(strcmp(optarg->arg, "val2") == 0);
			continue;
		}
		free(optarg);
	}
}

int main()
{
  test_longopt_shortopt_error();
  return 0;
}
