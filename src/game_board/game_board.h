#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include <functional>

namespace GameBoard {
  struct Cell {
    Cell() : current(false), next(false) { };
    bool current;
    bool next;
  };

  using Board = std::vector< std::vector<Cell> >;
  using LocMutation = std::function<void(const int&, const int&, Cell&)>;
  using Mutation = std::function<void(Cell&)>;

  class GameBoard {
    public:
      GameBoard(const int&, const int&);

      void randomize(const int&);
      bool stateOf(const int&, const int&) const;
      void print() const;
    private:
      void advance_time();
      void mutate(const LocMutation&);
      void mutate(const Mutation&);
      Board board;
  };
}

#endif
