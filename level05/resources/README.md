## Project README: Finding flag05

Upon our initial login as **flag05**, we noticed the presence of a **new mail**. Intriguing, but the real surprise awaited us when we decided to explore the files that flag05 could execute. We ran the following command:

```bash
find / -user flag05 2>/dev/null
```

To our discovery, we found a program in the directory **/opt/openarenaserver/\*** that could execute any file within the repository. The catch? It could only be run by **flag05**.

Eager to exploit, we decided to place the **getflag** executable inside the directory **/opt/openarenaserver/** and executed it. Surprisingly, within 2 seconds, we received a token. Odd, isn't it?

Delving deeper into the Linux mail system, we navigated to **/var/mail** and stumbled upon a **crontab** configuration file. This file was executing the program with **sudo privileges**, shedding light on the mysterious behavior.

It became clear that the automated execution, triggered by the crontab configuration, was the reason behind the timely token delivery. Understanding this mechanism allowed us to successfully retrieve the coveted flag.

