#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
  int size, fp, i, length, found = 0, nl = 1;
  char *map, c;
  struct stat st;

  length = strlen(argv[1]);
  stat(argv[2], &st);
  size = st.st_size;
  fp = open(argv[2], O_RDONLY);

  map = mmap(NULL, size, PROT_READ, MAP_SHARED, fp, 0);
  for(i = 0; i < size; i++)
  {
    c = map[i];
    if(c == 10)
      nl++;
    found = strncmp(argv[1], map + i, length);
    if(found == 0)
    {
      printf("%i\n",nl);
      break;
    }
  }
  if(!(found == 0))
    puts("0");
  exit(0);
}
