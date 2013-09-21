/*
** change_sensitive.c for change_sensitive in /home/knocka_a/
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sat Apr 28 12:29:54 2012 antoine knockaert
** Last update Fri Jun  1 16:41:32 2012 antoine knockaert
*/

#include	"../edit.h"

void		change_sensitive(GtkWidget *widget, int usetype, gboolean value)
{
  gboolean	type;

  if (usetype)
    gtk_widget_set_sensitive(widget, value);
  else
    {
      type = gtk_widget_get_sensitive(widget);
      if (type == TRUE)
	type = FALSE;
      else
	type = TRUE;
      gtk_widget_set_sensitive(widget, type);
    }
}
