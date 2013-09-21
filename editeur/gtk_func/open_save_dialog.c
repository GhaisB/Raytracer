/*
** open_save_dialog.c for open_save_dialog in /home/knocka_a/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Sun Apr 29 22:38:39 2012 antoine knockaert
** Last update Sat Jun  2 19:13:38 2012 antoine knockaert
*/

#include	"../edit.h"

char		*launch_open_save_dialog(GtkWidget *dialog)
{
  char		*filename;
  char		*ret;

  if (gtk_dialog_run(GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
    {
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      ret = my_strdup(filename);
      g_free(filename);
    }
  else
    ret = NULL;
  gtk_widget_destroy(dialog);
  return (ret);
}

/*
** Filename :
** NULL : Open Dialog // char * : Save Dialog
*/
char		*open_save_dialog(char *title, GtkWidget *parent,
				  GtkFileChooserAction action, char *filename)
{
  GtkWidget	*dialog;
  char		*text;

  if (action == GTK_FILE_CHOOSER_ACTION_SAVE)
    text = TXT_BUTTON_SAVE;
  else
    text = TXT_BUTTON_OPEN;
  dialog = gtk_file_chooser_dialog_new(title,
				       GTK_WINDOW(parent),
				       action,
				       TXT_BUTTON_CANCEL, GTK_RESPONSE_CANCEL,
				       text, GTK_RESPONSE_ACCEPT,
				       NULL);
  gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog),
						 TRUE);
  if (!filename && action == GTK_FILE_CHOOSER_ACTION_SAVE)
    gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), TXT_NEW_FILE);
  else if (action == GTK_FILE_CHOOSER_ACTION_SAVE)
    gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(dialog), filename);
  return (launch_open_save_dialog(dialog));
}
