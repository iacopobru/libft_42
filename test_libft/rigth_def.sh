HEADER_FILE="../libft.h"

# Controllo se il file esiste
if [ ! -f "$HEADER_FILE" ]; then
    echo "[ERROR] Il file $HEADER_FILE non esiste."
    exit 1
fi


function is_rigth_def()
{
	grep_output=$(grep "$1" "$HEADER_FILE")
	if [ -n "$grep_output" ]; then
		found_definition=$(echo "$grep_output" | sed 's/\t\+/ /') # toglie le tabulazioni 
		found_definition=$(echo "$found_definition" | sed 's/\([, (]\)int \(\**\)[^, )*]*/\1int \2I/g') #sostituisce ad un nome di una variabile int I
		found_definition=$(echo "$found_definition" | sed 's/\([, (]\)char \(\**\)[^, )*]*/\1char \2C/g') #sostituisce ad un nome di una variabile char C
		found_definition=$(echo "$found_definition" | sed 's/\([, (]\)void \(\**\)[^, )*]*/\1void \2V/g') #sostituisce ad un nome di una variabile void V
		found_definition=$(echo "$found_definition" | sed 's/\([, (]\)size_t \(\**\)[^, )*]*/\1size_t \2S_T/g') #sostituisce ad un nome di una variabile size_t S_T
		if diff <(echo "$found_definition") <(echo -e "$2") > /dev/null; then
			:
		else
			echo "[ERROR] wrong definition of $1:"
			diff <(echo "$found_definition") <(echo -e "$2")
		fi
	fi
}

is_rigth_def "ft_isalpha" "int ft_isalpha(int I);"
is_rigth_def "ft_isdigit" "int ft_isdigit(int I);"
is_rigth_def "ft_isalnum" "int ft_isalnum(int I);"
is_rigth_def "ft_isascii" "int ft_isascii(int I);"
is_rigth_def "ft_isprint" "int ft_isprint(int I);"
is_rigth_def "ft_strlen" "size_t ft_strlen(const char *C);"
is_rigth_def "ft_memset" "void *ft_memset(void *V, int I, size_t S_T);"
is_rigth_def "ft_bzero" "void ft_bzero(void *V, size_t S_T);"
is_rigth_def "ft_memcpy" "void *ft_memcpy(void *V, const void *V, size_t S_T);"
is_rigth_def "ft_memmove" "void *ft_memmove(void *V, const void *V, size_t S_T);"
is_rigth_def "ft_strlcpy" "size_t ft_strlcpy(char *C, const char *C, size_t S_T);"
is_rigth_def "ft_strlcat" "size_t ft_strlcat(char *C, const char *C, size_t S_T);"













#PRIMA IMPLEMENTAZIONE
# grep_output=$(grep "ft_strlen" ../libft.h)

# if [ -n "$grep_output" ]; then
# 	if diff <(grep "ft_strlen" ../libft.h | sed 's/(char \*[^, )]*/(char */')  <(echo -e "size_t\tft_strlen(char *);") > /dev/null; then
# 		:
# 	else
# 		echo "[ERROR] wrong definition of ft_strenl"
# 		diff <(grep "ft_strlen" ../libft.h | sed 's/(char \*[^, )]*/(char */')  <(echo -e "size_t\tft_strlen(char *);")
# 	fi
# fi
