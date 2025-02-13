#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>


enum{EXPRESSO=1, CAPUCCINO, MACCIATO};
enum{SMALL=10, MEDIUM=20, TALL=30, GRANDE=45, VENTI=60};

typedef struct
{
    char nom[20];
    int volume;
    bool lait;
    bool chocolat;
    float prix;
} Cafe;

Cafe * machineACafe(int typecafe)
{
    Cafe * tasse = NULL;
    tasse = malloc(sizeof(Cafe));
    switch (typecafe)
    {
    case EXPRESSO:
        tasse->volume = SMALL;
        tasse->lait= false;
        tasse->chocolat = false;
        tasse->prix = 1.0f;
        strcpy(tasse->nom, "Expresso");
        break;
    default:
        printf("Recette inconnue");
    }
    return tasse;
}

void machineACafeP(int typecafe, Cafe ** monBras)
{
    *monBras = calloc(1, sizeof(Cafe));
    switch (typecafe)
    {
    case EXPRESSO:
        (*monBras)->volume = SMALL;
        (*monBras)->lait= false;
        (*monBras)->chocolat = false;
        (*monBras)->prix = 1.0f;
        strcpy((*monBras)->nom, "Expresso");
        break;
    default:
        printf("Recette inconnue");
    }
}


void afficherCafe(Cafe unCafe)
{
    printf("Hmm un café %s qui coute %f eur",unCafe.nom, unCafe.prix);
}

int main(void)
{
    Cafe *maTasse = NULL;
    int typecafe=0;
    printf("Un cafe?, Quel type 1: Expresso, 2:Capuccino, 3: Macciato");
    scanf("%d", &typecafe);
    //maTasse= machineACafe(typecafe);
    machineACafeP(typecafe,&maTasse);
    afficherCafe(*maTasse);

    free(maTasse);
    maTasse = NULL;

    return 0;
}