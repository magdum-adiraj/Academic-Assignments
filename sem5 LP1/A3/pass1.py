MNT=[]
KPDTAB=[]
PNTAB=[]
APTAB=[]
LC=1

def MNT_insert(lst):
    global LC
    pp=0
    kp=0
    kplen=len(KPDTAB)
    for i in range(1,len(lst)):
        if "=" in lst[i]:
            kp+=1
            parameter=lst[i]
            kpstring=""
            defaultval=""
            for i in range(0,len(parameter)-1):
                kpstring+=parameter[i]
                if(parameter[i+1]=="="):
                    defaultval+=parameter[(i+2):]
                    break
            PNTAB.append(kpstring)
            KPDTAB.append([kpstring,defaultval])
        else:
            pp+=1
            PNTAB.append(lst[i])

    MNT.append([lst[0],pp,kp,LC,kplen])

def PNTAB_search(operand):
    for i in range(0,len(PNTAB)):
        index=-1
        if operand in PNTAB[i]:
            index=i
            break
    return index

def MDT_insert(lst):
    global LC
    f2=open('MDT1.txt','a')
    for i in range(0,len(lst)):
        index1=PNTAB_search(lst[i])
        if(index1!=-1):
            f2.write(f"(P,{index1}) ")
        else:
            f2.write(f"{lst[i]} ")
    f2.write("\n")
    f2.close()
    LC+=1

f=open('text.txt','r')
while True:
    line=f.readline()
    if "MACRO" in line:
        line=f.readline()
        lst=line.split()
        MNT_insert(lst)
        while("MEND" not in line):
            line=f.readline()
            lst=line.split()
            MDT_insert(lst)
        PNTAB.clear()
    else:
        f1=open('intermediate_code.txt','a')
        f1.write(line)
        line=f.readline()
        f1.write(line)
        f1.close()
    if not line:
        break
f.close()

f3=open('MNT1.txt','a')
f3.write("NAME   PP   KP   MDTP   KPDTP")
for i in range(0,len(MNT)):
    f3.write(f"\n{MNT[i][0]}   {MNT[i][1]}   {MNT[i][2]}   {MNT[i][3]}   {MNT[i][4]}   ")
f3.close()