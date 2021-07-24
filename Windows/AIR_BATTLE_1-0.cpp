
/*
Angelo Saginario
4 IC  AIR BATTLE
V. 1.0  18/03/19
*/

#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define ARIA 0
#define JET 1
#define SCRAP 2
#define AIR_HOLE 3
#define WIN 5
#define N 10

//Gestione Colori
#define RED SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY)
#define BLUE SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define WHITE SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define GREEN SetConsoleTextAttribute(h,FOREGROUND_GREEN)
#define YELLOWN SetConsoleTextAttribute(h,FOREGROUND_RED |FOREGROUND_GREEN | FOREGROUND_INTENSITY)
//funzioni grafiche
void banner (void);
void f22 (void);
void t50 (void);
void atd (void);
void iran (void);
void efa (void);
void nazi (void);
void gene (void);
void menu (void);

//funzioni gioco
void sky_1 (void);              //GRAFICA MATRICE ALLEATA
void sky_2 (void);              // -- -- -- -- -- NEMICA
void possy_1 (void);              //POSIZIONAMENTO DELLE NAVI ALLEATO
void possy_2 (void);              //POSIZIONAMENTO DELLE NAVI NEMICO
void sparo_1 (int&, int&);
void sparo_2 (int&, int&);
void win (void);
void lose (void);

class plane                     //CLASSE AEREI
{
    public:
    int x;
    int y;
};

int campo_1 [N][N]={};            //MATRICE ALLEATA
int campo_2 [N][N]={};            //MATRICE NEMICA

HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE);

using namespace std;

int main()
{
    int i,j;
    int f_x, f_y;
    int s_x, s_y;

    menu();
    possy_1();
    possy_2();

    while(1)            //ciclo infinito
    {
    	system("cls");

        banner();
        sky_1();
        sky_2();

        cout << "\n\n";

        sparo_1(f_x, f_y);
        win();

        system("PAUSE");
		system("cls");

	    sparo_2(s_x, s_y);
        lose();

	    system("PAUSE");
	}
	system ("PAUSE");
}

void banner (void)
{
	WHITE;
	cout <<"\n\n";
	cout <<" _____________________________________________________________________________\n";
    cout <<"|  ";
	BLUE;
	cout <<" _______ _ ______     ______  _______ _______ _______ _       _______";
	WHITE;
	cout <<"      |\n";
    cout <<"|  ";
    BLUE;
	cout <<"(_______) (_____ \\   (____  \\(_______|_______|_______|_)     (_______)";
	WHITE;
	cout <<"     |\n";
    cout <<"|  ";
	BLUE;
	cout <<" _______| |_____) )   ____)  )_______    _       _    _       _____";
	WHITE;
	cout <<"        |\n";
    cout <<"|  ";
	BLUE;
	cout <<"|  ___  | |  __  /   |  __  (|  ___  |  | |     | |  | |     |  ___)";
	WHITE;
	cout <<"       |\n";
    cout <<"|";
	BLUE;
	cout <<"  | |   | | | |  \\ \\   | |__)  ) |   | |  | |     | |  | |_____| |_____";
	WHITE;
	cout <<"      |\n";
    cout <<"|  ";
	BLUE;
	cout <<"|_|   |_|_|_|   |_|  |______/|_|   |_|  |_|     |_|  |_______)_______)";
	WHITE;
	cout <<"     |\n";
    cout <<"|_____________________________________________________________________________|\n";
    cout <<"\n\n\n";
}

void f22 (void)
{
	WHITE;
    cout <<"\n\n    Stati Uniti d' America:\n\n";
    BLUE;
    cout <<"    |* * * * * * * * * * ";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	BLUE;
    cout <<"    | * * * * * * * * *  ";
	RED;
	cout <<":::::::::::::::::::::::::|\n";
	BLUE;
    cout <<"    |* * * * * * * * * * ";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	BLUE;
    cout <<"    | * * * * * * * * *  ";
	RED;
	cout <<":::::::::::::::::::::::::|\n";
	BLUE;
    cout <<"    |* * * * * * * * * * ";
    WHITE;
	cout <<"OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	BLUE;
    cout <<"    | * * * * * * * * *  ";
	RED;
	cout <<":::::::::::::::::::::::::|\n";
    BLUE;
	cout <<"    |* * * * * * * * * * ";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    RED;
	cout <<"    |:::::::::::::::::::::::::::::::::::::::::::::|\n";
    WHITE;
	cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    RED;
	cout <<"    |:::::::::::::::::::::::::::::::::::::::::::::|\n";
    WHITE;
	cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    RED;
	cout <<"    |:::::::::::::::::::::::::::::::::::::::::::::|\n";
    WHITE;
	cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
	WHITE;

    cout <<"\n\n\n ";
    cout <<"\t F-22 Raptor  \n";
    cout <<"\t\t\t                \\               /\n";
    cout <<"\t\t\t                 \\     ___     /\n";
    cout <<"\t\t\t _________________\\___(   )___/_________________\n";
    cout <<"\t\t\t                  \\   / . \\   /\n";
    cout <<"\t\t\t                   \\__\\___/__/ \n";
    cout <<"\n     F-22 Raptor e'un caccia da superiorita' aerea, con caratteristiche\n";
    cout <<"     stealth,di costruzione statunitense, talvolta classificato dallo stesso\n";
    cout <<"     Dipartimento della Difesa americano come velivolo da supremazia aerea.\n";
	cout <<"________________________________________________________________________________\n";
}

void t50 (void)
{
    cout <<"\n\n    Russia:\n\n";
    WHITE;
    cout <<"     _____________________________________________\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n"; //colorare bianco
    BLUE;
    cout <<"    |000000000000000000000000000000000000000000000|\n";
    cout <<"    |000000000000000000000000000000000000000000000|\n";
    cout <<"    |000000000000000000000000000000000000000000000|\n";
    cout <<"    |000000000000000000000000000000000000000000000|\n"; //colorare blu
    RED;
    cout <<"    |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n";
    cout <<"    |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n";
    cout <<"    |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n";
    cout <<"    |@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|\n"; //colorare rosso

	WHITE;
    cout <<"\n\n\n";
    cout <<"\t T-50 \n";
    cout <<"\t\t\t           \\       _       /\n";
    cout <<"\t\t\t            \\     /_\\     /\n";
    cout <<"\t\t\t ____________\\___/_._\\___/____________\n";
    cout <<"\t\t\t             \\   \\   /   /\n";
    cout <<"\t\t\t              \\__/\\_/\\__/\n";
    cout <<"\n     Il T-50, noto anche come PAK FA e' un prototipo di caccia multiruolo\n";
    cout <<"     monoposto di 5* generazione con caratteristiche stealth sviluppato\n";
    cout <<"     da Sukhoi per l'aeronautica militare russa.\n";
	cout <<"________________________________________________________________________________\n";
}

void atd (void)
{
	WHITE;
    cout <<"\n\n     Giappone:\n\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOO";
    RED;
	cout <<"xxxx";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOO";
    RED;
	cout <<"xxxxxxxxxx";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOO";
    RED;
	cout <<"xxxxxxxxxxxx";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOO";
    RED;
	cout <<"xxxxxxxxxxxx";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOO";
    RED;
	cout <<"xxxxxxxxxx";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOO";
    RED;
	cout <<"xxxx";
	WHITE;
	cout <<"OOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";

    cout <<"\n\n\n";
    cout <<"\t Mitsubishi ATD-X\n";
    cout <<"\t\t\t              \\     /\n";
    cout <<"\t\t\t               \\ _ /\n";
    cout <<"\t\t\t            ----/_\\----\n";
    cout <<"\t\t\tx--------------( . )--------------x\n";
    cout <<"\t\t\t     x|x   | |_|\\_/|_| |   x|x\n";
    cout <<"\t\t\t           x           x    \n";
    cout <<"\n     Il Mitsubishi ATD-X e' un velivolo sperimentale giapponese realizzato per\n";
    cout <<"     lo studio di tecnologie avanzate da riversare su un modello di aereo da\n";
    cout <<"     caccia dotato di tecnologia stealth da avviare alla produzione sul \n";
    cout <<"     territorio nazionale e destinare al Jieitai, le forze di autodifesa\n";
    cout <<"     giapponesi.\n";
	cout <<"________________________________________________________________________________\n";
}

void iran (void)
{
	WHITE;
    cout <<"\n\n    Iran: \n\n";
    GREEN;
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    WHITE;
    cout <<"    |=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n";
    RED;
	cout <<"    |                    / | \\                    |\n";
    cout <<"    |                    \\(|)/                    |\n";
    WHITE;
	cout <<"    |=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n";
    RED;
	cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";

	WHITE;
    cout <<"\n\n\n";
    cout <<"\t\t\t         \\        __        /\n";
    cout <<"\t\t\t          \\  ____/__\\____  /\n";
    cout <<"\t\t\t___________\\/___/____\\___\\/___________\n";
    cout <<"\t\t\t            \\   \\____/   /\n";
    cout <<"\t\t\t             \\__/    \\__/\n";
    cout <<"\n     Il Qaher-313 e' un presunto aereo da caccia monoposto dalle\n";
    cout <<"     caratteristiche stealth sviluppato dall'azienda aeronautica Iran\n";
    cout <<"     Organization (IAIO) e, al febbraio 2013, in fase di studio.\n";
	cout <<"     Aviation Industries\n";
	cout <<"________________________________________________________________________________\n";
}

void efa (void)
{
	WHITE;
    cout <<"\n\n    Europa: \n\n";
    BLUE;
    cout <<"     __________________________________________\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOO";
    YELLOWN;
	cout <<"****";
	BLUE;
	cout <<"OOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOO";
    YELLOWN;
	cout <<"*      *";
	BLUE;
	cout <<"OOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOO";
    YELLOWN;
	cout <<"*        *";
	BLUE;
	cout <<"OOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOO";
    YELLOWN;
	cout <<"*      *";
	BLUE;
	cout <<"OOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOO";
    YELLOWN;
	cout <<"****";
	BLUE;
	cout <<"OOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";
    cout <<"    |OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO|\n";

	WHITE;
    cout <<"\n\n\n";
    cout <<"\t\t\t              |     |\n";
    cout <<"\t\t\t              |  _  |\n";
    cout <<"\t\t\t______________|_( )_|______________\n";
    cout <<"\t\t\t   o   +|+   [ ( o ) ]   +|+       \n";
    cout <<"\t\t\t            *[_]---[_]*\n";
    cout <<"\n      L'Eurofighter Typhoon, il cui prototipo era designato EFA (European\n";
    cout <<"      Fighter Aircraft), e' un velivolo multiruolo di quarta generazione,\n";
    cout <<"      con ruolo primario di caccia intercettore e da superiorita' aerea.\n";
	cout <<"	  bimotore\n";
	cout <<"________________________________________________________________________________\n";
}
//RISOLVERE PROBLEMA
void gene (void)
{
	WHITE;
	cout <<"\n\t\t\t   Maggiore Olegna\n";
    cout <<"\t\t\t _______________________\n";
    cout <<"\t\t\t|                       |\n";
    cout <<"\t\t\t|       \\\\ /////        |\n";
    cout <<"\t\t\t|       |      |        |\n";
    cout <<"\t\t\t|      (| _  _ |)       |\n";
    cout <<"\t\t\t|       |` |  '|        |\n";
    cout <<"\t\t\t|       |  __  |        |\n";
    cout <<"\t\t\t| >>>___/\\_^__/\\___<<<  |\n";
    cout <<"\t\t\t|/               |||  \\ |\n";
    cout <<"\t\t\t|_______________________|\n";
}

void menu (void)
{
	system("CLS");
    banner();

    int scelta;                 //Fa scegliere all'utente in quale sezione del menu' andare
    int scelta1;                // scelta jet

	WHITE;
	cout <<"       SE SEI UN ASPIRANTE TERRORISTA, QUESTO E' IL GIOCO CHE FA PER TE!\n";
    cout <<"\n                 1) FIGHT!           __|__          2) CREDITS! \n";
    cout <<"                              --o--o--(_)--o--o--\n";
    cout <<"                 3) REGOLE!                         4) EXIT!";
    cin >> scelta;

	system("cls");

	switch ( scelta )
	{
		case 1:
			break;
		
		case 2:
			banner();
    		WHITE;
        	cout <<"\t\t\t\t  CREDITS\n\n ";
        	cout <<"\t                RINGRAZIAMENTI SPECIALI\n\n";
        	cout <<" Game Designer                     --------> Angelo Saginario\n";
        	cout <<" Character Animation Engineering   --------> Angelo Saginario\n";
        	cout <<" Sales // Marketing Division       --------> Angelo Saginario\n";
        	cout <<" Sound Engineering                 --------> Angelo Saginario\n";
        	cout <<" Programmer Group                  --------> Angelo Saginario\n\n ";
		
 			system("PAUSE");
    		menu();
			break;
		
		case 3:
			banner();

        	cout <<"\t\t\t\t REGOLE\n\n";
        	cout <<"  Il gioco ''AIR BATTLE'' affonda le proprie radici nel famoso gioco \n";
        	cout <<"  della battaglia navale, entrambi i giocatori hanno a disposizione \n";
        	cout <<"  5 JET e un numero infinito di colpi. Il gioco termina quando uno \n";
        	cout <<"  dei due giocatori distrugge tutti i JET nemici.\n\n  ";
			
			system("PAUSE");
			menu();
			break;
			
		case 4:
			banner();
			gene();
		
        	cout <<"                          Grazie per aver giocato!\n\n                       ";

        	system("PAUSE");
        	exit(0);
	}
/*
    if( scelta == 1)
    {
    }

    if( scelta == 2)
    {
    	banner();
    	WHITE;
        cout <<"\t\t\t\t  CREDITS\n\n ";
        cout <<"                RINGRAZIAMENTI SPECIALI\n\n";
        cout <<" Game Designer                     --------> Angelo Saginario\n";
        cout <<" Character Animation Engineering   --------> Angelo Saginario\n";
        cout <<" Sales // Marketing Division       --------> Angelo Saginario\n";
        cout <<" Sound Engineering                 --------> Angelo Saginario\n";
        cout <<" Programmer Group                  --------> Angelo Saginario\n\n ";

 		system("PAUSE");
    	menu();
    }

    if( scelta == 3)
    {
        banner();

        cout <<"\t\t\t\t REGOLE\n\n";
        cout <<" Il gioco ''AIR BATTLE''affonda le proprie radici nel famoso gioco \n";
        
        menu();
    }

    if( scelta == 4)
    {
        banner();
		gene();
		
        cout <<"                          Grazie per aver giocato!\n\n                          ";

        system("PAUSE");
        return;
    }
*/
	WHITE;
    cout <<"\n\n Scegli la tua Dotazione!\n";

    f22();
    system("PAUSE");

    t50();
    system("PAUSE");

	atd();
    system("PAUSE");

    iran();
    system("PAUSE");

	efa();
    system("PAUSE");

    cout <<"\n 1 = USA\n 2 = Russia\n 3 = Giappone\n 4 = Iran\n 5 = Europa\n\n ";
    cin >> scelta1;

    switch( scelta1 )
    {
        case 1:
        	system("cls");
            f22();
            system("PAUSE");
            break;

        case 2:
        	system("cls");
            t50();
            system("PAUSE");
            break;

        case 3:
        	system("cls");
            atd();
            system("PAUSE");
            break;

        case 4:
        	system("cls");
            iran();
            system("PAUSE");
            break;

        case 5:
        	system("cls");
            efa();
            system("PAUSE");
            break;
    }
	system("cls");
	
	banner();
	gene();
	
	WHITE;
	cout <<"\n			         STORIA\n\n";
	cout <<" Ambientato nel 2052, sull'orlo di una 3*Guerra Mondiale, un battaglione di\n";
	cout <<" JET militari viene attaccato, al largo sul pacifico da un nemico sconosciuto,\n";
	cout <<" dotato, come anche il tuo battaglione, di una schermatura stealth, quindi\n";
	cout <<" invisibile ai radar. Tocchera' a te dirigere ogni colpo dei tuoi alleati.\n\n "; 
	
	system("PAUSE");
	system("CLS");
}

void possy_1(void)
{
    int scelta = 0;

    plane plane1;
    plane plane2;
    plane plane3;
    plane plane4;
    plane plane5;

//	system("cls");

	banner();
    sky_1();
	gene();

	cout <<"\n\t\t\t In guardia soldato! Oggi\n\t\t\t ti occuperai della logistica\n\t\t\t di questa battaglia\n";
    cout <<"\n Desideri posizionare i JET automaticamente:\n 1 = SI\n 2 = NO\n";
    cin >> scelta;

    if(scelta == 1)
    {
    	system("cls");

        srand(time(NULL));

        plane1.x = rand()%N;
        plane1.y = rand()%N;

        campo_1[plane1.x][plane1.y]=JET;

		banner();
		sky_1();

		system("PAUSE");
		system("cls");

        plane2.x = rand()%N;
        plane2.y = rand()%N;

        campo_1[plane2.x][plane2.y]=JET;

		banner();
		sky_1();

		system("PAUSE");
		system("cls");

        plane3.x = rand()%N;
        plane3.y = rand()%N;

        campo_1[plane3.x][plane3.y]=JET;

		banner();
		sky_1();

		system("PAUSE");
		system("cls");

        plane4.x = rand()%N;
        plane4.y = rand()%N;

        campo_1[plane4.x][plane4.y]=JET;

		banner();
		sky_1();

		system("PAUSE");
		system("cls");

        plane5.x = rand()%N;
        plane5.y = rand()%N;

        campo_1[plane5.x][plane5.y]=JET;

		banner();
		sky_1();

		system("PAUSE");
		system("cls");
    }

    if(scelta == 2)
    {
    	system("cls");

        banner();
        sky_1();

    	cout << endl;

        cout <<"\n Dammi la coordinata x del 1'JET: ";
        cin >> plane1.x;
        cout <<"\n Dammi la coordinata y del 1'JET: ";
        cin >> plane1.y;

        campo_1[plane1.x][plane1.y]=JET;

        system("cls");

        banner();
        sky_1();

        cout << endl;

        cout <<"\n Dammi la coordinata x del 2'JET: ";
        cin >> plane2.x;
        cout <<"\n Dammi la coordinata y del 2'JET: ";
        cin >> plane2.y;

        campo_1[plane2.x][plane2.y]=JET;

        system("cls");

        banner();
        sky_1();

        cout << endl;

        cout <<"\n Dammi la coordinata x del 3'JET: ";
        cin >> plane3.x;
        cout <<"\n Dammi la coordinata y del 3'JET: ";
        cin >> plane3.y;

        campo_1[plane3.x][plane3.y]=JET;

        system("cls");

        banner();
        sky_1();

        cout << endl;


        cout <<"\n Dammi la coordinata x del 4'JET: ";
        cin >> plane4.x;
        cout <<"\n Dammi la coordinata y del 4'JET: ";
        cin >> plane4.y;

        campo_1[plane4.x][plane4.y]=JET;

        system("cls");

        banner();
        sky_1();

        cout << endl;


        cout <<"\n Dammi la coordinata x del 5'JET: ";
        cin >> plane5.x;
        cout <<"\n Dammi la coordinata y del 5'JET: ";
        cin >> plane5.y;

        campo_1[plane5.x][plane5.y]=JET;

        cout << endl;

		system("cls");
    }


}

void possy_2(void)
{
    plane plane6;
    plane plane7;
    plane plane8;
    plane plane9;
    plane plane10;

    srand(time(NULL));

    plane6.x = rand()%N;
    plane6.y = rand()%N;

    cout << plane6.x << "\n" << plane6.y << "\n";

    campo_2[plane6.x][plane6.y]=JET;


    plane7.x = rand()%N;
    plane7.y = rand()%N;

    cout << plane7.x << "\n" << plane7.y << "\n";

    campo_2[plane7.x][plane7.y]=JET;


    plane8.x = rand()%N;
    plane8.y = rand()%N;

    cout << plane8.x << "\n" << plane8.y << "\n";

    campo_2[plane8.x][plane8.y]=JET;


    plane9.x = rand()%N;
    plane9.y = rand()%N;

    cout << plane9.x << "\n" << plane9.y << "\n";

    campo_2[plane9.x][plane9.y]=JET;


    plane10.x = rand()%N;
    plane10.y = rand()%N;

    cout << plane10.x << "\n" << plane10.y << "\n";

    campo_2[plane10.x][plane10.y]=JET;
}

void sky_1 (void)
{
    int i, j;
    int z = ARIA;
	int cy = ARIA;         					//coordinata y GRAFICA

/*  cout << "\nz=" << z << "\n";
    cout << "i=" << i << "\n";
    cout << "j=" << j << "\n\n";			//controllo variabili
*/
    WHITE;
    cout << "\n";
    cout << " \tLEGGENDA: \n"; 
	BLUE;
	cout << "~";
	WHITE;
	cout << " = ARIA\n"; 
	cout << "O = MANCATO\n";
	YELLOWN; 
	cout <<"^";
	WHITE;
	cout <<" = JET\n"; 
	RED;
	cout <<"X";
	WHITE;
	cout <<" = COLPITO\n\n";
    cout << "\n     CAMPO ALLEATO\n";
    cout << "   | 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << " --|---------------------" << endl;

    for(i=0; i<N; i++)
    {
        WHITE;
    	cout << "  " << cy << "|";

    	cy++;

		for(j=0; j<N; j++)
        {

            z=campo_1[i][j];

            if( z == ARIA )
            {
            BLUE;
            cout << " ~";
            }
            if( z == AIR_HOLE )
            {
            WHITE;
            cout << " O";
            }
            if( z == JET )
            {
            YELLOWN;
            cout << " ^";
            }
            if( z == SCRAP )
            {
            RED;
            cout << " X";
            }
        }

    cout << endl;
    }

}

void sky_2 (void)
{
    int i, j;
    int z = ARIA;
	int cy = ARIA;         					//coordinata y GRAFICA

	WHITE;
    cout << "\n     CAMPO NEMICO\n";
    cout << "   | 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << " --|---------------------" << endl;
    for(i=0; i<N; i++)
    {
		WHITE;
    	cout << "  " << cy << "|";

    	cy++;

		for(j=0; j<N; j++)
        {

            z=campo_2[i][j];

            if( z == ARIA )
            {
            BLUE;
            cout << " ~";
            }
            if( z == AIR_HOLE )
            {
            WHITE;
            cout << " O";
            }
            if( z == JET )
            {
            BLUE;
            cout << " ~";
            }
            if( z == SCRAP )
            {
            RED;
            cout << " X";
            }
        }

    cout << endl;
    }

}

void sparo_1 (int& f_x, int& f_y)
{
    int scelta = 0;
	int voice = 0;

	srand(time(NULL));

    gene();

	WHITE;
	cout << "\n Missile pronto per il lancio!";
	cout << "\n\n Inserisci la coordinata x: ";
	cin >> f_x;
	cout << " Inserisci la coordinata y: ";
	cin >> f_y;

	if(campo_2[f_x][f_y]== ARIA)
	{
		system("cls");

		campo_2[f_x][f_y] = campo_2[f_x][f_y] + AIR_HOLE;

		banner();
    	
		WHITE;
    	cout << "\n";
    	cout << " \tLEGGENDA: \n"; 
		BLUE;
		cout << "~";
		WHITE;
		cout << " = ARIA\n"; 
		cout << "O = MANCATO\n";
		YELLOWN; 
		cout <<"^";
		WHITE;
		cout <<" = JET\n"; 
		RED;
		cout <<"X";
		WHITE;
		cout <<" = COLPITO\n\n";
    	
		sky_2();
		gene();

		voice = rand()%5;

		WHITE;
		switch ( voice )
		{
			case 0:
        		cout << "\n\t\t\t Hai ucciso due gabbiani,\n\t\t\t ritenta soldato.\n\n";
        		break;

			case 1:
        		cout << "\n\t\t\t Hai una pessima mira\n\t\t\t soldato.\n\n";
        		break;

        	case 2:
        		cout << "\n\t\t\t Le munizioni non sono\n\t\t\t infinite!\n\n";
        		break;

    		case 3:
    			cout << "\n\t\t\t Acqu... volevo dire Aria!\n\n";
    			break;

            case 4:
    			cout << "\n\t\t\t Impegnati di piu' se non\n\t\t\t vuoi finire a sbucciare\n\t\t\t patate!\n\n";
    			break;
		}
	}

	if(campo_2[f_x][f_y] == JET)
	{
        system("cls");

		campo_2[f_x][f_y] = campo_2[f_x][f_y] + JET;
		
		banner();
		
		cout << "\n";
    	cout << " \tLEGGENDA: \n ~ = ARIA\n O = MANCATO\n ^ = JET\n X = COLPITO\n\n";
    	cout << "     CAMPO NEMICO\n";
    	
		sky_2();
		gene();

		voice = rand()%3;

		YELLOWN;
		switch ( voice )
		{
			case 0:
        		cout << "\n\t\t\t JET abbattuto, ottimo\n\t\t\t lavoro soldato.\n\n ";
        		break;

			case 1:
        		cout << "\n\t\t\t Ottima mira\n\t\t\t soldato.\n\n";
        		break;

        	case 2:
        		cout << "\n\t\t\t Ottimo lavoro\n\t\t\t colpo perfetto\n\n";
        		break;
		}
	}

}

void sparo_2 (int& s_x, int& s_y)
{	
	int voice = 0;
	
	srand(time(NULL));

    s_x = rand()%N;
    s_y = rand()%N;

	if(campo_1[s_x][s_y]== ARIA)
	{
		campo_1[s_x][s_y] = campo_2[s_x][s_y] + AIR_HOLE;
		
		banner();
		sky_1();
        gene();

		voice = rand()%3;
		
		WHITE;
		switch ( voice )
		{
			case 0:
        		cout << "\n\t\t\t Il missile non\n\t\t\t ci ha arrecato danni.\n\n";
        		break;

			case 1:
        		cout << "\n\t\t\t Ti ha mancato, \n\t\t\t ora tocca a noi.\n\n";
        		break;

        	case 2:
        		cout << "\n\t\t\t Ti ha mancato, ma non \n\t\t\t abbassare la guardia.\n\n";
        		break;
		}
	}

	if(campo_1[s_x][s_y]== JET)
	{
		campo_1[s_x][s_y] = campo_1[s_x][s_y] + JET;
		
        banner();
		sky_1();
		gene();

		cout << "\n\t\t Jet abbattuto\n\n";
	}

}

void win (void)
{
    int c = 0;
    int i,j;

    for(i=0; i<N; i++)
    {
		for(j=0; j<N; j++)
        {
            if(campo_2[j][i] == SCRAP)
            {
            	c++;
            	if(c == WIN)
            	{
            		cout <<" Abbiamo abbattuto tutti i JET nemci, abbiamo vinto!";

					system("PAUSE");
            		menu();
            		system("cls");
				}
            }
        }
    }

    //cout <<"count = "<< c;
}

void lose (void)
{
	int c;			//count
    int i,j;

    for(i=0; i<N; i++)
    {
		for(j=0; j<N; j++)
        {
            if(campo_1[j][i] == SCRAP)
            {
            	c++;
				if(c == WIN)
				{
					cout << " Il nostro battaglione e' stato abbattuto, abbiamo perso.";
				
					system("PAUSE");
					menu();
            		system("cls");
				}
            }
        }
    }
}
