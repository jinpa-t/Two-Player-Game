/**
 * Author: github @jinpa-t
 * Description: Definition of Game class. 
 * Date: 7/12/2022
*/
class Game {
  private:
    unsigned int gameDuration = 100; //seconds
    Player *players = new Player[2];
    enum Turns{PLAYER1TURN,PLAYER2TURN};
    int currentTurn;
  public:
    Game();
    ~Game() { delete []players; }
    void startGame();
    void changeTurn();
    void intializeTurn();
    void setPlayers(std::string n1, std::string n2);
    void attackOpponent(Player & plrAttacking, Player & plrToAttack);
};

Game::Game() {
  std::cout << "Game created!\n";
}

void Game::startGame() {
  srand(time(NULL));
  intializeTurn();
  std::cout << currentTurn << std::endl;
  while (gameDuration >= 0) {
    //sleep second;
    std::cout << std::flush << gameDuration << std::endl;
    if (currentTurn == PLAYER2TURN) {
      attackOpponent(players[0], players[1]);
    } else {
      attackOpponent(players[1], players[0]);
    }
    changeTurn(); // flip turn
    std::cout << std::flush << players[0].getName() << " health: " << players[0].getHealth() << std::endl;
    std::cout << std::flush << players[1].getName() << " health: " << players[1].getHealth() << std::endl;
    if (players[0].getHealth() <= 0) {
      std::cout << "Game over: " << players[1].getName() << " has own the game!\n";
      break;
    }
    if (players[1].getHealth() <= 0) {
      std::cout << "Game over: " << players[0].getName() << " has own the game!\n";
      break;
    }
    // suspend the thread for 1 second
    usleep(1000000);
    gameDuration--;
  }
}

void Game::intializeTurn() {
  currentTurn = rand() % (2);
}

void Game::changeTurn() {
  currentTurn = PLAYER2TURN - currentTurn;
}

void Game::setPlayers(std::string n1, std::string n2) {
  players[0].setName(n1);
  players[1].setName(n2);
}

void Game::attackOpponent(Player & plrAttacking, Player & plrToAttack) {
  int attackPower = plrAttacking.getAttackPower();
  if (plrToAttack.getName() == players[1].getName()) {
    players[0].takeDamage(attackPower);
  } else {
    players[1].takeDamage(attackPower);
  }
}
