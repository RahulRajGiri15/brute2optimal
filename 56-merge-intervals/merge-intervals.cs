public class Solution {
    public int[][] Merge(int[][] intervals) {
        List<int[]>res = new List<int[]>();
        Array.Sort(intervals,(a,b) =>a[0].CompareTo(b[0]));
        int u2 = intervals[0][0];
        int v2 = intervals[0][1];
        foreach(var arr in intervals){
            int u1 = arr[0];
            int v1 = arr[1];

            if(u1 <= v2){ /////overlapiing
                v2 = Math.Max(v2, v1);
            }
            else{ ////No overlapping 
                res.Add( new int[] {u2,v2});
                u2 = u1;
                v2 = v1;
            }
        }
        res.Add(new int[] {u2,v2});
        return res.ToArray();
    }
}