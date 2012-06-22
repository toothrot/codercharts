#include<stdio.h>
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
    if(c == argv[1][0])
    {
      for(o = 1; argv[1][o] != 0; o++)
      {
        if(map[i+o] != argv[1][o])
          break;
        if(argv[1][o+1] == 0 && map[i+o+1] == 10)
        {
          printf("%i\n", nl);
          found = true;
          break;
        }
      }
      if(found)
        break;
    } else if(map[i] == 10)
    {
      nl++;
      found = false;
    }
    i++;
  }
  if(!found)
    printf("0\n");
  munmap(map, 10000000);
  close(fp);
  return(0);
}
