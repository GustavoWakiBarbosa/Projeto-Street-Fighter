#include <stdio.h>
// #include <stdlib.h>
#include <locale.h>

int main()
{
    // Gustao Waki Barbosa - RA: 2760482211037
    // Elias Pinheiro Neto - RA: 2760482211024

    /*
    OBJETIVO DO PROGRAMA
    O objetivo do jogo é simular um luta de Street Fighter,
    em que há vários rounds alternando entre golpes dados(Ryu)
    e golpes recebidos(Ken), ganha o round aquele que tiver mais
    pontos, e a partida aquele que tiver mais rounds ganhos.

    O jogo consta com um sistema de golpes com "bônus" de pontos.
    Se o número do ataque for perfeito os pontos referentes a ele são multiplicados por 3.
    Se o número do ataque for triangular os pontos referentes a são multiplicados por 2.
    */

    system("color 3f");
    setlocale(LC_ALL, "Portuguese");

    int pontos_ryu = 0, pontos_ken = 0;
    int vez_jogador = 0;
    int ataque = 1, soma, tipo_bonus;

    while (ataque != 0)
    {
        scanf("%d", &ataque);
        if (ataque > 0)
        {
            vez_jogador = 1;
        }
        else if (ataque < 0)
        {
            vez_jogador = 2;
            ataque *= -1;
        }

        /*
        Verificando se um número é perfeito.
        Se o valor de um golpe for um número perfeito, este terá seu valor multiplicado por 3

        Um número n ∈ ℤ⁺ é dito perfeito se a soma de seus divisores próprios é igual ao próprio número.
        Por exemplo, 6 é um número perfeito, pois seus divisores próprios são 1, 2 e 3 e 1 + 2 + 3 = 6.
        */
        tipo_bonus = 0;
        soma = 0;
        for (int a = 1; a <= ataque / 2; a++)
        {
            if (ataque % a == 0)
            {
                soma += a;
                if (soma < ataque)
                {
                    continue;
                }
                else if (soma == ataque)
                {
                    ataque = ataque * 3;
                    tipo_bonus = 1;
                    break;
                }
                else
                {
                    break;
                }
            }
        }

        if (tipo_bonus == 0)
        {
            /*
            Verificando se o numero é um triangular
            Se o valor de um golpe for um número perfeito, este terá seu valor multiplicado por 2

            Um número n ∈ ℤ⁺ é dito triangular se é igual à soma de todos os números inteiros de 1 até m,
            onde m é um número pertencente a ℤ⁺ tal que m ≤ n. Por exemplo, 6 = 1 + 2 + 3 e 10 = 1 + 2 + 3 + 4 são números triangulares.
            */
            soma = 0;
            for (int i = 1; i <= ataque; i++)
            {
                soma += i;
                if (soma < ataque)
                {
                    continue;
                }
                else if (soma == ataque)
                {
                    // O numero é triangular
                    ataque *= 2;
                    break;
                }
                else
                {
                    // O numero não é triangular
                    break;
                }
            }
        }

        // verifica de quem era o golpe e adiciona os pontos para ele
        if (vez_jogador == 1)
        {
            pontos_ryu = pontos_ryu + ataque;
        }
        else
        {
            pontos_ken = pontos_ken + ataque;
        }
    }

    // Dizer quem ganhou
    if (pontos_ryu > pontos_ken)
    {
        printf("Ryu ganhou\n");
    }
    else if (pontos_ken > pontos_ryu)
    {
        printf("Ken ganhou\n");
    }
    else
    {
        printf("Empate\n");
    }

    printf("Pontos Ryu: %d \nPontos Ken: %d", pontos_ryu, pontos_ken);
}
