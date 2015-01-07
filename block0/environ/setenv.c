/* setenv.c */
#include <stdio.h>
#include <stdlib.h>
#define FL_OVWR         0        /* Overwrite flag. You may change it. */
int main (int argc, char ** argv)
{
        if (argc < 3)
        {
                fprintf (stderr, "setenv: Too few arguments\n");
                fprintf (stderr,
                        "Usage: setenv <variable> <value>\n");
                exit (1);
        }
        if (setenv (argv[1], argv[2], FL_OVWR) != 0)
        {
                fprintf (stderr, "setenv: Cannot set '%s'\n", argv[1]);
                exit (1);
        }
        printf ("%s=%s\n", argv[1], getenv (argv[1]));
        exit (0);
}

