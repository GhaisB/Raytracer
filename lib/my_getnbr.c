/*
** my_getnbr.c for my_getnbr in /home/duez_a/
** 
** Made by guillaume duez
** Login   <duez_a@epitech.net>
** 
** Started on  Tue Oct 11 15:04:18 2011 guillaume duez
** Last update Sat Jun  2 18:36:14 2012 antoine knockaert
*/

int	calcul_first(char *str, int *i)
{
  int	compteur;
  int	x;
  int	j;

  j = *i;
  x = 0;
  compteur = 0;
  while (str[j] <= '9' && str[j] >= '0')
    {
      compteur = (compteur * 10) + (str[j] - '0');
      j = j + 1;
      x = x + 1;
      if (x > 10)
	return (0);
    }
  return (compteur);
}

int	my_getnbr(char *str)
{
  int	compteur;
  int	i;
  int	neg;

  neg = ( - 1);
  i = 0;
  compteur = 0;
  while (str[i])
    {
      if (str[i] == '-')
        neg = neg * (-1);
      if (str[i] <= '9' && str[i] >= '0')
	{
	  compteur = calcul_first(str, &i);
	  compteur = compteur * ( - 1 * neg);
	  return (compteur);
	}
      i = i + 1;
    }
  return (compteur);
}
