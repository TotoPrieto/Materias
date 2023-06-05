public class Delta<String>{



  //-------------------------------------------------------------------------------------------
  //Retorna el número máximo de islas distintas que se pueden recorrer en el grafo comprando un único boleto.
  
  
  public int maxIslasDistintas(Grafo<String> grafo) {
    int resultado=0, cant=0;
  
    if((grafo!=null)&&(!grafo.esVacio())){
      ListaGenerica<Vertice<String>> listaV=grafo.listaDeVertices();
      boolean visitado[]=new boolean[listaV.tamanio()];
      resultado=maxIslasDistintas(grafo, visitado, listaV.elemento(0),cant, resultado);
    }
  
    return resultado;
  } 

  private int maxIslasDistintas(Grafo<String> grafo, boolean[] visitado, Vertice<String> act, int cant,int max){
    visitado[act.posicion()]=true;
    int islaproximavisitada=0;
    ListaGenerica<Arista<String>> ady= grafo.listaDeAdyacentes(act);
    cant++;
    Arista<String> proxima;
    
    while(!ady.fin()){
      proxima=ady.proximo();
  
      if(!visitado[proxima.verticeDestino().posicion()]){
        max=maxIslasDistintas(grafo, visitado, proxima.verticeDestino(),cant, max);
        islaproximavisitada++;
    }
  }
  
  if(islaproximavisitada==0){
    if(cant>max){
      max=cant;
    }
  }
  
  visitado[act.posicion()]=false;
  return max;
  }



}