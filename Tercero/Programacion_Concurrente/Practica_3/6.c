/*
En un entrenamiento de futbol hay 20 jugadores que forman 4 equipos (cada jugador
conoce el equipo al cual pertenece llamando a la función DarEquipo()). Cuando un
equipo está listo (han llegado los 5 jugadores que lo componen), debe enfrentarse a otro
equipo que también esté listo (los dos primeros equipos en juntarse juegan en la cancha
1, y los otros dos equipos juegan en la cancha 2). Una vez que el equipo conoce la
cancha en la que juega, sus jugadores se dirigen a ella. Cuando los 10 jugadores del
partido llegaron a la cancha comienza el partido, juegan durante 50 minutos, y al
terminar todos los jugadores del partido se retiran (no es necesario que se esperen para
salir).

*/

monitor Team{
    condition queue[1..4];
    int cant[1..4] = ([4],0);
    int team_ready = 0;
    int field = 1;

    procedure join(int team; var f){
      if((cant[team] < 4) or (team_ready == 0)){
        cant[team] ++;
        if(cant[team] == 5){
          team_ready=team;
        }
        wait(queue[team]);
        f = cant[team];
      }else{
        f = field;
        cant[team] = field;
        cant[team_ready] = field;
        signal_all(queue[team]);
        signal_all(queue[team_ready]);
        team_ready = 0;


      }
    }
}


Process Player[1..20]{
  int field = 0;
  int team;

  DarEquipo(team);
  Team.join(team,field);
  wait(3000) //play 50 minutes in field
}
