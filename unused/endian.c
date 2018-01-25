#include <stdio.h>
#include <stdlib.h>

typedef unsigned char * p_byte;

void show_bytes(p_byte start, int len)
{
        for(int i = 0; i < len; i++)
                printf(" %.2x", start[i]);
        printf("\n");
}

void show_int(int x)
{
        show_bytes((p_byte) &x, sizeof(int));
}

void show_float(float x)
{
        show_bytes((p_byte) &x, sizeof(float));
}

void show_pointer(void * x)
{
        show_bytes((p_byte) &x, sizeof(void *));
}

char* itoa(int num, char* str,int radix)
{
        char index[]="0123456789ABCDEF";
        unsigned unum;
        int i=0,j,k;

        if(radix==10 && num<0)
        {
                unum=(unsigned)-num;
                str[i++]='-';
        }
        else unum=(unsigned)num;

        do{
                str[i++]=index[unum%(unsigned)radix];
                unum/=radix;
        }while(unum);
        str[i]='\0';

        if(str[0]=='-')
                k=1;
        else
                k=0;
        char temp;
        for(j=k;j<=(i-1)/2;j++)
        {
                temp=str[j];
                str[j]=str[i-1+k-j];
                str[i-1+k-j]=temp;
        }
        return str;
}

int main(void)
{
        int val = 0x87654321;
        p_byte p_val = (p_byte) &val;
        show_bytes(p_val, 1);
        show_bytes(p_val, 2);
        show_bytes(p_val, 3);
        show_bytes(p_val, 4);

        int a = 3510593;//0x00359141
        float b = 3510593.0;//0x4A564504
        show_int(a);
        show_float(b);

        char x[100];
        itoa(a, x, 2);
        printf("%s\n", x);
        return 0;
}
