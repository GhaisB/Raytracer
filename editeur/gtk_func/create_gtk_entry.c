/*
** gtk_entry.c for ch in /home/knocka_a/repositories/rt/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Fri May 25 10:01:05 2012 antoine knockaert
** Last update Fri May 25 10:09:25 2012 antoine knockaert
*/

#include	"../edit.h"

GtkWidget	*create_gtk_entry(int max_length, char *value)
{
  GtkWidget	*entry;

  entry = gtk_entry_new_with_max_length(max_length);
  if (entry)
    {
      gtk_entry_set_width_chars(GTK_ENTRY(entry), max_length);
      gtk_entry_set_text(GTK_ENTRY(entry), value);
    }
  return (entry);
}
