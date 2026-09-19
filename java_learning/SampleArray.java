public class SampleArray{
    public static void main(String[] arags){
        double [] a = new double[5];

        for(int i=0;i<5;i++){
            a[i] = i*0.5;
            System.out.println("a[" + i + "]:" + a[i]);
        }
        double sum=0;

        for(int i=0;i<5;i++){
            if(i%2==1){
                sum += a[i];
            }else{
                sum -= a[i];
            }
        }
        System.out.println("sum:" + sum);
    }
}