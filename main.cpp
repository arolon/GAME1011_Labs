#include <iostream>
#include <string>

struct Achievement
{
	std::string title;
	std::string description;
	float score = 0.0f;
};

struct Game
{
	std::string name;
	std::string publisher;
	std::string developers;
	Achievement* achievements = nullptr;
	int achievementCount = 0;
};

struct Platform
{
	std::string name;
	std::string manufacturer;
	Game* games = nullptr;
	int gameCount = 0;
};

// -Stores platforms
// -Each player can have multiple games
// -Each game can have multiple achievements

int main()
{
	int platformCount;
	printf("Enter the number of platforms.\n");
	std::cin >> platformCount;
	

	Platform* platforms = new Platform[platformCount];
	printf("There will be %i platforms.\n", platformCount);

	for (int i = 0; i < platformCount; i++)
	{
		Platform& platform = platforms[i];

		int platformNumber = i + 1;
		printf("Please input the name of platform %i \n", platformNumber);
		std::cin >> platform.name;
		

		printf("What is the manufacturer of platform %i?\n", platformNumber);
		std::cin >> platform.manufacturer;
		

		printf("Please input the number of games platform %i have (Min 5)\n", platformNumber);
		std::cin >> platform.gameCount;
		
		if (platform.gameCount < 5) platform.gameCount = 5;


		platform.games = new Game[platform.gameCount];
		//printf("The platform %i have %i games.\n", platformNumber, platform.gameCount);

		for (int j = 0; j < platform.gameCount; j++)
		{
			Game& game = platform.games[j];
			int gameNumber = j + 1;

			printf("Please input the name of game %i\n", gameNumber);
			std::cin >> game.name;
			

			printf("Please input the publisher of game %i\n", gameNumber);
			std::cin >> game.publisher;
			

			printf("Who are the developers of the game %i?\n", gameNumber);
			std::cin >> game.developers;
			

			printf("Please input the number of achievements game %i have (Min 5)\n", gameNumber);
			std::cin >> game.achievementCount;
			
			if (game.achievementCount < 5) game.achievementCount = 5;

			game.achievements = new Achievement[game.achievementCount];
			//printf("Game %i has %i achievements.\n", gameNumber, game.achievementCount);

			for (int k = 0; k < game.achievementCount; k++)
			{
				Achievement& achievement = game.achievements[k];
				int achievementNumber = k + 1;

				printf("Please input the title of achievement %i\n", achievementNumber);
				std::cin >> achievement.title;
				

				printf("Please input the description of achievement %i\n", achievementNumber);
				std::cin >> achievement.description;
				

				printf("Please input a decimal for the score value of achievement %i?\n", achievementNumber);
				std::cin >> achievement.score;
				
			}
		}
	}
	//Print everything to the console and delete
	for (int i = 0; i < platformCount; i++) {
		printf("Platform %i has the name: %s ,the manufacturer: %s and the games:\n", i + 1, platforms[i].name.c_str(), platforms[i].manufacturer.c_str());
		for (int j = 0; j < platforms[i].gameCount; j++) {
			printf("	Game %i has the name: %s, the publisher: %s, the developers %s and the achievements:\n", j + 1, platforms[i].games[j].name.c_str(), platforms[i].games[j].publisher.c_str(), platforms[i].games[j].developers.c_str());
			for (int k = 0; k < platforms[i].games[j].achievementCount; k++) {
				printf("		Achievement %i has the title: %s, the description: %s and the score value of: %f\n", k + 1, platforms[i].games[j].achievements[k].title.c_str(), platforms[i].games[j].achievements[k].description.c_str(), platforms[i].games[j].achievements[k].score);
			}
			delete[] platforms[i].games[j].achievements;
		}
		delete[] platforms[i].games;
	}
	delete[] platforms;

	printf("Press any key to finish");
	std::cin >> platformCount;	

	return 0;
}
