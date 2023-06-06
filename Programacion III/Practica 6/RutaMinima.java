public class RutaMinima{

  private ListaGenerica<String> caminoMasCorto;
  private int cantBoletos;

  public RutaMinima(){
    caminoMasCorto=new ListaGenericaEnlazada<String>();
    cantBoletos=1;
  }

  public ListaGenerica<String> getLista(){
    return caminoMasCorto;
  }

  public void setLista(ListaGenerica<String> listaGenerica){
    this.caminoMasCorto=listaGenerica;
  }

  public int getBoletos(){
    return cantBoletos;
  }

  public void agregarBoletos(){
    cantBoletos++;
  }

  public void eliminarBoletos(){
    cantBoletos--;  
  }

  
  public void setBoletos(int i){
    cantBoletos=i;
  }
}

