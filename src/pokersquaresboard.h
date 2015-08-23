#ifndef POKERSQUARESBOARD_H
#define POKERSQUARESBOARD_H

#include "card.h"

#include <array>

enum class Line {ONE, TWO, THREE, FOUR, FIVE};
enum class Row {ONE, TWO, THREE, FOUR, FIVE};

class PokerSquaresBoard {
public:
	PokerSquaresBoard(Card card1, Card card2, Card card3, Card card4, Card card5) {
		for (Card& card : lines_) {
			card = Card::NO_VALUE;
		}
		lines_[0] = card1;
		lines_[1 * 5] = card2;
		lines_[2 * 5] = card3;
		lines_[3 * 5] = card4;
		lines_[4 * 5] = card5;
		currentRow_ = Row::ONE;
	}
	
	inline bool put(Card card, Line line) {
		int index = (int) line + (int) currentRow_ * 5;
		if (lines_[index] == Card::NO_VALUE) {
			lines_[index] = card;
			return true;
		}
		return false;
	}

	inline Card getCard(Line line, Row row) const {
		return lines_[(int) line + (int) row * 5];
	}

private:
	Row currentRow_;
	std::array<Card, 5 * 5> lines_;
};

#endif // POKERSQUARESBOARD_H
