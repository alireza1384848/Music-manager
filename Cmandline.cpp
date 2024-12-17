#include "Cmandline.h"

Cmandline::Cmandline():playQueue(100)
{
	Musicians = new SparseSet(1000, 1000);
}
string* getText() {
	cout << "Enter Text:";
	int count = 0;
	string a;
	int countenter = 0;
	string m;
	m = getchar();
	while (1)
	{
		char in = getchar();
		if (in == '"')
		{
			countenter = 0;
			count++;
		}
		else if (count == 1 && in != '/' && in != '\n')
		{
			countenter = 0;
			a += in;
		}

		else if (count == 0 && in != '"' && in != '\n')
		{
			break;
		}
		else if (in == '\n')
		{
			countenter++;
			if (countenter == 2)
			{
				a += " ";
			}
			if (count > 1)
			{
				count = 0;
			}
			else if (countenter == 3) { cout<<endl << "!!End Text!!"<<endl; break; }
			else continue;
		}
	}	return new string(a);
}
string* Cmandline::getcommand()
{
	string* cmd = new string[3];
	cout<<endl << "Enter Your command:";
	cin >> cmd[0];
	//2
	if(cmd[0]=="delm"||cmd[0]=="delmp"|| cmd[0] == "addmp" || cmd[0] == "searchm")
	{
		std::cin >>cmd[1];
		cin>> cmd[2];
		return cmd;
	}
	
	
	//3
	else if (cmd[0] == "search" ||cmd[0]=="countw")
	{
		string temp = cmd[0];
		cmd = new string[4];
		cmd[0] = temp;
		cin >> cmd[1];//id
		cin >> cmd[2];//id
		cin >> cmd[3];
		return cmd;
	}
	
	
	//5
	else if (cmd[0] == "addms")
	{
		cmd = new string[5];
		cmd[0] = "addms";
		cin >> cmd[1];//name
		cin >> cmd[2];//year
		cmd[3] = *getText();
		cin >> cmd[4];
		return cmd;
	}
	//0
	else if(cmd[0] == "pop" || cmd[0] == "exit")
	{
		return cmd;
	}
	
	//1
	else {
		getline(std::cin, cmd[1]);
	//	getline(std::cin, cmd[2]);
		return cmd;
	}
}

void Cmandline::proccescommand()
{

	string* cmd = getcommand();
	if (cmd[0] == "adds")
	{
		try
		{
			string name = cmd[1];
			if (name != "") {
				Musicians->insert(name.substr(1));
				cout << "Successfully Added!"<< "  ID : "<<Musicians->lastid() << endl;
			}
			else
			{
				cout << "Enter Name!!" << endl;
			}

		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}

	}
	else if (cmd[0] == "dels")
	{
		try
		{
			string id = cmd[1].substr(1);
			int mainid = stoi(id);
			Musicians->erase(mainid);
			cout << "Successfully Deleted!" << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
	}
	else if (cmd[0] == "find")
	{
		try
		{
			string id = cmd[1].substr(1);
			int mainid = stoi(id);
			Musicians->search(mainid);
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
	}
	else if (cmd[0] == "prints")
	{
		Musicians->print();
	}
	else if (cmd[0] == "cls")
	{
		delete Musicians;
		Musicians = new SparseSet(1000, 1000);
		Musics.clear();
		AllPlaylist.clear();
		playQueue.clear();
		cout << "Successfully Cleared!" << endl;
	}
	else if (cmd[0] == "findm")
	{
		try
		{
			string name = cmd[1].substr(1);
			Musicians->findmusic(name);
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
	}
	else if (cmd[0] == "delm")
	{
		try
		{
			string artistid = cmd[1];
			string  musicid = cmd[2];
			int artid = stoi(artistid);
			int musid = stoi(musicid);
			Musicians->delmusic(artid, musid);
			Musics.erase(findMusicind(musid));
			for (size_t i = 0; i < AllPlaylist.size(); i++)
			{
				try
				{
					AllPlaylist[i]->erase(musid);
				}
				catch (const std::exception&)
				{
				}

			}
			cout << "Successfully Deleted!" << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
	}
	else if (cmd[0] == "addms")
	{
		try
		{
			string name = cmd[1];
			string text = cmd[3];
			string Sid = cmd[4];
			string  Syear = cmd[2].substr(1);
			int year = stoi(Syear);
			int id = stoi(Sid);
			Musics.push_back(Musicians->Addmusic(id, name, text, year));
			cout << "Successfully Added!"<<"  ID : "<<Musics.back()->id() << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:"<< e.what() << endl;
		}
	}
	else if (cmd[0] == "search")
	{
		try
		{
			string artistid = cmd[1];
			string  musicid = cmd[2];
			int artid = stoi(artistid);
			int musid = stoi(musicid);
			string word = cmd[3];
			Musicians-> findword(artid, musid,word);
			//cout << "Successfully Deleted!" << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
	}
	else if (cmd[0] == "countw")
	{
		try
		{
			string artistid = cmd[1];
			string  musicid = cmd[2];
			int artid = stoi(artistid);
			int musid = stoi(musicid);
			string word = cmd[3];
			Musicians->countword(artid, musid, word);
			//cout << "Successfully Deleted!" << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
		}
	else if (cmd[0] == "addp")
	{
		try
		{
			string name = cmd[1];
			if (name != "") {
				SparcePlaylist* temp = new SparcePlaylist(name);
				AllPlaylist.push_back(temp);
				cout << "Successfully Added!" << "  ID : " << AllPlaylist.back()->getid() << endl;
			}
			else
			{
				cout << "Enter a Name For Playlist!!"<<endl;
			}

		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong , tip:" << e.what() << endl;
		}
	
	}
	else if (cmd[0] == "addmp")
	{
		try
		{
			string musicid = cmd[1];
			string  playlistid = cmd[2];
			int musid = stoi(musicid);
			int playid = stoi(playlistid);
			AllPlaylist[findplayid(playid)]->insert(findMusic(musid));

			cout << "Successfully Added!" << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
	
	}
	else if (cmd[0] == "searchp")
	{
		try
		{
			string name = cmd[1];
			int id = stoi(name);
			findprintPL(id);
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong , tip:" << e.what() << endl;
		}

		}
	else if (cmd[0] == "searchm")
	{
		try
		{
			string Plid = cmd[1];
			string  Muid = cmd[2];
			int plid = stoi(Plid);
			int muid = stoi(Muid);
			AllPlaylist[findplayid(plid)]->search(muid);

		//	cout << "Successfully Found!" << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}

		}
	else if (cmd[0] == "delmp")
	{
		try
		{
			string plaid = cmd[1];
			string  musicid = cmd[2];
			int plid = stoi(plaid);
			int musid = stoi(musicid);
			AllPlaylist[findplayid(plid)]->erase(musid);
			cout << "Successfully Deleted!" << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
		}
	else if (cmd[0] == "showp")
		{
			try
			{
				string sid = cmd[1];
				int id = stoi(sid);
				AllPlaylist[findplayid(id)]->cpyset();
				AllPlaylist[findplayid(id)]->Quicksortinyear(0, AllPlaylist[findplayid(id)]->Size() - 1);
				cout << "****************************Playlist Info (sorted by Year)*****************************" << endl;
				AllPlaylist[findplayid(id)]->printsort();
				cout << endl;

			}
			catch (const std::exception& e)
			{
				cout << "Something went wrong tip:" << e.what() << endl;
			}

		}
	else if (cmd[0] == "addqp")
	{
		try
		{
			string sid = cmd[1];
			int id = stoi(sid);
			playQueue.inqueue(AllPlaylist[findplayid(id)]);
			cout << "successfuly added!!"<<endl;
			//playQueue.Front()->Print();
		}
		catch (const std::exception& e)
		{
			cout << "Something went wrong tip:" << e.what() << endl;
		}
		
		}
	else if (cmd[0] == "pop")
	{
		try
		{
		playQueue.dequeue();
//		playQueue.Front()->Print();
		}
		catch (const std::exception&e)
		{
			cout << "Error : " << e.what();
		}
	}
	else if (cmd[0] == "exit")
	{
		try
		{
			exit(0);
		}
		catch (const std::exception& e)
		{
			cout << "Error : " << e.what();
		}
		}
	else
	{
		cout << "Command Not Found!!"<<endl;
 }
}
//Todo: make it binery search
Music* Cmandline::findMusic(int id)
{
	for (int i = 0; i < Musics.size(); i++)
	{
		if(Musics[i]->id()==id)
		{
			return Musics[i];
		}

	}
	throw out_of_range("Music Can't found");
}
int Cmandline::findMusicind(int id)
{
	for (int i = 0; i < Musics.size(); i++)
	{
		if (Musics[i]->id() == id)
		{
			return i;
		}

	}
	throw out_of_range("Music Can't found");
}

void Cmandline::findprintPL(int id)
{
	int mid = 0;
	int left = 0;
	int right = AllPlaylist.size()-1;
	while (right>=left)
	{
		int mid = left + ((right - left) / 2);
		if (AllPlaylist[mid]->getid() == id)
		{
			AllPlaylist[mid]->Print();
			return;
		}
		else if(AllPlaylist[mid]->getid()> id)
		{
			right = mid - 1;
		}
		else
		{
			left = mid+1;
		}

	}
	throw overflow_error("Playlist Doesn't Exist");
}

int Cmandline::findplayid(int id)
{
	int mid = 0;
	int left = 0;
	int right = AllPlaylist.size() - 1;
	while (right >= left)
	{
		int mid = left + ((right - left) / 2);
		if (AllPlaylist[mid]->getid() == id)
		{
			return	mid;
		}
		else if (AllPlaylist[mid]->getid() > id)
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}

	}
	throw overflow_error("Playlist Doesn't Exist");

	return 0;
}
