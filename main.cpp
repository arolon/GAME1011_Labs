#include <iostream>
#include <string>
#include <vector>

class Weapon {
public:
    std::string name;
    int damage;
    std::vector<std::string> specialAbilities;

    Weapon() {
        name = "Unknown Weapon";
        damage = 0;
        specialAbilities = {};
    }

    Weapon(std::string n, int d, std::vector<std::string> abilities) {
        name = n;
        damage = d;
        specialAbilities = abilities;
    }

    friend std::ostream& operator<<(std::ostream& os, const Weapon& weapon) {
        os << "Weapon: " << weapon.name << " | Damage: " << weapon.damage << " | Abilities: ";
        for (int i = 0; i < 2; ++i) {
            os << weapon.specialAbilities[i] << " and ";
        }
        return os;
    }

    bool operator==(const Weapon& other) const {
        return name == other.name && damage == other.damage;
    }
};

class Armour {
public:
    std::string name;
    std::string description;
    int armourValue;

    Armour() {
        name = "Unknown armour";
        description = "desc";
        armourValue = 0;
    }

    Armour(std::string n, std::string desc, int av) {
        name = n;
        description = desc;
        armourValue = av;
    }

    friend std::ostream& operator<<(std::ostream& os, const Armour& armour) {
        os << "Armour: " << armour.name << " | Defence: " << armour.armourValue << " | Description: " << armour.description;
        return os;
    }

    bool operator==(const Armour& other) const {
        return name == other.name && armourValue == other.armourValue;
    }
};

class Character {
public:
    std::string name;
    std::string species;
    std::string backstory;
    int health;
    Weapon weapon;
    Armour armour;

    Character() {
        name = "Unknown character";
        species = "None";
        backstory = "None";
        health = 50;
        weapon = Weapon();
        armour = Armour();
    }

    Character(std::string n, std::string s, std::string b, int h, Weapon w, Armour a) {
        name = n;
        species = s;
        backstory = b;
        health = h;
        weapon = w;
        armour = a;
    }

    void displayInfo() const {
        std::cout << "\nCharacter Name: " << name
            << "\nSpecies: " << species
            << "\nBackstory: " << backstory
            << "\nHealth: " << health << std::endl;
        std::cout << weapon << std::endl;
        std::cout << armour << "\n" << std::endl;
    }

    bool operator==(const Character& other) const {
        if (name == other.name && species == other.species && health == other.health && weapon == other.weapon && armour == other.armour) {
            std::cout << "\nCharacters are the same!\n";
            return true;
        }
        else {
            std::cout << "\nCharacters are NOT the same!\n";
            return false;
        }
    }
};

int main() {
    std::cout << "Welcome! customize three characters\n";

    Character characters[3];
    Weapon weapons[3] = {
        {"Longsword", 50, {"Heavy Swing", "Precision Thrust"}},
        {"War Axe", 55, {"Cleave", "Shield Breaker"}},
        {"Crossbow", 40, {"Piercing Bolt", "Quick Reload"}}
    };

    Armour armours[3] = {
        {"Chainmail", "Balanced protection with mobility", 35},
        {"Plate Armour", "Heavy but strong defense", 50},
        {"Gambeson", "Light padding for agility", 20}
    };

    for (int i = 0; i < 3; ++i) {
        std::string name, species, backstory;
        int health, weaponChoice, armourChoice;

        std::cout << "\nCreating Character " << (i + 1) << ":" << std::endl;
        std::cout << "Enter character name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter species: ";
        std::getline(std::cin, species);
        std::cout << "Enter backstory: ";
        std::getline(std::cin, backstory);
        std::cout << "Enter starting health (50-200): ";
        std::cin >> health;
        health = std::max(50, std::min(200, health));

        std::cout << "Choose a weapon:\n";
        for (int j = 0; j < 3; ++j) {
            std::cout << j + 1 << ". " << weapons[j].name << " (Damage: " << weapons[j].damage << ")\n";
        }
        std::cin >> weaponChoice;
        weaponChoice = std::max(1, std::min(3, weaponChoice)) - 1;

        std::cout << "Choose an armour:\n";
        for (int j = 0; j < 3; ++j) {
            std::cout << j + 1 << ". " << armours[j].name << " (Defence: " << armours[j].armourValue << ")\n";
        }
        std::cin >> armourChoice;
        armourChoice = std::max(1, std::min(3, armourChoice)) - 1;

        characters[i] = Character(name, species, backstory, health, weapons[weaponChoice], armours[armourChoice]);
        characters[i].displayInfo();
    }

    std::cout << "\nCompare two characters by index (1-3): ";
    int index1, index2;
    std::cin >> index1 >> index2;
    if (index1 != index2 && index1 >= 1 && index1 <= 3 && index2 >= 1 && index2 <= 3) {
        characters[index1 - 1] == characters[index2 - 1];
    }
    else {
        std::cout << "Invalid comparison indices.\n";
    }

    std::cout << "\nDisplaying all characters:\n";
    for (int i = 0; i < 3; ++i) {
        characters[i].displayInfo();
    }

    return 0;
}
