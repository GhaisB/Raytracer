/*
** create_label.c for create_label in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri Apr 27 22:05:57 2012 antoine knockaert
** Last update Sat Jun  2 19:12:20 2012 antoine knockaert
*/

#include	"../edit.h"

/*
** Justification types :
** GTK_JUSTIFY_LEFT / _RIGHT / _CENTER / _FILL (Justified text)
*/
GtkWidget	*create_label(char *str, GtkJustification jtype,
			      GtkWidget *container)
{
  GtkWidget	*lbl;
  gchar		*str2;

  lbl = NULL;
  if (str)
    {
      str2 = g_locale_to_utf8(str, -1, NULL, NULL, NULL);
      lbl = gtk_label_new(str2);
      g_free(str2);
      if (lbl)
	{
	  gtk_label_set_justify(GTK_LABEL(lbl), jtype);
	  gtk_label_set_use_markup(GTK_LABEL(lbl), TRUE);
	  if (container)
	    gtk_container_add(GTK_CONTAINER(container), lbl);
	}
      else
	my_putstr("Gtk: Error while creating label\n");
    }
  return (lbl);
}
