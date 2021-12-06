#include <iostream>
using namespace std;

int main() {
    string str = "akdandksasaskasakbdksaasdf";
    int freq[26] = {0};
    for (int i = 0; i < 26; i++) {
        freq[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << freq[i] << " , ";
    }
    char ans = 'a';
    int maxOccurence = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxOccurence) {
            maxOccurence = freq[i];
            ans = i + 'a';
        }
    }

    cout << maxOccurence << " " << ans << " .";
}