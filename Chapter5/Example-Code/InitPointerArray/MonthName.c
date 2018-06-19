/*
 *	Date: 2018-06-19
 *	Page 113 of K&R
 *	By Rivers
*/

char *month_name(int i)
{
	static char *name[13] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December"
	};

	return (i < 1 || i > 12) ? name[0] : name[i];
}

