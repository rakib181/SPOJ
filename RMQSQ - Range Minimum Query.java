import java.util.*;
 class RMQSQ {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=(int)Math.sqrt(n)+1,INF=Integer.MAX_VALUE;;
        int[] arr=new int[n];
        int[] b=new int[m];
        Arrays.fill(b,INF);
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
            b[i/m]=Math.min(b[i/m],arr[i]);
        }
        int q=sc.nextInt();
        while (q-->0) {
            int l = sc.nextInt(), r = sc.nextInt(), ans = INF;
            for (int i = l; i <= r; ) {
                if (i % m == 0 && i + m - 1 <= r) {
                    ans = Math.min(ans, b[i / m]);
                    i += m;
                } else {
                    ans = Math.min(ans, arr[i]);
                    i++;
                }
            }
            System.out.println(ans);
        }
    }
}
