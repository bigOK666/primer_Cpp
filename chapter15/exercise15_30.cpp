#include"exercise15_30_Basket.h"

int main()
{
	Basket b;
	b.add_item(Quote("Book1", 20));
	b.add_item(Bulk_quote("Book2", 10, 5, 0.2));
	b.add_item(Quote("Book1", 20));
	b.add_item(Bulk_quote("Book2", 10, 5, 0.2));
	b.add_item(Bulk_quote("Book2", 10, 5, 0.2));
	b.add_item(Bulk_quote("Book2", 10, 5, 0.2));
	b.add_item(Bulk_quote("Book2", 10, 5, 0.2));
	b.add_item(Bulk_quote("Book2", 10, 5, 0.2));

	b.total_receipt(std::cout);

}