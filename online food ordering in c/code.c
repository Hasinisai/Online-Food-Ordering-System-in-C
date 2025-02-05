#include <stdio.h>
#include <string.h>

// Define the structure for food items
typedef struct {
    int id;
    char name[100];
    float price;
} FoodItem;

// Function to display the menu
void displayMenu(FoodItem menu[], int size) {
    printf("Menu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rs. %.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}

// Function to place an order
void placeOrder(FoodItem menu[], int size) {
    int id, quantity;
    float total = 0;
    printf("Enter the id of the item you want to order: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (menu[i].id == id) {
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            total = menu[i].price * quantity;
            printf("Total: Rs. %.2f\n", total);
            return;
        }
    }
    printf("Item not found!\n");
}

// Function to display orders
void displayOrders(FoodItem orders[], int size) {
    printf("Your Orders:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rs. %.2f\n", orders[i].id, orders[i].name, orders[i].price);
    }
}

int main() {
    // Define the menu items
    FoodItem menu[] = {
        {1, "Pizza", 200.0},
        {2, "Burger", 150.0},
        {3, "Sandwich", 100.0}
    };

    // Define the orders array
    FoodItem orders[10];
    int orderSize = 0;

    int choice;
    while (1) {
        printf("1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Display Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu(menu, 3);
                break;
            case 2:
                placeOrder(menu, 3);
                // Add the order to the orders array
                orders[orderSize++] = menu[0]; // For simplicity, we're adding the first menu item
                break;
            case 3:
                displayOrders(orders, orderSize);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
