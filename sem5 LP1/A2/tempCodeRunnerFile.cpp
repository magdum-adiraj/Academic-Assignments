		else if(label != "NAN")
		{
			if(presentST(label))
			{
				ST[getSymID(label)].addr = to_string(LC);
			}
			else
			{
				ST[scnt].no = scnt + 1;
				ST[scnt].sname = label;
				ST[scnt].addr = to_string(LC);
				scnt++;
			}
		}