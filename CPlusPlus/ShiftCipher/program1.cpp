// Name: Ahmed Dweidar
// Class: CPSC 370 - Intro to Cryptography - Fall 2015
// Email: adweidar@live.esu.edu
// Assignment and purpose: Program 1 - Shift Cipher, encryption and decryption. 
// Date: September 13th, 2015

// header files

#include <iostream>
#include <string>
using namespace std;

// function prototypes

string shiftCipherDecrypt(string, int); // shift cipher function
string encryptAffine(string); // encrypt using affine function
string decryptAffine(string); // decrypt using affine function

int main()
{
	string plaintext;  // string to hold plaintext for affine encrypt and decrypt
	string ciphertext;  // string to hold ciphertext for affine encrypt and decrypt
	string cipherText; // string to hold ciphertext for shift cipher function
	int key = 25;  // key 25 to print out all possibilities using brute force method

	// decrypting ciphertext using shift cipher trying all possibilities (brute force)

	cout << "Enter the ciphertext you would like to decrypt (in uppercase): ";
	getline(cin, cipherText);
	cout << endl;

	shiftCipherDecrypt(cipherText, key);
	cout << endl;
	cout << "--------------------------------------------------------------------" << endl;

	// encrypting plaintext using affine function

	cout << "Enter the plaintext message you want to encrypt (in lowercase): ";
	cin >> plaintext;

	cout << endl;
	cout << "Encrypted message is: " << encryptAffine(plaintext) << endl << endl;
	cout << "--------------------------------------------------------------------" << endl << endl;

	// decrypting ciphertext using affine function

	cout << "Enter the ciphertext message you want to decrypt (in uppercase): ";
	cin >> ciphertext;

	cout << endl;
	cout << "Decrypted message is: " << decryptAffine(ciphertext) << endl << endl;
	cout << "--------------------------------------------------------------------" << endl << endl << endl;

	system("pause");
	return 0;
}

// function to use shift cipher to decrypt a phrase by trying all possibilities

string shiftCipherDecrypt(string cipherText, int key)
{
	string plainText = cipherText; // setting plaintext to equal ciphertext to return plaintext when function is called
	int length = cipherText.length(); // length is however long the word/phrase is

	for (int i = 1; i <= key; i++) // looping through all the possible keys from 1 to 26
	{
		for (int j = 0; j < length; j++) // looping through each letter of the word 
		{
			if (isalpha(cipherText[j])) // checks to see if it is a letter of the alphabet
			{
				cipherText[j] = tolower(cipherText[j]); // change it to lower case

				if (cipherText[j] == 'z') // if letter is z
				{
					cipherText[j] = 'a'; // wrap around to a
				}
				else
				{
					cipherText[j]++; // increment the letter
				}
			}
		}
		cout << "The decrypted word at key " << i << " is " << cipherText << endl;
	}

	return plainText;
}

// function to encrypt a word using the affine function 7x + 8

string encryptAffine(string plaintext)
{
	string ciphertext;  // string to hold ciphertext
	int alpha = 7;  // alpha value
	int beta = 8;  // beta value

	for (int i = 0; i < plaintext.length(); i++)  // loops through each letter of the plaintext and applies affine function
	{
		ciphertext = ciphertext + (char)((((alpha * (plaintext[i] - 'a')) + beta) % 26) + 65);
	}

	return ciphertext;
}

// function to decrypt a word using affine function 5x + 12

string decryptAffine(string ciphertext)
{
	string plaintext;  // string to hold plaintext
	int alpha = 21;  // alpha value (The inverse of 5 is 21)
	int beta = 8;  // beta value (new function is 21y + 8)

	for (int i = 0; i < ciphertext.length(); i++)  // loops through each letter of the ciphertext and applies affine function
	{
		plaintext = plaintext + (char)((((alpha * (ciphertext[i] - 'A')) + beta) % 26) + 97);
	}

	return plaintext;
}












