#include <iostream>

void string_to_int(const std::string& , int& , int& );
/*  
    std::stoi might throw an exeption of type "std::invalid_argument" in case argument can't be converted
    which could be used to handle wrong input
*/
void set_choice(char* , int& , int& , char );
void get_coordonates(std::istream& , std::string&);
bool valid(char** ,int& , int&);
bool out_of_bounds(int& , int&);

int main() {
    //TODO: use an STL container
    char *matrix = new char[9] {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int x = 0, y = 0;
    std::string coordonates = "";
    
    while (true) {
        // get the choice of the first player
        std::cout << "Player 1: ";
        get_coordonates(std::cin, coordonates);
        
        // Transform string in coordonates and verify if desired position is available
        string_to_int(coordonates, x, y);
        set_choice(matrix, x, y, 'X');

        std::cout << "Player 2: ";
        get_coordonates(std::cin, coordonates);
        string_to_int(coordonates, x, y);
        set_choice(matrix, x, y, 'O');



        std::cout << " " << matrix[0] << " | " << matrix[1] << " | " << matrix[2] << "\n";
        std::cout << "---+---+--- \n";
        std::cout << " " << matrix[3] << " | " << matrix[4] << " | " << matrix[5] << "\n";
        std::cout << "---+---+--- \n";
        std::cout << " " << matrix[6] << " | " << matrix[7] << " | " << matrix[8] << "\n";
    }
    
    
    
    delete[] matrix;
}

/*  TODO:
    # Use Matrix library instead of dynamic allocated memory

    # Ask every player for a coordonate that will corespond to the certan cell in the matrimatrix[] 
        EX. 02 will be the cell from first row and third column
        * It can be read as a string of 2 chars then deduced as coordonates
        * Players can't marks cell that are already used or out of bounds
        
    # Make an algorithm that will verify when a player win or ist's a draw 
        Remark: This check should beging from the third round of the game (every player choice is considered a round, game consists of MIN = 3 rounds and MAX = 9)
    # Render the table until there are no more empty cells left (Draw)
    # Handle std::stoi exeptions for input correction
    # Cell availability and out of matrix can be handled throgh custom exceptions
*/

void set_choice(char* matrix, int& x, int& y, char ch) {
    matrix[(x * 3) + y] = ch;
}

void string_to_int(const std::string& str, int& x, int& y) {
    int tmp = std::stoi(str);
    x = tmp / 10;
    y = tmp % 10;
}

void get_coordonates(std::istream& in, std::string& str) {
    for(size_t i = 0; i < 2; ++i) {
        in >> str[i];
    }
    in.sync();  //clear buffer
}

bool out_of_bounds(int& x, int& y) {
    return (x < 3 && y < 3) ? true : false;
}

bool valid(char** matrix, int& x, int& y) {
   return (*matrix[3 * x + y] != ' ') ?  true :  false;
}   //is cell in position (x, y) valid or not