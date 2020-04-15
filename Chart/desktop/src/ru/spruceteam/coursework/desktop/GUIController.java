package ru.spruceteam.coursework.desktop;

import javafx.fxml.FXML;
import javafx.scene.control.ProgressIndicator;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.DirectoryChooser;
import javafx.stage.FileChooser;

import java.io.File;
import java.io.IOException;

public class GUIController {

    @FXML
    AnchorPane mainmenu;
    @FXML
    AnchorPane simpleMenu;
    @FXML
    AnchorPane multyMenu;
    @FXML
    AnchorPane progressM;

    @FXML
    RadioButton single;

    public void onSingle(){
        multy.setSelected(false);
        singlefile.setSelected(false);
        multyfile.setSelected(false);
    }

    @FXML
    RadioButton multy;

    public void onMulty(){
        single.setSelected(false);
        singlefile.setSelected(false);
        multyfile.setSelected(false);
    }

    @FXML
    RadioButton singlefile;

    public void onSingleFile(){
        single.setSelected(false);
        multy.setSelected(false);
        multyfile.setSelected(false);
    }

    @FXML
    RadioButton multyfile;

    public void onMultyFile(){
        multy.setSelected(false);
        singlefile.setSelected(false);
        single.setSelected(false);
    }

    public void onBack(){
        mainmenu.setVisible(true);
        simpleMenu.setVisible(false);
        multyMenu.setVisible(false);
    }

    public void onNext(){
        int mode = single.isSelected() ? 0 : multy.isSelected() ? 1 : singlefile.isSelected() ? 2 : 3;
        switch (mode){
            case 0:
                mainmenu.setVisible(false);
                simpleMenu.setVisible(true);
                break;
            case 1:
                mainmenu.setVisible(false);
                multyMenu.setVisible(true);
                break;
            case 2: {
                FileChooser chooser = new FileChooser();
                chooser.setInitialDirectory(new File("./"));
                chooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("JSON", "*.json"));
                new SimpleChart(chooser.showOpenDialog(mainmenu.getScene().getWindow()));
            }
                break;
            case 3: {
                DirectoryChooser chooser = new DirectoryChooser();
                chooser.setInitialDirectory(new File("./"));
                new MultyChart(chooser.showDialog(mainmenu.getScene().getWindow()));
            }
                break;

        }
    }

    @FXML
    ProgressIndicator progress;

    @FXML
    TextField singleSize;
    @FXML
    TextField singleTestN;

    private Process analysisProcess;

    public void onSingleTestStart(){
        removeAllJson();
        int size = Integer.parseInt(singleSize.getText());
        int testN = Integer.parseInt(singleTestN.getText());
        ProcessBuilder processBuilder = new ProcessBuilder("analysis",  size + "", testN + "", "1");
        try {
            analysisProcess = processBuilder.start();
            Thread thread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        analysisProcess.waitFor();
                        progressM.setVisible(false);
                        mainmenu.setVisible(true);
                        //TODO on test finish
                       new SimpleChart();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            });
            thread.start();
            simpleMenu.setVisible(false);
            progress.setProgress(ProgressIndicator.INDETERMINATE_PROGRESS);
            progressM.setVisible(true);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @FXML
    TextField multyMinSize;
    @FXML
    TextField multyMaxSize;
    @FXML
    TextField multyTestN;
    @FXML
    TextField multyTact;

    public void onMultyTestStart(){
        removeAllJson();
        progress.setProgress(0);
        Thread thread = new Thread(new Runnable() {

            int minSize = Integer.parseInt(multyMinSize.getText());
            int maxSize = Integer.parseInt(multyMaxSize.getText());
            int tact = Integer.parseInt(multyTact.getText());
            int testN = Integer.parseInt(multyTestN.getText());
            double progressMax = (maxSize - minSize)/((double)tact), i = 0;
            int currentSize = minSize;

            @Override
            public void run() {
                while (currentSize <= maxSize){
                    ProcessBuilder processBuilder = new ProcessBuilder("analysis",  currentSize + "", testN + "", "1");
                    try {
                        analysisProcess = processBuilder.start();
                        analysisProcess.waitFor();
                    } catch (IOException | InterruptedException e) {
                        e.printStackTrace();
                    }
                    currentSize = Math.min(currentSize + tact, maxSize);
                    progress.setProgress(i++/progressMax);
                }
                progressM.setVisible(false);
                mainmenu.setVisible(true);
                //TODO on finish
                new MultyChart();
            }
        });
        multyMenu.setVisible(false);
        progressM.setVisible(true);
        thread.start();
    }

    private void removeAllJson(){
        File dir = new File("./");
        File[] files = dir.listFiles();
        if (files != null)
        for (File file : files) {
            if (file.getName().contains(".json"))
                file.delete();
        }
    }

}
