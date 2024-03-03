#include <bits/stdc++.h>
typedef long long lint ; 
using namespace std ; 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// data-structures 
lint formatDateToInt(string s) 
  {
    if (s.size() != 10) {return -1;}
    lint day = ((s[0] - '0') * 10) + (s[1] - '0');
    lint month = ((s[3] - '0') * 10) + (s[4] - '0');
    lint year = ((s[6] - '0') * 1000) + ((s[7] - '0') * 100) + ((s[8] - '0') * 10) + (s[9] - '0');
    lint result = year * 10000 + month * 100 + day;
    return result;
}
template <typename T> class Node
   {
    public:
        T value;
        Node* left;
        Node* right;
        lint height;
        Node(T val) 
        {
         this->value=val ;
         this->left = NULL ; 
         this->right = NULL ; 
         this->height=0 ; 
        }
    };
template <typename T> class AVL
   {

   public:

      Node<T> *  root;
      AVL()  {root=nullptr;}
      Node<T> *  search(T val) {return search(root, val);}
      void    insert(T value) {root = insert(value, this->root);}
      void    deleteNode(T value){root = deleteNode(root, value); }
      lint    balance_factor(Node<T> * root){ if(!root)return 0 ; else return height(root->left) - height(root->right) ; }
      lint    height()                                {return height(root) ; }  
      bool    isEmpty()                               {return root == nullptr;}
      bool    balanced()                              {return balanced(root);}
      void    inorder()                               {return inorder(this->root) ; reverse(this->in.begin() , this->in.end()) ; }
      void    preorder()                              {return preorder(this->root) ;}
      void    postorder()                             {return postorder(this->root) ;}
      int     size()                                  {return size(this->root) ;}
      vector<string> in ;

    private : 
      int size(Node<T> * root)
      {
        if(root==nullptr){return 0 ; }
        return 1 + size(root->left) + size(root->right) ; 
      }

    private:

      Node<T> * search(Node<T> * node, T val) {
          if (node == nullptr || node->value->key == val->key)  return node;
          if (val->key < node->value->key) return search(node->left, val);
          else return search(node->right, val);   }
    private:
      lint height(Node<T> * node) {
          if (node == nullptr) return 0;
          return node->height;}
  
    private:
      Node<T> * insert(T val, Node<T> * node){
          if (node == nulAlptr) { node = new Node<T>(val); return node;}

          if (val->key < node->value->key)  node->left = insert(val, node->left);
          else if (val->key > node->value->key) node->right = insert(val, node->right);

          node->height = max(height(node->left),height(node->right)) + 1;

          return rotate(node); }
    private:     
      bool balanced(Node<T> * node) {
          if (node == nullptr) {
              return true;
          }
          return abs(height(node->left) - height(node->right)) <= 1 && balanced(node->left) && balanced(node->right);}

    private:
      Node<T> * rotate(Node<T> * node){
          //four cases 
          if(height(node->left)-height(node->right)>1)
          {
            //left heavy 
            // case:1 if heights of left and right subtree of child nodes are poistive 
            //         this means case of L-L / L-R
            if(height(node->left->left)- height(node->left->right)>0)
            {
              //case L-L
              return rightrotate(node) ; 
            }
            if(height(node->left->left)- height(node->left->right)<0)
            {
              //case L-R
              node->left = leftrotate(node->left) ; 
              return rightrotate(node) ; 
            }
          }
          if(height(node->left)-height(node->right) < -1)
          {
            // right heavy 
            // case:1 if heights of left and right subtree of child nodes are poistive 
            //         this means case of R-L / R-R
            if(height(node->right->left) - height(node->right->right) < 0)
            {
              //case R-R
              return leftrotate(node) ; 
            }
            if(height(node->right->left)- height(node->right->right) > 0)
            {
              //case R-L
              node->left = rightrotate(node->right) ; 
              return leftrotate(node) ; 
            }
          }
          return node ; }

    private:     
      Node<T> * leftrotate(Node<T> * child){
        Node<T> * parent = child->right;
        Node<T> * t = parent->left;
        parent->left = child;
        child->right = t;

        // Update heights
        child->height = max(height(child->left), height(child->right)) + 1;
        parent->height = max(height(parent->left), height(parent->right)) + 1;

        return parent;}

      Node<T> * rightrotate(Node<T> * child){
      Node<T> * parent = child->left;
      Node<T> * t = parent->right;
      parent->right = child;
      child->left = t;

      // Update heights
      child->height = max(height(child->left), height(child->right)) + 1;
      parent->height = max(height(parent->left), height(parent->right)) + 1;

      return parent;}
      private:
         Node<T>* deleteNode(Node<T>* node, T val) {
        if (node == nullptr) return node;

        if (val->key < node->value->key)node->left = deleteNode(node->left, val); 
        else if (val->key > node->value->key) node->right = deleteNode(node->right, val);
        else 
        {
            if (node->left == nullptr || node->right == nullptr) 
            {
                Node<T>* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {temp = node; node = nullptr;} 
                else {*node = *temp;}
                delete temp;
            } 
            else 
            {
                Node<T>* temp = minValueNode(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
        }
        if (node == nullptr) {return node;}
        node->height = 1 + max(height(node->left), height(node->right));
        return rotate(node);
    }
        Node<T>* minValueNode(Node<T>* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    public:    
    void inorder(Node<T> *root){
        if(!root){return ;}
        inorder(root->left) ; 
        in.push_back(root->value->name ) ;  
        inorder(root->right) ; }
     private:       
    void preorder(Node<T> *root){
        if(!root){return ;}
        cout<<root->value->key <<" " ;  
        preorder(root->left) ; 
        preorder(root->right) ;}
    private:
    void postorder(Node<T> *root){
        if(!root){return ;}
        postorder(root->left) ; 
        postorder(root->right) ;
        cout<<root->value->key <<" " ;}

  };
class score
{
public:
    string date;
    int key;
    int runs;
    int wickets;

    score(std::string date, int runs, int wickets)
    {
        this->date = date;
        this->key = formatDateToInt(date);
        this->runs = runs;
        this->wickets = wickets;
    }
};
struct CR
{
    bool operator()(score* const& s1, score* const& s2)
    {
        return s1->runs < s2->runs;
    }
};
struct CW
{
    bool operator()(score* const& s1, score* const& s2)
    {
        return s1->wickets < s2->wickets;
    }
};
class player
{
    public:
    string name ; 
    string role ; 
    string team ; 
    int total_runs  ;
    int total_wickets ; 
    int key ; 
    string recent_match ; 
    unordered_map<string , int> map_runs ; 
    unordered_map<string , int> map_wickets ; 
    player(string name ,string role , string team)
    {
        this->name = name ; 
        this->role=role ; 
        this->total_runs = 0 ; 
        this->total_wickets=0 ; 
        this->team = team ; 
        this->key=0 ; 
        this->recent_match = "00/00/0000";
    }
    priority_queue<score*, vector<score*>, CR> bat_score  ;  
    priority_queue<score*, vector<score*>, CW> ball_score ;
    void input(string date , int runs , int wickets)
    {
        score* newscore = new score(date , runs , wickets) ; 
        recent_match = date ; 
        total_runs+=runs ; 
        total_wickets+=wickets ;
        bat_score.push(newscore)  ; 
        ball_score.push(newscore) ;
        if(role=="Bowler"){key=total_wickets ;}
        if(role=="Batsman"){key=total_runs;}
        map_wickets[date] = wickets ; 
        map_runs[date] = runs ; 
    } 
} ;
class match
{
    public : 
    string date = "00/00/0000" ; 
    lint key ; 
    set<player*> player_list; 
    string team1 = "none"; 
    string team2 = "none" ; 
    match(string date )
    {
      this->date=date ; 
      this->key=formatDateToInt(date) ; 
      this->team1 = "none" ;
      this->team2 = "none" ; 
    }

    match(string date , string team1 , string team2)
    {
      this->date=date ; 
      this->key=formatDateToInt(date) ; 
      this->team1 = team1 ; 
      this->team2 = team2 ; 
    }

    void edit(player * p1)
    {
       if(team1=="none"){this->team1 = p1->team ; }
       else if (p1->team!=team1 && team2=="none"){this->team2 = p1->team ;}
       player_list.insert(p1) ; 
       if(date=="00/00/0000"){date = p1->recent_match ; }
    }



} ;
class ranking 
{
    public:
    AVL<player*> * batrank = new AVL<player*>() ; 
    AVL<player*> * ballrank = new AVL<player*>() ;  
    player *bat1 = nullptr, *bat2 = nullptr, *bat3 = nullptr;
    player *ball1 = nullptr, *ball2 = nullptr, *ball3 = nullptr;

 void check(player* mark) {
    if (bat1 == nullptr || (mark->total_runs > bat1->total_runs && mark->name != bat1->name)) {
        bat3 = bat2;
        bat2 = bat1;
        bat1 = mark;
    } else if (bat2 == nullptr || (mark->total_runs > bat2->total_runs && mark->name != bat2->name && mark->name != bat1->name)) {
        bat3 = bat2;
        bat2 = mark;
    } else if (bat3 == nullptr || (mark->total_runs > bat3->total_runs && mark->name != bat3->name && mark->name != bat1->name && mark->name != bat2->name)) {
        bat3 = mark;
    }

    if (ball1 == nullptr || (mark->total_wickets > ball1->total_wickets && mark->name != ball1->name)) {
        ball3 = ball2;
        ball2 = ball1;
        ball1 = mark;
    } else if (ball2 == nullptr || (mark->total_wickets > ball2->total_wickets && mark->name != ball2->name && mark->name != ball1->name)) {
        ball3 = ball2;
        ball2 = mark;
    } else if (ball3 == nullptr || (mark->total_wickets > ball3->total_wickets && mark->name != ball3->name && mark->name != ball1->name && mark->name != ball2->name)) {
        ball3 = mark;
    }
}


} ;
unordered_map<string , player*> player_search ;
unordered_map<string , match*> match_search ;
ranking * world  = new ranking(); 
void input_1(string name, string role, string team, string date, int runs, int wickets) {
    // Check if the player already exists in player_search
    if (player_search.find(name) == player_search.end()) {
        // Create a new player only if it doesn't exist
        player* newplayer = new player(name, role, team);
        player_search[name] = newplayer;
    }

    // Update the player's information
    player_search[name]->input(date, runs, wickets);

    // Check if the match already exists in match_search
    if (match_search.find(date) == match_search.end()) {
        // Create a new match if it doesn't exist
        match* newmatch = new match(date);
        match_search[date] = newmatch;
    }

    // Update the match with the player
    match_search[date]->edit(player_search[name]);

    // Update the rankings
    world->check(player_search[name]);

    // Update AVL trees
    if(role=="Batsman")
    {
    if (world->batrank->search(player_search[name]) == nullptr) {
        world->batrank->insert(player_search[name]);
    } else {
        world->batrank->deleteNode(player_search[name]);
        world->batrank->insert(player_search[name]);
    }
    }
    if(role=="Bowler")
    {
    if (world->ballrank->search(player_search[name]) == nullptr) {
        world->ballrank->insert(player_search[name]);
    } else {
        world->ballrank->deleteNode(player_search[name]);
        world->ballrank->insert(player_search[name]);
    }   
    }
}
void input_player()
{
    cout<<" enter name of your player : " ;
    string name  ; cin>>name ;  cout<<endl ; 
    // step1 : PLAYER INFO
    if(player_search.find(name)==player_search.end())      //player does not exists
    {
        cout<<"currently no record , enter the following details :"<<endl  ;
        cout<<"wether Bowler / Batsman :"  ;  
        string role ; cin>>role ; 
        cout<<"in which team : " ;
        string team ; cin>>team ; 
        // creation of new player 
        player * newplayer = new player(name , role , team) ; 
        // insertion of player 
        player_search[name] = newplayer ; 
    }
    // step 2 : PLAYER INFORMATION 
    cout<<"enter the date of match :" ; 
    string date ; cin>>date ; 
    cout<<"enter the number of runs scored : " ; 
    int runs ; cin>>runs ; 
    cout<<"enter the number of wickets scored : " ; 
    int wickets ; cin>>wickets ; 
    player_search[name]->input(date , runs , wickets) ; 
    // step 3 : EDITING THE MATCH INFORMATION 
    if(match_search.find(date)==match_search.end())// match does not exits 
    {
        // creation of new match 
        match* newmatch = new match(date) ; 
        // insertion of match 
        match_search[date] = newmatch ;
    }
    // step 3.1 : updating match 
    match_search[date]->edit(player_search[name]) ;
    // step 4 : UPDATING RANKINGS 
    world->check(player_search[name]) ;
    string role = player_search[name]->role ;
    // step 5 : UPDATIONS IN AVL TREE OF PLAYERS
    if(role=="Batsman")
    {
    if (world->batrank->search(player_search[name]) == nullptr) {
        world->batrank->insert(player_search[name]);
    } else {
        world->batrank->deleteNode(player_search[name]);
        world->batrank->insert(player_search[name]);
    }
    }
    if(role=="Bowler")
    {
    if (world->ballrank->search(player_search[name]) == nullptr) {
        world->ballrank->insert(player_search[name]);
    } else {
        world->ballrank->deleteNode(player_search[name]);
        world->ballrank->insert(player_search[name]);
    }   
    }
}
void display_player()
{
    cout<<"==========player display==========="<<endl ; 
    cout<<"enter the name of the player "  ; 
    string name ; cin>>name ; 
    cout<<"-----------------------------------"<<endl ;  
    player * person = player_search[name] ; 
    cout<<"Name : "<<person->name<<endl<<"Team : "<<person->team<<endl<<"Role :"<<person->role<<endl  ;   
    cout<<"-----------------------------------"<<endl ; 
    cout<<"Current Preformance"<<endl ; 
    cout<<"___________________________________"<<endl ;  
    string role = person->role ; 
    score  *t1 , *t2 , *t3 ; 
    if(role=="Bowler")
    {
                                     
        cout<<"|sr no. |    Date   | wickets took|"<<endl ; 
        t1 = person->ball_score.top() ; person->ball_score.pop() ; 
        cout<<"|  1.   |"<<t1->date<<" | "<<t1->wickets<<"           |"<<endl ; 
        if(person->ball_score.empty()){cout<<"only one game played"<<endl ; return ; }
        t2 = person->ball_score.top() ; person->ball_score.pop() ; 
        cout<<"|  2.   |"<<t2->date<<" | "<<t2->wickets<<"           |"<<endl ;   
        if(person->ball_score.empty()){cout<<"only two game played"<<endl ; return ; }     
        t3 = person->ball_score.top() ; person->ball_score.pop() ; 
        cout<<"|  3.   |"<<t3->date<<" | "<<t3->wickets<<"           |"<<endl ; 

        person->ball_score.push(t1) ; 
        person->ball_score.push(t2) ;
        person->ball_score.push(t3) ;           
        cout<<"-----------------------------------"<<endl ;
    }

    if(role=="Batsman")
    {
        cout<<"|sr no. |    Date   | runs scored |"<<endl ; 
        t1 = person->bat_score.top() ; person->bat_score.pop() ; 
        cout<<"|  1.   |"<<t1->date<<" | "<<t1->runs<<"         |"<<endl  ; 
        if(person->bat_score.empty()){cout<<"only one game played"<<endl ; return ; }
        t2 = person->bat_score.top() ; person->bat_score.pop() ; 
        cout<<"|  2.   |"<<t2->date<<" | "<<t2->runs<<"         |"<<endl ;   
        if(person->bat_score.empty()){cout<<"only two game played"<<endl ; return ; }     
        t3 = person->bat_score.top() ; person->bat_score.pop() ; 
        cout<<"|  3.   |"<<t3->date<<" | "<<t3->runs<<"         |"<<endl ;  

        person->bat_score.push(t1) ; 
        person->bat_score.push(t2) ;
        person->bat_score.push(t3) ;  
        cout<<"-----------------------------------"<<endl ;    
    }

}
void display_match()
{
    cout << "Enter date of match: ";
    string date;
    cin >> date;

    if (match_search.find(date) == match_search.end()) {
        cout << "No current records of this match." << endl;
        return;
    }

    match *m = match_search[date];
    cout << "Following are the match details:" << endl;
    cout << "Match teams: " << m->team1 << " and " << m->team2 << endl;
    cout << "Match players:" << endl;

    int runner = 1;

    // Determine the maximum name length for proper alignment
    int maxNameLength = 0;
    for (auto player : m->player_list) {
        maxNameLength = max(maxNameLength, static_cast<int>(player->name.length()));
    }

    cout << left << setw(6) << "Sr. No." << setw(maxNameLength + 4) << "Player"
        << "Runs" << setw(8) << "/Wickets" << endl;

    for (auto player : m->player_list) {
        cout << left << setw(6) << runner << setw(maxNameLength + 5) << player->name
            << player->map_runs[date] << setw(8) << player->map_wickets[date] << endl;
        runner++;
    }


}
void display_rankings(int n) {
    cout << "============rank display===========" << endl;
    cout << endl;

    // Display top batsmen
    cout << "Top " << n << " batsmen" << endl;
    cout <<"______________________________________________________________"<<endl ; 
    cout << left << setw(5) << "| Rank" << setw(20) << " | Player" << setw(20) << "   | Team" << "     | Runs    |" << endl;
    cout <<"|------+---------------------+---------------------+---------|"<<endl ; 

    world->batrank->inorder();
    int size_batsmen = world->batrank->in.size();
    for (int i = 0; i < n && i < size_batsmen; i++) {
        cout << left << "| " << setw(4) << i + 1 << " | " << setw(19) << world->batrank->in[size_batsmen - i - 1]
            << " | " << setw(19) << player_search[world->batrank->in[size_batsmen - i - 1]]->team << " | "  ;
            if( player_search[world->batrank->in[size_batsmen - i - 1]]->total_runs < 100)
            {
             cout<<player_search[world->batrank->in[size_batsmen - i - 1]]->total_runs << "      |" << endl;
            }
            else
            {
            cout<<player_search[world->batrank->in[size_batsmen - i - 1]]->total_runs << "     |" << endl;
            }
    }   
    cout <<"--------------------------------------------------------------"<<endl ; 
    cout << endl;

    // Display top bowlers
    cout << "Top " << n << " bowlers" << endl;

    cout <<"______________________________________________________________"<<endl ; 
    cout << left << setw(5) << "| Rank" << setw(20) << " | Player" << setw(20) << "   | Team" << "     | Wickets |" << endl;
    cout <<"|------+---------------------+---------------------+---------|"<<endl ; 

    world->ballrank->inorder();
    int size_bowlers = world->ballrank->in.size();
    for (int i = 0; i < n && i < size_bowlers; i++) {
        cout << left << "| " << setw(4) << i + 1 << " | " << setw(19) << world->ballrank->in[size_bowlers - i - 1]
            << " | " << setw(19) << player_search[world->ballrank->in[size_bowlers - i - 1]]->team
            << " | " ;
            if( player_search[world->ballrank->in[size_bowlers - i - 1]]->total_wickets < 10)
            {
                cout<< player_search[world->ballrank->in[size_bowlers - i - 1]]->total_wickets << "       |" << endl ; 
            }
            else
            {
                cout<< player_search[world->ballrank->in[size_bowlers - i - 1]]->total_wickets << "      |" << endl ; 
            }
    }
    cout <<"--------------------------------------------------------------"<<endl ; 
}
void import_dataset()
{
    input_1("Virat", "Batsman", "IND", "20/10/2022", 100, 0);
    input_1("Rohit", "Batsman", "IND", "20/10/2022", 50, 0);
    input_1("Jasprit", "Bowler", "IND", "20/10/2022", 5, 4);  
    input_1("Umesh", "Bowler", "IND", "20/10/2022", 4, 3);    
    input_1("Shadab", "Bowler", "PAK", "20/10/2022", 1, 1);   
    input_1("Wahab", "Bowler", "PAK", "20/10/2022", 3, 3);    
    input_1("Babar", "Batsman", "PAK", "20/10/2022", 75, 0);
    input_1("Fakhar", "Batsman", "PAK", "20/10/2022", 42, 0);
    input_1("Virat", "Batsman", "IND", "20/11/2022", 110, 0);
    input_1("Rohit", "Batsman", "IND", "20/11/2022", 50, 0);
    input_1("Jasprit", "Bowler", "IND", "20/11/2022", 7, 4); 
    input_1("Umesh", "Bowler", "IND", "20/11/2022", 3, 3);    
    input_1("Shadab", "Bowler", "PAK", "20/11/2022", 2, 1);    
    input_1("Wahab", "Bowler", "PAK", "20/11/2022", 4, 3);  
    input_1("Babar", "Batsman", "PAK", "20/11/2022", 75, 0);
    input_1("Fakhar", "Batsman", "PAK", "20/11/2022", 42, 0);
    input_1("Virat", "Batsman", "IND", "20/12/2022", 120, 0);
    input_1("Rohit", "Batsman", "IND", "20/12/2022", 50, 0);
    input_1("Jasprit", "Bowler", "IND", "20/12/2022", 9, 4);  
    input_1("Umesh", "Bowler", "IND", "20/12/2022", 6, 3);   
    input_1("Shadab", "Bowler", "PAK", "20/12/2022", 3, 1);   
    input_1("Wahab", "Bowler", "PAK", "20/12/2022", 5, 3);    
    input_1("Babar", "Batsman", "PAK", "20/12/2022", 75, 0);
    input_1("Fakhar", "Batsman", "PAK", "20/12/2022", 42, 0);
    input_1("Joe", "Batsman", "ENG", "19/09/2004", 204, 0);
    input_1("Jason", "Batsman", "ENG", "19/09/2004", 28, 0);
    input_1("Stuart", "Bowler", "ENG", "19/09/2004", 3, 3);  
    input_1("Olly", "Bowler", "ENG", "19/09/2004", 1, 1);    
    input_1("David", "Batsman", "AUS", "19/09/2004", 78, 0);
    input_1("Marnus", "Batsman", "AUS", "19/09/2004", 63, 0);
    input_1("Josh", "Bowler", "AUS", "19/09/2004", 1, 1);    
    input_1("James", "Bowler", "AUS", "19/09/2004", 2, 2);    
    input_1("Joe", "Batsman", "SL", "01/01/2023", 100, 0);
    input_1("Mark", "Batsman", "SA", "01/01/2023", 90, 0);
    input_1("Willy", "Batsman", "WI", "01/01/2023", 80, 0);
    input_1("Tom", "Batsman", "BAN", "01/01/2023", 70, 0);
    input_1("Chris", "Batsman", "NZ", "01/01/2023", 60, 0);
    input_1("James", "Bowler", "SL", "01/01/2023", 0, 5);
    input_1("Andrew", "Bowler", "SA", "01/01/2023", 0, 10);
    input_1("Matthew", "Bowler", "WI", "01/01/2023", 0, 15);
    input_1("Joseph", "Bowler", "BAN", "01/01/2023", 0, 20);
    input_1("David", "Bowler", "NZ", "01/01/2023", 0, 25);
}
class test
{
    public : 
    int key  ; 
    string name  ; 
    test(int key)
    {
        this->key = key ; 
        this->name = to_string(key); 
    }

} ; 
int main()
    {
        import_dataset() ; 
        cout<<"enter your name : " ;
        string name ; cin>>name ;  
        cout<<"welcome "<<name<<" to the cricket portal :) "<<endl  ; 
            cout<<"following functionaliteies are been provided : "<<endl ; 
            cout<<"1 . inputting a player information "<<endl ; 
            cout<<"2 . displaying a player information"<<endl ; 
            cout<<"3 . displaying a match information "<<endl ; 
            cout<<"4 . displaying current standings "<<endl ; 
        bool exit = false; 
        while(!exit)
        {
            option :
            cout<<endl ; 
            cout<<"enter the task you want to perform :"; 
            int choice = 0 ; cin>>choice ; 
            if(choice<1 || choice>4){cout<<"invalid choice"<<endl  ; goto option ; }
            else if(choice==1){input_player() ;}
            else if(choice==2){display_player() ;}
            else if(choice==3){display_match() ;}
            else if(choice==4)
            {
              cout<<"enter the list length : " ; 
              int n ; cin>>n ; 
              display_rankings(n) ; 
            }
            cout<<endl<<"======================= THANK YOU ======================= "<<endl<<endl ; 
            string ok ; 
            cout<<"do you want to exit or stay in the portal (answer in yes/no) :  " ; 
            cin>>ok ; 
            if(ok=="no"){exit = true ; }      
        }
        return 0;
    }
    /*end*/ 



























 