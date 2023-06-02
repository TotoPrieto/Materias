public class Mapa {

  //Construccion basica
  public Grafo<String> mapaCiudades;

  public Mapa(Grafo<String> ciudades){
    this.mapaCiudades=ciudades;
  }

  public Mapa(){
  
  }

  public void setmapaCiudades(Grafo<String> ciudades){
    this.mapaCiudades=ciudades;
  }

  public Grafo<String> getmapaCiudades(){
    return mapaCiudades;
  }

  //Metodos

  public ListaGenerica<String> devoolverCamino(String ciudad1, String ciudad2){
    ListaGenerica<String> listaCaminos = new ListaGenericaEnlazada<String>();
    
    if(!mapaCiudades.esVacio()){
      boolean[] visitado= new boolean[mapaCiudades.listaDeVertices().tamanio()];
      Vertice<String> origen= devolverVerice(ciudad1);
    
      if (origen.dato().equals(ciudad1)){

        //Doy por hecho que es un unico grafo conexo, porque si no se conectan chau.
        
        dfs(listaCaminos, visitado, origen, ciudad2);
      
      }
      
    }
  return listaCaminos;
}


  public void dfs (ListaGenerica<String> listaCamino, boolean[] visitado, Vertice<String> vActual, String destino){
    visitado[vActual.posicion()]=true;  
    
    if(vActual.dato().equals(destino)){  
      listaCamino.agregarInicio(vActual.dato());
  
    }else{
      ListaGenerica<Arista<String>> ady= mapaCiudades.listaDeAdyacentes(vActual);
      ady.comenzar();
      
      while(!ady.fin()&&(listaCamino.esVacia())){
        Arista<String> siguiente= ady.proximo();
        //si el siguiente Vertice ya fue visitado, pregunto por otro
        if(!visitado[siguiente.verticeDestino().posicion()])
          dfs(listaCamino, visitado, siguiente.verticeDestino(), destino);
  
      }  
      //Una vez que sale(porque puede ser que la lista ya no este vacia) pregunta si agrega si ciudad, y vuelve de la recursion
      if(!listaCamino.esVacia())
        listaCamino.agregarInicio(vActual.dato());
    }
    }
  
  public Vertice<String> devolverVerice(String c1){
    
    Vertice<String> vertAct=null;

    int i=0;
    int numTot= mapaCiudades.listaDeVertices().tamanio()-1;
    
    vertAct= mapaCiudades.vertice(i);
    
    while((i<numTot)&&(!vertAct.dato().equals(c1))){
      i++;
      vertAct= mapaCiudades.vertice(i);
    }

    return vertAct;
  }


}
