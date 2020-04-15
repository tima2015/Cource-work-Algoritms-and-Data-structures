package ru.spruceteam.coursework.desktop;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.net.URL;

public class DesktopLauncher extends Application {
	public static void main (String[] arg) {
		launch(arg);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		URL location = getClass().getResource("gui.fxml");//new File("gui.fxml").toPath().toUri().toURL();
		System.out.println(location);
		Parent root = FXMLLoader.load(location);
		primaryStage.setScene(new Scene(root));
		primaryStage.setResizable(false);
		primaryStage.show();
	}
}
