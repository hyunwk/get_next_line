char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!(*s))
			return (0);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len_src;

	if (!src)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	while (i++ < dstsize - (size_t)1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (len_src);
}
