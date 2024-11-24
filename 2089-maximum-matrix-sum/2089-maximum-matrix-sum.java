class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int minPositive=Integer.MAX_VALUE,maxNegative=Integer.MIN_VALUE,negatives=0;
        long sum=0;
        for(int i=0; i<matrix.length;i++){
            for(int j=0; j<matrix[0].length;j++){
                if(matrix[i][j]<0){
                    negatives+=1;
                    sum-=(matrix[i][j]);
                    maxNegative=Math.max(maxNegative, matrix[i][j]);

                }else{
                    sum+=matrix[i][j];
                    minPositive=Math.min(minPositive,matrix[i][j]);
                }
            }
        }
        if((negatives&1)==0) return sum;
        return sum-2*Math.min(-maxNegative, minPositive);
    }
}