typedef struct aluno{
    char *nome;
    int matricula;
    char *curso;
    char *email;
    int telefone_fixo;
    int celular;
    int tcc;//é inteiro pq a pergunta é se é tcc 1 ou tcc 2
    int semestre;
    int frequencia;
    struct aluno * proximo;
    struct aluno * anterior;
}aluno;



typedef struct professor{    
    char *nome;
    int siape;
    char *email;
    char *instituicao;
    int telefone_fixo;
    int celular;
    struct professor * proximo;
    struct professor * anterior;
}professor;


typedef struct banca{ 
    int id;
    char *titulo;
    char *resumo;
    char *data;
    char *horario;
    char *local_da_banca;
    int matricula;
    struct aluno *aluno;
    struct professor *orientador;
    int siape;
    struct professor *avaliador_1;
    int siape_1;
    struct professor *avaliador_2;
    int siape_2;
    struct banca * proximo;
    struct banca * anterior;
}banca;
