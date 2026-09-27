public class SampleClass1 {
    public static void main(String[] args){
        ISStudents is2 = new ISStudents();

        is2.grade = 2;
        is2.numOfStudents = 95;

        System.out.println("学年:" + "\t" + is2.grade);
        System.out.println("学生数:" + "\t" + is2.numOfStudents);
    }
}

class ISStudents{
    int grade;
    int numOfStudents;
}