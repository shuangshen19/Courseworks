#include <stdio.h>
int main(void)
{
    // 設定原始參數
    char se[2][4] = {"yes","NO "};
    int stock[] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};

    // 設定初始畫面
    printf("歡迎來到好茶販賣機!!!\n");
    printf("販賣機裡有15種飲料可供您做選擇\n");
    printf("操作方法:1.選擇您所想要的好茶\n");
    printf("         2.如有存貨(yes)，請您投入相對應的金額\n");
    printf("           如已完售(NO)，請重新選擇您所想要的好茶\n");
    printf("         3.您就會獲得您想要的好茶!\n");
    
    int flag = 0;

    // 設定重複迴圈,在每一次購買後更新庫存並顯示
    do
    {
    int s[15];
    int target, pay;

    // 如果已售完,將庫存數據從yes改成NO
    int i;
    for(i = 0; i < 15; i++)
    {
        if(stock[i]==0) s[i] = 1;
        else s[i] = 0;
    }

    // MENU和飲料代碼
    printf("\n1        2        3        4        5        \n");
    printf("紅茶     綠茶     烏龍茶   玄米茶   清茶     \n");
    printf("NT20     NT20     NT20     NT20     NT20     \n");  
    printf(se[s[0]]);
    printf("      ");
    printf(se[s[1]]);
    printf("      ");
    printf(se[s[2]]);
    printf("      ");
    printf(se[s[3]]);
    printf("      ");
    printf(se[s[4]]);
    printf("\n\n6        7        8        9        10       \n");
    printf("檸檬綠   檸檬紅   多多綠   水果茶   愛玉檸檬 \n");
    printf("NT25     NT25     NT25     NT25     NT25     \n"); 
    printf(se[s[5]]);
    printf("      ");
    printf(se[s[6]]);
    printf("      ");
    printf(se[s[7]]);
    printf("      ");
    printf(se[s[8]]);
    printf("      ");
    printf(se[s[9]]);
    printf("\n\n11       12       13       14       15       \n");
    printf("奶茶     奶綠     烏龍奶   鮮奶茶   珍珠奶茶 \n");
    printf("NT30     NT30     NT30     NT30     NT30     \n");
    printf(se[s[10]]);
    printf("      ");
    printf(se[s[11]]);
    printf("      ");
    printf(se[s[12]]);
    printf("      ");
    printf(se[s[13]]);
    printf("      ");
    printf(se[s[14]]);
    
    printf("\n\n請輸入您想選擇的飲料號碼:");
    scanf("%d", &target);

    // 判斷飲料的金錢(成功購買顯示購買成功並找零,不成功顯示退還金額) 
    if(target <= 5 && target > 0)
    {
        if(stock[target-1] > 0)
        {
            printf("您選擇的飲料為20元,請投入金額:");
            scanf("%d", &pay);
            if(pay >= 20) 
	    {
	        int c = pay-20;
	        printf("購買成功\!!您的找零為%d元\n", c);
                printf("謝謝光臨!祝您擁有愉快的一天!\n");
	        stock[target-1]--;
                continue;
	    }	
            else printf("您投入的金錢不足無法購買,退您%d元\n", pay);
        }
        else printf("您選擇的飲料已售完,請重新輸入\n");	
    }
    else if(target <= 10 && target > 5)
    {
        if(stock[target-1] > 0)
        {
            printf("您選擇的飲料為25元,請投入金額:");
            scanf("%d", &pay);
            if(pay >= 25) 
	    {
	        int c = pay-25;
	        printf("購買成功\!!您的找零為%d元\n", c);
                printf("謝謝光臨!祝您擁有愉快的一天!\n");
	        stock[target-1]--;
                continue;
	    }	
            else printf("您投入的金錢不足無法購買,退您%d元\n", pay);
        }
        else printf("您選擇的飲料已售完,請重新輸入\n");		
    }
    else if(target <= 15 && target > 10)
    {
        if(stock[target-1] > 0)
        {
            printf("您選擇的飲料為30元,請投入金額:");
            scanf("%d", &pay);
            if(pay >= 30) 
	    {
	        int c = pay-30;
	        printf("購買成功\!!您的找零為%d元\n", c);
                printf("謝謝光臨!祝您擁有愉快的一天!\n");
	        stock[target-1]--;
                continue;
	    }	
            else printf("您投入的金錢不足無法購買,退您%d元\n", pay);
        }
        else printf("您選擇的飲料已售完,請重新輸入\n");		
    }
    else if(target == 8888) flag = 1;  // 退出販賣機
    // 輸入錯誤請使用者重新輸入正確代碼
    else 
    {
        printf("您輸入的飲料代碼不存在，請重新輸入代碼(1~15)\n");
        continue;
    }
    }while(flag == 0);   
    printf("您已離開好茶販賣機,祝您玩得愉快\n");
    return 0;
}
