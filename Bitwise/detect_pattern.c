Detect a specific bit pattern such as 1011

If the question is:

Detect whether pattern 1011 exists in a bit stream.

Then a sliding-window approach is appropriate:

bool detect_pattern(uint32_t stream, uint32_t pattern, int pattern_len)
{
    uint32_t mask = (1U << pattern_len) - 1;


    for (int i = 0; i <= 32 - pattern_len; i++) {
        if (((stream >> i) & mask) == pattern)
            return true;
    }


    return false;
}

Example:

uint32_t stream  = 0b110101101;
uint32_t pattern = 0b1011;


if (detect_pattern(stream, pattern, 4))
    printf("Pattern found\n");
Important interview distinction

There are two different questions interviewers commonly ask:

"Detect N consecutive 1s" → use
n & (n >> 1) & (n >> 2)...
"Detect a specific pattern like 1011 in a bit stream" → use a mask + sliding window.
