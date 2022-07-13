/**
 * Author: github @jinpa-t
 * Description: Two player game where computer selects randomly.
 * Date: 7/12/2022
*/
#include <iostream>
#include <unistd.h> // for delay
#include "rlutil.h" // for console color
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

int main() {
  // set console color
  rlutil::setColor(3);
  printf("**********************\n");
  Game * match1 = new Game();
  match1->setPlayers("John", "Vinny");
  match1->startGame();
  delete match1;

  return 0;
}