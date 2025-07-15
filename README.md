# Calculateur de section de câble pour le bâtiment

Cet outil, développé en C++ avec Qt, permet de faciliter le dimensionnement préliminaire des câbles électriques dans le domaine du bâtiment.

    ⚠️ Attention : Ce calculateur ne remplace pas une étude électrique complète réalisée avec des logiciels professionnels comme Caneco. Il sert uniquement à dégrossir le travail de chiffrage du matériel électrique.

Fonctionnalités :

    Champ "Source" :

        Applique automatiquement une chute de tension type en fonction du contexte d’utilisation : alimentation tableau ou alimentation terminale.

    Type de câble :

        Prend en compte le matériau (cuivre, aluminium...) et le type de brin pour adapter le calcul.

    Sélection des unités (I (A) / P (W) / S (VA)) :

        Permet d’entrer directement les données disponibles sur les équipements sans conversion manuelle.

    Champ "Chute de tension réelle" :

        Affiche la chute de tension résultante du calcul selon les paramètres saisis.

    Bouton "Obtenir section" :

        Lance le calcul de la section de câble recommandée.

# Objectif :

Cet outil vise à aider les électriciens et les professionnels du bâtiment à estimer rapidement la section des câbles nécessaires pour leurs installations, en tenant compte des contraintes courantes (longueur, puissance, chute de tension, etc.).




# Compilation : 
Assurez-vous d’avoir installé Qt, CMake et un compilateur C++ compatible (g++, clang++ ou MSVC).

## Cloner le dépôt (ou copier les fichiers sources dans un dossier)
cd chemin/vers/le/projet

## Créer un dossier de build et y entrer
mkdir build
cd build

## Générer les fichiers Make avec CMake
cmake ..

## Compiler le projet
make
