#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> SplitLogFile(const string& FileName, size_t maxPartSize){

	vector<string> partFiles;
	string outputPrefix = "log_part";
    ifstream inFile(FileName, ios::binary | ios::ate);
    if(inFile.is_open()){

		size_t fileSize = inFile.tellg();
		inFile.seekg(0, ios::beg);

		cout << "Размер исходного файла: " << fileSize << " байт\n";
		cout << "Максимальный размер части: " << maxPartSize << " байт\n";

		int partNum = 1;
		size_t totalWritten = 0;

		while(totalWritten < fileSize){
			ostringstream filenameStream;
			filenameStream << outputPrefix << partNum << ".txt";
			string outputFile = filenameStream.str();

			ofstream outFile(outputFile, ios::binary);
			if (!outFile.is_open()){
				cerr << "Ошибка: не удалось создать файл " << outputFile << endl;
				break;
			}
			size_t bytesWritten = 0;
			string line;
			while (bytesWritten < maxPartSize && totalWritten < fileSize){

				size_t lspos = inFile.tellg();

				if(!getline(inFile, line)){
					break;
				}
				size_t lepos = inFile.tellg();

				size_t lineSize = lepos - lspos;

				if(bytesWritten + lineSize > maxPartSize && bytesWritten > 0){
					inFile.seekg(lspos);
					break;
				}

				outFile << line << endl;
				bytesWritten += lineSize;
				totalWritten += lineSize;
			}

			outFile.close();
			partFiles.push_back(outputFile);

			if(inFile.peek() == EOF) break;

			partNum++;
		}

		inFile.close();

		std::cout << "Файл успешно разделен на " << partFiles.size() << " частей\n";

    }else{
    	cerr << "Ошибка: не удалось открыть файл " << FileName << endl;
    }
    return partFiles;
}

void CreateIndexFile(const vector<string>& partFiles, const string& FileName){
	string indexFile = "log_index.txt";
	ofstream index(indexFile);
    if (!index.is_open()) {
        std::cerr << "Ошибка: не удалось создать индексный файл " << indexFile << std::endl;
        return;
    }

    index << "Исходный файл: " << FileName << "\n";
    index << "Количество частей: " << partFiles.size() << "\n\n";
    index << "Список частей:\n";

    for (size_t i = 0; i < partFiles.size(); i++){
        ifstream file(partFiles[i], ios::binary | ios::ate);
        index << "Часть " << i + 1 << ": " << partFiles[i] << " (" << file.tellg() << " байт)" << endl;
        file.close();
    }
    index.close();
    cout << "Создан индексный файл: " << indexFile << endl;
}

int main(){
	string FileName = "application.log";
    ifstream inFile(FileName);
    if (inFile.is_open()){
		size_t maxPartSize = 1 * 1024;
		vector<std::string> partFiles = SplitLogFile(FileName, maxPartSize);

		if (!partFiles.empty()) {
			CreateIndexFile(partFiles, FileName);
		}
    }else{
    	cerr << "Ошибка! Не удалось открыть файл" << endl;
    }

    return 0;
}
