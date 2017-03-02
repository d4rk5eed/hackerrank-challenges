#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell {
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell {
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell {
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

Fireball* fbl = dynamic_cast<Fireball*>(spell);
if (fbl != NULL) {
    fbl->revealFirepower();
    return;
}

Frostbite* fbi = dynamic_cast<Frostbite*>(spell);
if (fbi != NULL) {
    fbi->revealFrostpower();
    return;
}

Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell);
if (ts != NULL) {
    ts->revealThunderpower();
    return;
}

Waterbolt* wtb = dynamic_cast<Waterbolt*>(spell);
if (wtb != NULL) {
    wtb->revealWaterpower();
    return;
}

  string x = SpellJournal::read();
  string y = spell->revealScrollName();
  int n = x.size();
  int m = y.size();
  int *z = new int[(n + 1) * (m + 1)];
  int **c = new int*[n + 1];
  for (auto i = 0; i <= n; i++) {
    c[i] = &z[i * (m + 1)];
  }
  for(auto j = 0; j <= m; j++) c[0][j] = 0;
  for(auto i = 0; i <= n; i++) c[i][0] = 0;

  for (auto i = 1; i <= n; i++) {
    for (auto j = 1; j <= m; j++) {
      if (x[i - 1] == y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      }
      else {
        c[i][j] = max(c[i - 1][j], c[i][j - 1]);
      }
    }
  }
  int lsb_max = c[n][m];
  cout << lsb_max<< endl;
}

class Wizard {
public:
  Spell *cast() {
    Spell *spell;
    string s; cin >> s;
    int power; cin >> power;
    if(s == "fire") {
      spell = new Fireball(power);
    }
    else if(s == "frost") {
      spell = new Frostbite(power);
    }
    else if(s == "water") {
      spell = new Waterbolt(power);
    }
    else if(s == "thunder") {
      spell = new Thunderstorm(power);
    }
    else {
      spell = new Spell(s);
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

int main() {
  int T;
  cin >> T;
  Wizard Arawn;
  while(T--) {
    Spell *spell = Arawn.cast();
    counterspell(spell);
  }
  return 0;
}
