package com.matlab;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;

public class ChangeFile02 {
	public static void main(String[] args) {
		File fread = new File("data.txt");
		File fwrite = new File("data4.txt");
		try{
			Reader reader = new FileReader(fread);
			Writer writer = new FileWriter(fwrite);
			BufferedReader bufferedReader = new BufferedReader(reader);
			BufferedWriter bufferedWriter = new BufferedWriter(writer);
			String str = null;
			while((str= bufferedReader.readLine())!=null) {
				
				StringBuilder date ;
				String year;
				String m = null;
				String hourString;
				int hourInt;
				
				//String s = "05/13/13 ����06ʱ33��52��";

				StringBuilder stringBuilder = new StringBuilder(str);
				date = stringBuilder.replace(2, 3, "-");
				date = stringBuilder.replace(5, 6, "-");
				System.out.println(date);
				m = stringBuilder.substring(9, 11); //��ȡ���硢����
				hourString = stringBuilder.substring(11,13);
				if(m.equals("����"))
				{
					
					  //��ȡʱ
					System.out.println(m);
					System.out.println(hourString);
					hourInt = Integer.valueOf(hourString);
					hourInt += 12;
					if(hourInt==24) {
					    //	hourInt = 0;
						hourString = "12"; 
					}
					/*else {
						hourString = String.valueOf(hourInt);
					}*/
					
				}
				else if(m.equals("����")) {
					if(hourString.equals("12"))
					{
						hourString =  "00";
					}
				}
				System.out.println(hourString);
				date = stringBuilder.replace(11, 13, hourString);
				date = stringBuilder.delete(9, 11);  //ɾ����������
				System.out.println(date);
				//date = stringBuilder.delete(9, 12);
				// ��ȡ����
				// 06תint
				//int+12
				//�滻hour
				// ɾ������
				System.out.println(date);
				date = stringBuilder.replace(11, 12, ":");  //�滻ʱ��:
				System.out.println(date);
				date = stringBuilder.replace(14, 15, ":");  //�滻����:
				System.out.println(date);
				date = stringBuilder.delete(17, 20);
				System.out.println(date);
				year = stringBuilder.substring(6, 8);
				year = "20"+year+"-";
		        System.out.println(year);
		        date = stringBuilder.insert(0, year);
		        System.out.println(date);
		        date = stringBuilder.delete(10, 13);
		        System.out.println(date);
		        //date = stringBuilder.delete(10, 11);
		        
		        
		        String dateString = date.toString();
		        bufferedWriter.write(dateString);
		        bufferedWriter.newLine();
			}
			bufferedReader.close();
			bufferedWriter.close();
			reader.close();
			writer.close();
			
		}catch(Exception e)
		{
			e.printStackTrace();
		}
	}

}
