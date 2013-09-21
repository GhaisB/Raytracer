/*
** epur_str.c for epur in /home/knocka_a/lem-in/other
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed Mar 28 14:01:14 2012 antoine knockaert
** Last update Thu May 31 20:14:39 2012 antoine knockaert
*/

#include	"../rt.h"

char		*epur_str(char *str, int mfree, char c)
{
  int		i;
  int		j;
  char		*s;

  i = 0;
  j = 0;
  s = xmalloc((my_strlen(str) + 10) * sizeof(char));
  init_str(s, my_strlen(str) + 10);
  while (str && str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (s && str && str[i] && str[i] != c)
    {
      while (str && str[i] && str[i] != ' ' && str[i] != '\t')
        s[j++] = str[i++];
      while (str && str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
      if (str && str[i])
	s[j++] = ' ';
    }
  if (mfree)
    xfree(str);
  if (s && (my_strlen(s) - 1) >= 0 && s[my_strlen(s) - 1] == ' ')
    s[my_strlen(s) - 1] = 0;
  return (s);
}
