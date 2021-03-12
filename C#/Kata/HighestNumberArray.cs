using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Linq.Expressions;

namespace codewars.Kata
{
    public class HighestNumberArray
    {

        //<Summary>
        //Complete the method which returns the number which is most frequent in the given 
        //input array. If there is a tie for most frequent number, return the largest number among them.
        //</Sumamry>
        public static int HighestRank(int[] arr)
        {
            int count = int.MinValue, maxValue = 0;

            foreach (var item in arr.GroupBy(x => x))
            {
                if(count < item.Count() ){
                    count = item.Count();
                    maxValue = item.Key;
                }
                if(count == item.Count()){
                    maxValue = maxValue < item.Key ?item.Key : maxValue;
                }
            }

            return maxValue;
        }
    }
}
