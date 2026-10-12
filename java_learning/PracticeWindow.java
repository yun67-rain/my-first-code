import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.Group;
import javafx.scene.canvas.Canvas;
import javafx.scene.paint.Color;

import javafx.scene.canvas.GraphicsContext;


public class PracticeWindow extends Application {
  @Override
  public void start(Stage st) throws Exception {
    Group root = new Group();
    Canvas canvas = new Canvas(300, 250); // 一つの描画領域を設定
    canvas.setTranslateX(50); // 描画領域の左上のx座標（デフォルトは0）
    canvas.setTranslateY(75); // 描画領域の左上のy座標（デフォルトは0）
    GraphicsContext gc = canvas.getGraphicsContext2D(); // 一つのcanvasで描画を管理するインスタンスの生成
    drawShapes(gc); // gcを引数として下で定義したdrawShapesを呼んで，描画内容を定める
    
    root.getChildren().add(canvas); // rootにcanvasを登録する

    Scene scene = new Scene(root, 400, 400, Color.BLACK);
    st.setTitle("Hello world");
    st.setScene(scene);
    st.show();
  }
  
  public static void main(String[] a) {
    launch(a);
  }

  private void drawShapes(GraphicsContext gc) {
    gc.setFill(Color.WHITE); // 色の指定

    int [] xposition = {40,60,80,100,120,100,80,60,40};
    int starty = 30;
    int stepy = 20;
    for(int i=0;i<9;i++){
        gc.fillText("Hello World!",xposition[i] , starty + i * stepy); // 描画するテキストとその座標（テキストの左下の位置）を指定
    }
}
}