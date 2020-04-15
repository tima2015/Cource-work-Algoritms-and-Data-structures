package ru.spruceteam.coursework.desktop;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.BigDecimal;

public class Test {
    private Test(){}

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

    public static Test fromJson(File file){
        JsonObject parse = null;
        try {
            parse = JsonParser.parseReader(new FileReader(file)).getAsJsonObject();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        Test test = new Test();
        test.n = parse.get("N").getAsInt();
        test.l = parse.get("L").getAsInt();
        test.data = new Data[test.l];
        JsonArray measurements = parse.get("Measurements").getAsJsonArray();
        for (int i = 0; i < measurements.size(); i++) {
            JsonObject value = measurements.get(i).getAsJsonObject();
            test.data[i] = new Data(value.get("bubble").getAsDouble(), value.get("quick").getAsDouble());
        }
        return test;
    }


}
