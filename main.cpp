#include <iostream>
#include <string>
#include <stdio.h>
/** cppbox - c++ playground for random stuff
*   idk how to code at all so i made this
*   yeah im rarted
*
*   a lot of parts of this code are "stolen"
*   from other people in stackoverflow. like
*   i said, i don't know how to fuclvjgn code pls help
*
*   linux only btw sorry windows users :(
*   maybe later I'll make it multi-platform but not now
*   or else I'll have to deal with re-writing the code without
*   ANSI escape codes, <windows.h> and other shit
*
*   btw this main will probally turn into a class later on
*/

/**
*           ANSI CHEATSHEET
*
*               COLORS
*            foreground background
*   black        30         40
*   red          31         41
*   green        32         42
*   yellow       33         43
*   blue         34         44
*   magenta      35         45
*   cyan         36         46
*   white        37         47
*
*             IDFK TBH
*   reset             0  (everything back to normal)
*   bold/bright       1  (often a brighter shade of the same colour)
*   underline         4
*   inverse           7  (swap foreground and background colours)
*   bold/bright off  21
*   underline off    24
*   inverse off      27
*
*   go back one line: "\x1b[1A"
*/

int main()
{
    /** looking back at this, wtf no*/
    std::cout << "\033[31mHey, press w to go up and enter to submit, arrow keys broke\ndw, if you reach first option and press w, it'll go back down\nleave blank for confirm\033[0m\n";

    std::string woahbro[3] = {"1. Option 1\n", "2. Option 2\n", "3. Option 3\n"};
    for(int i = 0; i <= 2; ++i)
    {
        if(i != 2)
        {
            std::cout << woahbro[i];
        }
        else {std::cout << "\033[32m" << woahbro[i];}
    }

    int yeah = 2;
    std::cout << "\033[0m     <--  your input\n\x1b[1A"; // karen took the fucking kids
    while(true)
    {
        char key;
        std::cin >> key;
        if(key == 'w' || key == 'W')
        {
            //BEWARE: ansi escape code garbage and terrible (but commented) coding below
            if(yeah >= 2) //if we're still at option 3
            {
                std::cout << "\x1b[1A\x1b[1A\033[0m" << woahbro[yeah]; // make current selection w/o color
                yeah = yeah - 1;
                std::cout << "\n\x1b[1A\x1b[1A\x1b[1A\033[32m" << woahbro[yeah] << "\n"; //newline, go up 2 characters and select text, then newline again
            } else if(yeah == 1)
            {
                std::cout << "\x1b[1A\x1b[1A\x1b[1A\033[0m" << woahbro[yeah]; // make current selection w/o color, this time it goes up +1 lines because of the \n above
                yeah = yeah - 1;
                std::cout << "\n\x1b[1A\x1b[1A\x1b[1A\033[32m" << woahbro[yeah] << "\n\n"; //newline, go up 2 characters and select text, then newline 2 times
            } else if(yeah == 0) //resets the niggy
            {
                std::cout << "\x1b[1A\x1b[1A\x1b[1A\x1b[1A\033[0m" << woahbro[yeah]; // make current selection w/o color, this time it goes up +2 lines because of the \n above
                yeah = 2; //default value fyi
                std::cout << "\n\033[32m" << woahbro[yeah]; //newline to the 3rd option and yeet skeet
                //cerebral palsy
            }

        } else if(key == 'S' || key == 's')
        {
            if(yeah >= 2) //if still at option 3
            {
                std::cout << "\x1b[1A\x1b[1A\033[0m" << woahbro[yeah];
                yeah = yeah - 2;
                std::cout << "\n\x1b[1A\x1b[1A\x1b[1A\x1b[1A\033[32m" << woahbro[yeah] << "\n\n";
            } else if(yeah == 1)
            {
                std::cout << "\x1b[1A\x1b[1A\x1b[1A\033[0m" << woahbro[yeah];
                yeah = yeah + 1;
                std::cout << "\033[32m" << woahbro[yeah];
            } else if(yeah == 0)
            {
                std::cout << "\x1b[1A\x1b[1A\x1b[1A\x1b[1A\033[0m" << woahbro[yeah];
                yeah = yeah + 1;
                std::cout << "\033[32m" << woahbro[yeah] << "\n";
            }
        }
    }

    return 0;
}
