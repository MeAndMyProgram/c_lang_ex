/* возвращает значение из стека */

double pop(void)
{
  if(sl >  0)
    return val[--sl];
  else
    printf("error: stack empty\n");
    return 0.0;
}
