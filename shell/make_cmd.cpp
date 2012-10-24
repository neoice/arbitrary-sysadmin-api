// make_cmd.cpp: Routine to parse a string into arguments
// taken with love from a professor
//
// TODO: rewrite this because of "not invented here" ;)

#include <string.h>
#include <iostream>
#include "make_cmd.h"
using namespace std;

#define DELIM " \t\n"

int make_cmd(char *cmd_str, struct cmd_t &command)
{
  int numtokens = 0;		// number of tokens
  int argcount = 0;		// number of arguments processed
  char **argv = NULL;		// temporary vector of arguments
  const char *snew;		// command string without leading spaces
  char *temp_str;		// temporary string used by strtok
  int i;			// loop traversal variable

  // Initialize cmd structure
  command.argv = NULL;
  command.input_redirect = NULL;
  command.output_redirect = NULL;
  command.background = false;

  // Remove spaces at beginning
  snew = cmd_str + strspn(cmd_str, DELIM);
  if (strlen(snew) == 0) return 0;
  temp_str = new char[strlen(snew) + 1];
  if (temp_str == NULL) return -1;
  strcpy(temp_str, snew);

  // Count the number of tokens in the command
  if (strtok(temp_str, DELIM) != NULL)
    for (numtokens = 1; strtok(NULL, DELIM) != NULL; numtokens++) ;

  // Create an array of pointers for the tokens
  argv = new char *[numtokens + 1];
  command.argv = new char *[numtokens + 1];
  if (argv == NULL || command.argv == NULL) {
    delete []temp_str;
    return -1;
  }

  // Insert pointers to tokens into the argument array
  if (numtokens == 0)  {
    delete []temp_str;
  }
  else {
    strcpy(temp_str, snew);
    *argv = strtok(temp_str, DELIM);
    for (i = 1; i < numtokens; i++)
      *(argv + i) = strtok(NULL, DELIM);
  }

  // Put in final NULL pointer
  *(argv + numtokens) = NULL;

  // Store information in command structure
  i = 0;
  while (i < numtokens) {
    if (strcmp(*(argv + i), ">") == 0) {
      if (command.output_redirect != NULL) return -1;
      if (i == numtokens - 1) return -1;
      command.output_redirect = *(argv + i + 1);
      i += 2;
    }
    else if (strcmp(*(argv + i), "<") == 0) {
      if (command.input_redirect != NULL) return -1;
      if (i == numtokens - 1) return -1;
      command.input_redirect = *(argv + i + 1);
      i += 2;
    }
    else if (strcmp(*(argv + i), "&") == 0) {
      if (i != numtokens - 1) return -1;
      command.background = true;
      i++;
    }
    else {
      *(command.argv + argcount) = *(argv + i);
      i++;
      argcount++;
    }
  }

  // Put in final NULL pointer
  *(command.argv + argcount) = NULL;
  if (argcount == 0) {
    delete []command.argv;
    command.argv = NULL;
    return -1;
  }

  // Free temporary memory
  delete []argv;

  return argcount;
}
