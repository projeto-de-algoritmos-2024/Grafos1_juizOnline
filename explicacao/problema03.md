## [Dominação Bacteriana](https://judge.beecrowd.com/pt/problems/view/2687)

Problema de grafos nível 7 da plataforma beecrowd | 2687

O Instituto Federal do Sul de Minas (IF), campus Muzambinho abriu vagas para o novo curso superior: Medicina veterinária. A coordenadora do curso já previa alguns problemas com as bactérias estudadas, pois é inevitável que um pote com bactérias caia no chão. Se isso acontecesse, seria difícil controlá-las pois para aplicação do antídoto é necessária uma proporcionalidade, além disso precisa ser jogado ao redor da bactéria, matando de fora para dentro.

Além de uma quantidade exata, o antídoto tem que ser jogado ao redor da bactéria, por isso a área da bactéria precisa ser calculada para que a coordenadora possa aplicar a dose certa. A areá de uma bactéria é dada em um grid(x,y) e nele a coordenadora marca a borda da bactéria representados por 1. A partir disso a área da bactéria é dada pelo (perímetro(borda(1)) + o conteúdo(o lado de dentro da borda ou seja quantidade de zeros cercados por 1) dividido por dois, uma média simples.

Por sua boa reputação, pediu a você para desenvolver um aplicativo que resolva esse problema. Valendo alguns pontos extra, desenvolva o algorítimo capaz de calcular a área dominada pela bactéria, que por sinal possui formatos muitos bizarros, esboçada pela coordenadora, para que a aplicação do antídoto tenha resultado.

### Entrada
A entrada possui Q(0 < Q < 100) quantidades de bactérias expostas, e em seguida uma pequena descrição da área, composta de um inteiro L (0 < L < 15) indicando a largura e altura do grid e por último o grid(LxL) com o desenho da borda da bactéria.

### Saída
Como informado, exiba a área dominada com duas casas decimais.