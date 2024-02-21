## Project README: Finding flag00

After watching intra's video for this project, we believed that we needed to use find. (find in capslock in video)

So we tryed to find any file with flag00 as creator.

To do so we used:
```bash
find / -user flag00 -print 2>/dev/null
```

Explanation of the command:

- **find**: Command to search for files and directories.
- **-user** flag00: Specifies the search criteria to look for files created by the user flag00.
- **--print 2>/dev/null**: Redirects error messages to /dev/null to prevent them from being displayed.

One of our file allowed was named john (PATH: /usr/sbin/john)

We used:
```bash
cat /usr/sbin/john
```

Witch return us cdiiddwpgswtgt;
We tryed this as  password for user flag00... 
Not a succes. 
So we decided to put it into the website Dcode.
We realize it was a cesar code.
cdiiddwpgswtgt decrypted give us: `nottoohardhere`

We used it in order to log as flag00 and run `getflag`