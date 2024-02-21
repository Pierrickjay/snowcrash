## Project README: Finding flag14

Our routine: 
```bash
ls -la
find / -user flag14 -print 2>/dev/null
```
But this time, nothing ...
But after searching for something we realized that we needed to exploit getflag.

So we tryed the same method then level13 but getflag was over-protected.

So the idea is to use gdb for **switching value and bypass all protection** of getflag.

```bash
Breakpoint 12, 0x0804898e in main ()
(gdb) set $eax = 0
(gdb) step
Single stepping until exit from function main,
which has no line number information.

Breakpoint 14, 0x08048b02 in main ()
(gdb) set $eax = 3014
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) n
Program not restarted.
(gdb) step
Single stepping until exit from function main,
which has no line number information.

Breakpoint 13, 0x08048bb6 in main ()
(gdb) step
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

And VOILA
