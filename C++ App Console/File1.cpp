#include <iostream>
#include <string>
#include "IRClientTCP.h"
#include "IRJSONExtraction.h"




int main(){
	IRClientTCP passDomo;



	char reponse[10000];

	passDomo.SeConnecterAUnServeur("172.20.21.22",80);


	std::string requete ="GET /api/F276DD7951/sensors HTTP/1.1\r\nHost: 172.20.21.22\r\nConnection: keep-alive\r\n\r\n";

//
//	std::string requeteLampe ="PUT /api/F276DD7951/lights/3/state HTTP/1.1\r\nHost: 172.20.21.5\r\nConnection: keep-alive\r\n\r\n";

	passDomo.Envoyer(requete.c_str(),requete.length());


	int n=passDomo.Recevoir(reponse,10000);
	reponse[n]=0;
	std::string reponseString=reponse;

	n= passDomo.Recevoir(reponse,10000);
	reponse[n]=0;
	reponseString=reponseString+reponse;




	int debutDonnee = reponseString.find("\r\n\r\n", 0);
	reponseString= reponseString.substr(debutDonnee+4);
    std::string repString;


	char rep2[1000];

	while (1){

       int input;
	  std::cout << "choisissez 1 pour allumer 2 pour eteindre et ailleurs pour quitter)";
	  std::cin >> input;
	  std::string repString;

	if (input == 1) {
			std::string requeteLampe ="PUT /api/F276DD7951/lights/3/state HTTP/1.1\r\nHost: 172.20.21.22\r\nConnection: keep-alive\r\n\r\n{\"on\": true}";
			passDomo.Envoyer(requeteLampe.c_str(),requeteLampe.length());
		passDomo.Recevoir(rep2, 1000);

		std::cout << '\n' << '\n' << rep2 ;
		repString = rep2;
	}
	else if (input == 2) {
				   std::string requeteLampe ="PUT /api/F276DD7951/lights/3/state HTTP/1.1\r\nHost: 172.20.21.22\r\nConnection: keep-alive\r\n\r\n{\"on\": false}";
                   passDomo.Envoyer(requeteLampe.c_str(),requeteLampe.length());
					passDomo.Recevoir(rep2, 1000);

					std::cout << '\n' << '\n' << rep2 ;
					repString = rep2;
		 }
	else{
        break;
    }


	}
//
//	int n = passDomo.Recevoir(reponse,10000);
//	reponse[n] = 0;
//	RepTot = RepTot + reponse;


	passDomo.SeDeconnecter();

//   	std::cout << reponseString ;
 // std::cout << reponseString;

	std::cout << repString << '\n';

	IRJSONExtraction jSON;
	jSON.Extraction(repString);


	std::string jsonDescription = jSON.Description();
	std::cout << jsonDescription;

	std::string temp = jSON.ValeurAttributNiveau2("name","Temp A7-1","state","temperature");
	std::cout << "Il fait : "<< temp << " centieme de degres dans la salle" << '\n';

	std::string press = jSON.ValeurAttributNiveau2("name","Temp A6-1","state","pressure");
	std::cout << "La pression est de : " << press << " hPa dans la salle" <<'\n';

	std::string humid = jSON.ValeurAttributNiveau2("name", "Temp A6-1", "state", "humidity");
	std::cout << "Il y a " << humid << " % d'humidite dans la salle" << '\n';

	std::string type = jSON.ValeurAttributNiveau1("name","Temp A7-1", "type");
	std::cout << "Le type du capteur : " << type;



	std::cin.get();
	return 0;
}


