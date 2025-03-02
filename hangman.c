#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gallows(int tries, char guessed_word[], string word, char used[]);
string random_word();

int main(void)
{
    int tries = 6;
    // Get random word
    string word = random_word();
    // initialize displayed word
    char guessed_word[7] = "------";
    // Create used letters array
    char used[7] = "      ";
    // Print empty gallows
    gallows(tries, guessed_word, word, used);
    // start game loop
    while (tries > 0)
    {
        // Recieve letter from user
        char guess = get_char("Guess a letter: ");
        // Copy guessed_word to array a to compare later
        char a[7];
        strcpy(a, guessed_word);

        // See if guessed letter is in word
        for (int i = 0; i < 6; i++)
        {
            if (guess == word[i])
            {
                // If letter is in word, change displayed word
                guessed_word[i] = guess;
            }
        }
        // if letter is not in word subtract 1 from remaining tries
        if (strcmp(guessed_word, a) == 0)
        {
            tries--;
            used[6 - tries] = guess;
        }
        // Print gallows
        gallows(tries, guessed_word, word, used);
        // When tries = 0 print "Hangman!" and end program
        if (tries == 0)
        {
            printf("Hangman!\n");
            return 0;
        }
        // When user guesses all 6 letters correctly print "You Win!"
        if (strcmp(word, guessed_word) == 0)
        {
            printf("You Win!\n");
            return 0;
        }
    }
}

string random_word()
{
    // Seed random number generator
    srand(time(NULL));
    // Initialize array of words
    string words[] = {
        "abacus",  "bistro", "crater", "digest", "export", "famine", "grumpy", "hunter", "island",
        "jumper",  "kitten", "ladder", "mellow", "nature", "oracle", "pollen", "quench", "ransom",
        "stencil", "timber", "umpire", "velvet", "wander", "fungus", "zipper", "absurd", "battle",
        "kraken",  "double", "embark", "frozen", "gilded", "hamper", "intact", "jigsaw", "kernel",
        "lizard",  "bandit", "nugget", "obtain", "purple", "quiver", "riddle", "sacred", "tunnel",
        "untold",  "volume", "walnut", "ranger", "zephyr", "ardent", "beacon", "canvas", "deacon",
        "empire",  "fickle", "gopher", "honcho", "imbued", "jungle", "keeper", "lavish", "magnet",
        "nickel",  "outfit", "perish", "quench", "ramble", "subtle", "tenant", "unique", "vacant",
        "wizard",  "cactus", "sponge", "almond", "glitch", "potion", "domain", "evolve", "fusion",
        "growth",  "hectic", "inmate", "hobbit", "noodle", "legend", "manual", "novice", "output",
        "prison",  "fabric", "render", "summit", "thread", "utmost", "vortex", "wealth", "kitten",
        "zigzag"};
    // Select random word and turn it into an array
    int random = (rand() % 100);
    string word = words[random];
    return word;
}

void gallows(int tries, char guessed_word[], string word, char used[])
{
    if (tries == 6)
    {
        printf("   ____\n");
        printf("   |  |\n");
        printf("   |\n");
        printf("   |\n");
        printf("   |\n");
        printf("___|\n");
        printf("%s\n", guessed_word);
        printf("Used: %s\n", used);
    }
    else if (tries == 5)
    {
        printf("   ____\n");
        printf("   |  |\n");
        printf("   |  O\n");
        printf("   |\n");
        printf("   |\n");
        printf("___|\n");
        printf("%s\n", guessed_word);
        printf("Used:%s\n", used);
    }
    else if (tries == 4)
    {
        printf("   ____\n");
        printf("   |  |\n");
        printf("   |  O\n");
        printf("   |  |\n");
        printf("   |\n");
        printf("___|\n");
        printf("%s\n", guessed_word);
        printf("Used:%s\n", used);
    }
    else if (tries == 3)
    {
        printf("   ____\n");
        printf("   |  |\n");
        printf("   |  O\n");
        printf("   | /| \n");
        printf("   |\n");
        printf("___|\n");
        printf("%s\n", guessed_word);
        printf("Used:%s\n", used);
    }
    else if (tries == 2)
    {
        printf("   ____\n");
        printf("   |  |\n");
        printf("   |  O\n");
        printf("   | /|\\ \n");
        printf("   |\n");
        printf("___|\n");
        printf("%s\n", guessed_word);
        printf("Used:%s\n", used);
    }
    else if (tries == 1)
    {
        printf("   ____\n");
        printf("   |  |\n");
        printf("   |  O\n");
        printf("   | /|\\ \n");
        printf("   | /\n");
        printf("___|\n");
        printf("%s\n", guessed_word);
        printf("Used:%s\n", used);
    }
    else if (tries == 0)
    {
        printf("   ____\n");
        printf("   |  |\n");
        printf("   |  O\n");
        printf("   | /|\\ \n");
        printf("   | / \\ \n");
        printf("___|\n");
        printf("%s\n", word);
    }
}
