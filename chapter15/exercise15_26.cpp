#include"exercise15_26.h"

int main()
{
	Quote q1;
	Quote q2;
	Bulk_quote bq1;
	Bulk_quote bq2;
	Quote* pq1 = &q1;
	Disc_quote* dqp1 = &bq1;
	Bulk_quote* bqp1 = &bq1;

	q2 = q1;
	q2 = std::move(q1);
	Quote q3(q2);
	Bulk_quote bq3(bq2);
}