#ifndef MAP_H
#define MAP_H
using namespace std;


class Road;
class Place;
class DLPlace;

enum Direction{
    North,
    South,
    East,
    West,
    None
};

class Place{
    friend void merge_roads(Road &north, Road &south, Road &west, Road &east);
    friend class Road;
    protected:
    
    Direction allowed_direction;
    Place* next;
    int index_id;

    public:
    virtual ~Place() = default; 

    Place(){
        next = nullptr;
        allowed_direction = Direction::None;
    };

    PlacePlace(Direction direction, Place* next, int val){
        this->next = next;
        this->allowed_direction = direction;
        index_id = val;
    };



};

//class for classes in the middle of the intersection, where turning is required
//Doubly Linked Place class
class DLPlace: public Place{
    friend void merge_roads(Road &north, Road &south, Road &west, Road &east);
    friend class Road;
    private:
    //special case for middle places
    Direction turn_direction;
    Place* turn;

    public:
    DLPlace(){
        next = nullptr;
        allowed_direction = Direction::None;
        turn_direction = Direction::None;
        turn = nullptr;
        index_id = 0;
    };

    DLPlace(Place* next, Direction allowed_direction, Place* turn, Direction turn_direction, int val){
        this->next = next;
        this->allowed_direction = allowed_direction;
        this->turn_direction = turn_direction;
        this->turn = turn;
        this->index_id = val;
    };


};


class Road{
    friend void merge_roads(Road &north, Road &south, Road &west, Road &east);
    private:
    Place head;
    unsigned int half_size; //half the length of the road (ex: 5 means road is 10 places long to avoid odd numbers)
    Direction direction;
    //Place object right before two middle DLPlace objects
    Place* pre_dl;

    public:
    Road(Direction direction, int half_size){
        //half size means to be at least 2
        head = Place(direction, nullptr, 0);
        this->direction = direction;
        this->half_size = (half_size < 2)?(2):(half_size);
        //create linked list
        Place* last = &head;
        for(int i=0;i<this->half_size*2;i++){
            if(i== this->half_size-1 || this->half_size-2 == i){
                DLPlace* segment = new DLPlace(nullptr, direction, nullptr, Direction::None, i+1);
                last->next = segment;
                last = segment;
                continue;
            }
            Place* segment = new Place(direction, nullptr, i+1);
            if(i==this->half_size-3)pre_dl = segment;
            last->next = segment;
            last = segment;
        }
    };


    //remove this function
    void iter_through_road(){
        Place* temp = &head;
        for(int i =0;i<half_size * 2;i++){
            if(temp->allowed_direction != direction){
                DLPlace* test = dynamic_cast<DLPlace*>(temp);
                cout<<test->index_id<<", dir: "<<test->turn_direction<<", odir: "<<test->allowed_direction<<endl;
                temp = test->turn;
                continue;
            }
            cout<<temp->index_id<<", dir: "<<temp->allowed_direction<<endl;
            temp = temp->next;
        }
    
    
    };
};

void merge_roads(Road &north, Road &south, Road &west, Road &east){
    //local function to replace a target (to_delete) with to_replace, linking target to before and after
    auto link_chain = [](Place* pre_place, DLPlace* first_replaced, DLPlace* second_replaced){
        //get pointers to places that need to be deleted
        Place* first_deleted = pre_place->next;
        Place* second_deleted = pre_place->next->next;

        //link the places together
        pre_place->next = first_replaced;
        first_replaced->turn_direction = pre_place->allowed_direction;
        first_replaced->turn = second_replaced;
        second_replaced->turn_direction = pre_place->allowed_direction;
        second_replaced->turn = second_deleted->next;
        //delete pre_place->next and pre_place->next->next
        delete first_deleted;
        delete second_deleted;
    };

    link_chain(south.pre_dl, dynamic_cast<DLPlace*>(east.pre_dl->next->next), dynamic_cast<DLPlace*>(west.pre_dl->next));
    link_chain(north.pre_dl, dynamic_cast<DLPlace*>(west.pre_dl->next->next), dynamic_cast<DLPlace*>(east.pre_dl->next));

}


#endif