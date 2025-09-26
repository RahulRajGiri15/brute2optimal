public class Solution {
    public void ReverseString(char[] s) {
        //Array.Reverse(s);

        //////////////////////////////

        int n = s.Length;
        char[] arr = new char[n];
        int j=0;
        for(int i=n-1;i>=0;i--){
            arr[j] = s[i];
            j++;
        }
        for(int i=0;i<n;i++){
            s[i] = arr[i];
        }

    }
}