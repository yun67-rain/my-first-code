import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.Group;
import javafx.scene.paint.Color;

public class SampleWindow1 extends Application{
    @Override
    public void start(Stage st) throws Exception{
        Group root = new Group();

        Scene scene = new Scene(root,400,400,Color.BLACK);
        st.setTitle("Hello world");
        st.setScene(scene);
        st.show();
    }

    public static void main(String[] args){
        launch(args);
    }
}