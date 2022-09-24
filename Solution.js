
/**
 * @param {number[]} data
 * @return {boolean}
 */
var validUtf8 = function (data) {
    const BITMASK_INT_128 = 1 << 7;
    const BITMASK_INT_64 = BITMASK_INT_128 >> 1;
    const MIN_LENGTH_OF_BYTES_FOR_UTF8 = 1;
    const MAX_LENGTH_OF_BYTES_FOR_UTF8 = 4;

    let numberOfBytesToProcess = 0;

    for (let currentInt of data) {

        if (numberOfBytesToProcess === 0) {
            let bitmask = BITMASK_INT_128;
            while (((bitmask & currentInt) === bitmask) && numberOfBytesToProcess <= MAX_LENGTH_OF_BYTES_FOR_UTF8) {
                bitmask >>= 1;
                ++numberOfBytesToProcess;
            }
            if (numberOfBytesToProcess === MIN_LENGTH_OF_BYTES_FOR_UTF8 || numberOfBytesToProcess > MAX_LENGTH_OF_BYTES_FOR_UTF8) {
                return false;
            }
            if (numberOfBytesToProcess > 0) {
                --numberOfBytesToProcess;
            }
            continue;
        }

        if ((BITMASK_INT_128 & currentInt) !== BITMASK_INT_128 || (BITMASK_INT_64 & currentInt) === BITMASK_INT_64) {
            return false;
        }
        --numberOfBytesToProcess;
    }
    return numberOfBytesToProcess <= 0;
};
