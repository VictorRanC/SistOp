#include <iostream>
#include <cstdlib>
#include <thread>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

void Caballo(int n, int l){
  cout << "Caballo " << n+1 << " listo"<< endl;
  for (int i =0; i <= l; i++){
    std::this_thread::sleep_for(std::chrono::milliseconds(1 + rand() % (1200)));
    cout << " Parada " << i << " del caballo " << n +1 << endl;
  }
  cout << "El caballo " << n+1 << " llegó a la meta.  "<< endl;
}


int main() {
  int IntCaballos;
  int IntN;
  std::vector<std::thread> threads;
  srand(time(NULL));

  cout << "Ingrese la cantidad de caballos: " ;
  cin >> IntCaballos;
  cout << "Ingrese la cantidad de paradas(N): " ;
  cin >> IntN;

  for (int i = 0; i < IntCaballos; i++) {
    threads.push_back(std::thread(Caballo, i, IntN));
  }
 
  for (auto &th : threads) {
    th.join();
  }
  return 0;
}