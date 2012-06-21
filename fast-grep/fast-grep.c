#include<stdio.h>
#include<sys/mman.h>

int main(int argc, char *argv[])
{
  unsigned i = 0;
  int fp = 0, j = 0, found = 0, nl = 1;
  char *map;

  fp = open(argv[2], 0);
  map = mmap(NULL, 10000000, PROT_READ, MAP_SHARED, fp, 0);
  while(map[i] != 0)
  {
    if(map[i] == 10)
    {
      nl++;
      i++;
      continue;
    }
    if(!found && map[i] == argv[1][0])
    {
      found = 1;
      j = i;
    } else if(found)
    {
      if(argv[1][i-j+1] != 0)
      {
        if(map[i] != argv[1][i-j])
          found = 0;
      } else {
        printf("%i\n", nl);
        break;
      }
    }
    i++;
  }
  if(!found)
    puts("0");
  munmap(map, 10000000);
  close(fp);
  return(0);
}
