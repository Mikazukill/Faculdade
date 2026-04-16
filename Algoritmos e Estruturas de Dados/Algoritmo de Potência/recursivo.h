int recursiva(int base, int exp) {

    if (exp > 0 && base > 0) {
        if (exp == 0) {
            return 1;
        } else if (exp == 1) {
                return base;
            } else {
                return recursiva(base, exp - 1)* base;
            }
    } else {
        return -1;
    }
}
