``` mermaid
sequenceDiagram
    actor Utilisateur
    participant Main
    participant Console
    participant Gui
    
    Utilisateur->>Main: Lancer le programme
    Main->>Utilisateur: Demander le mode (c/g)
    Utilisateur->>Main: Saisir le mode
    Main->>Utilisateur: Demander chemin fichier
    Utilisateur->>Main: Saisir le chemin
    
    alt Chemin vide
        Main->>Utilisateur: Erreur: Chemin vide
        Main->>Main: Retourner 1
    else Mode Console
        Main->>Utilisateur: Demander nb itérations
        Utilisateur->>Main: Saisir itérations
        alt Paramètre invalide
            Main->>Utilisateur: Erreur: Paramètre invalide
            Main->>Main: Retourner 1
        else Paramètre valide
            Main->>Console: new Console(path, iterations)
            activate Console
            Main->>Console: run()
            Console->>Console: Exécuter simulation
            Console-->>Main: Fin simulation
            deactivate Console
            Main->>Main: Retourner 0
        end
    else Mode Graphique
        Main->>Gui: new Gui(path)
        activate Gui
        Main->>Gui: run()
        Gui->>Gui: Afficher interface graphique
        Gui-->>Main: Fin simulation
        deactivate Gui
        Main->>Main: Retourner 0
    else Mode invalide
        Main->>Utilisateur: Erreur: Mode invalide
        Main->>Main: Retourner 1
    end
```