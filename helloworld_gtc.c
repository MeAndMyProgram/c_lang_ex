#include <gtk/gtk.h>

int main(int argc, char *argv[])
{

  GtkWiget*window;
  /*иницианализация GTK+*/
  gtk init(&argc, &argv);
  /*главное меню*/
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL):
  /*Заголовок*/

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show (window);
  gtk_main ();
  return 0;
}
