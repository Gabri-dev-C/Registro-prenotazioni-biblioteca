# Registro prestiti biblioteca

Semplice programma che tiene traccia delle prenotazioni dei libri.
Attualmente il programma permette solo di aggiungere prenotazioni,
senza funzioni di ricerca o modifica.

## Tecnologie utilizzate

Una struct per la memorizzazione dei dati in memoria.
Un vettore di char usato come buffer per la scrittura dei dati in memoria di massa.
Una funzione trim() per una pulitura minimale dell'input utente.

## Salvataggio su file

I dati vengono salvati sul file di testo `registro.txt`. 
Il programma scrive i dati linea per linea, quindi è compatibile con qualsiasi editor di testo.

## Funzionalità

Il programma legge i dati in input e li scrive formattati sul file.

## Come usare il programma

1. Scarica la repository.
2. Compila il file `main.cpp` usando un compilatore C++.
3. Esegui il programma (`./esercizi` su Linux/Mac o `esercizi.exe` su Windows).

## Licenza

Questo progetto è rilasciato sotto licenza [MIT](https://opensource.org/licenses/MIT).
