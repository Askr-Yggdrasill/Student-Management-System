package PropertyFeeManagementSystem;

import java.util.InputMismatchException;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;

public class ChangeResidentSystem {
    public void ui() {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>修改系统\n");
        System.out.println("1. 修改住户信息\n");
        System.out.println("0. 退出");
        System.out.print("\n请输入操作：");
    }
    public void changeResident(Scanner scanner, List<Resident> allResident){
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>修改系统\n");
        if(allResident.isEmpty()){
            System.out.println("\n暂无住户，请导入再试(按回车返回)");
            scanner.nextLine();
            return;
        }
        String idNumber;
        System.out.print("请输入身份证号:");
        while(true) {
            idNumber = scanner.nextLine();
            if (idNumber == null || !idNumber.matches("^\\d{17}[\\dxX]$")) {  //正则表达式，14位数字，最后一位可以为x
                System.out.println("身份证号格式错误，请确保为18位数字(或最后一位为数字)");
                System.out.print("请重新输入：");
                continue;
            }
            break;
        }
        ListIterator<Resident> iterator = allResident.listIterator();
        Resident resident = null;
        while(iterator.hasNext()) {
            resident = iterator.next();
            if(resident.getIdNumber().equals(idNumber)){
                break;
            }
        }
        if(resident == null){
            System.out.println("\n暂无此人");
        }
        else{
            re:
            while(true) {
                Main.clearScreen();
                System.out.println("============================物业费管理系统=============================");
                System.out.println(">>修改系统\n");
                resident.allPrint();
                System.out.println("====================================================================\n");
                System.out.println("0. 退出\n");
                System.out.print("请输入操作:");
                int select;
                while(true) {
                    select = scanner.nextInt();
                    scanner.nextLine();
                    if (select >= 0 && select <= 12) {
                        break;
                    }
                    System.out.print("属性不存在，请重新输入：");
                }
                switch (select) {
                    case 0:
                        Main.returnPrint(scanner,1000,
                                "\n正在返回...","返回失败，按回车强制结束！");
                        return;
                    case 1:
                        resident.setName(scanner);
                        break;
                    case 2:
                        resident.setSex(scanner);
                        break;
                    case 3:
                        resident.setIdNumber(scanner, allResident);
                        break;
                    case 4:
                        resident.setPhoneNumber(scanner);
                        break;
                    case 5:
                        resident.setBuildingNumber(scanner);
                        break;
                    case 6:
                        resident.setUnitNumber(scanner);
                        break;
                    case 7:
                        resident.setHouseNumber(scanner);
                        break;
                    case 8:
                        resident.setSquareMeter(scanner);
                        break;
                    case 9:
                        resident.setPerPrice(scanner);
                        break;
                    case 10:
                        resident.setOthers(scanner);
                        break;
                    case 11:
                        System.out.print("请输入新的物业费：");
                        double money;
                        while(true) {
                            try{
                                money = scanner.nextDouble();
                                scanner.nextLine();
                                resident.setMoney(money);
                                break;
                            }
                            catch (InputMismatchException e) {
                                System.out.print("输入格式错误，请重新输入：");
                            }
                        }
                        break;
                    case 12:
                        resident.setOthers(scanner);
                        break;
                }
                Main.returnPrint(scanner,1000,
                        "\n修改成功，正在返回...","返回失败，按回车强制结束！");
            }
        }
    }
}
