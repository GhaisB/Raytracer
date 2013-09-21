/*
** concat.c for concat in /home/knocka_a/rendu/c/minishell2
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat Mar  3 17:46:02 2012 antoine knockaert
** Last update Wed May 30 20:38:52 2012 guillaume boufflers
*/

#include	"../rt.h"

char		*concat(char *str1, char *str2)
{
  char		*ret;
  int		size;
  int		i;
  int		j;

  i = 0;
  j = 0;
  size = my_strlen(str1) + my_strlen(str2) + 5;
  ret = xmalloc(size * sizeof(char));
  if (ret)
    {
      while (str1 && str1[i])
	ret[j++] = str1[i++];
      i = 0;
      while (str2 && str2[i])
	ret[j++] = str2[i++];
      ret[j] = 0;
    }
  return (ret);
}
