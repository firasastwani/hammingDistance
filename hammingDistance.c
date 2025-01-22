#include <stdio.h> 
#include <stdlib.h> // atoi, atof, atol
#include <string.h>



// Converts a decimal number to a binary string
void numToBinaryString(int num, char *binaryStr) {
    int index = 0;
    while (num > 0) {
        binaryStr[index++] = (num % 2) + '0';
        num /= 2;
    }
    binaryStr[index] = '\0';
    // Reverse the string to get the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[index - i - 1];
        binaryStr[index - i - 1] = temp;
    }
}

// Pads the shorter binary string with leading zeros
void padBinaryStrings(char *binaryStr1, char *binaryStr2) {
    int len1 = strlen(binaryStr1);
    int len2 = strlen(binaryStr2);
    int maxLen = len1 > len2 ? len1 : len2;

    char paddedStr1[33] = {0};
    char paddedStr2[33] = {0};

    // Pad binaryStr1
    for (int i = 0; i < maxLen - len1; i++) {
        paddedStr1[i] = '0';
    }
    strcpy(paddedStr1 + (maxLen - len1), binaryStr1);

    // Pad binaryStr2
    for (int i = 0; i < maxLen - len2; i++) {
        paddedStr2[i] = '0';
    }
    strcpy(paddedStr2 + (maxLen - len2), binaryStr2);

    // Copy back to original strings
    strcpy(binaryStr1, paddedStr1);
    strcpy(binaryStr2, paddedStr2);
}


int hammingDistance(char *binaryStr1, char *binaryStr2) {

    int distance = 0; 

    for(int i = 0; i < strlen(binaryStr1); i++) {
        if(binaryStr1[i] != binaryStr2[i]) {
            distance++; 
        }
    }

    return distance;     

}



int main(int argc, char * argv[]) {


    if(argc != 3){
        printf("Only takes two arguments"); 

        return 0; 
    }

    int num1 = atoi(argv[1]); 
    int num2 = atoi(argv[2]); 

    char binaryStr1[33] = {0}; // 32 bits + 1 for null terminator
    char binaryStr2[33] = {0};

    numToBinaryString(num1, binaryStr1);
    numToBinaryString(num2, binaryStr2);

    padBinaryStrings(binaryStr1, binaryStr2);

    printf("Binary 1: %s\n", binaryStr1);
    printf("Binary 2: %s\n", binaryStr2);

    int hamming = hammingDistance(binaryStr1, binaryStr2);

    printf("Hamming Distance: %d\n", hamming);

    return 0; 
}