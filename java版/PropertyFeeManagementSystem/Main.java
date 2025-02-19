package PropertyFeeManagementSystem;

import java.util.InputMismatchException;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String truePassWord = "10086";

        Scanner scanner = new Scanner(System.in);
        FileTools fileTools = new FileTools();

        System.out.println("=============欢迎使用物业费管理系统==============\n");
        System.out.print("请输入登录密码：");
        while (true) {
            String password = scanner.nextLine();
            if (!password.equals(truePassWord)) {
                System.out.print("密码错误！请重新输入密码：");
            } else {
                break;
            }
            returnPrint(scanner,2000,"密码正确！正在进入系统...","进入失败！");
        }   //判断密码

        LinkedList<Resident> allResidents = new LinkedList<>(); //创建链表
        fileTools.readFile(allResidents);

//        Resident lll = new Resident();
//        lll.setResident();
//        allResidents.add(lll);
        int select = 1;
        do {
            clearScreen();
            //整理排序
            allResidents.sort((r1, r2) -> Double.compare(r1.getMoney(), r2.getMoney()));
            fileTools.writeFile(allResidents);
            System.out.println("============================物业费管理系统=============================\n");
            System.out.println("1. 导入系统");
            System.out.println("2. 修改系统");
            System.out.println("3. 删除系统");
            System.out.println("4. 查询系统");
            System.out.println("5. 缴费系统");
            System.out.println("6. 月份控制\n");
            System.out.println("0. 退出");
            System.out.print("\n请输入操作：");
            select = scanner.nextInt();
            scanner.nextLine();
            switch (select) {
                case 0: {
                    clearScreen();
                    System.out.println("============================物业费管理系统=============================\n");
                    returnPrint(scanner, 2000, "正在退出中...", "警告，退出失败！");
                }//退出系统
                break;
                case 1: {
                    AddResidentSystem addSystem = new AddResidentSystem();
                    Resident newResident;
                    do {
                        clearScreen();
                        addSystem.ui();
                        select = scanner.nextInt();
                        scanner.nextLine();
                        switch (select) {
                            case 0:
                                break;
                            case 1:
                                newResident = addSystem.addResident(scanner, allResidents);
                                if (trueOrFalse(scanner)) {
                                    allResidents.add(newResident);
                                    returnPrint(scanner, 1000, "添加成功，正在返回...", "返回失败！");
                                }
                                break;
                            default:
                                System.out.print("输入不合法！请重新输入：");
                                returnPrint(scanner,1000,"","");
                                break;
                        }
                    } while (select != 0);
                    select = 1;
                }//导入系统
                break;
                case 2: {
                    ChangeResidentSystem changeSystem = new ChangeResidentSystem();
                    do {
                        clearScreen();
                        changeSystem.ui();
                        select = scanner.nextInt();
                        scanner.nextLine();
                        while(select != 0 && select != 1){
                            System.out.print("操作不存在，请重新输入：");
                            select = scanner.nextInt();
                            scanner.nextLine();
                        }
                        if(select == 1){
                            clearScreen();
                            changeSystem.changeResident(scanner, allResidents);
                        }
                    }while (select != 0);
                    select = 1;
                }//修改系统
                break;
                case 3: {
                    DeleteResidentSystem deleteSystem = new DeleteResidentSystem();
                    do {
                        clearScreen();
                        deleteSystem.ui();
                        select = scanner.nextInt();
                        scanner.nextLine();
                        switch (select) {
                            case 0:
                                break;
                            case 1:
                                deleteSystem.deleteResident(scanner, allResidents);
                                returnPrint(scanner, 1000, "正在返回...", "返回失败！");
                                break;
                            default:
                                System.out.print("输入不合法！请重新输入：");
                                returnPrint(scanner,1000,"","");
                                break;
                        }
                    } while (select != 0);
                    select = 1;
                }//删除系统
                break;
                case 4: {
                    if (allResidents.isEmpty()) {
                        clearScreen();
                        System.out.println("============================物业费管理系统=============================");
                        System.out.println(">>修改系统\n");
                        System.out.println("目前无人居住，请导入后继续！(按回车返回)");
                        scanner.nextLine();
                        returnPrint(scanner, 1000, "正在返回...", "返回失败!");
                        break;
                    }
                    FindResidentSystem findSystem = new FindResidentSystem();
                    do{
                        findSystem.ui();
                        select = scanner.nextInt();
                        scanner.nextLine();
                        switch (select) {
                            case 0:     //退出
                                break;
                            case 1:     //总体输出
                                findSystem.printAll(allResidents);
                                System.out.println("\n按回车继续");
                                scanner.nextLine();
                                break;
                            case 2:     //按身份证号
                                findSystem.findIdNumber(scanner, allResidents);
                                System.out.println("\n按回车继续");
                                scanner.nextLine();
                                break;
                            case 3:     //按姓名
                                findSystem.findName(scanner, allResidents);
                                break;
                            case 4:     //按联系电话
                                findSystem.findPhoneNumber(scanner, allResidents);
                                break;
                            case 5:     //按楼号
                                findSystem.findBuildingNumber(scanner, allResidents);
                                break;
                            case 6:     //按单元号
                                findSystem.findUnitNumber(scanner, allResidents);
                                break;
                            case 7:     //按房号
                                findSystem.findHouseNumber(scanner, allResidents);
                                break;
                            default:
                                System.out.print("输入不合法！请重新输入：");
                                returnPrint(scanner,1000,"","");
                                continue;
                        }
                        if(select != 1) {
                            returnPrint(scanner, 1000, "正在返回...", "返回失败!");
                        }
                    }while(select != 0);
                    select = 1; //防止外层判断也掉了，直接结束
                }//查询系统
                break;
                case 5: {
                    if (allResidents.isEmpty()) {
                        clearScreen();
                        System.out.println("============================物业费管理系统=============================");
                        System.out.println(">>缴费系统\n");
                        System.out.println("目前无人居住，请导入后继续！(按回车返回)");
                        scanner.nextLine();
                        returnPrint(scanner, 1000, "正在返回...", "返回失败!");
                        break;
                    }
                    do{
                        Main.clearScreen();
                        System.out.println("============================物业费管理系统=============================");
                        System.out.println(">>缴费系统\n");
                        System.out.println("1. 缴费");
                        System.out.println("0. 退出");
                        System.out.print("\n请输入操作：");
                        select = scanner.nextInt();
                        scanner.nextLine();
                        switch (select) {
                            case 0:
                                break;
                            case 1: {
                                String idNumber;
                                System.out.print("请输入身份证号:");
                                while (true) {
                                    idNumber = scanner.nextLine();
                                    if (idNumber == null || !idNumber.matches("^\\d{17}[\\dxX]$")) {  //正则表达式，14位数字，最后一位可以为x
                                        System.out.println("身份证号格式错误，请确保为18位数字(或最后一位为数字)");
                                        System.out.print("请重新输入：");
                                        continue;
                                    }
                                    break;
                                }
                                ListIterator<Resident> iterator = allResidents.listIterator();
                                Resident resident = null;
                                boolean key = true;
                                while (iterator.hasNext()) {
                                    resident = iterator.next();
                                    if (resident.getIdNumber().equals(idNumber)) {
                                        key = false;
                                        Main.clearScreen();
                                        System.out.println("============================物业费管理系统=============================");
                                        System.out.println(">>缴费系统>>缴费\n");
                                        System.out.println("====================================================================");
                                        System.out.println(resident.briefPrint());
                                        System.out.println("====================================================================\n");
                                        break;
                                    }
                                }
                                if (key) {
                                    System.out.println("\n暂无此人");
                                    break;
                                } else {
                                    System.out.println("1. 缴费");
                                    System.out.println("2. 修改金额\n");
                                    System.out.println("0. 退出\n");
                                    System.out.print("请输入操作:");
                                    select = scanner.nextInt();
                                    while (select < 0 || select > 2) {
                                        System.out.print("操作不存在，请重新输入：");
                                        select = scanner.nextInt();
                                    }
                                    if (select == 1) {
                                        resident.addMoney(scanner);
                                    } else if (select == 2) {
                                        double money;
                                        System.out.print("请输入新的物业费：");
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
                                    }
                                }
                                System.out.println("当前数据:");
                                System.out.println("====================================================================");
                                System.out.println(resident.briefPrint());
                                System.out.println("====================================================================\n");
                                System.out.println("\n按回车继续");
                                scanner.nextLine();
                            }
                            break;
                            default:
                                System.out.print("输入不合法！请重新输入：");
                                returnPrint(scanner,1000,"","");
                                continue;
                        }
                        if(select != 1) {
                            returnPrint(scanner, 1000, "正在返回...", "返回失败!");
                        }
                    }while(select != 0);
                    select = 1; //防止外层判断也掉了，直接结束
                }//缴费系统
                break;
                case 6: {
                    if (allResidents.isEmpty()) {
                        clearScreen();
                        System.out.println("============================物业费管理系统=============================");
                        System.out.println(">>月份系统\n");
                        System.out.println("目前无人居住，请导入后继续！(按回车返回)");
                        scanner.nextLine();
                        returnPrint(scanner, 1000, "正在返回...", "返回失败!");
                        break;
                    }
                    do{
                        Main.clearScreen();
                        System.out.println("============================物业费管理系统=============================");
                        System.out.println(">>月份系统\n");
                        System.out.println("1. 回退到上一月");
                        System.out.println("2. 下一月");
                        System.out.println("0. 退出");
                        System.out.print("\n请输入操作：");
                        select = scanner.nextInt();
                        scanner.nextLine();
                        ListIterator<Resident> iterator = allResidents.listIterator();
                        switch (select) {
                            case 0:
                                returnPrint(scanner, 1000, "正在返回...", "返回失败!");
                                break;
                            case 1: {
                                while(iterator.hasNext()) {
                                    Resident resident = iterator.next();
                                    resident.setMoney(resident.getMoney() + resident.getPerMonthPrice());
                                }
                            }
                            break;
                            case 2:{
                                while(iterator.hasNext()) {
                                    Resident resident = iterator.next();
                                    resident.setMoney(resident.getMoney() - resident.getPerMonthPrice());
                                }
                            }
                            break;
                            default:
                                System.out.print("输入不合法！请重新输入：");
                                returnPrint(scanner,1000,"","");
                                continue;
                        }
                        if(select != 0) {
                            returnPrint(scanner, 1000, "修改成功!正在返回...", "返回失败!");
                        }
                    }while(select != 0);
                    select = 1; //防止外层判断也掉了，直接结束
                }//月份控制
                default:
                    System.out.print("该操作不存在！请重新输入：");
            }
        } while (select != 0);
    }

    public static boolean trueOrFalse(Scanner scanner) {
        System.out.print("是否保存？(是：1 否：0)");
        byte buildingNumber;
        while(true) {
            try {
                buildingNumber = scanner.nextByte();
                scanner.nextLine();
                if(buildingNumber == 1) {
                    return true;
                }
                else if(buildingNumber == 0) {
                    return false;
                }
                else {
                    System.out.print("输入非法！请重新输入！");
                }
            }
            catch (InputMismatchException e) {
                System.out.print("输入非法！请重新输入！");
            }
        }
    }   //是或者否判断

    public static void returnPrint(Scanner scanner,int time,String s1,String s2) {    //咋瓦鲁多
        System.out.println(s1);
        try {
            Thread.sleep(time);//假装在加载
        } catch (InterruptedException e) {
            System.out.println(s2+"\n按回车强制结束程序！");
            scanner.next();
            System.exit(1);
        }
    }
    //清空屏幕
    public static void clearScreen() {
        for (int i = 0; i < 50; i++) {
            System.out.println();
        }
    }
}