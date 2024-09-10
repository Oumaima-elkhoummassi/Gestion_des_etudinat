#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
int jour;
int mois;
int annee;
}Date;

typedef struct {
   int id;
  char Nom[20];
  char Prenom[30];
  Date naissance;
  char  Département[20];
  int Note;
} Etudiant;

void welcome()
{
    printf("\tGestion des etudiants!\n");
    printf("");
    printf("\n0: exit\n1: ajouter un etudiant\n2: afficher les etudiant\n3:update  \n4:delete  \n5:afficher  \n6:Recherche \n7:Tri \n");
}

int ajouter(Etudiant E[100], int count)
{
    int reponce;
    int id_last=1;
    E[count].id=id_last;
    printf("entre votre nom:");
    scanf("%s",E[count].Nom);
    printf("entre votre prenom:");
    scanf("%s",E[count].Prenom);
    printf("entre votre Departement \n1:Informatique\n2:Management\n3:Gestion\nentre votre choix :");
    scanf("%d",&reponce);
    switch (reponce)
    {
    case 1:
    strcpy(E[count].Département,"Informatique");
    break;
    case 2:
    strcpy(E[count].Département,"Management");
    break;
    case 3:
    strcpy(E[count].Département,"Gestion");
    break;
    default:
    printf("not found!");
        break;
    }
    do{
 printf("Entrer le jour de naissance :");
     scanf("%d",&E[count].naissance.jour);
     printf("Entrer le mois de naissance :"); 
     scanf("%d",&E[count].naissance.mois);
     printf("Entrer l'annee de naissance:"); 
     scanf("%d",&E[count].naissance.annee);
     if(E[count].naissance.jour>32 || E[count].naissance.mois>13 || E[count].naissance.annee<1000){
        printf("erurre :\n");
     }
    }while(E[count].naissance.jour>32 || E[count].naissance.mois>13 || E[count].naissance.annee<1000);
    
     printf("entre votre Note :");
     scanf("%d",&E[count].Note);
    id_last++;
    count++;
    return count;
}

void affiche(Etudiant E[100],int count){
	int i;
	for(i=0;i<count;i++){
	printf("\nId: %d \nNom: %s \nPrenom : %s \nDate de naissance est : %d-%d-%d \nDepartement:%s\n", E[i].id, E[i].Nom, E[i].Prenom, E[i].naissance.jour,E[i].naissance.mois,E[i].naissance.annee,E[i].Département);
   
	}
}

void update(Etudiant E[100],int id_modifier,int count){
     int i,rep,jour_nv,mois_nv,anne_nv,Note_nv;
     char Nom_nv[20];
     char Prenom_nv[20];
     printf("entre le nouveau Nom :");
     scanf("%s",Nom_nv);
     printf("entre le nouveau Prenom : ");
     scanf("%s",Prenom_nv);
    printf("entre votre Departement \n1:Informatique\n2:Management\n3:Gestion\nentre votre choix :");
    scanf("%d",&rep);
     do{
     printf("entre le nouveau jour de naissance :");
     scanf("%d",&jour_nv);
     printf("entre le nouveau mois de naissance :");
     scanf("%d",&mois_nv);
     printf("entre le nouveau anne de naissance :");
     scanf("%d",&anne_nv);
     if(jour_nv>32 || mois_nv>13 || anne_nv<1000){
        printf("erurre merci de verifie la date :");
     }
     }while(jour_nv>32 || mois_nv>13 || anne_nv<1000);
    
    printf("entre votre nouveau Note");
    scanf("%d",&Note_nv);
    for(i=0;i<count;i++){
        if(E[i].id==id_modifier){
            strcpy(E[i].Nom,Nom_nv);
            strcpy(E[i].Prenom,Prenom_nv);
            
    switch (rep)
    {
    case 1:
    strcpy(E[i].Département,"Informatique");
    break;
    case 2:
    strcpy(E[i].Département,"Management");
    break;
    case 3:
    strcpy(E[i].Département,"Gestion");
    break;
    default:
    printf("not found!");
        break;
    }
    E[i].naissance.jour=jour_nv;
    E[i].naissance.mois=mois_nv;
    E[i].naissance.annee=anne_nv;
    E[i].Note=Note_nv;
        }
    }

}
void suprime(Etudiant E,int count,int id_supprime){

}
int main()
{
    int choix;
    int c = 0;
    int id_last=1;
    Etudiant E[100];
    
    while (1) {
        welcome();
        printf("Entee votre choix: ");
         scanf("%d", &choix);
         
        
       
        switch (choix) {
        case 1: 
        c=ajouter(E,c);
        id_last++;
            break;
        case 2:
         printf("count %d\n", c);
         affiche(E,c);
            break;
        case 3:
        int id_modifier,j,f;
           
            printf("avant la modification :\n");
            affiche(E,c);
            printf("---------------------------\n");
            printf("enter le id de etudiant que vous voulais suprime :");
            scanf("%d",&id_modifier);
            for(j=0; j<c; j++){
            if(E[j].id==id_modifier){
             f=1;
             update(E,id_modifier,c); 
              printf("apres la modification :\n");
             affiche(E,c);
            }
            }
           
          break;
        case 4:/*
          int id_supprime,j,f;
           
            printf("avant la modification :\n");
            affiche(E,c);
            printf("---------------------------\n");
            printf("enter le id de etudiant que vous voulais suprime :");
            scanf("%d",&id_modifier);
            for(j=0; j<c; j++){
            if(E[j].id==id_modifier){
             f=1;
             update(E,id_modifier,c); 
              printf("apres la modification :\n");
             affiche(E,c);
            }
            }
        */
          
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            printf("exit...");
            exit(0);
         default:
                printf("Default!\n");
				getchar();
				break;
        }
    }
    return (0);
}