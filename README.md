# library-management
Educational-purpose library management cli app using C++

## Usage
### Prerequisites:
* CMake (download binaries from [official download page](https://cmake.org/download/#latest))
* Some C++ compiler. on your own :)
### 1. Clone repository:
 ```sh
 git clone git@github.com:xeptore/library-management.git
 cd library-management
 ```
### 2. Build:
```sh
cd build
cmake ..
make
```
### 3. Execute:
```sh
./bin/lib
```

## Lessons Learned:
* First using CMake experience:  
As of current version (3.14.5), official documentation was a bit confusing, other blog posts (ill list them below, _BE PATIENT!_) were much more useful (and also much more _old_!)
* First OOP experience in C++:  
Seems a bit bothering, were CMake configurations, and _library linking_ things come in, and I couldnt really find out **why it was not working** (when following documentation), and **why it was working**!
But thinking in memory addresses, pointers, iterators, and standard data structures, was not so bad.
After getting _odd!_ CMake configurations done and started _real_ programming, I found many similarities and thoughts as i had when i am programming with younger son of C++, Golang (_and also same feelings!_).
---

## Docs I've Used:
Here are links to documentation and blog posts i've used till now:
* [CMake Official Tutorial](https://cmake.org/cmake-tutorial/):  
Actually Step 2 for adding libraries (models and helper functions).
* [This Blog Post](http://derekmolloy.ie/hello-world-introductions-to-cmake/):  
Very helpful blog post i've found that helped me _finally_ configure CMake.
* [This Blog Post](http://gernotklingler.com/blog/care-include-dependencies-cpp-keep-minimum/) and [This Reference Page](https://en.cppreference.com/w/cpp/language/class):  
I had a problem ( another one :) ) in **circular library linking** which _somehow_ was same as what i had in Golang when i first started it.  
This blog post and this questions ([1](https://stackoverflow.com/questions/30223453/c-circular-dependency-in-header-files) & [2](https://stackoverflow.com/questions/39722036/circular-dependencies-between-c-classes)) helped me solve it using combination of _forward declaration_ and _pointer type class members_.  
* [This Q/A](https://stackoverflow.com/questions/20153220/c-vector-stdbad-alloc-error):
When i was working with `std::vector`s which contain pointers to some data types (book type), and iterating over them in `main.cpp` (not in their own class), i was getting `std::bad_alloc` error. In [this commit](https://github.com/xeptore/library-management/commit/6f5254270a6275b69ccbd8c3dd4bd3ce9acc2f34), and [these lines](https://github.com/xeptore/library-management/blob/6f5254270a6275b69ccbd8c3dd4bd3ce9acc2f34/src/main.cpp#L269-L274), where i have to iterate on _book_ `vector`, if i was using vector directly in the loop, it raises mentioned error, but when i store its address into another variable (in this case `books`) before the loop and then use that variable in loop iteration (`.begin()`, and `.end()`), everything would work fine.
* [Standard Library Reference](http://www.cplusplus.com/reference/string/to_string/):
Simple `std::to_string()` function used to convert `int` to `std::string`.
* [This](https://www.hackerearth.com/practice/notes/validating-user-input-in-c/) and [this](https://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm) blog posts:
I had a problem using `std::getline()` function, which receives empty string when is was used after `cin`. I found this blog post and [this](https://stackoverflow.com/questions/5739937/using-getlinecin-s-after-cin) stackoverflow q/a useful in solving my problem.  
* [gologger](https://github.com/xeptore/gologger):  
My own project. Used for copying ugly codes to colorize console outputs.  
And also [this](https://en.wikipedia.org/wiki/ANSI_escape_code) WikiPedia  page for ASCII color codes.

---

2019 - [_@xeptore_](https://gitlab.com/xeptore)
