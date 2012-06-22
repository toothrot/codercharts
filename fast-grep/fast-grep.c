#include<stdio.h>
#include<sys/mman.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
  bool found = false;
  int  o, fp = 0, nl = 1, i = 0;
  char *map, c;

  fp = open(argv[2], 0);
  map = mmap(NULL, 10000000, PROT_READ, MAP_PRIVATE, fp, 0);
  while(map[i] != 0)
  {
    c = map[i];
    if(found)
    {
      o++;
      if(c != argv[1][o])
      {
        found = false;
      } else if(argv[1][o+1] == 0 && map[i+1] == 10)
      {
        printf("%i\n", nl);
        break;
      }
    } else if(c == argv[1][0])
    {
      found = true;
      o = 0;
      i++;
      continue;
    }
    if(c == 10)
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
