#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli gasolina[100000 + 10]; // Armazena a quantidade de gasolina disponível em cada bomba
lli distancia[100000 + 10]; // Armazena a distância até a próxima bomba
queue<int> filaDeBombas; // Fila para armazenar os índices das bombas consideradas
long unsigned int numBombas; // Número total de bombas

// Macro para calcular o saldo de gasolina em uma bomba específica
#define saldo(bomba) (gasolina[bomba] - distancia[bomba])

int main(void) {
  long unsigned int i;
  cin >> numBombas;

  // Lendo os valores de gasolina e distância para cada bomba
  for (i = 0; i < numBombas; i++)
    cin >> gasolina[i] >> distancia[i];

  // Garantindo que a fila esteja vazia
  while (!filaDeBombas.empty())
    filaDeBombas.pop();

  filaDeBombas.push(0); // Começamos testando a partir da bomba 0

  lli saldoAcumulado = 0; // Mantém o saldo de gasolina enquanto percorremos as bombas
  int ultimoIndice = 0; // Última bomba considerada na tentativa de completar o circuito

  while (filaDeBombas.size() < numBombas) {
    ultimoIndice = filaDeBombas.back(); // Obtém o índice da última bomba adicionada à fila
    saldoAcumulado += saldo(ultimoIndice); // Atualiza o saldo de gasolina

    // Se o saldo for negativo, significa que não conseguimos avançar, então removemos bombas
    while (saldoAcumulado < 0 && !filaDeBombas.empty())
      filaDeBombas.pop();

    // Se a fila ficou vazia, reiniciamos o saldo
    if (filaDeBombas.empty())
      saldoAcumulado = 0;

    // Adicionamos a próxima bomba à fila
    filaDeBombas.push((ultimoIndice + 1) % numBombas);
  }

  // O primeiro elemento da fila é o ponto de partida ideal
  printf("%d\n", filaDeBombas.front());

  return 0;
}
