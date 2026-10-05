#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Item {
private:
    string name;
    int value;
    bool isTreasure;
public:
    Item(string setName, int setValue, bool setIsTreasure) {
        name = setName;
        value = setValue;
        isTreasure = setIsTreasure;
    }

    const string& getName() const {
        return name;
    }

    const int& getValue() const {
        return value;
    }

    const bool& getIsTreasure() const {
        return isTreasure;
    }
};

struct Tile {
    char symbol = ' ';      
    bool isWall = false;
    bool isSurface = false;
    bool hasItem = false;
    Item item = { "", 0, false };
};

class Submarine {
private:
    int xCord;
    int yCord;
    int maxOxygen;
    int currentOxygen;
    int totalEarnings;
    vector<Item> cargo;

public:
    Submarine(int startX, int startY) {
        xCord = startX;
        yCord = startY;
        maxOxygen = 50;
        currentOxygen = maxOxygen;
        totalEarnings = 0;
    }

    const int& getXCord() {
        return xCord;
    }
    void setXCord(int x) {
        xCord = x;
    }

    const int& getYCord() {
        return yCord;
    }
    void setYCord(int y) {
        yCord = y;
    }

    const int& getMaxOxygen() {
        return maxOxygen;
    }
    void setMaxOxygen(int oxygen) {
        maxOxygen = oxygen;
    }

    const int& getCurrentOxygen() {
        return currentOxygen;
    }
    void setCurrentOxygen(int oxygen) {
        currentOxygen = oxygen;
    }

    const int& getTotalEarnings() {
        return totalEarnings;
    }
    void setTotalEarnings(int earnings) {
        totalEarnings = earnings;
    }

    const vector<Item>& getCargo() {
        return cargo;
    }
    void setCargo(const vector<Item>& cargoList) {
        cargo = cargoList;
    }
    void addItem(const Item& item) {
        cargo.push_back(item);
    }

    void reSurface() {
        currentOxygen = maxOxygen;
        cout << "You have resurfaced! Your Oxygen has been refilled." << endl;

        int descentEarnings = 0;
        if (cargo.empty()) {
            cout << "You have not collected any treasure. You're total earnings remain: " << getTotalEarnings() << endl;
        }
        else {
            for (int i = 0; i < cargo.size(); i++) {
                cout << " - " << cargo[i].getName() << ": worth $" << cargo[i].getValue() << endl;
                descentEarnings += cargo[i].getValue();
            }
            setTotalEarnings(getTotalEarnings() + descentEarnings);
            cout << "Your total earnings for this descent is: $" << descentEarnings << endl;
            cout << "Your new total earnings is: $" << getTotalEarnings() << endl;
            cargo.clear();
        }
    }
};

class missionMap {
private:
    int width;
    int height;
    vector<vector<Tile>> grid;
public:
    missionMap(int w, int h) {
        width = w;
        height = h;
        grid.resize(height, vector<Tile>(width));
        buildLevel();
    }

    const int& getWidth() { 
        return width; 
    }
    const int& getHeight() { 
        return height; 
    }

    bool isWallTile(int x, int y) {
        return grid[y][x].isWall;
    }
    bool isSurfaceTile(int x, int y) {
        return grid[y][x].isSurface;
    }

    void buildLevel() {
        for (int x = 0; x < width; ++x) {
            grid[0][x].isSurface = true;
            grid[0][x].symbol = '~';
        }
        grid[3][4].isWall = true; grid[3][4].symbol = '#';
        grid[3][5].isWall = true; grid[3][5].symbol = '#';
        grid[3][6].isWall = true; grid[3][6].symbol = '#';
        grid[6][2].isWall = true; grid[6][2].symbol = '#';
        grid[6][3].isWall = true; grid[6][3].symbol = '#';
        grid[6][4].isWall = true; grid[6][4].symbol = '#';

        grid[2][3].hasItem = true;
        grid[2][3].item = { "Gold Coin", 5, true };
        grid[2][3].symbol = '*';

        grid[5][7].hasItem = true;
        grid[5][7].item = { "Bronze Sword", 80, true };
        grid[5][7].symbol = '*';

        grid[4][4].hasItem = true;
        grid[4][4].item = { "Ancient Skeleton", 0, false };
        grid[4][4].symbol = '*';
    }

    void printView(int xSub, int ySub) {
        int xCam = xSub - 2;

        if (xCam < 0) {
            xCam = 0; 
        }
        if (xCam > width - 5) { 
            xCam = width - 5; 
        }

        int yCam = ySub - 2;
        if (yCam < 0) { 
            yCam = 0; 
        }
        if (yCam > height - 5) { 
            yCam = height - 5; 
        }
        cout << endl;
        for (int r = yCam; r < yCam + 5; r++) {
            for (int c = xCam; c < xCam + 5; c++) {
                if (c == xSub && r == ySub) {
                    cout << "@ ";
                }
                else {
                    cout << grid[r][c].symbol << " ";
                }
            }
            cout << endl;
        }
    }

    void inspectArea(Submarine& sub) {
        bool foundSomething = false;

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                int checkX = sub.getXCord() + dx;
                int checkY = sub.getYCord() + dy;

                if (checkX >= 0 && checkX < width && checkY >= 0 && checkY < height) {
                    Tile& tile = grid[checkY][checkX];
                    if (tile.hasItem) {
                        foundSomething = true;

                        if (tile.item.getIsTreasure()) {
                            cout << "You found a " << tile.item.getName()
                                << "! (Value: $" << tile.item.getValue() << endl;
                            sub.addItem(tile.item);

                            tile.hasItem = false;
                            if (tile.isSurface) {
                                tile.symbol = '~';
                            }
                            else {
                                tile.symbol = ' ';
                            }
                        }
                        else {
                            cout << "You see a " << tile.item.getName()
                                << ". It has no monetary value." << endl;
                        }
                    }
                }
            }
        }

        if (!foundSomething) {
            cout << "Nothing interesting nearby." << endl;
        }
    }
};

int main() {
    bool keepPlaying= true;

    do {
        cout << "SUBMARINE ADVENTURE GAME" << endl << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Quit" << endl;
        cout << "Select an option: ";

        string menuChoice;
        cin >> menuChoice;

        if (menuChoice == "2") {
            std::cout << "Thanks for playing! Goodbye.";
            keepPlaying = false;
            break;
        }
        else if (menuChoice == "1") {
            
            missionMap map(10, 10);
            Submarine sub(2, 0);

            bool isDead = false;

            while (!isDead) {
                map.printView(sub.getXCord(), sub.getYCord());
                cout << endl << "Oxygen: " << sub.getCurrentOxygen() << "/" << sub.getMaxOxygen() << endl;
                cout << "Enter a move (W/A/S/D or inspect): ";
                string command;
                cin >> command;
                if (command == "inspect" || command == "INSPECT" || command == "Inspect") {
                    map.inspectArea(sub);
                    continue;
                }
                int moveX = 0;
                int moveY = 0;
                if (command == "w" || command == "W") { 
                    moveY = -1; 
                }
                else if (command == "s" || command == "S") { 
                    moveY = 1; 
                }
                else if (command == "a" || command == "A") { 
                    moveX = -1; 
                }
                else if (command == "d" || command == "D") { 
                    moveX = 1; 
                }
                else {
                    cout << "Invalid move! Please type W, A, S, D, or inspect." << endl;
                    continue;
                }

                int targetX = sub.getXCord() + moveX;
                int targetY = sub.getYCord() + moveY;

                if (targetX < 0 || targetX >= map.getWidth() || targetY < 0 || targetY >= map.getHeight()) {
                    cout << "You can't move past the edge of the level! Try again!" << endl;
                    continue;
                }

                if (map.isWallTile(targetX, targetY)) {
                    cout << "You can't move into a wall! Try again!" << endl;
                    continue;
                }

                sub.setXCord(targetX);
                sub.setYCord(targetY);
                sub.setCurrentOxygen(sub.getCurrentOxygen() - 1);

                if (map.isSurfaceTile(sub.getXCord(), sub.getYCord())) {
                    sub.reSurface();
                }

                if (sub.getCurrentOxygen() <= 0) {
                    cout << "OUT OF OXYGEN! Submarine lost!!" << endl;
                    std::cout << "Returning to Main Menu..." << endl << endl;
                    isDead = true;
                }
            }
            
        }
        else {
            cout << "Invalid choice! Please enter 1 or 2." << endl;
        }
    } while (keepPlaying);
}