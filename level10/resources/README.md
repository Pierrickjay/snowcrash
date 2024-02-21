## Project README: Finding flag10

Our routine: 
```bash
ls -la
find / -user flag10 -print 2>/dev/null
```

We decompiled the file after we dowloaded with command:
```bash
scp -P 4343 level010@localhost:/home/user/level10/level10 ~
```

We realize it s client that need to connect to a **server**.
So we created the serv present in **main_10.c**. But when we tried to pass **token** to ./level10 he did connect to the serv but we didn't have access to **token** so didn't work.

We searched online for exploit on **access** and we realise it's possible to switch between to file with **symlink**.
The idea is to execute level10 with our link pointing to the authorize file and switching it with the token file while level10 is running. In doing so, we were able to b**ypass acces** and open file not authorize and read the token file.

And VOILA
