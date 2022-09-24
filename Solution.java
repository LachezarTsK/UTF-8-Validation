
public class Solution {

    private static final int BITMASK_INT_128 = 1 << 7;
    private static final int BITMASK_INT_64 = BITMASK_INT_128 >> 1;
    private static final int MIN_LENGTH_OF_BYTES_FOR_UTF8 = 1;
    private static final int MAX_LENGTH_OF_BYTES_FOR_UTF8 = 4;

    public boolean validUtf8(int[] data) {

        int numberOfBytesToProcess = 0;

        for (int currentInt : data) {

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
}
