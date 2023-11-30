#include <iostream>
#include <string>

using namespace std;

int main() {
  // Saisie de la clé
  cout << "Entrez la clé : ";
  int clé;
  cin >> clé;

  // Saisie du texte à chiffrer
  cout << "Entrez le texte à chiffrer : ";
  string message;
  cin >> message;

  // Chiffrement du message
  for (int i = 0; i < message.length(); i++) {
    char lettre = message[i];
    int code = lettre - 'a';
    code = code + clé;
    if (code > 'z') {
      code = code - 'z' + 'a' - 1;
    }
    lettre = code + 'a';
    message[i] = lettre;
  }

  // Affichage du message chiffré
  cout << "Message chiffré : " << message << endl;

  // Déchiffrement du message
  for (int i = 0; i < message.length(); i++) {
    char lettre = message[i];
    int code = lettre - 'a';
    code = code - clé;
    if (code < 'a') {
      code = code + 'z' - 'a' + 1;
    }
    lettre = code + 'a';
    message[i] = lettre;
  }

  // Affichage du message déchiffré
  cout << "Message déchiffré : " << message << endl;

  return 0;
}
