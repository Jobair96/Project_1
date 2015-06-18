//
// Created by jobair_hassan on 16/06/15.
//

#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(Model *model) : model_(model) {

}

Controller::~Controller() {

}

void Controller::initializePlayer(const string playerType, const int playerNumber) {
    model_->setPlayer(playerType, playerNumber);
}

void Controller::initializeDeck(const int seed) {
    model_->shuffleDeck(seed);
}

void Controller::setActivePlayer(const int playerNumber) {
    model_->setActivePlayer(playerNumber);
}
int Controller::getPlayerWithSevenSpade(const Card card) const {
    return model_->getPlayerWithCard(card)->playerNumber();
}

void Controller::updateLegalPlays() {
    model_->updateAllLegalPlays();
}

Player* Controller::activePlayer() const {
    return model_->activePlayer();
}

void Controller::setFirstPlayer(const int playerNumber) {
    setActivePlayer(playerNumber);
    model_->activePlayer()->setLegalPlay(Card(SPADE, SEVEN));
}

bool Controller::isLegalPlay(const Card card) const {
    return model_->activePlayer()->checkCard(card);
}

void Controller::playCard(Card card) {
    model_->activePlayer()->removeCardFromHand(card);
    model_->addCardToTable(card);
    model_->updateAllLegalPlays();
    model_->updateActivePlayer();
}

void Controller::rageQuit() {
    model_->replaceCurrentHumanWithComputer();
}

void Controller::completeComputerTurn() {
}

void Controller::discard(const Card card) {
    if(model_->activePlayer()->legalPlays().size() != 0) {
        model_->activePlayer()->removeCardFromHand(card);
        model_->activePlayer()->discard(card);
    } else {
        cout << "You have a legal play. You may not discard" << endl;
    }

}
