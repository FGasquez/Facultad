
/** 2. Implementar el acceso a una base de datos de solo lectura que puede atender
a lo sumo 5 consultas simultáneas. **/


monitor DB{
  condition queue;
  int sleep = 0;
  int count = 0;

  procedure in(){
    if(count < 6){
      count ++;
    }else{
      sleep ++;
      wait(queue);
    }
  }

  procedure out(){
    if(count < 6){
      count --;
    }else{
      sleep --;
      signal(queue);
    }
  }
}

Process users[1..N]{
  db.in();
  //use DB
  db.out():
}
