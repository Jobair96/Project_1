//
// Created by jobair_hassan on 16/06/15.
//

#ifndef MODEL_H
#define MODEL_H

#include "Deck.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "TableCards.h"


class Model {

public:
    Model();
    ~Model();

    Deck deck() const;
    TableCards tableCards() const;

    void setPlayer(const std::string, const int);
    void shuffleDeck(const int);
    void setActivePlayer(const int);
    void setLegalPlay(const Card);

    void updateLegalPlays(Card card);

    void updateActivePlayer();

    void addCardToTable(const Card);

    Player* getPlayerWithCard(const Card) const;
    Player* activePlayer() const;
    int getActivePlayerNumber() const;
    Card getFirstLegalPlay() const;
    std::vector<Card> getDiscards(int) const;
    int getScore(int) const;
    int getScoreGain(int) const;
    std::vector<int> getWinners() const;

    bool allHandsEmpty() const;
    bool hasLegalPlay() const;

    bool isLegal(const Card) const;
    bool isActiveHumanPlayer() const;
    bool isEndOfGame() const;

    void updateScore(int);

    void clearTable();
    void resetPlayers();
    void resetLegalPlays();

    void replaceCurrentHumanWithComputer();

private:
    Deck deck_;
    TableCards tableCards_;
    std::vector<Card> legalPlays_;

    Player *player_1_;
    Player *player_2_;
    Player *player_3_;
    Player *player_4_;

    Player *activePlayer_;

    std::string playerTypes_[4];

    Player *getPlayer(int) const;
};


#endif //MODEL_H
