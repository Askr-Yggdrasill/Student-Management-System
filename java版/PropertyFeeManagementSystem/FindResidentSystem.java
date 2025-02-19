package PropertyFeeManagementSystem;

import java.util.*;

public class FindResidentSystem {
    public void ui() {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查询系统\n");
        System.out.println("1. 全部输出");
        System.out.println("2. 按身份证号码");
        System.out.println("3. 按姓名");
        System.out.println("4. 按联系电话");
        System.out.println("5. 按楼号");
        System.out.println("6. 按单元号");
        System.out.println("7. 按房号\n");
        System.out.println("0. 退出");
        System.out.print("\n请输入操作：");
    }
    //已知目标住户节点，深层次打印
    public void print(Scanner scanner, List<Resident> tempResidents, String systemName){  //...,临时链表，节点数量
        int i = tempResidents.size();
        while(true) {
            Main.clearScreen();
            System.out.println("============================物业费管理系统=============================");
            System.out.println(">>查找系统>>按" + systemName +"查找\n");
            int j = 0;
            //按格式打印出目标节点信息
            System.out.println("====================================================================");
            for (Resident resident : tempResidents) {
                System.out.println((j + 1) + ". " + resident.briefPrint());
                j++;
            }
            System.out.println("====================================================================");
            System.out.println("\n0. 退出");
            System.out.print("\n请输入序号：");

            while(true) {
                int k = scanner.nextInt();
                scanner.nextLine();
                if(k == 0){
                    return;
                }
                if(k < 0 || k > i){
                    System.out.print("该住户不存在，请重新输入：");
                    continue;
                }
                Main.clearScreen();
                System.out.println("============================物业费管理系统=============================");
                System.out.println(">>查找系统>>按" + systemName + "查找>>详细信息\n");
                tempResidents.get(k - 1).allPrint();
                System.out.println("====================================================================");
                System.out.println("按回车键返回");
                scanner.nextLine();
                break;
            }
        }
    }

    public void printAll(List<Resident> allResident){
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查找系统>>全部输出\n");
        ListIterator<Resident> iterator = allResident.listIterator();
        byte k = 0;
        while(iterator.hasNext()) {
            Resident resident = iterator.next();
            resident.allPrint();
        }
        System.out.println("====================================================================");
    }

    public void findIdNumber(Scanner scanner, List<Resident> allResident) {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查找系统>>按身份证号查找\n");
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
        byte k = 0;
        while(iterator.hasNext()) {
            Resident resident = iterator.next();
            if(resident.getIdNumber().equals(idNumber)){
                resident.allPrint();
                System.out.println("====================================================================\n");
                k = 1;
                break;
            }
        }
        if(k == 0){
            System.out.println("\n暂无此人");
            System.out.println("按回车继续");
            scanner.nextLine();
        }
    }

    public void findName(Scanner scanner,List<Resident> allResidents) {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查找系统>>按姓名查找\n");
        String name;
        System.out.print("请输入姓名：");
        name = scanner.nextLine();

        ListIterator<Resident> iteratorAllResidents = allResidents.listIterator();
        List<Resident> tempResidents = new ArrayList<>();    //存目标用户
        while(iteratorAllResidents.hasNext()) {
            Resident resident = iteratorAllResidents.next();
            if(resident.getName().equals(name)){
                tempResidents.add(resident);
            }
        }
        if(tempResidents.isEmpty()){
            System.out.println("\n暂无此人");
            System.out.println("按回车继续");
            scanner.nextLine();
        }
        else {
            print(scanner,tempResidents,"姓名");
        }
    }

    public void findPhoneNumber(Scanner scanner,List<Resident> allResidents) {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查找系统>>按电话号码查找\n");
        String phoneNumber;
        System.out.print("请输入电话号码:");
        while(true) {
            phoneNumber = scanner.nextLine();
            if (phoneNumber == null || !phoneNumber.matches("^1\\d{10}$")) {  //正则表达式，14位数字，最后一位可以为x
                System.out.println("电话号码格式错误，请确保为11位数字(首位为1)");
                System.out.print("请重新输入：");
                continue;
            }
            break;
        }
        ListIterator<Resident> iteratorAllResidents = allResidents.listIterator();
        List<Resident> tempResidents = new ArrayList<>();    //存目标用户
        while(iteratorAllResidents.hasNext()) {
            Resident resident = iteratorAllResidents.next();
            if(resident.getPhoneNumber().equals(phoneNumber)){
                tempResidents.add(resident);
            }
        }
        if(tempResidents.isEmpty()){
            System.out.println("\n暂无此人\n");
            System.out.println("按回车继续");
            scanner.nextLine();
        }
        else {
            print(scanner,tempResidents,"电话号码");
        }
    }

    public void findBuildingNumber(Scanner scanner,List<Resident> allResidents) {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查找系统>>按楼号查找\n");
        byte buildingNumber;
        System.out.print("请输入楼号(1-12)");
        while(true) {
            try {
                buildingNumber = scanner.nextByte();
                scanner.nextLine();
                if (buildingNumber >= 1 && buildingNumber <= 12) {
                    break;
                }
            }
            catch (InputMismatchException e) {
                scanner.nextLine();
            }
            System.out.print("该楼不存在，请重新输入：");
        }
        ListIterator<Resident> iteratorAllResidents = allResidents.listIterator();
        List<Resident> tempResidents = new ArrayList<>();    //存目标用户
        while(iteratorAllResidents.hasNext()) {
            Resident resident = iteratorAllResidents.next();
            if(resident.getBuildingNumber() == buildingNumber){
                tempResidents.add(resident);
            }
        }
        if(tempResidents.isEmpty()){
            System.out.println("\n暂无此人");
            System.out.println("按回车继续");
            scanner.nextLine();
        }
        else {
            print(scanner,tempResidents,"楼号");
        }
    }

    public void findUnitNumber(Scanner scanner,List<Resident> allResidents) {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查找系统>>按单元号查找\n");
        byte unitNumber;
        System.out.print("请输入单元号(1-12)");
        while(true) {
            try {
                unitNumber = scanner.nextByte();
                scanner.nextLine();
                if (unitNumber >= 1 && unitNumber <= 12) {
                    break;
                }
            }
            catch (InputMismatchException e) {
                scanner.nextLine();
            }
            System.out.print("该单元不存在，请重新输入：");
        }
        ListIterator<Resident> iteratorAllResidents = allResidents.listIterator();
        List<Resident> tempResidents = new ArrayList<>();    //存目标用户
        while(iteratorAllResidents.hasNext()) {
            Resident resident = iteratorAllResidents.next();
            if(resident.getUnitNumber() == unitNumber){
                tempResidents.add(resident);
            }
        }
        if(tempResidents.isEmpty()){
            System.out.println("\n暂无此人");
            System.out.println("按回车继续");
            scanner.nextLine();
        }
        else {
            print(scanner,tempResidents,"单元号");
        }
    }

    public void findHouseNumber(Scanner scanner,List<Resident> allResidents) {
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>查找系统>>按房号查找\n");
        byte houseNumber;
        System.out.print("请输入房号(1-127)");
        while(true) {
            try {
                houseNumber = scanner.nextByte();
                scanner.nextLine();
                if (houseNumber >= 1) {
                    break;
                }
            }
            catch (InputMismatchException e) {
                scanner.nextLine();
            }
            System.out.print("该房间不存在，请重新输入：");
        }
        ListIterator<Resident> iteratorAllResidents = allResidents.listIterator();
        List<Resident> tempResidents = new ArrayList<>();    //存目标用户
        while(iteratorAllResidents.hasNext()) {
            Resident resident = iteratorAllResidents.next();
            if(resident.getHouseNumber() == houseNumber){
                tempResidents.add(resident);
            }
        }
        if(tempResidents.isEmpty()){
            System.out.println("\n暂无此人");
            System.out.println("按回车继续");
            scanner.nextLine();
        }
        else {
            print(scanner,tempResidents,"房号");
        }
    }
}
