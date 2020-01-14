#ifndef DATEHEURE_H
#define DATEHEURE_H
#include <string>
using namespace std;

typedef enum {JANVIER=1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE } Mois;
typedef enum {LUNDI=1, MARDI, MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE} JourDeLaSemaine;


class DateHeure
{
private :
  int m_annee;
  JourDeLaSemaine m_jourDeLaSemaine;
  Mois m_mois;
  unsigned char m_jour;
  unsigned char m_heure;
  unsigned char m_minute;
  unsigned char m_seconde;
public:
  DateHeure();
  ~DateHeure();
  // Les méthodes d'accès
  inline void setAnnee(int annee) {m_annee = annee;}
  inline int getAnnee() const {return m_annee;}
  inline void setJourDeLaSemaine(JourDeLaSemaine jourDeLaSemaine) {m_jourDeLaSemaine = jourDeLaSemaine;}
  inline JourDeLaSemaine getJourDeLaSemaine() const {return m_jourDeLaSemaine;}
  inline void setMois(Mois mois) {m_mois = mois;}
  inline Mois getMois() const {return m_mois;}
  inline void setJour(unsigned char jour) {m_jour = jour;}
  inline unsigned char getJour() const {return m_jour;}
  inline void setHeure(unsigned char heure) {m_heure = heure;}
  inline unsigned char getHeure() const {return m_heure;}
  inline void setMinute(unsigned char minute) {m_minute = minute;}
  inline unsigned char getMinute() const {return m_minute;}
  inline void setSeconde(unsigned char seconde) {m_seconde = seconde;}
  inline unsigned char getSeconde() const {return m_seconde;}
  // Autres méthodes
  inline void setDate(int annee, Mois mois, JourDeLaSemaine jourDeLaSemaine) {m_annee = annee; m_mois = mois; m_jourDeLaSemaine = jourDeLaSemaine;}
  inline void setHeure(unsigned char heure, unsigned char minute, unsigned char seconde) {m_heure = heure; m_minute = minute ; m_seconde = seconde;}
  string stringDescription() const;

};
#endif
