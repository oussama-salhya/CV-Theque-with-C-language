#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define BIG_MAX 100
#define MAX 25
#include "TPAYS.h"
#include "TPERMIS.h"
#include "TETATCIVILE.h"
#include "TVILLES.h"
#include "Lng.h"
#include "TCANDIDATS.h"
#include "TFORMATIONS.h"
#include "TTYPECONTRAT.h"
#include "TCV.h"
#include "TCOMPETENCES.h"
#include "TEXPERIENCES.h"

void Menulangue();

struct TLANGUES
{
    int Idlangue;
	char langue[50];

};struct TLANGUES L ;

struct TNIVEAU
{
    int Idniveau;
	char niveau[50];

};struct TNIVEAU N ;

void Ajouterlangue()
{

	FILE *Fp;
	Fp=fopen("TLANGUE.txt","a");
	test_file_opening(Fp);
	printf("\tSaisir la langue desiree ");
	scanf("%s",&L.langue);
	getchar();
	if(RecherchelangueParNom(L.langue)==1)
    {
        printf("cette langue est deja existee\n");
        return;
    }

	L.Idlangue=getID("TLANGUE.txt")+1;
	fflush(stdin);

	fprintf(Fp,"%d ; %s  \n",L.Idlangue,L.langue);
	printf("\n\nla langue %u %s est ajoutee au fichier TLANGUE.txt avec success \n",L.Idlangue,L.langue);
	fclose(Fp);
}

void Recherchelangue()
{
	int Numl,j=0;
	printf("\n\tEntrez le numero de la langue a rechercher :");
	scanf("%d",&Numl);
	FILE *Fp;
	Fp=fopen("TLANGUE.txt","r");
	do
	{
	fscanf(Fp,"%d ;%s \n",&L.Idlangue,&L.langue);
	if(Numl==L.Idlangue)
	{
	        printf("\n\t===============INFORMATION SUR LA LANGUE  %d  ================\n\t ",L.Idlangue);
	        printf("\n\tLA LANGUE \t\t\t:%s",L.langue);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fp));
	fclose(Fp);
	if(j==0){
	    printf("\n\tDesole! Cette langue n'existe pas\n");
	}
}

void Supprimerlangue()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez Le numero de la langue a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechL(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fpt,*Fp;
	        Fp=fopen("TLANGUE.txt","r");
	        test_file_opening(Fp);
	        Fpt=fopen("LANGUE.txt","a");
	        test_file_opening(Fpt);
	        do
	        {
	         fscanf(Fp,"%d ;%s \n",&L.Idlangue,&L.langue);
	         if(NumRech!=L.Idlangue)
	         {
	         fprintf(Fpt,"%d ;%s \n",L.Idlangue,L.langue);
	         }
	        }while(!feof(Fp));
	        fclose(Fpt);
	        fclose(Fp);
	        remove("TLANGUE.txt");
	        rename("LANGUE.txt","TLANGUE.txt");
	        printf("\n\tLa suppression est Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tCe numero de langue n'existe pas");
	}
}

void Modifierlangue(){

	FILE *Fp,*Fpt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez Le numero de la langue a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechL(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fp=fopen("TLANGUE.txt","r");
	    test_file_opening(Fp);
	    Fpt=fopen("LANGUE.txt","a");
	    test_file_opening(Fpt);

	 do
	 {
	fscanf(Fp,"%d ;%s \n",&L.Idlangue,&L.langue);
	if(num==L.Idlangue)
	{
	L.Idlangue=num;

	printf("\n\tEntrez La nouvelle langue :");
	gets(L.langue);

	}
	fprintf(Fpt,"%d ;%s \n",L.Idlangue,L.langue);
	}while(!feof(Fp));
    fclose(Fpt);
    fclose(Fp);
    remove("TLANGUE.txt");
    rename("LANGUE.txt","TLANGUE.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annulee\n");
	}
	}
	else
	{
	printf("\n\tCe Numero de langue N'existe pas\n");
	}
}

int RecherchelangueParNom(char * langue)
{
	unsigned int 	id;
    char  langue_courant[MAX];
    char  line[BIG_MAX];
    FILE * F=fopen("TLANGUE.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s \n",&id,langue_courant);
        if(!strcmp(langue,langue_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechL(int Numrech)
{
	FILE *Fp;
	Fp=fopen("TLANGUE.txt","r");
	test_file_opening(Fp);
	do
		{
		fscanf(Fp,"%d ;%s \n",&L.Idlangue,&L.langue);
		fflush(stdin);
		if(L.Idlangue==Numrech)
			{
			fclose(Fp);
			return 1;
			}
		}while(!feof(Fp));
	fclose(Fp);
	return -1;
}

void Afficherlangue()
{
FILE *Fp;
Fp=fopen("TLANGUE.txt","r");
printf("\n\tLa liste des langues :\n");
printf("\n\tNumero\tLa langue\n");
printf("\n\t--------------------------------------\n");
do
{
fscanf(Fp,"%d ;%s \n",&L.Idlangue,&L.langue);
fflush(stdin);
printf("\n\t%d ;%s \n",L.Idlangue,L.langue);
}while(!feof(Fp));
fclose(Fp);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Ajouterniveau()
{

	FILE *Fn;
	Fn=fopen("TNIVEAU.txt","a");
	test_file_opening(Fn);
	printf("\tSaisir le niveau desire ");
	scanf("%s",&N.niveau);
	getchar();
	if(RechercheniveauParNom(N.niveau)==1)
    {
        printf("ce niveau est deja existe\n");
        return;
    }

	N.Idniveau=gettID("TNIVEAU.txt")+1;
	fflush(stdin);

	fprintf(Fn,"%d ; %s  \n",N.Idniveau,N.niveau);
	printf("\n\nle niveau %u %s est ajoute au fichier TNIVEAU.txt avec success \n",N.Idniveau,N.niveau);
	fclose(Fn);
}

void Rechercheniveau()
{
	int Numl,j=0;
	printf("\n\tEntrez le numero du niveau a rechercher :");
	scanf("%d",&Numl);
	FILE *Fp;
	Fp=fopen("TNIVEAU.txt","r");
	do
	{
	fscanf(Fp,"%d ;%s \n",&N.Idniveau,&N.niveau);
	if(Numl==N.Idniveau)
	{
	        printf("\n\t===============INFORMATION SUR LE NIVEAU  %d  ================\n\t ",N.Idniveau);
	        printf("\n\tLE NIVEAU \t\t\t:%s",N.niveau);
	        printf("\n\t-----------------------------------------------------------------");
	        j++;
	}

	}while(!feof(Fp));
	fclose(Fp);
	if(j==0){
	    printf("\n\tDesole! Ce niveau n'existe pas\n");
	}
}

void Supprimerniveau()
{
	char rep;
	int NumRech;
	printf("\n\tEntrez Le numero du niveau a supprimer :");
	scanf("%d",&NumRech);
	getchar();
	fflush(stdin);

	if(rechN(NumRech)==1)
	{
	    printf("\n\tVoulez-vous vraiment Supprimer o/n?");
	    scanf("%c",&rep);
	    fflush(stdin);
	    if(rep=='o'||rep=='O')
	    {
	        FILE *Fpt,*Fp;
	        Fp=fopen("TNIVEAU.txt","r");
	        test_file_opening(Fp);
	        Fpt=fopen("NIVEAU.txt","a");
	        test_file_opening(Fpt);
	        do
	        {
	         fscanf(Fp,"%d ;%s \n",&N.Idniveau,&N.niveau);
	         if(NumRech!=N.Idniveau)
	         {
	         fprintf(Fpt,"%d ;%s \n",N.Idniveau,N.niveau);
	         }
	        }while(!feof(Fp));
	        fclose(Fpt);
	        fclose(Fp);
	        remove("TNIVEAU.txt");
	        rename("NIVEAU.txt","TNIVEAU.txt");
	        printf("\n\tLa suppression est Effectuee avec succees");

	    }
	}
	else
	{
	    printf("\n\tCe numero de niveau n'existe pas");
	}
}

void Modifierniveau(){

	FILE *Fp,*Fpt;
	int num,i;
	char rep='n';
	printf("\n\tEntrez Le numero de niveau a Modifier: ");
	scanf("%d",&num);
	fflush(stdin);

	if(rechN(num)==1)
	{
	printf("\n\tVoulez vous vraiment Modifier o/n?");
	scanf("%c",&rep);
	fflush(stdin);
	if(rep=='o'||rep=='O')
	{
	    Fp=fopen("TNIVEAU.txt","r");
	    test_file_opening(Fp);
	    Fpt=fopen("NIVEAU.txt","a");
	    test_file_opening(Fpt);

	 do
	 {
	fscanf(Fp,"%d ;%s \n",&N.Idniveau,&N.niveau);
	if(num==N.Idniveau)
	{
	N.Idniveau=num;

	printf("\n\tEntrez Le nouveau niveau :");
	gets(N.niveau);

	}
	fprintf(Fpt,"%d ;%s \n",N.Idniveau,N.niveau);
	}while(!feof(Fp));
    fclose(Fpt);
    fclose(Fp);
    remove("TNIVEAU.txt");
    rename("NIVEAU.txt","TNIVEAU.txt");
	printf("\n\tLa Modification a Reussi");
	}
	else
	{
	printf("\n\tLa Modification a ete annulee\n");
	}
	}
	else
	{
	printf("\n\tCe Numero de niveau N'existe pas\n");
	}
}

int RechercheniveauParNom(char * niveau)
{
	unsigned int 	id;
    char  niveau_courant[MAX];
    char  line[BIG_MAX];
    FILE * F=fopen("TNIVEAU.txt","r");

    test_file_opening(F);

    while(!feof(F))
    {
        fscanf(F,"%d ;%s \n",&id,niveau_courant);
        if(!strcmp(niveau,niveau_courant))
        {
            return 1;
        }
    }

    fclose(F);
    return 0;
}

int rechN(int Numrech)
{
	FILE *Fp;
	Fp=fopen("TNIVEAU.txt","r");
	test_file_opening(Fp);
	do
		{
		fscanf(Fp,"%d ;%s \n",&N.Idniveau,&N.niveau);
		fflush(stdin);
		if(N.Idniveau==Numrech)
			{
			fclose(Fp);
			return 1;
			}
		}while(!feof(Fp));
	fclose(Fp);
	return -1;
}

void Afficherniveau()
{
FILE *Fp;
Fp=fopen("TNIVEAU.txt","r");
printf("\n\tLa liste des niveaux :\n");
printf("\n\tNumero\tLe niveau\n");
printf("\n\t--------------------------------------\n");
do
{
fscanf(Fp,"%d ;%s \n",&N.Idniveau,&N.niveau);
fflush(stdin);
printf("\n\t%d ;%s \n",N.Idniveau,N.niveau);
}while(!feof(Fp));
fclose(Fp);
}

unsigned int getID(char *File)
{
	unsigned int id;
	int j=(-1);
	char langue_courant[MAX];
	char N[100];
    FILE *F;
    F=fopen("TLANGUE.txt","r");
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
			fscanf(F,"%d ;%s \n",&id,langue_courant);
		}
	fclose(F);
	return id;
	}
}

 int gettID(char *File)
{
     int id;
	int j=(-1);
	char niveau_courant[MAX];
	char N[100];
    FILE *F;
    F=fopen("TNIVEAU.txt","r");
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
			fscanf(F,"%d ;%s \n",&id,niveau_courant);
		}
	fclose(F);
	return id;
	}
}

void Menulangue()
{
int Choix;char rep;
do
	{
	    system("cls");
	    printf("\n\t              **********************                  ");
	    printf("\n\t*************** MENU DE LANGUE ********************");
	    printf("\n\t             **********************                ");
	    printf("\n\t                                                \n ");
	    printf("\t*  (1) Ajouter une langue                       *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (2) Rechercher une langue                    *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (3) Supprimer une langue                     *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (4) Modifier une langue                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (5) Afficher toutes Les langue               *\n");
	    printf("\t*-----------------------------------------------*\n");
        printf("\t*  (6) Ajouter un niveau                        *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (7) Rechercher un niveau                     *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (8) Supprimer un niveau                      *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (9) Modifier un niveau                       *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (10) Afficher tous les niveaux               *\n");
	    printf("\t*-----------------------------------------------*\n");
	    printf("\t*  (11) Quiter                                  *\n");
	    printf("\t*-----------------------------------------------*\n");



	    do
		    {
		     printf("\n\t>>> Etrez votre choix...");
		     scanf("%d",&Choix);
		    }while(Choix<1||Choix>11);
	    switch(Choix)
			{
		    case 1:Ajouterlangue();
		        break;
		    case 2:Recherchelangue();
		        break;
		    case 3:Supprimerlangue();
		        break;
		    case 4:Modifierlangue();
		        break;
		    case 5:Afficherlangue();
		        break;
            case 6:Ajouterniveau();
                break;
            case 7:Rechercheniveau();
                break;
            case 8:Supprimerniveau();
                break;
            case 9:Modifierniveau();
                break;
            case 10:Afficherniveau();
                break;
		    case 11:break;
		    }
	    printf("\n\t>>> Voulez-vous continuez O/N?...");
	    scanf("%s",&rep);
	    fflush(stdin);
	}while(rep=='o'||rep=='O');
}
