#ifndef CAPTEUR_TEMPERATURE_H
#define CAPTEUR_TEMPERATURE_H

#include "Domotique.h"
#include <string>

class CapteurTemperature:public Domotique{
	private:
	std::string nom;

	public:
	CapteurTemperature(std::string IP,std::string cle, std::string _nom);
	std::string Temperature();
	std::string Humidite();
	std::string Pression();
	std::string Type();


};


#endif
