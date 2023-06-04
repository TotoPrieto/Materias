public class Algoritmos<T>{
  


  //<--------------------------------------------------------------------------------------------->
  //1.     Retorna true si un dígrafo contiene un subgrafo cuadrado, false en caso contrario. 
  // Un subgrafo cuadrado es un ciclo simple de longitud 4

  public boolean subgrafoCuadrado(Grafo<T> grafo){
    boolean b=false;
    //Debe verificar si hay algun subgrafo que en 4 vertives vuelva al mismo lugar.
    return b;
  }



  //<--------------------------------------------------------------------------------------------->
  //Retorna el grado del digrafo pasado como parámetro. El grado de un digrafo es el de su vértice de grado máximo. 
  //El grado de un vértice en un grafo dirigido es la suma del número de aristas que salen de él (grado de salida) 
  //y el número de aristas que entran en él (grado de entrada).

  public int getGrado(Grafo<T> grafo){
    int max=0, grado=0;
  
    if(!grafo.esVacio()){
      ListaGenerica<Vertice<T>> listV= grafo.listaDeVertices();
      int gradActS, i;
      int [] gradActE= new int[listV.tamanio()];
      Vertice<T> act= null;
      ListaGenerica<Arista<T>> sig= null;
      Arista<T> ari;
    
      for(i=0; i<listV.tamanio(); i++){
        act= grafo.vertice(i);
        sig=grafo.listaDeAdyacentes(act);
        sig.comenzar();
      
        while(!sig.fin()){ //corroboro las aristas de salida
          ari=sig.proximo();
          gradActE[ari.verticeDestino().posicion()]++;
        }
      }
      
      for(i=0; i<listV.tamanio(); i++){
          gradActS=0;
          act= grafo.vertice(i);
          sig=grafo.listaDeAdyacentes(act);
          gradActS=sig.tamanio();

          grado= gradActS + gradActE[i];
          if(grado>max)
            max=grado;
      }
    }
    return grado;
}


//// Retorna true si el grafo dirigido pasado como parámetro tiene al menos un ciclo, false en caso contrario.

 public boolean tieneCiclo(Grafo<T> grafo){
  boolean b;
  if(!grafo.esVacio()){
    int i;
    ListaGenerica<Vertice<T>> lisV= grafo.listaDeVertices();
    Vertice<T> act;
    boolean[] visitado= new boolean [lisV.tamanio()];
    for(i=0; i<lisV.tamanio();i++){
      act=lisV.elemento(i);
      b=tieneCicloRec(act, lisV.proximo(), visitado, grafo); //Mando como aux al lisV.proximo() para que no se toque el act y el aux al principio
      //No importa que en el ultimo llamado del for mande null el proximo, total su valor no lo uso hasta que recursa
      
      if(b==true){
        return true;
      }
    }
  }
  return false;
 }

 //siempre mando el mismo actual. Lo que hago es revisar todas sus aristas para ver si alguna se conecta consigo misma
 private boolean tieneCicloRec(Vertice<T>actual, Vertice<T> aux, boolean[] visitado, Grafo<T> grafo){

  if(actual.dato().equals(aux.dato())){
    return true;
  }

  boolean b=false;
  visitado[aux.posicion()]=true;
  ListaGenerica<Arista<T>> ady= grafo.listaDeAdyacentes(actual);
  Vertice<T> sig;
  while(!ady.fin()){
   sig=ady.proximo().verticeDestino();
   int pos= sig.posicion();
    if(!visitado[pos]){
      b=tieneCicloRec(actual, sig, visitado, grafo);
      if(b==true)
        return true; // Como debe buscar al menos un ciclo, al encontrar uno solo lo hago salir de la recursion
      visitado[pos]=false;  
    }
  }
  return false;
 }


}
