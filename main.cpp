#include <iostream>
#include <string>

std::string chiffrementCesar(const std::string& texte, int decalage) {
    std::string resultat = "";

    for (char caractere : texte) {
        if (caractere == ' ') {
            // Ne pas chiffrer les espaces, les conserver inchangés
            resultat += ' ';
        } else {
            // Chiffrer les caractères alphabétiques en tenant compte du décalage
            char nouveauCaractere = 'A' + (caractere - 'A' + decalage) % 26;
            resultat += nouveauCaractere;
        }
    }

    return resultat;
}

int main() {
    int decalage;
    std::string texte;

    // Demander à l'utilisateur d'entrer la clé de chiffrement
    std::cout << "Entrez la clé de chiffrement (entier) : ";
    std::cin >> decalage;

    // Ignorer le caractère de nouvelle ligne restant dans le buffer
    std::cin.ignore();

    // Demander à l'utilisateur d'entrer le texte à chiffrer
    std::cout << "Entrez le texte à chiffrer : ";
    std::getline(std::cin, texte);

    // Chiffrer le texte avec la clé fournie
    std::string texteChiffre = chiffrementCesar(texte, decalage);

    // Afficher le texte original et le texte chiffré
    std::cout << "Texte original : " << texte << std::endl;
    std::cout << "Texte chiffré : " << texteChiffre << std::endl;

    return 0;
}
