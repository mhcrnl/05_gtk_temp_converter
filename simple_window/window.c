#include <gtk/gtk.h>
#include <stdio.h>

GtkWidget *window;
//GtkLabel *mylabel;
GtkButton *btClose;
GtkEntry  *eFahr;
GtkEntry  *eCels;
GtkButton *bCalc;
GtkButton *bClear;
GtkButton *bHelp;
GtkWidget *dialog;

int main(int argc, char *argv[]) {
		
	GtkBuilder *builder;
	gtk_init(&argc, &argv);
	
	
	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "window.glade", NULL);
	
	window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow"));
	//mylabel = GTK_LABEL(gtk_builder_get_object(builder, "MyLabel"));
	btClose = GTK_BUTTON(gtk_builder_get_object(builder, "btClose"));
	eFahr	= GTK_ENTRY (gtk_builder_get_object(builder, "eFahr"));
	eCels	= GTK_ENTRY (gtk_builder_get_object(builder, "eCels"));
	
	bCalc 	= GTK_BUTTON(gtk_builder_get_object(builder, "bCalc"));
	bClear	= GTK_BUTTON(gtk_builder_get_object(builder, "bClear"));
	bHelp	= GTK_BUTTON(gtk_builder_get_object(builder, "bHelp"));
	
	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);
	
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
	
}
/*
void help(){
	GtkDialogFlags flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;
	dialog = gtk_dialog_new_with_buttons("My dialog", window,
			flags,_("_OK"), GTK_RESPONSE_ACCEPT,
			_("_Cancel"), GTK_RESPONCE_REJECT, NULL);
}
*/
void clear(){
	gtk_entry_set_text(GTK_ENTRY(eFahr), " ");
	gtk_entry_set_text(GTK_ENTRY(eCels), " ");
}

void calculate(){
	printf("Calculeaza gradele celsius.");
	//gchar *fahr_text;
	gchar *fahr_text = gtk_entry_get_text(GTK_ENTRY(eFahr));
	int celsius = (atoi(fahr_text)-32) * 5/9;
	gchar *cels = g_strdup_printf("%d", celsius);
	//int i = 0;
	//i = atoi(fahr_text);
	//printf("%d", i);
	gtk_entry_set_text(GTK_ENTRY(eCels), cels);

}

void exit_app(){
	
	printf("Exit app");
	gtk_main_quit();
}
/*
void button_clicked(){
	
	printf("Button clicked!");
	gtk_label_set_text(mylabel, "Hello, World!");
}
*/
