#include <stdio.h>
#include <dirent.h>

int main (int argc, char ** argv) 
{
  DIR * d;
  struct dirent * entry;
  if (argc != 2) {
    printf("Использование: %s <директория>\n", argv[0]);
    return 0;
  }
  d = opendir(argv[1]);
  if (d == NULL) 
  {
     printf("Ошибка чтения директории\n");
     return 1;
  }
  while (entry = readdir(d)) 
    printf("%s inode=%i\n", entry->d_name, entry->d_ino);
  closedir(d);
  return 0;
}


