# bbsh

**Current Version: v0.03**
What I have added so far:
- Dynamic input from scratch
- String parsers and Tokenizers from scratch
- Executing external commands with execvp
- Making my own commands (help, jmp, exit)

This is a Baby Shell that I made in C, using POSIX functions to try and understand how a terminal works under the hood.

**How this would work**
- This works like a standard shell similar to bash, some commands are of course, not built in and I had to build from scratch, meaning
I would also implement my own flags, how they work, and a pretty big manual page for it which I would do once the shell is big
enough.

## Why?
- Im just tired of seeing repos of people who do a very basic version of a shell and call it a day. Im building this so maybe
in the future someone would actually use it and hopefully enjoy the things it has to offer.

- The things I am currently working on are just the standard process to build a shell, I would implement the things I actually
want once it is stable enough for daily use.

## Version Plans:

**v0.01-0.10**
- Basic shell prompt (with directory)
- Custom input parser (to split up args and execute commands)
- Custom shell commands (alongside implementing external commands now usually included in a baby shell)
- Executing actual commands (duh)
- I/O Redirection ('<', '>', '>>', '2>')
- Pipes ('|')
- Signal Handling
- Auto Tab Completion
- Decent UI

**NOTE: the plans ain't done yet but I will eventually figure it out once im deep into the project.**

i lab c
