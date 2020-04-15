package ru.spruceteam.coursework.desktop;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.time.TimeSeries;
import org.jfree.data.time.TimeSeriesCollection;
import org.jfree.data.xy.XYDataset;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;

import javax.swing.*;
import java.io.File;

public class SimpleChart {

    private SimpleTest test;

    private static SimpleTest readSimpleFile(){
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
        return SimpleTest.fromJson(file);
    }

    SimpleChart(File file){
        this(SimpleTest.fromJson(file));
    }

    SimpleChart(){
        this(readSimpleFile());
    }

    SimpleChart(SimpleTest test){
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
        JFreeChart chart = ChartFactory.createXYLineChart("Сравнение методов сортировки","L","Время",createDataset(), PlotOrientation.VERTICAL,true, true,false);

        return chart;
    }

}
