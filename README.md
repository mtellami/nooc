# Nooc

```console

   ___  ___  ___  ___
  / _ \/ _ \/ _ \/ _ 
 /_//_/\___/\___/_.__/  v0.1.0

```


- Nooc is port scanning tool written in Cpp that allows you to enumerate valid ports for hosts. It is a really simple tool that does fast SYN/CONNECT/UDP scans on the host/list of hosts and lists all ports that return a reply. 

### Features 
- Fast scan using hardware supported thread.
- DNS resolve
- Range ports scanning

### Usage

```zsh
    nooc -host example.com
```

## Options:

+ -h or -host
The hostname to scan.
```zsh
    ./nooc -h 127.0.0.2
```

+ -p or -port
The ports range: <min, max>
```zsh
    ./nooc -h 127.0.0.1 -p 1000,7000
```

