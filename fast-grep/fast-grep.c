#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
  bool found = false;
  int  o, fp = 0, nl = 1, i = 0;
  char *map;

  fp = open(argv[2], 0);
  map = mmap(NULL, 10000000, PROT_READ, MAP_PRIVATE, fp, 0);
  while(map[i] != 0)
  {
    if(map[i] != argv[1][0] && map[i] != 10){
      i++;
      continue;
    } else if(map[i] == argv[1][0])
    {
      i++;
      for(o = 1; argv[1][o] == map[i]; o++, i++)
      {
        if(argv[1][o+1] == 0 && map[i+1] == 10)
        {
          printf("%i\n", nl);
          return(0);
        }
      }
    } else if(map[i] == 10)
    {
      i++;
      nl++;
      found = false;
    }
  }
  if(!found)
    printf("0\n");
  munmap(map, 10000000);
  close(fp);
  return(0);
}
