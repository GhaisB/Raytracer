/*
** main.c for main in /home/knocka_a/parsing
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Tue May  8 15:58:37 2012 antoine knockaert
** Last update Sat Jun  2 18:41:18 2012 antoine knockaert
*/

#include	"../rt.h"

void		clean_tabl(char **str)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      str[i] = epur_str(str[i], i, COM);
      i++;
    }
}

void		add_to_list(int type, t_pars *pars, char *name)
{
  t_sph		*obj;

  obj = xmalloc(sizeof(t_sph));
  obj->type = type;
  obj->name = my_strdup(name);
  obj->nt = NULL;
  add_params_first(obj, pars->values);
  add_to_list_obj(pars, obj);
}

int		add_oeil_info(char **str, int i, t_pars *pars)
{
  int		ret;

  if ((ret = count_for_obj(str, i + 1, pars)) != 9)
    {
      my_putstr("Invalid number of params of 'OEIL'.\n");
      return (0);
    }
  stock_params(str, i + 1, pars, 0);
  pars->oeil[0] = pars->values[0];
  pars->oeil[1] = pars->values[1];
  pars->oeil[2] = pars->values[2];
  pars->oeil[3] = pars->values[3];
  pars->oeil[4] = pars->values[4];
  pars->oeil[5] = pars->values[5];
  pars->oeil[6] = pars->values[6];
  pars->oeil[7] = pars->values[7];
  pars->oeil[8] = pars->values[8];
  return (1);
}

int		parseur(t_pars *pars, char **str)
{
  int		i;
  int		ret;
  int		type;

  i = 0;
  while (str && str[i])
    {
      if (my_match(str[i], "OEIL"))
	if (!add_oeil_info(str, i, pars))
	  return (0);
      if ((type = is_type(str[i], pars)) != -1)
	{
	  ret = count_for_obj(str, i + 1, pars);
	  if (ret != NB_PARAM)
	    {
	      aff_error(i, ret);
	      return (0);
	    }
	  stock_params(str, i + 1, pars, 1);
	  add_to_list(type, pars, str[i]);
	  i += ret;
	}
      i++;
    }
  return (1);
}

t_sph		*parse(char *filename, t_cod *cor, t_mlx *init_ptr, char **file)
{
  int		fd;
  t_pars	*pars;

  pars = xmalloc(sizeof(t_pars));
  fd = init(pars, filename);
  if (!file)
    file = read_all(fd);
  clean_tabl(file);
  if (file)
    if (!parseur(pars, file))
      return (NULL);
  close(fd);
  if (pars->obj_a != NULL && verif_oeil(pars))
    {
      stock_oeil(pars, cor, init_ptr);
      return (pars->obj_a);
    }
  else
    {
      my_putstr("Rt: Error: No objects or OEIL not set.\n");
      return (NULL);
    }
}
