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
  boolean b=false;

  if(!grafo.esVacio()){
    boolean[] visitado=new boolean[grafo.listaDeVertices().tamanio()];
    
  
  
  }
  return b;
 }



}
