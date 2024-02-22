## Project README: Finding flag02

After our routine:

```bash
ls -la
find / -user flag01 -print 2>/dev/null
```

There was a **.pcap file**
We dowload it in our Deskopt with:
```bash
scp -P 4343 level02@localhost:/home/user/level02/level02.pcap ~
```

While looking for a .pcap reader, we finded the Software Wireshark.
Into Wireshark, we went to `statistics->conversation->tcp->FollowStream`
We can see some **passord**: so we took the character after it and try it without succes.
We realized that 7F on ascii table corresponded with del.
So everytime there was a 7f, we removed the corresponding char.

password before: **ft_wandr...NDRel.L0L**.

password after: **ft_waNDReL0L**.

Same step as always, run getflag as flag02 and get: **kooda2puivaav1idi4f57q8iq**

