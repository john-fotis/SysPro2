# This is the second of the total three assignments for the [Systems Programming Course](http://cgi.di.uoa.gr/~antoulas/k24/) during my B.Sc in Informatics and Telecommunications. It is based on my [first assignment](https://github.com/john-fotis/SysPro1).

## Description:
The main purpose here, is to convert the monitor application to a server-client service. The server creates a number of children monitor-applications, which are responsible to answer all the user travel requests made to the server after that moment. The main goal here is to practice on [fork-exec](https://en.wikipedia.org/wiki/Fork%E2%80%93exec) usage to create a multi-processing server. The communication between the entities is achieved through [named pipes](https://en.wikipedia.org/wiki/Named_pipe), while the application must also handle a set of different [POSIX signals](https://en.wikipedia.org/wiki/Signal_(IPC)). The pipe messages are based on a custom communication protocol, with fixed-size packets. Each packet has a 2-byte header and a payload whose size is determined by the user.

## Requirements:
- Ubuntu-based linux distribution (Developed in Ubuntu 20.04 LTS)
- GCC 7.5.0 or newer
- GNU Make 4.2.1
- Bash shell

## How to run:
You can run everything, in the root path of the project, using the [Makefile](https://github.com/john-fotis/SysPro2/blob/main/Makefile). Type `make help` for all the available options. You can also run both the script and application with the appropriate make rules. All the run parameters can be changed through the [Makefile](https://github.com/john-fotis/SysPro2/blob/main/Makefile).

## Bash-Script:
  #### You first need to produce an `input_dir` directory which contains subdirectories named after countries. Each country has a number of input record-files for the main application. For this purpose you need the [citizenRecordsFile](https://github.com/john-fotis/SysPro2/blob/main/citizenRecordsFile)
  
  ### To do this you have two options:
  1) `make scriptRun` or
  2) `./create_infiles.sh [citizenRecordsFile] [input_dir] [numFilesPerDirectory]`

  **Notes:**
  **citizenRecordsFile** is case-sensitive, however, it can be modified in the [create_infiles.sh](https://github.com/john-fotis/SysPro2/blob/main/create_infiles.sh). `input_dir` is the target directory with the final input files for the main application. Number of files per directory is at least 1.

## Application:
  #### Firstly, simply compile with `make` or `make all`.
  The application reads all the input files in the given *input_dir*. The server is responsible to spread the workload - based on countries - **evenly** among the available monitors. Each monitor initiates its database after reading its assigned record files. Afterwards, it notifies the server of its progress and sends a portion of its data to it. This data works as cache, and is used to answer user-requests fast, using only server resources. In case this cache fails to answer a request the server needs to promote the request to some or all the available monitors and wait the for the reply. The UI is sollely achieved through the server, via a terminal-menu. You can type `/help` to get all the available commands when using the application.
 
  ### The above can be tested by executing the application with:
  1) `make run` or
  2) `./travelMonitor -m numMonitors -b bufferSize -s sizeOfBloom -i input_dir`
  
  **Notes:**
  - All arguments are mandatory, case and order sensitive.
  - **bufferSize** is the number of bytes used in the custom communication protocol in the pipes.
  - Minimum **sizeOfBloom** is 1, optimal 1000 (for the current input file) and maximum tested is 100K bytes.
  - **input_dir** must be the same string as the argument given to the [create_infiles.sh](https://github.com/john-fotis/SysPro2/blob/main/create_infiles.sh).
  - You can also run with `make valgrind` rule. It has been tested for multiple leak types.
 
## Copyright and License:
#### &copy; 2021 John Fotis
#### This project is licensed under the [MIT License](https://github.com/john-fotis/SysPro2/blob/main/LICENSE.md)
