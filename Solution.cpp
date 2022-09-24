
#include <vector>
using namespace std;

class Solution {
    
    inline static const int BITMASK_INT_128 = 1 << 7;
    inline static const int BITMASK_INT_64 = BITMASK_INT_128 >> 1;
    inline static const int MIN_LENGTH_OF_BYTES_FOR_UTF8 = 1;
    inline static const int MAX_LENGTH_OF_BYTES_FOR_UTF8 = 4;

public:
    bool validUtf8(vector<int>& data) {

        int numberOfBytesToProcess = 0;

        for (const auto& currentInt : data) {

            if (numberOfBytesToProcess == 0) {
                int bitmask = BITMASK_INT_128;
                while (((bitmask & currentInt) == bitmask) && numberOfBytesToProcess <= MAX_LENGTH_OF_BYTES_FOR_UTF8) {
                    bitmask >>= 1;
                    ++numberOfBytesToProcess;
                }
                if (numberOfBytesToProcess == MIN_LENGTH_OF_BYTES_FOR_UTF8 || numberOfBytesToProcess > MAX_LENGTH_OF_BYTES_FOR_UTF8) {
                    return false;
                }
                if (numberOfBytesToProcess > 0) {
                    --numberOfBytesToProcess;
                }
                continue;
            }

            if ((BITMASK_INT_128 & currentInt) != BITMASK_INT_128 || (BITMASK_INT_64 & currentInt) == BITMASK_INT_64) {
                return false;
            }
            --numberOfBytesToProcess;
        }
        return numberOfBytesToProcess <= 0;
    }
};
