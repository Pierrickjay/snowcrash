## Project README: Finding flag13

Our routine: 
```bash
ls -la
find / -user flag13 -print 2>/dev/null
```

We saw that in the decompile that the function was calling getuid. So our idea was to **create a function: getuid**

After that we create a lib.so with this file and we use this lib to compile our program.
to do inside the /var/crash :

```bash
gcc -shared -fPIC -o libgetuid_override.so getuid.c -ldl
then put this lib as a default lib :
export LD_PRELOAD=/var/crash/libgetuid_override.so
```
Then if we execute just like this and doesn't work but if we try with *gdb* it does work.

```bash
(gdb) b main
Breakpoint 1 at 0x804858f
(gdb) run
Starting program: /home/user/level13/level13

Breakpoint 1, 0x0804858f in main ()
(gdb) step
Single stepping until exit from function main,
which has no line number information.
your token is 2A31L79asukciNyi8uppkEuSx
0xb7e424d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

And VOILA
