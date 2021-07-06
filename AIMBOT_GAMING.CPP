#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<iomanip.h>
#include<time.h>
#include<dos.h>
#include<conio.h>
int flag=0;
class aimbot
{
 int mch1,mch2,gch1,gch2,mttime,gttime,m_id,id,check,f;
 float mprice,gprice;
 char mname[50],gname[50],mgame[24],ggame[24],mpackage[30],gpackage[30],usr_id[50];
 public:
 void menter();
 void mprint();
 void mfiles();
 void genter();
 void gprint();
 void gfiles();
 void mstatus();
 void msprint();
 void gstatus();
 void gsprint();
 void addmember();
 void list();
 int compare(int i_d);
 void m_remove();
}m,g;
void aimbot::m_remove()
{
 int i_d;
 clrscr();
 ifstream fio("list.dat",ios::in);
 ofstream file("temp.dat",ios::out|ios::app);
 int rno,found=0;
 cout<<"\n\t\t\tA_I_M_B_O_T::G_A_M_I_N_G\n\n";
 cout<<"\n\n\n\t\t\tENTER THE ID NO OF MEMBER TO BE DELETED: ";
 cin>>i_d;
 while(!fio.eof())
 {
  fio.read((char*)&m,sizeof(m));
  if(m.m_id==i_d)
  {
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n\n";
   cout<<"\n\n\t\t\t        RECORD DELETED...\n\n\t\t\t  <PRESS ANY KEY TO CONTINUE>";
   found=1;
  }
  else
  file.write((char*)&m,sizeof(m));
 }
 if(found==0)
 {
  clrscr();
  cout<<"\n\t\t\tA_I_M_B_O_T::G_A_M_I_N_G\n\n";
  cout<<"\n\n\n\t\t\tRECORD NOT FOUND!!\n\n\t\t\t<PRESS ANY KEY TO CONTINUE>";
 }
 fio.close();
 file.close();
 remove("list.dat");
 rename("temp.dat","list.dat");
 getch();
}
int aimbot::compare(int i_d)
{
 ifstream in;
 in.open("list.dat",ios::in|ios::binary);
 in.seekg(0,ios::end);
 int size=in.tellg();
 int no=size/sizeof(m);
 int i=0,a;
 in.seekg(0);
 while(!in.eof()&&(i<no))
 {
  in.read((char *)&m,sizeof(m));
  if(i_d==m.m_id)
  {
   strcpy(m.mname,m.usr_id);
   a=1;
   check=1;
   break;
  }
  i++;
 }
 in.close();
 return a;
}
int pass()
{
 clrscr();
 char c[5];
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n\n";
 if(flag!=0)
 cout<<"\n\t\t   HINT: CONVERT THE DECIMAL '5' INTO BINARY";
 cout<<"\n\n\n\t\t\t    ENTER THE 4-DIGIT PIN\n\t\t\t           ";
 for(int i=0;i<4;i++)
 {
  flag=i;
  c[i]=getch();
  cout<<" *";
 }
 c[i]='\0';
 if(strcmp(c,"0101")==0)
 return 1;
 else
 return 0;
}
void aimbot::list()
{
 cout<<"\n\t\t\t    A_I_M_B_O_T::G_A_M_I_N_G\n\n";
 cout<<"\n\t\t\t\t ***************\n\t\t\t\t  MEMBER'S LIST\n\t\t\t\t ***************\n";
 cout<<"\n\t\t\t ID-NO\t\t\t    NAME\n\t\t\t*******\t\t\t   ******\n\n";
 ifstream in;
 in.open("list.dat",ios::in|ios::binary);
 in.seekg(0,ios::end);
 int size=in.tellg();
 int no=size/sizeof(m);
 int i=0;
 in.seekg(0);
 while(!in.eof()&&(i<no))
 {
  in.read((char *)&m,sizeof(m));
  cout<<"\t\t\t "<<m.m_id<<"\t\t\t    "<<m.usr_id<<"\n";
  i++;
 }
 cout<<"\n\n\t\t\t    <PRESS ANY KEY TO GO BACK>";
 in.close();
 getch();
}
void aimbot::addmember()
{
 ofstream out;
 out.open("list.dat",ios::out|ios::binary|ios::app);
 cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n";
 cout<<"\n\n\n\n\t\t\t   ENTER THE MEMBER-ID: ";
 cin>>m.m_id;
 cout<<"\n\n\t\t\t ENTER THE NAME OF NEW MEMBER: ";
 gets(m.usr_id);
 out.write((char*)&m,sizeof(m));
 clrscr();
 cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n";
 cout<<"\t\t\t       NEW MEMBER ADDED";
 cout<<"\n\n\n\t\t         <PRESS ANY KEY TO CONTINUE>\n";
 out.close();
 getch();
}
void aimbot::mstatus()
{
 cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n";
 cout<<"*****************\n MEMBER'S STATUS\n*****************\n\n";
 ifstream in;
 in.open("member.dat");
 in.seekg(0,ios::end);
 int size=in.tellg();
 int no=size/sizeof(m);
 int i=0;
 in.seekg(0);
 while(!in.eof()&&(i<no))
 {
  in.read((char *)&m,sizeof(m));
  m.msprint();
  i++;
 }
 in.close();
 cout<<"\n\n\n\n\t\t\t  <PRESS ANY KEY TO GO BACK>";
}
void aimbot::msprint()
{
 cout<<"\nNAME: "<<mname<<"    GAME: "<<mgame<<"    PACKAGE: "<<mpackage<<"    TOTAL PRICE: "<<mprice<<"\n";
}
void aimbot::gstatus()
{
 cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n";
 cout<<"****************\n GUEST'S STATUS\n****************\n\n";
 ifstream in;
 in.open("guest.dat");
 in.seekg(0,ios::end);
 int size=in.tellg();
 int no=size/sizeof(g);
 int i=0;
 in.seekg(0);
 while(!in.eof()&&(i<no))
 {
  in.read((char *)&g,sizeof(g));
  g.gsprint();
  i++;
 }
 in.close();
 cout<<"\n\n\n\n\t\t\t  <PRESS ANY KEY TO GO BACK>";
 getch();
}
void aimbot::gsprint()
{
 cout<<"\nNAME: "<<gname<<"    GAME: "<<ggame<<"    PACKAGE: "<<gpackage<<"    TOTAL PRICE: "<<gprice<<"\n";
}
void aimbot::menter()
{
 do
 {
  clrscr();
  cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n";
  cout<<"\t\t     PLEASE ENTER THE FOLLOWING DETAILS:\n";
  cout<<"\n\n\t\t\t  SELECT THE REQUIRED GAME:\n"
      <<"\n\t\t\t      <1>   NFS"
      <<"\n\t\t\t      <2>   GTA"
      <<"\n\t\t\t      <3>   PUBG"
      <<"\n\t\t\t      <4>   COD"
      <<"\n\t\t\t      <5>   Delta Force"
      <<"\n\t\t\t      <6>   Max Payne"
      <<"\n\t\t\t      <7>   CS:GO"
      <<"\n\t\t\t      <8>   Cyber Punk"
      <<"\n\t\t\t      <9>   Warframe"
      <<"\n\t\t\t      <10>  Fortnite"
      <<"\n\t\t\t      <11>  Mafia III"
      <<"\n\t\t\t      <12>  FIFA 2020"
      <<"\n\n\t\t\t    ENTER YOUR CHOICE: ";
  cin>>mch1;
  switch(mch1)
  {
   case 1:
   strcpy(mgame,"NFS");
   break;
   case 2:
   strcpy(mgame,"GTA");
   break;
   case 3:
   strcpy(mgame,"PUBG");
   break;
   case 4:
   strcpy(mgame,"COD");
   break;
   case 5:
   strcpy(mgame,"Delta Force");
   break;
   case 6:
   strcpy(mgame,"Max Payne");
   break;
   case 7:
   strcpy(mgame,"CS:GO");
   break;
   case 8:
   strcpy(mgame,"Cyber Punk");
   break;
   case 9:
   strcpy(mgame,"Warframe");
   break;
   case 10:
   strcpy(mgame,"Fortnite");
   break;
   case 11:
   strcpy(mgame,"Mafia III");
   break;
   case 12:
   strcpy(mgame,"FIFA 2020");
   break;
   default:
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
   cout<<"\n\n\n\n\n\n\t\t\t         WRONG CHOICE!!\n\n\t\t          <PRESS ANY KEY TO TRY AGAIN>";
   getch();
  }
 }while(mch1>12||mch1<1);
 clrscr();
 cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\t     ENTER TIME<in hours>: ";
 cin>>mttime;
 do
 {
  clrscr();
  cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n";
  cout<<"\t\t\t SELECT THE REQUIRED PACKAGE:";
  cout<<"\n\n\t\t\t      <1>  BASIC\n\n\t\t\t      <2>  NORMAL\n\n\t\t\t      <3>  PREMIUM";
  cout<<"\n\n\t\t\t    ENTER YOUR CHOICE: ";
  cin>>mch2;
  switch(mch2)
  {
   case 1:
   strcpy(mpackage,"Basic");
   mprice=50*mttime;
   break;
   case 2:
   strcpy(mpackage,"Normal");
   mprice=100*mttime;
   break;
   case 3:
   strcpy(mpackage,"Premium");
   mprice=150*mttime;
   break;
   default:
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
   cout<<"\n\n\n\n\n\n\t\t\t         WRONG CHOICE!!\n\n\t\t          <PRESS ANY KEY TO TRY AGAIN>";
   getch();
  }
 }while(mch2>3||mch2<1);
}
void aimbot::mprint()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\t       **************\n\t\t\t        BILL RECEIPT\n\t\t\t       **************\n";
 cout<<"................................................................................";
 cout<<"\n\t\t\tNAME          :    "<<mname<<"\n";
 cout<<"\t\t\tGAME          :    "<<mgame<<"\n";
 cout<<"\t\t\tPACKAGE       :    "<<mpackage<<"\n";
 cout<<"\t\t\t"<<"TOTAL PRICE   :    "<<mprice<<"\n";
 cout<<"\n\n\t\t\tTHANK YOU AND VISIT US AGAIN\n";
 cout<<"................................................................................";
 cout<<"\n\n\t\t\t<PRESS ANY KEY TO CONTINUE>";
 getch();
}
void aimbot::mfiles()
{
  clrscr();
  int l=0;
  cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
  cout<<"\n\n\n\n\n\t\t\t      ENTER YOUR ID: ";
  cin>>m_id;
  l=compare(m_id);
  if(l==1)
  {
   if(check==1)
   {
    fstream file;
    file.open("member.dat",ios::in|ios::out|ios::binary|ios::app);
    m.menter();
    file.write((char*)&m,sizeof(m));
    clrscr();
    cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
    cout<<"\n\n\n\n\n\n\t\t      <PRESS ANY KEY TO PROCESS THE BILL>\n";
    getch();
    file.read((char*)&m,sizeof(m));
    m.mprint();
    file.close();
   }
  }
  else
  {
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
   cout<<"\n\n\n\n\n\n\t\t\t        MEMBER NOT FOUND\n\n\t\t          <PRESS ANY KEY TO TRY AGAIN>";
  }
  getch();
}
void aimbot::genter()
{
  cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n";
  cout<<"\n\t\t\t       ENTER YOUR NAME: ";
  gets(gname);
 do
 {
  clrscr();
  cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n";
  cout<<"\t\t     PLEASE ENTER THE FOLLOWING DETAILS:\n";
  cout<<"\n\n\t\t\t  SELECT THE REQUIRED GAME:\n"
      <<"\n\t\t\t      <1>   NFS"
      <<"\n\t\t\t      <2>   GTA"
      <<"\n\t\t\t      <3>   PUBG"
      <<"\n\t\t\t      <4>   COD"
      <<"\n\t\t\t      <5>   Delta Force"
      <<"\n\t\t\t      <6>   Max Payne"
      <<"\n\t\t\t      <7>   CS:GO"
      <<"\n\t\t\t      <8>   Cyber Punk"
      <<"\n\t\t\t      <9>   Warframe"
      <<"\n\t\t\t      <10>  Fortnite"
      <<"\n\t\t\t      <11>  Mafia III"
      <<"\n\t\t\t      <12>  FIFA 2020"
      <<"\n\n\t\t\t    ENTER YOUR CHOICE: ";
  cin>>gch1;
  switch(gch1)
  {
   case 1:
   strcpy(ggame,"NFS");
   break;
   case 2:
   strcpy(ggame,"GTA");
   break;
   case 3:
   strcpy(ggame,"PUBG");
   break;
   case 4:
   strcpy(ggame,"COD");
   break;
   case 5:
   strcpy(ggame,"Delta Force");
   break;
   case 6:
   strcpy(ggame,"Max Payne");
   break;
   case 7:
   strcpy(ggame,"CS:GO");
   break;
   case 8:
   strcpy(ggame,"Cyber Punk");
   break;
   case 9:
   strcpy(ggame,"Warframe");
   break;
   case 10:
   strcpy(ggame,"Fortnite");
   break;
   case 11:
   strcpy(ggame,"Mafia III");
   break;
   case 12:
   strcpy(ggame,"FIFA 2020");
   break;
   default:
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
   cout<<"\n\n\n\n\n\n\t\t\t         WRONG CHOICE!!\n\n\t\t          <PRESS ANY KEY TO TRY AGAIN>";
   getch();
  }
 }while(gch1>12||gch1<1);
 clrscr();
 cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\t     ENTER TIME<in hours>: ";
 cin>>gttime;
 do
 {
  clrscr();
  cout<<"\n\t\t\t  A_I_M_B_O_T::G_A_M_I_N_G\n\n\n\n";
  cout<<"\t\t\t SELECT THE REQUIRED PACKAGE:";
  cout<<"\n\n\t\t\t      <1>  BASIC\n\n\t\t\t      <2>  NORMAL\n\n\t\t\t      <3>  PREMIUM";
  cout<<"\n\n\t\t\t    ENTER YOUR CHOICE: ";
  cin>>gch2;
  switch(gch2)
  {
   case 1:
   strcpy(gpackage,"Basic");
   gprice=75*gttime;
   break;
   case 2:
   strcpy(gpackage,"Normal");
   gprice=150*gttime;
   break;
   case 3:
   strcpy(gpackage,"Premium");
   gprice=200*gttime;
   break;
   default:
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
   cout<<"\n\n\n\n\n\n\t\t\t         WRONG CHOICE!!\n\n\t\t          <PRESS ANY KEY TO TRY AGAIN>";
   getch();
  }
 }while(gch2>3||gch2<1);
 clrscr();
}
void aimbot::gprint()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\t       **************\n\t\t\t        BILL RECEIPT\n\t\t\t       **************\n";
 cout<<"................................................................................";
 cout<<"\n\t\t\tNAME          :    "<<gname<<"\n";
 cout<<"\t\t\tGAME          :    "<<ggame<<"\n";
 cout<<"\t\t\tPACKAGE       :    "<<gpackage<<"\n";
 cout<<"\t\t\t"<<"TOTAL PRICE   :    "<<gprice<<"\n";
 cout<<"\n\n\t\t\tTHANK YOU AND VISIT US AGAIN\n";
 cout<<"................................................................................";
 cout<<"\n\n\t\t\t<PRESS ANY KEY TO CONTINUE>";
 getch();
}
void aimbot::gfiles()
{
 fstream file;
 file.open("guest.dat",ios::in|ios::out|ios::binary|ios::app);
 g.genter();
 file.write((char*)&g,sizeof(g));
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t      <PRESS ANY KEY TO PROCESS THE BILL>\n";
 getch();
 file.read((char*)&g,sizeof(g));
 g.gprint();
 file.close();
}
void intro()
{
 clrscr();
 cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t   ++++++++++++++++++++++++++\n\t\t\t    WELCOME TO AIMBOT GAMING \n\t\t\t   ++++++++++++++++++++++++++";
 cout<<"\n\t\t\t    <PRESS ANY KEY TO BEGIN>";
 getch();
}
void about_us()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\t\t\t    AIBOT GAMING BY GROUP-5\n\n\t\t\t        ***************\n\t\t\t         GROUP MEMBERS\n\t\t\t        ***************\n\n\t\t\t    <1>   ASHIQUE MUHAMMED JAILANI\n\n\t\t\t    <2>   JITHIN JOHN\n\n\t\t\t    <3>   JOSEPH JOY\n\n\t\t\t    <4>   REENPHY GEORGE\n\n\t\t\t    <5>   RYAN ROY";
 cout<<"\n\n\n\t\t\t   <PRESS ANY KEY TO CONTINUE>";
 getch();
}
void thanks()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\tTHANK YOU FOR USING OUR SERVICES";
 cout<<"\n\n\n\t\t\t    <PRESS ANY KEY TO QUIT>";
 getch();
}
void wrong_choice()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\t         WRONG CHOICE!!\n\n\t\t          <PRESS ANY KEY TO TRY AGAIN>";
 getch();
}
void pkg_info()
{
 int choice2;
 do
 {
  clrscr();
  cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G\n\n\n";
  cout<<"\n\n\n\t\t\t       **************\n\t\t\t        PACKAGE INFO\n\t\t\t       **************";
  cout<<"\n\n\t\t\t       <1>   BASIC\n\n\t\t\t       <2>   NORMAL\n\n\t\t\t       <3>   PREMIUM\n\n\t\t\t       <4>   BACK";
  cout<<"\n\n\n\t\t\t      ENTER YOUR CHOICE: ";
  cin>>choice2;
  switch(choice2)
  {
   case 1:
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G\n\n\n";
   cout<<"\t\t\t\t  *******\n\t\t\t\t   BASIC\n\t\t\t\t  *******";
   cout<<"\n\n\n\t\t\t PROCESSOR:  AMD Sempron 145\n\n\t\t\t NO: OF CORES:  2\n\n\t\t\t THREADS:  4\n\n\t\t\t MAX TURBO FREQUENCY:  1.20 GHz\n\n\t\t\t GRAPHIC CARD:  Nvidia GT 710\n\n\t\t\t RAM:  4GB";
   cout<<"\n\n\n RATE PER HOUR:\t\t FOR MEMBERS: RS 50\t\t  FOR OTHERS: RS 75";
   cout<<"\n\n\t\t\t<PRESS ANY KEY TO GO BACK>";
   getch();
   break;
   case 2:
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G\n\n\n";
   cout<<"\t\t\t\t  ********\n\t\t\t\t   NORMAL\n\t\t\t\t  ********";
   cout<<"\n\n\n\t\t\t PROCESSOR:  AMD Athlon 4223\n\n\t\t\t NO: OF CORES:  8\n\n\t\t\t THREADS:  16\n\n\t\t\t MAX TURBO FREQUENCY:  3.26 GHz\n\n\t\t\t GRAPHIC CARD:  Nvidia GTX 1050\n\n\t\t\t RAM:  8GB";
   cout<<"\n\n\n RATE PER HOUR:\t\t FOR MEMBERS: RS 100\t\t  FOR OTHERS: RS 150";
   cout<<"\n\n\t\t\t<PRESS ANY KEY TO GO BACK>";
   getch();
   break;
   case 3:
   clrscr();
   cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G\n\n\n";
   cout<<"\t\t\t\t  *********\n\t\t\t\t   PREMIUM\n\t\t\t\t  *********";
   cout<<"\n\n\n\t\t\t PROCESSOR:  AMD Ryzen Threadripper 2990WX\n\n\t\t\t NO: OF CORES:  32\n\n\t\t\t THREADS:  64\n\n\t\t\t MAX TURBO FREQUENCY:  4.60 GHz\n\n\t\t\t GRAPHIC CARD:  Nvidia GTX 1080 Ti\n\n\t\t\t RAM:  32GB";
   cout<<"\n\n\n RATE PER HOUR:\t\t FOR MEMBERS: RS 150\t\t  FOR OTHERS: RS 200";
   cout<<"\n\n\t\t\t<PRESS ANY KEY TO GO BACK>";
   getch();
   break;
   case 4:
   break;
   default:
   wrong_choice();
  }
 }while(choice2!=4);
}
void main_menu()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\t\t\t\t***********\n\t\t\t\t MAIN MENU\n\t\t\t\t***********\n"
     <<"\n\n\t\t\t\t<1>   ADMIN\n\n\t\t\t\t<2>   MEMBER\n\n\t\t\t\t<3>   GUEST\n\n\t\t\t\t<4>   PACKAGE INFO\n\n\t\t\t\t<5>   ABOUT US\n\n\t\t\t\t<6>   QUIT"
     <<"\n\n\n\t\t\t       SELECT YOUR CHOICE: ";
}
void admin()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\t\t\t\t    *******\n\t\t\t\t     ADMIN\n\t\t\t\t    *******\n\n\n\t\t\t\t<1>   STATUS\n\n\t\t\t\t<2>   ADD MEMBERS\n\n\t\t\t\t<3>   LIST MEMBER\n\n\t\t\t\t<4>   REMOVE MEMBERS\n\n\t\t\t\t<5>   BACK TO MAIN MENU";
 cout<<"\n\n\n\t\t\t          SELECT YOUR CHOICE: ";
}
void status()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\t\t\t\t   ********\n\t\t\t\t    STATUS\n\t\t\t\t   ********\n\n\n\t\t\t\t<1>   MEMBERS\n\n\t\t\t\t<2>   GUEST\n\n\t\t\t\t<3>   BACK"
     <<"\n\n\n\t\t\t      SELECT YOUR CHOICE: ";
}
void access_granted()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\t\tACCESS GRANTED\n\n\t\t\t  <PRESS ANY KEY TO CONTINUE>";
 getch();
}
void access_denied()
{
 clrscr();
 cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
 cout<<"\n\n\n\n\n\n\t\t\t\tACCESS DENIED\n\n\n\t\t    <PRESS ANY KEY TO GO BACK TO MAIN MENU>";
 getch();
}
void main()
{
 clrscr();
 int ch1,ch2,ch3,flag;
 aimbot a;
 intro();
 do
 {
  main_menu();
  cin>>ch1;
  clrscr();
  switch(ch1)
  {
   case 1:
   for(int j=4;j>0;j--)
   {
    if(pass()==1)
    {
     access_granted();
     do
     {
      admin();
      cin>>ch2;
      switch(ch2)
      {
       case 1:
       do
       {
	status();
	cin>>ch3;
	switch(ch3)
	{
	 case 1:
	 clrscr();
	 a.mstatus();
	 getch();
	 break;
	 case 2:
	 clrscr();
	 a.gstatus();
	 break;
	 case 3:
	 break;
	 default:
	 wrong_choice();
	}
       }while(ch3!=3);
       break;
       case 2:
       clrscr();
       a.addmember();
       break;
       case 3:
       clrscr();
       a.list();
       break;
       case 4:
       a.m_remove();
       break;
       case 5:
       flag=1;
       break;
       default:
       wrong_choice();
      }
     }while(ch2!=5);
    }
    else
    {
     for(int i=10;i>0;i--)
     {
      if(j==1)
      break;
      clrscr();
      cout<<"\n\t\t\t   A_I_M_B_O_T::G_A_M_I_N_G";
      cout<<"\n\n\n\n\n\n\t\t\t\t  WRONG PIN!!"
	  <<"\n\n\t\t\t      TRY AGAIN IN "
	  <<i<<" sec";
      cout<<"\n\n\t\t\t   NUMBER OF ATTEMPS LEFT: "<<j-1;
      delay(1000);
     }
    }
    if(j==1)
    {
     access_denied();
    }
    if(flag==1)
    break;
   }
   break;
   case 2:
   aimbot m;
   m.mfiles();
   break;
   case 3:
   aimbot gt;
   gt.gfiles();
   break;
   case 4:
   pkg_info();
   break;
   case 5:
   about_us();
   break;
   case 6:
   thanks();
   break;
   default:
   wrong_choice();
  }
 }while(ch1!=6);
}