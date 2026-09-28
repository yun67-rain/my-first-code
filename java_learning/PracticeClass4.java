public class PracticeClass4{
    public static void main(String[] args){
        Student st = new Student("坊ちゃん",1234567);

        System.out.println("氏名:" + "\t\t" + st.getName());
        System.out.println("学籍番号:" + "\t" + st.getId());
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