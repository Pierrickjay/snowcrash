## Project README: Finding flag03

After our routine: 

```bash
ls -la
find / -user flag01 -print 2>/dev/null
```

The file said exploit me.
We dowloaded the file with command:
```bash
scp -P 4343 level03@localhost:/home/user/level03/level03 ~
```

We decompile it with an online decompiler.
We saw that this program called:
```bash
/usr/bin/env echo Exploit me
```

So the idea is to make this file run getflag cause in doing so we are not running getflag as user **level03** but as **flag03** since level03 file was created by **flag03**.

To do so, we add to **$PATH** in our env a path to **/tmp/** and create a file named **echo** whitch will run getflag when executed.

We tryed and VOILA: **qi0maab88jeaj46qoumi7maus**