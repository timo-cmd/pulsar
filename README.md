# Pulsar

An aggressive polymorphic ransomware written in optimizing Golang. Written for research and malware analysis. Pulsar consists of a encryption file which does all the primar function such as encrypting the current partition and loading the payload message. On the other hand, pulsar comes served with a strong kernel that allows the virus to modify it selfe by using polymorphic source-encryption and debugging. The Pulsar malware can be distributed using either a c&c-server or via mail using a makro file. Pulsar is thought to attack windows os only, since I'm still working on cross-platform availabillity.

## Usage

Pulsar can be built and run locally using this snippet

```sh
# clone this repo branch
cd pulsar-main
cd test
setup.cmd
```

Lets encrypt some test files:

```sh
keygen.cmd # generates the public and the private key
crack.cmd
```

In order to decrypt the files do so.:

```sh
decrypt.cmd
```

I suggest to run the virus on a vm only since this is dangerous real-life malware

## Contributions

I welcome contributions; however, please add relevant unit tests for any new features or procedures.

## License

```ruby
@misc{Pulsar-v0.0.3,
  author = {Timo Sarkar},
  title = {Pulsar Ransomware },
  year = {2020},
  howpublished = {\url{https://github.com/timo-cmd/pulsar}}
}
```
Built by <a href="http://timo-cmd.github.com">Timo Sarkar </a>.
