clear,clc
students = 118 ;
subject = 9;
[num ,txt] = xlsread('chengji.xlsx','Sheet2') ;
temp = txt(: ,1);
% ÿ������ȡһ������
P.name = [];
for i = 1: subject : length(num(:,1))
    P.name = [P.name; temp(i)];
end
P.grade = xlsread('chengji.xlsx','Sheet2','H:H');
P.xuefen = xlsread('chengji.xlsx','Sheet2','L:L');
% ���ɼ�С��60�����ſμ���Ϊ��
for i = 1: length(P.grade)
    if P.grade(i) < 60
        P.grade(i) = 0;
    end
end       
zongjidian = P.grade.* P.xuefen;
for i = 1:students
    P.personal(i) = sum(zongjidian(subject * (i-1)+1 : subject *(i-1)+ subject ));
end
P.personal = (P.personal/sum(P.xuefen(1:subject)))';
%    ����
% me = find(strcmp(P.name,'������') == 1);
% P.name(find(P.personal > P.personal(me)))'
% P.personal(find(P.personal > P.personal(me)))'
% P.personal(me)
[paixu.fenshu,weizhi] = sort(P.personal); 
paixu.name = P.name(weizhi);
