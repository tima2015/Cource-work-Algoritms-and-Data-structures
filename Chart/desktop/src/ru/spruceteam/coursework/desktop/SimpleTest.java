package ru.spruceteam.coursework.desktop;

import com.badlogic.gdx.utils.JsonReader;
import com.badlogic.gdx.utils.JsonValue;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigDecimal;
import java.math.BigInteger;

public class SimpleTest {
    private SimpleTest(){}

    private int n;
    private int l;
    private Data[] data;

    public int getN() {
        return n;
    }

    public int getL() {
        return l;
    }

    public Data[] getData() {
        return data;
    }

    public Data getAverage(){
        BigDecimal sumB = BigDecimal.ZERO;
        BigDecimal sumQ = BigDecimal.ZERO;
        for (int i = 0; i < l; i++) {
            sumB = sumB.add(BigDecimal.valueOf(data[i].bubble));
            sumQ = sumQ.add(BigDecimal.valueOf(data[i].quick));
        }
        sumB = sumB.divide(BigDecimal.valueOf(l));
        sumQ = sumQ.divide(BigDecimal.valueOf(l));
        return new Data(sumB.doubleValue(), sumQ.doubleValue());
    }

    public static SimpleTest fromJson(File file){
        JsonValue parse = null;
        try {
            parse = new JsonReader().parse(new FileInputStream(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        SimpleTest test = new SimpleTest();
        if (parse == null) {
            return null;
        }
        test.n = parse.get("N").asInt();
        test.l = parse.get("L").asInt();
        test.data = new Data[test.l];
        JsonValue measurements = parse.get("Measurements");
        for (int i = 0; i < measurements.size; i++) {
            JsonValue value = measurements.get(i);
            test.data[i] = new Data(value.get("bubble").asInt(), value.get("quick").asInt());
        }
        return test;
    }


}
