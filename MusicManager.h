#pragma once

#include <vector>
#include <iostream>
#include <fstream>

#define _WIN32_WINNT 0x0400
#include <windows.h>
#include <atlstr.h>

#include <fstream>
#include <cassert>
#include "picojson.h"
#include <Windows.h>

using namespace std;

//�y�Ȃ̊�{�f�[�^���Ǘ�
//�f�[�^��json�`���̃t�@�C����ǂݍ���(picojson�g�p)
//�t�H���_���̓ǂݍ��݂͕ύX�̗]�n�L
class MusicManager
{
public:
	MusicManager();
	~MusicManager();

	//1�ȕ��̃f�[�^�\����
	typedef struct Item {
		string music_name;//�Ȗ�
		string artist;//�A�[�e�B�X�g
		int level[3];//���x��
		int easy_color[7];//�ȉ�3�s�̓v���C�Ŏg�p����F�̎��
		int normal_color[7];
		int hard_color[7];
		float preview[2];//�Ȏ����̍ۂ̊J�n�ƏI���I�t�Z�b�g
	};

	void DataLoding();

	const Item& getItem(int i);//�ȃf�[�^
	const int getItemNumber();//�Ȑ�
	const string& getFolderList(int i);//�t�H���_���̈ꗗ

private:
	static vector<string> m_folder_list;//�t�H���_�����X�g�i�Ȗ��j
	static vector<Item> item;//�ȃf�[�^
};

