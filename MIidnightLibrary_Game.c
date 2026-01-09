// DEVELOPER AREA //

// Things i Did:(Hudson)
// Version: 1.3.0
// 1. Bug in stage_1 option1 where the clear() function was not working.
// 2. I added and \n in some of the lines like in "GAME OVER" logo i remove \n since it
//    was not showing as intended.


// 3. I create new sm(""); , printf(""); to shorten the long lines of codes to make it easier to 
//    read during development.
// 4. I suggest changing the message from printf() to sm() in all stage message after selecting options
//    to make it look better.
// 5. I decrease the loading time of sm() in some places to make it look better.

//Things i did:(Juman)
//Version 1.4.0
// 1. Added the player score system.
// 2. Refined few simple print texts.
// 3. Added borders to make parts of the source code.
// 4. The victory code had some bug. fixed it.
// 5. Added the developer tool using switch-case.
//Version 1.5.0
//1. Added background music.
//2. Added player name feature.
//3. Fixed a mismatch in Developer Tool
//Version 1.5.3
//1. Made stage transition text to use sm instead of printf. 
//2. Stage transtition texts now uses getchar() to ask user to press enter to continue rather than using sleep().

//---------------------------------------------------------------------------------------------------------------------------------------------------


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------

//Functions of features
void INTRO();             //line 120
char* menu();              //line 102 // i planned to add this to mention which line they on, but i will do it later
void ins();                
void credit();             
void clear();                        
void story_background();
void developer_tool(); 
void easter_egg();
void play_music();
void stop_music();
char* player_name();

//---------------------------------------------------------------------------------------------------------------------------------------------------
            

//Function of stages (from line 167 to 613)
void stage_1();
void stage_2(); 
void stage_3(); 
void stage_4();
void stage_5();
void stage_6();
void stage_7();
void stage_8();
void stage_9();
void stage_10();

//---------------------------------------------------------------------------------------------------------------------------------------------------

//Endings 
void victory_end();
void secret_end(); //not yet decided
void dead_end();

//---------------------------------------------------------------------------------------------------------------------------------------------------

// Simulate Typing...

void sm(const char* text, int delay)
{
    for (int i = 0; text[i] !='\0'; i++){
    printf("%c", text[i]);
    fflush(stdout);
    usleep(delay);}
    printf("\n");
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

//features declaration

void clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void credit()
{
    clear();
    sm("CREDIT:\n\nTHE MIDNIGHT LIBRARY GAME WAS CREATED BY TEAM RELOAD (HUDSON,JUMAN and SHIVAM).",65000);
    sleep(2);
    clear();
}

void ins()
{
    clear();
    printf("INSTRUCTIONS:\n\n1.Only select one of the given options.\n2.The player score will be calculated.\n");
    printf("3.True correct options will have +10 points\n4.Alternate correct options will have +5 points.\n");
    printf("5.Trap options will have -5 points.\n6.Follow the story and choose the options wisely.\n\n\n");
    printf("# PRESS ENTER TO RETURN TO THE MAIN MENU #");
    getchar();getchar();
}

void story_background()
{
    clear();
    printf("STORY BACKGROUND\n\n");
    printf("Long ago, in the land of Salazar, the greatest wizard of all time,\n");
    printf("a castle was built to guard forbidden knowledge. This castle is\n");
    printf("called the Midnight Library. It only appears at midnight.\n\n");

    printf("Inside, thousands of books hold secrets of power. Some tell the truth,\n");
    printf("others hide deadly lies. Demons and cursed tomes haunt its halls.\n\n");

    printf("The most powerful book of all is the SHADOW BOOK.\n");
    printf("It has the power to save the world from demons, but it is hidden\n");
    printf("deep within the library, protected by the sinister Librarian.\n\n");

    printf("The Librarian will try to trick you, trap you, and keep you from\n");
    printf("finding the Shadow Book. Only the clever and the brave can\n");
    printf("survive the puzzles, avoid the lies, and defeat the Librarian.\n\n");

    printf("Your goal: Find the SHADOW BOOK and save the world.\n");
    printf("But beware... not all paths lead to truth.\n\n");

    printf("# PRESS ENTER TO RETURN TO THE MAIN MENU #");
    getchar(); // clear newline
    getchar(); // wait for Enter
}

//Type "6" in the main menu to see the easter egg
void easter_egg()
{
    clear();
    sm("YOU FOUND AN EASTER EGG!\n\n",5000);
    sleep(2);
    clear();
    printf("    _______________________________\n");
    printf("   /                               \\\n");
    printf("  |   ==========================   |\n");
    printf("  |   ||                       ||  |\n");
    printf("  |   ||   A HIDDEN PAGE...    ||  |\n");
    printf("  |   ||                       ||  |\n");
    printf("  |   ==========================   |\n");
    printf("  |                                |\n");
    printf("  |   “The Shadow Book is not the  |\n");
    printf("  |    only one… Somewhere lies    |\n");
    printf("  |    THE MIRROR BOOK.”           |\n");
    printf("  |                                |\n");
    printf("  |   Beware: Staring too long may |\n");
    printf("  |   erase you from existence.    |\n");
    printf("  |                                |\n");
    printf("  |        HUDSON – JUMAN – SHIVAM |\n");
    printf("  |        Keepers of RELOAD ⚡    |\n");
    printf("   \\______________________________/\n\n");

    printf("# PRESS ENTER TO RETURN TO THE MAIN MENU #");
    getchar(); // clears leftover newline
    getchar(); // actually waits for Enter
}

char* player_name()
{
    static char name[25];   //static so it stays in memory

    int c;
    while ((c = getchar()) != '\n' && c != EOF);    // Clear leftover characters from previous input
    printf("\n\n\n\n\n");
    printf("               ");
    printf("Enter your player name: ");
    fgets(name, sizeof(name), stdin);

    if (name[strlen(name)-1]=='\n') 
        name[strlen(name)-1]='\0';
    
    return name;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//BACKGROUND MUSIC

// Start background music in loop
void play_music() 
{
#ifdef _WIN32
    system("start /min powershell -command \"while($true) { (New-Object Media.SoundPlayer 'gamebgm.wav').PlaySync() }\"");
#elif __APPLE__
    system("while true; do afplay gamebgm.wav; done &");
#elif __linux__
    system("mpg123 -q --loop -1 gamebgm.wav &");
#endif
}

// Stop background music
void stop_music() 
{
#ifdef _WIN32
    system("taskkill /IM powershell.exe /F >nul 2>&1");
#elif __APPLE__
    system("killall afplay > /dev/null 2>&1");
#elif __linux__
    system("killall mpg123 > /dev/null 2>&1");
#endif
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

//DEVELOPER TOOL
//Type "reload" in any input stage and it will load the developer window.

void developer_tool()
{
    clear();
    char a[7];
    printf("\n\n\n\n\n");
    printf("                  ");
    printf("Enter the password: ");
    // while ((getchar()) != '\n');
    scanf("%6s",a);
    clear();
    if ((strcmp(a,"juman")==0) || (strcmp(a,"hudson")==0) || (strcmp(a,"shivam")==0))
    {
    int x;
    clear();
    sm("|----------------------------|",5000);
    sm("|       DEVELOPER TOOL       |",5000);
    sm("|----------------------------|\n\n",5000);
    sleep(2);
    clear();
    clear();
    printf("Which part you want to jump to ?\n");
    printf("1.Intro\n");
    printf("2.Main Menu\n");
    printf("3.Instructions\n");
    printf("4.Story Background\n");
    printf("5.Credits\n");
    printf("6.Easter Egg\n");
    printf("7.Stage_1 Castle Arrival\n");
    printf("8.Stage_2 Entrance Hall\n");
    printf("9.Stage_3 Hall of Forgotten Stories\n");
    printf("10.Stage_4 Hall of Mirrors\n");
    printf("11.Stage_5 Hall of Lies\n");
    printf("12.Stage_6 Dungeon Tunnels\n");
    printf("13.Stage_7 Chamber of Whispers\n");
    printf("14.Stage_8 Puzzle Room\n");
    printf("15.Stage_9 Guardian Chamber\n");
    printf("16.Stage_10 Final Chamber\n");
    printf("17.Game Over\n");
    printf("18.Victory\n\n\n");
    printf("Enter your selection:");
    scanf(" %d",&x);

    switch(x)
    {
        case 1: INTRO(); break;
        case 2: menu(); break;
        case 3: ins(); break;
        case 4: story_background(); break;
        case 5: credit(); break;
        case 6: easter_egg(); break;
        case 7: stage_1(); break;
        case 8: stage_2(); break;
        case 9: stage_3(); break;
        case 10: stage_4(); break;
        case 11: stage_5(); break;
        case 12: stage_6(); break;
        case 13: stage_7(); break;
        case 14: stage_8(); break;
        case 15: stage_9(); break;
        case 16: stage_10(); break;
        case 17: dead_end(); break;
        case 18: victory_end(); break;

    }
    }
    else
    {
        clear();
        printf("Incorrect password!\n");
        sleep(2);
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

//Player Name and Scoring function
int score = 0;
char* name;

//---------------------------------------------------------------------------------------------------------------------------------------------------


// Main Selection Menu

char* menu()
{
    static char a[10];
    clear();
    sm("MAIN MENU\n",50000);
    sm("1. Start",1000);
    sm("2. Instructions",1000);
    sm("3. Story Background",1000);
    sm("4. Credits",1000);
    sm("5. Exit\n",1000);
    sleep(1);
    printf("Enter your selection -> ");//change it from sm to printf to avoid delay in input and the user input is showing below the ->
    scanf(" %9s",a);                   //if i try to fix it the code is gonna get a bit complicated
    return a; //a contains the selection  
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

//INTRO
void INTRO()
{
    clear();
    printf("           ");
    sm("Welcome to the MIDNIGHT LIBRARY\n\n",75000);
    printf("                   ");
    sm("Created by \n\n",1500);
    sleep(1);
    sm("rrrrrrr   eeeeeee  ll        oooooo    aaaa    ddddd",1500);
    sm("rr   rr   ee       ll        oo  oo   aa  aa   dd   dd",1500);
    sm("rrrrrrr   eeeeeee  ll        oo  oo   aaaaaa   dd   dd",1500);
    sm("rr rr     ee       ll        oo  oo   aa  aa   dd   dd",1500);
    sm("rr  rr    eeeeeee  llllllll  oooooo   aa  aa   ddddd",1500);
    sm("rr   rr",1000);
    sm("rr    rr          LEAD BY TRIO OF HUDSON-JUMAN-SHIVAM\n\n",1500);
    sleep(1);   //changed from 2 to 1 sec
    printf("\n\n");
    printf("             ");
    printf("# PRESS ENTER TO CONTINUE #");
    
    getchar();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------


//Ending Functions

void dead_end()
{
    clear();
    sm("   ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗ ",1000); // i removed \n  from the end of each line to fix formatting
    sm("  ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗",1000);
    sm("  ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝",1000);
    sm("  ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗",1000);
    sm("  ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║",1000);
    sm("   ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝\n\n",1000);
    printf("YOU TOTAL PLAYER SCORE IS: %d\n\n",score);
    sleep(3);
    printf("# PRESS ENTER TO GO BACK TO THE MAIN MENU #");
    getchar();
    getchar();
}


void victory_end()
{
    clear();
    printf("VICTORY! YOU WON!\n\n");
    printf("YOU TOTAL PLAYER SCORE IS: %d\n",score);
    sleep(3);
    clear();
    credit();
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------


// STAGES

void stage_1()
{
    char a[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("CASTLE ARRIVAL\n\n");
    sm("You are lost in the land of Salazar, desperate to find the sacred SHADOW BOOK.",40000);
    sm("The clock strikes midnight. A dark castle appears in front of you. This is the Midnight Library. A raven flies above and says:\n",50000);
    sm("“Books of truth and death are inside. Choose wisely.”\n\n",40000);
    printf("1. Enter boldly.\n");
    printf("2. Walk around the castle.\n");
    printf("3. Wait outside.\n\n");
    printf("Your selection ->  ");
    scanf(" %9s",a);
    if (strcmp(a, "1")==0)
    {
        clear();
        score += 10;
        sm("You push the doors open with all your strength. The castle groans as if it were",10000);
        sm("alive. A chill wind greets you as you step into the darkness...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        clear();
        stage_2();
    }
    else if (strcmp(a, "2")==0)
    {
        clear();
        score +=5;
        sm("You circle the castle's black walls. Claw marks scar the walls. The raven whispers:",10000);
        sm("Some doors lie, some doors tell truth.” You go back to the gate.\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_2();
    }
    else if (strcmp(a, "3")==0) // i change from printf();  to sm(); to make it make it look better
    {
        clear();
        sm("The castle fades like smoke in the air. The land grows silent...",10000);
        sm("then the demons crawl out of the mist. You scream as they drag you away...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        clear();
        dead_end();
    }
    else if(strcmp(a, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_1();
    }
}


void stage_2()
{
    char b[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("ENTRANCE HALL\n\n");
    sm("The doors slam shut behind you. Candles flare to life, throwing long shadows across the",50000);
    sm("vast hall. Three staircases rise ahead: one to the left, one to the right, and one in the",50000);
    sm("middle. The air is thick with dust and faint whispers that come from nowhere.\n\n",50000);
    sleep(2);
    printf("1. Climb the left staircase, where a faint glow flickers.\n");
    printf("2. Take the right staircase, where shadows move strangely.\n");
    printf("3. Step onto the middle staircase.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",b);
    if (strcmp(b, "1")==0)
    {
        clear();
        score+=10;
        sm("A faint glow calls to you. Each step feels heavier as whispers grow louder. You",10000);
        sm("reach the top and see a new hall ahead....\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_3();
    }
    else if (strcmp(b, "2")==0)
    {
        clear();
        score+=5;
        sm("The shadows twist unnaturally as you climb. Something crawls along the wall, but",10000);
        sm("vanishes when you blink. A heavy door waits at the top...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_5();
    }
    else if (strcmp(b, "3")==0)
    {
        clear();
        score-=5;
        sm("The middle steps feel endless. The air thickens, and your reflection moves on its",10000);
        sm("own in the polished rail. A mirror-filled chamber lies ahead...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_4();
    }
        else if (strcmp(b, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",1000);
        sleep(1);
        stage_2();
    }
}

void stage_3()
{
    char c[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("HALL OF FORGOTTEN STORIES\n\n");
    sm("The hall stretches endlessly, lined with shelves of books so tall they vanish into the dark",50000);
    sm("ceiling. The air hums with whispers.\n",50000);
    sm("On a pedestal rests a glowing book, pulsing softly with light.",50000);
    sm("Nearby, a massive tome is chained with thick iron.\n\n",50000);
    sleep(2);
    printf("1. Open the glowing book and read its pages.\n");
    printf("2. Ignore the books and move forward quickly.\n");
    printf("3. Break the chains and open the locked tome.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",c);
    if (strcmp(c, "1")==0)
    {
        clear();
        score+=10;
        sm("The book’s light blinds you for a moment. Strange symbols swirl and rearrange into",10000);
        sm("words. The pages whisper, pulling you deeper into their truth...”\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_6();
    }
    else if (strcmp(c, "2")==0)
    {
        clear();
        score-=5;
        sm("You rush forward, avoiding temptation. A hidden door creaks open, dragging you",10000);
        sm("back to the entrance hall...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_2();
    }
    else if (strcmp(c, "3")==0)
    {
        clear();
        sm("The chains shatter and a black smoke erupts. The book wails, summoning demons.",10000);
        sm("The walls crack as darkness devours you...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        clear();
        dead_end();
    }
        else if (strcmp(c, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_3();
    }
}

void stage_4()
 
{
    char d[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("HALL OF MIRRORS\n\n");
    sm("You step into a long corridor. Every wall is covered with mirrors. Each reflection shows",50000);
    sm("you… but not as you are. Some show you older, some younger, some crowned like a\n",50000);
    sm("king, others broken and bleeding.\n",50000);
    sm("One mirror begins to whisper:\n",50000);
    sm("“Riddle me this… What walks on four legs at dawn, two at noon, and three at dusk?”",50000);
    sleep(2);
    printf("1. Answer the riddle.\n");
    printf("2. Smash a mirror with your fist.\n");
    printf("3. Step into one of the reflections.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",d);
    if (strcmp(d, "1")==0)
    {
        clear();
        score-=5;
        sm("Your voice trembles as you give your answer. The mirrors shatter—but instead of",10000);
        sm("freedom, you find yourself standing once again in the entrance hall...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_2();
    }
    else if (strcmp(d, "2")==0)
    {
        clear();
        score-=5;
        sm("The glass breaks and your reflection grabs your arm! It yanks you into its world.",10000);
        sm("The castle twists... you are thrown back to the entrance...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_2();
    }
    else if (strcmp(d, "3")==0)
    {
        clear();
        sm("The mirror ripples like water. You step through... and instantly demons surround\n",10000);
        sm("you. Their claws rip into your soul...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        clear();
        dead_end();
    }
        else if (strcmp(d, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_4();
    }
}

void stage_5()
{
    char e[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("HALL OF LIES\n\n");
    sm("The room is dark, except for two books floating in the air. Both shout over each other.\n",50000);
    sm("Book 1: “The Shadow Book is in the Chamber of Whispers!”",50000);
    sm("Book 2: “The Shadow Book is in the Dungeon Tunnels!”\n\n",50000);
    sm("The voices grow louder, pressing into your skull.\n",50000);
    sleep(2);
    printf("1. Compare both books carefully before choosing.\n");
    printf("2. Trust Book 1 and follow its words.\n");
    printf("3. Walk away without choosing.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",e);
    if (strcmp(e, "1")==0)
    {
        clear();
        score+=10;
        sm("You breathe deeply and study their words. One feels false, its words too sweet.",10000);
        sm("You toss it aside and follow the uneasy truth into the tunnels below...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_6();
    }
    else if (strcmp(e, "2")==0)
    {
        clear();
        score-=5;
        sm("The book glows warmly, tricking you with false comfort. You follow its voice into a",10000);
        sm("chamber where whispers claw at your mind...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_7();
    }
    else if (strcmp(e, "3")==0)
    {
        clear();
        score-=5;
        sm("The voices scream as you turn away, but the noise fades as you return to the\nentrance hall...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_2();
    }
        else if (strcmp(e, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_5();
    }
}


void stage_6()
{
    char f[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("DUNGEON TUNNELS\n\n");
    sm("A narrow staircase takes you deep underground. The smell of damp stone fills your",50000);
    sm("nose. Long claw marks cover the walls, and you hear a low growl echoing from the",50000);
    sm("darkness.”\n\n",50000);
    sm("A torch hangs on the wall, unlit.\n",50000);
    sleep(2);
    printf("1. Move forward through the dark without lighting the torch.\n");
    printf("2. Light the torch to see clearly.\n");
    printf("3. Turn back the way you came.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",f);
    if (strcmp(f, "1")==0)
    {
        clear();
        score+=10;
        sm("Your steps echo through the damp tunnel. The growls stalk you, then fade. At last,",10000);
        sm("a faint light ahead guides you onward...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_7();
    }
    else if (strcmp(f, "2")==0)
    {
        clear();
        sm("The fire roars to life... but dozens of glowing eyes open in the shadows.\n",10000);
        sm("Then the Demons lunge toward you, drawn by the flame...\n\n",10000);
        sleep(7);
        dead_end();
    }
    else if (strcmp(f, "3")==0)
    {
        clear();
        score-=5;
        sm("Fear grips you. You scramble up the stairs and return to the safety of the entrance hall...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_2();
    }
        else if (strcmp(f, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_6();
    }
}

void stage_7()
{
    char g[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("CHAMBER OF WHISPERS\n\n");
    sm("The room is filled with floating books. They all whisper at once, the noise clawing at your",50000);
    sm("mind like knives.\n",50000);
    sm("Amid the madness, you catch one soft, almost hidden voice.”\n\n",50000);
    sleep(2);
    printf("1. Focus only on the faint whisper and listen.\n");
    printf("2. Grab one random book and open it.\n");
    printf("3. Try to read every book at once.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",g);
    if (strcmp(g, "1")==0)
    {
        clear();
        score+=10;
        sm("You block out the madness and cling to the softest voice. It speaks: ‘The Librarian\n",10000);
        sm("fears truth more than fire.’ The books scatter, revealing a hidden passage...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_8();
    }
    else if (strcmp(g, "2")==0)
    {
        clear();
        score-=5;
        sm("The book screams with a voice not its own! Shadows reach for you and you\nstumble back into the tunnels...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_6();
    }
    else if (strcmp(g, "3")==0)
    {
        clear();
        sm("Your eyes burn, your head cracks with voices. You collapse as your mind shatters\ninto whispers...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        dead_end();
    }
        else if (strcmp(g, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\\n",50000);
        sleep(1);
        stage_7();
    }
}


void stage_8()
{
    char h[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("PUZZLE CHAMBER\n\n");
    sm("The air turns cold. Floating stone tablets circle you, each carved with glowing runes. The",50000);
    sm("shadow of the Librarian appears at the edge of the room. His voice is low and sharp:\n",50000);
    sm("“Solve the runes, seeker… or be lost forever.”\n",50000);
    sm("The runes spin slowly, waiting for your hand.\n\n",50000);
    sleep(2);
    printf("1. Study the runes carefully and solve the puzzle.\n");
    printf("2. Smash the shelves and try to break through.\n");
    printf("3. Refuse to play the Librarian’s game.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",h);
    if (strcmp(h, "1")==0)
    {
        clear();
        score+=10;
        sm("You trace the glowing symbols with steady hands. They rearrange, forming a door",10000);
        sm("of light. A path forward opens...\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_9();
    }
    else if (strcmp(h, "2")==0)
    {
        clear();
        sm("Your blow echoes. The Librarian laughs. The runes blaze red and demons burst",10000);
        sm("from the shadows...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        dead_end();
    }
    else if (strcmp(h, "3")==0)
    {
        clear();
        score-=5;
        sm("You stand defiant. The chamber shifts and resets endlessly, trapping you in a loop",10000);
        sm("until you stumble back into the tunnels...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_6();
    }
        else if (strcmp(h, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_8();
    }
}

void stage_9()
{
    char i[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("GUARDIAN CHAMBER\n\n");
    sm("A giant demon rises from the floor, wings scraping the ceiling, eyes burning like fire. Its",50000);
    sm("voice shakes the ground:\n",50000);
    sm("“Answer my riddle… or you will never see the Shadow Book.”\n",50000);
    sm("Its claws tighten around a gate behind it.\n\n",50000);
    sleep(2);
    printf("1. Duel the demon with the riddle challenge.\n");
    printf("2. Offer it a fake book to distract it.\n");
    printf("3. Attack the demon with brute force.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",i);
    if (strcmp(i, "1")==0)
    {
        clear();
        score+=10;
        sm("The demon leans closer, flames spilling from its mouth. You speak the answer",10000);
        sm("clearly. The ground shakes... then the monster bows and steps aside.\n\n",10000);
        sm("# Press Enter to continue #",10000);
        getchar();
        getchar();
        stage_10();
    }
    else if (strcmp(i, "2")==0)
    {
        clear();
        score+=5;
        sm("You pull out a worthless tome. The demon snarls but snatches it away. Distracted,",10000);
        sm("it unlocks the gate for you...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_10();
    }
    else if (strcmp(i, "3")==0)
    {
        clear();
        sm("You rush forward foolishly. The demon raises one claw and tears you apart in a\nsingle strike...\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        dead_end();
    }
        else if (strcmp(i, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_9();
    }
}

void stage_10()
{
    char j[10];
    clear();
    printf("----------------------------------------\n");
    printf("%s's current score is: %d \n",name ,score);
    printf("----------------------------------------\n\n");
    printf("FINAL CHAMBER (The Librarian)\n\n");
    sm("The chamber opens into a vast library lit by ghostly blue fire. At the center stands the",50000);
    sm("Librarian, a tall skeletal figure wrapped in torn pages, its face hidden beneath a hood",50000);
    sm("of ink. In his hands, he clutches the Shadow Book.\n",50000);
    sm("His voice drips like poison:\n",50000);
    sm("“You have come far, mortal. But the book is mine. Dare you challenge the Keeper of Secrets?”\n\n",50000);
    sm("The book pulses with dark power.\n\n",50000);
    sleep(2);
    printf("1. Face the Librarian with knowledge and truth, using every clue you learned.\n");
    printf("2. Turn and run, hoping to escape.\n");
    printf("3. Rush forward and grab the Shadow Book from his hands.\n\n");
    printf("Your selection -> ");
    scanf(" %9s",j);
    if (strcmp(j, "1")==0)
    {
        clear();
        score+=10;
        sm("You recall every clue and every whisper. The Librarian screams as the truth burns him.",10000);
        sm("His body unravels into pages... and the Shadow Book floats into your hands.\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        victory_end();
    }
    else if (strcmp(j, "2")==0)
    {
        clear();
        score-=5;
        sm("You sprint, but every corridor bends back to the start. You find yourself once again\nat the entrance hall...\n\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        stage_2();
    }
    else if (strcmp(j, "3")==0)
    {
        clear();
        sm("You snatch the book, but its curse seeps into your veins. The Librarian laughs as",10000);
        sm("your body withers. You have become the new Librarian...\n",10000);
        printf("# Press Enter to continue #");
        getchar();
        getchar();
        dead_end();
    }
        else if (strcmp(j, "reload")==0)
    {
        developer_tool();
    }
    else
    {
        sm("Invalid Input. Please try again.\n",50000);
        sleep(1);
        stage_10();
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------

// Main Function

int main()
{
    play_music();

    INTRO();
    while(1)
    {
    char* a = menu();
    if (strcmp(a, "1")==0)
    {
        clear();
        score=0;
        name=player_name();
        clear();
        stage_1();
    }
    else if (strcmp(a, "2")==0)
    {
        ins();
    }
    else if (strcmp(a, "3")==0)
    {
        story_background();
    }
    else if (strcmp(a, "4")==0)
    {
        credit();
    }
    else if (strcmp(a, "5")==0)
    {
        clear();
        sm("Thanks For Playing the game, Byeee\n",50000);
        sleep(2);
        stop_music();
        clear();
        exit(0);
    }
    else if (strcmp(a, "6")==0)
    {
    easter_egg();
    }
    else if (strcmp(a, "reload")==0)
    {
        developer_tool();
    }
    else 
    {
        printf("Invalid Input. Please try again.\n");
    }
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
