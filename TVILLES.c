#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define BIG_MAX 100
#define MAX 25
#include "TPAYS.h"
#include "TPERMIS.h"
#include "TETATCIVILE.h"
#include "TVILLES.h"
#include "TCANDIDATS.h"
#include "TEXPERIENCES.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"

struct ville
{
    int IdVille;
	char Ville[50];
	char pays[50];
};struct ville V ;

void AjouterVille()
{
	FILE *Fp;
	Fp=fopen("TVILLES.txt","a");
	test_file_opening(Fp);
	printf("\tSaisir le Nom du ville :  ");
	scanf("%s",&V.Ville);
	fflush(stdin);
	printf("\tSaisir le pays du cette ville :  ");
	scanf("%s",&V.pays);
	fflush(stdin);
	if(RechercheVilleParNom(V.Ville)==1)
    {
        printf("\tCette ville deja existe\n");
        return;
    }

	V.IdVille=getIDVille("TVILLES.txt")+1;
	fflush(stdin);
	fprintf(Fp,"%d ; %s ; %s \n",V.IdVille,V.Ville,V.pays);
	printf("\n\nla ville %u %s %s est ajoute au fichier TVILLES.txt avec success \n",V.IdVille,V.Ville,V.pays);
	fclose(Fp);
}

void RechercheVille()
{
	int NumR,j=0;
	printf("\n\tEntrez le numero du ville a rechercher :");
	scanf("%d",&NumR);
	FILE *Fp;
	Fp=fopen("TVILLES.txt","r");
	do
	{
	fscanf(Fp,"%d ; %s ; %s \n",&V.IdVille,&V.Ville,&V.pays);
	if(NumR==V.IdVille)
	{
	        printf("\n\t===============INFORMATION SUR LA ville %d  ================\n\t ",V.IdVille);
	        printf("\n\tLa ville \t\t\t:%s\n\tpays \t\t\t:%s  ",V.Ville,V.pays);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fp));
	fclose(Fp);
	if(j==0){
	    printf("\n\tDesole! Cette ville n'existe pas\n");
	}
}
void AfficherVilleC(int NumR)
{
	FILE *Fp;
	Fp=fopen("TVILLES.txt","r");
	do
	{
	fscanf(Fp,"%d ; %s ; %s \n",&V.IdVille,&V.Ville,&V.pays);
	if(NumR==V.IdVille)
	{
	        printf("\n\tLa Ville \t\t\t:%s",V.Ville);
	        printf("\n\tLe Pays  \t\t\t:%s",V.pays);
	}
	}while(!feof(Fp));
	fclose(Fp);
}

void SupprimerVille()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez Le numero de la ville a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechVille(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fpt,*Fp;
	        Fp=fopen("TVILLES.txt","r");
	        test_file_opening(Fp);
	        Fpt=fopen("VILLES.txt","a");
	        test_file_opening(Fpt);
	        do
	        {
	         fscanf(Fp,"%d ; %s ; %s \n",&V.IdVille,&V.Ville,&V.pays);
	         if(NumRech!=V.IdVille)
	         {
	         fprintf(Fpt,"%d ; %s ; %s \n",V.IdVille,V.Ville,V.pays);
	         }
	        }while(!feof(Fp));
	        fclose(Fpt);
	        fclose(Fp);
	        remove("TVILLES.txt");
	        rename("VILLES.txt","TVILLES.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tCe numero de la ville n'existe pas");
	}
}

void ModifierVille(){

	FILE *Fp,*Fpt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez Le numero de la ville a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechVille(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fp=fopen("TVILLES.txt","r");
	    test_file_opening(Fp);
	    Fpt=fopen("VILLES.txt","a");
	    test_file_opening(Fpt);
	 do
	 {
	fscanf(Fp,"%d ; %s ; %s \n",&V.IdVille,&V.Ville,&V.pays);
	if(num==V.IdVille)
	{
	V.IdVille=num;

	printf("\n\tEntrez La nouvelle ville :");
	gets(V.Ville);
    if(RechercheVilleParNom(V.Ville)==1)
    {
        printf("\tCette ville deja existe\n");
        return;
    }
	printf("\n\tEntrez sa pays :");
	gets(V.pays);

	}
	fprintf(Fpt,"%d ; %s ; %s \n",V.IdVille,V.Ville,V.pays);
	}while(!feof(Fp));
    fclose(Fpt);
    fclose(Fp);
    remove("TVILLES.txt");
    rename("VILLES.txt","TVILLES.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tCe Numero de la ville N'existe pas\n");
	}
}

int RechercheVilleParNom(char * ville)
{
	unsigned int 	id;
    char  ville_courant[MAX];
    char pays_courant[MAX];
    char  line[BIG_MAX];
    FILE * F=fopen("TVILLES.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ; %s ; %s \n",&id,&ville_courant,&pays_courant);
        if(!strcmp(ville,ville_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechVille(int Numrech)
{
	FILE *Fp;
	Fp=fopen("TVILLES.txt","r");
	test_file_opening(Fp);
	do
		{
		fscanf(Fp,"%d ; %s ; %s \n",&V.IdVille,&V.Ville,&V.pays);
		fflush(stdin);
		if(V.IdVille==Numrech)
			{
			fclose(Fp);
			return 1;
			}
		}while(!feof(Fp));
	fclose(Fp);
	return -1;
}

void AfficherVille()
{
FILE *Fp;
Fp=fopen("TVILLES.txt","r");
printf("\n\tLa liste des villes:\n");
do
{
fscanf(Fp,"%d ; %s ; %s \n",&V.IdVille,&V.Ville,&V.pays);
fflush(stdin);
printf("\t%d ; %s ; %s \n",V.IdVille,V.Ville,V.pays);
}while(!feof(Fp));
fclose(Fp);
}

unsigned int getIDVille(char *File)
{
	unsigned int id;
	int j=(-1);
	char ville_courant[MAX];
	char pays_courant[MAX];
	char N[100];
    FILE *F;
    F=fopen("TVILLES.txt","r");
    test_file_opening(F);
    while(!feof(F))
	{
    fgets(N,100,F);
    j++;
	}
    if(j==0)
    {
    	fclose(F);
		return 0;
	}
	else
	{
		fclose(F);
		F=fopen(File,"r");
		test_file_opening(F);
		while(!feof(F))
		{
			fscanf(F,"%d ; %s ; %s \n",&id,&ville_courant,&pays_courant);
		}
	fclose(F);
	return id;
	}
}

void MenuVille()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t               **********************                  ");
	    printf("\n\t***************   MENU DES Villes   ********************");
	    printf("\n\t               **********************                ");
	    printf("\n\t                                               \n");
	    printf("\t*  (1) Ajouter une ville                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher Une ville                     *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer Une ville                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier Une ville                       *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les villes                 *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (6) Quiter                                   *\n");
	    printf("\t*-----------------------------------------------*\n");

	    do
		    {
		     printf("\n\t>>> Etrez votre choix...");
		     scanf("%d",&Choix);
		     fflush(stdin);
		    }while(Choix<1||Choix>6);
	    switch(Choix)
			{
		    case 1:AjouterVille();
		        break;
		    case 2:RechercheVille();
		        break;
		    case 3:SupprimerVille();
		        break;
		    case 4:ModifierVille();
		        break;
		    case 5:AfficherVille();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}

