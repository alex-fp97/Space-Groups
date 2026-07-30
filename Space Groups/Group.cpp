#include "Group.h"
#include <iostream>
#include <functional>
#include <vector>

//template<typename T> Group<T>::Group(const std::vector<T> &elements, std::function<T(const T&)> func) : gp_elements(elements)
//{
//    gp_operation = func<T>;
//}

template<typename T> Group<T>::~Group()
{
    delete gp_operation;
}



/*template<typename T, typename Op> T Group<T, Op>::findIdentity()
{
	T sample = group_elements[0];
	T opedSample;
	while (true) {
		opedSample = group_operator(sample, sample);
		if (group_operator(opedSample, sample) == sample) {
			identity = opedSample;
			break;
		}
	}

    #include <iostream>
#include <functional> // Για το std::modulus

// Δημιουργούμε έναν δικό μας τύπο που "ντύνει" τον ακέραιο
struct Number {
    int value;

    // Constructor για να μετατρέπεται αυτόματα ένας αριθμός σε Number
    Number(int v) : value(v) {}
};

// Υπερφορτώνουμε τον τελεστή * για τον τύπο Number
// Επιστρέφει απευθείας το αποτέλεσμα χρησιμοποιώντας τη std::modulus
int operator*(Number lhs, Number rhs) {
    return std::modulus<int>{}(lhs.value, rhs.value);
}

int main() {
    // Ορίζουμε δύο αντικείμενα Number
    Number x = 10;
    Number y = 3;

    // Χρήση ΜΟΝΟ του τελεστή * χωρίς παρενθέσεις ή επιπλέον κλήσεις συναρτήσεων
    int result = x * y;

    std::cout << "Το αποτέλεσμα είναι: " << result << std::endl; // Έξοδος: 1 (10 % 3)
    return 0;
}








}*/