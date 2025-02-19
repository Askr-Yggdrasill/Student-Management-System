package PropertyFeeManagementSystem;

import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;

public class DeleteResidentSystem {
    public void ui(){
        Main.clearScreen();
        System.out.println("============================物业费管理系统=============================");
        System.out.println(">>删除系统\n");
        System.out.println("1. 删除住户");
        System.out.println("0. 退出");
        System.out.print("\n请输入操作：");
    }

    public void deleteResident(Scanner scanner, List<Resident> allResident){
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
        }
        else {
            if (Main.trueOrFalse(scanner)) {
                iterator.remove();
                System.out.print("已成功删除!");
            }
            else{
                System.out.print("已取消!");
            }
        }
    }
}
