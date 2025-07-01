# Bitwise Operations and Bit Manipulation

## Overview

Bitwise operations are fundamental low-level operations that work directly on the binary representation of numbers. They are essential for performance-critical applications, embedded systems, and competitive programming.

## Basic Bitwise Operators

### AND Operator (`&`)
Returns 1 only when both corresponding bits are set to 1.

**Use case**: Check if both bits are set
```c
5 & 3     // 101 & 011 = 001 = 1
12 & 8    // 1100 & 1000 = 1000 = 8
```

### OR Operator (`|`)
Returns 1 when at least one corresponding bit is set to 1.

**Use case**: Check if at least one bit is set
```c
5 | 3     // 101 | 011 = 111 = 7
12 | 8    // 1100 | 1000 = 1100 = 12
```

### XOR Operator (`^`)
Returns 1 when corresponding bits are different (exclusive OR).

**Use case**: Find if at least one bit is different; result is 0 when bits are the same
```c
5 ^ 3     // 101 ^ 011 = 110 = 6
12 ^ 8    // 1100 ^ 1000 = 0100 = 4
```

### NOT Operator (`~`)
Flips every bit (bitwise complement).

**Use case**: Invert all bits
```c
~5        // ~00000101 = 11111010 = -6 (in two's complement)
```

## Power of Two Detection

### Key Property
If `k = 2^n`, then `k & (k-1) == 0`

**Examples**:
```c
8 & 7     // 1000 & 0111 = 0000 = 0 ✓ (8 = 2³)
16 & 15   // 10000 & 01111 = 00000 = 0 ✓ (16 = 2⁴)
6 & 5     // 110 & 101 = 100 ≠ 0 ✗ (6 is not a power of 2)
```

**Implementation**:
```c
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

## Bit Manipulation Operations

### Set a Bit
Set the x-th bit in number n:
```c
n | (1 << x)
```
**Example**: Set 2nd bit in 5 (101) → `5 | (1 << 2)` = `101 | 100` = `111` = 7

### Flip a Bit
Toggle the x-th bit in number n:
```c
n ^ (1 << x)
```
**Example**: Flip 1st bit in 5 (101) → `5 ^ (1 << 1)` = `101 ^ 010` = `111` = 7

### Clear a Bit
Clear the x-th bit in number n:
```c
n & ~(1 << x)
```
**Example**: Clear 0th bit in 5 (101) → `5 & ~(1 << 0)` = `101 & 110` = `100` = 4

### Check if Bit is Set
Check if the x-th bit is set:
```c
bool isBitSet(int n, int x) {
    return (n & (1 << x)) != 0;
}
```

## Divisibility by Powers of 2

When a number is divisible by 2^n, the last n bits of that number will be zero.

**Examples**:
- 8 (divisible by 2³) → `1000` (3 trailing zeros)
- 16 (divisible by 2⁴) → `10000` (4 trailing zeros)
- 12 (divisible by 2²) → `1100` (2 trailing zeros)

## Brian Kernighan's Algorithm

### Clear Rightmost Set Bit
The operation `n & (n-1)` clears the rightmost set bit.

**Example**:
```
n     = 00110100  (52)
n-1   = 00110011  (51)
n&(n-1) = 00110000  (48)
```

### Count Set Bits Implementation
```c
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);  // Clear rightmost set bit
        count++;
    }
    return count;
}
```

**How it works**: Each iteration removes exactly one set bit, so the loop runs exactly as many times as there are set bits.

## GCC Built-in Functions

GCC provides optimized built-in functions for common bit operations:

| Function | Description | Example |
|----------|-------------|---------|
| `__builtin_popcount(x)` | Count set bits (Hamming weight) | `__builtin_popcount(52)` → 3 |
| `__builtin_clz(x)` | Count leading zeros (32-bit) | `__builtin_clz(52)` → 26 |
| `__builtin_ctz(x)` | Count trailing zeros | `__builtin_ctz(52)` → 2 |
| `__builtin_ffs(x)` | Find first set bit (1-based, 0 if x=0) | `__builtin_ffs(52)` → 3 |
| `__builtin_parity(x)` | Check if set bit count is odd | `__builtin_parity(52)` → 1 |

### Example Analysis
For `x = 52` (binary: `110100`):
- **Set bits**: 3 (positions 2, 4, 5)
- **Leading zeros**: 26 (32-bit: `00000000000000000000000000110100`)
- **Trailing zeros**: 2 (from right: `110100`)
- **First set bit**: Position 3 (1-based from right)
- **Parity**: 1 (3 set bits is odd)

## Common Patterns and Tricks

### Swap Two Numbers
```c
a ^= b;
b ^= a;
a ^= b;
```

### Check if Number is Even/Odd
```c
bool isEven(int n) { return (n & 1) == 0; }
bool isOdd(int n) { return (n & 1) == 1; }
```

### Get Absolute Value (for positive numbers)
```c
int abs(int n) {
    int mask = n >> 31;  // All 1s if negative, all 0s if positive
    return (n ^ mask) - mask;
}
```

### Isolate Rightmost Set Bit
```c
int rightmostSetBit(int n) {
    return n & (-n);
}
```
