#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num_process,quantum;
	cout<<"Enter number of process: ";
	cin>>num_process;
	cout<<"Enter the time quantum: ";
	cin>>quantum;
	cout<<endl<<endl;
	vector<pair<int,pair<int,int> > >vect;
	int priority[num_process],burst[num_process],arrival[num_process];
	for(int i=0;i<num_process;i++)
	{
		cout<<"Enter the priority of P"<<i+1<<" : ";
		cin>>priority[i];
		cout<<"Enter the burst time of P"<<i+1<<" : ";
		cin>>burst[i];
		cout<<"Enter the arrival time of P"<<i+1<<" : ";
		cin>>arrival[i];
		vect.push_back(make_pair(arrival[i],make_pair(burst[i],priority[i])));
		cout<<endl;
	}
	vect.push_back( make_pair ( 0 , make_pair (10000,10000) ) );
	int time=0,last=-1;
	for(time=quantum;time>-10000;time=time+quantum)
	{
		cout<<time<<endl;
	    vector < pair < pair < int , int > , pair < int , int > > > sect;
	    for(int i=0;i<vect.size()-1;i++)
	    {
	        if(vect[i].first>=0&&vect[i].first<=time&&vect[i].second.first!=0&&i!=last)
	        {
	            sect.push_back(make_pair(make_pair(i,vect[i].first),make_pair(vect[i].second.first,vect[i].second.second)));
	        }
	        if(sect.size()==0&&last!=-1&&vect[last].second.first!=0)
	        {
	        	sect.push_back(make_pair(make_pair(last,vect[last].first),make_pair(vect[last].second.first,vect[last].second.second)));
			}
			if(sect.size()==0)
			{
				sect.push_back(make_pair(make_pair(num_process,vect[num_process].first),make_pair(vect[num_process].second.first,vect[num_process].second.second)));
			}
	    }
	    int maxpri=10001,maxpri_ind;
	    for(int i=0;i<sect.size();i++)
	    {
	        if(sect[i].second.second<maxpri)
	        {
	            maxpri=sect[i].second.second;
	            maxpri_ind=i;
	        }
	    }
	    if(vect[sect[maxpri_ind].first.first].second.first>quantum&&maxpri_ind!=num_process)
	    vect[sect[maxpri_ind].first.first].second.first=vect[sect[maxpri_ind].first.first].second.first-quantum;
	    else if(maxpri_ind!=num_process)
	    {
	        time=time-vect[sect[maxpri_ind].first.first].second.first;
	        vect[sect[maxpri_ind].first.first].second.first=0;
	    }
	    else
	    time=time-quantum+1;
	    last=sect[maxpri_ind].first.first;
	    for(int i=0;i<num_process;i++)
		{
	    	cout<<vect[i].first<<" "<<vect[i].second.first<<" "<<vect[i].second.second<<endl;
		}
		cout<<endl;
		int check=0;
		for(int x1=0;x1<num_process;x1++)
		{
			if(vect[x1].second.first==0)
			check++;
		}
		if(check==num_process)
		break;
	}
	return 0;
}

