//13 . Gold Mine Problem
import java.io.*;
import java.util.*;

public class Main {

   private static class Pair {
      String psf;
      int i;
      int j;

      public Pair(String psf, int i, int j) {
         this.psf = psf;
         this.i = i;
         this.j = j;
      }
   }
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      int m = Integer.parseInt(br.readLine());
      int[][] arr = new int[n][m];

      for (int i = 0; i < n; i++) {
         String str = br.readLine();
         for (int j = 0; j < m; j++) {
            arr[i][j] = Integer.parseInt(str.split(" ")[j]);
         }
      }

      int[][] dp = new int[arr.length][arr[0].length];
      
      for(int j = arr[0].length - 1; j >= 0; j--){
          for(int i = 0; i < arr.length; i++){
              if(j == arr[0].length - 1){
                  dp[i][j] = arr[i][j];
              } else if(i == 0){
                  dp[i][j] = arr[i][j] + Math.max(dp[i][j + 1], dp[i + 1][j + 1]);
              } else if(i == arr.length - 1){
                  dp[i][j] = arr[i][j] + Math.max(dp[i][j + 1], dp[i - 1][j + 1]);
              } else {
                  dp[i][j] = arr[i][j] + Math.max(dp[i][j + 1], Math.max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
              }
          }
      }
      
      int max = Integer.MIN_VALUE;
      for(int i = 0; i < dp.length; i++){
          if(dp[i][0] > max){
              max = dp[i][0];
          }
      }
      
      System.out.println(max);
      
      ArrayDeque<Pair> que = new ArrayDeque<>();
      
      for(int i = 0; i < dp.length; i++){
          if(dp[i][0] == max){
              que.add(new Pair(i + " ", i, 0));
          }
      }
      
      while(que.size() > 0){
          Pair rem = que.removeFirst();
          
          if(rem.j == arr[0].length - 1){
              System.out.println(rem.psf);
          } else if(rem.i == 0){
              int g = Math.max(dp[rem.i][rem.j + 1], dp[rem.i + 1][rem.j + 1]);
              
              
              if(g == dp[rem.i][rem.j + 1]){
                  que.add(new Pair(rem.psf + "d2 ", rem.i, rem.j + 1));
              }
              
              if(g == dp[rem.i + 1][rem.j + 1]){
                  que.add(new Pair(rem.psf + "d3 ", rem.i + 1, rem.j + 1));
              }
          } else if(rem.i == arr.length - 1){
              int g = Math.max(dp[rem.i][rem.j + 1], dp[rem.i - 1][rem.j + 1]);
              
              
              if(g == dp[rem.i - 1][rem.j + 1]){
                  que.add(new Pair(rem.psf + "d1 ", rem.i - 1, rem.j + 1));
              }
              
              if(g == dp[rem.i][rem.j + 1]){
                  que.add(new Pair(rem.psf + "d2 ", rem.i, rem.j + 1));
              }
          } else {
              int g = Math.max(dp[rem.i][rem.j + 1], Math.max(dp[rem.i - 1][rem.j + 1], dp[rem.i + 1][rem.j + 1]));
              
              if(g == dp[rem.i - 1][rem.j + 1]){
                  que.add(new Pair(rem.psf + "d1 ", rem.i - 1, rem.j + 1));
              }
              
              if(g == dp[rem.i][rem.j + 1]){
                  que.add(new Pair(rem.psf + "d2 ", rem.i, rem.j + 1));
              }
              
              if(g == dp[rem.i + 1][rem.j + 1]){
                  que.add(new Pair(rem.psf + "d3 ", rem.i + 1, rem.j + 1));
              }
          }
          
          
      }
   }


}
/******************************************************************************************************/
// 14 . Print Subsets with target sum
import java.io.*;
import java.util.*;

public class Main {

    public static class Pair{
        int i;
        int j;
        String psf;

        public Pair(int i, int j, String psf){
            this.i = i;
            this.j = j;
            this.psf = psf;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int tar = Integer.parseInt(br.readLine());

        boolean[][] dp = new boolean[arr.length + 1][tar + 1];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else if (j == 0) {
                    dp[i][j] = true;
                } else {
                    if(dp[i - 1][j] == true){
                        dp[i][j] = true;
                    } else {
                        int val = arr[i - 1];
                        if (j >= val && dp[i - 1][j - val] == true) {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }

        System.out.println(dp[dp.length - 1][tar]);
        Queue<Pair> q = new ArrayDeque<>();
        q.add(new Pair(n,tar,""));
      

        while (q.size() > 0) {
			Pair rp = q.remove();
			if (rp.i == 0 || rp.j == 0) {
				System.out.println(rp.psf);
			} else {
				boolean exc = dp[rp.i - 1][rp.j];
				boolean inc = rp.j - arr[rp.i - 1] >= 0 ? dp[rp.i - 1][rp.j - arr[rp.i - 1]] : false;
				
				if (inc == true) {
					q.add(new Pair(rp.i - 1, rp.j - arr[rp.i - 1], (rp.i - 1) + " " + rp.psf));
				}
				if (exc == true) {
					q.add(new Pair(rp.i - 1, rp.j, rp.psf));
				}
			}
		}
    }
}

//16 . Longest Palisdromic Subsequence
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        
        int[][] dp = new int[str.length()][str.length()];
        for(int g = 0; g < dp.length; g++){
            for(int i = 0, j = g; j < dp[0].length; i++, j++){
                if(g == 0){
                    dp[i][j] = 1;
                } else if(g == 1){
                    dp[i][j] = str.charAt(i) == str.charAt(j)? 2: 1;
                } else {
                    if(str.charAt(i) == str.charAt(j)){
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    } else {
                        dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }

        System.out.println(dp[0][dp[0].length - 1]);
    }
}
/**************************************************************************************************/
// 18. WildCard pattern matching 
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s1 = scn.next();
		String s2 = scn.next();
		System.out.println(solution(s1,s2));
	}

	public static boolean solution(String str, String pattern) {
		boolean[][] dp = new boolean[pattern.length() + 1][str.length() + 1];
		for(int i = dp.length - 1; i >= 0 ;i--) {
			for(int j = dp[0].length - 1; j >= 0; j--) {
				if(i == dp.length - 1 && j == dp[0].length - 1) {
					dp[i][j] = true;
				}else if(i == dp.length - 1) {
					dp[i][j] = false;
				}else if(j == dp[0].length - 1) {
					if(pattern.charAt(i) == '*') {
						dp[i][j] = dp[i + 1][j];
					}
				}else {
					if(pattern.charAt(i) == '?') {
						dp[i][j] = dp[i + 1][j + 1];
					}else if(pattern.charAt(i) == '*') {
						dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
					}else if(pattern.charAt(i) == str.charAt(j)) {
						dp[i][j] = dp[i + 1][j + 1];
					}else {
						dp[i][j] = false;
					}
				}
			}
		}
		
		return (dp[0][0]);
	}

}
/******************************************************************************************/
// 19. Regular Expression Matching
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s1 = scn.next();
		String s2 = scn.next();
		System.out.println(solution(s1,s2));
	}

	public static boolean solution(String s, String p) {
		boolean[][] dp = new boolean[p.length() + 1][s.length() + 1];
        dp[0][0] = true;
        for(int i = 1 ; i < dp.length; i++){
            for(int j = 0 ; j < dp[0].length; j++){
                if(j == 0 ){
                    if(p.charAt(i - 1) == '*')
                        dp[i][j] = dp[i - 2][j];
                }else{
                    if(p.charAt(i - 1) == '.' || p.charAt(i - 1) == s.charAt(j - 1)){
                        dp[i][j] = dp[i - 1][j - 1];
                    }else if(p.charAt(i - 1) == '*'){
                        dp[i][j] = dp[i - 2][j];
                        if(p.charAt(i - 2) == s.charAt(j - 1) || p.charAt(i - 2) == '.')
                            dp[i][j] = dp[i][j - 1] || dp[i - 2][j];
                    }
                }
                
            }
        }
        return dp[dp.length - 1][dp[0].length - 1];
	}
// More Simplified and elaborate form of the above code
    public static boolean solution(String s, String p) {
		boolean[][] dp = new boolean[p.length() + 1][s.length() + 1];
        for(int i = 0 ; i < dp.length; i++){
            for(int j = 0 ; j < dp[0].length; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = false;
                else if(j == 0){
                    if(p.charAt(i - 1) == '*')
                        dp[i][j] = dp[i - 2][j];
                    else 
                        dp[i][j] = false;
                }
                else{
                    if(p.charAt(i - 1) == '.' || p.charAt(i - 1) == s.charAt(j - 1)){
                        dp[i][j] = dp[i - 1][j - 1];
                    }else if(p.charAt(i - 1) == '*'){
                        dp[i][j] = dp[i - 2][j];
                        if(p.charAt(i - 2) == s.charAt(j - 1) || p.charAt(i - 2) == '.')
                            dp[i][j] = dp[i][j - 1] || dp[i - 2][j];
                    }
                }
                
            }
        }
        return dp[dp.length - 1][dp[0].length - 1];
	}

}
/**************************************************************************************************/
// 21. Catalan Numbers
import java.io.*;
import java.util.*;

public class Main {

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      long[] dp = new long[n + 1];
      dp[0] = 1;

      for(int i = 1; i < dp.length; i++){
         for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - 1 - j];
         }
      }

      System.out.println(dp[n]);
   }

}
/****************************************************************************************************/
// 22. Unique Binary Search Trees
class Solution {
    public:
        int numTrees(int n) {
            if(n == 1)
                return 1;
            int dp[n + 1];
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            dp[1] = 1;
            dp[2] = 2;
            for(int i = 3; i<=n; i++){
                 for(int j = 0; j < i; j++){
                    dp[i] += dp[j] * dp[i - 1 - j];
                 }
            }
            return dp[n];
        }
};
/***************************************************************************************************/
// 23. Counting Valleys & Mountains
import java.io.*;
import java.util.*;

public class Main {
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      long[] dp = new long[n + 1];
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i < dp.length; i++){
         int inside = i - 1;
         int outside = 0;
         while(inside >= 0){
             dp[i] += dp[inside] * dp[outside];
             inside--;
             outside++;
         }
      }
      System.out.println(dp[n]);
   }
}
/*************************************************************************************************/
// Count balanced parenthesis
import java.io.*;
import java.util.*;

public class Main {
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parseInt(br.readLine());
      long[] dp = new long[n + 1];
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i < dp.length; i++){
         int inside = i - 1;
         int outside = 0;
         while(inside >= 0){
             dp[i] += dp[inside] * dp[outside];
             inside--;
             outside++;
         }
      }
      System.out.println(dp[n]);
   }
}
/***********************************************************************************************/ 
// 25. Non-Intersecting Chords
import java.io.*;
import java.util.*;

public class Main {

    public static long NumberOfChords(int n){
        long[] dp = new long[2*n + 1];
        dp[0] = dp[2] = 1;
        for(int i = 4 ; i < dp.length; i += 2){
            for(int j = 0 ; j < i - 1; j += 2){
                dp[i] += dp[j] * dp[i - 2 - j];
            }
        }
        return dp[dp.length - 1];
    }
  public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        System.out.println(NumberOfChords(n));
	}
}
// Another way is to just find out the catalan of n/2 where n is the number of chords 
/***********************************************************************************************/
// 28. Cutting rod for maximum profit
public class Main {

    public static int solution(int[] prices){
        int[] dp = new int[prices.length + 1];
        for(int i = 1; i < dp.length; i++){
            int max = Integer.MIN_VALUE;
            for(int j = 0; j < i; j++){
                max = Math.max(max, dp[i - j - 1] + prices[j]);
            }
            dp[i] = max;
        }
        return dp[dp.length - 1];
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] prices = new int[n];
        for(int i = 0 ; i < n ; i++){
            prices[i] = scn.nextInt();
        }
        System.out.println(solution(prices));
    }

}
/*******************************************************************************************/
// 29. Palindromic Partitioning
import java.io.*;
import java.util.*;

public class Main {

	public static int minPalindromicCut(String s) {
		int n = s.length();
		boolean[][] dp = new boolean[s.length()][s.length()];
		for (int gap = 0; gap < s.length(); gap++) {
			int si = 0, ei = gap;
			while (ei < s.length()) {
				if (gap == 0) {
					dp[si][ei] = true;
				} else if (gap == 1) {
					dp[si][ei] = s.charAt(si) == s.charAt(ei);
				} else {
					if (s.charAt(si) == s.charAt(ei)) {
						dp[si][ei] = dp[si + 1][ei - 1];
					} else {
						dp[si][ei] = false;
					}
				}
				si++;
				ei++;
			}
		}

		int[] cuts = new int[n];
		for (int i = 0; i < n; i++) {
			if (dp[0][i] == true) {
				cuts[i] = 0;
			} else {
				cuts[i] = Integer.MAX_VALUE;
				for (int j = 0; j < i; j++) {
					if(dp[j + 1][i] == true && 1 + cuts[j] < cuts[i]){
						cuts[i] = 1 + cuts[j];
					}
				}
			}
		}
		return cuts[n - 1];
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.nextLine();
		System.out.println(minPalindromicCut(str));
	}
}
/*****************************************************************************************/ 
// 30. Matrix Chain Multiplication
public class Main{
    public static int mcm(int[] arr){
        int[][] dp = new int[arr.length - 1][arr.length - 1];
        for(int g = 0; g < dp.length; g++){
            for(int i = 0, j = g; j<dp.length; i++, j++){
                if(g == 0)
                    dp[i][j] = 0;
                else if(gap == 1)
                    dp[i][j] = arr[i] * arr[j] * arr[j + 1];
                else{
                    int minm  = Integer.MAX_VALUE;
                    for(int k = i; k < j; k++){
                        int lc = dp[i][k];
                        int rc = dp[k + 1][j];
                        int mc = arr[i] * arr[k + 1] * arr[j + 1];
                        int tc = lc + rc + mc;
                        if(tc < minm)
                            minm = tc;
                    }
                    dp[i][j] = minm
                }
            }
        }
        return dp[0][dp.length - 1];
    }
}
                        
                        


                        

                        


                        

                        


                        
                        


                        


                        


                        