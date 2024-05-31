//67.二进制求和

//让两个字符串等长补0，单独处理最高位
class Solution{
public:
	string addBinary(string a,string b){
		int alen = a.size();
		int blen = b.size();

		while(alen < blen){
			a = '0' + a;
			alen++;
		}
		while(alen > blen){
			b = '0' + b;
			blen++;
		}

		for (int i = alen - 1; i > 0 ; i--){
			a[i] = a[i] - '0' + b[i];
			if (a[i] >= '2'){
				a[i] = (a[i] - '0') % 2 + '0';
				a[i-1] = a[i-1] + 1;
			}
		}
		a[0] = a[0] -'0' + b[0];
		if (a[0] >= '2'){
			a[0] = (a[0] - '0') % 2 + '0';
			a = '1' + a;
		}
		return a;
	}
};
