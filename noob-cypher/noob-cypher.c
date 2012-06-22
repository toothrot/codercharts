#include<stdio.h>
#include<sys/mman.h>
#include<string.h>

int main(int argc, char *argv[])
{
  int fp = 0, i = 0, j = 0, table[26];
  char *map;

  for(i = 0; i < 26; i++)
    table[argv[1][i] - 'A'] = i;

  fp = open(argv[2], 0);
  map = mmap(NULL, 10000000, PROT_READ, MAP_PRIVATE, fp, 0);
  for(i = 0; map[i] != 0; i++)
  {
    if(isspace(map[i]))
    {
      putchar(map[i]);
    } else
    {
      putchar('A' + table[map[i] - 'A']);
    }
  }
  munmap(map, 10000000);
  close(fp);
  return(0);
}
