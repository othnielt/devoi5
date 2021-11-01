#include <cstdlib>
#include <Card.h>
#include <ctime>
#include <cassert>

 // question 1

 void Card :: write (){
   
  if (col == 0) {
		cout << "Color: club";
	}
	if (col == 1) {
		cout << "Coleur: diamond";

	}
	if (col == 2) {
		cout << "Color: heart";
	}
	 if (col == 3) {
		cout << "Color: spade";
	}

	if (val < 11) {
		cout << "Valeur: " << val << endl;
	}
	if (val == 11) {
		cout << "Valeur: jack" << endl;
	}
    if (val == 12) {
		cout << "Valeur: queen" << endl;
	}
    if (val == 13) {
		cout << "Valeur: king" << endl;
	}
}


// question2 


void CardsSet::novSet() {
	empty();
	for (int i = 0; i < 4; i++) {


		for (int j = 1; j < 14; j++) {



			set[number++] = Card(static_cast<color>(i), j);

		}
	}
}

// melange les carte 
void CardsSet::shuffle() {

	srand(time(0));

	for (int i = 0; i < 52; i++) {
		int randomNumber = i + (rand() % (number - i));
		swap(set[i], set[p]);
	}
}

// prendre une carte dans le jeu et le renvoie 
Card CardsSet::take() {
	Card getTime = set[0];

	for (int i = 0; i < number - 1; i++) { 

		set[i] = set[i + 1];
	}

	number -1;


	return getTime;
}

// mettre une carte sur le plateau 
void CardsSet::put(Card card) {

	if (number < 52) {

		set[number++] = card;
	}
}


Card CardsSet::lookIn(int no) {

	if (no < 53) {

		return set[no - 1];

	}
	else {

		return set[0];
	}
}


// question 3 

// renvoie le nombre de point en main 
int Player::play() {

	bool joueur = true;

	char reponse[3];

	Card card;

	inHand.empty();
    
	 
	if (!computer) {

		
		cout << "Current player is " << endl;
	
	}
	else {
		
		cout << "Current player is computer: " << endl;
		
	}

	while (joueur && packet.numCards() > 0) {

		card = packet.take();

		inHand.put(card);
        
        

		cout << "Do you want another card?" << endl;

		cin >> answer;

		joueur = (reponse[0] == 'y');
	}

	return countPoints();
} 





int Player::countPoints() {

	Card  card;

	int total = 0;

	int as = 0;


	for (int i = 1; i <= inHand.numCards(); i++) {

		card = inHand.lookIn(i);

		if (card.value() == 1) {

			as = as+1;

			total =  total + 14;
		}
		else {

			total =  total + card.value();
		}
	}

	while (as > 0 && total > 21) {
		total = total - 13;
		as-1;
	}
	
	return total;
}







 

