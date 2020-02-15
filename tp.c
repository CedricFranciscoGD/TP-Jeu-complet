#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Centre
	{
		char storyC[150];
		int goldC;
		int lifePointC;
		int chapitreC[3];
	};
	typedef struct Centre centre;

struct Athenes
{
	char storyA[150];
	int goldA;
	int lifePointA;
	int chapitreA[3];

};
typedef struct Athenes athenes;

struct Item
	{
		char nom[100];
		int prix;	
	};
	typedef struct Item item;

int main (){

	/*capoue histoire = {"Bienvenue a Capoue jeune gladiateur, vous combattrez a present pour nous, voici vos cadeaux de bienvenue:"};
	capoue gold = {100};
	capoue pv= {100};
	capoue chapitre= {1};
	*/

	centre persoC ={"Bienvenue au centre pokemon, vous souhaitez acheter quelque chose ?" };
	athenes persoA ={"Bienvenue a Athenes jeune gladiateur, vous combattrez a present pour nous, faites honneur a notre deesse Athena ! Voici vos cadeaux de bienvenue:", 20, 12,  1 };
	
/****************************************************************************************************************************************************************************************************

	VARIABLE	CHOIX DE LA DESTINATION


****************************************************************************************************************************************************************************************************/

	//choix premiere destination
	int choixDest=0;
	//confirmation du choix
	int nvChoix=0;
	//choix du chapitre 
	int choixChap=0;

	int chapitre[10];

	chapitre[0]=1;
	chapitre[1]=2;
	chapitre[2]=3;
	chapitre[3]=4;
	chapitre[4]=5;
	chapitre[5]=6;
	chapitre[6]=7;
	chapitre[7]=8;
	chapitre[8]=9;
	chapitre[9]=10;
	
	//Jauge de vie de depart
	int pointDevie=100;
	//Pecule d'or de depart
	int pokePiece=10;



/****************************************************************************************************************************************************************************************************

		VARIABLE	CHOIX SHOP + INVENTAIRE

			
****************************************************************************************************************************************************************************************************/

	//Choix action joueur
	int choixJoueur = 0;

	//Choix item a acheter
	int choixAchat = 0;

	//Nombre d'item que l'on veut ajouter
	int addItem = 0; 

	/*J'ai essayé de donner la possibilité d'ajouter plusieur items, mais les noms d'items se remplacent si on choisi 2 et le programme s'arrete
	 si on choisi 3. Je laisse quand meme le code dans l'état puisque c'est fonctionnel avec 1 item et marche a moitié avec 2
	Pour ce qui est du tri, j'ai en commentaire en bas de mon code la fonction qui devait me permettre de trier ce qu'il y avait a
	trier mais je n'ai pas réussi a la faire marcher, elle doit etre fausse.*/

	//Choix de nom pour les 3 items que l'on peut rajouter
	char item1;
	char item2;
	char item3;

	//Choix de prix pour les 3 items que l'on peut rajouter
	int prix1;
	int prix2;
	int prix3;

    
    
/****************************************************************************************************************************************************************************************************

        VARIABLE    CHOIX COMBAT + LVL UP

			
****************************************************************************************************************************************************************************************************/    
    
    	//Variables
	int nombreEnnemi = 1;
    int nombreAmi = 3;

    //Aspicot
    int idAspicot = 4;
	int pdvAspicot = 10;
	int pdmAspicot = 10;
    int dotApiscot = 0;

    //Abo
    int idAbo = 5;
	int pdvAbo = 12;
	int pdmAbo = 12;
    int dotAbo = 0;

    //Smogo
    int idSmogo = 6;
	int pdvSmogo = 20;
	int pdmSmogo = 20;
    int dotSmogo = 0;
    
    //Salameche
    int idSalameche = 1;
	int pdvSalameche = 10;
	int pdmSalameche = 20;
    int dotSalameche = 0;
    
    int flammeche = 5;
    int coutFlammeche = 5;

    //Carapuce
    int idCarapuce = 3;
    int aggroCarapuce = 0;
	int pdvCarapuce = 20;
	int pdmCarapuce = 10;
    int dotCarapuce = 0;

    //Bulbizarre
    int idBulbizarre = 2;
	int pdvBulbizarre = 15;
	int pdmBulbizarre = 15;
    int dotBulbizarre = 0;
    
    int Soin = 4;

    //attaques
	int atkLegere = 1;
    int atkLourde = 3;
    
	//Variable comportement joueur
	int choixAction = 0;
    int choixCible = 0;
    int choixCibleEnnemi = 0;
    int choixActionEnnemi = 0;
	//Variable comportement Monstre
	int i = 0;
	int coutSort = 3;
	int coutAntidote = 5;
    
    

	//Barre d'exp des pokémons alliés
	//Tableau
	int exp[3];

	//0 = Salamèche
	//1 = Bulbizarre
	//2 = Carapuce
	exp[0] = 0;
	exp[1] = 0;
	exp[2] = 0;

	//LVL 
	int lvl[3];

	//0 = Salamèche
	//1 = Bulbizarre
	//2 = Carapuce
	lvl[0] = 1;
	lvl[1] = 1;
	lvl[2] = 1;
    
    
    
    printf("Vous avez %d point de vie\n", pointDevie);
    printf("Vous avez %d poke pieces \n",pokePiece );

    while (pointDevie >1)
    {
   
	printf("Choisissez votre destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	scanf("%d", &choixDest);
    while(choixDest==1 || choixDest==2 || choixDest==3)
    {
	if (choixDest== 1){
		//Mon inventaire
	item inventaire[50] = {{"Pokeball", 100},{"Potion de vie", 100},{"Super potion de vie",100},
	{"Antidote",100},{"Carte",100}, {"Canne",100}};

	//Items dispo au shop
	item shop[15] = {{"Filet", 160},{"Lance en bois",25},{"Massue",200},{"Viande de boeuf",10},
	{"Fiole vide",5},{"Bouclier en bois",50},{"Glaive en bois",55},{"Pain",8}};


	printf("Que souhaitez vous faire ?\n");
	printf("Tapez 1 pour afficher votre inventaire..\n");
	printf("Tapez 2 pour vous rendre au shop..\n");
    printf("Tapez 0 pour quittez le centre pokemon\n");
	scanf("%d", &choixJoueur);
	if (choixJoueur== 1)
	{
		printf("Vous ouvrez votre inventaire: \n");
		item ball = {"Poke ball", 100};
		printf("Vous possedez: \n");
		printf("-%s \n", ball.nom);
		item potion = {"Potion de vie", 100};
		printf("-%s \n", potion.nom);
		item spotion = {"Super potion de vie", 100};
		printf("-%s \n", spotion.nom);
		item antidote = {"Antidote", 100};
		printf("-%s \n", antidote.nom);
		item carte = {"Carte", 100};
		printf("-%s \n", carte.nom);
		item canne = {"Canne", 100};
		printf("-%s \n", canne.nom);
        printf("-Vous avez %d poke pieces \n",pokePiece );
        
	}
	
	else if (choixJoueur == 2)
	{
		printf("Vous entrez dans le shop: \n");
		printf("Bonjour voila ce que j'ai a t'offrir:\n");
		item ball = {"Poke ball",25};
		item sball = {"Super ball", 50};
		item potion = {"Potion de vie",20};
		item spotion = {"Super potion de vie",40};
		item antidote = {"Antidote",25};
		item rappel = {"Rappel",30};
		item huile = {"Huile",30};
		item corde = {"Corde de sortie",20};
		printf("1:%s ................................ Prix: %d Or \n",ball.nom, ball.prix );
		printf("2:%s ................................ Prix: %d Or \n",sball.nom, sball.prix );
		printf("3:%s ................................ Prix: %d Or \n",potion.nom, potion.prix );
		printf("4:%s ................................ Prix: %d Or \n",spotion.nom, spotion.prix );
		printf("5:%s ................................ Prix: %d Or \n",antidote.nom, antidote.prix );
		printf("6:%s ................................ Prix: %d Or \n",rappel.nom, rappel.prix );
		printf("7:%s ................................ Prix: %d Or \n",huile.nom, huile.prix );
		printf("8:%s ................................ Prix: %d Or \n",corde.nom, corde.prix );

		printf("Que souhaitez vous faire ?\n");
		printf("Tapez 1 pour afficher votre inventaire..\n");
		printf("Tapez 3 pour faire un achat\n");
		printf("Tapez 4 pour demander au marchand d'ajouter un item\n");
		printf("Tapez 0 pour quittez le shop\n");

		scanf("%d", &choixJoueur);
    
		
		if (choixJoueur==1)
		{
        printf("Vous ouvrez votre inventaire: \n");
		item ball = {"Poke ball", 100};
		printf("Vous possedez: \n");
		printf("-%s \n", ball.nom);
		item potion = {"Potion de vie", 100};
		printf("-%s \n", potion.nom);
		item spotion = {"Super potion de vie", 100};
		printf("-%s \n", spotion.nom);
		item antidote = {"Antidote", 100};
		printf("-%s \n", antidote.nom);
		item carte = {"Carte", 100};
		printf("-%s \n", carte.nom);
		item canne = {"Canne", 100};
		printf("-%s \n", canne.nom);
        printf("-Vous avez %d poke pieces \n",pokePiece );
		}
        
		//Ici le joueur peut choisir l'item qu'il souhaite acheter
		else if(choixJoueur==3)
		{
			printf("Que souhaitez vous acheter ?\n");
			printf("Tapez le numero correspondant a l'article de votre choix\n");
			scanf("%d",&choixAchat);
			if (choixAchat==1)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n", ball.nom, ball.prix );
			}
			else if (choixAchat==2)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",sball.nom, sball.prix );
			}
			else if (choixAchat==3)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",potion.nom, potion.prix );
			}
			else if (choixAchat==4)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",spotion.nom, spotion.prix );
			}
			else if (choixAchat==5)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",antidote.nom, antidote.prix );
			}
			else if (choixAchat==6)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",rappel.nom, rappel.prix );
			}
			else if (choixAchat==7)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",huile.nom, huile.prix );
			}
			else if (choixAchat==8)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",corde.nom, corde.prix );
			}
			else if (choixAchat==9)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",&item1, prix1 );
			}
			else if (choixAchat==10)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",&item2, prix2);
			}
			else if (choixAchat==11)
			{
				printf("Vous venez d'acheter '%s' pour %d Or\n",&item3, prix3);
			}

		}

		// Ici le joueur a la possibilité de demander au marchand d'ajouter jusqu'à 3 items
		else if (choixJoueur==4)
		{
			printf("Combien d'objet souhaitez vous ajouter ? (maximum 2) \n");
			scanf("%d",&addItem);
			if (addItem==1)
			{
				printf("Choisissez le nom de l'objet:\n");
				scanf("%s",&item1);
				printf("Choisissez le prix de l'objet:\n");
				scanf("%d", &prix1);
				printf("Le marchand vient d'ajouter '%s' au prix de %d or dans sa boutique\n", &item1, prix1 );
				printf("\n");
				printf("Voila ce que j'ai a t'offrir:\n");
				printf("1:%s ................................ Prix: %d Or \n",ball.nom, ball.prix );
				printf("2:%s ................................ Prix: %d Or \n",sball.nom, sball.prix );
				printf("3:%s ................................ Prix: %d Or \n",potion.nom, potion.prix );
				printf("4:%s ................................ Prix: %d Or \n",spotion.nom, spotion.prix );
				printf("5:%s ................................ Prix: %d Or \n",antidote.nom, antidote.prix );
				printf("6:%s ................................ Prix: %d Or \n",rappel.nom, rappel.prix );
				printf("7:%s ................................ Prix: %d Or \n",huile.nom, huile.prix );
				printf("8:%s ................................ Prix: %d Or \n",corde.nom, corde.prix );
				printf("9:%s ................................ Prix: %d Or \n",&item1, prix1 );

				
			}
			if (addItem==2)
			{
				printf("Choisissez le nom de l'objet:\n");
				scanf("%s",&item1);
				printf("Choisissez le prix de l'objet:\n");
				scanf("%d", &prix1);
				printf("Le marchand vient d'ajouter '%s' au prix de %d or dans sa boutique\n", &item1, prix1 );
				printf("\n");
				printf("Choisissez le nom de l'objet 2 :\n");
				scanf("%s",&item2);
				printf("Choisissez le prix de l'objet 2:\n");
				scanf("%d", &prix2);
				printf("Le marchand vient d'ajouter '%s' au prix de %d or dans sa boutique\n", &item2, prix2 );
				printf("\n");
				printf("Voila ce que j'ai a t'offrir:\n");
				printf("1:%s ................................ Prix: %d Or \n",ball.nom, ball.prix );
				printf("2:%s ................................ Prix: %d Or \n",sball.nom, sball.prix );
				printf("3:%s ................................ Prix: %d Or \n",potion.nom, potion.prix );
				printf("4:%s ................................ Prix: %d Or \n",spotion.nom, spotion.prix );
				printf("5:%s ................................ Prix: %d Or \n",antidote.nom, antidote.prix );
				printf("6:%s ................................ Prix: %d Or \n",rappel.nom, rappel.prix );
				printf("7:%s ................................ Prix: %d Or \n",huile.nom, huile.prix );
				printf("8:%s ................................ Prix: %d Or \n",corde.nom, corde.prix );
				printf("9:%s ................................ Prix: %d Or \n",&item1, prix1 );
				printf("10:%s ............................... Prix: %d Or \n",&item2, prix2 );
            }
			if (addItem==3)
			{
				printf("Choisissez le nom de l'objet:\n");
				scanf("%s",&item1);
				printf("Choisissez le prix de l'objet:\n");
				scanf("%d", &prix1);
				printf("Le marchand vient d'ajouter '%s' au prix de %d or dans sa boutique\n", &item1, prix1 );
				printf("\n");
				printf("Choisissez le nom de l'objet 2 :\n");
				scanf("%s",&item2);
				printf("Choisissez le prix de l'objet 2:\n");
				scanf("%d", &prix2);
				printf("Le marchand vient d'ajouter '%s' au prix de %d or dans sa boutique\n", &item2, prix2 );
				printf("\n");
				printf("Choisissez le nom de l'objet 3 :\n");
				scanf("%s",&item3);
				printf("Choisissez le prix de l'objet 3 :\n");
				scanf("%d", &prix3);
				printf("Le marchand vient d'ajouter '%s' au prix de %d or dans sa boutique\n", &item3, prix3 );
				printf("\n");
				printf("Voila ce que j'ai a t'offrir:\n");
				printf("1:%s ................................ Prix: %d Or \n",ball.nom, ball.prix );
				printf("2:%s ................................ Prix: %d Or \n",sball.nom, sball.prix );
				printf("3:%s ................................ Prix: %d Or \n",potion.nom, potion.prix );
				printf("4:%s ................................ Prix: %d Or \n",spotion.nom, spotion.prix );
				printf("5:%s ................................ Prix: %d Or \n",antidote.nom, antidote.prix );
				printf("6:%s ................................ Prix: %d Or \n",rappel.nom, rappel.prix );
				printf("7:%s ................................ Prix: %d Or \n",huile.nom, huile.prix );
				printf("8:%s ................................ Prix: %d Or \n",corde.nom, corde.prix );
				printf("9:%s ................................ Prix: %d Or \n",&item1, prix1 );
				printf("10:%s ............................... Prix: %d Or \n",&item2, prix2 );
				printf("11:%s ............................... Prix: %d Or \n",&item3, prix3 );
			}

		}  
				
	}
        else if (choixJoueur==0)
            {
                printf("Merci de votre visite \n");
                printf("Ou souhaitez vous aller ?\n");
                printf("Tapez '1' pour vous rendre au Centre pokemon, tapez '2' pour pour commencez votre aventure ou tapez '3' pour affonter des pokemons sauvage \n");
                scanf("%d", &choixDest);
                
            }


                
        

		

}
        else if (choixDest==2){
		printf("Felicitation votre aventure est sur le point de commencer ! \n");
		printf("Vous allez devoir choisir quel chapitre vous souhaitez lancer, mais attention certains vous rapporteront des bonus tandis que d'autre seront des pieges\n");
		printf("Vous avez %d points de vie \n",pointDevie );
        printf("Vous avez %d poke pieces \n",pokePiece );
	


		printf("Souhaitez vous changer de chapitre ?\n");
		printf("Tapez le numero correspondant au chapitre qui vous interesse: \n");
		printf("\n");
		printf("Chapitre [1] \n");
		printf("Chapitre [2] \n");
		printf("Chapitre [3] \n");
		printf("Chapitre [4] \n");
		printf("Chapitre [5] \n");
		printf("Chapitre [6] \n");
		printf("Chapitre [7] \n");
		printf("Chapitre [8] \n");
		printf("Chapitre [9] \n");
		printf("Chapitre [10] \n");

		scanf ("%d", &choixChap);


		while(choixChap>10)
		{
		
			printf("Vous ne pouvez pas vous rendre a ce chapitre car il n'existe pas ou n'a pas encore ete decouvert\n ");
			printf("Veuillez choisir un chapitre valide:\n");
			scanf ("%d", &choixChap);
		}

		while (pointDevie > 1){


		if (choixChap ==1 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous tombez dans un gouffre et trouvez un tresor\n");
			pointDevie -= 20;
			pokePiece += 50;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
			
		}

		else if (choixChap ==2 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous tombez sur une vieille charette abandonnée \n");
			pointDevie += 0;
			pokePiece += 5;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		
		}
		else if (choixChap ==3 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Le professeur Chen vous recompense pour vos recentes decouvertes \n");
			pointDevie += 0;
			pokePiece += 50;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		}
		else if (choixChap ==4 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous vous faites voler par la team rocket \n");
			pointDevie -= 5;
			pokePiece -= 40;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		}
		else if (choixChap ==5 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous remportez un combat d'arene \n");
			pointDevie -= 50;
			pokePiece += 100;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		}
		else if (choixChap ==6 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous trouvez une Hyper Potion \n");
			pointDevie += 50;
			pokePiece += 0;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		}
		else if (choixChap ==7)
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous terrasser le fantominus qui effraye les villageois qui vous recompense pour votre aide \n");
			pointDevie -= 10;
			pokePiece += 100;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		}
		else if (choixChap ==8)
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous tombez sur votre rival et le vainquez \n");
			pointDevie -= 70;
			pokePiece += 50;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		}
		else if (choixChap ==9 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous vous inscrivez a un championnat que vous remportez et de plus vous etes totalement soigne par l'infirmiere Joelle \n");
			pointDevie = 100;
			pokePiece += 200;
			printf("-Vous avez %d points de vie\n", pointDevie);
			printf("-Vous avez %d poke pieces \n",pokePiece );
            printf("Que souhaitez vous faire ?\n");
            printf("Tapez 0 pour quittez l'aventure\n");
            printf("Tapez 5 pour choisir un nouveau chapitre\n");
            scanf("%d", &choixJoueur);
            
            if(choixJoueur==0)
            {
                printf("Vous quittez l'aventure\n");
                printf("Choisissez votre nouvelle destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	            scanf("%d", &choixDest);
                break;
            }
            else if (choixJoueur==5)
            {
                printf("Choisissez un nouveau chapitre\n");
                scanf ("%d", &choixChap);
            }
            
            else 
            {
                printf("!!! Choix invalide j'ai dit '0' ou '5'.. '%d' c'est ni l'un ni l'autre !!!\n",choixJoueur);
                printf("Choisissez un chapitre\n");
                scanf ("%d", &choixChap);
            }
		}
		else if (choixChap ==10 )
		{
			printf("Vous vous rendez au chapitre numero %d \n", choixChap);
			printf("Vous tombez dans un piege confectionne par la team rocket qui vous torture jusqu'a la mort \n");
			pointDevie -= 100;
			pokePiece -= 0;
			printf("Vous avez %d point de vie\n", pointDevie);
			printf("Vous avez %d poke pieces \n",pokePiece );
			printf("Choisissez un nouveau chapitre\n");
			scanf ("%d", &choixChap);
            
		}
        
		}
		
	   if (pointDevie<=0)
		{
			printf("Vous etes mort, la partie est terminee.\n");
            printf("Vous avez perdu %d poke pieces \n",pokePiece );
            pointDevie =0;
			pokePiece = 0;
            printf("Vous avez %d point de vie\n", pointDevie);
            printf("Vous avez %d poke pieces \n",pokePiece );
            break;
            
		}

        }
        else if (choixDest ==3)
        {
            printf("Un Aspicot sauvage apparait\n");
	        printf("Aspicot sauvage a %d points de vie\n", pdvAspicot);
	        printf("Vous avez %d points de vie \n", pdvSalameche);



// Boucle de combat 
	while (nombreAmi > 0 || nombreEnnemi >0)
	{
        //-------------------------------------------------------------------------------------------------------------------------
        //TOUR DE SALAMECHE
        if (pdmSalameche<10)
        {
            printf("Salameche recupere 1 pt de magie\n");
            pdmSalameche ++;
        }
        printf("C'est le tour de Salameche que souhaitez vous faire ? \n");
        printf("Tapez 1 pour lancer une attaque lourde\n");
        printf("Tapez 2 pour vous defendre\n");
        printf("Tapez 3 pour lancer flammeche\n");
        printf("Tapez 4 pour utiliser un sort d'antidote\n");
        printf("Tapez 5 pour aggro un nouvel ennemi\n");
        printf("Tapez 6 pour abandonner le combat et choisir une nouvelle destination \n");
        printf("\n");
        scanf("%d", &choixAction);
        printf("\n");

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            printf("Vous lancez une attaque lourde ! \n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= atkLourde;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= atkLourde;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= atkLourde;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
        }


        else if (choixAction == 2)
        {
            printf("Vous vous protegez et votre defense est multipliee par 4 ! \n");
            printf("Vous avez %d point de vie ! \n", pdvSalameche);

        }


        else if (choixAction == 3)
        {
            printf("Vous lancez flammeche \n");
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= flammeche;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= flammeche;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= flammeche;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
            printf("Il vous reste %d points de magie \n", pdmSalameche -= coutFlammeche);
        }

        // N'ayant pas réussi à faire perdurer le poison, mon antidote sera un soin de 3 pv contre 5 pts de magie.
        else if (choixAction == 4)
        {
            printf("Vous utilisez un sort d'antidote \n");
            printf("Vous recuperez 3 points de vie\n");
            printf("Vous avez %d points de vie\n", pdvSalameche += 3 );
            printf("Il vous reste %d points de magie \n", pdmSalameche -= coutAntidote);

        }

        else if (choixAction == 5)
        {	
            if (nombreEnnemi == 1 )
            {
            printf("Abo apparait ! \n");
            printf("Abo a %d points de vie et %d points de magie \n ", pdvAbo, pdmAbo);
            nombreEnnemi++;
            }
            else if (nombreEnnemi == 2)
            {
                printf("Smogo apparait ! \n");
                printf("Smogo a %d points de vie et %d points de magie \n ", pdvSmogo, pdmSmogo);
                nombreEnnemi++;
            }

            else if (nombreEnnemi == 3)
            {
                printf("Nombre maximum d'ennemi atteint, choisissez une autre action ! \n ");
                printf("\n");
                scanf("%d", &choixAction);
                printf("\n");
            }
        }
        
        else if (choixAction == 6)
        {
            printf("Vous choisissez de quittez le combat 'vous ne gagnez pas l'exp des pokemons encore vivant' \n");
            printf("Que souhaitez vous faire ?\n");
            printf("Choisissez votre destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	        scanf("%d", &choixDest);
            break;
        }
        //FIN DU TOUR DE SALAMECHE 
        //--------------------------------------------------------------------------------------------------------------------------------


        //-------------------------------------------------------------------------------------------------------------------------
        //TOUR DE BULBIZARRE
        if (pdmBulbizarre<10)
        {
            printf("Bulbizarre recupere 1 pt de magie\n");
            pdmBulbizarre ++;
        }
        printf("C'est le tour de Bulbizarre que souhaitez vous faire ? \n");
        printf("Tapez 1 pour lancer une attaque legere\n");
        printf("Tapez 2 pour vous defendre\n");
        printf("Tapez 3 pour lancer un sort de soin\n");
        printf("Tapez 4 pour utiliser un sort d'antidote\n");
        printf("Tapez 5 pour aggro un nouvel ennemi\n");
        printf("Tapez 6 pour abandonner le combat et choisir une nouvelle destination \n");
        printf("\n");
        scanf("%d", &choixAction);
        printf("\n");

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            printf("Vous lancez une attaque legere ! \n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= atkLegere;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= atkLegere;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= atkLegere;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
        }


        else if (choixAction == 2)
        {
            printf("Vous vous protegez et votre defense est multipliee par 4 ! \n");
            printf("Vous avez %d point de vie ! \n", pdvBulbizarre);

        }


        else if (choixAction == 3)
        {
            printf("Bulbizarre utilise Soin ! \n");
            printf("Qui voulez vous soigner ? Salameche = 1, Bulbizarre = 2, Carapuce = 3.\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            if (choixCible == idSalameche)
            {
                pdvSalameche += Soin;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            if (choixCible == idBulbizarre)
            {
                pdvBulbizarre += Soin;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (choixCible == idCarapuce)
            {
                pdvCarapuce += Soin;
                printf("Carapuce a %d points de vie! \n", pdvSalameche);
            }
            printf("Il vous reste %d points de magie \n", pdmBulbizarre -= coutSort);
        }

        // N'ayant pas réussi à faire perdurer le poison, mon antidote sera un soin de 3 pv contre 5 pts de magie.
        else if (choixAction == 4)
        {
            printf("Vous utilisez un sort d'antidote \n");
            printf("Vous recuperez 3 points de vie\n");
            printf("Vous avez %d points de vie\n", pdvBulbizarre += 3 );
            printf("Il vous reste %d points de magie \n", pdmBulbizarre -= coutAntidote);

        }

        else if (choixAction == 5)
        {	
            if (nombreEnnemi == 1 )
            {
            printf("Abo apparait ! \n");
            printf("Abo a %d points de vie et %d points de magie \n ", pdvAbo, pdmAbo);
            nombreEnnemi++;
            }
            else if (nombreEnnemi == 2)
            {
                printf("Smogo apparait ! \n");
                printf("Smogo a %d points de vie et %d points de magie \n ", pdvSmogo, pdmSmogo);
                nombreEnnemi++;
            }

            else if (nombreEnnemi == 3)
            {
                printf("Nombre maximum d'ennemi atteint, choisissez une autre action ! \n ");
                printf("\n");
                scanf("%d", &choixAction);
                printf("\n");
            }
            
            else if (choixAction == 6)
        {
            printf("Vous choisissez de quittez le combat 'vous ne gagnez pas l'exp des pokemons encore vivant' \n");
            printf("Que souhaitez vous faire ?\n");
            printf("Choisissez votre destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	        scanf("%d", &choixDest);
            break;
        }
        }
        //FIN DU TOUR DE BULBIZARRE 
        //--------------------------------------------------------------------------------------------------------------------------------





        //-------------------------------------------------------------------------------------------------------------------------
        //TOUR DE CARAPUCE
        if (pdmBulbizarre<10)
        {
            printf("Carapuce recupere 1 pt de magie\n");
            pdmCarapuce ++;
        }
        printf("C'est le tour de Carapuce que souhaitez vous faire ? \n");
        printf("Tapez 1 pour lancer une attaque legere\n");
        printf("Tapez 2 pour vous defendre\n");
        printf("Tapez 3 pour lancer un sort de d'aggro\n");
        printf("Tapez 4 pour utiliser un sort d'antidote\n");
        printf("Tapez 5 pour aggro un nouvel ennemi\n");
        printf("Tapez 6 pour abandonner le combat et choisir une nouvelle destination \n");
        printf("\n");
        scanf("%d", &choixAction);
        printf("\n");

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            printf("Vous lancez une attaque legere ! \n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= atkLegere;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= atkLegere;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= atkLegere;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
        }


        else if (choixAction == 2)
        {
            printf("Vous vous protegez et votre defense est multipliee par 4 ! \n");
            printf("Vous avez %d point de vie ! \n", pdvCarapuce);

        }


        else if (choixAction == 3)
        {
            printf("Carapuce utilise Aggro ! \n");
            aggroCarapuce == 1;
            printf("Il vous reste %d points de magie \n", pdmCarapuce -= coutSort);
        }

        // N'ayant pas réussi à faire perdurer le poison, mon antidote sera un soin de 3 pv contre 5 pts de magie.
        else if (choixAction == 4)
        {
            printf("Vous utilisez un sort d'antidote \n");
            printf("Vous recuperez 3 points de vie\n");
            printf("Vous avez %d points de vie\n", pdvCarapuce += 3 );
            printf("Il vous reste %d points de magie \n", pdmCarapuce -= coutAntidote);

        }

        else if (choixAction == 5)
        {	
            if (nombreEnnemi == 1 )
            {
            printf("Abo apparait ! \n");
            printf("Abo a %d points de vie et %d points de magie \n ", pdvAbo, pdmAbo);
            nombreEnnemi++;
            }
            else if (nombreEnnemi == 2)
            {
                printf("Smogo apparait ! \n");
                printf("Smogo a %d points de vie et %d points de magie \n ", pdvSmogo, pdmSmogo);
                nombreEnnemi++;
            }

            else if (nombreEnnemi == 3)
            {
                printf("Nombre maximum d'ennemi atteint, choisissez une autre action ! \n ");
                printf("\n");
                scanf("%d", &choixAction);
                printf("\n");
            }
            
            else if (choixAction == 6)
        {
            printf("Vous choisissez de quittez le combat 'vous ne gagnez pas l'exp des pokemons encore vivant' \n");
            printf("Que souhaitez vous faire ?\n");
            printf("Choisissez votre destination:\nTapez '1' pour vous rendre au Centre pokemon 'achat'\nTapez '2' pour commencez votre aventure 'Farm poke piece'\nTapez '3' pour affonter des pokemons sauvages 'Farm exp' \n");
	        scanf("%d", &choixDest);
            break;
        }
        }
        //FIN DU TOUR DE CARAPUCE 
        //--------------------------------------------------------------------------------------------------------------------------------



// Condition qui devrait empecher Aspicot de m'envoyer un sort si sa reserve de magie est insuffisante mais qui ne marche pas.
// Je n'arrive pas a bloquer (ce n'est pas faute d'avoir essayé différentes méthodes).


// DEBUT TOUR ENNEMIS
//----------------------------------------------------------------------------------------------------
// TOUR ASPICOT 

        
        printf("C'est au tour d'Aspicot.");
        
        if (pdmAspicot<10)
        {
            printf("Aspicot recupere 1 pt de magie\n");
            pdmAspicot ++;
        }
        
        for (i = 0; i < 1; i++)
        {
            choixActionEnnemi = printf("%d\n", 1 + rand()%3);
        }
        
        if (choixActionEnnemi == 1)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                pdvCarapuce -= atkLegere;
                printf("Carapuce a %d points de vie! \n", pdvCarapuce);
            }
            
        }
        
         else if (choixActionEnnemi == 2)
        {
            printf("Aspicot se protege et sa defense est multipliee ! \n");
            printf("Aspicot a %d point de vie ! \n", pdvAspicot);

        }
        
        else if (choixActionEnnemi == 3)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonne ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonne ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonne ! \n", pdvCarapuce);
            }
        }

        
        //-----------------------------------------------------------------
        //TOUR ABO
        
        if (nombreEnnemi==2)
        {
        printf("C'est au tour d'Abo.");
        
        if (pdmAbo<10)
        {
            printf("Aspicot recupere 1 pt de magie\n");
            pdmAbo ++;
        }
        
        for (i = 0; i < 1; i++)
        {
            choixActionEnnemi = printf("%d\n", 1 + rand()%3);
        }
        
        if (choixActionEnnemi == 1)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                pdvCarapuce -= atkLegere;
                printf("Carapuce a %d points de vie! \n", pdvCarapuce);
            }
            
        }
        
         else if (choixActionEnnemi == 2)
        {
            printf("Abo se protege et sa defense est multipliee ! \n");
            printf("Aspicot a %d point de vie ! \n", pdvAbo);

        }
        
        else if (choixActionEnnemi == 3)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonne ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonne ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonne ! \n", pdvCarapuce);
            }
        }
        }
        else 
        {
            printf("\n");
        }
        
        //---------------------------------------------------------------------------------------------
        //TOUR SMOGO
        
        if (nombreEnnemi==2)
        {
        printf("C'est au tour de Smogo.");
        
        if (pdmSmogo<10)
        {
            printf("Aspicot recupere 1 pt de magie\n");
            pdmAspicot ++;
        }
        
        for (i = 0; i < 1; i++)
        {
            choixActionEnnemi = printf("%d\n", 1 + rand()%3);
        }
        
        if (choixActionEnnemi == 1)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                pdvCarapuce -= atkLegere;
                printf("Carapuce a %d points de vie! \n", pdvCarapuce);
            }
            
        }
        
         else if (choixActionEnnemi == 2)
        {
            printf("Smogo se protege et sa defense est multipliee ! \n");
            printf("Smogo a %d point de vie ! \n", pdvSmogo);

        }
        
        else if (choixActionEnnemi == 3)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonne ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonne ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonne ! \n", pdvCarapuce);
            }
        }
        }
        else 
        {
            printf("\n");
        }
        

        

        
        if (pdvAspicot <= 0 )
				{	
					printf("Aspicot est mort !!! \n");
					printf("Vos pokemons ont gagne +5 points d'experience \n");
                    printf("Vous gagnez 10 poke pieces \n");
					exp[0]+=5;
					exp[1]+=5;
					exp[2]+=5;
                    pokePiece+=10;
					printf("Salameche a %d points d'experience\n", exp[0] );
					printf("Bulbizarre a %d points d'experience\n", exp[1] );
					printf("Carapuce a %d points d'experience\n", exp[2] );
                    printf("-Vous avez %d poke pieces \n",pokePiece );
				}

			else if (pdvSalameche <= 0)
				{
				printf("Salameche est mort !!! \n");
                pointDevie-=30;
                printf("VOus etes impacte par la mort de votre Salameche et perdez 30 point de vie !!! \n");      
				printf("-Vous avez %d point de vie \n",pointDevie );
				}	

			else if (pdvBulbizarre <= 0)
				{
				printf("Bulbizarre est mort !!! \n");
				pointDevie-=30;
                printf("VOus etes impacte par la mort de votre Bulbizarre et perdez 30 point de vie !!! \n");      
				printf("-Vous avez %d point de vie \n",pointDevie );
				}

			else if (pdvAbo <= 0)
				{
				printf("Abo etes mort !!! \n");
				printf("Vos pokemons ont gagne 10 points d'exp\n");
                printf("Vous gagnez 20 poke pieces \n");
				exp[0]+=10;
				exp[1]+=10;
				exp[2]+=10;
                pokePiece+=20;
				printf("Salameche a %d points d'experience\n", exp[0] );
				printf("Bulbizarre a %d points d'experience\n", exp[1] );
				printf("Carapuce a %d points d'experience\n", exp[2] );
                printf("-Vous avez %d poke pieces \n",pokePiece );
				}

			else if (pdvCarapuce <= 0)
				{
				printf("Carapuce est mort !!! \n");
				pointDevie-=30;
                printf("VOus etes impacte par la mort de votre Carapuce et perdez 30 point de vie !!! \n");      
				printf("-Vous avez %d point de vie \n",pointDevie );
				}
				
			else if (pdvSmogo <= 0)
				{
				printf("Smogo est mort !!! \n");
				printf("Vos pokemons ont gagne 20 points d'exp\n");
                printf("Vous gagnez 40 poke pieces \n");
				exp[0]+=20;
				exp[1]+=20;
				exp[2]+=20;
                pokePiece+=20;
				printf("Salameche a %d points d'experience\n", exp[0] );
				printf("Bulbizarre a %d points d'experience\n", exp[1] );
				printf("Carapuce a %d points d'experience\n", exp[2] );
                printf("-Vous avez %d poke pieces \n",pokePiece );
			}

			while(exp[0]>= 5 && exp[1]>= 5 && exp[2]>= 5)
			{
				lvl[0] ++;
				exp[0] -=5;
				printf("Salameche vient de monter LVL %d \n", lvl[0]);
				lvl[1] ++;
				exp[1] -=5;
				printf("Bulbizarre vient de monter LVL %d \n", lvl[1]);
				lvl[2] ++;
				exp[2] -=5;
				printf("Carapuce vient de monter LVL %d \n", lvl[2]);

			}

    }
        }
    }
}
    
	return 0;
}