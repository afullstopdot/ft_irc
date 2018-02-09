# ft_irc
This project is about creating an IRC client and server (Internet relay Chat) that allows to send and receives messages between many different people, from within chat groups called “channel”

## Getting Started

To use these progams [client/server] for learning or use clone it locally.

### Prerequisites

What things you need to install the software and how to install them

```
gcc or clang compiler
```

### Installing

Installing just requires a clone or download


```
git clone https://github.com/afullstopdot/ft_irc.git on terminal or download the zip straight from here.
```

## Compiling the library

For use

### Break down into end to end tests

Compile the library for use, using the Makefile

```
make all
```

Remove the object files

```
make clean
```

Remove the libft library

```
make fclean
```

Remove the library and recompile

```
make re
```

## server usage

```
./server [-p port]
```
```
port : port number
```

## client usage

```
./client [-h host] [-p port]
```

Where “hostname” is the host you want to ping

```
hostname : hostname of the machine the server is running on
```
```
port : port number
```

### Supported Commands

```
/connect <hostname> <port> - connect to server
```
```
/nick <name> - set nickname
```
```
/whoami - print set nickname
```
```
/join <channel> - join a channel
```
```
/who - list users on a channel
```
```
/msg <nickname> <msg> - send a private message to a user connected to the server
```

## Authors

* **Andre Marques** - *All* - [afullstopdot](https://github.com/afullstopdot)
* **** - *All* - [afullstopdot](https://github.com/afullstopdot)

## Resources

```
Unix Network Programming Vol 1, 3rd version
```

## Notes

```
ft_irc does not respect any rfc
```

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Disclaimer

This message pertains to the students of 42 and WTC (WeThinkCode_).

Copying this work as is, without understanding and being able to implement your own work defeats the pedagogy and subsequently is cheating.

Goodluck!
