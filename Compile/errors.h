#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED
enum errors
{
	OK = 1,
	FILE_NO_OPEN = 2,
	NULL_LENGTH = 3,
	BAD_MALLOC = 4,
	NULLPOINTER = 6,
	ENDOFARRAY = 7,
	STACKFULL = 8,
	STACKNULLSIZE = 9,
	ENDOFFILE = 10,
	BAD_FILE = 5,
        MAXERROR
};
extern errors MY_ERRNO;
void dump(const errors ERROR, const char *FUNCTION_NAME, const int LINE, const char *FILE, const bool kill);

#define PLEASE_KILL_MY_VERY_BAD_FUNCTION dump(MY_ERRNO, __PRETTY_FUNCTION__, __LINE__, __FILE__, true);
#define PLEASE_DONT_KILL_MY_VERY_BAD_FUNCTION dump(MY_ERRNO, __PRETTY_FUNCTION__, __LINE__, __FILE__, false);
#endif
