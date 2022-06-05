#include "PreProcessor.h"

PreProcessor::PreProcessor(std::vector<Transaction*> transactions)
{
	m_transactions = transactions;
}

std::vector<std::vector<Transaction*>> PreProcessor::CreateBatches()
{
	std::vector<std::vector<Transaction*>> batches;

	while (!m_transactions.empty())
	{
		std::vector<Transaction*> new_batch;
		Transaction *t = PopFrontTransaction();
		new_batch.push_back(t);
		t->Execute();

		// If we start with a DEPOSIT, keep grabbing until we get a TXN that is constrained
		while (t->TransactionType() == DEPOSIT_TYPE)
		{
			t = PopFrontTransaction();
			new_batch.push_back(t);
			t->Execute();
		}

		Account* a = t->GetFromAccount();
		
		bool keep_going = true;

		std::vector<Transaction*>::iterator it = m_transactions.begin();

		while (keep_going && it != m_transactions.end())
		{
			Transaction *t2 = (*it);

			if ((t2->TransactionType() == DEPOSIT_TYPE && !t2->ToAccount(a)) || 
				(t2->FromAccount(a) && t2->IsValid()))
			{// Its either a deposit to a different account or a valid TXN from our target account, so add it to this batch
				new_batch.push_back(t2);
				t2->Execute();
				it = m_transactions.erase(it);
			}
			else if (!t2->FromAccount(a))
			{// A TXN from another account, don't add it to the batch but we can keep looking for more TXNs to add
				it++;
				continue;
			}
			else
			{// An invalid TXN or a Deposit to our target account, we need to start a new batch
				keep_going = false;
			}
		}

		batches.push_back(new_batch);
	}

	// Rollback all of the transactions
	std::vector<std::vector<Transaction*>>::iterator i_outer = batches.end();
	while (i_outer != batches.begin())
	{
		--i_outer;
		std::vector<Transaction*>::iterator i_inner = i_outer->end();

		while (i_inner != i_outer->begin())
		{
			--i_inner;
			(*i_inner)->Rollback();
		}
	}

	return batches;
}

Transaction* PreProcessor::PopFrontTransaction()
{
	Transaction* t = ViewFrontTransaction();
	m_transactions.erase(m_transactions.begin());
	return t;
}

Transaction* PreProcessor::ViewFrontTransaction()
{
	Transaction* t = m_transactions.front();
	return t;
}