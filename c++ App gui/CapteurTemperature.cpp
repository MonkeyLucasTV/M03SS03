#include "CapteurTemperature.h"
#include <string>



CapteurTemperature::CapteurTemperature(std::string IP, std::string cle, std::string _nom):
Domotique(IP,cle)
{
	nom=_nom;
}


std::string CapteurTemperature::Temperature(){
	jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau2("name",nom,"state","temperature");

}

std::string CapteurTemperature::Humidite(){
	jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau2("name",nom,"state","humidity");
}

std::string CapteurTemperature::Pression(){
	jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau2("name",nom,"state","pressure");
}

std::string CapteurTemperature::Type(){

	jSON.Extraction(GetAppareil("sensors"));
	return jSON.ValeurAttributNiveau1("name",nom,"type");
}



