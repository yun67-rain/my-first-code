import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import javafx.scene.paint.Color;
import javafx.scene.shape.ArcType;

public class CircleGraph extends Application {

    @Override
    public void start(Stage st) throws Exception {
        List<Double> dataList = readData("data.txt");

        Group root = new Group();
        Canvas canvas = new Canvas(400, 400);
        GraphicsContext gc = canvas.getGraphicsContext2D(); 

        drawCircleGraph(gc, dataList, 400, 400);

        root.getChildren().add(canvas);
        Scene scene = new Scene(root, 400, 400, Color.WHITE);

        st.setTitle("Line Graph");
        st.setScene(scene);
        st.show();
    }

    private List<Double> readData(String filename) {
        List<Double> list = new ArrayList<>();

        try {
            File file = new File("./" + filename);
            FileReader fr = new FileReader(file);
            BufferedReader br = new BufferedReader(fr);

            String str = br.readLine(); 
            while (str != null) {
                str = str.trim(); 
                if (!str.isEmpty()) {
                    list.add(Double.parseDouble(str));
                }
                str = br.readLine(); 
            }

            br.close(); 
        } catch (FileNotFoundException e) {
            System.err.println("ファイルが開けませんでした．");
        } catch (IOException e) {
            System.err.println("ファイルの読み込みに失敗しました．");
        }

        return list;
    }

    private void drawCircleGraph(GraphicsContext gc, List<Double> data, double width, double height) {
        if (data == null || data.isEmpty()) return;

        int numOfData = data.size();

        Color[] color = new Color[numOfData];
        Random rnd = new Random(); 
        for (int i = 0; i < numOfData; i++){
            color[i] = Color.rgb(rnd.nextInt(256), rnd.nextInt(256), rnd.nextInt(256));
        }

        double centerx = 160;
        double centery = 220;
        double radius = 100;
        double diameter = radius * 2;
        double startAngle = 90;

        double total = 0;
        for (double val : data){
            total += val;
        }

        for(int i=0;i < numOfData;i++){
            double val = data.get(i);
            double angle = - (val / total) * 360.0;

            gc.setFill(color[i]);
            gc.fillArc(centerx - radius,centery - radius,diameter,diameter,startAngle,angle,ArcType.ROUND);

            double halfAngle = startAngle + angle /2.0;
            double rad = Math.toRadians(halfAngle);
            double textRadius = radius + 20;
            double textx = centerx + textRadius * Math.cos(rad);
            double texty = centery - textRadius * Math.sin(rad);

            gc.setFill(Color.BLACK);
            String text = String.format("%.0f", val);
            double textOffsetx = text.length() * 3.5;
            gc.fillText(text, textx - textOffsetx, texty + 5);

            startAngle += angle;
        }

        gc.setFill(Color.BLACK);
        gc.setLineWidth(1.0);
        gc.strokeOval(centerx - radius,centery - radius, diameter, diameter);

        double legendx = 290;
        double legendy = 120;
        double legendBoxWidth = 50;
        double itemHeight = 16;
        double legendHeight = numOfData * itemHeight + 10;

        gc.setFill(Color.LIGHTGRAY);
        gc.fillRect(legendx,legendy,legendBoxWidth,legendHeight);
        gc.setStroke(Color.BLACK);
        gc.strokeRect(legendx,legendy,legendBoxWidth,legendHeight);

        for(int i=0;i < numOfData;i++){
            double itemy = legendy + 8 + i * itemHeight;

            gc.setFill(color[i]);
            gc.fillRect(legendx + 8, itemy,10,10);
            gc.setStroke(Color.BLACK);
            gc.strokeRect(legendx + 8,itemy,10,10);

            gc.setFill(Color.BLACK);
            gc.fillText(String.valueOf(i+1), legendx + 24, itemy +9);
        }

    }

    public static void main(String[] args) {
        launch(args);
    }
}
