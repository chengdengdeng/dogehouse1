//12.整数转罗马数字

//1.朴素模拟
const pair<int,string> valueSymbols[] = {
		{1000,"M"},
		{900,"CM"},
		{500,"D"},
		{400,"CD"},
		{100,"C"},
		{90,"XC"},
		{50,"L"},
		{40,"XL"},
		{10,"X"},
		{9,"IX"},
		{5,"V"},
		{4,"IV"},
		{1,"I"},
};

class Solution{
public:
	string intToRoman(int num){
		string roman;
		for (const auto &[valueSymbols,symbol] : valueSymbols) {
			while(num >= value){
				num -= value;
				roman += symbol;
			}
			if (num == 0){
				break;
			}
		}
	}
};

//硬编码数字(耍赖法）
const string thousands[] = {" ","M","MM","MMM"};
const string hundreds[] ={" ","C","CC","CCC","CD","D","DC","DCCC","CM"};
const string tens[] = {" ","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const string ones[] = {" ","I","II","III","IV","V","VI","VII","VIII","IX"};

class Solution{
public:
	string intToRoman(int num){
		return thousand[num / 1000] + hundreds[num % 1000/100] + tens[num % 100/10] + ones[num%10];
	}
};