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
  char  Departement[20];
  float Note;
} Etudiant;

void welcome()
{
    printf("\tGestion des etudiants!\n");
    printf("");
    printf("\n0: exit\n1: ajouter un etudiant\n2: afficher les etudiant\n3:update  \n4:delete  \n5:Calcule le Note Generale\n6:afficher les statistique\n7:Recherche\n8:Tri  \n");
}

int ajouterEtudiant(Etudiant E[100], int count,int id_last)
{
    int reponce;
    
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
    strcpy(E[count].Departement,"Informatique");
    break;
    case 2:
    strcpy(E[count].Departement,"Management");
    break;
    case 3:
    strcpy(E[count].Departement,"Gestion");
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
     scanf("%f",&E[count].Note);

    
    count++;
    
    return count;
}


void ajouter(Etudiant E[100], int count,int id_last)
{
    int reponce;
    
    E[0].id=1;
    strcpy(E[0].Nom,"ali");
    strcpy(E[0].Prenom,"sami");
    strcpy(E[0].Departement,"Informatique");
    E[0].naissance.jour=20;
    E[0].naissance.mois=2;
    E[0].naissance.annee=2000;
    E[0].Note=9.55;
    E[1].id=2;
    strcpy(E[1].Nom,"omar");
    strcpy(E[1].Prenom,"kamila");
    strcpy(E[1].Departement,"Management");
    E[1].naissance.jour=2;
    E[1].naissance.mois=12;
    E[1].naissance.annee=2004;
    E[1].Note=14.12;
    E[2].id=3;
   strcpy(E[2].Nom,"salma");
   strcpy(E[2].Prenom, "Jean");
   strcpy(E[2].Departement, "Gestion");
    E[2].naissance.jour = 12;
    E[2].naissance.mois = 5;
    E[2].naissance.annee = 2000;
    E[2].Note = 14;

    E[3].id=4;
   strcpy(E[3].Nom,"bachir");
   strcpy(E[3].Prenom, "halima");
   strcpy(E[3].Departement, "Gestion");
    E[3].naissance.jour = 12;
    E[3].naissance.mois = 5;
    E[3].naissance.annee = 2000;
    E[3].Note = 16.14;

   E[4].id=5;
   strcpy(E[4].Nom,"mohamad");
   strcpy(E[4].Prenom, "salimi");
   strcpy(E[4].Departement, "Management");
    E[4].naissance.jour = 12;
    E[4].naissance.mois = 5;
    E[4].naissance.annee = 2020;
    E[4].Note = 13.22;



    
    
}

void affiche(Etudiant E[100],int count){
	int i;
    printf("\nListe des Etudiants :\n");
	for(i=0;i<count;i++){
	printf("\nId: %d \nNom: %s \nPrenom : %s \nDate de naissance est : %d-%d-%d \nDepartement:%s\nNote: %.2f\n", E[i].id, E[i].Nom, E[i].Prenom, E[i].naissance.jour,E[i].naissance.mois,E[i].naissance.annee,E[i].Departement,E[i].Note);
    printf("\n");
	}
}

void update(Etudiant E[100],int id_modifier,int count){
     int i,rep,jour_nv,mois_nv,anne_nv;
     float Note_nv;
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
    scanf("%f",&Note_nv);
    for(i=0;i<count;i++){
        if(E[i].id==id_modifier){
            strcpy(E[i].Nom,Nom_nv);
            strcpy(E[i].Prenom,Prenom_nv);
            
    switch (rep)
    {
    case 1:
    strcpy(E[i].Departement,"Informatique");
    break;
    case 2:
    strcpy(E[i].Departement,"Management");
    break;
    case 3:
    strcpy(E[i].Departement,"Gestion");
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
int suprime(Etudiant E[100],int count,int id_supprime){

    int i,j;
    for(i=0;i<count;i++){
        if(E[i].id==id_supprime){
    for(j=i+1;j<count;j++){
        E[j-1]=E[j];
    }
    count--;

        }


    }
    return count;

}

void calcule(Etudiant E[100],int count){
    int i,in=0,m=0,g=0;
    int total_info=0,total_management=0,total_gestion=0;
    for(i=0;i<count;i++){
        if(strcmp(E[i].Departement,"Informatique")==0){
            total_info=total_info + E[i].Note;
            in++;

        }
        if(strcmp(E[i].Departement,"Management")==0)
        {
            total_management=total_management + E[i].Note;
            m++;

        }
        if(strcmp(E[i].Departement,"Gestion")==0){
            total_gestion=total_gestion + E[i].Note;
            g++;
        }
    
    }
    if(in>0)printf("le moyane generale de Note de departement Informatique est :%d\n",total_info/in);
    if(m>0)printf("le moyane generale de Note de departement Mnagement est :%d\n",total_management/m);
    if(g++>0)printf("le moyane generale de Note de departement Gestion est :%d\n",total_gestion/g);
  
    printf("la somme de cette universiter est:  %d\n",total_info+total_management+total_gestion);

}

void Statistiques(Etudiant E[100],int count){

 int i,j,k;
 int reponce;
    float max1,max2,max3;
    char Nom_top[20];
    char Nom_top2[20];
    char Nom_top3[20];
    printf("\n1:Afficher le nombre total d etudiants nscrits\n2:Afficher le nombre d etudiants dans chaque departement\n3:Afficher les etudiants ayant une moyenne generale superieure à un certain seuil\n4:Afficher les 3 etudiants ayant les meilleures notes\n5:Afficher le nombre d etudiants ayant reussi dans chaque departement\nEntre votre choix:");
    scanf("%d",&reponce);
  switch (reponce)
  {
  case 1:
       printf("le nombre Total des etudiants %d\n",count);
    break;

  case 2:
 int total=0,total_Einfo=0,total_Emag=0,total_Eget=0;
      for(i=0;i<count;i++){
        if(strcmp(E[i].Departement,"Informatique")==0){
             total_Einfo++;
        }
        if(strcmp(E[i].Departement,"Management")==0)
        {
           total_Emag++;
        }
        if(strcmp(E[i].Departement,"Gestion")==0){
           total_Eget++;
        }}
      printf("le nombre Total des etudiants par departement\n");
      printf("\n");
      printf("le nombre des etudiant dans la Departement Informatique %d\n",total_Einfo);
      printf("le nombre des etudiant dans la Departement  Management %d\n",total_Emag);
      printf("le nombre des etudiant dans la Departement Gestion %d\n",total_Eget);
     break;
     case 3:
    int seuil;
    printf("entre le seuile que vous voulais :");
    scanf("%d",&seuil);
    for(i=0;i<count;i++){
     if (E[i].Note>seuil)
         {
            printf("cette etudiant %s a un moyen generale depasse le seuil %d  la note est %.2f\n",E[i].Nom,seuil,E[i].Note);
         }
    }
   
     break;
    case 4:
        
       max1=E[0].Note;
       max2=E[0].Note;
       max3=E[0].Note;
       int id_max1,id_max2,id_max3;
  for(i=0;i<count;i++){
  if(E[i].Note > max1){
        max1=E[i].Note;
        strcpy(Nom_top,E[i].Nom);  
       }else if(E[i].Note > max2 && max1 >max2 ){
        max2=E[i].Note;
        strcpy(Nom_top2,E[i].Nom);
        id_max2=E[i].id;
        
       }else if(E[i].Note > max3 && max2 > max3){
        max3=E[i].Note;
        strcpy(Nom_top3,E[i].Nom);
        }
  }
      printf("\n");
      printf("la premier note est %.2f de l etudinant %s \n",max1,Nom_top);
      printf("la deuxieme note est %.2f de l etudinant %s\n",max2,Nom_top2);
      printf("le troisieme note est %.2f de l etudinant %s\n",max3,Nom_top3);
    break;
    case 5:
     int info_pass=0,manag_pass=0,gest_pass=0;
      for(i=0;i<count;i++){
        if(strcmp(E[i].Departement,"Informatique")==0){
             if(E[i].Note>=10){
             info_pass++;
        }
        }
        if(strcmp(E[i].Departement,"Management")==0){
             if(E[i].Note>=10){
             manag_pass++;
        }
        }

        if(strcmp(E[i].Departement,"Gestion")==0){
             if(E[i].Note>=10){
          gest_pass++;
        }
        }
       
      }
       printf("\n");
      printf("pour le Departement Informatique le total  a depasse 10 est :%d\n",info_pass);
      printf("pour le Departement Management le total  a depasse 10 est :%d\n",manag_pass);
      printf("pour le Departement Gestion le total  a depasse 10 est :%d\n",gest_pass);
      
    break ;

   default:
   printf("not found");
    break;
  }



  }
void Recherche(Etudiant E[100],int count,char Nom_recherche[]){
    int i ;
    for(i=0;i<count;i++){
        if(strcmp(E[i].Nom,Nom_recherche)==0){
printf("\nId: %d \nNom: %s \nPrenom : %s \nDate de naissance est : %d-%d-%d \nDepartement:%s\nNote: %.2f\n", E[i].id, E[i].Nom, E[i].Prenom, E[i].naissance.jour,E[i].naissance.mois,E[i].naissance.annee,E[i].Departement,E[i].Note);
        }
    }
}

void Recherche_departement(Etudiant E[100],int count,int reponce){
    char departement[20];
    int i;
    switch (reponce)
    {
    case 1:
    strcpy(departement,"Informatique");
    break;
    case 2:
    strcpy(departement,"Management");
    break;
    case 3:
    strcpy(departement,"Gestion");
    break;
    default:
    printf("not found!");
        break;
    }
    for(i=0;i<count;i++){
        if(strcmp(E[i].Departement,departement)==0){
            printf("|le Nom : %s| |le prenom : %s| \n",E[i].Nom,E[i].Prenom);
        }

    }
}
void triabulle_aVSz(Etudiant E[100], int count) {
  

    int i, j;
    Etudiant tmp;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(E[j].Nom, E[j + 1].Nom) > 0) {
                tmp = E[j];
                E[j] = E[j + 1];
                E[j + 1] = tmp;
            }
        }
    }

    printf("\nListe des Etudiants apres tri:\n");
    for (i = 0; i < count; i++) {
        printf("\nId: %d\nNom: %s\nPrenom: %s\nDate de naissance: %d-%d-%d\nDepartement: %s\nNote: %.2f\n",
               E[i].id, E[i].Nom, E[i].Prenom,
               E[i].naissance.jour, E[i].naissance.mois, E[i].naissance.annee,
               E[i].Departement, E[i].Note);
        printf("\n");
    }
}

void triabulle_zVSa(Etudiant E[100], int count) {
  

    int i, j;
    Etudiant tmp;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(E[j].Nom, E[j + 1].Nom) < 0) {
                tmp = E[j];
                E[j] = E[j + 1];
                E[j + 1] = tmp;
            }
        }
    }

    printf("\nListe des Etudiants apres tri:\n");
    for (i = 0; i < count; i++) {
        printf("\nId: %d\nNom: %s\nPrenom: %s\nDate de naissance: %d-%d-%d\nDepartement: %s\nNote: %.2f\n",
               E[i].id, E[i].Nom, E[i].Prenom,
               E[i].naissance.jour, E[i].naissance.mois, E[i].naissance.annee,
               E[i].Departement, E[i].Note);
        printf("\n");
    }
    }
void triselection_maxNote(Etudiant E[100],int count){
    int i,j;
    int max;
    Etudiant tmp;
    for(i=0;i<count-1;i++){
        max=i;
    for(j=i+1;j<count;j++){
 if(E[j].Note>E[max].Note){
  max=j;
 }
 }
 if(max!=i){
  tmp=E[i];
  E[i]=E[max];
  E[max]=tmp;
 }

    }
     printf("\nListe des Etudiants après tri:\n");
    for (i = 0; i < count; i++) {
        printf("\nId: %d\nNom: %s\nPrenom: %s\nDate de naissance: %d-%d-%d\nDepartement: %s\nNote: %.2f\n",
               E[i].id, E[i].Nom, E[i].Prenom,
               E[i].naissance.jour, E[i].naissance.mois, E[i].naissance.annee,
               E[i].Departement, E[i].Note);
        printf("\n");
    }
    
}
void triinsertion_minNote(Etudiant E[100],int count){
    int i,j;
    float cle;
    for(i=0;i<count;i++){
        cle =E[i].Note;
        j=i-1;
        while(j>=0 && E[j].Note>cle){
            E[j+1]=E[j];
            j--;
        }
        E[j+1].Note=cle;

    }
      printf("\nListe des Etudiants apres tri:\n");
    for (i = 0; i < count; i++) {
        printf("\nId: %d\nNom: %s\nPrenom: %s\nDate de naissance: %d-%d-%d\nDepartement: %s\nNote: %.2f\n",
               E[i].id, E[i].Nom, E[i].Prenom,
               E[i].naissance.jour, E[i].naissance.mois, E[i].naissance.annee,
               E[i].Departement, E[i].Note);
        printf("\n");
    }
}





void valide_Note(Etudiant E[], int count) {
    int i, j = 0, k = 0;
    Etudiant valide[100];
    Etudiant Non_valide[100];

    // Separate students into 'valide' and 'Non_valide'
    for (i = 0; i < count; i++) {
        if (E[i].Note >= 10) {
            valide[j] = E[i];
            j++;
        } else {
            Non_valide[k] = E[i];
            k++;
        }
    }

    // Print valid students
    printf("Liste des etudiants valides:\n");
    for (i = 0; i < j; i++) {
        printf("\nId: %d\nNom: %s\nPrenom: %s\nDate de naissance: %d-%d-%d\nDepartement: %s\nNote: %.2f\n",
               valide[i].id, valide[i].Nom, valide[i].Prenom,
               valide[i].naissance.jour, valide[i].naissance.mois, valide[i].naissance.annee,
               valide[i].Departement, valide[i].Note);
    }

    // Print non-valid students
    printf("Liste des etudiants non valides:\n");
    for (i = 0; i < k; i++) {
        printf("\nId: %d\nNom: %s\nPrenom: %s\nDate de naissance: %d-%d-%d\nDepartement: %s\nNote: %.2f\n",
               Non_valide[i].id, Non_valide[i].Nom, Non_valide[i].Prenom,
               Non_valide[i].naissance.jour, Non_valide[i].naissance.mois, Non_valide[i].naissance.annee,
               Non_valide[i].Departement, Non_valide[i].Note);
    }
}



int main()
{
    int choix;
    int c = 5;
    int id_last=6;
    Etudiant E[100];
    
    while (1) {
        welcome();
        printf("Entee votre choix: ");
         scanf("%d", &choix);
         
         ajouter(E,c,id_last);
       
        switch (choix) {
        case 1: 
        
       c=ajouterEtudiant(E,c,id_last);
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
        case 4:
          int id_supprime;
           
            printf("avant la supprime:\n");
            affiche(E,c);
            printf("---------------------------\n");
            printf("enter le id de etudiant que vous voulais supprime :");
            scanf("%d",&id_supprime);
            for(j=0; j<c; j++){
            if(E[j].id==id_supprime){
             f=1;
            c= suprime(E,id_supprime,c); 
            printf("apres la supprime :\n");
             affiche(E,c);
            }
            }
        
          
            break;
        case 5:
        calcule(E,c);
            break;
        case 6:
        Statistiques(E,c);
            break;
        case 7:
        int rep;
        printf("\n1:Recherche un etudiant\n2:Recherche un list des etudiant dans un departement\nentre votre choix:");
        scanf("%d",&rep);
         switch (rep)
         {
         case 1:
            char Nom_cher[20];
        int i,f=0;
        printf("entre le Nom a rechercher :");
        scanf("%s",Nom_cher);
        for(i=0;i<c;i++){
            if(strcmp(E[i].Nom,Nom_cher)==0){
                f=1;
                 Recherche(E,c,Nom_cher);
            }
        }
        if(f==0){
            printf("not found!");
        }
         break;
        case 2:
    int reponce;
    
    printf("entre votre Departement a recherche \n1:Informatique\n2:Management\n3:Gestion\nentre votre choix :");
    scanf("%d",&reponce);
    Recherche_departement(E,c,reponce);
        break; 
         default:
         printf("not found!");
        break;
         }
        break;
        case 8:
        int choix_tri;
        printf("\n1:Tri liste des etudiant par ordre alphapitique de 'a' vs 'z'\n2::Tri liste des etudiant par ordre alphapitique de 'z' vs 'a'\n3:Tri des etudiants par moyenne generale de max vs min\n4:Tri des etudiants par moyenne generale de min vs max\n5:Tri des etudiants selon leur statut de reussite\nentre votre choix: ");
        scanf("%d",&choix_tri);

        switch (choix_tri)
        {
        case 1:
            triabulle_aVSz(E,c);
            break;
        case 2:
           triabulle_zVSa(E,c);
        break;
        case 3:
         triselection_maxNote(E,c);

        break;
        case 4:
        triinsertion_minNote(E,c);
        break;

        case 5:
        valide_Note(E,c);
        break;
        
        default:
            break;
        }





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