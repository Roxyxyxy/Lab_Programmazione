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
- Consultazione di statistiche generali (completate, da completare, totali)
- Salvataggio manuale delle attività su file (`todo.txt`)
- Caricamento manuale da file tramite menu
- Gestione e validazione delle date
- Architettura modulare orientata agli oggetti: classi `ToDo`, `ToDoList`, `Date`
- Interfaccia utente testuale semplice e intuitiva
- Build system professionale basato su CMake
- Test unitari completi con Google Test framework
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
├── build/               # Directory di compilazione (generata)
└── test/
    └── test_todolist.cpp  # Test unitari con Google Test framework
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

L'applicazione presenta un **menu interattivo numerato** con 10 opzioni principali per la gestione completa delle attività:

1. **Aggiungi un nuovo todo** (solo descrizione)
2. **Aggiungi todo con data scadenza** (descrizione + data)
3. **Visualizza tutti i todos** (elenco completo)
4. **Visualizza todos da completare** (solo task pendenti)
5. **Completa un todo** (marca come completato)
6. **Rimuovi un todo** (elimina dalla lista)
7. **Mostra statistiche** (contatori e percentuali)
8. **Modifica descrizione di un todo** (aggiorna testo)
9. **Salva lista su file** (esporta in `todo.txt`)
10. **Carica lista da file** (importa da `todo.txt`)
11. **Esci** (chiude l'applicazione)

Il programma utilizza un'interfaccia testuale semplice e guidata, con validazione degli input e messaggi di conferma per ogni operazione.

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

- Creazione e gestione di task
- Operazioni sulla lista (aggiunta, rimozione, completamento)
- Salvataggio e caricamento da file
- Validazione delle date
- Gestione degli edge cases

---

## Tecnologie utilizzate

- **Linguaggio**: C++11
- **Paradigma**: Programmazione orientata agli oggetti
- **Build System**: CMake 3.25+
- **Testing Framework**: Google Test
- **Controllo versione**: Git
- **Persistenza dati**: File di testo (`todo.txt`)

---

## Autore

**Roxana Merla** – Matricola 7075963  
Corso di Laurea in Ingegneria Informatica  
Esame di Laboratorio di Programmazione (A.A. 2024–2025)
