public class Pi{
    public static void main(String[] args){
        double m=1.0;
        int l=3;
        for(int i=0;i<1000;i++){
            if(i%2==0){
                m -= 1.0/l;
            }else{
                m += 1.0/l;
            }
            l += 2;
        }
        double n=4.0*m;
        System.out.println("π=" + n);
    }
}