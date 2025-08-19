# Registro Attività - ToDo List in C++11 (A.A. 2024–2025)

Applicazione da linea di comando per la gestione di attività quotidiane, sviluppata in C++11 con architettura modulare orientata agli oggetti, salvataggio persistente su file e test automatizzati. Progetto realizzato per l'esame di **Laboratorio di Programmazione**.

---

## Funzionalità

- Aggiunta di nuove attività con descrizione semplice
- Aggiunta di attività con descrizione e data di scadenza
- Rimozione di task esistenti dalla lista
- Possibilità di marcare attività come completate
- Visualizzazione dell'elenco completo delle attività
- Visualizzazione delle sole attività da completare
- Modifica della descrizione di task esistenti
- Consultazione di statistiche generali (completate, da completare, percentuali)
- Salvataggio e caricamento manuale da file con formato semplificato
- Gestione e validazione avanzata delle date (controllo anni bisestili)
- Validazione robusta degli input utente con controlli automatici
- Architettura modulare orientata agli oggetti: classi `ToDo`, `ToDoList`, `Date`
- Interfaccia utente testuale semplice e intuitiva
- Build system professionale basato su CMake
- Test unitari completi con Google Test framework v1.14.0
- Versionamento del codice con Git

---

## Struttura del progetto

```
Lab_Programmazione/
├── main.cpp             # Interfaccia utente e logica principale
├── ToDoList.h/cpp       # Gestione della lista di attività
├── ToDo.h/cpp           # Definizione e gestione dei singoli task
├── Date.h/cpp           # Gestione e validazione delle date
├── CMakeLists.txt       # Configurazione del build system
├── README.md            # Documentazione del progetto
├── build/               # Directory di compilazione (generata)
└── test/
    ├── test_date.cpp    # Test unitari per la classe Date
    ├── test_todo.cpp    # Test unitari per la classe ToDo
    └── test_todolist.cpp # Test unitari per la classe ToDoList
```

---

## Compilazione

### Con CLion

Aprire il progetto con CLion e premere **Build**.

### Da terminale (con CMake - raccomandato)

```bash
mkdir build && cd build
cmake .. && cmake --build .
```

### Compilazione rapida (senza CMake)

```bash
g++ -std=c++11 *.cpp -o myToDoList
```

---

## Utilizzo

L'applicazione presenta un **menu interattivo numerato** con 11 opzioni per la gestione completa delle attività:

1. **Aggiungi un nuovo todo** (solo descrizione)
2. **Aggiungi todo con data scadenza** (descrizione + data con validazione)
3. **Visualizza tutti i todos** (elenco completo numerato)
4. **Visualizza todos da completare** (solo task pendenti)
5. **Completa un todo** (marca come completato con input validato)
6. **Rimuovi un todo** (elimina dalla lista con conferma)
7. **Mostra statistiche** (contatori, percentuali di completamento)
8. **Modifica descrizione di un todo** (aggiorna testo esistente)
9. **Salva lista su file** (esporta in formato linea per linea)
10. **Carica lista da file** (importa da file salvato)
11. **Esci** (chiude l'applicazione)

Il programma utilizza un'interfaccia testuale semplice e guidata, con **validazione automatica** degli input numerici, gestione robusta degli errori e messaggi di conferma per ogni operazione.

---

## Testing

Il progetto include una **suite completa di test unitari** scritta con **Google Test**. I test coprono tutte le funzionalità principali delle classi `ToDo`, `ToDoList` e `Date`.

### Eseguire i test

Dopo aver compilato con CMake:

```bash
cd build
ctest
```

### Copertura dei test

- **Classe Date**: Validazione costruttori, getters/setters, controllo anni bisestili, operator==
- **Classe ToDo**: Creazione task, gestione completamento, manipolazione date e descrizioni
- **Classe ToDoList**: Operazioni CRUD complete, salvataggio/caricamento file, statistiche
- **Edge cases**: Gestione indici non validi, file inesistenti, date malformate
- **Integrazione**: Test del flusso completo di operazioni

---

## Tecnologie utilizzate

- **Linguaggio**: C++11 (standard universitario)
- **Paradigma**: Programmazione orientata agli oggetti
- **Build System**: CMake 3.10+ (compatibilità Windows/Linux)
- **Testing Framework**: Google Test v1.14.0
- **Controllo versione**: Git
- **Persistenza dati**: File di testo con formato semplificato linea per linea
- **Validazione**: Controlli automatici per input utente e date
- **Architettura**: Modulare con separazione responsabilità (header/implementation)

---

## Autore

**Roxana Merla** – Matricola 7075963  
Corso di Laurea in Ingegneria Informatica  
Esame di Laboratorio di Programmazione (A.A. 2024–2025)
