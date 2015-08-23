#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <vector>
#include <algorithm>

class Deck {
public:
	Deck() : cards_(52) {
		Card cards[] = {
			CLUB_ACE, CLUB_2, CLUB_3, CLUB_4, CLUB_5, CLUB_5, CLUB_6, CLUB_7, CLUB_8, CLUB_9, CLUB_10, CLUB_JACK, CLUB_QUEEN, CLUB_KING,
			DIAMOND_ACE, DIAMOND_2, DIAMOND_3, DIAMOND_4, DIAMOND_5, DIAMOND_5, DIAMOND_6, DIAMOND_7, DIAMOND_8, DIAMOND_9, DIAMOND_10, DIAMOND_JACK, DIAMOND_QUEEN, DIAMOND_KING,
			HART_ACE, HART_2, HART_3, HART_4, HART_5, HART_5, HART_6, HART_7, HART_8, HART_9, HART_10, HART_JACK, HART_QUEEN, HART_KING,
			SPADE_ACE, SPADE_2, SPADE3, SPADE_4, SPADE_5, SPADE_5, SPADE_6, SPADE_7, SPADE_8, SPADE_9, SPADE_10, SPADE_JACK, SPADE_QUEEN, SPADE_KING
		};
		for (int i = 0; i < 52; ++i) {
			cards_[i] = cards[i];
		}
	}

	void shuffle() {
		std::random_shuffle(cards_.begin(), cards_.end());
	}

	Card peak() const {
		return cards_.back();
	}

	void pop() {
		cards_.pop_back();
	}
private:
	std::vector<Card> cards_;
};

#endif // DECK_H
