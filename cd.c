#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) {


  // χρειάζεται να ελεχθεί αν λειτουργεί από το καινούργιο κέλυφος
  // και να επιστρέφει τις καινουγιες αλλαγές στη διεργασία πατέρα που την κάλεσε
  
  setenv ("OLDPWD", getenv("PWD") , 1);
  setenv ("PWD", argv[1] , 1);
  
  return 0;
}
