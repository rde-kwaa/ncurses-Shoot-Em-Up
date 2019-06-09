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
    Entity entities[4];
    
    entities[0] = Entity(0,0);
    entities[1] = Player(0,0);
    entities[2] = Enemy(20,20);
    entities[3] = Bullet(10,10,"-");
    for(int x = 0; x < sizeof(entities)/sizeof(Entity);x++){
        for(int y = 0; y < sizeof(entities)/sizeof(Entity);y++){
            if(x != y){
                entities[x].collide(entities[y]);
            }
        }
    }
}
