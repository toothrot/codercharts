#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
  int size, fp, i, nl = 1;
  char *map, c;
  char *match = 0;
  struct stat st;

  stat(argv[2], &st);
  size = st.st_size;
  fp = open(argv[2], O_RDONLY);

  map = mmap(NULL, size, PROT_READ, MAP_SHARED, fp, 0);
  match = strstr(map, argv[1]);
  if(match)
  {
    for(i = 0; i < match-map; i++)
    {
      if(map[i] == 10)
        nl++;
    }
    printf("%i", nl);
  } else {
    printf("0");
  }
  exit(0);
}
