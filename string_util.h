#ifndef __MYUTIL_STRING_UTIL_H__
#define __MYUTIL_STRING_UTIL_H__

#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

// This header will generate a series of containers.
// It may cause conflicts.
// Watch out.
#include "vector_template.h"
vector_(string,char *)

void string_util_cleanup(char ** pstr);
void string_split(char * str, vector_string * vec);


#endif
