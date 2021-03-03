#include <bits/stdc++.h>

using namespace std;

int main() {
  cout << "Enter the path to the file: ";
  string path;
  std::cin >> path;

  ifstream file(path);
  // file.open();
  ofstream json("output.json");
  // json.open();
  json << "[\n";

  while (!file.eof()) {
    string line;
    getline(file, line);

    string converted = "  \"" + line + "\",\n";
    json << converted;
  }

  json << "]";
  json.close();
  file.close();

  return 0;
}