# 📋 Plan de tâches - Projet mysh

## 🎯 Objectif
Créer un interpréteur de commandes basique en C avec support Docker, Makefile et GitHub Actions CI.

---

## 🛠️ Étapes techniques

### 1. 🧱 Initialisation du projet
- [ ] Créer la structure de dossiers (src/, include/, tests/)
- [ ] Créer les fichiers : `main.c`, `mysh.h`, `Makefile`, `Dockerfile`, `.github/workflows/ci.yml`

### 2. 🔧 Compilation
- [ ] Écrire le `Makefile` avec les commandes : `all`, `clean`, `fclean`, `re`, `test`, `docker-run`

### 3. 📜 Lecture de commande
- [ ] Lire une ligne entrée par l'utilisateur (prompt `mysh$ `)
- [ ] Nettoyer les espaces, gérer les commandes vides
- [ ] Découper la ligne en arguments (`strtok` ou équivalent)

### 4. ⚙️ Exécution
- [ ] Exécuter une commande simple (ex: `ls`)
- [ ] Gérer les erreurs (commande introuvable)

### 5. 🔁 Boucle principale
- [ ] Répéter le prompt après chaque commande (jusqu'à `exit`)
- [ ] Gérer `Ctrl+C` (signal `SIGINT`) proprement

---

## ➡️ Fonctionnalités supplémentaires

### 6. 🔄 Redirections
- [ ] Implémenter la redirection de sortie (`>`)
- [ ] Implémenter la redirection d'entrée (`<`)

### 7. ⛓️ Pipes
- [ ] Gérer les pipes (`|`) entre plusieurs commandes
- [ ] Exécuter les commandes enchaînées avec `dup2` et `fork`

---

## 🐳 Docker

### 8. 🐋 Dockerfile
- [ ] Écrire un `Dockerfile` basé sur Alpine ou Debian
- [ ] Copier le code source et compiler le projet
- [ ] Ajouter une commande `ENTRYPOINT ["./mysh"]`

### 9. 🧪 Docker + Makefile
- [ ] Ajouter une règle `docker-build`
- [ ] Ajouter une règle `docker-run`

---

## ⚙️ Intégration continue (CI)

### 10. 📦 GitHub Actions
- [ ] Créer un fichier `.github/workflows/ci.yml`
- [ ] Compiler le projet
- [ ] Lancer des tests automatiques avec des fichiers d'entrée/sortie
- [ ] Comparer les résultats avec les fichiers attendus (`diff`)

---

## 🎁 Bonus

- [ ] Ajouter un historique des commandes
- [ ] Gérer les variables d’environnement (`$HOME`, etc.)
- [ ] Coloriser le prompt (`mysh$`) avec ANSI

---

## 🧼 Nettoyage

### 11. 🧹 Finalisation
- [ ] Valgrind : vérifier les fuites mémoire
- [ ] `make clean` pour supprimer les binaires
- [ ] `make fclean` pour tout nettoyer

---

## ✅ Finalisation
- [ ] Rédiger un rapport ou une documentation d’utilisation
- [ ] Publier sur GitHub
