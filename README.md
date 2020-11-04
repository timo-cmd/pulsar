# Pulsar

An aggressive polymorphic ransomware written in optimizing C99 and C++20. Written for research and malware analysis. Pulsar consists of a encryption file which does all the primar function such as encrypting the current partition and loading the payload message. On the other hand, pulsar comes served with a strong kernel that allows the virus to modify it selfe by using polymorphic source-encryption and debugging. The Pulsar malware can be distributed using either a c&c-server or via mail using a makro file. Pulsar is thought to attack linux os only, since I'm still working on cross-platform availabillity.

## Usage

Pulsar can be built and run locally using this snippet

```sh
git clone https://github.com/timo-cmd/pulsar.git
cd pulsar-main
chmod a+x sources/encrypt.c
make install
make build
./sources/encrypt
```

In order to decrypt the files do so.:

```sh
cd PathToPulsarKernel
chmod a+x sources/decrypt.c
make decrypt
./sources/decrypt
```

I suggest to run the virus on a vm only since this is dangerous real-life malware

<!--
To run Swisp with an input file containing your Lisp code:

```
.build/debug/Swisp -i filename
```

To run Swisp in interactive REPL mode:

```
.build/debug/Swisp
```

Example of REPL in action:

```
Swisp> (define r 10)
Swisp> (* pi (* r r))
314.159265358979
Swisp> (if (> (* 11 11) 120) (* 7 6) oops)
42
Swisp> 
```

To run the tests:

```
swift test
```

## Contributions

I welcome contributions; however, please add relevant unit tests for any new features or procedures.

## License
-->

```ruby
@misc{Pulsar-v0.0.3,
  author = {Timo Sarkar},
  title = {Pulsar Ransomware },
  year = {2020},
  howpublished = {\url{https://github.com/timo-cmd/pulsar}}
}
```
Built by <a href="http://timo-cmd.github.com">Timo Sarkar </a>.
