#pragma once

#include "DisplayableObject.h"
#include <string>

class Text : public DisplayableObject {

private:

	std::string m_text = "PlaceHolder";
	bool m_editable = false;

	int m_x; // x pos of drawn string
	int m_y; // y pos of drawn string
	int m_s; // size of drawn string
	int m_cap; // char limit of string

public:

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, bool editable);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, bool editable);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s, int CAP);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s, bool editable);

	Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s, int CAP, bool editable);

	bool setText(std::string text); // return bool to know if text can be set. This is so we cant ignore the text width cap (m_cap)

	std::string getText();

	virtual void virtDraw() override;

	virtual void virtKeyDown(int iKeyCode) override;

};

