/**
 * Author: github @jinpa-t
 * Description: Definition of Player class.
 * Date: 7/12/2022
*/
class Player {
  private:
    std::string plrName;
    int health = 100;
  public:
    Player() { }
    
    Player(std::string name) {
      plrName = name;
    }
    
    ~Player() { }
    
    void setName(std::string n){
      plrName = n;
    }
    
    std::string getName() const {
      return plrName;
    }
    
    int getHealth() const {
      return health;
    }
    
    int getAttackPower() const {
      return rand() % (25);
    }
    
    void takeDamage(int n) {
      health -= n;
    }
};
