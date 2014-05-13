 t_0000001 = -1  
 output = t_0000001
 t_0000002 = i LT 9
 t_0000003 = j GT 8
 t_0000004 = k EQ 7
 t_0000005 = t_0000003 AND t_0000004  
 t_0000006 = t_0000002 OR t_0000005  
 IF FALSE t_0000006, goto L_0000007  
 output = 6
 L_0000007:  
 t_0000008 = i NE 5
 IF FALSE t_0000008, goto L_0000009  
 t_0000010 = j GE 4
 IF FALSE t_0000010, goto L_0000011  
 IF FALSE k, goto L_0000012  
 t_0000013 = output + 1  
 output = t_0000013
 L_0000012:  
 t_0000014 = output + 1  
 output = t_0000014
 L_0000011:  
 t_0000015 = output + 1  
 output = t_0000015
 L_0000009:  
 t_0000016 = output + 1  
 output = t_0000016


 