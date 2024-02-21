## Project README: Finding flag09

Our routine: 
```bash
ls -la
find / -user flag09 -print 2>/dev/null
```

We understood that the program was adding his position to each character:
For exemple : abc = a(a + pos 0)c(b + pos1)e(c + pos 2)
So we create a program that will do the complet oposite witt the chars presentes in token. (check program_flag09.c)

password for user flag09 = f3iji1ju5yuevaus41q1afiuq
getflag = s5cAJpM8ev6XHw998pRWG728z

And VOILA
