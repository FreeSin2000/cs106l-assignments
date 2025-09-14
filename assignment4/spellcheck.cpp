#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  auto space_it = find_all(source.begin(), source.end(), isspace);
  Corpus tokens;
  std::transform(
    space_it.begin(), space_it.end() - 1, 
    space_it.begin() + 1,
    std::inserter(tokens, tokens.end()),
    [&source](auto it1, auto it2) {
      return Token{source, it1, it2};
    }
  );
  std::erase_if(tokens, [](auto token){ return token.content.empty();});
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  auto view =
    source
    | rv::filter([&dictionary](auto token) { return !dictionary.contains(token.content);})
    | rv::transform(
      [&dictionary](auto token) {
        auto view = dictionary | rv::filter([&token](auto dic_word) {return levenshtein(token.content, dic_word) == 1;});
        std::set<std::string> suggestions(view.begin(), view.end());
        return Misspelling{token, suggestions};
      }
    )
    | rv::filter([](auto misspelling) { return !misspelling.suggestions.empty();});
  return std::set<Misspelling>(view.begin(), view.end());
};

/* Helper methods */

#include "utils.cpp"