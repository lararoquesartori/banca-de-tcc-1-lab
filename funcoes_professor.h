professor * inicio_professor = NULL;
professor * fim_professor = NULL;
int tamanho_professor = 0;

int buscar_siape(int siape){
    int v = 0;
    professor * buscador_de_professor = inicio_professor;
    for(int i = 0; i < tamanho_professor; i++){
        if(buscador_de_professor->siape == siape){
            return 1;
        }else if(buscador_de_professor->proximo == NULL)
            v = 0;
        buscador_de_professor = buscador_de_professor->proximo;
    }
    return v;
}

professor * buscar_professor(int siape){
    professor * buscador_de_professor = inicio_professor;
    for(int i = 0; i < tamanho_professor; i++){
        if(buscador_de_professor->siape == siape)
            return buscador_de_professor;
        buscador_de_professor = buscador_de_professor->proximo;
    }
    return NULL;
}

void adicionar_professor(professor * novo_professor){
     if(inicio_professor == NULL ){
            inicio_professor = novo_professor;
            fim_professor = novo_professor;
            tamanho_professor++;
        }else if(buscar_siape(novo_professor->siape) == 0){ //percorrer a lista
            inicio_professor->anterior = novo_professor;
            novo_professor->proximo = inicio_professor;
            inicio_professor = novo_professor;
            tamanho_professor++;
        }else{
            printf("Professor já cadastrado");
        }

}

void cadastrar_professor(char *nome, int siape, char *email, char *instituicao, int telefone_fixo, int celular){
    //adicionamos todos os alunos ao inicio, como não foi definido metodo de cadastro,
    //pelo com melhor complexidade
    professor * novo = malloc(sizeof(professor));
    novo->nome = (char *)malloc(sizeof(char)*100);
    novo->nome = nome;
    novo->instituicao = (char *)malloc(sizeof(char)*100);
    novo->instituicao = instituicao;
    novo->email = (char *)malloc(sizeof(char)*100);
    novo->email = email;
    novo->siape = siape;
    novo->telefone_fixo = telefone_fixo;
    novo->celular = celular;
    novo->proximo = NULL;
    novo->anterior = NULL;
    adicionar_professor(novo);
}

void scan_professor(){

    int siape,telefone_fixo,celular;
    char *nome = (char *)malloc(sizeof(char)*100);
    printf("Escreva o nome do Professor \n");
    scanf(" %[^\n]s", nome);
    char *instituicao = (char *)malloc(sizeof(char)*100);
    printf("Escreva a instituição do Professor\n");
    scanf(" %[^\n]s", instituicao);
    char *email = (char *)malloc(sizeof(char)*100);
    printf("Escreva o email do Professor \n");
    scanf(" %[^\n]s", email);
    printf("Escreva o siap do Professor \n");
    scanf("%d", &siape);
    printf("Escreva o celular do Professor \n");
    scanf("%d", &celular);
    printf("Escreva o telefone fixo do Professor\n");
    scanf("%d", &telefone_fixo);
    cadastrar_professor(nome,siape,email,instituicao,telefone_fixo,celular);
    //free(nome);
    //free(instituicao);
    //free(email);
}

void scan_professor_restrito(int siape){

    int telefone_fixo,celular;
    char *nome = (char *)malloc(sizeof(char)*100);
    printf("Escreva o nome do Professor \n");
    scanf(" %[^\n]s", nome);
    char *instituicao = (char *)malloc(sizeof(char)*100);
    printf("Escreva a instituição do Professor\n");
    scanf(" %[^\n]s", instituicao);
    char *email = (char *)malloc(sizeof(char)*100);
    printf("Escreva o email do Professor \n");
    scanf(" %[^\n]s", email);
    printf("Escreva o celular do Professor \n");
    scanf("%d", &celular);
    printf("Escreva o telefone fixo do Professor\n");
    scanf("%d", &telefone_fixo);
    cadastrar_professor(nome,siape,email,instituicao,telefone_fixo,celular);

    //free(nome);
    //free(instituicao);
    //free(email);
}

int exibir_um_professor(int siape){
    professor * professor = inicio_professor;
    for(int i = 0; i < tamanho_professor; i++){
        if(professor->siape == siape){
            printf("PROFESSOR SELECIONADO: %s \n", professor->nome);
            printf("SIAPE: %d\n", professor->siape);
            printf("EMAIL: %s \n", professor->email);
            printf("INSTITUIÇÃO: %s \n", professor->instituicao);
            printf("TELEFONE: %d\n", professor->telefone_fixo);
            printf("CELULAR: %d\n", professor->celular);
            printf("_____________________________________________\n\n");
            return 0;
        }
        professor = professor->proximo;
    }
    return 0;
}

void exibir_todos_os_professores(){
    if(tamanho_professor != 0){
        printf("________________PROFESSORES________________\n\n");
        professor * professor = inicio_professor;
        for(int i = 0; i < tamanho_professor; i++){
            printf("PROFESSOR: %s \n", professor->nome);
            printf("SIAPE: %d\n", professor->siape);
            printf("EMAIL: %s \n", professor->email);
            printf("INSTITUIÇÃO: %s \n", professor->instituicao);
            printf("TELEFONE: %d\n", professor->telefone_fixo);
            printf("CELULAR: %d\n", professor->celular);
            printf("_____________________________________________\n\n");

            professor = professor->proximo;
        }
    }
}
void abrir_arquivo_professor(){
    FILE *fp =fopen("professor.bin","w");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo");
        return;
    }

    fclose(fp);
}

void ler_arquivo_professor(){
    int numero_professor;
    professor professor_1, * professor_ponteiro;


    FILE *fp =fopen("professor.bin","r");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo...\n");
        return;
    }

    fread(&numero_professor, sizeof(int), 1, fp);

    for (int i = 0; i < numero_professor; i++)
    {


        fread(&professor_1, sizeof(struct professor), 1, fp);

        professor_1.nome = (char *)malloc(sizeof(char)*100);
        professor_1.instituicao = (char *)malloc(sizeof(char)*100);
        professor_1.email = (char *)malloc(sizeof(char)*100);

        fread(professor_1.nome, sizeof(char), 100, fp);
        fread(professor_1.instituicao, sizeof(char), 100, fp);
        fread(professor_1.email, sizeof(char), 100, fp);


        cadastrar_professor(professor_1.nome,professor_1.siape,professor_1.email,professor_1.instituicao,professor_1.telefone_fixo,professor_1.celular);

        //free(professor_1.nome);
        //free(professor_1.instituicao);
        //free(professor_1.email);
        }


    fclose(fp);
}

void salvar_professor(){
    professor * professor_1;
    professor_1 = (professor *)malloc(sizeof(professor));
    professor_1->nome = (char *)malloc(sizeof(char)*100);
    professor_1->instituicao = (char *)malloc(sizeof(char)*100);
    professor_1->email = (char *)malloc(sizeof(char)*100);


    FILE *fp =fopen("professor.bin","w");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo");
        return;
    }

    fwrite(&tamanho_professor, sizeof(int), 1, fp);
    for (int i = 0; i < tamanho_professor; ++i)
    {
        if(i == 0){

            professor_1 = inicio_professor;


            fwrite(professor_1, sizeof(struct professor), 1, fp);
            fwrite(professor_1->nome, sizeof(char), 100, fp);
            fwrite(professor_1->instituicao, sizeof(char), 100, fp);
            fwrite(professor_1->email, sizeof(char), 100, fp);

        }
        else{

            professor_1 = professor_1->proximo;

            fwrite(professor_1, sizeof(struct professor), 1, fp);
            fwrite(professor_1->nome, sizeof(char), 100, fp);
            fwrite(professor_1->instituicao, sizeof(char), 100, fp);
            fwrite(professor_1->email, sizeof(char), 100, fp);


            }
    }

    //free(professor_1.nome);
    //free(professor_1.instituicao);
    //free(professor_1.email);

    fclose(fp);
}

void apagar_professor(int siape){
    if(buscar_siape(siape) == 1){
        professor *professor_excluido = inicio_professor;

        if(inicio_professor->siape == siape){ //inicio
            if(tamanho_professor == 1){
                fim_professor = NULL;
                inicio_professor = NULL;
            }else{
                inicio_professor = inicio_professor->proximo;
                inicio_professor->anterior = NULL;
            }
            free(professor_excluido);
            tamanho_professor--;
        }

        else if(fim_professor->siape == siape){ //fim

            professor *professor_excluido = fim_professor;

            fim_professor->anterior->proximo = NULL;
            fim_professor = fim_professor->anterior;
            free(professor_excluido);
            tamanho_professor--;

        }else{//meio
           professor * buscador = inicio_professor;
            while(buscador->siape != siape){
                    buscador = buscador->proximo;
            }
            buscador->anterior->proximo = buscador->proximo;
            buscador->proximo->anterior = buscador->anterior;
            free(buscador);
            tamanho_professor--;
        }

    }else{

        printf("Tentou-se remover um professor que não existe! :/ \n");
    }
}

void atualizar_professor(){
    int siape;
    printf("digite a siape do professor paraa atualiza-lo\n");
    scanf("%d", &siape);
    if(buscar_siape(siape) == 0){
        printf("siape incorreto");
    }else{
        exibir_um_professor(siape);
        printf("\n Coloque os novos valores do professor\n");
        apagar_professor(siape);
        scan_professor_restrito(siape);
    }
}
