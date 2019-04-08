#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

 class Building
 {
 	 private:
 	 int mLength;
     int mWidth;
     int mLotLength;
     int mLotWidth;

 	public:
     //setter functions
     void setLength(int length){
        mLength=length;
    }

    void setWidth(int width){
        mWidth=width;
    }

    void setLotLength(int lotLength){
        mLotLength=lotLength;
    }

    void setLotWidth(int lotWidth){
        mLotWidth=lotWidth;
    }

 	//constructor

 	Building(){
 	}
     Building(int length,int width,int lotLength,int lotWidth){
        setLength(length);
        setWidth(width);
        setLotLength(lotLength);
        setLotWidth(lotWidth);
    }

    //getter functions
    int getLength(){
        return mLength;
    }

    int getWidth(){
        return mWidth;
    }

    int getLotLength(){
        return mLotLength;
    }

    int getLotWidth(){
        return mLotWidth;
    }
    
    //destructor
    ~Building(){

    }

    protected:
    //building area
     int calcBuildingArea(){
        return mLength*mWidth;
    }

    //lot area
    int calcLotArea(){
        return mLotLength*mLotWidth;
    }
    
};



class Office: public Building{

    private:
    string mBusinessName;
    int mParkingSpaces;
   	static int sTotalOffices;
   	int index;

	public:

    Office(int index,int length,int width,int lotLength,int lotWidth,string businessName,int parkingSpaces){
    	
    	this->index=index;
        setLength(length);
        setWidth(width);
        setLotLength(lotLength);
        setLotWidth(lotWidth);
        setBusinessName(businessName);
        setParkingSpaces(parkingSpaces);
        sTotalOffices++;
    }

    //getters
    int getIndex(){
    	return index;
    }
    string getBusinessName(){
        return mBusinessName;
    }

    int getParkingSpaces(){
        return mParkingSpaces;
    }


    int getOfficeArea(){
    	int officeArea=calcBuildingArea();
    	return officeArea;
    }

    int getLotArea(){
    	int officeLotArea=calcLotArea();
    	return officeLotArea;
    }

    int getTotalOffices(){
    	return sTotalOffices;
    }
	
    void toString(){
        cout<<"\nBusiness "<<getIndex()<<":"<<getBusinessName();
        
        if(getParkingSpaces()!=0)
        {
            cout<<"; has "<<getParkingSpaces()<<" parking spaces."<<endl;
        }

        cout<<"Office area: "<< getOfficeArea()<<" Lot area: "<< getLotArea();
        if(sTotalOffices!=0)
        {
            cout<<" (total offices: "<< sTotalOffices<<")";
        }    
    }

    ~Office(){
    }

    //setters
    void setBusinessName(string businessName){
        mBusinessName=businessName;
    }
	private:

    void setParkingSpaces(int parkingSpaces){
        mParkingSpaces=parkingSpaces;
    }

};
int Office:: sTotalOffices=0;



vector <Office> forSale;

void generateData(){
	
	for(int j=0;j<5;j++)
	{
		int lotLength= rand()%500+1000;
		int lotWidth=  rand()%200+1000;
		int length= rand()%200+500;
		int width= rand()%400 + 400;
		int parkingSpaces= rand()%30;
		Office var(j,length,width,lotLength,lotWidth,"unoccupied",parkingSpaces);
		forSale.push_back(var);

	}
}



void myData(){
	for(int j=0;j<forSale.size();j++)
	{
		forSale[j].toString();
		cout<<endl;
	}
}



int main(){
	int choice;
	generateData();
	cout<<"Do you want to buy or sell an office?"<<endl;
	cout<<"1)Buy 2)Sell"<<endl;
	cin>>choice;
	string business;
	switch(choice){
		case 1: int num;
				
				cout<<"Here are all offices available for sale:"<<endl;
				myData();
				cout<<"\nWhich property do you wish to buy? (please specify the serial number)"<<endl;
				cin>>num;
				cout<<"What might be your business Name?"<<endl;
				cin.ignore();
				getline (cin, business);
				forSale[num].setBusinessName(business);
				cout<<endl<<endl<<"PAYMENT SUCCESSFUL!"<<endl<<endl;
				cout<<"Here is the updated list of offices"<<endl;
				myData();
				break;

		case 2: cout<<"\nThank you for selling your property to us!\nKindly enter the details:"<<endl;
				int length,width,lotLength,lotWidth,parkingSpaces;
				cout<<"Length of Building: ";
				cin>>length;
				cout<<endl<<"Width of Building: ";
				cin>>width;
				cout<<endl<<"Length of Lot: ";
				cin>>lotLength;
				cout<<endl<<"Width of Lot: ";
				cin>>lotWidth;
				cout<<endl<<"No. of parking spaces: ";
				cin>>parkingSpaces;
				cout<<endl<<"Thank you!";
				forSale.push_back(Office(forSale.size(),length,width,lotLength,lotWidth,"unoccupied",parkingSpaces));
				cout<<" Updated list:"<<endl;
				myData();
				break;

	}
	return 0;
}