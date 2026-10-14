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

public class LineGraph extends Application {

    @Override
    public void start(Stage st) throws Exception {
        List<Double> dataList = readData("data.txt");

        Group root = new Group();
        Canvas canvas = new Canvas(400, 400);
        GraphicsContext gc = canvas.getGraphicsContext2D(); 

        drawLineGraph(gc, dataList, 400, 400);

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

    private void drawLineGraph(GraphicsContext gc, List<Double> data, double width, double height) {
        if (data == null || data.isEmpty()) return;

        double padding = 50;
        double graphWidth = width - padding * 2;
        double graphHeight = height - padding * 2;
        double originX = padding;
        double originY = height - padding;

        double maxData = 0;
        for (double val : data) {
            if (val > maxData) maxData = val;
        }
        double maxY = Math.ceil(maxData / 50.0) * 50; 
        if (maxY == 0) maxY = 100;

        gc.setFill(Color.LIGHTGRAY);
        gc.fillRect(originX,padding,graphWidth,graphHeight);

        int yStepCount = 5;
        for (int i = 0; i <= yStepCount; i++) {
            double yVal = maxY * i / yStepCount;
            double yPos = originY - (yVal / maxY) * graphHeight;

            gc.setStroke(Color.GRAY);
            gc.setLineWidth(2.0);
            gc.strokeLine(originX, yPos, originX + graphWidth , yPos);

            gc.setFill(Color.BLACK);
            gc.fillText(String.format("%.0f", yVal), originX - 35, yPos + 4);
        }

        gc.setStroke(Color.BLACK);
        gc.setLineWidth(1.0);
        gc.strokeLine(originX , padding, originX + graphWidth , padding);
        gc.strokeLine(originX, originY, originX + graphWidth , originY);
        gc.strokeLine(originX, padding , originX, originY);

        int n = data.size();
        double stepX = graphWidth / n; 
        double[] xpoint = new double [n];
        double[] ypoint = new double [n];

        gc.setStroke(Color.BLACK);
        gc.setLineWidth(1.0);
        for(int i =0; i<= n ;i++){
            double gridX = originX + i * stepX;
            gc.strokeLine(gridX , originY , gridX , originY + 4);
        }

        for (int i = 0; i < n; i++) {
            xpoint[i] = originX +  i *stepX + stepX / 2;
            ypoint[i] = originY - (data.get(i) / maxY) * graphHeight;

            gc.setFill(Color.BLACK);
            gc.fillText(String.valueOf(i + 1), xpoint[i] - 4, originY + 12);
        }

        gc.setStroke(Color.BLUE);
        gc.setLineWidth(1.5);
        for(int i=0;i < n-1;i++){
            gc.strokeLine(xpoint[i] , ypoint[i] , xpoint[i+1] ,ypoint[i+1]);
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
