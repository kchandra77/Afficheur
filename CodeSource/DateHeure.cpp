#include "DateHeure.h"
#include <time.h>
#include <sstream>
using namespace std;

DateHeure::DateHeure()
{
  time_t t;
  struct tm * heure;
  time(&t);
  heure = localtime(&t);
  m_annee = 1900 + heure->tm_year;
  m_mois = (Mois)(heure->tm_mon+1);
  m_jourDeLaSemaine = (JourDeLaSemaine) (((heure->tm_wday+6)%7)+1);
  m_jour = (unsigned char)heure->tm_mday;
  m_heure = (unsigned char)heure->tm_hour;
  m_minute = (unsigned char)heure->tm_min;
  m_seconde = (unsigned char)heure->tm_sec;
}


DateHeure::~DateHeure()
{
}

string DateHeure::stringDescription() const
{
  stringstream ss;
  switch(m_jourDeLaSemaine)
  {
    case 1: 
      ss << "Lundi";
      break;
    case 2:
      ss << "Mardi";
      break;
    case 3:
      ss << "Mercredi";
      break;
    case 4:
      ss << "Jeudi";
      break;
    case 5:
      ss << "Vendredi";
      break;
    case 6:
      ss << "Samedi";
      break;
    case 7:
      ss << "Dimanche";
      break;
  }
  ss << " " << (unsigned int)m_jour << " ";
  switch(m_mois)
  {
    case 1: 
      ss << "Janvier";
      break;
    case 2:
      ss << "Février";
      break;
    case 3:
      ss << "Mars";
      break;
    case 4:
      ss << "Avril";
      break;
    case 5:
      ss << "Mai";
      break;
    case 6:
      ss << "Juin";
      break;
    case 7:
      ss << "Juillet";
      break;
    case 8: 
      ss << "Aout";
      break;
    case 9:
      ss << "Septembre";
      break;
    case 10:
      ss << "Octobre";
      break;
    case 11:
      ss << "Novembre";
      break;
    case 12:
      ss << "Decembre";
      break;
  }
  ss << " " << m_annee << " - " ;
  if(m_heure<10) ss << "0";
  ss << (unsigned int) m_heure << ":";
  if(m_minute<10) ss << "0";
  ss << (unsigned int)m_minute << ":";
  if(m_seconde<10) ss << "0";
  ss << (unsigned int)m_seconde;
  
  return ss.str();
  
}