using System.Linq;
namespace codewars.Kata
{
    public class FindTheOddInt
    {
        public static int find_it(int[] seq)
        {
            for (int i = 0; i < seq.Length; i++)
            {
                int count = 0;
                for (int j = 0; j < seq.Length; j++)
                {
                    if(seq[i]== seq[j]){
                        count++;
                    }
                }
                if((count % 2)==1){
                    return seq[i];
                }
            }
            return -1;
        }

        public static int find_it_v2(int[] seq)
        {
            return seq.First(x=> (seq.Count(c=> c==x) %2) == 1);
        } 
        
    }
}