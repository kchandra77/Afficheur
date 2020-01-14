#ifndef LIGNE_H
#define LIGNE_H

#include <string.h>
#include <string>

using namespace std;

//!  Classe de gestion d'une ligne de l'afficheur 
/*!
  Elle gère le message à afficher sur une ligne de l'afficheur ainsi que les effets à appliquer. Une ligne est caractérisée par : \n
  1) son numéro de ligne : notre afficheur ne pouvant afficher qu'une seule ligne à la fois, ce numéro vaudra '1'. Les méthodes d'accès sont : getNumeroLigne() et setNumeroLigne() \n
  2) son numéro de page : notre afficheur est capable de gérer plusieurs page. Cependant, pour des raisons de simplification, nous n'utiliserons qu'une seule page. La première page se nommera donc 'A'. Les méthodes d'accès sont getNumeroPage() et setNumeroPage().\n
  3) son effet de chargement : le texte peut appaître immediatement, arrivé de la droite ou de la gauche, avec un effet de neige... tous ces effets sont décrits dans l'énumération EffetChargement. 
  */

//! Énumération EffetChargement
/*! Cette énumération donne la liste de tous les effets de chargement possibles.*/
typedef enum {	
  LEADING_IMMEDIATE = 0 /*!< Apparition immédiate */,
  LEADING_XOPEN /*!< Ouverture comme un X */,
  LEADING_CURTAIN_UP/*!< Apparition ligne par ligne du bas vers le haut */,
  LEADING_CURTAIN_DOWN/*!< Apparition ligne par ligne du haut vers le bas */,
  LEADING_SCROLL_LEFT/*!< Le texte arrive de la droite vers la gauche */,
  LEADING_SCROLL_RIGHT/*!< Le texte arrive de la gauche vers la droite */,
  LEADING_VOPEN/*!< */,
  LEADING_VCLOSE,
  LEADING_SCROLL_UP,
  LEADING_SCROLL_DOWN,
  LEADING_HOLD,
  LEADING_SNOW,
  LEADING_TWINKLE,
  LEADING_BLOCK_MOVE,
  LEADING_RANDOM,
  LEADING_HELLO_WORLD,
  LEADING_WELCOME,
  LEADING_AMPLUS
} EffetChargement;

typedef enum {
  NORMAL = 0,
  BLINKING,
  SONG_1,
  SONG_2,
  SONG_3
} EffetAffichage;

typedef enum {
  W_0_5_SEC = 0,
  W_1_SEC,
  W_2_SEC,
  W_3_SEC,
  W_4_SEC,
  W_5_SEC,
  W_6_SEC,
  W_7_SEC,
  W_8_SEC,
  W_9_SEC,
  W_10_SEC,
  W_11_SEC,
  W_12_SEC,
  W_13_SEC,
  W_14_SEC,
  W_15_SEC,
  W_16_SEC,
  W_17_SEC,
  W_18_SEC,
  W_19_SEC,
  W_20_SEC,
  W_21_SEC,
  W_22_SEC,
  W_23_SEC,
  W_24_SEC,
  W_25_SEC
} TemporisationAffichage;

typedef enum {
  LAGGING_IMMEDIATE = 0,
  LAGGING_XOPEN,
  LAGGING_CURTAIN_UP,
  LAGGING_CURTAIN_DOWN,
  LAGGING_SCROLL_LEFT,
  LAGGING_SCROLL_RIGHT,
  LAGGING_VOPEN,
  LAGGING_VCLOSE,
  LAGGING_SCROLL_UP,
  LAGGING_SCROLL_DOWN,
  LAGGING_HOLD
} EffetSortie;


class Ligne
{
  
  
public:
     //! Un constructeur.
    /*!
      Le constructeur sans argument. Il initialise les attributs de l'objet avec des valeurs par défaut. Le message est "Hello", le numéro de la ligne est 1, le numéro de la page est 'A', l'effet de chargement est LEADING_SCROLL_LEFT, l'effet d'affichage est NORMAL, la temporisation d'affichage est de 2 secondes et l'effet de sortie est LAGGING_SCROLL_LEFT.
      \sa setMessage(), setNumeroLigne(), setNumeroPage(), setEffetChargement(), setEffetAffichage(), setTemporisationAffichage(), setEffetSortie(), ~Ligne()
    */
    Ligne () ;
    
     //! Un constructeur.
    /*!
      Le constructeur à un argument. L'argument attendu est le message à afficher. Sinon, par défaut, le numéro de la ligne est 1, le numéro de la page est 'A', l'effet de chargement est LEADING_SCROLL_LEFT, l'effet d'affichage est NORMAL, la temporisation d'affichage est de 2 secondes et l'effet de sortie est LAGGING_SCROLL_LEFT.
      \sa setMessage(), setNumeroLigne(), setNumeroPage(), setEffetChargement(), setEffetAffichage(), setTemporisationAffichage(), setEffetSortie(), ~Ligne()
    */
    Ligne ( const char * message, unsigned int longueurMessage );
    Ligne ( string message );
    
     //! Le destructeur.
    /*!
      Le destructeur ne fait rien de particulier.
      \sa Ligne()
    */
    ~Ligne();

    //! Méthode d'accès permettant de lire l'attribut m_numeroLigne.
    /*!
      \return Cette méthode renvoie le numero de la ligne.
      \sa setNumeroLigne()
    */
    inline int getNumeroLigne() const { return m_numeroLigne;}

    //! Méthode d'accès permettant de modifier l'attribut m_numeroLigne.
    /*!
      \param numeroLigne le nouveau numero de ligne.
      \sa getNumeroLigne()
    */
    inline void setNumeroLigne(int numeroLigne) {m_numeroLigne = numeroLigne; m_paquetDonnees[2] = '0' + numeroLigne; }

    //! Méthode d'accès permettant de lire l'attribut m_numeroPage.
    /*!
      \return Cette méthode renvoie le numero de la page.
      \sa setNumeroPage()
    */
    inline char getNumeroPage() const { return m_numeroPage;}

    //! Méthode d'accès permettant de modifier l'attribut m_numeroPage.
    /*!
      \param numeroPage le nouveau numero de page.
      \sa getNumeroPage()
    */
    inline void setNumeroPage(char numeroPage) {m_numeroPage = numeroPage; m_paquetDonnees[6] = numeroPage; }


    //inline const char * getMessage() const { return m_message;}
    //inline void setMessage(const char message[]) {strcpy(m_message,message); strcpy(m_paquetDonnees+24,message); }
    inline string getMessage() const {return m_message;}
    inline void setMessage( string message) {m_paquetDonnees.erase(24); m_paquetDonnees += message;}

    inline EffetChargement getEffetChargement() const {return m_effetChargement;}
    inline void setEffetChargement(EffetChargement effetChargement) { m_effetChargement = effetChargement; m_paquetDonnees[10] = 'A' + effetChargement;}

    inline EffetAffichage getEffetAffichage() const {return m_effetAffichage;}
    inline void setEffetAffichage(EffetAffichage effetAffichage) { m_effetAffichage = effetAffichage; m_paquetDonnees[14] = 'A' + effetAffichage; }

    inline TemporisationAffichage getTemporisationAffichage() const {return m_temporisationAffichage;}
    inline void setTemporisationAffichage(TemporisationAffichage temporisationAffichage) { m_temporisationAffichage = temporisationAffichage; m_paquetDonnees[18] = 'A' + temporisationAffichage;}

    inline EffetSortie getEffetSortie() const {return m_effetSortie;}
    inline void setEffetSortie(EffetSortie effetSortie) { m_effetSortie = effetSortie; m_paquetDonnees[22] = 'A' + effetSortie;}

    /* Autres méthodes */
//    inline const char * getPaquetDonnees() const {return m_paquetDonnees;};
    inline string getPaquetDonnees() const {return m_paquetDonnees;}

private:

    // Le message à afficher
    //char m_message[15];
    string m_message;
    // Le numéro de page et de ligne
    int m_numeroLigne;
    char m_numeroPage;
    // Les effets en entrée
    EffetChargement m_effetChargement;
    EffetAffichage m_effetAffichage;
    TemporisationAffichage m_temporisationAffichage;
    EffetSortie m_effetSortie;
    // Le message à afficher avec numéro de page, de ligne, et les effets et le checksum.
    //char m_paquetDonnees[255];
    string m_paquetDonnees;
    void preparerPaquetDonnees();

};

#endif
