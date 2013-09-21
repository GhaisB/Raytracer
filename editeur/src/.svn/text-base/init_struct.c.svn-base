/*
** init_struct.c for init.c in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 27 23:25:31 2012 antoine knockaert
** Last update Sun Jun  3 11:01:15 2012 antoine knockaert
*/

#include	"../edit.h"

void		init_labels_name(t_glob *glob)
{
  glob->pobj_labels[0] = my_strdup("Nom de l'objet");
  glob->pobj_labels[1] = my_strdup("Type de l'objet");
  glob->pobj_labels[2] = my_strdup("Couleur de l'objet");
  glob->pobj_labels[3] = my_strdup("Position de l'obje");
  glob->pobj_labels[4] = my_strdup("Rotation de l'objet");
  glob->pobj_labels[5] = my_strdup("Brillance");
  glob->pobj_labels[6] = my_strdup("Transparence");
  glob->pobj_labels[7] = my_strdup("Refraction");
  glob->pobj_labels[8] = my_strdup("Ck");
  glob->pobj_labels[9] = my_strdup("Point A");
  glob->pobj_labels[10] = my_strdup("Point B");
  glob->pobj_labels[11] = my_strdup("Point C");
  glob->pobj_labels[12] = my_strdup("Constante 1");
  glob->pobj_labels[13] = my_strdup("Constante 2");
  glob->pobj_labels[14] = my_strdup("mat_type");
  glob->pobj_labels[15] = my_strdup("Damier");
  glob->pobj_labels[16] = my_strdup("Réflexion floue");
  glob->pobj_labels[17] = my_strdup("Limite minimale");
  glob->pobj_labels[18] = my_strdup("Limite maximale");
  glob->pobj_labels[19] = my_strdup("Perturbation");
  glob->pobj_labels[20] = my_strdup("Rayon");
}

t_glob		*init_struct(void)
{
  t_glob	*glob;

  glob = xmalloc(sizeof(t_glob));
  glob->main = NULL;
  glob->filename = NULL;
  init_labels_name(glob);
  return (glob);
}
