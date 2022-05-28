//============================================================================
// Name        : Code_Jam_2022_Qualification_Round.cpp
// Author      : Serhat Alkan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <filesystem>
#include <sstream>
#include <iomanip>

class UserIO 
{

  private:

	std::vector<std::string> vectorInputLines;
	std::vector<std::string> vectorOutputLines;

  public:

	const std::vector<std::string>& getVectorInputLines() const 
	{
		return vectorInputLines;
	}

	void setVectorOutputLines(const std::vector<std::string> &vOutputLines) 
	{
		this->vectorOutputLines = vOutputLines;
	}

	void readInput() 
	{
		int caseNum, a, b;
		std::string line;

		std::cin >> caseNum;
		line = std::to_string(caseNum);
		this->vectorInputLines.push_back(line);

		for(int i = 0; i < caseNum; i++)
		{
			std::cin >> a; 
			std::cin >> b;
        	line = std::to_string(a) + ' ' + std::to_string(b);
			this->vectorInputLines.push_back(line);
		}		
	}

	void writeOutput() 
	{
		std::ofstream file;

		for (std::vector<std::string>::iterator it = this->vectorOutputLines.begin(); it != this->vectorOutputLines.end(); it++) 
		{
			std::cout << *it << std::endl;
		}
	}
};

enum PunchCardRowType 
{   
    PUNCHCARROW_BOUND_TYPE = 0,
    PUNCHCARROW_DATA_TYPE = 1
};

class PunchCardRow
{
  public:

    std::string symbols;

	PunchCardRow(PunchCardRowType type, int nRow, int nColumn)
	{
		std::stringstream ss;

		for (unsigned int unI = 0; unI < ((2 * nColumn) + 1); unI++)
		{
			if (type == PUNCHCARROW_BOUND_TYPE)
			{
				char c = ((nRow == 0) && (unI < 2)) ? '.' : ((unI % 2) ? '-' : '+');
				ss << c;
			}
			else
			{
				char c = ((nRow == 1) && (unI < 1)) ? '.' : ((unI % 2) ? '.' : '|');
				ss << c;
			}
		}

		setStrSymbols(ss.str());
	}

	~PunchCardRow()
	{

	}

	const std::string getStrSymbols() const
	{
		return this->symbols;
	}

	void setStrSymbols(const std::string& symbols)
	{
		this->symbols = symbols;
	}

	void addOutputText(std::vector<std::string>& par_vectorStrOutputText)
	{
		par_vectorStrOutputText.push_back(getStrSymbols());
	}

	void print()
	{
		std::cout << getStrSymbols() << std::endl;
	}
};

class PunchCard
{
  public:

    std::vector<PunchCardRow *> rows;

	PunchCard(int nRow, int nColumn)
	{
		PunchCardRow *punchCardRow = nullptr;

		rows.clear();

		for (unsigned int unI = 0; unI < nRow; unI++)
		{
			punchCardRow = new PunchCardRow(PUNCHCARROW_BOUND_TYPE, (2 * unI), nColumn);
			rows.push_back(punchCardRow);
			punchCardRow = new PunchCardRow(PUNCHCARROW_DATA_TYPE, ((2 * unI) + 1), nColumn);
			rows.push_back(punchCardRow);
		}

		punchCardRow = new PunchCardRow(PUNCHCARROW_BOUND_TYPE, (2 * nRow), nColumn);
		rows.push_back(punchCardRow);
	}

	~PunchCard()
	{
		for (unsigned int unI = 0; unI < rows.size(); unI++)
		{
			PunchCardRow *punchCardRow = rows[unI];
			delete punchCardRow;
		}

		rows.clear();
	}

	const std::vector<PunchCardRow *> getVectorRows() const
	{
		return this->rows;
	}

	void SetVectorRows(const std::vector<PunchCardRow *>& rows)
	{
		this->rows = rows;
	}

	void addOutputText(std::vector<std::string>& par_vectorStrOutputText)
	{
		for (std::vector<PunchCardRow*>::iterator it = rows.begin(); it != rows.end(); ++it)
		{
			PunchCardRow *punchCardRow = *it;
			punchCardRow->addOutputText(par_vectorStrOutputText);
		}
	}

	void print(int par_nCaseNumber)
	{
		std::cout << "Case #" << par_nCaseNumber << ":" << std::endl;

		for (std::vector<PunchCardRow*>::iterator it = rows.begin(); it != rows.end(); ++it)
		{
			PunchCardRow *punchCardRow = *it;
			punchCardRow->print();
		}
	}
};

class Parse
{
  private:

	std::vector<std::string> split(std::string const &str, char delim) 
	{
		std::vector<std::string> tokens;
		size_t start;
		size_t end = 0;

		while ((start = str.find_first_not_of(delim, end)) != std::string::npos) 
		{
			end = str.find(delim, start);
			tokens.push_back(str.substr(start, end - start));
		}

		return tokens;
	}

  public:

    std::vector<PunchCard*> punchCards;
    std::vector<std::string> vectorOutputText;

	Parse()
	{
		punchCards.clear();
		vectorOutputText.clear();
	}
	
	~Parse(){
	
		for (unsigned int unI = 0; unI < punchCards.size(); unI++)
		{
			delete punchCards[unI];
		}

		punchCards.clear();
		vectorOutputText.clear();
	}

	void exec(const std::vector<std::string> &vInputLines) 
	{
		std::vector<int> likes;
		int numOfPunchCard = stoi(vInputLines.front());

		for (unsigned int unI = 0; unI < numOfPunchCard; unI++)
		{
			int nRow = stoi(split(vInputLines.at(unI + 1), ' ')[0]);
			int nColumn = stoi(split(vInputLines.at(unI + 1), ' ')[1]);

			PunchCard *punchCard = new PunchCard(nRow, nColumn);
			punchCards.push_back(punchCard);
		}

		for (unsigned int unI = 0; unI < punchCards.size(); unI++)
		{
			vectorOutputText.push_back("Case #" + std::to_string(unI + 1) + ":");
			punchCards[unI]->addOutputText(vectorOutputText);
		}
	}
};

int main(int argc, char** argv) 
{
	UserIO *myUserIO = new UserIO();
	myUserIO->readInput();

	Parse *parserpP = new Parse();
	parserpP->exec(myUserIO->getVectorInputLines());
	
	myUserIO->setVectorOutputLines(parserpP->vectorOutputText);
	myUserIO->writeOutput();

	delete myUserIO;
	delete parserpP;

	return 0;
}
