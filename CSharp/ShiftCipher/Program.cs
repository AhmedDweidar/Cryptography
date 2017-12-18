using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShiftCipher
{
    class Program
    {
        static void Main(string[] args)
        {
            string plainText = "Performing shift cipher";
            int key = 5;
            string cipherText = Encrypt(plainText, key);

            Console.WriteLine("PlainText = {0}\nCipherText = {1}\nKey = {2}\n", plainText, cipherText, key);

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }

        static string Encrypt(string plainText, int key)
        {
            // holds the chars from the plaintext
            char[] charArray = plainText.ToCharArray();
            // holds the new chars after the shift was performed. Eventually becomes the cipherText
            char[] cipherText = new char[plainText.Length];

            for (int i = 0; i < charArray.Length; i++)
            {
                // convert all letter to lowercase
                char letter = char.ToLower(charArray[i]);

                // ignore spaces (spaces should be printed)
                if (letter == ' ')
                {
                    continue;
                }
                else
                {
                    // add the key shift to all letters
                    letter = (char)(letter + key);
                }

                if (letter > 'z')
                {
                    // subtract 26 on overflow (wraps around to 'a')
                    letter = (char)(letter - 26);
                }
                else if (letter < 'a')
                {
                    // add 26 on underflow (wraps around to 'z')
                    letter = (char)(letter + 26);
                }

                // new letter is appended to cipherText char array after shift
                cipherText[i] = letter;
            }

            return new string(cipherText);
        }
    }
}
