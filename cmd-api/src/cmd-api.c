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

int AreStringsEqualFrom(const char* s1, const char* s2,int from) {
	int len1, len2, i=0, lensub, lenbig;
	const char *bigger, *smaller;

	if ((s1 == NULL) || (s2 == NULL)) return 0;

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (len1 > len2) {
		bigger = s1;
		smaller = s2;
		lensub = len2;
		lenbig = len1;
	}
	else
	{
		bigger = s2;
		smaller = s1;
		lensub = len1;
		lenbig = len2;
	}

	if ((lenbig - from) < lensub) return 0;

	while ((bigger[i+from] == smaller[i]) && (i < lensub)) {
		i++;
	}

	if (i == lensub) return 1;
	else return 0;
}

int isSubstring(char* sub, char* str) {
	int sublen= strlen(sub), len = strlen(str), i=0;

	while (i <= len-sublen) {
		if (AreStringsEqualFrom(sub, str, 0)) {
			return i;
		}
		i++;
		str++;
	}

	return -1;
}

optarg_t* getoptW(int argc, char** argv, char* format) {
	/**
	 * - argvind -- Index of the option's argument.
	 *             Start with the second word after the executable.
	 * - formatind -- Index of the option in the format string
	 * - argformatind -- Starting index of the argument types in the format string 
	 */
	int argvind, formatind, argformatind;
	optarg_t* optarg = (optarg_t*)malloc(sizeof(optarg_t));

	if (optind == -1) {
		return NULL;
	}
	if (optind > argc - 1) {
		puts("Error in parameters number!");
		exit(EXIT_FAILURE);
	}
	if (argv[optind][0] != '-') {
		puts("It is not an option: missing dash");
		exit(EXIT_FAILURE);
	}
	optarg->opt = ++argv[optind];
	if ((formatind = isSubstring(optarg->opt, format)) == -1) {
		optarg->arg = NULL;
		puts("Unknown option!");
		exit(EXIT_FAILURE);
	}

	argvind = optind + 1;
	argformatind = formatind + strlen(optarg->opt);	
	if ((argvind > argc - 1) && (format[argformatind] != '|')) {
		puts("Missing end bar for the last option in format string");
		exit(EXIT_FAILURE);
	}
	if (argformatind >= (int)strlen(format)) {
		puts("Format string is wrong at the end");
		exit(EXIT_FAILURE);
	}
	if ((format[argformatind] == ':') && (argv[argvind][0] == '-')) {
		puts("Argument expected when : is in format string");
		exit(EXIT_FAILURE);
	}
	if ((format[argformatind] != ':') && (argv[argvind][0] != '-')) {
		puts("Argument not expected when : is not in format string");
		exit(EXIT_FAILURE);
	}
	if (format[argformatind] == ':') {
		optarg->arg = argv[argvind];
		optind += 2;
		++argformatind;
	} else {
		optarg->arg = NULL;
		++optind;
	}

	if (format[argformatind] != '|') {
		puts("Missing end bar in option format");
		exit(EXIT_FAILURE);
	}

	if (optind > argc - 1) optind = -1;
	return optarg;
}
