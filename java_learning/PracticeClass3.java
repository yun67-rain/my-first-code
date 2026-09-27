public class PracticeClass3 {
    public static void main(String[] args){
        Student st = new Student("坊ちゃん",1234567);

        System.out.println("氏名:" + "\t" + st.name);
        System.out.println("学籍番号:" + "\t" + st.id);
    }
}

class Student{
    String name;
    int id;

    Student(){

    }

    Student(String name,int id){
        this.name = name;
        this.id = id;
    }
}