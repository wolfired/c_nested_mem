# c_nested_mem
a c template for nested memory lifecycle management

# Usage

```bash

xmake f -p linux -a x64 -m debug
xmake b -a
GCOV_PREFIX=./build/.codecov GCOV_PREFIX_STRIP=64 xmake r -a

gcov -n ./build/.codecov/*.o && mv ./*.gcov ./build/.codecov
#or
gcov ./build/.codecov/*.o && mv ./*.gcov ./build/.codecov
# or
gcov -H ./build/.codecov/*.o && mv ./*.gcov ./build/.codecov
# or
gcov -H -k ./build/.codecov/*.o && mv ./*.gcov ./build/.codecov

lcov --capture --directory ./build/.codecov --output-file ./build/.codecov/coverage.info

```