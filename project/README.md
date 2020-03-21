#Blinky Buzzy Toy

For this Lab we were in charge of program he MSP430 for it to be able to,
create sounds, change the led lights and program the speaker.

To get started there are 7 .c files that make this lab up they are all linked
together in order to be able to accomplish the over all goal. You have the
main.c which initializes the msp430. along with the timerLIb files in order to
keep the set timers for your msp430.

To initialize the msp430 follow the next steps
   * open up the shell and go into the timerLib folder
   * once inside the folder type in "Make install"
   * go back to the predvious directory and then go into the toy folder once
   inside type in "make load"
   * this should initiate the board and the program should be up and running
   * if you want to erase the boards programming go ahead and type msp430 f2500
   "erase"

What you are able to do:
     * Press S1 continously and green light turns on and of periodically while
     making noise
     * S2 is the same but it has a different noise and turns on the red light
     * S3 will turn on both the green and red light and they will be turning on
     and off periodically while you hold the button
     * S4 turns off the light and emits a frequency itself.

Have Fun!
