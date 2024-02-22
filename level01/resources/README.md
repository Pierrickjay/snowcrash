## Project README: Finding flag01

After first level, we develop a routine:

```bash
ls -la
find / -user flag01 -print 2>/dev/null
```
But we had nothing. After doing some ressearch, we find that all password of users were save into `/etc/password`

We used:
```bash
cat /etc/password
```

We saw that password was there for flag01, but it was hashed (**42hDRfypTqqnw**)

- After some research we heard about **John the ripper**
- In order to make it work, we put the encrypted code into a file and use the following command:
```bash
./john [filename] --show
```
- And VOILA: we find the password for flag01 : **abcdefg**

- Last step, we run getflas as flag01 et get : **f2av5il02puano7naaf6adaaf**
