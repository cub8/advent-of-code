#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> read_data(string filename) {
  ifstream input_file(filename);
  string line;
  vector<string> lines;

  while (getline(input_file, line)) {
    lines.push_back(line);
  }

  return lines;
}

vector<int> find_numbers(vector<string> lines) {
  vector<int> numbers;
  numbers.reserve(lines.size());

  for (auto &line : lines) {
    char first_num, last_num;
    bool found_first = false;

    for (auto &chr : line) {
      bool is_digit = isdigit(chr);

      if (!is_digit)
        continue;

      if (!found_first) {
        first_num = chr;
        found_first = true;
      }

      last_num = chr;
    }

    string number;
    number += first_num;
    number += last_num;

    numbers.push_back(stoi(number));
  }

  return numbers;
}

int sum_numbers(vector<int> numbers) {
  int sum = 0;

  for (auto &num : numbers) {
    sum += num;
  }

  return sum;
}

int main(int argc, char *argv[]) {
  const char *FILENAME = argv[1];

  vector<string> data = read_data(FILENAME);
  vector<int> numbers = find_numbers(data);
  int result = sum_numbers(numbers);

  cout << "Result: " << result << endl;
}
