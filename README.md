Com o passar dos anos nos deparamos com o aumento considerável no número de equipamentos portáteis e, portanto, da nossa depedência por pilhas e baterias recarregáveis.

Compreendendo que uma pilha AA com alta resistência interna apresenta uma queda de tensão acentuada quando submetida a uma carga que venha a drenar muita corrente elétrica apresentando, por exemplo, a indicação de "bateria fraca" mesmo que você tenha acabado de tirá-la do carregador, foi desenvolvido um sistema que pode medir sua resistência interna e indicar se ainda está apta para uso.

!["Analisador da saúde de pilha AA"](/cover.png)

Ao identificar a pilha inserida no case, é realizada a medição da tensão da pilha através de um divisor de tensão de alta impedância (para que a resistência interna não interfira). Se for verificado que a pilha está carregada, tensão acima de 1V, um gatilho aciona um relé conectando uma carga de 1,2ohm (forçando a drenagem de uma alta corrente) e uma nova medição é realizada. É importante salientar que o relé fica ativo por apenas 100ms, para não danificar a pilha.

!["Circuito"](/circuito.jpg)

Considerando a primeira medição como circuito aberto (Voc) e a segunda medição como circuito com carga (Vload), é possível estimar a resistência interna com a seguinte fórmula: Rin = 1,2 * (Voc - Vload) / Vload. 

O fluxograma do algoritimo utilizado pode ser visto na figura a seguir e nele consta um estado que é acionado quando a primeira medição (Voc) resulta em um valor abaixo de 1V, os três leds piscam para indicar ao usuário que a pilha não está apta para ser analisada.

!["Fluxograma"](/fluxograma.png)

Os valores de 200miliohm para considerar a pilha saudável e 500miliohm para considerá-la descartável foram calibrados a partir da medição de 10 pilhas novas e 10 pilhas com a autonomia de menos de 1 hora nos equipamentos citados no início deste artigo. Obs.: Como o equipamento está em fase de validação, estes valores podem ser ajustados futuramente. Sugiro, caso implementem, calibrar de acordo aos equipamentos portáteis que utilizem.
