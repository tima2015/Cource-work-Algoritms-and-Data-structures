package ru.spruceteam.coursework.desktop;

import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.backends.lwjgl.LwjglApplicationConfiguration;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import ru.spruceteam.coursework.Core;

import javax.swing.*;
import java.io.File;
import java.net.URI;
import java.net.URL;
import java.nio.file.Files;
import java.util.Enumeration;

public class DesktopLauncher extends Application {
	public static void main (String[] arg) {
		//LwjglApplicationConfiguration config = new LwjglApplicationConfiguration();
		//new LwjglApplication(new Core(), config);
		launch(arg);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		URL location = new File("gui.fxml").toPath().toUri().toURL();
		Parent root = FXMLLoader.load(location);
		primaryStage.setScene(new Scene(root));
		primaryStage.show();
	}
}
