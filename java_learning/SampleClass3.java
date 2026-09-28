public class SampleClass3{
    public static void main(String[] args){
        ISStudents is2 = new ISStudents(95,2);

        System.out.println("学年" + "\t" + is2.getGrade());
        System.out.println("学年数" + "\t" + is2.getNumOfStudents());
    }
}

class ISStudents{
    private int grade;
    private int numOfStudents;

    ISStudents(){

    }

    ISStudents(int num,int grade){
        this.numOfStudents = num;
        this.grade = grade;
    }

    public void setGrade(int grade){
        this.grade = grade;
    }

    public void setNumOfStudents(int num){
        this.numOfStudents = num;
    }

    public int getGrade(){
        return this.grade;
    }

    public int getNumOfStudents(){
        return this.numOfStudents;
    }
}