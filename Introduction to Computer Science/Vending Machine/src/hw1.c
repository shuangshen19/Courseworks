#include <stdio.h>
int main(void)
{
    // �]�w��l�Ѽ�
    char se[2][4] = {"yes","NO "};
    int stock[] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};

    // �]�w��l�e��
    printf("�w��Ө�n���c���!!!\n");
    printf("�c����̦�15�ض��ƥi�ѱz�����\n");
    printf("�ާ@��k:1.��ܱz�ҷQ�n���n��\n");
    printf("         2.�p���s�f(yes)�A�бz��J�۹��������B\n");
    printf("           �p�w����(NO)�A�Э��s��ܱz�ҷQ�n���n��\n");
    printf("         3.�z�N�|��o�z�Q�n���n��!\n");
    
    int flag = 0;

    // �]�w���ưj��,�b�C�@���ʶR���s�w�s�����
    do
    {
    int s[15];
    int target, pay;

    // �p�G�w�⧹,�N�w�s�ƾڱqyes�令NO
    int i;
    for(i = 0; i < 15; i++)
    {
        if(stock[i]==0) s[i] = 1;
        else s[i] = 0;
    }

    // MENU�M���ƥN�X
    printf("\n1        2        3        4        5        \n");
    printf("����     ���     �Q�s��   �Ȧ̯�   �M��     \n");
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
    printf("�f�c��   �f�c��   �h�h��   ���G��   �R���f�c \n");
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
    printf("����     ����     �Q�s��   �A����   �ï]���� \n");
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
    
    printf("\n\n�п�J�z�Q��ܪ����Ƹ��X:");
    scanf("%d", &target);

    // �P�_���ƪ�����(���\�ʶR����ʶR���\�ç�s,�����\��ܰh�٪��B) 
    if(target <= 5 && target > 0)
    {
        if(stock[target-1] > 0)
        {
            printf("�z��ܪ����Ƭ�20��,�Ч�J���B:");
            scanf("%d", &pay);
            if(pay >= 20) 
	    {
	        int c = pay-20;
	        printf("�ʶR���\\!!�z����s��%d��\n", c);
                printf("���¥��{!���z�֦��r�֪��@��!\n");
	        stock[target-1]--;
                continue;
	    }	
            else printf("�z��J�����������L�k�ʶR,�h�z%d��\n", pay);
        }
        else printf("�z��ܪ����Ƥw�⧹,�Э��s��J\n");	
    }
    else if(target <= 10 && target > 5)
    {
        if(stock[target-1] > 0)
        {
            printf("�z��ܪ����Ƭ�25��,�Ч�J���B:");
            scanf("%d", &pay);
            if(pay >= 25) 
	    {
	        int c = pay-25;
	        printf("�ʶR���\\!!�z����s��%d��\n", c);
                printf("���¥��{!���z�֦��r�֪��@��!\n");
	        stock[target-1]--;
                continue;
	    }	
            else printf("�z��J�����������L�k�ʶR,�h�z%d��\n", pay);
        }
        else printf("�z��ܪ����Ƥw�⧹,�Э��s��J\n");		
    }
    else if(target <= 15 && target > 10)
    {
        if(stock[target-1] > 0)
        {
            printf("�z��ܪ����Ƭ�30��,�Ч�J���B:");
            scanf("%d", &pay);
            if(pay >= 30) 
	    {
	        int c = pay-30;
	        printf("�ʶR���\\!!�z����s��%d��\n", c);
                printf("���¥��{!���z�֦��r�֪��@��!\n");
	        stock[target-1]--;
                continue;
	    }	
            else printf("�z��J�����������L�k�ʶR,�h�z%d��\n", pay);
        }
        else printf("�z��ܪ����Ƥw�⧹,�Э��s��J\n");		
    }
    else if(target == 8888) flag = 1;  // �h�X�c���
    // ��J���~�ШϥΪ̭��s��J���T�N�X
    else 
    {
        printf("�z��J�����ƥN�X���s�b�A�Э��s��J�N�X(1~15)\n");
        continue;
    }
    }while(flag == 0);   
    printf("�z�w���}�n���c���,���z���o�r��\n");
    return 0;
}
