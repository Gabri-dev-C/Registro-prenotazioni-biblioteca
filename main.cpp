#include <iostream>
#include <cstring>
using namespace std;

struct prenotazione{			// struttura del record
    char data_prenotazione[11];
    char cliente[50];
    char libro[30];
};

void gh_trim(char s[]);			// tolgo spazi prima e dopo la stringa

int main(){
    prenotazione nuova_prenotazione;
    char buffer[200] = "";		// buffer per scrivere e leggere i record
    int i;
    FILE* punta_file;
    bool scrittura_riuscita = true;

    // gestione dell'input
    cout << "Inserisci la data della prenotazione (gg/mm/aaaa): ";
    cin >> nuova_prenotazione.data_prenotazione;
    cin.ignore();
    cout << "Inserisci nome e cognome del cliente: ";
    cin.getline(nuova_prenotazione.cliente, 50);
    cout << "Inserisci titolo del libro: ";
    cin.getline(nuova_prenotazione.libro, 30);

    // pulizia dell' input
    gh_trim(nuova_prenotazione.data_prenotazione);
    gh_trim(nuova_prenotazione.cliente);
    gh_trim(nuova_prenotazione.libro);

    // Preparazione del buffer
    strcat(buffer, nuova_prenotazione.data_prenotazione);
    strcat(buffer, ";");
    strcat(buffer, nuova_prenotazione.cliente);
    strcat(buffer, ";");
    strcat(buffer, nuova_prenotazione.libro);
    strcat(buffer, "\n");

    // apro l'associazione al file in accodamento
    if(fopen_s(&punta_file, "registro.txt", "a") != 0){
        cout << "ERRORE: il file non può essere aperto\n";
        system("PAUSE");
        return 1;
    }

    // scrivo il buffer nel file
    if(fputs(buffer, punta_file) == EOF){
        cerr << "ERRORE: nella scrittura del file\n";
        scrittura_riuscita = false;
    }

    // chiudo l'associazione al file
    if (fclose(punta_file) == EOF){
        cerr << "ERRORE: nella chiusura del file\n";
        scrittura_riuscita = false;
    }

    if(scrittura_riuscita)
        cout << "Prenotazione registrata con successo!\n";

    return 0;
}

// la funzione toglie gli spazi dall'inizio e dalla fine
// della stringa inserita come parametro
void gh_trim(char s[]){
    int i = 0, j = 0;

    if(s[i] == '\0'){
        cout << "ERRORE: la stringa e' vuota";
        return 1;
    }

    while(s[i] == ' ') i++;     // conto gli spazi a inizio stringa.

    if(s[i] == '\0'){
        cout << "ERRORE: la stringa e' composta solo da spazi";
        return 1;
    }

    j = i;
    i = 0;

    while(s[j] != '\0'){        // tolgo gli spazi a inizio riga, sovrascrivendoli
        s[i] = s[j];
        i++;
        j++;
    }

    j--;                        // punto l'ultimo carattere

    while (s[j] == ' ') j--;    // conto gli spazi a fine riga

    s[j+1] = '\0';              // tolgo gli spazi a fine riga

    return 0;
}
