#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Commodity;
class Store;


/*
 * The function is used to read a full line into a string variable
 * INPUT: None
 * RETURN: Full line input by user
 * */
string readWholeLine() {
    string input;
    cin.get();
    getline(cin, input);
    return input;
}

/*
 * This function is used to configure whether the input string is a number
 * INPUT: A string
 * RETURN: Bool. True if input string is a number, otherwise false.
 */
bool isNum(string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

/*
 * Commodity is about an item which the user can buy and the manager can add or delete.
 * ATTRIBUTE:
 *  price: The price of the commodity, an integer.
 *  description: The text which describe the commodity detail, a string.
 *  commodityName: The name of the commodity, a string.
 */
class Commodity {
protected:
    int price,no,total;
    string description;
    string commodityName;
    Commodity *ptr,*head;
    
    

public:
    
	
	
	~Commodity() = default;
	
    Commodity() {
        price = 0;
        no=0;
        total=0;
        description = "";
        commodityName = "";
        ptr=NULL;
        head=NULL;
   
   
    }

    Commodity(int price, string commodityName, string description) {
        this->price = price;
        this->commodityName = commodityName;
        this->description = description;
    }
    
	void writeprice(int r){
				price=r;
				}
		
           		int readprice(){
           			
           			return price;
				}
	void writecommodityName(string a){
			       
				    a.assign(commodityName);
				}
		
           		string  readcommodityName(){
           			
           			return commodityName;
				}
				
	void writedescription(string a){
			       
				    a.assign(description);
				}
		
           		string  readdescription(){
           			
           			return description;
				}			
	void writeptr(Commodity *r){
			
				ptr=r;
				
				}
		
           		Commodity *readptr(){
           			
           			return ptr;
           		}
    void writeno(int r){
				no=r;
				}
		
           		int readno(){
           			
           			return no;
				}
				
    /*
     * This method will show the full information of the commodity to user interface.
     * There is a overloading version, with an argument amount which will output the information with the amount
     * INPUT: None, or an integer specify the amount of this commodity
     * RETURN: None
     */
    void detail() {
        cout << commodityName << endl;
        cout << "price: " << price << endl;
        cout << "description: " << description << endl;
        cout << "----------------------------" << endl;
    }

    void detail(int amount) {
        cout << commodityName << endl;
        cout << "price: " << price << endl;
        cout << "description: " << description << endl;
        cout << "x " << amount << endl;
        cout << "----------------------------" << endl;
    }

    /*
     * The getter function of commodityName
     */
    string getName() {
        return commodityName;
    }

    /*
     * The getter function of price
     */
    int getPrice() {
        return price;
    }
};

/*
 * [YOU NEED TO FINISH THIS CLASS]
 * This is a list storing the existing commodity in the store.
 * There are some method which can modify the content.
 * You may use any data structure to complete this class.
 */
class CommodityList : public Commodity {
private:
	

public:
    /*
     * Print the full information of the commodities inside the list
     * You must call Commodity.detail() to show the commodity information.
     * INPUT: None
     * RETURN: None
     */
    void showCommoditiesDetail() {
       Commodity *a,*b;
		a=head;
		b=head;
		
		
	
		for(int i=1;i<=total;i++){
		
		b->writeno(i);
		b=b->readptr();
	}
		
      
	  while(a!=NULL)
	                 {
	                
		cout<<a->readno()<<"."<<endl;								  
	 	cout<<a->readcommodityName()<<endl;
     	cout<<"price:  "<<"$"<<a->readprice()<<endl;
     	cout<<"description:  "<<a->readdescription()<<endl;
		 a= a->readptr();
		 
		 }
		 
    }

    /*
     * Print only the commodity name of the commodities inside the list
     * You don't need to use Commodity.detail() here, just call the Commodity.getName() function is ok
     * INPUT: None
     * RETURN: None
     */
    void showCommoditiesName() {
    	
    Commodity *a,*b;
		a=head;
		b=head;
		for(int i=1;i<=total;i++){
		
		b->writeno(i);
		b=b->readptr();
	}
      
	  while(a!=NULL)
	                 {
		cout<<a->readno()<<"."<<endl;								  
	 	cout<<a->readcommodityName()<<endl;
     	
		 a= a->readptr();
		 
		 }
		
    }
    

    /*
     * Check whether the list is empty or not
     * INPUT: None
     * RETURN: Bool. True if the list is empty, otherwise false
     */
    bool empty() {
        
		if(head==NULL){
			return true;
		}
      return false;
	}

    /*
     * Return the size(or length) of the list
     * INPUT: None
     * RETURN: Integer. List size
     */
    int size() {
    	
    	return total ;
        
    }

    /*
     * Return a commodity object at specified position
     * INPUT: Integer. The index of that commodity
     * RETURN: Commodity. The wanted commodity object
     */
    Commodity get(int index) {
        Commodity *a;
		  a=head;
		 while(a&&a->readno()<index){
          		
				 a=a->readptr();
			
			 }
        return *a;
    }

    /*
     * Push a new commodity object into the list
     * INPUT: Commodity. The object need to be pushed
     * RETURN: None
     */
    void add(Commodity* newCommodity) {
    	 Commodity *a;
		  a=head;
    	 if(a==NULL){
    	 	a=newCommodity;
    	 	a->writeptr(NULL);
    	 	head=a;
    	 total++;
		 }
    	else{
    		newCommodity->writeptr(a);
    		head=newCommodity;
    		total++;
		}
	
	}
	
	
	
		
		
        
    

    /*
     * Check the input commodity object is existing inside the list
     * If the commodity name is the same, we take those objects the same object
     * INPUT: Commodity. The object need to be checked
     * OUTPUT: Bool. True if the object existing, otherwise false
     */
    bool isExist(Commodity* commodity) {
        
		Commodity *a;
		a=head;
	   
    while(a) {
					if(a->readcommodityName().compare (commodity->readcommodityName())==0) {
						
						return true; 
						
					}
					a = a->readptr();
				}
		return false ;
}
    /*
     * Remove an object specified by the position
     * INPUT: Integer. The position of the object which need to be removed
     * OUTPUT: None
     */
    void remove(int index) {
    	   	
    		Commodity *a,*b,*c;
				a = head;
				b = NULL;
				c = head;
				
			 while(a&&a->readno()<index){
          		
				 b=a ;
				  
				 a=a->readptr();
			
			
			 }
		 
			 if(a&&a->readno()==index){
		 
			    if(b==NULL){
			    	head=a->readptr();
			    	delete a;
			    	a=0;
			    	total--;
			    	
				}
			 
			 	else if(a->readptr()==NULL){
			 		
			 		b->writeptr(NULL);
			 		delete a;
			 		a=0;
			 		total--;
				 }
			 
			 	else{
				  
				  b->writeptr(a->readptr());
				  delete a;
				  a=0;
				  total--;
				  }
				  
				   
			 }
		 		
			
			
				for(int i=1;i<=total;i++){
		
					c->writeno(i);
					c=c->readptr();
					}	
			
			
				}
		 	
		
	
	
    	
        
    };

/*
 * [YOU NEED TO FINISH THIS CLASS]
 * The shopping cart is used to store the commodities user wanted.
 * Because the same name represents the same object, if there is a commodity which have more than one object inside
 * the cart, then it will be store as the same object and the cart must keep the amount of the object.
 * You may use any data structure to complete this class.
 */
class ShoppingCart: public Commodity {
private:
  int price2,no2,total2;
  string C,D;
  ShoppingCart *ptr,*head;

  Commodity data[1386*5];
  int bucket[1386*5]={0}; 
  int endpoint = 0;
  

public:
		void writeprice2(int r){
				price=r;
				}
		
           		int readprice2(){
           			
           			return price2;
				}
	void writeC(string a){
			       
				    a.assign(C);
				}
		
           		string  readC(){
           			
           			return C;
				}
				
	void writeD(string a){
			       
				    a.assign(D);
				}
		
           		string  readD(){
           			
           			return D;
				}			
	void writeptr( ShoppingCart*r){
			
				ptr=r;
				
				}
		
           		ShoppingCart *readptr(){
           			
           			return ptr;
           		}
    void writeno2(int r){
				no2=r;
				}
		
           		int readno2(){
           			
           			return no2;
				}		
		
		
		

    /*
     * Push an commodity object into the cart.
     * Be careful that if the input object is existing in the list, then keep the amount of that object rather than
     * actually push the object into the cart.
     * INPUT: Commodity. The object need to be pushed.
     * OUTPUT: None.
     */
    void push(Commodity entry) {
        endpoint %= 5086;
       for(int i=0;i<=endpoint;i++){
           if(data[i].getName() == entry.getName()){
                bucket[i]++;
                return;
           }
       }

        data[++endpoint] = entry;
        bucket[endpoint] = 1;


    }

    /*
     * Show the content of the cart to user interface.
     * INPUT: None.
     * OUTPUT: None.
     */
    void showCart() {
        int index = 0;
        for(int i =0;i<=endpoint;i++){
            if(bucket[i]){
                cout<<++index<<". ";
                data[i].detail(bucket[i]);
                cout<<endl;
            }
        }
        
    }

    /*
     * Return the cart size. (The same object must be seen as one entry)
     * INPUT: None.
     * OUTPUT: Integer. The cart size.
     */
    int size() {
        int result =0;
        for(int i=0;i<=endpoint;i++){
            if(bucket[i])result++;
        }
        return result;
    }

    /*
     * Remove an entry from the cart. Don't care about the amount of the commodity, just remove it.
     * INPUT: The order of the entry.
     * OUTPUT: None.
     */
    void remove(int index) {
        
        int target=0;
        int i;
        for(i=0 ;i<=endpoint && target<index;i++){
            if(bucket[i])   target++;
        }

        bucket[i]=0;
        // data[i] =  Commodity();

    }

    /*
     * Check the total amount of price for the user.
     * Remember to clear the list after checkout.
     * INPUT: None.
     * OUTPUT: Integer. The total price.
     */
    int checkOut() {
        int sum=0;
        int index=0;
        for(int i=0;i<=endpoint;i++){
            if(bucket[i]){
                cout<<index<<". ";
                data[i].detail(bucket[i]);
                cout<<endl;
                sum+= bucket[i]*data[i].getPrice();
            }
        }
        
        for(int i=0;i<endpoint+87;i++){
            bucket[i] =0; 
        }


        return sum;
    }

    /*
     * Check if the cart have nothing inside.
     * INPUT: None.
     * OUTPUT: Bool. True if the cart is empty, otherwise false.
     */
    bool empty() {
        return ( size() == 0);
    }
};

/*
 * [DO NOT MODIFY ANY CODE HERE]
 * The Store class manage the flow of control, and the interface showing to the user.
 * Store use status to choose the interface to show. As the result, status control is very important here.
 * If you can understand the code here, you will have great work on the above two class.
 * The detail of Store is in the README
 */
class Store {
private:
    enum UMode {USER, MANAGER} userStatus;
    enum SMode {OPENING, DECIDING, SHOPPING, CART_CHECKING, CHECK_OUT, MANAGING, CLOSE} storeStatus;
    CommodityList commodityList;
    ShoppingCart cart;

    bool isValidNum(string& str) {
        if (isNum(str) && stoi(str) <= 0)
            return false;
        return true;
    }

    int numberInput() {
        string input;
        cin >> input;
        while (!isValidNum(input)) {
            cout << "Please input again your input is NOT an integer or is lower than or equal to 0:" << endl;
            cin >> input;
        }
        return stoi(input);
    }

    int inputCheck(string input, int maxChoiceLen, bool noZero) {
        // Change input to the general integer
        int choice = 0;
        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i])) {
                choice = choice * 10 + (input[i] - '0');
            } else {
                return -1;
            }
        }

        if (noZero) {
            return (choice <= maxChoiceLen && choice > 0) ? choice : -1;
        } else {
            return (choice <= maxChoiceLen && choice >= 0) ? choice : -1;
        }
    }

    int getInput(int maxChoiceLen, bool noZero = false) {
        string input;

        cin >> input;
        int choice = inputCheck(input, maxChoiceLen, noZero);
        while (choice == -1) {
            cout << "your input is wrong, please input again:" << endl;
            cin >> input;
            choice = inputCheck(input, maxChoiceLen, noZero);
        }

        return choice;
    }

    void commodityInput() {
        string name, detail;
        int price;
        Commodity* newCom;

        cout << "Please input the commodity name:" << endl;
        name = readWholeLine();
        cout << "Please input the commodity price:" << endl;
        price = numberInput();
        cout << "Please input the detail of the commodity:" << endl;
        detail = readWholeLine();

        newCom = new Commodity(price, name, detail);
        if (commodityList.isExist(newCom)) {
            cout << "[WARNING] " << name << " is exist in the store. If you want to edit it, please delete it first" << endl;
        } else {
            commodityList.add(newCom);
        }
    }

    void deleteCommodity() {
        if (commodityList.empty()) {
            cout << "No commodity inside the store" << endl;
            return;
        }

        int choice;
        cout << "There are existing commodity in our store:" << endl;
        commodityList.showCommoditiesName();
        cout << "Or type 0 to regret" << endl
             << "Which one do you want to delete?" << endl;

        choice = getInput(commodityList.size());

        if (choice != 0) {
            commodityList.remove(choice );
        }
    }

    void showCommodity() {
        if (commodityList.empty()) {
            cout << "No commodity inside the store" << endl;
            return;
        }

        cout << "Here are all commodity in our store:" << endl;
        commodityList.showCommoditiesDetail();
        cout << endl;
    }

    void askMode() {
        string input;

        cout << "Are you a general user or a manager?" << endl
             << "1. general user, 2. manager" << endl
             << "Or type 0 to close the store" << endl;

        int choice = getInput(2);

        userStatus = (choice == 2) ? UMode::MANAGER : UMode::USER;

        if (choice == 0) {
            storeStatus = SMode::CLOSE;
        } else if (userStatus == UMode::USER) {
            storeStatus = SMode::DECIDING;
        } else if (userStatus == UMode::MANAGER) {
            storeStatus = SMode::MANAGING;
        }
    }

    void decideService() {
        string input;

        cout << "Below are our service:" << endl
             << "1. Buy the commodity you want" << endl
             << "2. Check your shopping cart" << endl
             << "3. Check out" << endl
             << "Or type 0 to exit user mode" << endl
             << "You may choose what you need:" << endl;

        int choice = getInput(3);

        if (choice == 1) {
            storeStatus = SMode::SHOPPING;
        } else if (choice == 2) {
            storeStatus = SMode::CART_CHECKING;
        } else if (choice == 3) {
            storeStatus = SMode::CHECK_OUT;
        } else if (choice == 0) {
            storeStatus = SMode::OPENING;
        }
    }

    void chooseCommodity() {
        string input;
        showCommodity();
        cout << "Or input 0 to exit shopping" << endl;

        int choice = getInput(commodityList.size());

        // Push the commodity into shopping cart here
        if (choice == 0) {
            storeStatus = SMode::DECIDING;
        } else {
            // May be some bug here, test later
            cart.push(commodityList.get(choice ));
        }
    }

    void showCart() {
        if (cart.empty()) {
            cout << "Your shopping cart is empty" << endl;
            storeStatus = SMode::DECIDING;
            return;
        }

        int choice;
        do {
            cout << "Here is the current cart content:" << endl;
            cart.showCart();

            cout << "Do you want to delete the entry from the cart?" << endl
                 << "1. yes, 2. no" << endl;

            choice = getInput(2, true);

            if (choice == 1) {
                cout << "Which one do you want to delete(type the commodity index)?" << endl
                     << "Or type 0 to regret" << endl;
                int index = getInput(cart.size());
                if (index == 0) {
                    break;
                }
                cart.remove(index - 1);
            }
        } while (choice == 1);

        cout << "Do you want to checkout?" << endl
             << "1. yes, 2. No, I want to buy more" << endl;
        choice = getInput(2, true);
        if (choice == 1) {
            storeStatus = SMode::CHECK_OUT;
        } else {
            storeStatus = SMode::DECIDING;
        }
    }

    void checkOut() {
        if (cart.empty()) {
            cout << "Your shopping cart is empty, nothing can checkout" << endl;
        } else {
            cout << "Here is the current cart content:" << endl;
            cart.showCart();
            cout << "Are you sure you want to buy all of them?" << endl
                 << "1. Yes, sure, 2. No, I want to buy more" << endl;

            int choice = getInput(2, true);

            if (choice == 1) {
                int amount = cart.checkOut();
                cout << "Total Amount: " << amount << endl;
                cout << "Thank you for your coming!" << endl;
                cout << "------------------------------" << endl << endl;
            }
        }

        storeStatus = SMode::DECIDING;
    }

    void managerInterface() {
        cout << "Here are some manager services you can use:" << endl
             << "1. Add new commodity" << endl
             << "2. Delete commodity from the commodity list" << endl
             << "3. Show all existing commodity" << endl
             << "Or type 0 to exit manager mode" << endl
             << "Which action do you need?" << endl;

        int choice = getInput(3);

        if (choice == 1) {
            commodityInput();
        } else if (choice == 2) {
            deleteCommodity();
        } else if (choice == 3) {
            showCommodity();
        } else if (choice == 0) {
            storeStatus = SMode::OPENING;
        }
    }

    void userInterface() {
        if (storeStatus == SMode::OPENING) {
            askMode();
        } else if (storeStatus == SMode::DECIDING) {
            decideService();
        } else if (storeStatus == SMode::SHOPPING) {
            chooseCommodity();
        } else if (storeStatus == SMode::CART_CHECKING) {
            showCart();
        } else if (storeStatus == SMode::CHECK_OUT) {
            checkOut();
        } else if (storeStatus == SMode::MANAGING) {
            managerInterface();
        } else if (storeStatus == SMode::CLOSE) {
            return;
        }
    }

public:
    Store() {
        userStatus = UMode::USER;
        storeStatus = SMode::CLOSE;
    }

    void open() {
        storeStatus = SMode::OPENING;
        while (storeStatus != SMode::CLOSE) {
            userInterface();
        }
    }
};


int main() {
    Store csStore;
    csStore.open();
    return 0;
}
