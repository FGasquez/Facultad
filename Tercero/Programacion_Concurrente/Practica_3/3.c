/** 3. En un laboratorio de genética se debe administrar el uso de una máquina secuenciadora
de ADN. Esta máquina se puede utilizar por una única persona a la vez. Existen 100
personas en el laboratorio que utilizan repetidamente esta máquina para sus estudios,
para esto cada persona pide permiso para usarla, y cuando termina el análisis avisa que
termino. Cuando la máquina está libre se le debe adjudicar a aquella persona cuyo pedido
tiene mayor prioridad (valor numérico entre 0 y 100). **/

Monitor machine{
  condition queue[1..100];
  int priority[1..100] = ([100],0);
  int sleep = 0;
  int count = 0;

  procedure in(p){
    if(count > 0){
      sleep ++;
      priority[p] ++;
      wait(queue[p]);
    }else{
      count ++;
    }
  }

  procedure out(p){
    if(sleep > 0){
      for(i = 0; i < 101; i++ ){
        if(priority[i] > 0 ){
          sleep --;
          signal(queue[i]);
          break;
        }
      }
    }else{
      count --;
    }
  }
}


Process users[id:1..100]{
  machine.in(id);
    //use pc
  machine.out(id);
}
