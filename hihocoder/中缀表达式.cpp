// ��׺���ʽ
#include<bits/stdc++.h>
using namespace std;

int mycmp(char a, char b) {
    if(b == '(')
        return 1;//������ֱ����ջ
    else if((b == '*' || b == '/') &&(a == '+' || a == '-' || a == '('))
        return 1;//*��/���ȼ�����+��-��(����ջ
    else if((b == '+' || b == '-') && (a == '('))
        return 1;//+��-���ȼ�����(����ջ
    else
        return 0;
}

/*��׺���ʽת��׺���ʽ
 ��׺���ʽ֮���޷ָ�
 ��׺���ʽ��������������֮���ÿո�ָ�������ֲ�ͬ������*/
void infix_to_suffix(char* infix, char* suffix) {
    int i, k, j=0, top=0;
    char stack[1000];//�洢�������ջ

    for(i=0; infix[i]!='\0'; i++) {
        if(infix[i] >= '0' && infix[i] <= '9') {
            suffix[j++] = infix[i];//��������ֱ�����
        } else {
            if(i != 0 && infix[i-1] >= '0' && infix[i-1] <= '9') {
                suffix[j++] = ' ';//�������󲹳�ո�ָ�
            }
            if(infix[i] == ')') {
                //������������һֱ����ֱ�������ţ��������Ų����
                while(stack[top-1] != '(') {
                    suffix[j++] = stack[--top];
                    suffix[j++] = ' ';
                }
                top--;
            } else if(top == 0 || mycmp(stack[top-1], infix[i])) {
                //ջΪ�ջ�ǰ�����������ȼ�����ջ������������ǰ��������ջ
                stack[top++] = infix[i];
            } else {
                //��ǰ���������ȼ����ڻ����ջ���������򵯳�ջ��
                while(!mycmp(stack[top-1], infix[i])) {
                    suffix[j++] = stack[--top];
                    suffix[j++] = ' ';
                    if(top == 0)
                        break;
                }
                stack[top++] = infix[i];//��ǰ��������ջ
            }
        }
    }
    //����ո�ָ�
    if(suffix[j-1] != ' ') {
        suffix[j++] = ' ';
    }
    //���������ջ��Ϊ�գ��������в�����
    while(top != 0) {
        suffix[j++] = stack[--top];
        suffix[j++] = ' ';
    }
    suffix[j] = '\0';
}

int suffix_value(char* suffix) {
    int i, j;
    char op;
    int stack[1000];
    int top = 0, value = 0;
    for(i=0; suffix[i] != '\0'; i++) {
        if(suffix[i] >= '0' && suffix[i] <= '9') {
            value = value*10 + suffix[i] - '0';
        } else if(suffix[i] == ' ') {
            //��������ջ
            stack[top++] = value;
            value = 0;
        } else {
            //���ݲ���������ջ���������������м��㲢�õ����
            switch(suffix[i]) {
                case '+': value = stack[top-2] + stack[top-1];break;
                case '-': value = stack[top-2] - stack[top-1];break;
                case '*': value = stack[top-2] * stack[top-1];break;
                case '/': value = stack[top-2] / stack[top-1];break;
                default: break;
            }
            top -= 2;
        }
    }

    return stack[0];
} 

int main() {
    int n;
    char infix[1000], suffix[1000];//infix��׺���ʽ��suffix��׺���ʽ
    
    scanf("%d\n", &n);
    while(n--) {
        gets(infix);
        infix_to_suffix(infix, suffix);    
        printf("%d\n", suffix_value(suffix));
    }

    return 0;
}
