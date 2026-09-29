import javax.swing.text.Style;

public class PracticeClass5{
    public static void main(String[] args){
        ISStudents is2 = new ISStudents(95,2);

        is2.registerStudent(1234567,"坊ちゃん");
        is2.registerStudent(7654321,"マドンナちゃん");

        System.out.println("登録者数:" + is2.getNumOfRegisteredStudents());

        System.out.println("学籍番号 7654321 の学生は" + is2.getNameFromId(7654321));
        System.out.println("学籍番号 1234567 の学生は" + is2.getNameFromId(1234567));
        System.out.println("学籍番号 6316001 の学生は" + is2.getNameFromId(6316001));
    }
}

class ISStudents{
    private int grade;
    private int numOfStudents;
    private int numOfRegisteredStudents;

    private Student[] students;

    ISStudents(int num,int grade){
        this.numOfStudents = num;
        this.grade = grade;
        this.numOfRegisteredStudents = 0;

        this.students = new Student[num];
    }

    public void setGrade(int grade){
        this.grade = grade;
    }

    public void setNumOfStudents(int num){
        this.numOfStudents = num;
    }

    public int getNumOfStudents(){
        return this.numOfStudents;
    }

    public int getNumOfRegisteredStudents(){
        return this.numOfRegisteredStudents;
    }

    public void registerStudent(int id,String name){
        if(this.numOfRegisteredStudents < this.numOfStudents){
            this.students[this.numOfRegisteredStudents] = new Student(id,name);
            this.numOfRegisteredStudents++;
        }else{
            System.out.println("上限人数に達しています");
        }
    }

    public String getNameFromId(int id){
        for(int i=0;i<this.numOfRegisteredStudents;i++){
            if(this.students[i].getId() == id){
                return this.students[i].getName();
            }
        }
        return "No such student!!";
    }
}

class Student{
    private int id;
    private String name;

    public Student(int id,String name){
        this.id = id;
        this.name = name;
    }

    public int getId(){
        return this.id;
    }

    public String getName(){
        return this.name;
    }
}