public class SampleClass4{
    public static void main(String[] args){
        ISStudents is2 = new ISStudents(95,2);

        System.out.println("学年:" + "\t" + is2.getGrade());
        System.out.println("学年数" + "\t" + is2.getNameOfStudents());
    }
}

class ISStudents{
    private int grade;
    private int numOfStudents;

    private Student[] students;

    ISStudents(int num,int grade){
        this.numOfStudents = num;
        this.grade = grade;
        this.students = new Student[num];
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

class Student{
    private String name;
    private int id;

    Student(){

    }

    Student(String name,int id){
        this.name = name;
        this.id = id;
    }

    public void setName(String name){
        this.name = name;
    }

    public void setId(int id){
        this.id = id;
    }

    public String getName(){
        return this.name;
    }

    public int getId(){
        return this.id;
    }
}