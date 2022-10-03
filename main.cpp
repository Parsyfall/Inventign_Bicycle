#include <iostream>
#include <vector>

bool find(std::vector<char> &, char);
void set_choice(std::vector<char> &, int &, int &);
bool valid(std::vector<char> &, int &);
bool in_bounds(int &);
bool Win(std::vector<char> &);
void PrintTable(std::vector<char> &);

int main() {
  std::vector<char> table(9, ' ');
  int cell = 0, round = 0;

  do {
    for (int i = 1; i <= 2; ++i) {
      std::cout << "Player " << i << ": ";
      do {
        std::cin >> cell;
      } while (!valid(table, cell));

      set_choice(table, cell, i);
      PrintTable(table);
      if (++round >= 5) {
        // check for winner of draw
        if (Win(table)) {
          return 0;
        }
      }
    }
  } while (true);
}

void set_choice(std::vector<char> &table, int &cell, int &i) {
  char ch = (i == 1) ? 'X' : 'O';
  table[cell] = ch;
}

void PrintTable(std::vector<char> &table) {
  std::cout << " " << table[0] << " | " << table[1] << " | " << table[2]
            << "\n";
  std::cout << "---+---+--- \n";
  std::cout << " " << table[3] << " | " << table[4] << " | " << table[5]
            << "\n";
  std::cout << "---+---+--- \n";
  std::cout << " " << table[6] << " | " << table[7] << " | " << table[8]
            << "\n";
}

bool Win(std::vector<char> &table) {
  // check rows
  for (int i = 0; i < 3; ++i) {
    if ((table[i * 3] == table[i * 3 + 1]) &&
        table[i * 3 + 1] == table[i * 3 + 2]) {
      std::cout << "Player " << table[i] << " won!\n";
      return true;
    }
  }

  // check colums
  for (int i = 0; i < 3; ++i) {
    if (table[i] == table[i + 3] && table[i + 3] == table[i + 6]) {
      std::cout << "Player " << table[i] << " won!\n";
      return true;
    }
  }

  // check main diagonal
  if (table[0] == table[4] && table[4] == table[8]) {
    std::cout << "Player " << table[0] << " won!\n";
    return true;
  }

  // check secondary diagonal
  if (table[5] == table[4] && table[4] == table[2]) {
    std::cout << "Player " << table[2] << " won!\n";
    return true;
  }

  // check draw
  if (!find(table, ' ')) {
    std::cout << "\nDraw\n";
    std::terminate();
  }

  // default
  return false;
}

bool find(std::vector<char> &table, char key) {
  for (std::vector<char>::iterator it = table.begin(); it < table.end(); ++it) {
    if (*it == key)
      return true;
  }
  return false;
}

bool in_bounds(int &x) {

  if (x >= 0 && x < 9) {
    return true;
  } else {
    return false;
  }
}

bool valid(std::vector<char> &table, int &cell) {
  if (in_bounds(cell) && table[cell] == ' ') {
    return true;
  } else {
    std::cout << "\nInvalid option (ocupied or inexistent cell), try again\n";
    return false;
  }
}