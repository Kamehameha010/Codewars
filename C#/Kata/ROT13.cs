using System;
using System.Linq;

namespace codewars.Kata
{
    public class ROT13
    {
        /*
        How can you tell an extrovert from an introvert at NSA? Va gur ryringbef, gur rkgebireg ybbxf ng gur BGURE thl'f fubrf.
        I found this joke on USENET, but the punchline is scrambled. Maybe you can decipher it? According to Wikipedia, ROT13 (http://en.wikipedia.org/wiki/ROT13) is frequently used to obfuscate jokes on USENET.
        Hint: For this task you're only supposed to substitue characters. Not spaces, punctuation, numbers etc. Test examples: 
        */

        public static string Rot13(string input)
        {
            Func<char, string> rot13 = Cipher;
            return input.ToCharArray().Select(rot13).Aggregate((acc, curr) => acc+curr);
        }

        private static string Cipher(char chr)
        {
            int nChar = (int)chr;
            if (nChar >= 65 && nChar <= 90)
                return ((char)(((nChar - 65 + 13) % 26) + 65)).ToString();
            if (nChar >= 97 && nChar <= 122)
                return ((char)(((nChar - 97 + 13) % 26) + 97)).ToString();

            return chr.ToString();
        }
    }
}