/*
** valide_obj.c for valide_obj in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun May 27 17:55:08 2012 antoine knockaert
** Last update Sun Jun  3 20:35:03 2012 antoine knockaert
*/

#include	"../edit.h"

static	void	recup_value(double *value, t_glob *glob)
{
  int		i;

  i = 3;
  while (i <= 36)
    {
      if (i != 26)
	value[i - 2] =
	  atof((char *) gtk_entry_get_text(GTK_ENTRY(glob->pobj->entry[i])));
      else
      	value[i - 2] = (double)
	  gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(glob->pobj->entry[i]));
      i++;
    }
}

char		*gere_special_value(t_glob *glob, double *value)
{
  char		*str;
  GdkColor	color;

  value[0] = 0;
  gtk_color_button_get_color(GTK_COLOR_BUTTON(glob->pobj->entry[2]), &color);
  str = gdk_color_to_string(&color);
  printf("%s\n", str);
  str =
    gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(glob->pobj->entry[1]
							  ));
  if (str == NULL)
    printf("Warning: Object type not selected. Object not added.\n");
  return (str);
}

void		destroy_window(GtkWidget *widget, gpointer data)
{
  data = data;
  gtk_widget_destroy(widget);
}

void		valide_obj(GtkWidget *widget, gpointer data)
{
  t_glob	*glob;
  double	value[NB_PARAM + 5];
  t_sph		*obj;
  char		*str;

  widget = widget;
  glob = (t_glob *) data;
  if ((str = gere_special_value(glob, value)) != NULL)
    {
      obj = xmalloc(sizeof(t_sph));
      obj->nt = NULL;
      recup_value(value, glob);
      obj->name = str;
      add_params_first(obj, value);
      add_to_list_obj_edit(glob, obj);
      write_obj_file(glob);
      gtk_widget_destroy(glob->pobj->pwindow);
    }
}
