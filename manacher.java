package org.pankaj;

import com.google.common.collect.ForwardingMultiset;
import com.google.common.collect.HashMultiset;
import com.google.common.collect.Multiset;

import java.io.StringBufferInputStream;
import java.util.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main
{
    public static void main(String[] args) throws IOException
    {
        new Main().manacher("tcatacaxhd");
    }

    String manacher(String s){

        StringBuilder sb=new StringBuilder();
        sb.append('#');
        for(int i=0;i<s.length();++i){
            sb.append(s.charAt(i));
            sb.append('#');
        }
        String str= sb.toString();
        int[] manc=new int[str.length()];
        int l=0, r=0, c=0, len=0, max=0;

        for(int i=0;i<str.length();++i){
            if(i<r){
                int mirror=c-(i-c);
                len=Math.min(manc[mirror], r-i);
            }
            else {
                len=0;
            }
            while(i-len-1>=0 && i+len+1<str.length() && str.charAt(i-len-1)==str.charAt(i+len+1)){
                len++;
            }
            if(i+len>r){
                c=i;
                r=i+len;
                l=i-len;
            }
            manc[i]=len;
            max=Math.max(max, len);
        }

//        max palindrome
        for(int i=0;i<str.length();++i){
            if(manc[i]!=max){
                continue;
            }
            String ans="";

            len=0;

            int left=i/2-max/2;
            int right=i/2+max/2;
            if((max&1)>0){
                right++;
            }
            System.out.println(s.substring(left, right));
            return s.substring(left, right);
        }

        return "";

    }



}

