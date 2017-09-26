README
(or dont)


A shell must have 4 basic functions that are in a loop. Which are prompt, read, parse and execute. 

	The prompt part shows "myshell:" at the begining of every command line. But if "-n" was written in while starting the program is executing then there will be no prompt

	The read function of the the loop gets the user input and puts it into a char array. But if "cntrl+D" is pressed or exit command is entered the shell quits.

	Parsing part of the loop. Gets the char array as an argument from the readline and separetes the it word by word and puts it into an array of char arrays.

	Finally the exacute parts takes the array of arrays as an argument and then forks and uses execvp to call the shell function.

Troubles:
I couldnt do the metacharacters that was asked in the project. 

I started doing the pipe fuction, but because of the way i parsed my commands i needed to change the parsing. As i was trying to change my parsing and make it compatible with the pipe function I ran into some troubles. As the simple commands startes to not work and I kept gettting execution errors. Because of this i had to comment out the pipe exec.

Time was an issue for me aswell.

Resources:
https://piazza-resources.s3.amazonaws.com/irz3vwf0w5he/iteov1kwit2la/ec44004.pdf?AWSAccessKeyId=AKIAIEDNRLJ4AZKBW6HA&Expires=1474671854&Signature=II9JNMhT0ceN1OMgJH0VPbEGxQE%3D
http://brennan.io/2015/01/16/write-a-shell-in-c/
http://linuxgazette.net/111/ramankutty.html
http://stackoverflow.com/questions/19099663/how-to-correctly-use-fork-exec-wait
https://linux.die.net/man/2/pipe
Also
cplusplus.com
and
MAN pages of functions

Bogac Sabuncu
U34963528
EC440