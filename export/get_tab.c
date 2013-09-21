/*
** fonction_qui_change_une_string_en_double_tableau.c for  in /home/
** 
** Made by guillaume boufflers
** Login   <bouffl_g@epitech.net>
** 
** Started on  Wed May 23 19:34:51 2012 guillaume boufflers
** Last update Sat Jun  2 14:31:31 2012 antoine knockaert
*/

#include "./export.h"
#include "../rt.h"

void	init_map(char ***map, int *nb1, int *nb2, int *nb3)
{
  int	i;
  int	pos;

  i = 0;
  pos = 1;
  (*nb1) = 0;
  (*nb2) = 0;
  (*nb3) = 0;
  (*map) = malloc((HAUTEUR + 1) * sizeof(char *));
  while (i <= (HAUTEUR))
    {
      (*map)[i] = malloc((4 * LARGEUR + 1) * sizeof(char));
      pos++;
      i++;
    }
  (*map)[HAUTEUR] = NULL;
}

char	**get_map(unsigned char *data)
{
  char	**map;
  int	i;
  int	j;
  int	k;

  init_map(&map, &i, &j, &k);
  while (i < (LARGEUR * HAUTEUR * 4))
    {
      if (j == (LARGEUR * 4 - 1))
	{
	  j = 0;
	  k++;
	}
      else
	{
	  map[k][j] = data[i];
	  j++;
	}
      i++;
    }
  map[k] = NULL;
  return (map);
}
