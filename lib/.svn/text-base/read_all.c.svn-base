/*
** read_all.c for read_all in /home/knocka_a/repositories/42sh/lib
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Mon Apr  9 19:18:35 2012 antoine knockaert
** Last update Sat Jun  2 14:32:26 2012 antoine knockaert
*/

#include	<stdlib.h>
#include	"../rt.h"

char		**read_all(int fd)
{
  char		*buffer;
  char		*ret;
  char		*tmp;
  char		**final;

  final = NULL;
  buffer = xmalloc(2048 * sizeof(char));
  init_str(buffer, 2048);
  ret = NULL;
  while (buffer && xread(fd, buffer, 2000))
    {
      tmp = concat(ret, buffer);
      xfree(ret);
      ret = tmp;
      init_str(buffer, 2048);
    }
  xfree(buffer);
  if (ret)
    final = my_str_to_wordtab(ret, '\n');
  xfree(ret);
  return (final);
}
