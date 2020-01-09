// My Application
//
// By (Your name)

// Libraries
#include <gtk/gtk.h> // GTK Library
#include <stdio.h> // C IO Library (Not needed)
#include <regex.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>




// Variables
GtkWidget *window; // Window
GtkLabel *mylabel , *Sorry , *error , *errorMail , *filename , *resultat; // Label
GtkEntry *TextBox;
GtkButton *but1 , *exitdialog , *show;
GtkProgressBar *progress;
GtkDialog *dialog1;
GtkWidget *file ;


                      

// Main function
int main(int argc, char *argv[])
{
	GtkBuilder *builder ; // GTK Builder variable
	gtk_init(&argc, &argv); // Start GTK

	builder = gtk_builder_new(); // Create GTK UI Builder
	gtk_builder_add_from_file(builder, "projet1.glade", NULL); // Load our UI file

	// Assign the Variables
	window = GTK_WIDGET(gtk_builder_get_object(builder, "MyWindow")); // Load our window named MyWindow
	mylabel = GTK_LABEL(gtk_builder_get_object(builder, "MyLabel")); // Load our label named MyLabel
	Sorry = GTK_LABEL(gtk_builder_get_object(builder, "MyLabel1")); // Load our label named MyLabel1
	TextBox = GTK_ENTRY(gtk_builder_get_object(builder, "mail"));   //Load our TextBox
	but1 = GTK_BUTTON(gtk_builder_get_object(builder , "mail_controll"));
	error = GTK_LABEL(gtk_builder_get_object(builder, "Error_handel")); // Load our label named MyLabel
	errorMail = GTK_LABEL(gtk_builder_get_object(builder, "mailValidation")); // Load our label named MyLabel
	filename = GTK_LABEL(gtk_builder_get_object(builder, "filename"));
	progress = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "progress_bar")); // Load our label named MyLabel
	dialog1 = GTK_DIALOG(gtk_builder_get_object(builder, "diError"));
	show = GTK_BUTTON(gtk_builder_get_object(builder , "showmodal"));
	file = GTK_WIDGET(gtk_builder_get_object(builder, "file"));
	resultat = GTK_LABEL(gtk_builder_get_object(builder, "result")); //Resultat
	

	// Essential for a GTK based program
	gtk_builder_connect_signals(builder, NULL); 
	g_object_unref(builder);
	gtk_widget_set_size_request(window,400,300);
	gtk_widget_show_all(window); 
	gtk_main(); 

	return 0; 
}




//FUNCTION LOAD FILE

void load_file(GtkFileChooserButton *f){
	FILE *file , *file2;
	//int i;
	//double a=1.5, b=2.5;
	//double tab[2]; 
	char ch[4000] = "" ;
	char ch1[4000] = "" ;
	int somme = 0;
	//int x = 0 ;
	//char buff[4000] = "" ;
	sprintf(ch,"file name = %s\n", gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f)) );
		gtk_label_set_text(filename, "Valide");
			file2 = fopen("spam/samine.txt","w");	
			file = fopen(gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f)), "r");
		if (file == NULL)
		{
			perror("fopen()");
			
		}
		else {
			 perror("fopen()");
			/* 
			 fprintf(file, "%lf\n" ,a) ;
			 fprintf(file,"%lf\n",b);
			 */
			 
			 while(fgets(ch1,50,file) != NULL){
						
						
						
						
						
						fputs(ch1,file2);
						printf("%s",ch1 );
						
						
																	
						}
						
						fgets(ch , 50 , file);
							for(int i = 0 ; i <= strlen(ch1) ; i++ ) {				
								if (((ch[i-1]) == 99) || ((ch[i-1]) == 98) || ((ch[i-1]) == 97) || ((ch[i-1]) == 95) || ((ch[i-1]) == 101)){
								printf("existe %c la position = %d la somme = %d  \n" , (ch1[i-1]),i,somme);
								somme = somme + 1;									
							}	
					
									}
									
									if (somme < 5) {
										//printf(" votre mail nest pas valide car %d\n",somme);
										gtk_label_set_text(resultat, " Spam! Be careful");
										//execl("/bin/cp","cp","amine.txt","spam/",NULL);
										//printf("pk");	
										rename("spam/samine.txt","spam/spam.txt"); 
										remove (gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f)));
										
										}
										else{
											//printf("votre mail est valide continuer :) car %d\n" , somme);
											gtk_label_set_text(resultat, " Not a Spam Enjoy !");
											}
						
						
						
						
						
				 	 
				 }
				 		 
			 fclose(file);
			 fclose(file2);
			 
			 /*
			 for(i=0;i<10;i++)
			 fscanf(file,"%s\n",ch1+i);
		
			for(i=0;i<10;i++) 
			printf("%s\n",ch1);
		*/
		}
    
    
		
		
	



/*
bool spam_filter(GtkFileChooserButton *f){
	FILE *file ;
	int somme;
	
	char ch1[4000] = "" ;
	
	bool x = false;
	
	file = fopen(gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f)), "r");
		
		if (file == NULL)
    {
        perror("fopen()");
        bool x = true;
    }
    else {
			 perror("fopen()");
			 fgets(ch1,50,file);
					for(int i = 0 ; i <= strlen(ch1) ; i++ ) {				
						if (((ch1[i-1]) == 99) || ((ch1[i-1]) == 98) || ((ch1[i-1]) == 97) || ((ch1[i-1]) == 95) || ((ch1[i-1]) == 101)){
								printf("existe %c la position = %d la somme = %d  \n" , (ch1[i-1]),i,somme);
								somme = somme + 1;									
				}	
					
					}
			
		}
		if(x == true){
			
				return x ;
			}
		else{
			return x ;
		}
  
  
	
	
	
	}

*/
//fUNCTION TO SHOW DIALOG
/*
static void open_dialog(GtkWidget* button, gpointer window)
{
        GtkWidget *dialog, *label, *image, *hbox;
        dialog = gtk_dialog_new_with_buttons("Nonmodal Dialog", GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_STOCK_OK, GTK_RESPONSE_OK, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, NULL);  
        gtk_widget_show_all(dialog);
        g_signal_connect(dialog, "response", G_CALLBACK(window), dialog);
}
	*/	
// Function to exit our app
void exit_app()
{
	printf("Thanks For using our app \n"); 
	gtk_main_quit(); 
}

//Function to validate email	
	void ValidateEmail(){
			
		// gboolean find;
		 int somme = 0;
		 char texte[50] ;
		 
		 
		for(int i = 1 ; i <= strlen(gtk_entry_get_text(TextBox))	; i++){
			//chercher le @ et le point
				//printf(" Le %d caractere %c \n", i, (gtk_entry_get_text(TextBox)[i-1]));			
				
			
				if (((gtk_entry_get_text(TextBox)[i-1]) == 64) || ((gtk_entry_get_text(TextBox)[i-1]) == 46)){
						printf("Valid %c la position = %d la somme = %d  \n" , (gtk_entry_get_text(TextBox)[i-1]),i,somme);
						somme = somme + 1;
						
									
				}				
					else
					{
						printf("pas valide %c \n" , (gtk_entry_get_text(TextBox)[i-1]));
						
					}
		}
		
		if (somme < 2) {
			printf(" votre mail nest pas valide car %d\n",somme);
			gtk_label_set_text(errorMail, " votre mail nest pas valide");
			//execl("/bin/cp","cp","amine.txt","spam/",NULL);
			//printf("pk");	
			
			}
			else{
				printf("votre mail est valide continuer :) car %d\n" , somme);
				gtk_label_set_text(errorMail, " votre mail est valide continuez :)");
				}
		
						
	}


//Function to test if empty
void controlEmpty(){
	if(strlen(gtk_entry_get_text(TextBox)) == 0){
				char text[] = "Saisie votre mail svp";				
				gtk_label_set_text(error,  (const gchar*)text);
		}
		
				ValidateEmail();
				
	}


// Fonction Check
void button_clicked(GtkEntry *mail)
{
	char texte[50];
	
	if(strlen(gtk_entry_get_text(TextBox)) == 0){
				controlEmpty();
		}
	else {			
	sprintf(texte , "Votre Mail = %s" , gtk_entry_get_text(TextBox));
		ValidateEmail()	;
	printf("Button clicked \n");
	printf("Message  %s \n",texte);
	//gtk_label_set_text(Sorry, (const gchar*) texte);
}
	
	
	
}


 
