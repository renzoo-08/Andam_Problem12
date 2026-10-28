#include <stdio.h>

int main()
{
    int numCustomers, containers;
    int i;
    int totalContainers = 0;
    int price = 30;
    int discountMin = 10;
    float discountRate = 0.05;
    float subtotal, discount, payable;
    float totalDiscounts = 0.0;
    float totalRevenue = 0.0;

    do {
        printf("===============================\n");
        printf("How many customers will be served? ");
        if (scanf("%d", &numCustomers) != 1) {
            scanf("%*s");  
            numCustomers = 0;
            printf("===============================\n");
        }
        if (numCustomers <= 0)

            printf("Invalid input. Enter a whole number greater than 0.\n");
            printf("===============================\n");
    } while (numCustomers <= 0);

    for (i = 1; i <= numCustomers; i++) {

        do {
            printf("===============================\n");
            printf("Customer %d - number of containers purchased: ", i);
            if (scanf("%d", &containers) != 1) {
                scanf("%*s"); 
                containers = -1;
            }
            if (containers <= 0)
                printf("Invalid input. Enter a whole number greater than 0.\n");
        } while (containers <= 0);

        subtotal = containers * price;
        discount = 0.0;

        if (containers >= discountMin)
            discount = subtotal * discountRate;

        payable = subtotal - discount;
        
        printf("Customer %d amount payable: P%.2f\n\n", i, payable);

        totalContainers += containers;
        totalDiscounts += discount;
        totalRevenue += payable;
    }

    printf("=========== SUMMARY ===========\n");
    printf("Total containers sold: %d\n", totalContainers);
    printf("Total discounts:       P%.2f\n", totalDiscounts);
    printf("Total revenue:         P%.2f\n", totalRevenue);
    printf("===============================");
    return 0;
}