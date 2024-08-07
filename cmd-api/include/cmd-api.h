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
#ifndef CMD_H_
#define CMD_H_

#ifdef DEBUG
#define PRINT_DATA()	printf("CURRENT ---- OPTIND: %d ---- ARGVIND: %d ---- OPTION: %c ---- OPTARG: %s\n", optind, argvind, argv[optind][1], myoptarg);
#define PRINT_DATAW()	printf("CURRENT ---- OPTIND: %d ---- ARGVIND: %d ---- OPTION: %s ---- OPTARG: %s\n", optind, argvind, argv[optind], myoptarg);
#else
#define PRINT_DATA()	{};
#define PRINT_DATAW()	{};
#endif

#include <stdio.h>
#include <string.h>
#include <Windows.h>

int isCharInString(char c, char* str);
int AreStringsEqualFrom(const char* s1, const char* s2, int from);
int isSubstring(char* sub, char* str);
char* strsep(char** elem_pointer, char* pattern);
char* getoptW(int argc, char** argv, char* format);

#endif /* CMD_H_ */
