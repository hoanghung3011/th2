#include <iostream>
#include <fstream>

using namespace std;

int format(char *cardPoint) {
  int point = 0;
  switch (cardPoint[0]) {
    case '2':
      point = point + 0;
      break;
    case '3':
      point = point + 4;
      break;
    case '4':
      point = point + 8;
      break;
    case '5':
      point = point + 12;
      break;
    case '6':
      point = point + 16;
      break;
    case '7':
      point = point + 20;
      break;
    case '8':
      point = point + 24;
      break;
    case '9':
      point = point + 28;
      break;
    case 'T':
      point = point + 32;
      break;
    case 'J':
      point = point + 36;
      break;
    case 'Q':
      point = point + 40;
      break;
    case 'K':
      point = point + 44;
      break;
    case 'A':
      point = point + 48;
      break;
  }

  switch (cardPoint[1]) {
    case 'B':
      point = point + 1;
      break;
    case 'N':
      point = point + 2;
      break;
    case 'R':
      point = point + 3;
      break;
    case 'C':
      point = point + 4;
      break;
  }

  return point;
}

void inputCard(int &n, int(&CardCount)[100], int(&CardList)[100][2000]) {
  char filename[10000];
  ifstream card;
  card.open("card.inp");
  card >> n;
  char charPt[100];
  for (int i = 0; i < n; i++) {
    card >> CardCount[i];
    for (int j = 0; j < CardCount[i] * 2; j++) {
      card >> charPt;
      CardList[i][j] = format(charPt);
    }
  }
  card.close();
}

void CardSwapper(int &firstPt, int &secondPt) {
  int temp = firstPt;
  firstPt = secondPt;
  secondPt = temp;
}

void cardSort(int arrCount, int cardList[100]) {
  int score = 0;
  int EvaCard[100] = {0};
  int close[100] = {0};
  for (int i = 0; i < arrCount; i++) {
    EvaCard[i] = 1;
  }

  for (int i = 0; i < arrCount * 2; i++)
    for (int j = 0; j < arrCount * 2; j++) {
      if (cardList[i] < cardList[j]) {
        CardSwapper(cardList[i], cardList[j]);
        CardSwapper(EvaCard[i], EvaCard[j]);
      }
    }

  for (int i = 0; i < (arrCount * 2) - 1; i++) {
    if (EvaCard[i] == 1 && EvaCard[i + 1] == 0) {
      if (close[i] != 1 && close[i + 1] != 1) {
        score++;
        close[i] = 1;
        close[i + 1] = 1;
      }
    }
  }

  cout << score << "\n";
}

void playCard(int n, int CardCount[], int CardList[100][2000]) {
  for (int i = 0; i < n; i++) {
    cardSort(CardCount[i], CardList[i]);
  }
}

int main() {
  int n;
  int CardCount[100] = {0};
  int CardList[100][2000] = {0};
  inputCard(n, CardCount, CardList);
  playCard(n, CardCount, CardList);
  return 1;
}
