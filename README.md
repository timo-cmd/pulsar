# Pulsar

<!--

[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/jakerockland/Swisp/blob/master/LICENSE.md) [![Build Status](https://travis-ci.org/jakerockland/Swisp.svg?branch=master)](https://travis-ci.org/jakerockland/Swisp) [![Codecov](https://img.shields.io/codecov/c/github/jakerockland/Swisp.svg?branch=master)](https://codecov.io/gh/jakerockland/Swisp/branch/master) ![platforms](https://img.shields.io/badge/platforms-macOS%20%7C%20Linux-333333.svg) [![Swift Package Manager compatible](https://img.shields.io/badge/Swift%20Package%20Manager-compatible-brightgreen.svg)](https://github.com/apple/swift-package-manager)

A simple Scheme (Lisp dialect) interpreter written in Swift.

Inspired by [(How to Write a (Lisp) Interpreter (in Python))](http://norvig.com/lispy.html) by [Peter Norvig](http://norvig.com).

## Usage

Swisp can be built and run locally using the Swift compiler:

```
git clone https://github.com/jakerockland/Swisp.git
cd Swisp
swift build
.build/debug/Swisp
```

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

Copyright (c) 2016 Jake Rockland (http://jakerockland.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.-->

```c
@misc{Pulsar-v0.0.3,
  author = {Timo Sarkar},
  title = {Pulsar Ransomware },
  year = {2020},
  howpublished = {\url{https://github.com/timo-cmd/pulsar}}
}

