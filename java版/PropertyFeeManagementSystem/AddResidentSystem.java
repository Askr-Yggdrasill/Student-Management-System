package PropertyFeeManagementSystem;

import java.util.List;
import java.util.Scanner;

public class AddResidentSystem {
    public void ui(){
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>导入系统\n");
        System.out.println("1. 导入新住户");
        System.out.println("0. 退出");
        System.out.print("\n请输入操作：");
    }   //ui
    public Resident addResident(Scanner scanner, List<Resident> allResident){
        Resident newResident = new Resident();
        //设置属性
        newResident.setName(scanner);//姓名
        newResident.setSex(scanner);//性别
        newResident.setIdNumber(scanner,allResident);//身份证号
        newResident.setPhoneNumber(scanner);//电话号码
        newResident.setBuildingNumber(scanner);//楼号
        newResident.setUnitNumber(scanner);//单元号
        newResident.setHouseNumber(scanner);//房号
        newResident.setSquareMeter(scanner);
        newResident.setPerPrice(scanner);
        newResident.setOthers(scanner);

        return newResident;
    }   //添加
}
