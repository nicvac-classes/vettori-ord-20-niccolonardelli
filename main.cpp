#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  srand(time(0)); // generatore random

  int n, i, j, cornici, coppie;

  // Creo la cassettiera L di N listelli. La lunghezza dei listelli viene
  // generata randomicamente.
  cout << "Inserire il numero di listelli a disposizione" << endl;
  cin >> n;
  vector<int> L(n);

  for (i = 0; i <= n - 1; i++) {
    L[i] = 4 + rand() % 7;
    cout << "Lunghezza " << i + 1 << "° listello: " << L[i] << endl;
  }

  // Conto le coppie disponibili (due listelli della stessa lunghezza)
  coppie = 0;
  for (i = 0; i <= n - 2; i++) {

    // Fissato il listello i, cerco fra tutti gli altri listelli j se ce n'è uno
    // della stessa lunghezza.
    j = i + 1;

    // Ricerco finchè non finiscono i listelli (cioè j<=N-1) e finchè non trovo
    // la coppia (cioè L[i]=0).
    while (j <= n - 1 and L[i] != 0) {
      if (L[i] == L[j]) {

        // Ho trovato una coppia. Marco le due celle trovate con 0. Solo le
        // celle diverse da 0 verranno contollate (perchè nella condizione del
        // ciclo ho L[i]=0, quindi se L[i]=0 in questo ciclo non si entra).
        coppie = coppie + 1;
        cout << "Trovata la coppia di " << L[i] << " cm " << endl;
        L[i] = 0;
        L[j] = 0;
      }
      j = j + 1;
    }
  }

  // Se ad es. le coppie trovate sono 5, allora 5/2 = 2.5, ma essendo cornici
  // intero, la parte dopo la virgola viene scartata, quindi le cornici
  // saranno 2.
  cornici = coppie / 2;
  cout << "Si possono produrre " << cornici << " cornici" << endl;
}
