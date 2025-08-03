# Registro Attività (ToDo List)

Progetto sviluppato in C++ per l'esame di **Laboratorio di Programmazione** (A.A. 2024–2025).  
L'applicazione permette di gestire un semplice registro di attività quotidiane tramite interfaccia testuale.

---

## Funzionalità

- Aggiunta attività con descrizione e data di scadenza
- Rimozione di task esistenti
- Possibilità di marcare task come completati
- Visualizzazione elenco completo delle attività
- Visualizzazione statistiche generali
- Salvataggio automatico delle attività su file (`todo.txt`)
- Caricamento automatico da file all'avvio
- Organizzazione modulare in classi: `ToDo`, `ToDoList`, `Date`
- Interfaccia utente semplice e intuitiva via terminale
- Uso di CMake per la gestione del build
- Versionamento del codice con Git

## Struttura

```
Lab_Programmazione/
├── main.cpp          # Interfaccia utente
├── ToDoList.h/cpp    # Gestione lista
├── ToDo.h/cpp        # Singoli task
├── Date.h/cpp        # Gestione date
└── CMakeLists.txt    # Build system
```

## Compilazione

**Con CLion**: Aprire il progetto e premere Build

**Da terminale**:

```bash
mkdir build && cd build
cmake .. && cmake --build .
```

**Rapida**:

```bash
g++ -std=c++11 *.cpp -o myToDoList
```

## Utilizzo

L'applicazione presenta un menu interattivo con 10 opzioni principali per la gestione completa delle attività:

- Aggiungere nuovi task
- Completare task esistenti
- Visualizzare l'elenco delle attività
- Consultare statistiche dettagliate
- Salvare e caricare dati da file

Il programma utilizza un'interfaccia testuale semplice e guidata, adatta per l'uso da terminale.

---

**Roxana Merla - Matricola 7075963**
