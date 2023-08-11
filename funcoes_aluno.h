aluno * inicio_aluno = NULL;
aluno * fim_aluno = NULL;
int tamanho_aluno = 0;

int buscar_matricula(int matricula){
    int v = 0;
    aluno * buscador_de_aluno = inicio_aluno;
    for(int i = 0; i < tamanho_aluno; i++){
        if(buscador_de_aluno->matricula == matricula){
            return 1;
        }else if(buscador_de_aluno->proximo == NULL)
            v = 0;
        buscador_de_aluno = buscador_de_aluno->proximo;
    }
    return v;
    
}

aluno * buscar_aluno(int matricula){
    aluno * buscador_de_aluno = inicio_aluno;
    for(int i = 0; i < tamanho_aluno; i++){
        if(buscador_de_aluno->matricula == matricula)
            return buscador_de_aluno;
        buscador_de_aluno = buscador_de_aluno->proximo;
    }
    return NULL;
}
void adicionar_aluno(aluno * novo){
    if(inicio_aluno == NULL ){
            inicio_aluno = novo;
            fim_aluno = novo;
            tamanho_aluno++;
        }else if(buscar_matricula(novo->matricula) == 0){ //percorrer a lista
            inicio_aluno->anterior = novo;
            novo->proximo = inicio_aluno;
            inicio_aluno = novo;
            tamanho_aluno++;
        }else{
            printf("Aluno já cadastrado");
        }
}

void cadastrar_aluno(char *nome, int matricula, char *curso, char *email, int telefone_fixo, int celular, int tcc, int semestre, int frequencia){
    //adicionamos todos os alunos ao inicio_aluno, como não foi definido metodo de cadastro,
    //pelo com melhor complexidade
        aluno * novo = malloc(sizeof(aluno));
        novo->nome = (char *)malloc(sizeof(char)*100);
        novo->nome = nome;
        novo->curso = (char *)malloc(sizeof(char)*100); 
        novo->curso = curso;
        novo->email = (char *)malloc(sizeof(char)*100); 
        novo->email = email;
        novo->matricula = matricula;
        novo->celular = celular;
        novo->tcc = tcc;
        novo->telefone_fixo = telefone_fixo;
        novo->semestre = semestre;
        novo->frequencia = frequencia;
        novo->proximo = NULL;
        novo->anterior = NULL;
        adicionar_aluno(novo);
}
        
void scan_aluno(){
        int matricula, celular,tcc,telefone_fixo, semestre,frequencia;
        char *nome = (char *)malloc(sizeof(char)*100);
        printf("Escreva o nome do Aluno \n");
        scanf(" %[^\n]s", nome);
        char *curso = (char *)malloc(sizeof(char)*100); 
        printf("Escreva o curso do Aluno \n");
        scanf(" %[^\n]s", curso);
        char *email = (char *)malloc(sizeof(char)*100); 
        printf("Escreva o email do Aluno \n");
        scanf(" %[^\n]s", email);
        printf("Escreva a matricula do Aluno \n");
        scanf("%d", &matricula);
        printf("Escreva o celular do Aluno \n");
        scanf("%d", &celular);
        printf("Escreva o tcc do Aluno \n");
        scanf("%d", &tcc);
        printf("Escreva o semestre do Aluno \n");
        scanf("%d", &semestre);
        printf("Escreva a frequencia do Aluno \n");
        scanf("%d", &frequencia);
        printf("Escreva o telefone fixo do Aluno \n");
        scanf("%d", &telefone_fixo);
        cadastrar_aluno(nome,matricula,curso,email,telefone_fixo,celular,tcc,semestre,frequencia);
}

void scan_aluno_restrito(int matricula){
        int celular,tcc,telefone_fixo, semestre,frequencia;
        char *nome = (char *)malloc(sizeof(char)*100);
        printf("Escreva o nome do Aluno \n");
        scanf(" %[^\n]s", nome);
        char *curso = (char *)malloc(sizeof(char)*100); 
        printf("Escreva o curso do Aluno \n");
        scanf(" %[^\n]s", curso);
        char *email = (char *)malloc(sizeof(char)*100); 
        printf("Escreva o email do Aluno \n");
        scanf(" %[^\n]s", email);
        printf("Escreva o celular do Aluno \n");
        scanf("%d", &celular);
        printf("Escreva o tcc do Aluno \n");
        scanf("%d", &tcc);
        printf("Escreva o semestre do Aluno \n");
        scanf("%d", &semestre);
        printf("Escreva a frequencia do Aluno \n");
        scanf("%d", &frequencia);
        printf("Escreva o telefone fixo do Aluno \n");
        scanf("%d", &telefone_fixo);
        cadastrar_aluno(nome,matricula,curso,email,telefone_fixo,celular,tcc,semestre,frequencia);
} 


int exibir_um_aluno(int matricula){
    aluno * aluno = inicio_aluno;
    for(int i = 0; i < tamanho_aluno; i++){
        if(aluno->matricula == matricula){
            printf("ALUNO SELECIONADO: %s \n", aluno->nome);
            printf("MATRICULA: %d\n", aluno->matricula);
            printf("CURSO: %s \n", aluno->curso);
            printf("EMAIL: %s \n", aluno->email);
            printf("CELULAR: %d\n", aluno->celular);
            printf("TCC: %d \n", aluno->tcc);
            printf("TELEFONE: %d\n", aluno->telefone_fixo);
            printf("SEMESTRES: %d\n", aluno->semestre);
            printf("FREQUENCIA: %d\n", aluno->frequencia);
            printf("_____________________________________________\n\n"); 
            return 0;
        }  
        aluno = aluno->proximo;
    }
    return 0;
}


void exibir_todos_os_alunos(){
    if(tamanho_aluno != 0){
        printf("________________ALUNOS________________\n\n");
        aluno * aluno = inicio_aluno;
        for(int i = 0; i < tamanho_aluno; i++){
            printf("ALUNO: %s \n", aluno->nome);
            printf("MATRICULA: %d\n", aluno->matricula);
            printf("CURSO: %s \n", aluno->curso);
            printf("EMAIL: %s \n", aluno->email);
            printf("CELULAR: %d\n", aluno->celular);
            printf("TCC: %d \n", aluno->tcc);
            printf("TELEFONE: %d\n", aluno->telefone_fixo);
            printf("SEMESTRES: %d\n", aluno->semestre);
            printf("_____________________________________________\n\n");
            
            aluno = aluno->proximo;
        }
    }
}
void abrir_arquivo_aluno(){
    FILE *fp =fopen("aluno.bin","w");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo");
        return;
    }
    fclose(fp);
}

void ler_arquivo_aluno()
{
    int numero_aluno;
    aluno aluno_1;
    
    
    FILE *fp =fopen("aluno.bin","r");
    if (fp == NULL)
    {
        printf("nao foi possivel abrir o arquivo");
        return;
    }
    
    fread(&numero_aluno, sizeof(int), 1, fp);
    
    for (int i = 0; i < numero_aluno; i++)
    {
        
        
        fread(&aluno_1, sizeof(struct aluno), 1, fp);
        
        aluno_1.nome = (char *)malloc(sizeof(char)*100);
        aluno_1.curso = (char *)malloc(sizeof(char)*100);
        aluno_1.email = (char *)malloc(sizeof(char)*100);
        
        fread(aluno_1.nome, sizeof(char), 100, fp);
        fread(aluno_1.curso, sizeof(char), 100, fp);
        fread(aluno_1.email, sizeof(char), 100, fp);
        
        
        cadastrar_aluno(aluno_1.nome,aluno_1.matricula,aluno_1.curso,aluno_1.email,aluno_1.telefone_fixo,aluno_1.celular,aluno_1.tcc,aluno_1.semestre,aluno_1.frequencia);
        
    }  

    fclose(fp);
}

void salvar_aluno(){
    aluno * aluno_1;
    aluno_1 = (aluno *)malloc(sizeof(aluno));
    aluno_1->nome = (char *)malloc(sizeof(char)*100);
    aluno_1->curso = (char *)malloc(sizeof(char)*100);
    aluno_1->email = (char *)malloc(sizeof(char)*100);

    
    FILE *fp =fopen("aluno.bin","w");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo");
        return;
    }
    
    fwrite(&tamanho_aluno, sizeof(int), 1, fp);
    for (int i = 0; i < tamanho_aluno; ++i){
        if(i == 0){
            
            aluno_1 = inicio_aluno;


        fwrite(aluno_1, sizeof(struct aluno), 1, fp);
        fwrite(aluno_1->nome, sizeof(char), 100, fp);
        fwrite(aluno_1->curso, sizeof(char), 100, fp);
        fwrite(aluno_1->email, sizeof(char), 100, fp);
        

        
        }
        else{
            
            aluno_1 = aluno_1->proximo;
            fwrite(aluno_1, sizeof(struct aluno), 1, fp);
            fwrite(aluno_1->nome, sizeof(char), 100, fp);
            fwrite(aluno_1->curso, sizeof(char), 100, fp);
            fwrite(aluno_1->email, sizeof(char), 100, fp);
            

        }
    }
    

    
    fclose(fp);
    
        
        
}


void apagar_aluno(int matricula){

    if(buscar_matricula(matricula) == 1){
        aluno *aluno_excluido = inicio_aluno;

        if(inicio_aluno->matricula == matricula){ //inicio
            if(tamanho_aluno == 1){
                fim_aluno = NULL;
                inicio_aluno = NULL;
            }else{
                inicio_aluno = inicio_aluno->proximo;
                inicio_aluno->anterior = NULL;
            }
            free(aluno_excluido);
            tamanho_aluno--;
        }

        else if(fim_aluno->matricula == matricula){ //fim

            aluno *aluno_excluido = fim_aluno;

            fim_aluno->anterior->proximo = NULL;
            fim_aluno = fim_aluno->anterior;
            free(aluno_excluido);
            tamanho_aluno--;

        }else{//meio
           aluno * buscador = inicio_aluno;
            while(buscador->matricula != matricula){
                    buscador = buscador->proximo;
            }
            buscador->anterior->proximo = buscador->proximo;
            buscador->proximo->anterior = buscador->anterior;
            free(buscador);
            tamanho_aluno--;
        }

    }else{
        printf("Tentou-se remover um aluno que não existe! :/ \n");
    }
}

void atualizar_aluno(){
    int matricula;
    printf("digite a matricula do aluno a ter seus dados atualizados\n");
    scanf("%d", &matricula);
    if(buscar_matricula(matricula) == 0){
        printf("Matricula incorreta");
    }else{
        exibir_um_aluno(matricula);
        printf("\n Coloque os novos valores do aluno\n");
        apagar_aluno(matricula);
        scan_aluno_restrito(matricula);
    }
}
