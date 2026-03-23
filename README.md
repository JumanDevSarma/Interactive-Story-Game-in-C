# The Midnight Library

The Midnight Library is a text-based adventure game written in C. The player explores a mysterious castle-like library that appears only at midnight, makes choices through different story stages, avoids traps, solves challenges, and tries to recover the legendary Shadow Book.

---

## Story Premise

Long ago, in the land of Salazar, the greatest wizard of all time built a castle to guard forbidden knowledge. This castle is called the **Midnight Library**, and it appears only at midnight.

Inside, thousands of books hold secrets of power. Some tell the truth, while others hide deadly lies. Demons and cursed tomes haunt its halls. Deep within the library lies the most powerful book of all — the **Shadow Book** — protected by the sinister Librarian.

Your goal is to enter the Midnight Library, survive its dangers, and find the Shadow Book before it is too late.

---

## Features

- Text-based branching adventure game
- 10 playable story stages
- Multiple endings
- Player score system
- Player name input
- Simulated typing effect for story narration
- Background music support
- Developer tool for jumping to different parts of the game
- Hidden easter egg
- Cross-platform screen clearing support for Windows, macOS, and Linux

---

## Version

**Current Version:** 1.5.3

---

## Changelog

### Version 1.3.0
- Fixed a bug in Stage 1 where the `clear()` function was not working properly
- Improved formatting in some printed lines
- Added helper functions like `sm("")` and `printf("")` usage improvements to shorten long lines and improve code readability
- Suggested replacing some `printf()` stage messages with `sm()` for better visual presentation
- Reduced some `sm()` loading delays for smoother output

### Version 1.4.0
- Added the player score system
- Refined some text output
- Added borders to improve source code readability
- Fixed a bug in the victory code
- Added the developer tool using `switch-case`

### Version 1.5.0
- Added background music
- Added player name feature
- Fixed a mismatch in the Developer Tool

### Version 1.5.3
- Changed stage transition text to use `sm()` instead of `printf()`
- Stage transition messages now use `getchar()` to ask the user to press Enter to continue instead of using `sleep()`

### Version 1.5.4
- Fixed issue where background music kept playing on macOS after closing the game.
- Improved stop_music() to fully stop the looping afplay process.

---

## Game Flow

The game begins with an introduction and main menu. From there, the player can:

- Start the game
- Read instructions
- View the story background
- See credits
- Exit the game

After starting, the player enters their name and begins progressing through the following stages:

1. Castle Arrival
2. Entrance Hall
3. Hall of Forgotten Stories
4. Hall of Mirrors
5. Hall of Lies
6. Dungeon Tunnels
7. Chamber of Whispers
8. Puzzle Chamber
9. Guardian Chamber
10. Final Chamber

Depending on the player's choices, the game can lead to victory, death, or alternate paths.

---

## Scoring System

The game includes a score system that changes depending on the player's decisions:

- True correct options: +10 points
- Alternate correct options: +5 points
- Trap options: -5 points

Your total score is shown during gameplay and at the ending.

---

## Hidden Features

### Easter Egg
Enter `6` in the main menu to access the hidden easter egg.

### Developer Tool
Type `reload` during input stages to access the Developer Tool.

Developer Tool passwords:
- `juman`
- `hudson`
- `shivam`

The Developer Tool allows you to jump directly to different parts of the game such as:
- Intro
- Main Menu
- Instructions
- Story Background
- Credits
- Easter Egg
- Any stage
- Game Over
- Victory

---

## Technologies Used

- **Language:** C
- **Libraries:**
  - `stdio.h`
  - `stdlib.h`
  - `unistd.h`
  - `string.h`

---

## Platform-Specific Notes

The game includes platform-specific commands for screen clearing and background music.

### Screen Clearing
- Windows: `cls`
- macOS / Linux: `clear`

### Background Music
The game tries to play background music using OS-specific commands:

- **Windows:** PowerShell with `Media.SoundPlayer`
- **macOS:** `afplay`
- **Linux:** `mpg123`

Make sure the audio file `gamebgm.wav` is present in the same directory as the program.

---

## How to Compile and Run

- **Windows:** `gcc main.c -o midnight_library.exe
midnight_library.exe`
- **macOS:** `gcc main.c -o midnight_library
./midnight_library`
- **Linux:** `gcc main.c -o midnight_library
./midnight_library`

---

### File Requirements

To run the full version properly, make sure the following files are available in the same folder:
main.c
gamebgm.wav
How to Play
Run the program
From the main menu, select Start
Enter your player name
Read the story and choose from the given options
Make wise decisions to gain points and survive
Reach the final chamber and defeat the Librarian to win

---

### Controls

Enter menu numbers like 1, 2, 3, etc. to choose options
Press Enter when prompted to continue
Type reload in supported input sections to access the Developer Tool

---

### Stages
stage_1() to stage_10() — handle the story progression

---

### Project Structure
This project currently uses a single C source file containing:
Function declarations
Feature functions
Stage functions
Ending functions
Main game loop

---

### Credits
### The Midnight Library was created by Team Reload:
- Juman
- Hudson
- Shivam

---

### Future Improvements
Possible future updates for the project:
- Add save/load functionality
- Add more story branches and endings
- Improve input validation
- Improve background music handling
- Split the project into multiple source files
- Add better UI design in terminal
- Add more puzzles and secrets

---

### Notes
This project is a console-based adventure game designed for interactive storytelling and decision-making. It combines simple C programming concepts such as functions, strings, conditionals, loops, global variables, and system calls into a complete playable game experience.


