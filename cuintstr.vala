const int DEFAULT_CAPACITY=50;
struct intstr
{
	public uint hash;
	public string data;
}
struct intstrmap
{
public int mListPos;
public intstr[] mListData;

public intstrmap()
{
	this.mListPos=0;
        this.mListData=new intstr[DEFAULT_CAPACITY];
}
void ensureCapa(){
      int capalen=this.mListData.length*2;
      this.mListData.resize(capalen);      
}
void add(uint ukey,string val){
     if((this.mListPos+1)>this.mListData.length){
        this.ensureCapa();
     }
     intstr isns = intstr();
     isns.hash=ukey;
     isns.data=val;
     this.mListData[this.mListPos]=isns;
     this.mListPos++;
}
int index(uint ukey){
	 for (int i = 0; i < this.mListPos; i++) {
             intstr kh = this.mListData[i];
	     if (kh.hash==ukey) {
	       return i;
             }
	 }
         return -1;
}
public void setkv(uint ukey,string val){
     int index=this.index(ukey);
     if(index==-1){
        this.add(ukey,val);
     }else{
        this.mListData[index].data=val;
     }
}
public void print(){
    stdout.printf ("len=%d\n",this.mListPos);
    for (int i = 0; i < this.mListPos; i++) {
	string data=this.mListData[i].data;
	uint hs=this.mListData[i].hash;
	stdout.printf("iskv:%s|%u\n", data,hs);
    }
}
public string getkv(uint ukey){
     int index=this.index(ukey);
     if(index==-1){
        return null;
     }else{
        return this.mListData[index].data;
     }
}
public void delkv(uint ukey){
this.mListPos--;
int index=this.index(ukey);
if(index!=-1){
    intstr[] nlists=new intstr[this.mListPos];
    for (int i = 0; i < this.mListPos; i++) {
       if(i==index){
          nlists[i]=this.mListData[i+1];
        }else if (i<index){
          nlists[i]=this.mListData[i];
        }else{
          nlists[i]=this.mListData[i+1];
        }
    }
    for (int i = 0; i < this.mListPos; i++) {
	this.mListData[i]=nlists[i];
    }
}
}
}
void main () {
intstrmap mp=intstrmap();
for(int i=0;i<100;i++){
            string sout = @"$i";
	    mp.setkv((uint)i,sout);
}
mp.print();
mp.delkv((uint)5);
mp.setkv((uint)5,"good");
mp.print();
	for(int i=0;i<100;i++){
	    string s= mp.getkv((uint)i);
	stdout.printf("get:%s\n",s);
	}
}
