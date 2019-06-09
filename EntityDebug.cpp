#include "./inc/Entity.hpp"
#include "./inc/Enemy.hpp"
#include "./inc/Player.hpp"
#include "./inc/Bullet.hpp"

// int main(){
//     Entity *entities[4];
//     entities[0] = new Entity(0,0);
//     entities[1] = new Player(0,0);
//     entities[2] = new Enemy(20,20);
//     entities[3] = new Bullet(10,10,"-");
//     for(int x = 0; x < sizeof(entities)/8;x++){
//         for(int y = 0; y < sizeof(entities)/8;y++){
//             if(x != y){
//                 entities[x]->collide(*entities[y]);
//             }
//         }
//     }
// }


int main(){
    int j , k = 0;
    Entity entities[15];
    
    entities[0] = Entity(7,8);
    entities[1] = Entity(4,5);
    entities[2] = Entity(1,1);
    entities[3] = Entity(0,1);
    entities[4] = Entity(1,0);
    entities[5] = Entity(7,8);
    

    entities[6] = Enemy(7,8);
    entities[7] = Enemy(4,5);
    entities[8] = Enemy(1,1);
    entities[9] = Enemy(0,1);
    entities[10] = Enemy(1,0);
    entities[11] = Enemy(7,8);

    entities[12] = Player(0,0);
    entities[13] = Enemy(20,20);
    entities[14] = Bullet(10,10,"-");
     for(int x = 0; x < sizeof(entities)/sizeof(Entity);x++){
       std::cout << "entity nu : " << x << " life : " << entities[x].getHp() << std::endl;   
         for(int y = 0; y < sizeof(entities)/sizeof(Entity);y++){        
             if(x != y){
                entities[x].collide(entities[y]);
               }
         }
     }
}