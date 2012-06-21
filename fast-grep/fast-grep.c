#include<stdio.h>
#include<sys/mman.h>

int main(int argc, char *argv[])
{
  unsigned i = 0;
  int fp = 0, j = 0, length = 0, found = 0, nl = 1;
  char *map, c;

  while(argv[1][length] != 0)
    length++;

  fp = open(argv[2], 0);
  map = mmap(NULL, 10000000, PROT_READ, MAP_SHARED, fp, 0);
  while(map[i] != 0)
  {
    c = map[i];
    if(c == 10)
    {
      nl++;
      i++;
      continue;
    }
    if(c == argv[1][0])
    {
      found = 1;
      for(j = 0; j < length; j++)
      {
        if(map[i+j] != argv[1][j])
        {
          found = 0;
          break;
        }
      } 
      if(found && map[i+length] == 10)
      {
        printf("%i\n",nl);
        return(0);
      } else {
        i+=j;
        continue;
      }
    }
    i++;
  }
  puts("0");
  return(0);
}
