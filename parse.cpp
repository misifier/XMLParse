#include <iostream>  
#include "tinyxml2.h"
#include <stdio.h>
#include <string>



using namespace tinyxml2;
using namespace std;



char* Error[21] = {
	"XML_SUCCESS",
	"XML_NO_ATTRIBUTE",
	"XML_WRONG_ATTRIBUTE_TYPE",
	"XML_ERROR_FILE_NOT_FOUND",
	"XML_ERROR_FILE_COULD_NOT_BE_OPENED",
	"XML_ERROR_FILE_READ_ERROR",
	"UNUSED_XML_ERROR_ELEMENT_MISMATCH",
	"XML_ERROR_PARSING_ELEMENT",
	"XML_ERROR_PARSING_ATTRIBUTE",
	"UNUSED_XML_ERROR_IDENTIFYING_TAG",
	"XML_ERROR_PARSING_TEXT",
	"XML_ERROR_PARSING_CDATA",
	"XML_ERROR_PARSING_COMMENT",
	"XML_ERROR_PARSING_DECLARATION",
	"XML_ERROR_PARSING_UNKNOWN",
	"XML_ERROR_EMPTY_DOCUMENT",
	"XML_ERROR_MISMATCHED_ELEMENT",
	"XML_ERROR_PARSING",
	"XML_CAN_NOT_CONVERT_TEXT",
	"XML_NO_TEXT_NODE",
	"XML_ERROR_COUNT"
};
XMLError ret;



void read_xml(XMLElement *surface, XMLElement *std_surface);
XMLError Load_Xml(char* filepath);

char* configCpuType[] = {
"./main/board_for_gsl6152s/silead_config.xml", "./main/board_for_gsl6152s01/silead_config.xml", "./main/board_for_gsl6153/silead_config.xml",
"./main/board_for_gsl6153E_6101A02/silead_config.xml", "./main/board_for_gsl6153E_6101A12/silead_config.xml", "./main/board_for_gsl6153s01/silead_config.xml",
"./main/board_for_gsl6161e/silead_config.xml", "./main/board_for_gsl6163e135_6101A/silead_config.xml", "./main/board_for_gsl6163e135_6101B/silead_config.xml",
"./main/board_for_gsl6163e135_6101C/silead_config.xml", "./main/board_for_gsl6165b_6101A/silead_config.xml", "./main/board_for_gsl6165b_6101B/silead_config.xml",
"./main/board_for_gsl6165b_6101C/silead_config.xml", "./main/board_for_gsl6172e/silead_config.xml", "./main/board_for_gsl6172e01/silead_config.xml",
"./main/board_for_gsl6172e31/silead_config.xml", "./main/board_for_gsl6185e_6101A/silead_config.xml", "./main/board_for_gsl6185e_6101B/silead_config.xml",
"./main/board_for_gsl6185e_6101C/silead_config.xml", "./main/board_for_gsl6275e_6101A/silead_config.xml", "./main/board_for_gsl6275e_6101B/silead_config.xml",
"./main/board_for_gsl6275e_6101C/silead_config.xml"
};//22��

char* algxmlPath[] = { 
"./main/board_for_gsl6152s/silead_param.xml", "./main/board_for_gsl6152s01/silead_param.xml", "./main/board_for_gsl6153/silead_param.xml",
"./main/board_for_gsl6153E_6101A02/silead_param.xml", "./main/board_for_gsl6153E_6101A12/silead_param.xml", "./main/board_for_gsl6153s01/silead_param.xml",
"./main/board_for_gsl6161e/silead_param.xml", "./main/board_for_gsl6163e135_6101A/silead_param.xml", "./main/board_for_gsl6163e135_6101B/silead_param.xml",
"./main/board_for_gsl6163e135_6101C/silead_param.xml", "./main/board_for_gsl6165b_6101A/silead_param.xml", "./main/board_for_gsl6165b_6101B/silead_param.xml",
"./main/board_for_gsl6165b_6101C/silead_param.xml", "./main/board_for_gsl6172e/silead_param.xml", "./main/board_for_gsl6172e01/silead_param.xml",
"./main/board_for_gsl6172e31/silead_param.xml", "./main/board_for_gsl6185e_6101A/silead_param.xml", "./main/board_for_gsl6185e_6101B/silead_param.xml",
"./main/board_for_gsl6185e_6101C/silead_param.xml", "./main/board_for_gsl6275e_6101A/silead_param.xml", "./main/board_for_gsl6275e_6101B/silead_param.xml",
"./main/board_for_gsl6275e_6101C/silead_param.xml"
};//22��



int main()
{
	int mode = 0;
	int max_xml_count = sizeof(algxmlPath) / sizeof(algxmlPath[0]);
	char filepath[256];


	while (1)
	{
		printf("��ѡ��ģʽ��\n  1:��⵱ǰ·��xml��ʽ\n  2:�������·��xml��ʽ\n");
		fflush(stdin);
		scanf("%d", &mode);
		if (mode == 1)
		{
			int i = 0;
			system("pause");
			//printf("����XML������\n");
			//fflush(stdin);
			//scanf("%d", &max_xml_count);
			while (i<max_xml_count)
			{
				//load config
				ret = Load_Xml(algxmlPath[i]);
				printf("current file:%s\n", configCpuType[i], i);
				system("pause");
				//load param
				Load_Xml(algxmlPath[i]);
				printf("current file:%s\n", algxmlPath[i], i);
 				system("pause");
				i++;
			}
		}

		else if (mode == 2)
		{
			printf("������XML·������֧������·����:\n");
			fflush(stdin);
			gets(filepath);
			system("pause");
			Load_Xml(filepath);
			printf("current file:%s\n", filepath);
			system("pause");
		}
		else if (mode == 3)
		{

		}
		else
		{
			printf("�Ƿ�ָ����������룡\n");
	    }
	
	}

}

void read_xml(XMLElement *surface, XMLElement *std_surface)
{
	const XMLAttribute *attr1;
	const XMLAttribute *attr2;
	int line_num = 0;
	while (surface && std_surface)
	{

		attr1 = surface->FirstAttribute();//��ȡ��һ������ֵ  
		attr2 = std_surface->FirstAttribute();
		while (attr1)
		{
			cout << " " << attr1->Value();
			attr1 = attr1->Next(); //��ȡ��һ������ֵ 
		}
		while (attr2)
		{
			cout << " " << attr2->Value();
			attr2 = attr2->Next();
		}
		const char* content1 = surface->GetText(); //��ȡ�ڵ������
		const char* content2 = std_surface->GetText();

		if (content1)
		{
			cout << " " << content1 << endl;
		}
		if (content2)
		{
			cout << " " << content2 << endl;
		}

		XMLElement *surface1 = surface->FirstChildElement(); //�鿴��ǰ�����Ƿ����ӽڵ�  
		XMLElement *surface2 = std_surface->FirstChildElement();
		const char* text_surface1 = NULL;
		const char* text_surface2 = NULL;
		if (surface1 != NULL && surface2 != NULL)
		{
			 text_surface1 = surface1->GetText();
			 text_surface2 = surface2->GetText();
		}
		else if ((surface1 == NULL && surface2 != NULL) || (surface1 != NULL && surface2 == NULL))
		{
			line_num = surface->GetLineNum();
			printf("error!one xml has more childelement\n");
			system("pause");
		}
		else
		{
			 text_surface1 = NULL;
			 text_surface2 = NULL;
		}
		if (text_surface1 != NULL && text_surface2 != NULL)
		{
			if (*text_surface1 == *text_surface2)
			{
				read_xml(surface1, surface2);//�ݹ����  
			}
			else
			{
				line_num = surface->GetLineNum();
				printf("Error!in line %d,lost some param!\n", line_num);
				system("pause");
				return;
			}
		}
		else
		{
			read_xml(surface1, surface2);
		}

		surface = surface->NextSiblingElement();//��ǰ�������һ���ڵ�  
		std_surface = std_surface->NextSiblingElement();
		if (surface != NULL && std_surface != NULL)
		{
			text_surface1 = surface->GetText();
			text_surface2 = std_surface->GetText();
		}
		else if ((surface == NULL && std_surface != NULL) || (surface != NULL && std_surface == NULL))
		{
			if (surface)
			{
				line_num = surface->GetLineNum();
			}
			if (std_surface)
			{
				line_num = std_surface->GetLineNum();
			}
			printf("error!one xml less some param in line%d\n",line_num);
			system("pause");
			return;
		}
		else
		{
			text_surface1 = NULL;
			text_surface2 = NULL;
		}
		if (text_surface1 != NULL && text_surface2 != NULL)
		{
			if (*text_surface1 == *text_surface2)
			{
			}
			else
			{
				line_num = surface->GetLineNum();
				printf("error!in line param isn't same\n", line_num);
			}
		}

	}
}

XMLError Load_Xml(char* filepath)
{
	tinyxml2::XMLDocument mydocument; //����xml����  
	tinyxml2::XMLDocument std_document;

	ret = mydocument.LoadFile(filepath); //����xml�ļ�  
	if (ret != 0)
	{
		printf("ERROR!%s\n", Error[ret]);
		return ret;
	}
	ret = std_document.LoadFile("./main/board_for_gsl6275e_6101C/silead_param.xml");
	if (ret != 0)
	{
		printf("Standard XML Error!%s\n", Error[ret]);
		return ret;
	}

	XMLElement *rootElement = mydocument.RootElement(); //��ȡ���ڵ�  
	XMLElement *surface = rootElement->FirstChildElement();//��ȡ��һ��ֵΪvalue���ӽڵ� Ĭ��Ϊ���򷵻ص�һ���ڵ�  

	XMLElement *std_rootElement = std_document.RootElement();
	XMLElement *std_surface = std_rootElement->FirstChildElement();
	read_xml(surface,std_surface);
	//cin.get();
	return XML_SUCCESS;
}