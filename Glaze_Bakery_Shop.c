
#include <stdio.h>
#include <math.h>
#include <ctype.h> //To be able to use toupper

void greeting(); //welcome the user to the glaze bakery shop
void order(double *balance); //user will make a purchase
void viewAccount(double *balance); //display current account balance of user
void transaction(double *balance, double price); //transaction with user account
void reload(double *balance); //reload your account balance
void displayMenu(); //display beverage/food options and prices

int main ()
{
  double bal = 0.00;
  double *ptr_bal = &bal; //assigning the adress of bal to the pointer ptr_bal

  greeting();

  char option;
  while (option != 'E') //loop until exit is pressed
  {
    printf("Please select one of the following options.\n");
    printf("O: Order\n");
    printf("V: View Account Summary\n");
    printf("D: Display Menu\n");
    printf("R: Reload Account\n");
    printf("E: Exit\n");
    printf("Please select what you would like to do.\n");


    scanf(" %c", &option);

    printf("Option Selected: %c\n", option);
    printf("\n");

    option = toupper(option);

    switch(option)
    {
      case 'O':
        order(ptr_bal);
        break;
      case 'V':
        printf("You selected View Account Summary Option.\n");
        viewAccount(ptr_bal);
        break;
      case 'D':
        printf("You selected Display Menu Option.\n");
        displayMenu();
        break;
      case 'R':
        printf("You Selected Reload Account Option.\n");
        reload(ptr_bal);
        break;
    }

  }
  printf("Thank you for visiting Knightro's Coffee Shop!\n");
  printf("You have $%.2lf in your account.\n", *ptr_bal);
  printf("Have a great day!\n");
  printf("Go Knights! Charge On!\n");


  return 0;
}

void greeting() //user defined function for greetig message
{
  printf("Welcome to Glaze Bakery Shop!\n");
  printf("Indulge in the delightful world of sweet sensations at Glaze Bakery.\n");
  printf("Our ovens are fired up, and our talented bakers are crafting moments of joy, one delicious treat at a time.\n");
  printf("From freshly baked pastries to heavenly cakes, each bite is a celebration of flavors and craftsmanship.\n");
  printf("At Glaze, we blend passion with the finest ingredients to create a symphony for your taste buds.\n");
  printf("Thank you for choosing Glaze Bakery. Savor the sweetness, and let every bite tell a story!\n");
  printf("How can we help you today?\n");
}

void order(double *balance) //user defined function for the order
{

    int order_opt; //variable that holds the input of what the user would like to purchase
    printf("You have selected the Order Option.\n");
    displayMenu();
    printf("What would you like today? ");
    scanf("%d", &order_opt);
    printf("Option Selected: %d\n", order_opt);

    if (order_opt == 1)
    {
      double rate1 = 3.53;
      printf("Carrot Cake has been selected. Total cost is: $3.53\n");
      transaction(balance, rate1); //function call that passes a reference and a value
    }
    else if (order_opt == 2)
    {
      double rate2 = 4.20;
      printf("Cheesecake has been selected. Total cost is: $4.20\n");
      transaction(balance, rate2);
    }
    else if (order_opt == 3)
    {
      double rate3 = 3.13;
      printf("Blueberry Lemon Cake has been selected. Toatal cost is: $3.13\n");
      transaction(balance, rate3);
    }
    else if (order_opt == 4)
    {
      double rate4 = 4.12;
      printf("Oreo Cupcake has been selected. Toatal cost is: $4.12\n");
      transaction(balance, rate4);
    }
    else if (order_opt == 5)
    {
      double rate5 = 3.99;
      printf("Chocolate Cake has been selected. Toatal cost is: $3.99\n");
      transaction(balance, rate5);
    }
    else if (order_opt == 6)
    {
      double rate6 = 4.99;
      printf("Lemon Piehas been selected. Toatal cost is: $4.99\n");
      transaction(balance, rate6);
    }
    else if (order_opt == 7)
    {
      double rate7 = 5.03;
      printf("Brownies has been selected. Toatal cost is: $5.03\n");
      transaction(balance, rate7);
    }
    else if (order_opt == 8)
    {
      double rate8 = 1.50;
      printf("Bottle Water has been selected. Toatal cost is: $1.50\n");
      transaction(balance, rate8);
    }

}

void viewAccount(double *balance)
{
  printf("Here is your current account balance.\n");
  printf("You have $%.2lf in your account.\n", *balance);
  return;
}

void transaction(double *balance, double price)
{
  printf("Beginning Transaction Process.\n");

  while (*balance < price) //loops if your balance is lower then the price
  {
    printf("You do not have enough in your account.\n");
    printf("Please reload your account balance.\n");
    reload(balance); //function call to reload your balance to break loop
  }
  if (*balance >= price) // if statement to complete transaction
  {
    printf("Your account balance before official transaction: $%.2lf\n", *balance);
    printf("Billing $%.2lf to your account.\n", price);
    printf("Transaction was successfull!\n");
    *balance -= price;
    printf("You have now $%.2lf in your account balance.\n", *balance);

  }
}

void reload(double *balance)
{
  int rel_option;

  while (1)
  {
    printf("How much would you like to reload to your account?\n");
    printf("1: $1.00\n");
    printf("2: $5.00\n");
    printf("3: $10.00\n");
    scanf("%d", &rel_option);
    printf("Option Selected: %d\n", rel_option);

    if (rel_option == 1)
    {
      printf("$1.00 has been added to your account successfully!\n");
      *balance += 1.00;
      break;

    }
    if (rel_option == 2)
    {
      printf("$5.00 has been added to your account successfully!\n");
      *balance += 5.00;
      break;
    }
    if (rel_option == 3)
    {
      printf("$10.00 has been added to your account successfully!\n");
      *balance += 10.00;
      break;
    }
    else
    {
      printf("Please enter valid option;\n");
      continue; //will enter the while loop once again
    }
  }

}

void displayMenu()
{
  printf("Here are the options!\n");
  printf("1. Carrot Cake                           $3.53\n");
  printf("2. Cheesecake                            $4.20\n");
  printf("3. Blueberry Lemon Cake                  $3.13\n");
  printf("4. Oreo Cupcake                          $4.12\n");
  printf("5. Chocolate Cake                        $3.99\n");
  printf("6. Lemon Pie                             $4.99\n");
  printf("7. Brownies                              $5.03\n");
  printf("8. Bottle Water                          $1.50\n");
  return;

}
