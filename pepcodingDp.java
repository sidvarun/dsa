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
      int n = Integer.parsjnt(br.readLine());
      int m = Integer.parsjnt(br.readLine());
      int[][] arr = new int[n][m];

      for (int i = 0; i < n; i++) {
         String str = br.readLine();
         for (int j = 0; j < m; j++) {
            arr[i][j] = Integer.parsjnt(str.split(" ")[j]);
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
      
      while(que.ize() > 0){
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
        int n = Integer.parsjnt(br.readLine());
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parsjnt(br.readLine());
        }

        int tar = Integer.parsjnt(br.readLine());

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
      

        while (q.ize() > 0) {
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
// 19. Regular Expresion Matching
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
// More implified and elaborate form of the above code
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
      int n = Integer.parsjnt(br.readLine());
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
            memset(dp, 0, izeof(dp));
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
      int n = Integer.parsjnt(br.readLine());
      long[] dp = new long[n + 1];
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i < dp.length; i++){
         int inide = i - 1;
         int outide = 0;
         while(inide >= 0){
             dp[i] += dp[inide] * dp[outide];
             inide--;
             outide++;
         }
      }
      System.out.println(dp[n]);
   }
}
/*************************************************************************************************/
// Count balanced parenthjs
import java.io.*;
import java.util.*;

public class Main {
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int n = Integer.parsjnt(br.readLine());
      long[] dp = new long[n + 1];
      dp[0] = 1;
      dp[1] = 1;
      for(int i = 2; i < dp.length; i++){
         int inide = i - 1;
         int outide = 0;
         while(inide >= 0){
             dp[i] += dp[inide] * dp[outide];
             inide--;
             outide++;
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
			int i = 0, j = gap;
			while (j < s.length()) {
				if (gap == 0) {
					dp[i][j] = true;
				} else if (gap == 1) {
					dp[i][j] = s.charAt(i) == s.charAt(j);
				} else {
					if (s.charAt(i) == s.charAt(j)) {
						dp[i][j] = dp[i + 1][j - 1];
					} else {
						dp[i][j] = false;
					}
				}
				i++;
				j++;
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
/*****************************************************************************************************************************************/
// 31. boolean parenthjsation
import java.io.*;
import java.util.*;

public class Main {

	public static int solution(String str1, String str2) {
		int n = str1.length();
		int[][] t = new int[n][n];
		int[][] f = new int[n][n];
		for (int gap = 0; gap < n; gap++) {
			for(int i = 0, j = g; j<n; i++, j++){
                if (gap == 0) {
					t[i][j] = str1.charAt(i) == 'T' ? 1 : 0;
					f[i][j] = str1.charAt(i) == 'F' ? 1 : 0;
				} else {
					for (int k = i; k < j; k++) {
						char sign = str2.charAt(k);
						if (sign == '&') {
							t[i][j] += t[i][k] * t[k + 1][j];
							f[i][j] += ((t[i][k] * f[k + 1][j]) + (f[i][k] * t[k + 1][j])
									+ (f[i][k] * f[k + 1][j]));
						}
						if (sign == '|') {
							t[i][j] += ((t[i][k] * t[k + 1][j]) + (t[i][k] * f[k + 1][j])
									+ (f[i][k] * t[k + 1][j]));
							f[i][j] += ((f[i][k]) * (f[k + 1][j]));
						}
						if (sign == '^') {
							t[i][j] += ((t[i][k] * f[k + 1][j]) + (f[i][k] * t[k + 1][j]));
							f[i][j] += ((t[i][k] * t[k + 1][j]) + (f[i][k] * f[k + 1][j]));
						}
					}
				}
            }
		}
		return (t[0][t[0].length - 1]);
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s1 = scn.next();
		String s2 = scn.next();
		System.out.println(solution(s1, s2));
	}

}
/********************************************************************************************************************/
// 33. perfect Squares
class Solution {
    public:
        int numSquares(int n) {
            if (n <= 0)
            {
                return 0;
            }

            // cntPerfectSquares[i] = the least number of perfect square numbers 
            // which sum to i. Note that cntPerfectSquares[0] is 0.
            vector<int> cntPerfectSquares(n + 1, INT_MAX);
            cntPerfectSquares[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                // For each i, it must be the sum of some number (i - j*j) and 
                // a perfect square number (j*j).
                for (int j = 1; j*j <= i; j++)
                {
                    cntPerfectSquares[i] = 
                        min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
                }
            }

            return cntPerfectSquares.back();
        }
};
/**********************************************************************************************************************/
// 35. Kadane's algorithm
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        System.out.println(solution(arr));
    }

    public static int solution(int[] arr) {
        int finalans = arr[0];
        int curr = arr[0];
        for(int i = 1 ; i < arr.length; i++){
            curr = Math.max(arr[i], arr[i] + curr);
            finalans = Math.max(finalans, curr);
        }
        return finalans; 
    }
}

/************************************************************************************************************************/
// 35. Numeric Keypad
import java.io.*;
import java.util.*;

public class Main {

	public static int solution(int n) {
		ArrayList<Integer>[] nextkeys = new ArrayList[10];
		for(int i = 0; i < 10; i++){
		    nextkeys[i] = new ArrayList<>();
		}
		
		nextkeys[0].add(0);
		nextkeys[0].add(8);
		nextkeys[1].add(1);
		nextkeys[1].add(2);
		nextkeys[1].add(4);
		nextkeys[2].add(1);
		nextkeys[2].add(2);
		nextkeys[2].add(3);
		nextkeys[2].add(5);
		nextkeys[3].add(2);
		nextkeys[3].add(3);
		nextkeys[3].add(6);
		nextkeys[4].add(1);
		nextkeys[4].add(4);
		nextkeys[4].add(5);
		nextkeys[4].add(7);
		nextkeys[5].add(2);
		nextkeys[5].add(4);
		nextkeys[5].add(5);
		nextkeys[5].add(6);
		nextkeys[5].add(8);
		nextkeys[6].add(3);
		nextkeys[6].add(5);
		nextkeys[6].add(6);
		nextkeys[6].add(9);
		nextkeys[7].add(4);
		nextkeys[7].add(7);
		nextkeys[7].add(8);
		nextkeys[8].add(0);
		nextkeys[8].add(5);
		nextkeys[8].add(7);
		nextkeys[8].add(8);
		nextkeys[8].add(9);
		nextkeys[9].add(6);
		nextkeys[9].add(8);
		nextkeys[9].add(9);
		
		int[][] dp = new int[n + 1][10];
		for(int i = 0 ; i < 10; i++){
		    dp[1][i] = 1;
		}
		
		for(int i = 2; i <= n; i++){
		    for(int j = 0; j < 10; j++){
		        for(int key = 0 ; key < nextkeys[j].size();key++){
		            dp[i][j] += dp[i - 1][nextkeys[j].get(key)]; 
		        }
		    }
		}
		
		int ans = 0;
		for(int j = 0 ; j < 10; j++){
		    ans += dp[n][j];
		}
		return ans;
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println(solution(scn.nextInt()));
	}

}
/******************************************************************************************************/
// 36. Longest Common Substring
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s1 = scn.next();
		String s2 = scn.next();
		System.out.println(solution(s1,s2));
	}

	public static int solution(String s1, String s2){
		int[][] dp = new int[s1.length() + 1][s2.length() + 1];
		int ans = 0 ;
		for(int i = 1 ; i <= s1.length(); i++) {
			for(int j = 1 ; j <= s2.length() ;j++) {
				if(s1.charAt(i - 1) == s2.charAt(j - 1)) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				ans = Math.max(ans, dp[i][j]);
			}
		}
		return ans;
	}

}
/************************************************************************************************************/

                        


                        

                        


                        

                        


                        
                        


                        


                        


                        