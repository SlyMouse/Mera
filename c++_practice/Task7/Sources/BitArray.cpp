#include "../Headers/BitArray.h"

BitArray::BitArray(unsigned initVal)
{
    unsigned max_val = std::numeric_limits<unsigned>::max();
    int size = initVal / max_val;
    if(!size)
        size = 1;
    else
        len = size * 32;
    vec = std::vector<unsigned>(size, 0);
    int curr_index = 0;
    while(initVal != 0)
    {
        vec[curr_index] = initVal % ((unsigned long)max_val + 1);
        initVal /= max_val;
        curr_index++;        
    }
}

void BitArray::SetLength(int len)
{
    int new_size = (len + 31) / 32;
    vec.resize(new_size);
    unsigned &last_block = vec.back();
    int old_len = this->len;
    this->len = len;
    if(len % 32 != 0 && len < old_len)
        for(int i = len; i < len / 32 * 32 + 32; i++)
            this->SetBit(i, false);
    /* if(len > old_len && old_len % 32)
        for(int i = old_len; i < old_len / 32 * 32 + 32; i++)
            this->SetBit(i, false); */
}

int BitArray::GetLength()
{
    return len;
}

std::vector<unsigned> BitArray::GetVec()
{
    return vec;
}

bool BitArray::GetBit(int pos)
{
    if(pos < 0 || pos >= len)
        exit(2);
    
    unsigned curr_block = vec[pos/32];
    pos %= 32;
    
    return (curr_block >> pos) % 2;
}

void BitArray::SetBit(int pos, bool value)
{
    if(pos < 0 || pos >= len)
        exit(2);

    if(this->GetBit(pos) == value)
        return;

    unsigned &curr_block = vec[pos/32];
    pos %= 32;
    
    curr_block += pow(2, pos) * (value ? 1 : -1);
}

BitArray BitArray::operator<<(unsigned offset)
{
    BitArray copy = *this;
    // for(int i = vec.size() - 1; i > -1; i--)
    //     copy.vec[i] <<= offset;
    for(int i = len - 1 - offset; i > -1; i--)
        copy.SetBit(i + offset, copy.GetBit(i));
    for(int i = 0; i < offset; i++)
        copy.SetBit(i, false);

    return copy;
}

BitArray BitArray::operator>>(unsigned offset)
{
    BitArray copy = *this;
    // for(int i = 0; i < vec.size(); i++)
    //     copy.vec[i] >>= offset;
    for(int i = offset; i < len ; i++)
        copy.SetBit(i - offset, copy.GetBit(i));
    for(int i = len - offset; i < len; i++)
        copy.SetBit(i, false);

    return copy;
}

BitArray BitArray::operator~()
{
    BitArray copy = *this;
    for(int i = 0; i < vec.size(); i++)
        copy.vec[i] = ~copy.vec[i];

    return copy;
}

BitArray BitArray::operator&(const BitArray &other)
{
    BitArray copy = *this;
    for(int i = 0; i < vec.size(); i++)
        copy.vec[i] &= other.vec[i];

    return copy;
}

BitArray BitArray::operator|(const BitArray &other)
{
    BitArray copy = *this;
    for(int i = 0; i < vec.size(); i++)
        copy.vec[i] |= other.vec[i];

    return copy;
}

void BitArray::operator=(const BitArray &other)
{
    len = other.len;
    vec.resize((len + 31) / 32);
    for(int i = 0; i < other.vec.size(); i++)
        vec[i] = other.vec[i];
}

BitArray::BitArray(BitArray &other)
{
    *this = other;
}

std::string printBlock(unsigned block, int limit)
{
    int count = 0;
    std::string binary = "";
    while(count < limit)
        {
        if(count % 8 == 0 && count)
            binary.insert(0, " ");
        if(block % 2)
             binary.insert(0, "1");
        else
            binary.insert(0, "0");  
        count++;
        block /= 2;         
    }

    return binary;
}

std::ostream &operator<<(std::ostream &output, const BitArray &arr)
{
    std::string binary = "";
    int count = 0;
    int last_size = arr.len % 32;
    int last_index = arr.vec.size() - (!last_size ? 0 : 1);
    if(last_size)
    {
        unsigned last_block = arr.vec.back();
        output << printBlock(last_block, last_size) << " ";
    }
    for(int i = last_index - 1; i > -1; i--)
    {
        unsigned block = arr.vec[i];
        output << printBlock(block, 32);
        if(i)
            output << " ";
    }

    return output;
}