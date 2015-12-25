/* +---------------------------------------------------------------------------+
   | File:myExceptions.h                                                       |
   | Authors:Ican chen  E-mail:chenmingjianwork@163.com                        |
   | Date:2015/12/22                                                           |
   | Describe: exception classes for various error types.                      |
  +---------------------------------------------------------------------------+ */
#ifndef _MYEXCEPTIONS_H_
#define _MYEXCEPTIONS_H_

class illegalParameterValue
{
	public:
		illegalParameterValue(string theMessage = "Illegal parameter value")
			{message = theMessage;}
		void outputMessage(){cout << message << endl;}
	private:
		string message;
};

class illegalIndex
{
	public:
		illegalIndex(string theMessage = "Illegal index")
			{message = theMessage;}
		void outputMessage(){cout << message << endl;}
	private:
		string message;
};


#endif