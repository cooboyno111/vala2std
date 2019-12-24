import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

public class ValaC2Std {
	public static String [] behaviors= {"#include <glib.h>","#include <glib-object.h>","!GLIB_CHECK_VERSION (2,35,0)","g_type_init ();","GType","g_renew (","g_new0 (","g_list_index","g_list_remove","static gchar* g_unichar_to_string","g_utf8_get_char"};
	public static String [] rbehaviors= {"#include \"glib.h\"","//#include <glib-object.h>","TRUE","setlocale(LC_CTYPE, \"\");","/*GType","g_renew (sizeof(","g_new0 (sizeof(","g_list_index","g_list_remove","/*static gchar* g_unichar_to_string","g_utf8_get_char"};
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Vector<String> CSSlines = readTxtFile(args[0]);
		//Vector<String> CSSlines = readTxtFile("/home/lup/桌面/GPG/GIO/clvala/clmap2.c");
		Vector<String> NCSSlines = new Vector<String>();
		int endline=-1;
		for (int i = 0; i < CSSlines.size(); i++) {
			String CSSline = CSSlines.elementAt(i);
			int bhindex=hasbehaviors(CSSline);
			if (bhindex!=-1) {
				String newline = CSSline.replace(behaviors[bhindex], rbehaviors[bhindex]);
				//g_renew,g_new0 需要在后面加sizeof问题
				if(bhindex==5||bhindex==6) {
					int firstdot=newline.indexOf(",");
					String head=newline.substring(0, firstdot);
					String nil=newline.substring(firstdot, newline.length());
					newline=head+")"+nil;
				}
				//处理"g_list_index","g_list_remove"需要在尾部根据输入参数判断是否string的问题
				if(bhindex==7||bhindex==8) {
					if(newline.indexOf("g_list_remove_link")==-1) {
					int last=newline.lastIndexOf(");");
					String head=newline.substring(0, last);
					if(newline.indexOf("gpointer")!=-1) {
						newline=head+",true);";
					}else {
						newline=head+",false);";
					}}
				}
				//屏蔽static gchar* g_unichar_to_string方法
				if(bhindex==9) {
					for (int k = i; k < CSSlines.size(); k++) {
						if(CSSlines.elementAt(k).indexOf("}")!=-1){
							if(CSSlines.elementAt(k).length()<=1) {
								endline=k;
								break;
							}
						}
					}
					System.out.println("endline="+endline);
				}
				//g_utf8_get_char方法体将+替换为,
				if(bhindex==10) {
					//System.out.println("newline========================="+newline);
					newline=newline.replace('+', ',');
					//System.out.println("newline========================="+newline);
				}
				//屏蔽GType方法
				if(bhindex==4) {
					if(newline.indexOf("G_GNUC_CONST")!=-1) {
						newline=newline+"*/";
					}else if(newline.indexOf(";")!=-1){
						newline=newline.replace("/*", "");
					}else {
						//寻找此行后面包含}的最短的行
						//int endline=-1;
						for (int k = i; k < CSSlines.size(); k++) {
							if(CSSlines.elementAt(k).indexOf("}")!=-1){
								if(CSSlines.elementAt(k).length()<=1) {
									endline=k;
									break;
								}
							}
						}
						System.out.println("endline="+endline);
					}
				}
				System.out.println(newline);
				NCSSlines.add(newline);
			} else {
				//System.out.println(CSSline);

				if(endline==i) {
					NCSSlines.add(CSSline+"*/");
				}else {
					NCSSlines.add(CSSline);
				}
			}
		}
		//wfile("/home/lup/桌面/GPG/GIO/clvala/clmap2-out.c",NCSSlines);
		wfile(args[1],NCSSlines);
	}
	public static int hasbehaviors(String str) {
		for(int i=0;i<behaviors.length;i++) {
			if(str.indexOf(behaviors[i])!=-1) {
				return i;
			}
		}
		return -1;
	}
	public static void wfile(String name,Vector<String> lines) {
		try {
			FileWriter writer = new FileWriter(name);
			BufferedWriter bw = new BufferedWriter(writer);
			for (int i = 0; i < lines.size(); i++) {
				String CSSline = lines.elementAt(i);
				bw.write(CSSline+"\r\n");
			}
			bw.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static Vector<String> readTxtFile(String filePath) {
		Vector<String> vs = new Vector<String>();
		try {

			String encoding = "UTF-8";
			File file = new File(filePath);
			if (file.isFile() && file.exists()) { // 判断文件是否存在
				InputStreamReader read = new InputStreamReader(new FileInputStream(file), encoding);// 考虑到编码格式
				BufferedReader bufferedReader = new BufferedReader(read);
				String lineTxt = null;
				while ((lineTxt = bufferedReader.readLine()) != null) {
					// System.out.println(lineTxt);
					//String nline = lineTxt.trim();
					String nline = lineTxt;
					vs.add(nline);
				}
				read.close();
			} else {
				System.out.println("找不到指定的文件");
			}
		} catch (Exception e) {
			System.out.println("读取文件内容出错");
			e.printStackTrace();
		}
		return vs;
	}
}
