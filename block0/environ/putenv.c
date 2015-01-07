/* putenv.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUERY_MAX_SIZE          32
char * query_str;
void print_evar (const char * var)
{
        char * tmp = getenv (var);
        if (tmp == NULL)
        {
                printf ("%s is not set\n", var);
                return;
        }
        printf ("%s=%s\n", var, tmp);
}
int main (void)
{
        int ret;
        query_str = (char *) calloc (QUERY_MAX_SIZE, sizeof(char));
        if (query_str == NULL) abort ();
        strncpy (query_str, "FOO=foo_value1", QUERY_MAX_SIZE-1);
        ret = putenv (query_str);
        if (ret != 0) abort ();
        print_evar ("FOO");
        strncpy (query_str, "FOO=foo_value2", QUERY_MAX_SIZE-1);
        print_evar ("FOO");
        strncpy (query_str, "FOO", QUERY_MAX_SIZE-1);
        ret = putenv (query_str);
        if (ret != 0) abort ();
        print_evar ("FOO");
        free (query_str);
        exit (0);
}

