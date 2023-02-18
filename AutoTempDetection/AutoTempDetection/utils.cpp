#include "utils.h"
bool checkIfInt(std::any var) {
	try {
		if (std::any_cast<int>(var))
			return true;
	}
	catch (const std::bad_any_cast& e) {
		return false;
	}
}

bool checkIfNull(int var) {
	if (var == 0xFFFF)
		return true;
	else
		return false;
}