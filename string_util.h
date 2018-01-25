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

void string_util_cleanup(char ** pstr)
{
        free(*pstr);
        *pstr = NULL;
}

// some util fn
void string_split(char * str, vector_string * vec)
{
        vector_string_init(vec);
        int ind = 0;
        for(int i = 0; str[i] != '\0'; i++)
        {
                if(isblank(str[i]))
                {
                        if(i - ind > 0)
                        {
                                char * tmp = malloc(sizeof(char) * (i - ind) + 1);
                                strncpy(tmp, str + ind, i - ind);
                                tmp[i - ind] = '\0';
                                vector_string_push(vec, tmp);
                        }
                        ind = i + 1;
                }
        }
}


#endif
