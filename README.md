# Cesar
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


# chiffrement affine

#include <iostream>
#include <string>

// Fonction pour calculer le PGCD (Plus Grand Commun Diviseur)
int pgcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fonction pour trouver l'inverse multiplicatif modulo m
int inverseModulo(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // L'inverse multiplicatif n'existe pas
}

// Fonction pour chiffrer une lettre selon le chiffrement affine
char chiffrementAffine(char lettre, int a, int b) {
    if (isalpha(lettre)) {
        char base = isupper(lettre) ? 'A' : 'a';
        return (a * (lettre - base) + b) % 26 + base;
    }
    return lettre; // Si ce n'est pas une lettre, on le laisse inchangé
}

// Fonction pour chiffrer une chaîne de caractères avec le chiffrement affine
std::string chiffrementAffineString(const std::string &message, int a, int b) {
    std::string chiffre = "";
    for (char lettre : message) {
        chiffre += chiffrementAffine(lettre, a, b);
    }
    return chiffre;
}

int main() {
    // Clé du chiffrement affine (a et b)
    int a, b;

    // Demander à l'utilisateur de saisir les valeurs de la clé
    std::cout << "Entrez la valeur de a (premier paramètre) : ";
    std::cin >> a;
    std::cout << "Entrez la valeur de b (deuxième paramètre) : ";
    std::cin >> b;

    // Vérifier si la valeur de "a" est acceptable (PGCD(a, 26) doit être égal à 1)
    if (pgcd(a, 26) != 1) {
        std::cerr << "La valeur de 'a' n'est pas acceptable. Choisissez une autre valeur.\n";
        return 1;
    }

    // Saisir le message à chiffrer
    std::string message;
    std::cout << "Entrez le message à chiffrer (y compris les espaces) : ";
    std::cin.ignore(); // Pour éviter les problèmes avec getline après cin >>
    std::getline(std::cin, message);

    // Chiffrer le message
    std::string messageChiffre = chiffrementAffineString(message, a, b);

    // Afficher le message chiffré
    std::cout << "Message chiffré : " << messageChiffre << std::endl;

    return 0;
}


#chiffrement de lord Garnet


    Tout d'abord, la clé est saisie par l'utilisateur.
    Ensuite, le texte à chiffrer est saisi par l'utilisateur.
    Le message est chiffré en ajoutant la valeur de la clé à chaque lettre.
    Si la valeur de la lettre chiffrée est supérieure à z, elle est ramenée à une valeur inférieure à a en soustrayant la valeur de z et en ajoutant a - 1.
    Le message chiffré est ensuite affiché.
    Le message est ensuite déchiffré en soustrayant la valeur de la clé à chaque lettre.
    Si la valeur de la lettre déchiffrée est inférieure à a, elle est ramenée à une valeur supérieure à z en ajoutant la valeur de z et en soustrayant a - 1.
    Le message déchiffré est ensuite affiché.

Voici un exemple d'utilisation du code :

Entrez la clé : 3
Entrez le texte à chiffrer : Ceci est un message à chiffrer

Message chiffré : Dgo hq fhqwhvw lqv fhqwhvw

Message déchiffré : Ceci est un message à chiffrer



