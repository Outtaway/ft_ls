/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_limits.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpshenyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:02:29 by kpshenyc          #+#    #+#             */
/*   Updated: 2018/11/14 15:02:36 by kpshenyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_LIMITS_H
# define TYPE_LIMITS_H

# define __64BIT

# define _INT_MAX 2147483647
# define _INT_MIN -2147483648

# ifdef __64BIT
#  define _LONG_MAX 9223372036854775807
#  define _LONG_MIN -9223372036854775808
# endif

# ifdef __32BIT
#  define _LONG_MAX 2147483647
#  define _LONG_MIN -2147483648
# endif

# define _LLONG_MAX 9223372036854775807
# define _LLONG_MIN -9223372036854775808

# define _UINT_MAX 4294967295
# define _UINT_MIN 0

# ifdef __64BIT
#  define _ULONG_MAX 18446744073709551615
#  define _ULONG_MIN 0
# endif

# ifdef __32BIT
#  define _ULONG_MAX 4294967295
#  define _ULONG_MIN 0
# endif

# define _ULLONG_MAX 18446744073709551615
# define _ULLONG_MIN 0

# define _SCHAR_MAX 127
# define _SCHAR_MIN -128

# define _SHRT_MAX 32767
# define _SHRT_MIN -32768

# ifdef __64BIT
#  define _ULONG_MAX 18446744073709551615
# endif

# ifdef __32BIT
#  define _ULONG_MAX 4294967295
# endif

# ifdef __64BIT
#  define _ULLONG_MAX 18446744073709551615
# endif

# ifdef __32BIT
#  define _ULLONG_MAX 18446744073709551615
# endif

# define _UCHAR_MAX 255

# define _USHRT_MAX 65535

#endif
