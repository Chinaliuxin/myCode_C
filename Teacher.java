package com.xmx.entity;

public class Teacher {
	private String Tno;//教师编号
	private String Tname;//教师姓名
	private String Tstatus;//教师是否负责人
	private String Tsort;//导员或者教师
	private String Tsex;//教师性别
	public String getTno() {
		return Tno;
	}
	public void setTno(String tno) {
		Tno = tno;
	}
	public String getTname() {
		return Tname;
	}
	public void setTname(String tname) {
		Tname = tname;
	}
	public String getTstatus() {
		return Tstatus;
	}
	public void setTstatus(String tstatus) {
		Tstatus = tstatus;
	}
	public String getTsort() {
		return Tsort;
	}
	public void setTsort(String tsort) {
		Tsort = tsort;
	}
	public String getTsex() {
		return Tsex;
	}
	public void setTsex(String tsex) {
		Tsex = tsex;
	}
	
	
}
