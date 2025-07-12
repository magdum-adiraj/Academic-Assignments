MNT=[]
KPDTAB=[]
PNTAB=[]
APTAB=[]
LC=1

def pass_2_print(lst1):
    f6=open('Expanded_code.txt','a')
    #f6.write(lst1[0])
    for i in range(0,len(lst1)):
        if "(" in lst1[i]:
            para=lst1[i]
            index=int(para[3:-1])
            #print(index)
            val=APTAB[index]
            f6.write(val+" ")
        else:
            f6.write(lst1[i]+" ")
    f6.write("\n")
    f6.close()

def pass_2_oper(lst,kp,kpdtp,mdtp):
    kp1=0
    tempKP=[]
    for i in range(1,len(lst)):
        if "=" in lst[i]:
            kp1+=1
            parameter=lst[i]
            kpstring=""
            arg=""
            for i in range(0,len(parameter)-1):
                kpstring+=parameter[i]
                if parameter[i+1]=="=":
                    i+=1
                    arg=parameter[(i+1):]
                    break
            APTAB.append(arg)
            tempKP.append(kpstring)

        else:
            APTAB.append(lst[i])

    if kp1!=kp:
        for i in range(kpdtp,kp+kpdtp):
            if KPDTAB[i][0] not in tempKP:
                APTAB.append(KPDTAB[i][1])

    line=""
    if mdtp!=1:
        f5=open('MDT.txt','r')
        for i in range(1,mdtp):
            f5.readline()
        while f5:
            line=f5.readline()
            if("MEND" in line):
                break
            lst1=line.split()
            pass_2_print(lst1)
        f5.close()
    else:
        f5=open('MDT.txt','r')
        while f5:
            line=f5.readline()
            if("MEND" in line):
                break
            lst1=line.split()
            pass_2_print(lst1)
        f5.close()
    tempKP.clear()
    APTAB.clear()

#pass-2------------------------------------------------------------------------------------------------>
f3=open('Intermediate_code.txt','r')

for data in f3:
    flag=False
    lst=data.split()
    for i in range(0,len(MNT)):
        if lst[0]==MNT[i][0]:
            kp=MNT[i][2]
            kpdtp=MNT[i][4]
            mdtp=MNT[i][3]
            pass_2_oper(lst,kp,kpdtp,mdtp)
            flag=True
            break
    if flag==False:
        f4=open('Expanded_code.txt','a')
        f4.write(data)
        f4.close()
f3.close()
print("Output files of two pass macro are generated.")
print("Thank you!!")
