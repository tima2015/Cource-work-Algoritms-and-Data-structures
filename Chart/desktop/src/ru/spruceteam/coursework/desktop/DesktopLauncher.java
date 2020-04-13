package ru.spruceteam.coursework.desktop;

import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.backends.lwjgl.LwjglApplicationConfiguration;
import ru.spruceteam.coursework.Core;

import javax.swing.*;

public class DesktopLauncher {
	public static void main (String[] arg) {
		//LwjglApplicationConfiguration config = new LwjglApplicationConfiguration();
		//new LwjglApplication(new Core(), config);
		SwingUtilities.invokeLater(new RootFrame());
	}
}
