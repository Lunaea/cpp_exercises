#include "patron.h"

bool operator==(const Patron& a, const Patron& b) { return (a.getCard() == b.getCard()); }
bool operator!=(const Patron& a, const Patron& b) { return !(a == b); }