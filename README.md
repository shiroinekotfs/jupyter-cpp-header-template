# C++ Header template for Jupyter C++ kernel

C++ kernel for Jupyter headers template. Used to provide additional abilities for the kernel.

## Getting started

You can fork, import, or clone this template freely.

### Designing C++ header extension

You may note these requirements in designing a C++ header for Jupyter.

* **DO NOT USE** `using namespace std;` in the HEADER. It may raise additional errors, including conflict with other headers, resulting in undefined states of the whole kernel. It is also causing some **security** issues on the Enterprise deployment, such as [Research Labs](https://github.com/TheFlightSims/research-labs)

* No `stdin`. It includes these commands that are banned and cannot be executed generally once the external header is used:

```C++
std::cin >> some_variables_1;
cin >> some_variables_2;
std::getline(std::cin, some_string_1);
getline(cin, some_string_2);
```

It is because the C++ kernel uses pre-processing to add the I/O for user interactive, which means it can only process on the pre-compile `.cpp` file on each cell, not headers.

* Using namespace for your header. We do recommend not requiring it. However, if you want a user to use the code globally, save the code as you usually do.

* Include guard is **RECOMMENDED** to prevent any conflict while importing, declaring and using functions in C++ headers. To know what the guard is, check out this [Wikipedia page](https://en.wikipedia.org/wiki/Include_guard)

### Versioning headers

The version of headers must match the installed C++ kernel.

In the file `setup.cfg`, you can edit the version in the line 4:

```python
4 version = 1.0.0a5
```

Also, you can manipulate `setup.py` at the line 5:

```python
5       version='1.0.0a5',
```

### Include header files into

The C++ kernel can only interpret headers under the `{environment_path}/share/cpp_header`, but not in the sub-folders. If you want to include headers that are also in the subfolder (for example, in this repo, in the `sample/res` folder), your master header (in this example the `sample.hpp`) must include these headers with your property path.

Once it's completed, add all your headers in `setup.py` at line 22:

```python
22       data_files = [
23           ("share/cpp_header", ['sample/sample.hpp']),
24           ("share/cpp_header/res", ['sample/res/legacy.c', 'sample/res/linker.hpp'])
25       ]
```
