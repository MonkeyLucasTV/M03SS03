#include <iostream>
#include <string>
#include "IRClientTCP.h"

int main(){

	IRClientTCP passDomo;

       	char * reponse;

	passDomo.SeConnecterAUnServeur("172.20.21.5",80);

		std::string requete ="GET /api/F276DD7951/sensors HTTP/1.1\r\nHost: 172.20.21.5\r\nConnection: keep-alive\r\n";

	passDomo.Envoyer(requete.c_str(),requete.length());
	passDomo.Recevoir(reponse,10000);


		std::string reponseString = reponse;
		int debutDonnee = reponseString.find("\r\n\r\n", 0);
		reponseString= reponseString.substr(debutDonnee);

	passDomo.SeDeconnecter();
	std::cout << reponseString << endl;

	std::cin.get();


}
