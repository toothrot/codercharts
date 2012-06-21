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
    if(map[i] == argv[1][0])
    {
      found = 1;
      for(j = 0; argv[1][j] != 0; j++)
      {
        if(map[i+j] != argv[1][j])
        {
          found = 0;
          break;
        }
      } 
      if(found && map[i+j] == 10)
      {
        printf("%i\n",nl);
        break;
      } else {
        i+=j;
        continue;
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
