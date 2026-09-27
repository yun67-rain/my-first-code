public class SampleClass2 {
    public static void main(String[] args){
        ISStudents is2 = new ISStudents(95,2);
        
        System.out.println("学年:" + "\t" + is2.grade);
        System.out.println("学年数:" + "\t" + is2.numOfStudents);
    }
}

class ISStudents{
    int grade;
    int numOfStudents;

    ISStudents(){

    }

    ISStudents(int num,int grade){
        this.numOfStudents = num;
        this.grade = grade;
    }
}