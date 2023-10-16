  #include "shell.h"
 
  /* For the Cd funcion*/
  /* SO, what happens when the user types CD*/

  void type_cd(char *args)
  {/* If the user does not pass any argument*/
    if (args == NULL)
    {
      char *go_home = getenv("HOME");

      if (go_home == NULL)
      {
        perror("cd: HOME environment variable is not set\n");
      }
      else
      {
        /* Take the user home */
        if (chdir(go_home != 0))
        {
          perror("could not change directory");
        }
      }
    }
    else
    {
      /* If the user adds an argument*/
      if (chdir(args) != 0)
          {
              perror("could not change directory");
          }
    }
  }

  void func_exit(void)
  {
    printf("\nExiting shell.....\n");
    /* Before exiting, it can sleep*/
    sleep(2);
    exit(0); /*exited succressfully here sha*/
  }

/*env prints the current  current environment*/


  int _env(info_t *info)
  {
    print_list_str(info->env);
    return(0);
  }