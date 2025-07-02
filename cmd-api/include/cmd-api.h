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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Struct for command line parser
 * - opt -- Current option detected
 * - arg -- Current option's argument
 */
typedef struct optarg {
  char *opt;
  char *arg;
} optarg_t;

/**
 * Set of variables for cmd-api-c
 * - optind -- Index of the option. 
 *             Starts with the first word after the executable.
 */
static int optind = 1;

/**
 *  Find the shortest string among s1 and s2 in the other.
    \param s1 string 1
    \param s2 string 2
    \param from index of the longest string where to start
                comparing the shortest string. 

    \retval 1 -- both strings are equal or the shortest is contained in the longest
    \retval 0 -- the shortest string is not contained in the longest*/
int AreStringsEqualFrom(const char* s1, const char* s2, int from);

/**
    \param sub substring to search for in str
    \param str string that is searched for substring sub

    \retval i  -- index of str where sub substring starts
    \retval -1 -- no substring found in str*/
int isSubstring(char* sub, char* str);

/** Cycles on the command line parameters and arguments
    and returns the current option and its argument.
    This function should be used in a while loop and
    the returned struct should be freed after each call.
    Usage:
    while ((optarg = getoptW(argc, argv, "opt1:|opt2:|")) != NULL) {
		if (strcmp(optarg->opt, "opt1") == 0) {
			printf("%s\n", optarg->arg);
			continue;
		}
		if (strcmp(optarg->opt, "opt2") == 0) {
			printf("%s\n", optarg->arg);
			continue;
		}
		free(optarg);
	}
    \param argc number of command line items (related to main argc)
    \param argv array of command line words (related to main argv)
    \param format format string, which contains the option name
                followed by special characters to specify whether...:
                ':' -> ...the option expects an argument
                '|' -> ...the end of the option

    \retval optarg -- struct with current option and argument.
                    Needs deallocation after each getoptW call.
    \retval NULL -- end of command line */
optarg_t* getoptW(int argc, char** argv, char* format);

#endif /* CMD_H_ */
