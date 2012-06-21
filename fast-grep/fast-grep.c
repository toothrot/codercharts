#include<stdio.h>
#include<sys/mman.h>

int main(int argc, char *argv[])
{
  unsigned i = 0;
  int fp = 0, j = -1, nl = 1;
  char *map;

  fp = open(argv[2], 0);
  map = mmap(NULL, 10000000, PROT_READ, MAP_SHARED, fp, 0);
  while(map[i] != 0)
  {
    if(map[i] == 10)
    {
      nl++;
      j = 0;
    } else if(j > 0 || (nl == 1 && j == 0))
    {
      if(argv[1][i-j+1] == 0 && map[i+1] == 10)
      {
        printf("%i\n", nl);
        break;
      } else if(map[i] != argv[1][i-j])
      {
        j = -1;
      }
    } else if(map[i] == argv[1][0])
    {
      j = i;
    }
    i++;
  }
  if(!j)
    printf("0\n");
  munmap(map, 10000000);
  close(fp);
  return(0);
}
