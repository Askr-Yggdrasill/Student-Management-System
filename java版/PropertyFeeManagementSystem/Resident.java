package PropertyFeeManagementSystem;

import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Resident {
    private String name;
    private byte sex;   //1:男，2：女
    private String idNumber;    //身份证号
    private String phoneNumber;     //电话号码
    private byte buildingNumber;    //楼号
    private byte unitNumber;    //单元号
    private byte houseNumber;   //房号
    private double squareMeter; //平方数
    private double perPrice;    //每平米价格
    private double money;   //已缴纳物业费
    private String others;  //备注

    //getter
    public String getName(){
        return name;
    }
    public String getSex(){
        if (this.sex == 0){
            return "男";
        }
        else {
            return "女";
        }
    }
    public byte getSexNumber(){
        return this.sex;
    }
    public String getIdNumber(){
        return idNumber;
    }
    public String getPhoneNumber(){
        return phoneNumber;
    }
    public byte getBuildingNumber(){
        return buildingNumber;
    }
    public byte getUnitNumber(){
        return unitNumber;
    }
    public byte getHouseNumber(){
        return houseNumber;
    }
    public double getSquareMeter(){
        return squareMeter;
    }
    public double getPerPrice(){
        return perPrice;
    }
    public double getMoney(){
        return this.money;
    }
    public double getPerMonthPrice(){
        return this.squareMeter * this.perPrice;
    }
    public String getOthers(){
        return this.others;
    }

    //setter
    //名字
    public void setName(Scanner scanner){
        System.out.print("请输入姓名：");
        this.name = scanner.nextLine();
    }
    public void setName(String name){
        this.name = name;
    }
    //性别
    public void setSex(Scanner scanner){
        byte sex;
        System.out.print("请输入性别(0:女 1:男)：");
        while(true) {
            try {
                sex = scanner.nextByte();
                scanner.nextLine();
                if (sex != 0 && sex != 1) {
                    System.out.print("该性别不存在！请按重新输入：");
                    continue;
                }
                this.sex = sex;
                break;
            }
            catch (InputMismatchException e) {
                scanner.nextLine();
            }
            System.out.print("该性别不存在！请按重新输入：");
        };
    }
    public void setSex(byte sex){
        this.sex = sex;
    }
    //身份证号
    public void setIdNumber(Scanner scanner, List<Resident> allResidents){
        String idNumber;
        System.out.print("请输入身份证号:");
        restart:
        while(true) {
            idNumber = scanner.nextLine();
            //判断身份证格式
            if (idNumber == null || !idNumber.matches("^\\d{17}[\\dxX]$")) {  //正则表达式，14位数字，最后一位可以为x
                System.out.println("身份证号格式错误，请确保为18位数字(或最后一位为数字)");
                System.out.print("请重新输入：");
                continue;
            }
            //判断身份证是否已使用
            for (Resident resident : allResidents) {
                if (resident.getIdNumber().equals(idNumber)) {
                    System.out.print("该身份证已存在！请重新输入：");
                    continue restart;
                }
            }
            this.idNumber = idNumber;
            break;
        }
    }
    public void setIdNumber(String idNumber){
        this.idNumber = idNumber;
    }
    //电话号码
    public void setPhoneNumber(Scanner scanner){
        String phoneNumber;
        System.out.print("请输入电话号码:");
        while(true) {
            phoneNumber = scanner.nextLine();
            if (phoneNumber == null || !phoneNumber.matches("^1\\d{10}$")) {  //正则表达式，14位数字，最后一位可以为x
                System.out.println("电话号码格式错误，请确保为11位数字(首位为1)");
                System.out.print("请重新输入：");
                continue;
            }
            this.phoneNumber = phoneNumber;
            break;
        }
    }
    public void setPhoneNumber(String phoneNumber){
        this.phoneNumber = phoneNumber;
    }
    //楼号
    public void setBuildingNumber(Scanner scanner){
        byte buildingNumber;
        System.out.print("请输入楼号(1-12)");
        while(true) {
            try {
                buildingNumber = scanner.nextByte();
                scanner.nextLine();
                if (buildingNumber >= 1 && buildingNumber <= 12) {
                    this.buildingNumber = buildingNumber;
                    break;
                }
            }
            catch (InputMismatchException e) {
                scanner.nextLine();
            }
            System.out.print("该楼不存在，请重新输入：");
        }
    }
    public void setBuildingNumber(byte buildingNumber){
        this.buildingNumber = buildingNumber;
    }
    //单元号
    public void setUnitNumber(Scanner scanner){
        byte unitNumber;
        System.out.print("请输入单元号(1-12)");
        while(true) {
            try {
                unitNumber = scanner.nextByte();
                scanner.nextLine();
                if (unitNumber >= 1 && unitNumber <= 12) {
                    this.unitNumber = unitNumber;
                    break;
                }
            }
            catch (InputMismatchException e) {
                scanner.nextLine();
            }
            System.out.print("该单元不存在，请重新输入：");
        }
    }
    public void setUnitNumber(byte unitNumber){
        this.unitNumber = unitNumber;
    }
    //房号
    public void setHouseNumber(Scanner scanner){
        byte houseNumber;
        System.out.print("请输入房号(1-127)");
        while(true) {
            try {
                houseNumber = scanner.nextByte();
                scanner.nextLine();
                if (houseNumber >= 1) {
                    this.houseNumber = houseNumber;
                    break;
                }
            }
            catch (InputMismatchException e) {
                scanner.nextLine();
            }
            System.out.print("该房间不存在，请重新输入：");
        }
    }
    public void setHouseNumber(byte houseNumber){
        this.houseNumber = houseNumber;
    }
    //平方数
    public void setSquareMeter(Scanner scanner){
        double squareMeter;
        System.out.print("请输入平方数：");
        while(true) {
            try{
                squareMeter = scanner.nextDouble();
                scanner.nextLine();
                this.squareMeter = squareMeter;
                break;
            }
            catch (InputMismatchException e) {
                System.out.print("输入格式错误，请重新输入：");
            }
        }
    }
    public void setSquareMeter(double squareMeter){
        this.squareMeter = squareMeter;
    }
    //每平方物业费
    public void setPerPrice(Scanner scanner){
        double perPrice;
        System.out.print("请输入每平方物业费价格：");
        while(true) {
            try{
                perPrice = scanner.nextDouble();
                scanner.nextLine();
                this.perPrice = perPrice;
                break;
            }
            catch (InputMismatchException e) {
                System.out.print("输入格式错误，请重新输入：");
            }
        }
    }
    public void setPerPrice(double perPrice){
        this.perPrice = perPrice;
    }
    //已缴纳物业费
    public void setMoney(double money){
        this.money = money;
    }
    public void addMoney(Scanner scanner){
        double money;
        System.out.print("请输入缴费金额：");
        while(true) {
            try{
                money = scanner.nextDouble();
                scanner.nextLine();
                this.money += money;
                break;
            }
            catch (InputMismatchException e) {
                System.out.print("输入格式错误，请重新输入：");
            }
        }
    }
    //备注
    public void setOthers(Scanner scanner){
        String others;
        System.out.print("请输入备注：");
        others = scanner.nextLine();
        this.others = others;
    }
    public void setOthers(String others){
        this.others = others;
    }
    //打印
    public void allPrint(){
        System.out.println("====================================================================");
        System.out.printf("1. 姓名：%s\n",this.name);
        if(this.sex == 0){
            System.out.println("2. 性别：女");
        }
        else{
            System.out.println("2. 性别：男");
        }
        System.out.printf("3. 身份证号：%s\n",this.idNumber);
        System.out.printf("4. 电话号码：%s\n",this.phoneNumber);
        System.out.printf("5. 楼号：%d\n",this.buildingNumber);
        System.out.printf("6. 单元号：%d\n",this.unitNumber);
        System.out.printf("7. 房号：%d\n",this.houseNumber);
        System.out.printf("8. 平米数：%.2f\n",this.squareMeter);
        System.out.printf("9. 每平米物业费：%.2f\n",this.perPrice);
        System.out.printf("10.每月物业费：%.2f\n",this.getPerMonthPrice());
        System.out.printf("11.已缴纳物业费: %.2f",this.money);
        if(this.money < 0){
            System.out.println("(已欠费)");
        }
        else{
            System.out.println();
        }
        System.out.printf("12.备注：%s\n",this.others);
    }
    //简洁打印
    public String briefPrint(){
        String result = String.format("姓名：%s 身份证号：%s 性别：%s 物业费： %.2f",
                this.name,this.idNumber,this.getSex(),this.money);
        if(this.money < 0){
            result += "(已欠费)";
        }
        return result;
    }
    //整成一个字符串
    public String toString(){
        return this.getName() + " " + this.getSexNumber() + " " + this.getIdNumber() + " " + this.getPhoneNumber() + " "
                + this.getBuildingNumber() + " " + this.getUnitNumber() + " " + this.getHouseNumber() + " "
                + this.getSquareMeter() + " " + this.getPerPrice() + " " + this.getMoney() + " " + this.getOthers();
    }
}
