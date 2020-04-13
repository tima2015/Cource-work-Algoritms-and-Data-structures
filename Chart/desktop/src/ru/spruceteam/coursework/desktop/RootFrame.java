package ru.spruceteam.coursework.desktop;

import javax.swing.*;
import java.awt.*;

public class RootFrame implements Runnable
{
    private JFrame root;
    static MainMenu mainMenu;

    @Override
    public void run() {
        root = new JFrame("Analysis Chart");
        root.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        root.pack();
        root.add(new MainMenu());
        root.setResizable(false);
        root.setVisible(true);
    }
}
