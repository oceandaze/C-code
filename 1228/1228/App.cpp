#include "stdafx.h"
#include "App.h"


App::App()
{
	pos = 0;
}


void App::run(LoadData * p)
{
	  if (p==nullptr)
	  {
		  return;
	  }
	  pos = p->read(stu);
	  if (pos==0)
	  {
		  return;
	  }
	  int total = 0;
	  for (int i=0;i<pos;++i)
	  {
		  total += stu[i].getAge();
		  cout << stu[i] << endl;
	  }

	  cout << "Æ½¾ùÄêÁä£º" << total / pos << endl;

}

