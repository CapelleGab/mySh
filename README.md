# 🧠 mysh - Mini Shell en C

`mysh` est un mini-interpréteur de commandes Unix développé en C. Il vous permet d'exécuter des commandes classiques comme `ls`, `cat`, `echo`, avec un support simple des redirections et des pipes.

## 🚀 Objectifs

- Créer un shell simple capable d'interpréter et d'exécuter des commandes.
- Implémenter les redirections (`>`, `<`) et les pipes (`|`).
- Tester en environnement isolé via Docker.
- Automatiser la compilation et les tests avec un Makefile et GitHub Actions.

## 📦 Fonctionnalités

- Exécution de commandes simples (`ls`, `cat`, etc.)
- Redirections d’entrée et de sortie (`<`, `>`)
- Pipes (`|`) entre plusieurs commandes
- Support du mode interactif (`mysh$`)
- Historique basique en mémoire (bonus)

## 📁 Structure du projet

```
mysh/
├── src/              # Code source
├── include/          # Fichiers d'en-tête
├── tests/            # Scripts de tests
├── Makefile          # Compilation et gestion
├── Dockerfile        # Conteneur d'exécution
├── .github/workflows # Intégration continue
├── README.md         # Ce fichier
└── TASK.md           # Plan de travail
```

## 🧰 Dépendances

- `gcc` ou `clang`
- `make`
- `docker`
- (Facultatif) `valgrind` pour la gestion mémoire

## ▶️ Lancer le shell

```bash
make
./mysh
```

## 🐳 Via Docker

```bash
make docker-run
```

## 🧪 Tests

Les tests se trouvent dans le dossier `tests/` et sont exécutés via `make test`.

## ⚙️ CI

GitHub Actions lance automatiquement les tests à chaque push sur `main`.

## 🧠 Auteurs

Projet personnel d'entraînement à C, Docker et CI/CD.
