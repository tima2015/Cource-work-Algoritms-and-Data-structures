package ru.spruceteam.coursework.desktop;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

import javax.swing.*;
import java.io.File;

public class Chart {

    private Test test;

    private static Test readSimpleFile(){
        File file = null;
        File dir = new File("./");
        File[] files = dir.listFiles();
        if (files != null)
            for (int i = 0; i < files.length; i++) {
                if (files[i].getName().contains(".json")) {
                    file = files[i];
                    break;
                }
            }
        return Test.fromJson(file);
    }

    Chart(File file){
        this(Test.fromJson(file));
    }

    Chart(){
        this(readSimpleFile());
    }

    Chart(Test test){
        this.test = test;
        JFreeChart chart = createChart();
        JFrame frame = new JFrame();
        ChartPanel comp = new ChartPanel(chart);
        comp.setFillZoomRectangle(true);
        comp.setMouseWheelEnabled(true);
        frame.add(comp);
        frame.pack();
        frame.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        frame.setVisible(true);
    }

    private XYDataset createDataset(){
        XYSeries bubble = new XYSeries("Bubble");
        XYSeries quick = new XYSeries("Quick");
        for (int i = 0; i < test.getL(); i++) {
            Data data = test.getData()[i];
            bubble.add(i,data.bubble);
            quick.add(i,data.quick);
        }
        XYSeriesCollection dataset = new XYSeriesCollection();
        dataset.addSeries(bubble);
        dataset.addSeries(quick);
        return dataset;
    }

    private JFreeChart createChart(){

        return ChartFactory.createXYLineChart("Скорость алгоритмов сортировки","Номер теста","Время",createDataset(), PlotOrientation.VERTICAL,true, true,false);
    }

}
