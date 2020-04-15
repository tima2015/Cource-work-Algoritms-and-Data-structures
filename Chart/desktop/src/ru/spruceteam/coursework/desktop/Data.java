package ru.spruceteam.coursework.desktop;

import static java.lang.Math.log;

public class Data {

    public Data(double bubble, double quick) {
        if (quick == 0)
            quick = 0.1;
        if (bubble == 0)
            bubble = 0.1;
        this.bubble = (bubble);
        this.quick = (quick);
        /*this.bubble = Math.log(bubble);
        this.quick = Math.log(quick);*/
    }

    double bubble;
    double quick;

    @Override
    public String toString() {
        return "Data{" +
                "bubble=" + bubble +
                ", quick=" + quick +
                '}';
    }
}
