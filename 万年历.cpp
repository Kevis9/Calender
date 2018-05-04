#include <stdio.h> 
#include <time.h>
  void begin(void); 
  
  void zhibiao(int year,int mon);
  
  int main(void) {
   	
  	int i,y,m,d,day;
  	char p,ch='a';  		
      time_t t;
      struct tm * lt;
      time (&t);
      lt = localtime (&t);
	  //lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec
	  y=lt->tm_year+1900;
	  m=lt->tm_mon+1;
	  day=lt->tm_mday;
      begin();
      while (ch!='Q'){
      zhibiao(y,m);
      for (i=1;i<=3;i++)
        printf("\n");
        printf("%68s","1.Input A for backwarding\n");
        printf("%67s","2.Input D for forwarding\n");
        printf("%100s","3.IF you want to search for a certain date,please input X\n");
        printf("%60s","4.press q to quit\n");
        scanf("%c",&p);        			
        switch(p){
        	case 'A': {
			          m--;
			          if(m==0)
					  {
			          	m=12;
			          	y--;
			          	zhibiao(y,m);
					  }
			          
				break;
			        }
		    case 'D' :{ 
		             m++;
		             if (m==13)
					 {
		               m=1;
					   y++;	
					   zhibiao(y,m);
					 }
				break;
			        }
	
		    case 'X': {   for(i=1;i<=5;i++)
		                printf("\n");
			           printf("%50s","Please input the year,date:");
		    	        scanf("%d %d",&y,&m);
		    	        zhibiao(y,m);
		    	        
		    	        
				break;
			        } 
			    
			case 'Q' : ch=p;
		}
		    for (i=1;i<=10;i++)
		       printf("\n");
		    	 
		}
     return 0;                        	
  }
   void begin(void){
   	 int i,y,m,d,day;
      time_t t;
      struct tm * lt;
      time (&t);
      lt = localtime (&t);
	  //lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec
	  y=lt->tm_year+1900;
	  m=lt->tm_mon+1;
	  day=lt->tm_mday;
	  
      for(i=0;i<5;i++)
        printf("\n");                              
                    
	  }
	  
	  
	  void zhibiao(int year,int mon){
	  	
	  	int a,b,c,y,w,initial,d1=1,dnum,n,in;
	  	printf("\n");
	  	printf("%57d/%d\n",year,mon);
	  	printf("\n%70s","Sun Mon Tue Wed Tur Fri Sat\n");
	  	if ((mon==1)||(mon==3)||(mon==5)||(mon==7)||(mon==8)||(mon==10)||(mon==12))
      	 dnum=31;
	  if ((mon==4)||(mon==6)||(mon==9)||(mon==11))
	     dnum=30;
	  if (mon==2){
	  	   //IF (year mod 4=0)and(year mod 100<>0)or(year mod 400=0) THEN dn:=29  ELSE dn:=28;
              if ((year%4==0)&&(year%100!=0)||(year%400==0))
                   dnum=29;
              else dnum=28;
			  }
     if (mon==1){
          year=year-1;
		  mon=13;
		  a=year/1000;
		  b=(year%1000) / 100;
		  c=a*10+b;
		  y=year-c*100;
		  w=(y+(y/4)+(c/4)-2*c+(26*(mon+1) /10+d1-1)) % 7;
		  if (w<0) 
		  	w=w+7;
		  	switch(w){
		  		case 0: initial=44;break;
		  		case 1: initial=48;break;
		  		case 2: initial=52;break;
		  		case 3: initial=56;break;
		  		case 4: initial=60;break;
		  		case 5: initial=64;break;
		  		case 6: initial=68;break;
		  		
		  		default:printf("ERROR\n");
			  }
		  
	     mon=1;
	     year++;
	 }
	 if (mon==2)
	 {
	   year=year-1;
	   mon=14;
	   a=year/1000;
		  b=(year%1000) / 100;
		  c=a*10+b;
		  y=year-c*100;
		  w=(y+(y/4)+(c/4)-2*c+(26*(mon+1) /10)+d1-1) % 7;
		  if(w<0)
		  w=w+7;
		  switch(w){
		  	    case 0: initial=44;break;
		  		case 1: initial=48;break;
		  		case 2: initial=52;break;
		  		case 3: initial=56;break;
		  		case 4: initial=60;break;
		  		case 5: initial=64;break;
		  		case 6: initial=68;break;
		  		default:printf("error");
		  }
		  mon=2;
		  year++;
 	 }
 	 if ((mon!=1)&&(mon!=2))
 	   {
 	   	a=year/1000;
		  b=(year%1000) / 100;
		  c=a*10+b;
		  y=year-c*100;
		  w=(y+(y/4)+(c/4)-2*c+(26*(mon+1) /10+d1-1)) % 7;
		  if (w<0)
		  	w=w+7;
		  	switch(w){
		  		case 0: initial=44;break; 
		  		case 1: initial=48;break;
		  		case 2: initial=52;break;
		  		case 3: initial=56;break;
		  		case 4: initial=60;break;
		  		case 5: initial=64;break;
		  		case 6: initial=68;break;
		  		default: printf("error");
		  	}
		}
		in=initial;
		for(n=1;n<=((((68-initial)/4))+1);n++)
		{   
		    printf("%*d",in,d1);
		    in=4;
		    d1++;
		}
		  printf("\n");
		  printf("\n");
		while (d1<dnum){
			n=1;
			initial=44;
			printf("%*d",initial,d1);
			initial=4;
			while (n<=6){
				d1++;
				if (d1>dnum)
				n=6;
				else printf("%*d",initial,d1);
				n++;
	     
			}
			 printf("\n");
		     printf("\n");
			d1++;
	
		}
}
    
	      
	     
 	  
   
