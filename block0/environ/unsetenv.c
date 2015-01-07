/* unsetenv.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gnu/libc-version.h>
#define OLD_LIBC_VERSION         0
#define NEW_LIBC_VERSION         1
#define E_VAR                    "USER"
int libc_cur_version (void)
{
        int ret = strcmp (gnu_get_libc_version (), "2.2.2");
        if (ret < 0) return OLD_LIBC_VERSION;
        return NEW_LIBC_VERSION;
}
int main (void)
{
        int ret;
        char * str;
        if (libc_cur_version () == OLD_LIBC_VERSION)
        {
                unsetenv (E_VAR);
        } else
        {
                ret = unsetenv (E_VAR);
                if (ret != 0)
                {
                        fprintf (stderr, "Cannot unset '%s'\n", E_VAR);
                        exit (1);
                }
        }
  str = getenv (E_VAR);
  if (str == NULL)
  {
          printf ("'%s' has removed from environment\n", E_VAR);
  } else
  {
          printf ("'%s' hasn't removed\n", E_VAR);
  }
  exit (0);
}

