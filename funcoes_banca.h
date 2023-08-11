banca * inicio_banca = NULL;
banca * fim_banca = NULL;
int tamanho_banca = 0;

int buscar_id(int id){
    int v = 0;
    banca * buscador_de_banca = inicio_banca;
    for(int i = 0; i < tamanho_banca; i++){
        if(buscador_de_banca->id == id){
            return 1;
        }else if(buscador_de_banca->proximo == NULL)
            v = 0;
        buscador_de_banca = buscador_de_banca->proximo;
    }
    return v;
}

banca * buscar_banca(int id){
    banca * buscador_de_banca = inicio_banca;
    for(int i = 0; i < tamanho_banca; i++){
        if(buscador_de_banca->id == id)
            return buscador_de_banca;
        buscador_de_banca = buscador_de_banca->proximo;
    }
    return NULL;
}

void adicionar_banca(banca * novo){
    if(tamanho_banca == 0){
        inicio_banca = novo;
        fim_banca = novo;
        tamanho_banca++;
    }else if(buscar_id(novo->id) == 0){ //buscar_id percorre a lista
        inicio_banca->anterior = novo;
        novo->proximo = inicio_banca;
        inicio_banca = novo;
        tamanho_banca++;
    }else{
        printf("Banca com ID já cadastrado \n");
    }
}

void cadastrar_banca(int id, char *titulo, char *resumo, char *data, char *horario, char *local_da_banca, int matricula_aluno, int siape_orientador, int siape_avaliador_1, int siape_avaliador_2){
    banca * novo = malloc(sizeof(banca));
    novo->id = id;
    novo->resumo = resumo;
    novo->titulo = titulo;
    novo->data = data;
    novo->horario = horario;
    novo->local_da_banca = local_da_banca;
    int verificacao_aluno = buscar_matricula(matricula_aluno);
    if(verificacao_aluno == 1){
        novo->aluno = buscar_aluno(matricula_aluno);
        novo->matricula = matricula_aluno;
    }else{
        printf("Aluno não cadastrado no banco de dados.\n");
        return;
        }
    int verificacao_orientador = buscar_siape(siape_orientador);
    if(verificacao_orientador == 1){
        novo->orientador = buscar_professor(siape_orientador);
        novo->siape = siape_orientador;
    }else{
        printf("Professor não cadastrado no banco de dados.\n");
        return;
    }
    int verificacao_avaliador_1 = buscar_siape(siape_avaliador_1);
    if(verificacao_avaliador_1 == 1){
        novo->avaliador_1 = buscar_professor(siape_avaliador_1);
        novo->siape_2 = siape_avaliador_1;
    }else{
        printf("Professor não cadastrado no banco de dados. \n");
        return;
    }
    int verificacao_avaliador_2 = buscar_siape(siape_avaliador_2);
    if(verificacao_avaliador_2 == 1){
        novo->avaliador_2 = buscar_professor(siape_avaliador_2);
        novo->siape_2 = siape_avaliador_2;
    }else{
        printf("Professor não cadastrado no banco de dados. \n");
        return;
    }
    novo->proximo = NULL;
    novo->anterior = NULL;
    adicionar_banca(novo);
}

void scan_banca(){
    int id,siape,telefone_fixo,celular,matricula_aluno,siape_orientador,siape_avaliador_1,siape_avaliador_2;
    char *titulo = (char *)malloc(sizeof(char)*100);
    printf("Escreva o titulo do TCC \n");
    scanf(" %[^\n]s", titulo);
    char *resumo = (char *)malloc(sizeof(char)*100);
    printf("Escreva o Resumo do TCC\n");
    scanf(" %[^\n]s", resumo);
    char *data = (char *)malloc(sizeof(char)*100);
    printf("Escreva o data da apresentação\n");
    scanf(" %[^\n]s", data);
    char *horario = (char *)malloc(sizeof(char)*100);
    printf("Escreva o horario da apresentação\n");
    scanf(" %[^\n]s", horario);
    char *local_da_banca = (char *)malloc(sizeof(char)*100);
    printf("Escreva o local da apresentação\n");
    scanf(" %[^\n]s", local_da_banca);
    printf("Escreva o id da Banca \n");
    scanf("%d", &id);
    printf("Escreva a matricula do aluno do tcc \n");
    scanf("%d", &matricula_aluno);
    printf("Escreva o siape do orientador \n");
    scanf("%d", &siape_orientador);
    printf("Escreva o siape do primeiro avaliador \n");
    scanf("%d", &siape_avaliador_1);
    printf("Escreva o siape do segundo avaliador \n");
    scanf("%d", &siape_avaliador_2);
    cadastrar_banca( id,titulo,resumo,data,horario,local_da_banca,matricula_aluno, siape_orientador,siape_avaliador_1,siape_avaliador_2);

        //free(titulo);
        //free(resumo);
        //free(data);
        //free(horario);
        //free(local_da_banca);
}

void scan_banca_restrita(int id){
    int siape,telefone_fixo,celular,matricula_aluno,siape_orientador,siape_avaliador_1,siape_avaliador_2;
    char *titulo = (char *)malloc(sizeof(char)*100);
    printf("Escreva o titulo do TCC \n");
    scanf(" %[^\n]s", titulo);
    char *resumo = (char *)malloc(sizeof(char)*100);
    printf("Escreva o Resumo do TCC\n");
    scanf(" %[^\n]s", resumo);
    char *data = (char *)malloc(sizeof(char)*100);
    printf("Escreva o data da apresentação\n");
    scanf(" %[^\n]s", data);
    char *horario = (char *)malloc(sizeof(char)*100);
    printf("Escreva o horario da apresentação\n");
    scanf(" %[^\n]s", horario);
    char *local_da_banca = (char *)malloc(sizeof(char)*100);
    printf("Escreva o local da apresentação\n");
    scanf(" %[^\n]s", local_da_banca);
    printf("Escreva a matricula do aluno do tcc \n");
    scanf("%d", &matricula_aluno);
    printf("Escreva o siape do orientador \n");
    scanf("%d", &siape_orientador);
    printf("Escreva o siape do primeiro avaliador \n");
    scanf("%d", &siape_avaliador_1);
    printf("Escreva o siape do segundo avaliador \n");
    scanf("%d", &siape_avaliador_2);
    cadastrar_banca( id,titulo,resumo,data,horario,local_da_banca,matricula_aluno, siape_orientador,siape_avaliador_1,siape_avaliador_2);

        //free(titulo);
        //free(resumo);
        //free(data);
        //free(horario);
        //free(local_da_banca);
}

void exibir_uma_banca(int id){
    banca * banca = inicio_banca;
    for(int i = 0; i < tamanho_banca; i++){
        if(banca->id == id){
            printf("ID DA BANCA: %d \n", banca->id);
            printf("TITULO DA BANCA:\n%s\n", banca->titulo);
            printf("RESUMO:\n%s\n", banca->resumo);
            printf("ALUNO: %s\n", banca->aluno->nome);
            printf("ORIENTADOR: %s\n", banca->orientador->nome);
            printf("AVALIADOR_01: %s\n", banca->avaliador_1->nome);
            printf("AVALIADOR_02: %s\n", banca->avaliador_2->nome);
            printf("_____________________________________________\n\n");
            return;
        }
        banca = banca->proximo;
    }
    return;
}

void exibir_todas_as_banca(){
    if(tamanho_banca != 0){
        printf("________________BANCAS DE TCC________________\n\n");
        banca * banca = inicio_banca;
        for(int i = 0; i < tamanho_banca; i++){
            printf("ID DA BANCA: %d \n", banca->id);
            printf("TITULO DA BANCA:\n%s\n", banca->titulo);
            printf("RESUMO:\n%s\n", banca->resumo);
            printf("ALUNO: %s\n", banca->aluno->nome);
            printf("ORIENTADOR: %s\n", banca->orientador->nome);
            printf("AVALIADOR_01: %s\n", banca->avaliador_1->nome);
            printf("AVALIADOR_02: %s\n", banca->avaliador_2->nome);
            printf("_____________________________________________\n\n");

            banca = banca->proximo;
        }
    }
}

void abrir_arquivo_banca(){
    FILE *fp = fopen("banca.bin","w");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo");
        return;
    }
    fclose(fp);
}

void ler_arquivo_banca(){
    int numero_banca;
    banca banca_1;


    FILE *fp =fopen("banca.bin","r");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo..\n");
        return;
    }

    fread(&numero_banca, sizeof(int), 1, fp);

    for (int i = 0; i < numero_banca; i++){

        fread(&banca_1, sizeof(struct banca), 1, fp);

        banca_1.titulo = (char *)malloc(sizeof(char)*100);
        banca_1.resumo = (char *)malloc(sizeof(char)*100);
        banca_1.data = (char *)malloc(sizeof(char)*100);
        banca_1.horario = (char *)malloc(sizeof(char)*100);
        banca_1.local_da_banca = (char *)malloc(sizeof(char)*100);


        fread(banca_1.titulo, sizeof(char), 100, fp);
        fread(banca_1.resumo, sizeof(char), 100, fp);
        fread(banca_1.data, sizeof(char), 100, fp);
        fread(banca_1.horario, sizeof(char), 100, fp);
        fread(banca_1.local_da_banca, sizeof(char), 100, fp);

        cadastrar_banca(banca_1.id,banca_1.titulo,banca_1.resumo,banca_1.data,banca_1.horario,banca_1.local_da_banca,banca_1.matricula,banca_1.siape,banca_1.siape_1,banca_1.siape_2);

        //free(banca_1.titulo);
        //free(banca_1.resumo);
        //free(banca_1.data);
        //free(banca_1.horario);
        //free(banca_1.local_da_banca);
        //free(banca_1);
    }
    fclose(fp);
}

void salvar_banca(){
    banca * banca_1;
    banca_1 = (banca *)malloc(sizeof(banca));
    banca_1->titulo = (char *)malloc(sizeof(char)*100);
    banca_1->resumo = (char *)malloc(sizeof(char)*100);
    banca_1->data = (char *)malloc(sizeof(char)*100);
    banca_1->horario = (char *)malloc(sizeof(char)*100);
    banca_1->local_da_banca = (char *)malloc(sizeof(char)*100);


    FILE *fp =fopen("banca.bin","w");
    if (fp == NULL){
        printf("nao foi possivel abrir o arquivo");
        return;
    }

    fwrite(&tamanho_banca, sizeof(int), 1, fp);
    for (int i = 0; i < tamanho_banca; ++i){
        if(i == 0){

            banca_1 = inicio_banca;


            fwrite(banca_1, sizeof(struct banca), 1, fp);
            fwrite(banca_1->titulo, sizeof(char), 100, fp);
            fwrite(banca_1->resumo, sizeof(char), 100, fp);
            fwrite(banca_1->data, sizeof(char), 100, fp);
            fwrite(banca_1->horario, sizeof(char), 100, fp);
            fwrite(banca_1->local_da_banca, sizeof(char), 100, fp);
        }else{

            banca_1 = banca_1->proximo;

            fwrite(banca_1, sizeof(struct banca), 1, fp);
            fwrite(banca_1->titulo, sizeof(char), 100, fp);
            fwrite(banca_1->resumo, sizeof(char), 100, fp);
            fwrite(banca_1->data, sizeof(char), 100, fp);
            fwrite(banca_1->horario, sizeof(char), 100, fp);
            fwrite(banca_1->local_da_banca, sizeof(char), 100, fp);
        }
    }
    //free(banca_1.titulo);
    //free(banca_1.resumo);
    //free(banca_1.data);
    //free(banca_1.horario);
    //free(banca_1.local_da_banca);
    //free(banca_1);
    fclose(fp);

}

void apagar_banca(int id){
    if(buscar_id(id) == 1){
        banca *banca_excluido = inicio_banca;

        if(inicio_banca->id == id){ //inicio
            if(tamanho_banca == 1){
                fim_banca = NULL;
                inicio_banca = NULL;
            }else{
                inicio_banca = inicio_banca->proximo;
                inicio_banca->anterior = NULL;
            }
            free(banca_excluido);
            tamanho_banca--;
        }else if(fim_banca->id == id){ //fim

            banca *banca_excluido = fim_banca;

            fim_banca->anterior->proximo = NULL;
            fim_banca = fim_banca->anterior;
            free(banca_excluido);
            tamanho_banca--;
        }else{//meio
            banca * buscador = inicio_banca;
            while(buscador->id != id){
                buscador = buscador->proximo;
            }
            buscador->anterior->proximo = buscador->proximo;
            buscador->proximo->anterior = buscador->anterior;
            free(buscador);
            tamanho_banca--;
        }
    }else{
        printf("Tentou-se remover um banca que não existe! :/ \n");
    }
}

void atualizar_banca(){
    int id;
    printf("Digite o id da banca a se atualizar\n");
    scanf("%d", &id);
    if(buscar_id(id) == 0){
        printf("ID incorreto");
    }else{
        exibir_uma_banca(id);
        printf("\nColoque os novos valores da banca\n");
        apagar_banca(id);
        scan_banca_restrita(id);
    }
}
