# Structures de données (printemps 2024) Exercices - Université de Genève

## Contenu
 - **TP0** : Introduction au C et au VSCode (s'assurer que l'on peut déboguer)
 - **TP1** : Types de données simples et pointeurs
 - **TP2** : Pile, file d'attente, liste
 - **TP3** : Arbres, arbres AVL
 - **TP4** : Graphes
 - **TP5** : Hachage, tables de hachage, chaînage


## Mise en place de l'environnement local
### VSCode
S'il n'est pas installé, téléchargez et installez [Visual Studio Code](https://code.visualstudio.com/). S'il n'est pas installé, installez-le avec :

- **Linux:** `sudo apt-get install code`
- **MacOS:** Depuis le [site web](https://code.visualstudio.com/)
- **Windows:** Depuis le [site web](https://code.visualstudio.com/)

Assurez-vous d'installer l'[extension C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) pour VSCode. Elle devrait fournir des fonctionnalités d'intellisense, de navigation dans le code et de débogage.

### Windows
Si vous êtes sous **Windows**, suivez ce [tutoriel](https://www.youtube.com/watch?v=-gxwT-eAfvU) :
1) Installez [MSYS2](https://www.msys2.org/) et exécutez toujours les commandes à partir du terminal de MSYS2.
2) Exécutez `pacman -Syu` pour mettre à jour la liste des paquets (appuyez sur 'Y' quand on vous le demande). Redémarrez MSYS2 et faites la même chose pour `pacman -Su`.
3) Cherchez *MINGW* dans le menu démarrer et ouvrez le terminal *MINGW64*.
4) Lancez `pacman -S mingw-w64-x86_64-gcc` pour installer le compilateur GNU C.
5) Lancez `pacman -S mingw-w64-x86_64-gdb` pour installer le débogueur GNU.
6) Lancez `pacman -S mingw-w64-x86_64-cmake` pour installer CMake.
7) Ajoutez le dossier `bin` de MSYS2 à la variable d'environnement PATH de votre système. Il s'agit généralement de `C:\msys64\mingw64\bin`.
8) Si ce n'est pas encore fait, installez git depuis le [site officiel](https://git-scm.com/).


### Linux
**Linux** : 
1) Exécutez `sudo apt-get update` pour mettre à jour la liste des paquets.
2) Lancez `sudo apt-get install gcc` pour installer le compilateur GNU C.
3) Lancez `sudo apt-get install gdb` pour installer le débogueur GNU.
4) Lancez `sudo apt-get install cmake` pour installer CMake.
5) S'il n'est pas encore installé (vérifiez avec `git --version`), installez git avec `sudo apt-get install git`.

### MacOS
**MacOS:**
1) Installez [Homebrew](https://brew.sh/). Il s'agit d'un gestionnaire de paquets pour MacOS. Vous pouvez l'installer en lançant la commande suivante dans votre terminal :

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

2) Lancez `brew install gcc` pour installer le compilateur GNU C.
3) Installez VSCode (section suivante) et installez l'extension [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) pour VSCode. Vous utiliserez `lldb` au lieu de `gdb` pour le débogage.
4) Lancez `brew install cmake` pour installer CMake.
5) S'il n'est pas encore installé (vérifiez avec `git --version`), installez git avec `brew install git`.


### TP0 : Débogage
Vous devriez maintenant être en mesure de déboguer votre code !

Effectuez les étapes suivantes pour lancer tp0 :
 1) Ouvrez `src/tp0/main.c` dans VSCode.
 2) Ajoutez un breakpoint (point rouge) à la ligne 15.
 3) Sélectionnez "Run and Debug" dans la barre latérale de VSCode, puis sélectionnez "tp0 macos", "tp0 linux" ou "tp0 windows" dans le menu déroulant en haut à gauche, en fonction de votre système.
 4) Appuyez sur le bouton vert pour lancer le débogage. Si le code s'arrête au point d'arrêt, vous êtes prêt à partir!

### Git et tests
Nous allons créer des projets GitLab et GitHub. **Assurez-vous de les rendre privés !** 
1) **(Optionnel)** Allez sur [gitlab](https://gitlab.unige.ch) et créez un nouveau projet appelé `std2024`.
2) Allez sur votre [github](https://github.com) personnel et créez un nouveau projet appelé `std2024`. Ajoutez **Brian.Pulfer@unige.ch**, **Arthur.Freeman@etu.unige.ch** et **Ethan.Arm@etu.unige.ch** comme collaborateurs. 
3) Dans le dossier `std2024`, exécutez les commandes suivantes pour configurer le repo git (une seule fois):
```bash
git init # Initialise le repo git
git remote add origin LINK_TO_GITHUB_REPO # Ajoute le repo github en amont
git remote add gitlab LINK_TO_GITLAB_REPO # Ajoute le repo gitlab en amont (Optionnel)
git branch -m main # Renomme la branche en main
git add . # Ajoute tous les fichiers à la zone de transit
git commit -m "Initial commit." # Commite les changements
git push -u origin main # Pousse le code sur github --> Les tests sont déclenchés !
git push -u gitlab main # Pousse le code vers gitlab (Optionnel)
```

## Contact
- **Assistant** : [Brian Pulfer](mailto:Brian.Pulfer@unige.ch)
- **Moniteurs** : [Arthur Freeman](mailto:Arthur.Freeman@etu.unige.ch), [Ethan Arm](mailto:Ethan.Arm@etu.unige.ch)