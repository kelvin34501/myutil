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

char * kmp(char * src, char * tgt)
{
        int i=0,j=0,k=0;

        //scan the tgt to get the length of offset array
        for(k=0; tgt[k]!='\0'; k++);
        if(k==0)
                return NULL;
        int * buf = malloc(sizeof(int) * k);

        // gen offset array
        buf[0]=-1; k=0;
        for(i=1; tgt[i]!='\0'; i++) {
                if(tgt[k]==tgt[i]) {
                        buf[i] = buf[k]; i++; k++;
                } else {
                        buf[i] = k;
                        k = buf[k];
                        while(k>=0 && tgt[i]!=tgt[k])
                                k = buf[k];
                        i++;k++;
                }
        }
        buf[i]=k;

        //pattern matching
        for(i=0,j=0; src[i]!='\0';) {
                if(src[i]==tgt[j]) {
                        i++; j++;
                        if(tgt[j]=='\0')
                                return (src)+i-j;
                } else {
                        j=buf[j];
                        if(j<0) {
                                i++; j++;
                        }
                }
        }


        //free the resources
        free(buf);
        return NULL;
}
