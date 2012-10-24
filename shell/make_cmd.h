// make_cmd.cpp: Routine to parse a string into arguments
// taken with love from a professor
//
// TODO: rewrite this because of "not invented here" ;)

#ifndef MAKE_CMD_H
#define MAKE_CMD_H

struct cmd_t
{
  char **argv;		  // argument array
  char *input_redirect;	  // file name for input redirection (NULL - none)
  char *output_redirect;  // file name for output redirection (NULL - none)
  bool background;	  // true if run in background, false otherwise
};
 
// make_cmd: divdes cmd_str into argument tokens using white space as a
// delimiter
//
// RETURNS: If succesful, returns the number of the arguments in the
// argument array (argv).  On error, it returns -1.
//
// PARAMETERS:
// cmd_str - (IN) Contains the command line to be parsed.
// command - (OUT) Upon success, the function fills in the structure.
//
int make_cmd(char *cmd_str, struct cmd_t &command);

#endif
