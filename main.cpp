#include <iostream>
#include <string>

void draw(std::string n1, std::string n2, int hp1, int hp2, int dmg1, int dmg2, bool round)
{
	std::cout << n1 << ": HP: " << hp1 << ", DMG: " << dmg1 << std::endl;
	std::cout << n2 << ": HP: " << hp2 << ", DMG: " << dmg2 << std::endl;
	if (round) std::cout << n1 << " -> " << n2 << std::endl;
	else
	{
		std::cout << n2 << " -> " << n1 << std::endl;
	}
}

int lesshp(int hp, int edmg)
{
	return hp -= edmg;
}

int main() {
	std::string data;
	std::cout << "Add meg a ket hos nevet, eleterejet es sebzeset: ";
	std::string n1 = "", n2 = "";
	int hp1 = 0, hp2 = 0, dmg1 = 0, dmg2 = 0;
	bool round = true;

	std::cin >> n1 >> hp1 >> dmg1 >> n2 >> hp2 >> dmg2;

	while (hp1 > 0 && hp2 > 0)
	{
		draw(n1, n2, hp1, hp2, dmg1, dmg2, round);
		if (round)
		{
			hp2 = lesshp(hp2, dmg1);
			if (hp2 > 0) {
				round = false;
			}
			else
			{
				std::cout << n1 << ": HP: " << hp1 << ", DMG: " << dmg1 << std::endl;
				std::cout << n2 << ": HP: " << 0 << ", DMG: " << dmg2 << std::endl;
				std::cout << n2 << " died. " << n1 << " wins.";
			}
		}
		else
		{
			hp1 = lesshp(hp1, dmg2);
			if (hp1 > 0) {
				round = true;
			}
			else
			{
				std::cout << n1 << ": HP: " << 0 << ", DMG: " << dmg1 << std::endl;
				std::cout << n2 << ": HP: " << hp2 << ", DMG: " << dmg2 << std::endl;
				std::cout << n1 << " died. " << n2 << " wins.";
			}
		}
	}

	return 0;
}