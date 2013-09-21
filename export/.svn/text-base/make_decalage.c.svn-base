/*
** make_decalage.c for rt in /home/knocka_a/repositories/rt/export
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat Jun  2 18:36:36 2012 antoine knockaert
** Last update Sat Jun  2 18:36:37 2012 antoine knockaert
*/

#include "../rt.h"

unsigned char	*make_decalage(unsigned char *data)
{
  unsigned char	*tmp;
  int	i;
  int	pos;

  i = 0;
  pos = 0;
  tmp = data;
  while (i < (HAUTEUR * LARGEUR * 4))
    {
      if (i > 20 && (pos % 2 == 0))
	{
	  tmp[i + 20] = data[i] + 1;
	  pos++;
	}
      else if (pos == 3)
	pos = 0;
      i++;
    }
  return (tmp);
}
