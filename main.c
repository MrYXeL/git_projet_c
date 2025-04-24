#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


//-------------------------------Ecriture et lecture du fichier scores.txt-------------------------------//

void ecrireFichier(const char *nom, int points){
    FILE *fichier = fopen("scores.txt", "a");
    fprintf(fichier, "%s %d\n", nom, points);
    fclose(fichier);
}

int lireFichier(const char *nom){
    int points = 0;
    char ligne[256];
    FILE *fichier = fopen("scores.txt", "r");
    
    while (fgets(ligne, 256, fichier)){
        char nomLigne[50];
        int pointsLigne;
        if (sscanf(ligne, "%s %d", nomLigne, &pointsLigne) == 2){ //Regarde si on a bien deux element qui correspondent a se formatage
            if (strcmp(nom, nomLigne) == 0) { //Si c'est le bon nom
                points = pointsLigne;
            }
        }
    }
    fclose(fichier);

    return points;
}

//------------------------------------------Fonctions jeu maths------------------------------------------//


int addition(){
    int a,b,reponse;
    int essais = 1;
    int trouve = 0;
    srand(time(NULL));
    a = (rand() % 101);
    b = (rand() % 101);
    while ((essais < 4) && (trouve == 0)){
        printf("Combien font %d + %d ? ", a, b);
        scanf("%d", &reponse);
        if (reponse == a + b) {
            printf("Bravo !\n");
            trouve = 1;
        } else {
            if (essais != 3){
                printf("Reessaye !\n");
            }
            essais ++;
        }
    } if (essais == 1){
        return 10;
    } else if (essais == 2){
        return 5;
    } else if (essais == 3){
        return 1;
    } else {
        printf("Dommage ! \n");
        return 0;
    }
}

int soustraction(){
    int a,b,reponse;
    int trouve = 0;
    int essais = 1;
    srand(time(NULL));
    a = (rand() % 101);
    b = (rand() % 101);

    if (a < b){
        int temps;
        temps = a;
        a = b;
        b = temps;
    }

    while ((essais < 4) && (trouve == 0)){
        printf("Combien font %d - %d ? ", a, b);
        scanf("%d", &reponse);
        if (reponse == a - b) {
            printf("Bravo !\n");
            trouve = 1;
        } else {
            if (essais != 3){
                printf("Reessaye !\n");
            } essais ++;
        }

    } if (essais == 1){
        return 10;
    } else if (essais == 2){
        return 5;
    } else if (essais == 3){
        return 1;
    } else {
        printf("Dommage ! \n");
        return 0;
    }
}

int multiplication(){
    int a,b,reponse;
    int trouve = 0;
    int essais = 1;
    srand(time(NULL));
    a = ((rand() % 10) + 1);
    b = ((rand() % 10) + 1);
    while ((essais < 4) && (trouve == 0)){
        printf("Combien font %d x %d ? ", a, b);
        scanf("%d", &reponse);
        if (reponse == a * b) {
            printf("Bravo !\n");
            trouve = 1;
        } else {
            if (essais != 3){
                printf("Reessaye !\n");
            } essais ++;
        }
    }
    if (essais == 1){
        return 10;
    } else if (essais == 2){
        return 5;
    } else if (essais == 3){
        return 1;
    } else {
        printf("Dommage ! \n");
        return 0;
    }
}

void afficherTable(int nb){

    for (int i = 1; i < 11; i++){
        printf("%d x %d = %d \n", nb, i, nb*i);
    }
}

int table(){
    int table, reponse;
    int juste = 0;
    int essais = 1;
    int trouve = 0;
    printf("Quel table voulez-vous travailler : ");
    scanf("%d", &table);
    
    afficherTable(table);
    printf("\n");

    while ((essais < 4) && (trouve == 0)){
        juste = 0;
        for (int i = 1; i < 11; i++){
            printf("%d x %d = ", table, i);
            scanf("%d", &reponse);

            if (reponse == table*i){
                juste += 1;
            }
        }

        if (juste != 10){
            printf("Dommage !\n");
            essais ++;
        } else{
            printf("Bravo !\n");
            trouve = 1;
        }
    }

    if (essais == 1){
        return 10;
    } else if (essais == 2){
        return 5;
    } else if (essais == 3){
        return 1;
    } else {
        printf("Dommage ! \n");
        return 0;
    }
}

int division(){
    int a,b,reponse;
    int essais = 1;
    int trouve = 0;
    srand(time(NULL));
    a = ((rand() % 100) + 1);
    b = ((rand() % 10) + 1);

    int q,r;

    while ((essais < 4) && (trouve == 0)){
        printf("Donner le quotient de %d par %d : ", a, b);
        scanf("%d", &q);
        printf("Donner le reste de %d par %d : ", a, b);
        scanf("%d", &r);

        if  ((q == a / b) && (r == a % b)){
            printf("Bravo !\n");
            trouve = 1;
        } else{
            if (essais != 3){
                printf("Reessaye !\n");
            } essais ++;
        }
    }
    if (essais == 1){
        return 10;
    } else if (essais == 2){
        return 5;
    } else if (essais == 3){
        return 1;
    } else {
        printf("Dommage ! \n");
        return 0;
    }
}

int duree(){
    int min,sec,reponse;
    int essais = 1;
    int trouve = 0;
    srand(time(NULL));
    min = ((rand() % 10) + 1);
    sec = (rand() % 60);

    while ((essais < 4) && (trouve == 0)){
        printf("Converti en seconde %d min %d sec ", min, sec);
        scanf("%d", &reponse);

        if (reponse = ((min*60) + sec)){
            trouve = 1;
            printf("Bravo !\n");
        } else{
            if (essais != 3){
                printf("Reessaye !\n");
            } essais ++;
        } 
    }
    if (essais == 1){
        return 10;
    } else if (essais == 2){
        return 5;
    } else if (essais == 3){
        return 1;
    } else {
        printf("Dommage ! \n");
        return 0;
    }
}

int maths(){

    int points = 0;
    int choix = -1;
    while (choix != 0){
        printf("\n+-----------------------------------+\n");
        printf("|1 : Addition                       |\n");
        printf("|2 : Soustraction                   |\n");
        printf("|3 : Multiplication                 |\n");
        printf("|4 : Tables de Multiplication       |\n");
        printf("|5 : Division                       |\n");
        printf("|6 : Duree                          |\n");
        printf("|0 : Sortir du jeu                  |\n");
        printf("+-----------------------------------+\n");

        printf("Votre choix : ");
        scanf("%d", &choix);


        switch (choix)
        {
        case 1:
            points += addition();
            break;
        
        case 2:
            points += soustraction();
            break;
        
        case 3:
            points += multiplication();
            break;
        
        case 4:
            points += table();
            break;

        case 5:
            points += division();
            break;

        case 6:
            points += duree();
            break;
        
        default:
            return points;
            break;
        }
    }
}

//-----------------------------------------------Mini Jeux------------------------------------------------//

int pfs(){

    printf("\nSi vous gagnez, vous gagnez 2 points, si vous faites égalité vous gagnez un point\n");

    //Ordinateur
    int o;
    srand(time(NULL));
    o = (rand() % 3) + 1;

    //Joueur
    int choix = -1;
    printf("\n1 : Pierre");
    printf("\n2 : Feuille");
    printf("\n3 : Ciseaux\n");
    scanf("%d", &choix);

    if (choix == o){
        printf("Egalite !\n");
        return 1;
    } else if ((choix == 1) && (o == 2)){
        printf("Perdu !\n");
        return 0;
    } else if ((choix == 1) && (o == 3)){
        printf("Gagne !\n");
        return 3;
    } else if ((choix == 2) && (o == 1)){
        printf("Gagne !\n");
        return 3;
    } else if ((choix == 2) && (o == 3)){
        printf("Perdu !\n");
        return 0;
    } else if ((choix == 3) && (o == 1)){
        printf("Perdu !\n");
        return 0;
    } else if ((choix == 3) && (o == 2)){
        printf("Gagne !\n");
        return 3;
    }
}

int jeu(){

    int points = 0;
    int choix = -1;
    while (choix != 0){
        printf("\n+-----------------------------------+\n");
        printf("|1 : Pierre Feuille Ciseaux         |\n");
        printf("|0 : Sortir du jeu                  |\n");
        printf("+-----------------------------------+\n");

        printf("Votre choix : ");
        scanf("%d", &choix);


        switch (choix)
        {
        case 1:
            points += pfs();
            break;

        default:
            return points;
            break;
        }
    }  
}

//--------------------------------------------Lancement du jeu--------------------------------------------//

void main(){

    char nom[50];
    printf("Quels est votre nom : ");
    scanf("%s", nom);


    int points = lireFichier(nom);
    int choix = -1;
    while (choix != 0){
        printf("\n\n        Vous avez %d points         \n", points);
        printf("\n+-----------------------------------+\n");
        printf("|1 : Maths                          |\n");
        printf("|2 : Mini Jeu                       |\n");
        printf("|0 : Sortir du jeu                  |\n");
        printf("+-----------------------------------+\n");

        printf("Votre choix : ");
        scanf("%d", &choix);


        switch (choix)
        {
        case 1:
            points += maths();
            break;
        
        case 2:
            points += jeu();
            break;

        default:
            break;
        }
    }
    ecrireFichier(nom, points);
}

