package ru.spruceteam.coursework.desktop;

import com.badlogic.gdx.utils.Array;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

import javax.swing.*;
import java.io.File;

public class MultyChart {

    private static Array<SimpleTest> getDataFromFile(File dir){
        File[] files = dir.listFiles();
        Array<SimpleTest> array = new Array<>();
        for (int i = 0; i < files.length; i++) {
            if (files[i].getName().contains(".json")){
                array.add(SimpleTest.fromJson(files[i]));
            }
        }
        return array;
    }

    public MultyChart(){
        this(new File("./"));
    }

    public MultyChart(File dir) {
        JFreeChart chart = createChart(dir);
        JFrame frame = new JFrame();
        ChartPanel comp = new ChartPanel(chart);
        comp.setFillZoomRectangle(true);
        comp.setMouseWheelEnabled(true);
        frame.add(comp);
        frame.pack();
        frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        frame.setVisible(true);
    }

    private XYDataset createDataset(File dir){
        XYSeries bubble = new XYSeries("Bubble");
        XYSeries quick = new XYSeries("Quick");

        Array<SimpleTest> array = getDataFromFile(dir);
        for (int i = 0; i < array.size; i++) {
            SimpleTest test = array.get(i);
            Data average = test.getAverage();
            System.out.println(average);
            bubble.add(test.getN(), Math.log(average.bubble));
            quick.add(test.getN(), Math.log(average.quick));
        }

        XYSeriesCollection collection = new XYSeriesCollection();
        collection.addSeries(bubble);
        collection.addSeries(quick);
        return collection;
    }

    private JFreeChart createChart(File dir){
        JFreeChart chart = ChartFactory.createXYLineChart("Сравнение методов сортировки","N","Время",createDataset(dir), PlotOrientation.VERTICAL,true, true,false);

        return chart;
    }
}
