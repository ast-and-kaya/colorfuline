#include "SoundValue.h"



SoundValue::SoundValue()
{
}


SoundValue::~SoundValue()
{
}

void SoundValue::setFilePass(string pass) {


	//ヘッダー読み込み
	typedef struct {
		char            riff[4];          // RIFFヘッダ
		unsigned int    fileSize;         // ファイルサイズ - 8
		char            wave[4];          // WAVEヘッダ
		unsigned char   fmt[4];           // fmt チャンク
		int   fmtSize;                   // fmt チャンクのバイト数
		unsigned short  id;        // フォーマットID
		unsigned short  channels;         // チャンネル数
		unsigned int    samplingRate;     // サンプリングレート
		unsigned int    bytesPerSec;      // データ速度 (Byte/sec)
		unsigned short  blockSize;       // ブロックサイズ
		unsigned short  bitsPerSample;    // サンプルあたりのビット数
	} wav;

	wav data;
	FILE *fp;
	fopen_s(&fp, pass.c_str(), "rb");
	fread(&data, sizeof(wav), 1, fp);
	fclose(fp);
	//printf("識別子             : %s\n", data.riff);
	//printf("ファイルサイズ     : %d[bytes]\n", data.fileSize + 8);
	//printf("ファイル形式       : %s\n", data.wave);
	//printf("fmt                : %s\n", data.fmt);
	//printf("fmtチャンクサイズ  : %ld[bytes]\n", data.fmtSize);
	//printf("format ID(PCM=1)   : %d (0x%04x)\n", data.id, data.id);
	//printf("チャンネル数       : %d (モノラル=1 ステレオ=2)\n", data.channels);
	//printf("サンプリングレート : %d[Hz]\n", data.samplingRate);
	//printf("データ速度         : %d[bytes/sec]\n", data.bytesPerSec);
	//printf("ブロックサイズ     : %d[bytes]\n", data.blockSize);
	//printf("量子化ビット数     : %d[bit]\n", data.bitsPerSample);
	//printf("再生時間           : %.2f[sec]\n", (double)(data.fileSize + 8) / data.bytesPerSec);


	//全てのデータを読み込み
	FILE * fp2;
	fopen_s(&fp2, pass.c_str(), "rb");

	fseek(fp2, 0, SEEK_END);
	const int bin_size = ftell(fp2);
	fseek(fp2, 0, 0);

	vector<unsigned char> buff_s(bin_size);
	fread(&buff_s[0], sizeof(char), bin_size, fp2);
	buff = buff_s;

	fclose(fp2);

	//ヘッダー削除
	while (true)
	{
		string s = "";
		for (int i = 0; i < 4; i++) s += buff[i];
		if (s == "data")
		{
			for (int i = 0; i < 8; i++) buff.erase(buff.begin());
			break;
		}
		buff.erase(buff.begin());
	}
	//printf("%02x",buff[0]);

	ms_data = data.bytesPerSec / 1000; // 1/1000秒のデータ量

}

int SoundValue::getValue(float timing,int rl) {//rl 0:右 1:左

	long len_pos = round(timing * 1000) * ms_data;
	//cout << "buff_size" << buff.size() << flush;
	//cout << ":"<<len_pos << endl;

	int large = 0;
	for (int back = 0; back < 100; back++)
	{
		string s = "";
		//2進数に変換
		int fi = (rl == 1) ? 1 : 3;
		for (int i = fi; i >= fi-1; i--)
		{
			int len = (len_pos + i) + 4 * back;
			for (int j = 7; j >= 0; j--)
			{
				if (buff[len] >= pow(2, j)) {
					buff[len] -= pow(2, j);
					s += '1';
				}
				else {
					s += '0';
				}
			}
		}
		//cout << s << endl;

		//10進数に変換
		int v = 0;
		bool pm = (s[0] == '0') ? true : false;//正負判定
		for (int j = 1; ; j++)
		{
			v += (s[j] == '1') ? 1 : 0;
			v *= 2;

			if (j == 15)//ループ出
			{
				v /= 2;
				break;
			}
		}
		if (!pm) {
			v *= -1;
			v += 32768;
		}
		//cout << v << endl;

		large = (large < v) ? v : large;
	}

	if (rl == 0)//右
		{
		store_r.push_back(large);
		if (store_r.size() > 5) store_r.erase(store_r.begin());
		sound_value_r = accumulate(store_r.begin(), store_r.end(), 0) / store_r.size();//平均化
																		   
		//cout << sound_value << endl;

		return sound_value_r;
	}

	if (rl == 1)//左
	{
		store_l.push_back(large);
		if (store_l.size() > 5) store_l.erase(store_l.begin());
		sound_value_l = accumulate(store_l.begin(), store_l.end(), 0) / store_l.size();//平均化

		//cout << sound_value << endl;

		return sound_value_l;
	}

}