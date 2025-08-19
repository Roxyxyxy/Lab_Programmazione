#include <iostream>
#include <string>
#include <limits>
#include "ToDoList.h"
#include "ToDo.h"
#include "Date.h"
using namespace std;

void showMenu()
{
    cout << "\n========== MENU PRINCIPALE ==========" << endl;
    cout << "1. Aggiungi un nuovo todo" << endl;
    cout << "2. Aggiungi todo con data scadenza" << endl;
    cout << "3. Visualizza tutti i todos" << endl;
    cout << "4. Visualizza todos da completare" << endl;
    cout << "5. Completa un todo" << endl;
    cout << "6. Rimuovi un todo" << endl;
    cout << "7. Mostra statistiche" << endl;
    cout << "8. Modifica descrizione di un todo" << endl;
    cout << "9. Salva lista su file" << endl;
    cout << "10. Carica lista da file" << endl;
    cout << "0. Esci" << endl;
    cout << "=====================================" << endl;
    cout << "Scegli un'opzione: ";
}

// Pulisce il buffer di input per evitare errori di lettura
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Date inputDate()
{
    int day, month, year;
    cout << "Inserisci giorno (1-31): ";
    cin >> day;
    cout << "Inserisci mese (1-12): ";
    cin >> month;
    cout << "Inserisci anno (2000-2100): ";
    cin >> year;

    Date date(day, month, year);

    // Controllo validità della data
    if (!date.isValid())
    {
        cout << "Data non valida! Verrà utilizzata una data vuota." << endl;
        return Date(); // Data vuota
    }

    return date;
}

// Funzione per leggere un numero valido
int inputNumber()
{
    int number;
    while (true)
    {
        cin >> number;
        if (cin.fail() || number <= 0)
        {
            cout << "Inserisci un numero valido (maggiore di 0): ";
            clearInput();
        }
        else
        {
            clearInput();
            return number;
        }
    }
}

int main()
{
    cout << "********** Benvenuto nella mia ToDo List! **********" << endl;
    cout << "\nQuesto è un programma per gestire i tuoi task." << endl;

    // Creiamo una lista todo
    ToDoList myList("La mia lista personale");

    // Aggiungiamo alcuni todos di esempio per iniziare
    cout << "\nAggiungo alcuni task di esempio..." << endl;
    myList.addTodo("Studiare programmazione C++");
    myList.addTodo("Fare la spesa");
    myList.addTodo("Chiamare il dottore", Date(15, 8, 2025));

    int choice;
    bool running = true;

    while (running)
    {
        showMenu();
        cin >> choice;

        if (cin.fail())
        {
            cout << "Input non valido! Inserisci un numero." << endl;
            clearInput();
            continue;
        }

        clearInput(); // Pulisce il buffer

        switch (choice)
        {
        case 1:
        {
            string description;
            cout << "Inserisci la descrizione del todo: ";
            getline(cin, description);
            myList.addTodo(description);
            cout << "Todo aggiunto con successo!" << endl;
            break;
        }
        case 2:
        {
            string description;
            cout << "Inserisci la descrizione del todo: ";
            getline(cin, description);
            cout << "Inserisci la data di scadenza:" << endl;
            Date dueDate = inputDate();
            myList.addTodo(description, dueDate);
            cout << "Todo con scadenza aggiunto con successo!" << endl;
            break;
        }
        case 3:
            myList.displayAll();
            break;
        case 4:
            myList.displayPending();
            break;
        case 5:
        {
            if (myList.isEmpty())
            {
                cout << "Non ci sono todos da completare!" << endl;
                break;
            }
            myList.displayAll();
            cout << "Quale todo vuoi completare? (numero): ";
            int todoNum = inputNumber();
            myList.markCompleted(todoNum);
            break;
        }
        case 6:
        {
            if (myList.isEmpty())
            {
                cout << "Non ci sono todos da rimuovere!" << endl;
                break;
            }
            myList.displayAll();
            cout << "Quale todo vuoi rimuovere? (numero): ";
            int todoNum = inputNumber();
            myList.removeTodo(todoNum);
            break;
        }
        case 7:
            myList.showStats();
            break;
        case 8:
        {
            if (myList.isEmpty())
            {
                cout << "Non ci sono todos da modificare!" << endl;
                break;
            }
            myList.displayAll();
            cout << "Quale todo vuoi modificare? (numero): ";
            int todoNum = inputNumber();
            string nuovaDescrizione;
            cout << "Inserisci la nuova descrizione: ";
            getline(cin, nuovaDescrizione);
            myList.editDescription(todoNum, nuovaDescrizione);
            break;
        }
        case 9:
        {
            string filename;
            cout << "Inserisci il nome del file (es. todolist.txt): ";
            getline(cin, filename);
            myList.saveToFile(filename);
            break;
        }
        case 10:
        {
            string filename;
            cout << "Inserisci il nome del file da caricare: ";
            getline(cin, filename);
            myList.loadFromFile(filename);
            break;
        }
        case 0:
            cout << "\nGrazie per aver usato la ToDo List!" << endl;
            cout << "Arrivederci!" << endl;
            running = false;
            break;
        default:
            cout << "Opzione non valida! Riprova." << endl;
            break;
        }
    }

    return 0;
}
