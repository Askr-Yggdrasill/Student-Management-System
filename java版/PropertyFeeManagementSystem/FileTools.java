package PropertyFeeManagementSystem;

import java.io.*;
import java.nio.file.Files;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

//读取文件
public class FileTools {
    public void readFile(List<Resident> allResidents) {
        File file = new File("residentData.txt");
        if (!file.exists()) {
            try {
                file.createNewFile();
            } catch (IOException e) {
                System.err.println("创建文件失败：" + e.getMessage());
            }
        }
        else {
            try (BufferedReader reader = Files.newBufferedReader(file.toPath())) {
                String line;
                // 逐行读取文件内容
                while ((line = reader.readLine()) != null) {
                    Resident resident = new Resident();
                    Scanner scanner = new Scanner(line);

                    resident.setName(scanner.next());
                    resident.setSex(scanner.nextByte());
                    resident.setIdNumber(scanner.next());
                    resident.setPhoneNumber(scanner.next());
                    resident.setBuildingNumber(scanner.nextByte());
                    resident.setUnitNumber(scanner.nextByte());
                    resident.setHouseNumber(scanner.nextByte());
                    resident.setSquareMeter(scanner.nextDouble());
                    resident.setPerPrice(scanner.nextDouble());
                    resident.setMoney(scanner.nextDouble());
                    resident.setOthers(scanner.nextLine());

                    allResidents.add(resident);
                }
            }
            catch (IOException e) {
                System.err.println("文件读取失败: " + e.getMessage());
            }
        }
    }

    public void writeFile(LinkedList<Resident> allResidents) {
        String filePath = "residentData.txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (Resident resident : allResidents) {
                writer.write(resident.toString()); // 写入居民信息，每条信息占一行
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("写入居民信息到文件时发生错误: " + e.getMessage());
        }
    }
}
