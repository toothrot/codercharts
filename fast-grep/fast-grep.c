#include <stdio.h>
#include <string.h>

FILE *fp;

main(int argc, char *argv[])
{
  int n = 0;
  char line[1024];
  fp = fopen(argv[2], "rt");

  while(fgets(line, 80, fp) != NULL)
  {
    n++;
    sscanf(line, "%s", line);
    if(strcmp(line, argv[1]) == 0)
    {
      printf("%d\n", n);
      return 0;
    }
  }
  printf("0");
  return 0;
}
