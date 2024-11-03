
{
    for(int i = 1; i <= 9; i++){
        for(int j = 0; j < i - 1; j++){
            printf("*");
        }
        
        printf("%d\n", i);
        for(int m = 9; m > i; m--){
            printf("*", i);
        }
    }
    return 0;
}