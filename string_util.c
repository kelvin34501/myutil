#include "string_util.h"

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
