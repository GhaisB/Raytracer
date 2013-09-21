/*
** edit.h for edit in /home/knocka_a/lem-in/editeur
** 
** Made by antoine knockaert
** Login   <knocka_a@epitech.net>
** 
** Started on  Thu Mar 29 09:40:20 2012 antoine knockaert
** Last update Sun Jun  3 11:02:58 2012 antoine knockaert
*/

#ifndef		__EDIT_H__
#define		__EDIT_H__

#include	<gtk-2.0/gtk/gtk.h>
#include	<gtk-2.0/gdk/gdk.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"../rt.h"

/*
** Structures
*/

#define		START_PARAMS	1

typedef struct	s_main
{
  GtkWidget	*pwindow;
  GtkWidget	*button[6];
  GtkWidget	*lbl[4];
  GtkWidget	*vbox[3];
  GtkWidget	*hbox[3];
} t_main;

typedef struct	s_pobj
{
  GtkWidget	*pwindow;
  GtkWidget	*frame[2];
  GtkWidget	*vbox[3];
  GtkWidget	*hbox[10];
  GtkWidget	*lbl[21];
  GtkWidget	*entry[37];
  GtkWidget	*button[2];
  double	params[NB_PARAM];
} t_pobj;

typedef struct	s_glob
{
  char		*filename;
  t_sph		*obj_a;
  t_cod		*oeil;
  t_mlx		*init;
  t_main	*main;
  t_pobj	*pobj;
  char		*pobj_labels[NB_PARAM + START_PARAMS];
} t_glob;

/*
** Others Prototypes
*/
char		*launch_open_save_dialog(GtkWidget *dialog);
void		valide_obj(GtkWidget *widget, gpointer data);
void		preview(GtkWidget *widget, gpointer data);
void		pobj_window(GtkWidget *widget, gpointer data);
void		new_file(GtkWidget *widget, gpointer data);
void		open_file(GtkWidget *widget, gpointer data);
t_glob		*init_struct();
void		link_main_widget(t_main *main);
void		link_pobj_widget(t_pobj *pobj);
void		main_window(t_glob *glob);
void		add_to_list_obj_edit(t_glob *glob, t_sph *maillon);
void		write_obj_file(t_glob *glob);
void		write_obj(FILE *file, t_glob *glob);
void		write_base(FILE *file, t_glob *glob);
void		others_options(t_pobj *pobj);
void		base_options(t_pobj *pobj);
void		destroy_window(GtkWidget *widget, gpointer data);

/*
** GtkFunc Prototypes
*/
GtkWidget	*create_gtk_entry(int max_size, char *value);
void		update_main(t_glob *glob, t_main *main);
GtkWidget	*create_button(int type, char *str);
GtkWidget	*create_label(char *str, GtkJustification jtype,
			      GtkWidget *container);
void		create_modal(char *title, char *text, GtkWindow *parent);
GtkWidget	*create_window(char *title, GtkWindowType type,
			       GtkWindowPosition position, int *size);
void		change_sensitive(GtkWidget *widget, int usetype,
				 gboolean value);
char		*open_save_dialog(char *title, GtkWidget *parent,
				  GtkFileChooserAction action, char *filename);
void		gtk_combo_append(GtkComboBoxText *entry, char *str);

/*
** Lib Prototypes
*/
void		my_putstr(char *str);
int		my_strlen(char *str);
int		xread(int fd, void *buf, size_t count);
int		xopen(const char *pathname, int flags);
int		xclose(int fd);
void		*xmalloc(int size);
char		*my_strdup(char *str);

/*
** Defines
*/
#define	WIDTH_MAIN_WINDOW	600
#define HEIGHT_MAIN_WINDOW	600
#define	TITLE_MAIN_WINDOW	"Raytracer"
#define	LBL_TITLE_MAIN_WINDOW	"Editeur de fichier raytracer"
#define	LBL_FILE		"Fichier actuellement ouvert : "
#define	LBL_NO_FILE		"Aucun fichier ouvert"
#define LBL_COPY		"Raytracer - Promotion 2016"
#define	BUTTON_MAIN_CREATE_OBJ	"_Créer un objet"
#define	BUTTON_MAIN_EDIT_OBJ	"_Modifier un objet"
#define	BUTTON_MAIN_CREATE_LMP	"Créer une _lampe"
#define	BUTTON_MAIN_EDIT_LMP	"Modifier une la_mpe"
#define	BUTTON_MAIN_PREVIEW	"_Preview"
#define	BUTTON_MAIN_CLUSTER	"_Cluster"
#define	BUTTON_MAIN_NEW_FILE	"_Nouveau fichier"
#define	BUTTON_MAIN_OPEN_FILE	"Ouvrir un _fichier"
#define	TXT_BUTTON_CANCEL	"Annuler"
#define	TXT_BUTTON_SAVE		"Sauvegarder"
#define	TXT_BUTTON_OPEN		"Ouvrir"
#define	TXT_NEW_FILE		"Untitled.rt"

#define TXT_CHOOSE_FILE		"Choisissez un fichier a ouvrir"
#define	TXT_INVALID_FILE	"Fichier non valide."

#define	WIDTH_OBJ_WINDOW	900
#define	HEIGHT_OBJ_WINDOW	900
#define	TITLE_OBJ_WINDOW	"Créer un nouvel objet"
#define TXT_NEW_ESSENTIALS	"Params. Obligatoire"
#define	TXT_NEW_OPTIONS		"Params. Optionels"

#endif
