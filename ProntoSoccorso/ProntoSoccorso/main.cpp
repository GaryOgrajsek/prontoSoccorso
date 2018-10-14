#include "coda.h"
#include "coda.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Menu() {
	int sceltaMenu;
	cout << "1) Aggiungi un paziente" << endl;
	cout << "2) Elimina un paziente NO NON IN QUEL SENSO" << endl;
	cout << "3) Conta i pazienti" << endl;
	cout << "4) Salva i pazienti nel file"<<endl;
	cout << "5) Esci" << endl;
	cin >> sceltaMenu;
	return sceltaMenu;
}

void InizializzaCode(coda<string> & rossi, coda<string> & gialli, coda<string> & bianchi) {
	Init(rossi);
	Init(gialli);
	Init(bianchi);
}

void AggiungiPaziente(coda<string> & rossi, coda<string> & gialli, coda<string> & bianchi) {
	string nome="init name";
	int codice=0;
	cout << "Per terminare l'inserimento, inserisci . SOLO al nome." << endl;
	while (1) {
		cout << "Nome: ";
		cin >> nome;
		if (nome == ".")
			break;
		do {
			cout << "1=rossi, 2=gialli, 3=bianchi? ";
			cin >> codice;
		} while (codice < 1 || codice > 3);

		if (codice == 1) {
			Enqueue(rossi, nome);
		}
		else if (codice == 2) {
			Enqueue(gialli, nome);
		}
		else {
			Enqueue(bianchi, nome);
		}
	}
}

void EliminaPaziente(coda<string> & rossi, coda<string> & gialli, coda<string> & bianchi) {
	if (Empty(rossi) && Empty(gialli)) {
		Dequeue(bianchi);
	}
	else if (Empty(rossi)) {
		Dequeue(gialli);
	}
	else {
		Dequeue(rossi);
	}
}

void ContaPazienti(coda<string> rossi, coda<string> gialli, coda<string> bianchi) {
	int nRossi = 0, nGialli = 0, nBianchi = 0;
	while (!(Empty(rossi))) {
		Dequeue(rossi);
		nRossi++;
	}
	cout << "ROSSI: " << nRossi << endl;

	while (!(Empty(gialli))) {
		Dequeue(gialli);
		nGialli++;
	}
	cout << "GIALLI: " << nGialli << endl;

	while (!(Empty(bianchi))) {
		Dequeue(bianchi);
		nBianchi++;
	}
	cout << "BIANCHI: " << nBianchi << endl;
}


int main() {
	coda<string> pazientiRossi, pazientiGialli, pazientiBianchi;
	InizializzaCode(pazientiRossi, pazientiGialli, pazientiBianchi);
	bool continua = true;
	while (1) {
		switch (Menu()) {
		case 1:
			AggiungiPaziente(pazientiRossi, pazientiGialli, pazientiBianchi);
			break;
		case 2:
			EliminaPaziente(pazientiRossi, pazientiGialli, pazientiBianchi);
			break;
		case 3:
			ContaPazienti(pazientiRossi, pazientiGialli, pazientiBianchi);
			break;
		case 4:
			//SalvaPazienti(pazientiRossi, pazientiGialli, pazientiBianchi);
			break;
		case 5:
			cout << "Termine del programma!" << endl;
			system("PAUSE");
			return 0;
		default:
			cout << "Scelta	NON corretta!" << endl;
		}
		system("CLS");
	}
}
