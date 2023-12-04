# advent-of-code
When running tasks you have to pass filename from command line like this:
a) Ruby
```sh
# inside day-X directory, where X is day number
ruby ruby/solution.rb input.txt

# inside day-X/ruby directory
ruby solution.rb ../input.txt
```
b) C++
```sh
# inside day-X directory, where X is day number
g++ cpp/main.cpp -o cpp/output && ./cpp/output input.txt

# inside day-X/cpp directory
g++ main.cpp -o output && ./output ../input.txt
```
