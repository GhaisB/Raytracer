/*
** tests.c for tests in /home/knocka_a/repositories/rt
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Wed May  9 19:38:03 2012 antoine knockaert
** Last update Fri Jun  1 12:19:43 2012 antoine knockaert
*/

#include	"../rt.h"

int		is_type(char *str, t_pars *pars)
{
  int		i;

  i = 0;
  while (pars->types && pars->types[i])
    {
      if (my_match(str, pars->types[i]))
	return (i);
      i++;
    }
  return (-1);
}

int		count_for_obj(char **str, int i, t_pars *pars)
{
  int		j;

  j = 0;
  while (str && str[i] && is_type(str[i], pars) == -1)
    {
      i++;
      j++;
    }
  return (j);
}

void		stock_params(char **str, int i, t_pars *pars, int classic)
{
  int		j;

  j = 0;
  while (str && str[i] && is_type(str[i], pars) == -1)
    {
      if (j == 0 && classic)
	pars->values[j] = hex_to_double(str[i]);
      else if ((j == 35 || j == 36) && classic)
	pars->values[j] = hex_to_double(str[i]);
      else
	pars->values[j] = atof(str[i]);
      i++;
      j++;
    }
}

int		verif_oeil(t_pars *pars)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      if (pars->oeil[i] == -1)
	return (0);
      i++;
    }
  return (1);
}

void		aff_error(int i, int ret)
{
  printf("Invalid number of params for one object :");
  printf("\n\n\tBegin on line %d\n\tSet params : %d", i, ret);
  printf("\n\tNeeeded params : %d\n", NB_PARAM);
}
