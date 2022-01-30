
public class Greed {
    /*
    Greed is a dice game played with five six-sided dice. Your mission, should you choose
     to accept it, is to score a throw according to these rules. You will always be given
     an array with five six-sided dice values.
    Three 1's => 1000 points
    Three 6's =>  600 points
    Three 5's =>  500 points
    Three 4's =>  400 points
    Three 3's =>  300 points
    Three 2's =>  200 points
    One   1   =>  100 points
    One   5   =>   50 point

    A single die can only be counted once in each roll. For example, a given "5" can only 
    count as part of a triplet (contributing to the 500 points) or as a single 50 points, 
    but not both in the same roll.
     */
    public static int greedy(int[] dice) {
        int[] counts = new int[7];
        for (int die : dice) {
          counts[die]++;
        }
        int total = 0;
        for (int i = 1; i < counts.length; i++) {
          switch (i) {
          case 1:
            if (counts[i] >= 3) {
              total += 1000;
              counts[i] -= 3;
            }
            if (counts[i] > 0 && counts[i] < 3) {
              total += (100 * counts[i]);
            }
            break;      
          case 5:
            if (counts[i] >= 3) {
              total += 500;
              counts[i]-=3;
            }
            if (counts[i] > 0 && counts[i] < 3) {
              total += 50 * counts[i];
            }
            break;
          default :
            total += counts[i] >= 3 ? multiply100(i) : 0;
          }   
        }
        return total;
      }
    
      public static int multiply100(int value) {
        return value * 100;
      }
}