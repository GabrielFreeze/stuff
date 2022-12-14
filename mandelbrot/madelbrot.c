#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <math.h>
#include <inttypes.h>

#define ITERNUM 50
#define THRESH 10
#define GRAN 0.02


/*
                                                                                    ........:::..::--..
                                                                                   ..........::--:.......
                                                                                 ...........::-=::........
                                                                              ..........::::-%   =:........
                                                                           ..........:=-#--     +-+:=:.......
                                                                       ................:-           -:..........
                                                                   ...................:=*          =*+...............
                                                                 .....................::           +::...................
                                                               ......#::-:-:....::=:::::--@       #-:::::.:=..........::..
                                                             .........:-@---@:::=+  - +                @-@+ #:.......-#....
                                                          ............::     %- +                          @-@:::-+:::++-...
                                                       ...............:*     #                                 -#    %-:=...
                                                .....................:::-=*                                          =+......
                                   ..............................::--::                                           +=-:.......
                                 ................................- %                                                #-:.......
                                .....:...........................::-@                                                 ::..:...
                              ......:-:.........-:.............:-  +                                                  + *-+:..
                             ........--=-+::::::-#-:::=.......:::-*                                                     @-=...
                           ............::-%+*---=%  --%-::::::::                                                       =:.....
                         .............::=+   *         *+%:::::+                                                        +:-...
                      ..............::::-=                 #-:-=                                                       +*#:...
                  ...........:......::*                     #--*                                                        :.....
            .................:%::::::=                        +                                                        :......
       ......................::---+=-=                                                                                -.......
  ..........:.............:::--=                                                                                     :.......
:=+*=*+*+*#  #**%#%%#%%%                                                                                         +-::........
  ..........:.............:::--=                                                                                     :.......
       ......................::---+=-=                                                                                -.......
            .................:%::::::=                        +                                                        :......
                  ...........:......::*                     #--*                                                        :.....
                      ..............::::-=                 #-:-=                                                       +*#:...
                         .............::=+   *         *+%:::::+                                                        +:-...
                           ............::-%+*---=%  --%-::::::::                                                       =:.....
                             ........--=-+::::::-#-:::=.......:::-*                                                     @-=...
                              ......:-:.........-:.............:-  +                                                  + *-+:..
                                .....:...........................::-@                                                 ::..:...
                                 ................................- %                                                #-:.......
                                   ..............................::--::                                           +=-:.......
                                                .....................:::-=*                                          =+......
                                                       ...............:*     #                                 -#    %-:=...
                                                          ............::     %- +                          @- :::-+:::++-...
                                                             .........:-@---@:::=+  - +                @-@+ #:.......-#....
                                                               ......#::-:-:....::=:::::--@       #-:::::.:=..........::..
                                                                 .....................::           +::...................
                                                                   ...................:=*          =*+...............
                                                                       ................:-           -:..........
                                                                           ..........:=-#--     +-+:=:.......
                                                                              ..........::::-%   =:........
                                                                                 ...........::-=::........
                                                                                   ..........::--:.......
*/



int main() {
   
    //[-2 0.5]
    //[-1 1]
    float y1 = -1;
    float y2 = 1;
    float x1 = -2;
    float x2 = 0.5;

    char pixelmap[] = {' ',' ',' ',' ',' ',
                       '.','.','.','.','.',
                       ':',':',':',':',':',
                       '-','-','-','-','-',
                       '=','=','=','=','=',
                       '+','+','+','+','+',
                       '*','*','*','*','*',
                       '#','#','#','#','#',
                       '%','%','%','%','%',
                       '@','@','@','@','@'};

    for (float b = y1; b < y2; b+=GRAN*2) {
        for (float a = x1; a < x2; a+=GRAN) {           
            
            //z_0
            float za = a;
            float zb = b;

            //z_(n+1)
            float wa,wb;

            //Max num of iterations where the result does not tend to infinity.
            int max_n = 0;

            //As n -> ???, does z_n tend to infinity?
            for (int n = 0; n < ITERNUM; n++) {
                
                //Compute z_(n+1) using the value of z_n and the current point
                wa = (za*za - zb*zb) + a;
                wb = 2*za*zb + b;

                if (sqrt(wa*wa + wb*wb) > THRESH) {
                    //z_n is tending to infinity. C is not in Mandelbrot set.
                    max_n = n;
                    break;
                }
                za = wa;
                zb = wb;
            }

            //Display point according to max_n.
            putc(pixelmap[max_n],stdout);
        }
        putc('\n',stdout);
    }

    return 0;
}