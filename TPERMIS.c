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
#include "TLANGUE.h"
#include "TCANDIDATS.h"
#include "TFORMATIONS.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"
#include "TEXPERIENCES.h"

struct TPERMIS
{
    int IdPermis;
	char NomPermis[50];
};struct TPERMIS P ;

void AjouterPermis()
{

	FILE *Fp;
	Fp=fopen("TPERMIS.txt","a");
	test_file_opening(Fp);
	printf("\tSaisir le Nom du Permis ");
	scanf("%s",&P.NomPermis);
	getchar();
	if(RecherchePermisParNom(P.NomPermis)==1)
    {
        printf("Ce Permis deja existe\n");
        return;
    }

	P.IdPermis=getIDPermis("TPERMIS.txt")+1;
	fflush(stdin);

	fprintf(Fp,"%d ; %s  \n",P.IdPermis,P.NomPermis);
	printf("\n\nle Permis %u %s est ajoute au fichier TPERMIS.txt avec success \n",P.IdPermis,P.NomPermis);
	fclose(Fp);
}

void RecherchePermis()
{
	int NumR,j=0;
	printf("\n\tEntrez le numero du Permis a rechercher :");
	scanf("%d",&NumR);
	FILE *Fp;
	Fp=fopen("TPERMIS.txt","r");
	do
	{
	fscanf(Fp,"%d ;%s \n",&P.IdPermis,&P.NomPermis);
	if(NumR==P.IdPermis)
	{
	        printf("\n\t===============INFORMATION SUR LE Permis  %d  ================\n\t ",P.IdPermis);
	        printf("\n\tLe Permis \t\t\t:%s",P.NomPermis);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fp));
	fclose(Fp);
	if(j==0){
	    printf("\n\tDesole! Ce Permis n'existe pas\n");
	}
}

void AfficherPermisC(int NumR)
{
	FILE *Fp;
	Fp=fopen("TPERMIS.txt","r");
	do
	{
	fscanf(Fp,"%d ;%s \n",&P.IdPermis,&P.NomPermis);
	if(NumR==P.IdPermis)
	{
	        printf("\n\tLe Permis \t\t\t:%s",P.NomPermis);
	}
	}while(!feof(Fp));
	fclose(Fp);
}

void SupprimerPermis()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez Le numero du Permis a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechPermis(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fpt,*Fp;
	        Fp=fopen("TPERMIS.txt","r");
	        test_file_opening(Fp);
	        Fpt=fopen("Permis.txt","a");
	        test_file_opening(Fpt);
	        do
	        {
	         fscanf(Fp,"%d ;%s \n",&P.IdPermis,&P.NomPermis);
	         if(NumRech!=P.IdPermis)
	         {
	         fprintf(Fpt,"%d ;%s \n",P.IdPermis,P.NomPermis);
	         }
	        }while(!feof(Fp));
	        fclose(Fpt);
	        fclose(Fp);
	        remove("TPERMIS.txt");
	        rename("Permis.txt","TPERMIS.txt");
	        printf("\n\tLa suppression Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tCe numero du Permis n'existe pas");
	}
}

void ModifierPermis(){

	FILE *Fp,*Fpt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez Le numero du Permis a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechPermis(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fp=fopen("TPERMIS.txt","r");
	    test_file_opening(Fp);
	    Fpt=fopen("Permis.txt","a");
	    test_file_opening(Fpt);

	 do
	 {
	fscanf(Fp,"%d ;%s \n",&P.IdPermis,&P.NomPermis);
	if(num==P.IdPermis)
	{
	P.IdPermis=num;

	printf("\n\tEntrez Le Nouveau Permis :");
	gets(P.NomPermis);
	if(RecherchePermisParNom(P.NomPermis)==1)
    {
        printf("Ce Permis deja existe\n");
        return;
    }
	}
	fprintf(Fpt,"%d ;%s \n",P.IdPermis,P.NomPermis);
	}while(!feof(Fp));
    fclose(Fpt);
    fclose(Fp);
    remove("TPERMIS.txt");
    rename("Permis.txt","TPERMIS.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annule\n");
	}
	}
	else
	{
	printf("\n\tCe Numero du Permis N'existe pas\n");
	}
}

int RecherchePermisParNom(char * NomPermis)
{
	unsigned int 	id;
    char  NomPermis_courant[MAX];
    char  line[BIG_MAX];
    FILE * F=fopen("TPERMIS.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s \n",&id,NomPermis_courant);
        if(!strcmp(NomPermis,NomPermis_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechPermis(int Numrech)
{
	FILE *Fp;
	Fp=fopen("TPERMIS.txt","r");
	test_file_opening(Fp);
	do
		{
		fscanf(Fp,"%d ;%s \n",&P.IdPermis,&P.NomPermis);
		fflush(stdin);
		if(P.IdPermis==Numrech)
			{
			fclose(Fp);
			return 1;
			}
		}while(!feof(Fp));
	fclose(Fp);
	return -1;
}

void AfficherPermis()
{
FILE *Fp;
Fp=fopen("TPERMIS.txt","r");
printf("\n\tLa liste des Permis :\n");
printf("\n\tNumero\tLe Permis\n");
printf("\n\t--------------------------------------\n");
do
{
fscanf(Fp,"%d ;%s \n",&P.IdPermis,&P.NomPermis);
fflush(stdin);
printf("\n\t%d ;%s \n",P.IdPermis,P.NomPermis);
}while(!feof(Fp));
fclose(Fp);
}

unsigned int getIDPermis(char *File)
{
	unsigned int id;
	int j=(-1);
	char NomPermis_courant[MAX];
	char N[100];
    FILE *F;
    F=fopen("TPERMIS.txt","r");
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
			fscanf(F,"%d ;%s \n",&id,NomPermis_courant);
		}
	fclose(F);
	return id;
	}
}

void MenuPermis()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              **********************                  ");
	    printf("\n\t***************   MENU DE PERMIS   ********************");
	    printf("\n\t              **********************                ");
	    printf("\n\t                                               \n");
	    printf("\t*  (1) Ajouter un Permis                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher Un Permis                     *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer Un Permis                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier Un Permis                       *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher tous Les Permis                 *\n");
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
		    case 1:AjouterPermis();
		        break;
		    case 2:RecherchePermis();
		        break;
		    case 3:SupprimerPermis();
		        break;
		    case 4:ModifierPermis();
		        break;
		    case 5:AfficherPermis();
		        break;
		    case 6:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
