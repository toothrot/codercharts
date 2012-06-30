#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdbool.h>
#include<string.h>

int main(int argc, char *argv[])
{
  bool found = false;
  int  fp = 0, nl = 1, i = 0, l;
  char *map;
  l = strlen(argv[1]);

  fp = open(argv[2], 0);
  map = mmap(NULL, 10000000, PROT_READ, MAP_PRIVATE, fp, 0);
  while(map[i] != 0)
  {
    if(map[i] != argv[1][0] && map[i] != 10){
      i++;
      continue;
    } else if(map[i] == argv[1][0])
    {
      if((memcmp(argv[1], map+i, l) == 0) && map[i+l] == 10)
      {
        printf("%i\n", nl);
        return(0);
      } else {
        i++;
      }
    } else if(map[i] == 10)
    {
      i++;
      nl++;
      found = false;
    }
  }
  puts("0");
  return(0);
}
