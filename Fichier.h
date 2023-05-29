/*Déclaration des bibliotheques */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Définition des constantes */
#define max 50
/* Définition des stuctures et listes chaînées */
//Structure d'un administrateur 
typedef struct{
	char *nom;
	int pass;
}admin;
//Structure d'un utilisateur
typedef struct{
	char *nom;
	char *prenom;
	int code;
}user;
//Structure d'un livre
typedef struct{
	int ID;
	char nom[max];
	char *author[max];
}book;

/*  Définition des fonctions "principales" de l'application */

// Cette fonction permet d'ajouter un livre
void Book_ajouter(book livre){
	// On déclare une variable qui nous permettra de travailler sur le fichier
	FILE *fp;
	// On ouvre le fichier contenant les livres (books.txt) en mode lecture
	fp=fopen("books.txt","ab+");	
	// On teste si l'ouverture s'est bien déroulée. Dans le cas échéant, on affichons un message d'erreur et on quitter
	if(fp==NULL){
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tIl y a une erreur !");
		exit(1);
	}
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Entrez l'identifiant du livre : "); 
	fflush(stdin); printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	scanf("%d",&livre.ID);  
	puts("\n\n\n\t\t\t\t\t\t\t\t\t Entrez le nom du livre : "); 
	fflush(stdin); printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
	scanf("%s",livre.nom); 
	printf("\n\n\n\t\t\t\t\t\t\t\t\t Entrez le nom de l'Auteur: "); 
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",livre.author);
	fprintf(fp,"\n%d\n%s\n%s",livre.ID,livre.nom,livre.author);
	// On ferme le fichier qui a été ouvert
	fclose(fp);
	printf("\n\n\n\n\t\t\t\tEntrez n'importe quelle touche pour reterner a le menu.....");

    system("cls");
}
	
//fonction pour tester si le fichier est vide
int testSiFichierVide(FILE* fichier)
{
    int caracterePremier = 0;
 
    //On lit le prmeier caractère du fichier
    caracterePremier = fgetc(fichier);
    if(caracterePremier==EOF)
    {
        return 1;//le fichier est vide donc on retourne 1
    }
    return 0;//le fichier n'est pas vide donc on retourne 0
}

//fonction d'affichage la listes du livres enregistre.
void Book_afiche(book livre){
	// On déclare une variable qui nous permettra de travailler sur le fichier
	FILE *fp;
	// On ouvre le fichier contenant les livres (books.txt) en mode lecture
	fp=fopen("books.txt","r");
	// On teste si l'ouverture s'est bien déroulée. Dans le cas échéant, on affichons un message d'erreur et on quitter
	if(fp==NULL){
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Il y a une erreur !");
		exit(1);
	}
	if(testSiFichierVide(fp)==1)
        {
            printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t La liste des livre est vide! \n"); //Si le fichier est vide
        }
    else{
    	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Les livres disponible sont :\n");
		while(!feof(fp))
		{
			fscanf(fp,"%d %s %s",&livre.ID,livre.nom,livre.author);
			printf("\n\n\n\t\t\t\t\t\t\t\t\t Livre ID: %d\n \n\n\n\t\t\t\t\t\t\t\t\t Livre nom: %s\n \n\n\n\t\t\t\t\t\t\t\t\t Auteur nom: %s\n",livre.ID,livre.nom,livre.author);
			printf("\n\t\t\t\t\t\t\t\t\t----------------------------");
		}
	}
	// On ferme le fichier qui a été ouvert
	fclose(fp);
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEntrez n'importe quelle touche pour reterner a le menu....."); //Pour roterner a le menu d'admin. 
    getch();
    system("cls");
}

// Cette fonction permet de rechercher un livre
void Book_rechercher(book livre){
	char *nomR;
	int tr=0;
	// On déclare une variable qui nous permettra de travailler sur le fichier
	FILE *fp;
	// On ouvre le fichier contenant les membres (membres.txt) en mode lecture
	fp=fopen("books.txt","rt");
	// On teste si l'ouverture s'est bien déroulée. Dans le cas échéant, on affichons un message d'erreur et on quitter
	if(fp==NULL){
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Il y a une erreur !");
		exit(1);
	}
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tDonner le nom du livre a rechercher: "); 
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); 
	scanf("%s",nomR);
	while(fscanf(fp,"%d\n %s\n %s\n",&livre.ID,livre.nom,livre.author)==3)
	{
		if(strcmp(livre.nom,nomR) == 0){ 
			printf("\n\n\n\t\t\t\t\t\t\t\t\tLivre Information :\n");
			fscanf(fp,"%d %s %s",&livre.ID,livre.nom,livre.author);
			printf("\n\n\n\t\t\t\t\t\t\t\t\tLivre ID: %d\n \n\n\n\t\t\t\t\t\t\t\t\tLivre nom: %s\n \n\n\n\t\t\t\t\t\t\t\t\tAuteur nom: %s\n",livre.ID,livre.nom,livre.author);
			tr=1;
		}	
	}
	// On ferme le fichier qui a été ouvert
	fclose(fp); 
	if(tr==0)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLe livre n'existe pas !\n");
			
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEntrez n'importe quelle touche pour reterner a le menu.....");
    getch();
    system("cls");			
}
// Cette fonction permet de supprimer un livre

void Book_supprimer(book livre){
	int codeR,tr=0;
	// On déclare deux variables qui nous permettra de travailler sur le fichier
	FILE *temp;
	FILE *fp;
	// On ouvre le fichier contenant les livres (books.txt) en mode lecture
	fp=fopen("books.txt","rt");
	// On teste si l'ouverture s'est bien déroulée. Dans le cas échéant, on affichons un message d'erreur et on quitter
	if(fp==NULL){
		printf("Il y a une erreur !");
		exit(1);
	}
	// On ouvre le fichier contenant une copie de fichier du livres (temp.txt) en mode ecriture
	temp=fopen("temp.txt","wt");
	// On teste si l'ouverture s'est bien déroulée. Dans le cas échéant, on affichons un message d'erreur et on quitter
	if(temp==NULL){
		printf("Il y a une erreur !");
		exit(1);
	}
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Donner le code de livre a supprimer: \n"); 
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%d",&codeR);
	while(fscanf(fp,"%d\n %s\n %s\n",&livre.ID,livre.nom,livre.author)==3)
	{
		if(livre.ID != codeR)
			fprintf(temp,"%d\n %s\n %s\n",livre.ID,livre.nom,livre.author);
		else 
			tr=1;
	}
	// On ferme les fichiers qui ont été ouvert
	fclose(fp); fclose(temp);
	//supprimer le fichie originale avec la fonction remove()
	remove("books.txt");
	//renomer le nouveau ficher
	rename("temp.txt","books.txt");
	if(tr==0)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Le livre n'existe pas !\n");
	else
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Le livre a supprime !\n");	
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Entrez n'importe quelle touche pour reterner a le menu.....");//pour reterner a le menu d'admin
    getch();
    system("cls");		
}
// Cette fonction permet de reserver un livre

void book_reserve(book livre){
	// On déclare deux variables qui nous permettra de travailler sur le fichier
	FILE *fp;
	FILE *reserve;
	char *nomR;
	int tr=0;
	user student;
	fp=fopen("books.txt","rt");
	// On teste si l'ouverture s'est bien déroulée. Dans le cas échéant, on affichons un message d'erreur et on quitter
	if(fp==NULL){
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Il y a une erreur !");
		exit(1);
	}
	reserve=fopen("reserve.txt","ab+");
	// On teste si l'ouverture s'est bien déroulée. Dans le cas échéant, on affichons un message d'erreur
	if(reserve==NULL){
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Il y a une erreur !");
		exit(1);
	}
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Donner le nom du livre a reserver: "); scanf("%s",nomR);
	while(fscanf(fp,"%d\n %s\n %s\n",&livre.ID,livre.nom,livre.author)==3)
	{
		if(strcmp(livre.nom,nomR) == 0){ 
			fprintf(reserve," %s\n",nomR);
			printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nom :\n");
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&student.nom);
			printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre prenom :\n");
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&student.prenom);
			printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nombre appogee:\n");
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%d",&student.code);
			fprintf(reserve,"%s\n %s\n %d\n",student.nom,student.prenom,student.code);
			tr=1;
		}
	}
	fclose(fp); fclose(reserve);
	if(tr==0)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Le livre n'existe pas !\n");
	else
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Le livre a reserver !\n");	
	
}

/* **********************  les fonction de  menu d'etudaint    ************************/
//Listes chaînées d'un etudient
typedef struct liste{
	char name[20];
	char last_name[20];
	int nb;
	struct liste *next;
}liste;
 /*  Définition des fonction de traitement d'etudiants */
 
 //Fonction permet d'ajouter un etudiant
liste* ajouter(liste* L){
	liste* nouveau=malloc(sizeof(liste));
	if(L==NULL)
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez les information d'etudaint\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t Entrer etudiant nom: ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&nouveau->name);
	printf("\n\n\n\t\t\t\t\t\t\t\t\t Entrer etudiant prenom: ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&nouveau->last_name);
	printf("\n\n\n\t\t\t\t\t\t\t\t\t Saisissez le nombre appogee d'etudiant:");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%d",&nouveau->nb);
	nouveau->next=L;
}

 //Fonction permet d'afficher la listes des etudiants
void affichage(liste *L){
	if(L==NULL)
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLa liste des etudiants est vide!!\n");
	else{
		printf("\n\n\n\t\t\t\t\t\t\t\t\tLa liste des etudiants est:\n");
		while(L!=NULL){
			printf("\n\n\n\t\t\t\t\t\t\t\t\t Le Code d'etudiant: %d",L->nb);	
			printf("\n\n\n\t\t\t\t\t\t\t\t\t Le Nom d'etudiant: %s",L->name);
			printf("\n\n\n\t\t\t\t\t\t\t\t\t Le Prenom d'etudiant: %s",L->last_name);
			printf("\n\n\n\t\t\t\t\t\t\t\t\t----------------------------");
			L=L->next;
		}
	}
}

 //Fonction permet de supprimer un etudiant
liste* supprimer(liste *L,int code){
	liste *temp,*p;
	int tr=0;
	if(L!=NULL){
		if(L->nb==code){
		 p=L;
		 L=L->next;
		 free(p);
		}
		else{
			temp=L;
				while(temp->next!=NULL && temp->next->nb!=code){
					temp=temp->next;
				}
				if(temp->next!=NULL){
					p=temp->next;
					temp->next=temp->next->next;
					free(p);
					tr=1;
				}
		}
		if(tr=1)
			printf("\n\n\n\t\t\t\t\t\t\t\t\t l'etudiant a supprime!!!");
		else
			printf("\n\n\n\t\t\t\t\t\t\t\t\t N'existe pas!!!");
	}
	return L;
}

/* **********************   Menu d'etudiant    ************************/
void menue_student(){
	liste *L=NULL;
	int i,choix=0,code;
	do {
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t************Menu d'etudiants************\n\n");
		printf("\n\t\t\t\t\t\t\t\t\t 1.Afficher La Liste Des Etudiants\n\t\t\t\t\t\t\t\t\t 2.Ajouter Un Etudiant.\n\t\t\t\t\t\t\t\t\t 3.Supprimer Un Etudiant");
		printf("\n\t\t\t\t\t\t\t\t\t 4.Retourne a le menu d'admin");
		printf("\n\t\t\t\t\t\t\t\t\t 5.Fermer L'Application");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t****************************************\n\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tEntrez votre choix:");
		scanf("%d",&choix);
		system("cls");
		switch(choix){
			case 1:{	affichage(L);	break;	}
			case 2:{    L=ajouter(L);   break;	}
			case 3:{	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEntrer le code d'etudiant a supprimer:");
						scanf("%d",&code);
						L=supprimer(L, code);
					break;	}
			case 4: { menu_admin();	break;	}
			case 5:{
				printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMerci !\n\n\n\n\n\n\n\n");
				exit(0);
				break;
			}
			default:{ printf("\nInvalide");	break;	}
		}
	}while(choix!=0);
}

/* **********************   Menu d'admin    ************************/
void menu_admin(){
		book livre;
		int choix;
		choix=9;
	do{
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t************Main Menu************\n\n");
		printf("\n\t\t\t\t\t\t\t\t\t1- Afficher La Liste Des Livres\n");
		printf("\n\t\t\t\t\t\t\t\t\t2- Rechercher Un Livre\n");
		printf("\n\t\t\t\t\t\t\t\t\t3- Ajouter Un Livre\n");
		printf("\n\t\t\t\t\t\t\t\t\t4- Supprimer Un Livre\n");
		printf("\n\t\t\t\t\t\t\t\t\t5- Afficher Le Menu Etudiants\n"); 
		printf("\n\t\t\t\t\t\t\t\t\t6- Retourne a le menu principale\n");
		printf("\n\t\t\t\t\t\t\t\t\t7- Fermer L'Application\n");
		printf("\n\n\t\t\t\t\t\t\t\t\t**********************************\n\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tEntrez votre choix:");
		scanf("%d",&choix);
		system("cls");
		switch(choix){
			case 1: { Book_afiche(livre);	    break;}
			case 2: { Book_rechercher(livre);	break;}
			case 3: { Book_ajouter(livre);      break;}
			case 4: { Book_supprimer(livre);	break;}
			case 5: { menue_student();	break;	}
			case 6: { menue_return();	break;	}
			case 7:{
				printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMerci !\n\n\n\n\n\n\n\n");
				exit(0);
				break;
			}
			default: {printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLe Le choix est incorrect !\n\n");	break;}
		}
		getch();
		system("cls");
	}while(choix != 9);	
}

/* **********************   Menu d'utilisateur    ************************/
void menu_etudient(){
		int choix;
		book livre;
		choix=4;
	do{
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t************Main Menu************\n\n");
		printf("\n\t\t\t\t\t\t\t\t\t1- Afficher La Liste Des Livres\n");
		printf("\n\t\t\t\t\t\t\t\t\t2- Trouver Un Livre\n");
		printf("\n\t\t\t\t\t\t\t\t\t3- Reserver Un Livre\n");
		printf("\n\t\t\t\t\t\t\t\t\t4- Retourne a le menu principale\n");
		printf("\n\t\t\t\t\t\t\t\t\t5- Fermer L'Application\n");
		printf("\n\n\t\t\t\t\t\t\t\t\t**********************************\n\n");
		printf("\n\n\t\t\t\t\t\t\t\t\tEntrez votre choix:");
		scanf("%d",&choix);
		system("cls");
		switch(choix){
			case 1: { Book_afiche(livre);	    break;}
			case 2: { Book_rechercher(livre);	break;}
			case 3: { book_reserve(livre);	    break;}
			case 4: { menue_return();		break;}
			case 5:{ 
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMerci !\n\n\n\n\n\n\n\n");
					exit(0);
					break;
			}	
			default: {printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLe Le choix est incorrect !\n\n");	break;}
		}
		getch();
		system("cls");
	}while(choix != 5);
}

// Cette procedure affiche juste l'entete de notre application
void BienvenueMessage(){
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t##################################################################################\n");
    printf("\n\t\t\t\t\t\t\t\t############                                                          ############");
    printf("\n\t\t\t\t\t\t\t\t############     Projet de systeme de gestion de bibliotheque en C    ############");
    printf("\n\t\t\t\t\t\t\t\t############                                                          ############\n");
    printf("\n\t\t\t\t\t\t\t\t##################################################################################");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   *************************************************************\n");
	printf("\n\t\t\t\t\t\t\t\t\t   *******************     Bienvenue     ***********************\n");
	printf("\t\t\t\t\t\t\t\t\t   *******************       a la        ***********************\n");
	printf("\t\t\t\t\t\t\t\t\t   *******************    bibliotheque   ***********************\n");
	printf("\n\t\t\t\t\t\t\t\t\t   *************************************************************\n");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   Entrez n'importe quelle touche pour continuer.....");
    getch();
    system("cls");
}

/* Cette fonction permet d'afficher le menu de l'application "avec" le missage de bienvenue et de sélectionner une option */
void menue_principal(void){
    int choix;
   	user student;
	admin admin;
	int check=1;
	BienvenueMessage(); //fonction affiche le missage de bienveneu

	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t 1-Espace d'administration. \n\n\n\n\n\t\t\t\t\t\t\t\t\t 2-Espace d'etudiant. \n\n\n\n\n\t\t\t\t\t\t\t\t\t 3-Quitter.\n\n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t Entrer votre choix  =>  "); scanf("%d",&choix);
	system("cls"); //Fonction permet d'efacer le console

    if(choix==1)
	while(check){ //while(check ==1)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nom d'utilisateur:\n");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&admin.nom);
		printf("\n\n\n\t\t\t\t\t\t\t\t\t Tapez votre mot de passe:\n");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%d",&admin.pass);
		if(admin.pass!=1234 ) { 
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tMot de passe  invalide!");
			check = 1;
			continue;
		}
		check = 0;
		system("cls");
		menu_admin();
	}	
	
	else	if(choix==2)
				while(check){ //while(check ==1)
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nom :\n");
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&student.nom);
					printf("\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre prenom :\n");
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&student.prenom);
					printf("\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nombre appogee:\n");
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%d",&student.code);
					if(student.code!=2000) { 
						printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAppogee incorect!");
						check = 1;
						continue;
					}
					check = 0;
					system("cls");
					menu_etudient();
				}	
				else if(choix==3)
						{
							printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMerci !\n\n\n\n\n\n\n\n");
							exit(0);
						}	
					else
						{
							printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLe choix est invalide!\n\n");
						}	
}

/* Cette fonction permet d'afficher le menu de l'application "snas" le missage de bienvenue et de sélectionner une option */
void menue_return(void){
     int choix;
   	user student;
	admin admin;
	int check=1;

	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t 1-Espace d'administration. \n\n\n\n\n\t\t\t\t\t\t\t\t\t 2-Espace d'etudiant. \n\n\n\n\n\t\t\t\t\t\t\t\t\t 3-Quitter.\n\n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t Entrer votre choix  =>  "); scanf("%d",&choix);
	system("cls"); //Fonction permet d'efacer le console

    if(choix==1)
	while(check){ //while(check ==1)
		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nom d'utilisateur:\n");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&admin.nom);
		printf("\n\n\n\t\t\t\t\t\t\t\t\t Tapez votre mot de passe:\n");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%d",&admin.pass);
		if(admin.pass!=1234 ) { 
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tMot de passe  invalide!");
			check = 1;
			continue;
		}
		check = 0;
		system("cls");
		menu_admin();
	}	
	
	else	if(choix==2)
				while(check){ //while(check ==1)
					printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nom :\n");
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&student.nom);
					printf("\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre prenom :\n");
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%s",&student.prenom);
					printf("\n\n\n\t\t\t\t\t\t\t\t\t Saisissez votre nombre appogee:\n");
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"); scanf("%d",&student.code);
					if(student.code!=2000) { 
						printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAppogee incorect!");
						check = 1;
						continue;
					}
					check = 0;
					system("cls");
					menu_etudient();
				}	
			else if(choix==3)
					{
						printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMerci !\n\n\n\n\n\n\n\n");
						exit(0);
					}	
					else
					{
						printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tLe choix est invalide!\n\n");
					}	
}

