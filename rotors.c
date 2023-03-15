#include <stdio.h>

int startPosition = 0;
char alphabets [25] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int ringPosition = 20;
int ringPositionForDecryption = 20;

int CalculateEncryptedNewIndex(int toEncrypt) {
for (int i=0; i<25; i++){
        if (alphabets[i] == toEncrypt) {
            int newIndex = i + ringPosition;
            ringPosition +=1;
            if (newIndex > 25) {
                newIndex = newIndex - 25;
                return newIndex;
            }
            return newIndex;
        }
    }
}

int CalculateDecryptedNewIndex(int toDecrypt) {
    for (int i=0; i<25; i++){
        if (alphabets[i] == toDecrypt) {
            int newIndex = ringPositionForDecryption - i;
            ringPositionForDecryption -=1;
            if (newIndex > 25) {
                newIndex = newIndex - 25;
                return newIndex;
            }
            return newIndex;
        }
    }
}
int main() {
   for (int i = 0; i<5; i++) {
    char encrypt = 0;
    printf("\n Enter a value\n");
    scanf("%c", &encrypt);
    int newIndex = CalculateEncryptedNewIndex(encrypt);
    printf("\n %c", alphabets[newIndex]);
   }
    return 0;
}