#include <cctype>
#include <iostream>
#include <locale>

static std::string trimSpaces(std::string word) {
  std::size_t firstSpace;
  std::size_t lastSpace;

  if (word[0] != ' ' && word[word.length() - 1] != ' ')
    return word;
  firstSpace = -1;
  while (word[++firstSpace] == ' ')
    ;
  lastSpace = word.length();
  while (word[lastSpace - 1] == ' ')
    --lastSpace;
  return word.substr(firstSpace, lastSpace - firstSpace);
}

int main(int argc, char *argv[]) {
  std::string word;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    word = argv[i];
    word = trimSpaces(word);
    for (int j = 0; j < word.length(); j++) {
      std::cout << static_cast<char>(std::toupper(word[j]));
    }
    if (argv[i + 1])
      std::cout << ' ';
  }
  std::cout << std::endl;
  return 0;
}
