class ParkingSystem {
public:
    int big=0,small=0,medium=0;
    ParkingSystem(int big, int medium, int small) {
       this->big=big;
       this->medium=medium;
       this->small=small;
        
    }
    
    bool addCar(int carType) {
        if(carType==1 and  this->big){
            this->big-=1;
            return true;
        }else if(carType==2 and this->medium){
            this->medium--;
            return true;
        }
        else if(carType==3 and this->small){
            this->small--;
            return true;
        }  
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */