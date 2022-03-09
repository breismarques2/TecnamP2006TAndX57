/* sc_version_string.h - written by cmake. Changes will be lost! */
#ifndef SC_VERSION_STRING
#define SC_VERSION_STRING

/*
** The git commit id looks like "test-1-g5e1fb47", where test is the
** name of the last tagged git revision, 1 is the number of commits since that tag,
** 'g' is unknown, and 5e1fb47 is the first 7 chars of the git sha1 commit id.
** timestamp is created from date/time commands on known platforms, and uses
** preprocessor macros elsewhere.
*/

static char sc_version[512] = {
    "git commit id: 0.8, build timestamp 03 Nov 2020 03:17"
};

#endif
