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
*/
int main()
{

    std::cout << "\033[31mHey, press w to go up and enter to submit, arrow keys broke\ndw, if you reach first option and press w, it'll go back down\ncurrently down scroll broke so yeah F\033[0m\n";
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
            //BEWARE: ansi escape code garbage below
            if(yeah >= 2)
            {
                std::cout << "\x1b[1A\x1b[1A\033[0m" << woahbro[yeah]; // make current selection w/o color
                yeah = yeah - 1;
                std::cout << "\n\x1b[1A\x1b[1A\x1b[1A\033[32m" << woahbro[yeah] << "\n"; //newline, go up 2 characters and select text, then newline again
            } else if(yeah == 1)
            {
                std::cout << "\x1b[1A\x1b[1A\x1b[1A\033[0m" << woahbro[yeah]; // make current selection w/o color, this time it goes up +1 lines because of the \n above
                yeah = yeah - 1;
                std::cout << "\n\x1b[1A\x1b[1A\x1b[1A\033[32m" << woahbro[yeah] << "\n\n"; //newline, go up 2 characters and select text, then newline 2 times
            } else if(yeah == 0)
            {
                // all lines are probally done for, so instead of giving the user eye rape and making the program eat shit, I'll add a safeguard
                // we're only working with 4 lines anyway, and only 3 of them are actually being scrolled and used
                std::cout << "\x1b[1A\x1b[1A\x1b[1A\x1b[1A\033[0m" << woahbro[yeah]; // make current selection w/o color, this time it goes up +2 lines because of the \n above
                yeah = 2; //default value fyi
                std::cout << "\n\033[32m" << woahbro[yeah]; //newline to the 3rd option and yeet skeet
                //cerebral palsy
            }

        } else if(key == 'S' || key == 's')
        {
            if(yeah >= 2)
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
