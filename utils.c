int     ft_strcmp(const char *s1, const char *s2)
{
        while (*s1 && *s2 && *s1 == *s2)
        {
                s1++;
                s2++;
        }
        return ((unsigned char) *s1 - (unsigned char) *s2);
}

long  ft_safe_atoi(char *str)
{
        long result;
        int sign;

        result = 0;
        sign = 1;
        if (*str == '-')
        {
                sign = -1;
                str++;
        }
        else if (*str == '+')
                str++;
        while(*str)
        {
                result = result * 10 + *str - '0';
                str++;
        }
        return (result * sign);
}
