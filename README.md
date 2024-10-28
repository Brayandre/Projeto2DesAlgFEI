# Sistema de Mercado Virtual
O código apresentado é uma simulação de um sistema de mercado virtual, onde os usuários podem fazer login, navegar por setores de produtos, escolher itens para compra e adicionar ao carrinho, simulando a experiência de um supermercado online.

O mercado é dividido em vários setores, cada um contendo uma variedade de produtos. Esses setores incluem:

    • Bebidas
    • Açougue
    • Frutas e Vegetais
    • Alimentos Não Perecíveis
    • Limpeza
    • Padaria
    
Cada produto dentro desses setores possui três atributos principais:

    • Nome do produto
    • Quantidade disponível no estoque
    • Preço por unidade
    
Esses produtos estão organizados em arrays (listas), que agrupam os itens de cada setor de maneira estruturada.

# Carrinho de Compras

O sistema também possui uma estrutura de carrinho de compras, onde os itens selecionados pelos usuários são armazenados. Quando o usuário decide comprar um produto, ele escolhe a quantidade desejada, e essa informação é registrada no carrinho. Cada item do carrinho armazena:
  
    • Nome do produto
    • Quantidade comprada
    • Preço por unidade
    • Valor total do item (quantidade * preço unitário)
    
O carrinho serve como um registro temporário das compras até que o cliente finalize a compra ou saia do sistema.

O sistema exige que o usuário faça um login para acessar as funcionalidades do mercado. Cada cliente precisa fornecer um CPF e uma senha para entrar. As credenciais dos clientes são armazenadas em arrays, o que facilita a validação no momento do login.

# Funções do Sistema

1 - Exibição de Produtos
Uma função central do sistema é a exibição dos produtos disponíveis para compra. Quando o cliente faz login, ele pode navegar pelos setores e visualizar as informações detalhadas de cada produto, incluindo nome, quantidade em estoque e preço.

Login recomendado:

     • CPF/Login: "12345678901"
     • senha: "professor"


2 - Adição de Produtos ao Carrinho

Após visualizar os produtos, o cliente pode selecionar quantos itens deseja comprar. Se a quantidade selecionada estiver disponível em estoque, o sistema calcula o valor total da compra (quantidade multiplicada pelo preço unitário) e o adiciona ao carrinho. Caso não haja quantidade suficiente, o sistema avisa ao cliente.

3 - Salvar Carrinho

O sistema também inclui uma função que permite salvar os itens do carrinho em um arquivo binário, utilizando o CPF do cliente como parte do nome do arquivo. Isso serve para persistir os dados da compra, garantindo que o conteúdo do carrinho não seja perdido caso o usuário saia do sistema. Esse arquivo binário é um meio eficiente de armazenar as compras, permitindo que os dados sejam recuperados mais tarde, se necessário.

4 - Lógica de Compras

A navegação pelos setores do mercado segue um padrão simples de interação. O cliente escolhe um setor (por exemplo, bebidas), e o sistema exibe todos os produtos disponíveis nesse setor. Para cada produto, o cliente é questionado se deseja comprar ou não. Se a resposta for afirmativa, ele insere a quantidade que quer adquirir, e o valor total é calculado e exibido. O sistema também atualiza automaticamente a quantidade de estoque do produto, diminuindo com base no que foi comprado.

5 - Formas de Pagamento

O sistema oferece três opções de pagamento para finalizar as compras no carrinho:

    1. Crédito Fei: Cada aluno acumula saldo no Crédito Fei à medida que realiza horas complementares, ganhando R$2,50 para cada hora registrada. 
       O cliente pode utilizar esse saldo para pagar o carrinho, desde que o valor seja suficiente para cobrir o total.
    2. Cartão de Crédito: O cliente pode criar um cartão de crédito virtual com um limite inicial de R$2000. Esse cartão pode ser utilizado para pagamentos no mercado, 
       e o saldo é debitado conforme as compras são realizadas. O pagamento é realizado com sucesso se o saldo do cartão for suficiente para cobrir o valor do carrinho.
    3. Pix: O sistema gera uma chave aleatória de Pix, simulando o pagamento instantâneo. Após a geração da chave, o pagamento é efetuado automaticamente, 
       e o carrinho é registrado como pago.

# OBS

O metódo de pagamento via PIX não necessita de validação, ele automaticamente paga o carrinho, excluindo-o dos arquivos. Esse metódo é apenas uma simualção! 

6 - Interação com o Usuário

O sistema utiliza entradas e saídas de dados via console para permitir que o usuário faça suas escolhas. Isso inclui:

    • Seleção de setores para navegar pelos produtos.
    • Decisão de compra de produtos.
    • Quantidade a ser comprada.
    • Escolha do método de pagamento para finalizar a compra.
    
Além disso, a interface é bem simples, com mensagens claras que guiam o usuário durante a navegação e compras.

# Lista de Participantes

    • Brayan André da Costa. RA 22.124.017-9
    • João Vitor Maciente Rangel. RA: 22.124.017-9
