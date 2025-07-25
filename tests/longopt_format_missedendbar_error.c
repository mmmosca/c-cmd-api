/*
This program is free software: you can redistribute it and/or 
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see https://www.gnu.org/licenses/.
 
Author Marco M. Mosca, email: marcomichele.mosca@gmail.com
*/
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
