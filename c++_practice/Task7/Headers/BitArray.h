#include <vector>
#include <iostream>
#include <limits>
#include <math.h>
#include <string>

class BitArray
{
    public:
        BitArray(unsigned initVal);
        BitArray(BitArray &other);
        void SetLength(int len);
        int GetLength();
        void SetBit(int pos, bool value);
        bool GetBit(int pos);
        BitArray operator<<(unsigned offset);
        BitArray operator>>(unsigned offset);
        BitArray operator~();
        BitArray operator&(const BitArray &other);
        BitArray operator|(const BitArray &other);
        void operator=(const BitArray &other);
        friend std::ostream &operator<<(std::ostream &output, const BitArray &arr);
        std::vector<unsigned> GetVec();
    private:
        std::vector<unsigned> vec;
        size_t len = 32;
};