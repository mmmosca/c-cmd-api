#include "cmd-api.h"
#include "assert.h"


void test_longopt_basic()
{
	char* arr[] = {"exe", "-opt1", "val1", "-opt2", "val2"};
	optarg_t* optarg;
  
	while ((optarg = getoptW(5, arr, "opt1:|opt2:|")) != NULL) {
		if (strcmp(optarg->opt, "opt1") == 0) {
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
  test_longopt_basic();
  return 0;
}
