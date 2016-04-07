Testing C
=========

A fun minimal testing framework written in C. Works like this:

```
$ make 
gcc test.c ok.c fun.c -o spec
./spec
..F.F

Two some_test_name_4 failed.
One some_test_name_2 failed.

Finished in 0.019 seconds.
```

Just make sure `test.c` comes before your test files. This let's the test suite init properly so you don't need to register your tests. 

This project makes use of `((constructor))` to execute code before `main`. It _should_ work with gcc and clang.

**License**

This is free to use and break and make and take.
