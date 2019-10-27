#include <iostream>

#include <sstream> //Used for fourth function

#include <vector> //Used for fourth function

using namespace std;



int CharacterCounter(string Sentence)   //The function that is used for finding the number of characters
{
	int c = 0;               //c used as a counter
	for (int i = 0; Sentence[i]; i++)   //loop until the end of string
	{
		if (Sentence[i] != ' ')       //excluding spaces
			c++;           //incrementing count of characters
	}
	return c;
}


int WordCounter(string Sentence)   //The function that is used for finding the number of words
{
	int c = 1;              
	for (int i = 0; Sentence[i]; i++)   
	{
		if (Sentence[i] == ' ' && Sentence[i + 1] != ' ')   //Checking the condition for a word
			c++;          
	}
	return c;
}


int ProperWordsCounter(string Sentence) //The function that is used to count number of proper words (Capital letters)
{

	int c = 0;
	for (int i = 1; i < Sentence.length(); i++)   //if space is found, and next character is the first charater of next word, if it is capital then increase the count
	{
		if (Sentence[i] == ' ' && isupper(Sentence[i + 1]))
			c++;
	}

	return c;

}



int ConsecutiveLetterCounter(string Sentence) //The function that counts words with consecutive letters
{
	int c = 0;
	vector<string> result;  	//Vectore used to store the words
	istringstream iss(Sentence); //splitting the string by a whitespace

	for (string Sentence; iss >> Sentence;)
		result.push_back(Sentence); 	

	for (string Sentence : result) 
	{
		for (int i = 1; i < Sentence.length(); i++) //If two letters consecutively are equal then the counter increments
		{ 
			if (Sentence[i] == Sentence[i - 1])
			{
				c++;

				break;
			}
		}
	}
	return c;
}

int main() {

	string Sentence;

	cout << "Enter the senctence you want analyzed: ";

	getline(cin, Sentence);

	cout << "\nNumber of characters: " << CharacterCounter(Sentence);  //Calling first function

	cout << "\nNumber of words in the sentence: " << WordCounter(Sentence); //Calling second function

	cout << "\nNumber of proper words (any word that starts with a capital letter except the first word) : " << ProperWordsCounter(Sentence); //Calling third function

	cout << "\nNumber of words that contain two consecutive letters: " << ConsecutiveLetterCounter(Sentence) << "\n"; //Calling fourth function

	return 0;
}

