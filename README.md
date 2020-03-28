# CSV Parser for C++
The main goal of this project is to mimic the functionality of python's csv reader / dictionary.
[Python Reference](https://docs.python.org/3/library/csv.html)

I was looking for a library like this in c++ and couldn't find a good one so here we are.

An example usage would be like this:

```c++
// TODO: Insert example
```

## Feedback
Please feel free to provide comments / features / issues that you run into. I am more than willing to
see if that will be possible. I can't cover every case imaginable but will try to make this library
as bulletproof as possible. If you come across files or edge cases let me know!

## Testing 
I setup a folder for testing and running test on csv files that might be found. I am using the
c++ test frame worked called `Catch2` and if you aren't familiar with it the documentation is here:
[Catch2 Documentation](https://github.com/catchorg/Catch2/tree/master/docs)

If you plan on working on this project you can run tests here. Follow these instructions to
build the test and run it. First navigate into the directory `tests`.

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

This will produce an executable file named `csv_test` which can be run using `./csv_test`.
