# Installation

Clone this repo to your project and setup it as a [git submodule](https://git-scm.com/docs/git-submodule):
```
git submodule init
git submodule update
```

Then import the logger:
```
#import "./path_to_logger_repo/src/logger.h"
```

# Usage

Use the *openocd.cfg* from this repo:
```
openocd ... -f ./path_to_logger_repo/openocd.cfg
```

Specify these [parameters](https://openocd.org/doc/html/Architecture-and-Core-Commands.html) inside of *openocd.cfg*:
 - *traceclk* - specifies the frequency in Hz of the trace clock (for the TPIU embedded in Cortex-M3 or M4, this is usually the same frequency as HCLK);
 - *pinfreq* - specifies the expected data rate in Hz of the SWO pin;
 - *output* - specifies the port for output.

Then you can listen tcp/*output*. For example using netcat:
```
nc localhost 22888
```
