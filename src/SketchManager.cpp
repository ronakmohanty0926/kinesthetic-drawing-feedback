#include "SketchManager.h"
#include "Renderer.h"

using namespace midl;

void ABCSketchManager::DrawCurve(Curve3 &C)
{	
	//glColor3fv(Blue3f);	
	float p1[3], p2[3];
	for (int i = 1; i < C.GetNumVertices(); i++)
	{	
	
		C.GetVertex(i - 1, p1);
		C.GetVertex(i, p2);		

		p1[2] = 0.0;
		p2[2] = 0.0;
	/*	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glLineWidth(5);		
		glBegin(GL_LINES);
		/*float r = maxZ - minZ;
		float c1, c2;
		c1 = 1 - (0.3*((p1[2] - minZ) / r) + 0.5);
		c2 = 1 - (0.3*((p2[2] - minZ) / r) + 0.5);*/
		glColor3f(0.54,0.0 , 0.0);
		glVertex3f(p1[0], p1[1], p1[2]);
		//glColor3f(c2, c2, c2);
		glVertex3f(p2[0], p2[1], p2[2]);
		glEnd();	
		//glDisable(GL_BLEND);
	}
}

void ABCSketchManager::RenderSampleShape()
{
	
		float center[] = { 0.0, 0.0, -2.5 };
		float color[] = { 0.0, 0.54, 0.0 };
		//Square
		if (shapeIdentity == 1 && shapeCountsquare < 5)
			{


			//Sketch.clear();
			
			shapeName = "Square";
			vertices.clear();
			edges.clear();
			//shapeName = "Square";
			glDisable(GL_DEPTH_TEST);
			glTranslatef(0.0, -0.3, 0.0);
			DrawQuad(1.0, 1.0, center, false, color);
			glEnable(GL_DEPTH_TEST);
			glTranslatef(0.0, 0.3, 0.0);

			float v1[] = { 0.5, 0.2, -2.5 };
			float v2[] = { 0.5, -0.8, -2.5 };
			float v3[] = { -0.5, -0.8, -2.5 };
			float v4[] = { -0.5, 0.2, -2.5 };

			Tuple3f p1;
			p1.data[0] = v1[0];
			p1.data[1] = v1[1];
			p1.data[2] = v1[2];
			vertices.push_back(p1);

			Tuple3f p2;
			p2.data[0] = v2[0];
			p2.data[1] = v2[1];
			p2.data[2] = v2[2];
			vertices.push_back(p2);

			Tuple3f p3;
			p3.data[0] = v3[0];
			p3.data[1] = v3[1];
			p3.data[2] = v3[2];
			vertices.push_back(p3);

			Tuple3f p4;
			p4.data[0] = v4[0];
			p4.data[1] = v4[1];
			p4.data[2] = v4[2];
			vertices.push_back(p4);

			float e1[3], e2[3], e3[3], e4[3];
			SubVectors3(v2, v1, e1);
			SubVectors3(v3, v2, e2);
			SubVectors3(v4, v3, e3);
			SubVectors3(v1, v4, e4);
				
			Tuple3f t1;
			t1.data[0] = e1[0];
			t1.data[1] = e1[1];
			t1.data[2] = e1[2];
			edges.push_back(t1);

			Tuple3f t2;
			t2.data[0] = e2[0];
			t2.data[1] = e2[1];
			t2.data[2] = e2[2];
			edges.push_back(t2);

			Tuple3f t3;
			t3.data[0] = e3[0];
			t3.data[1] = e3[1];
			t3.data[2] = e3[2];
			edges.push_back(t3);

			Tuple3f t4;
			t4.data[0] = e4[0];
			t4.data[1] = e4[1];
			t4.data[2] = e4[2];
			edges.push_back(t4);

				
		}

			//Circle
			else if (shapeIdentity == 2 && shapeCountcircle < 5)
			{
			
				shapeName = "Circle";
				vertices.clear();
				edges.clear();
				//shapeName = "Circle";
				glDisable(GL_DEPTH_TEST);
				glTranslatef(0.0, -0.3, 0.0);
				DrawCircle(center, 0.5, false, color, 1.0, 50);
				glEnable(GL_DEPTH_TEST);
				glTranslatef(0.0, 0.3, 0.0);

			}

			//Sine-Wave
			else if (shapeIdentity == 3 && shapeCountsine < 5)
			{
				shapeName = "Sine";
				vertices.clear();
				edges.clear();
				//shapeName = "Sine-Wave";
				glDisable(GL_DEPTH_TEST);
				
				
				glBegin(GL_LINE_STRIP);
				glColor3fv(color);
				for (int i = -360; i<361; i++)
				{
					float x = 0.3*PI*i/360;
					float y = 0.5*sin(PI*i / 360);
					glVertex3f(x,y,-2.5);

				}
				glEnd();
				glEnable(GL_DEPTH_TEST);

				Tuple3f p;
				for (int i = -360; i<361; i++)
				{
					p.data[0] = 0.3*PI*i / 360;
					p.data[1] = 0.5*sin(PI*i / 360);
					p.data[2] = -2.5;
					vertices.push_back(p);
				}

			}


			
			//Cusp
			else if (shapeIdentity == 4 && shapeCountcusp < 5)
			{
				shapeName = "Cusp";
				vertices.clear();
				edges.clear();
				//shapeName = "Cusp";
				glTranslatef(0.0, -0.2, 0.0);
				glDisable(GL_DEPTH_TEST);
				glBegin(GL_LINE_STRIP);
				glColor3fv(color);

				for (float i = 0; i<0.8; i=i+0.1)
				{
					float x = i;
					float y = sqrt(x*x*x);
					glVertex3f(x, y, -2.5);
				}
				glEnd();
				glBegin(GL_LINE_STRIP);
				glColor3fv(color);
				for (float i = 0; i<0.8; i = i + 0.1)
				{
					float x = i;
					float y = -sqrt(x*x*x);
					glVertex3f(x, y, -2.5);
				}
				glEnd();
				
				glEnable(GL_DEPTH_TEST);

				Tuple3f p;
				for (int i = 0; i<0.8; i++)
				{
					p.data[0] = i;
					p.data[1] = sqrt(i*i*i)-0.2;
					p.data[2] = -2.5;
					vertices.push_back(p);
				}

				for (int i = 0; i<0.8; i++)
				{
					p.data[0] = i;
					p.data[1] = -sqrt(i*i*i)-0.2;
					p.data[2] = -2.5;
					vertices.push_back(p);
				}

				glTranslatef(0.0, 0.2, 0.0);	
			}

			else if (shapeCountcusp > 4 && shapeCountcircle > 4 && shapeCountsine > 4 && shapeCountsquare > 4)
			{
				shapeIdentity = 0;
				cerr << "All trials are over" << endl;
			}

			
			////MultiPurpose
			//else if (count == 5)
			//{
			//	vertices.clear();
			//	edges.clear();
			//	shapeName = "MultiPurpose";
			//	glDisable(GL_DEPTH_TEST);


			//	glBegin(GL_LINE_STRIP);
			//	glColor3fv(Red3f);
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = PI*i / 1000;
			//		
			//		glVertex3f(-0.3 + 0.3*cos(theta), 0.3*sin(theta), -2.5);
			//	}
			//	glEnd();

			//	glBegin(GL_LINE_STRIP);
			//	glColor3fv(Red3f);
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = PI * i / 1000;

			//		glVertex3f(0.3+0.3*cos(theta), -0.3*sin(theta), -2.5);
			//	}
			//	glEnd();

			//	glBegin(GL_LINE_STRIP);
			//	glColor3fv(Red3f);
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = PI * i / 1000;

			//		glVertex3f(0.6*cos(theta), -0.6*sin(theta), -2.5);
			//	}
			//	glEnd();

			//	Tuple3f p;
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = PI * i / 1000;

			//		p.data[0] = 0.6*cos(theta);
			//		p.data[1] = -0.6*sin(theta);
			//		p.data[2] = -2.5;
			//		vertices.push_back(p);
			//	}

			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = PI * i / 1000;

			//		p.data[0] = 0.3 + 0.3*cos(theta);
			//		p.data[1] = 0.3*sin(theta);
			//		p.data[2] = -2.5;
			//		vertices.push_back(p);
			//	}

			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = PI * i / 1000;

			//		p.data[0] = -0.3 + 0.3*cos(theta);
			//		p.data[1] = 0.3*sin(theta);
			//		p.data[2] = -2.5;
			//		vertices.push_back(p);
			//	}
			//	glEnable(GL_DEPTH_TEST);

			//}

			//Stippled
			else if (count == 5)
			{
				vertices.clear();
				edges.clear();
				shapeName = "Stippled1H";
				glDisable(GL_DEPTH_TEST);
				glBegin(GL_LINES);
				glColor3fv(Red3f);
				for (float i = -1.0; i < 1.1; i=i+0.1)glVertex3f(i, 0.0, -2.5);				
				glEnd();
				glEnable(GL_DEPTH_TEST);

				Tuple3f edge;
				Tuple3f vertex1, vertex2;
				for (float i = -1.0; i < 1.1; i = i + 0.2)
				{
					float v1[] = { i, 0, -2.5 };
					float v2[] = { i + 0.1, 0, -2.5 };
					float v[3];
					vertex1.data[0] = v1[0];
					vertex1.data[1] = v1[1];
					vertex1.data[2] = v1[2];

					vertex2.data[0] = v2[0];
					vertex2.data[1] = v2[1];
					vertex2.data[2] = v2[2];

					vertices.push_back(vertex1);
					vertices.push_back(vertex2);

					SubVectors3(v2, v1, v);
					edge.data[0] = v[0];
					edge.data[1] = v[1];
					edge.data[2] = v[2];
					edges.push_back(edge);
				}
				
			}

			/*else if (count == 7)
			{
				vertices.clear();
				edges.clear();
				shapeName = "Stippled1V";
				glDisable(GL_DEPTH_TEST);
				glBegin(GL_LINES);
				glColor3fv(Red3f);
				for (float i = -0.75; i < 0.75; i = i + 0.1)glVertex3f(0.0, i, -2.5);
				glEnd();
				glEnable(GL_DEPTH_TEST);

				Tuple3f edge;
				Tuple3f vertex1, vertex2;
				for (float i = -1.0; i < 1.1; i = i + 0.2)
				{
					float v1[] = { 0.0, i, -2.5 };
					float v2[] = { 0.0, i + 0.1, -2.5 };
					float v[3];

					vertex1.data[0] = v1[0];
					vertex1.data[1] = v1[1];
					vertex1.data[2] = v1[2];

					vertex2.data[0] = v2[0];
					vertex2.data[1] = v2[1];
					vertex2.data[2] = v2[2];

					vertices.push_back(vertex1);
					vertices.push_back(vertex2);

					SubVectors3(v2, v1, v);
					edge.data[0] = v[0];
					edge.data[1] = v[1];
					edge.data[2] = v[2];
					edges.push_back(edge);
				}

			}

			else if (count == 8)
			{
				vertices.clear();
				edges.clear();
				shapeName = "Stippled2H";
				glDisable(GL_DEPTH_TEST);
				glBegin(GL_LINES);
				glColor3fv(Red3f);
				for (float i = -1.0; i < 1.0; i = i + 0.2)glVertex3f(i, 0.0, -2.5);
				glEnd();
				glBegin(GL_LINES);
				for (float i = -0.75; i < 0.75; i = i + 0.1)glVertex3f(i, 0.0, -2.5);
				glEnd();
				glEnable(GL_DEPTH_TEST);
				
				Tuple3f edge1, edge2;
				Tuple3f vertex1, vertex2;
				for (float i = -1.0; i < 1.2; i = i + 0.4)
				{
					float v1[] = { i, 0.0, 0.0, -2.5 };
					float v2[] = { i + 0.2, 0.0, -2.5 };
					float vmajor[3];

					vertex1.data[0] = v1[0];
					vertex1.data[1] = v1[1];
					vertex1.data[2] = v1[2];

					vertex2.data[0] = v2[0];
					vertex2.data[1] = v2[1];
					vertex2.data[2] = v2[2];

					vertices.push_back(vertex1);
					vertices.push_back(vertex2);

					SubVectors3(v2, v1, vmajor);
					edge1.data[0] = vmajor[0];
					edge1.data[1] = vmajor[1];
					edge1.data[2] = vmajor[2];
					edges.push_back(edge1);
				}
				for (float i = -1.0; i < 1.05; i = i + 0.4)
				{
					float v1[] = { i, 0.0, -2.5 };
					float v2[] = { i + 0.2, 0.0, -2.5 };
					float vminor[3];

					vertex1.data[0] = v1[0];
					vertex1.data[1] = v1[1];
					vertex1.data[2] = v1[2];

					vertex2.data[0] = v2[0];
					vertex2.data[1] = v2[1];
					vertex2.data[2] = v2[2];

					vertices.push_back(vertex1);
					vertices.push_back(vertex2);

					SubVectors3(v2, v1, vminor);
					edge2.data[0] = vminor[0];
					edge2.data[1] = vminor[1];
					edge2.data[2] = vminor[2];
					edges.push_back(edge2);
				}

			}

			else if (count == 9)
			{
				vertices.clear();
				edges.clear();
				shapeName = "Stippled2V";
				glDisable(GL_DEPTH_TEST);
				glBegin(GL_LINES);
				glColor3fv(Red3f);
				for (float i = -0.75; i < 0.95; i = i + 0.2)glVertex3f(0.0, i, -2.5);
				glEnd();
				glBegin(GL_LINES);
				for (float i = -0.5; i < 0.7; i = i + 0.1)glVertex3f(0.0, i, -2.5);
				glEnd();
				glEnable(GL_DEPTH_TEST);

				Tuple3f edge1, edge2;
				Tuple3f vertex1, vertex2;
				for (float i = -0.75; i < 0.95; i = i + 0.4)
				{
					float v1[] = { 0.0, i, -2.5 };
					float v2[] = { 0.0, i + 0.2,-2.5 };
					float vmajor[3];

					vertex1.data[1] = v1[1];
					vertex1.data[2] = v1[2];

					vertex2.data[0] = v2[0];
					vertex2.data[1] = v2[1];
					vertex2.data[2] = v2[2];

					vertices.push_back(vertex1);
					vertices.push_back(vertex2);

					SubVectors3(v2, v1, vmajor);
					edge1.data[0] = vmajor[0];
					edge1.data[1] = vmajor[1];
					edge1.data[2] = vmajor[2];
					edges.push_back(edge1);
				}
				for (float i = -0.5; i < 0.7; i = i + 0.2)
				{
					float v1[] = { 0.0, i, -2.5 };
					float v2[] = { 0.0, i + 0.1, -2.5 };
					float vminor[3];

					vertex1.data[1] = v1[1];
					vertex1.data[2] = v1[2];

					vertex2.data[0] = v2[0];
					vertex2.data[1] = v2[1];
					vertex2.data[2] = v2[2];

					vertices.push_back(vertex1);
					vertices.push_back(vertex2);

					SubVectors3(v2, v1, vminor);
					edge2.data[0] = vminor[0];
					edge2.data[1] = vminor[1];
					edge2.data[2] = vminor[2];
					edges.push_back(edge2);
				}

			}*/

			////Draw Two Circles
			//else if (count == 10)
			//{
			//	vertices.clear();
			//	edges.clear();
			//	shapeName = "Con-Circle";
			//	glDisable(GL_DEPTH_TEST);
			//	glTranslatef(0.0, -0.3, 0.0);
			//	glColor3fv(Red3f);
			//	DrawCircle(center, 0.7, false, Red3f, 1.0, 50);
			//	DrawCircle(center, 0.35, false, Red3f, 1.0, 50);
			//	glEnable(GL_DEPTH_TEST);
			//	glTranslatef(0.0, 0.3, 0.0);
			//}

			////2-SemiCircle
			//else if (count == 11)
			//{
			//	vertices.clear();
			//	edges.clear();
			//	shapeName = "2-SemiCircle";
			//	glDisable(GL_DEPTH_TEST);

			//	glBegin(GL_LINE_STRIP);
			//	glColor3fv(Red3f);
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = -PI * i / 1000;

			//		glVertex3f(-0.2-0.3*sin(theta), 0.3*cos(theta),  -2.5);
			//	}
			//	glEnd();

			//	glBegin(GL_LINE_STRIP);
			//	glColor3fv(Red3f);
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = -PI * i / 1000;

			//		glVertex3f(0.2+0.3*sin(theta), -0.3*cos(theta), -2.5);
			//	}
			//	glEnd();

			//	Tuple3f p1, p2;
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = -PI * i / 1000;

			//		p1.data[0] = -0.2 - 0.3*sin(theta);
			//		p1.data[1] = 0.3*cos(theta);
			//		p1.data[2] = -2.5;
			//		vertices.push_back(p1);
			//	}
			//	for (int i = 0; i<1000; i++)
			//	{
			//		float theta = -PI * i / 1000;

			//		p2.data[0] = 0.2 + 0.3*sin(theta);
			//		p2.data[1] = -0.3*cos(theta);
			//		p2.data[2] = -2.5;
			//		vertices.push_back(p2);
			//	}



				/*glBegin(GL_LINE_STRIP);
				glColor3fv(Red3f);
				for (int i = 0; i<1000; i++)
				{
					float theta = PI * i / 1000;

					glVertex3f(0.3 + 0.3*cos(theta), -0.3*sin(theta), -2.5);
				}
				glEnd();

				glBegin(GL_LINE_STRIP);
				glColor3fv(Red3f);
				for (int i = 0; i<1000; i++)
				{
					float theta = PI * i / 1000;

					glVertex3f(0.6*cos(theta), -0.6*sin(theta), -2.5);
				}
				glEnd();*/

				//glEnable(GL_DEPTH_TEST);

			//}
			
		}	



void ABCSketchManager::DrawShadow(Curve3 &C)
{
	glColor3f(0.5, 0.5, 0.5);

	float p1[3], p2[3];
	for (int i = 1; i < C.GetNumVertices(); i++)
	{
		C.GetVertex(i - 1, p1);
		C.GetVertex(i, p2);
		p1[2] = 0.0;
		p2[2] = 0.0;
		float planePt[] = { 0.0, -0.5, 0.0 };
		float dist1 = PointToPlaneDist(p1, planePt, Yaxis);
		float dist2 = PointToPlaneDist(p2, planePt, Yaxis);

		/*p1[0] -= dist1;*/ p1[1] -= dist1; //p1[2] -= dist1;
		/*p2[0] -= dist2;*/ p2[1] -= dist1; //p2[2] -= dist2;		  

		//glTranslatef(0.0, -0.6, 0.0);
		glLineWidth(4);
		/*glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glDisable(GL_DEPTH_TEST);
		glBegin(GL_LINES);
		glVertex3f(p1[0], p1[1], p1[2]);
		glVertex3f(p1[0], p2[1], p2[2]);
		glEnd();
		glEnable(GL_DEPTH_TEST);
		//glTranslatef(0.0, 0.6, 0.0);
	}
}

void ABCSketchManager::DrawStylusShadow()
{
	glColor3f(0.5, 0.5, 0.5);

	float stp1[3];
	float planePt1[] = { 0.0, -0.5, 0.0 };
	float dist1 = PointToPlaneDist(curr_stylus, planePt1, Yaxis);
	float dist2 = PointToPlaneDist(curr_stylus, planeCenter, Zaxis);
	stp1[0] = curr_stylus[0]; stp1[1] = curr_stylus[1]; stp1[2] = curr_stylus[2];
	stp1[1] -= dist1;
	//cerr << dist2 << endl;
	/*if (dist2 <= -0.1 && dist2 >= -0.4 && isSketchOn)
	{
		stp1[2] = curr_stylus[2] - (0.75*dist2);
	}*/
	//else (p1[2] = curr_stylus[2]);
	DrawSphere(stp1, 0.03f, Gray3f, 0.5F);	
}

void ABCSketchManager::DrawPlaneShadow(float width, float height, float *center)
{	
	float v1[] = { -0.5*width, -0.5*height, 0.0 };
	float v2[] = { 0.5*width, -0.5*height, 0.0 };
	float planePt[] = { 0.0, -0.5, 0.0 };
	float dist1 = PointToPlaneDist(v1, planePt, Yaxis);
	float dist2 = PointToPlaneDist(v2, planePt, Yaxis);

	v1[1] -= dist1;
	v2[1] -= dist2;

	glPushMatrix();
	glTranslatef(center[0], 0.0, center[2]);
	glLineWidth(4);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_LINES);	
	glVertex3f(v1[0], v1[1],v1[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glEnd();
	glTranslatef(center[0], 0.0, center[2]);
	glPopMatrix();
	glDisable(GL_BLEND);
}

//void ABCSketchManager::RenderGrid()
//{	
//	glTranslatef(0.0, -0.3, 0.0);	
//	DrawGrid(GRID_PLANE::ZX, 2.0f, 1, Gray3f);
//	glTranslatef(0.0, 0.3, 0.0);
//}

void ABCSketchManager::RenderSketch()
{
	bool isFilled = true;

	float center[] = { 0.0,0.0, -2.5 }; // offset is for visual only
	DrawQuad(6.0, 4.0, center, isFilled, Gray3f, 0.3f); //Background

	DrawPlaneShadow(1.0 ,0.6, planeCenter);	//TeamShadow
	DrawStylusShadow();	

	for (int i = 0; i < Sketch.size(); i++)DrawCurve(Sketch[i]);
	if(!Sketch.empty())	for (int i = 0; i < Sketch.size(); i++)DrawShadow(Sketch[i]);
	
	if (isPrevStytlusSketching && isCurrStytlusSketching)
	{
		mode = MODE_SKETCH;
		currentMode.push_back(mode);
		isFilled = true;
		bool isFilledFrame = false;
		glDisable(GL_DEPTH_TEST);

		float newOrigin[] = { 0.02,-0.31,0.25 };
		float planeNorm[] = { Zaxis[0], Zaxis[1],Zaxis[2]};

		float degAngle = -30.0;
		float radAngle = (PI / 180)*(degAngle);
		//cerr << "angle->" << radangle << endl;
		AxisAngle(Xaxis, radAngle, matrix);
		RotateVec3(planeNorm, matrix);
		Normalize3(planeNorm);
		
		//float temp = PointToPlaneDist(cursor, newOrigin, planeNorm);
		if (Zdistance < 0.15 && Zdistance > -0.1)cursor[2] = 0.0;
		else if (Zdistance < -0.1)cursor[2] -= 0.75*Zdistance;
					
		DrawSphere(cursor, 0.03f, Green3f, 1.0F);

		//glEnable(GL_DEPTH_TEST);

		DrawQuad(1.5, 0.8, planeCenter, isFilled, Blue3f, 0.1f);
		DrawQuad(1.5, 0.8, planeCenter, isFilledFrame, Blue3f, 0.3f);	
	}

	//else if (mode == MODE_ROTATION || mode == MODE_TRANSLATION)
	//{
	//	isFilled = true;
	//	bool isFilledFrame = false;
	//		
	//	DrawQuad(1.0, 0.6, planeCenter, isFilled, Blue3f, 0.1f);
	//	DrawQuad(1.0, 0.6, planeCenter, isFilledFrame, Blue3f, 0.3f);
	//	
	//

	//	glDisable(GL_DEPTH_TEST);
	//	DrawSphere(curr_stylus, 0.03f, Blue3f, 0.5F);
	//	glEnable(GL_DEPTH_TEST);
	//	/*glBegin(GL_LINES);	
	//	glVertex3fv(curr_stylus);
	//	glVertex3fv(_pivot);
	//	glEnd();*/
	//}
	else
	{
		mode = MODE_IDLE;
		currentMode.push_back(mode);
		isFilled = true;
		bool isFilledFrame = false;
		
		DrawQuad(1.5, 0.8, planeCenter, isFilled, Blue3f, 0.1f);
		DrawQuad(1.5, 0.8, planeCenter, isFilledFrame, Blue3f, 0.3f);
		
		glDisable(GL_DEPTH_TEST);
		DrawSphere(curr_stylus, 0.03f, Red3f, 0.5F);
		glEnable(GL_DEPTH_TEST);
	}
}

bool ABCSketchManager::isNewShape()
{
	Sketch.clear();
	return true;
}

void ABCSketchManager::UpdateStylus(float *stylus)
{
	clock_t x;
	x = clock();
	stylusmov.push_back(x);

	Tuple3f _stylus;
	
	prev_stylus[0] = curr_stylus[0];
	prev_stylus[1] = curr_stylus[1];
	prev_stylus[2] = curr_stylus[2];	

	curr_stylus[0] = stylus[0];
	curr_stylus[1] = stylus[1];
	curr_stylus[2] = stylus[2];	

	_stylus.data[0] = curr_stylus[0];
	_stylus.data[1] = curr_stylus[2];
	_stylus.data[2] = curr_stylus[1];

	sty.push_back(_stylus);
	
	displacement[0] = curr_stylus[0] - prev_stylus[0];
	displacement[1] = curr_stylus[1] - prev_stylus[1];
	displacement[2] = curr_stylus[2] - prev_stylus[2];	
}

void ABCSketchManager::UpdateHapticStylus(float *stylus)
{
	clock_t x;
	x = clock();
	hapticstylusmov.push_back(x);

	Tuple3f _hstylus;

	_hstylus.data[0] = stylus[0];
	_hstylus.data[1] = stylus[2];
	_hstylus.data[2] = stylus[1];

	hapsty.push_back(_hstylus);
}

void ABCSketchManager::UpdateSketch()
{	
		isPrevStytlusSketching = isCurrStytlusSketching;
		//cerr << "CStylus->" << curr_stylus[0] << " " << curr_stylus[1] << " " << curr_stylus[2] << endl;
		if (Zdistance < 0.28 && Zdistance > -0.25 && curr_stylus[1] > -0.5 && curr_stylus[1] < 0.5 && curr_stylus[0] > -0.8 && curr_stylus[0] < 0.8 && isSketchOn)
		{isCurrStytlusSketching = true;}
		else isCurrStytlusSketching = false;

		if (isCurrStytlusSketching && isPrevStytlusSketching && !Sketch.empty())
		{
			float p[] = { curr_stylus[0],curr_stylus[1],curr_stylus[2] };

			int lastID = (int)(Sketch[Sketch.size() - 1].GetNumVertices()) - 1;

			if (lastID > -1)
			{			
				float temp[3];
				Sketch[Sketch.size() - 1].GetVertex(lastID, temp);
				p[0] = trailElasticity*curr_stylus[0] + (1 - trailElasticity)*temp[0];
				p[1] = trailElasticity*curr_stylus[1] + (1 - trailElasticity)*temp[1];
			}
			else
			{
				p[0] = curr_stylus[0]; p[1] = curr_stylus[1];
			}
			p[2] = 0.0;
			Sketch[Sketch.size() - 1].AddPoint(p);
			
			cursor[0] = p[0];
			cursor[1] = p[1];
			cursor[2] = p[2];
			mode = MODE_SKETCH;
			currentMode.push_back(mode);
/*
			myfile2 << mode << " " << curr_stylus[0] << " " << curr_stylus[1] << " " << curr_stylus[2] << " " << stylusmov[stylusmov.size() - 1];
			myfile2 << endl;*/
		}
		else if (isCurrStytlusSketching && !isPrevStytlusSketching)
		{
				Curve3 c;
				Sketch.push_back(c);
				mode = MODE_IDLE;
				currentMode.push_back(mode);
		}				
	}


void ABCSketchManager::SortSketchZ()
{
	minZ = FLT_MAX;
	maxZ = -FLT_MAX;

	float p[3];
	for (int i = 0; i < Sketch.size(); i++)
	{
		for (int j = 0; j < Sketch[i].GetNumVertices(); j++)
		{
			Sketch[i].GetVertex(j, p);
			if (p[2] < minZ) minZ = p[2];
			if (p[2] > maxZ) maxZ = p[2];
		}
	}
}

ABCSketchManager::ABCSketchManager()
{
	trailElasticity = 0.5;
	angle = 0.0;
	count = 0;
	planeAngle = 0.0;

	isCurrStytlusSketching = false;
	isPrevStytlusSketching = false;	
	isShapeVisible = false;
	SketchOff();
	planeAngle = 0.0;
	planeCenter[0] = planeCenter[1] = planeCenter[2] = 0.0;
	
	undoPress = 0;
	redoPress = 0;	

	shapeCountsquare = 0;
	shapeCountcircle = 0;
	shapeCountsine = 0;
	shapeCountcusp = 0;
	shapeIdentity = 0;
	shapeCount = 0;
	/*shapeCountstippled1h = 0;
	shapeCountstippled1v = 0;
	shapeCountstippled2h = 0;
	shapeCountstippled2v = 0;
	shapeCount2circle = 0;
	shapeCount2semi = 0;*/

	//Tuple2i t;
	//t.data[0] = 0; t.data[1] = 1; //Edge 1
	//meshEdges.push_back(t);
	//t.data[0] = 1; t.data[1] = 3;//Edge 2
	//meshEdges.push_back(t);
	//t.data[0] = 2; t.data[1] = 3;//Edge 3
	//meshEdges.push_back(t);
	//t.data[0] = 0; t.data[1] = 2;//Edge 4
	//meshEdges.push_back(t);
	//t.data[0] = 4; t.data[1] = 6;//Edge 5
	//meshEdges.push_back(t);
	//t.data[0] = 6; t.data[1] = 7;//Edge 6
	//meshEdges.push_back(t);
	//t.data[0] = 7; t.data[1] = 5;//Edge 7
	//meshEdges.push_back(t);
	//t.data[0] = 5; t.data[1] = 4;//Edge 8
	//meshEdges.push_back(t);
	//t.data[0] = 4; t.data[1] = 0;//Edge 9
	//meshEdges.push_back(t);
	//t.data[0] = 6; t.data[1] = 2;//Edge 10
	//meshEdges.push_back(t);
	//t.data[0] = 7; t.data[1] = 3;//Edge 11
	//meshEdges.push_back(t);
	//t.data[0] = 5; t.data[1] = 1;//Edge 12
	//meshEdges.push_back(t);
}

ABCSketchManager::~ABCSketchManager()
{	
	trailElasticity = 0.5;
		Sketch.clear();		
		Traj.clear();

		isCurrStytlusSketching = false;
		isPrevStytlusSketching = false;
		isShapeVisible = false;
		SketchOff();

		planeCenter[0] = planeCenter[1] = planeCenter[2] = 0.0;	
		count = 0;

		shapeCountsquare = 0;
		shapeCountcircle = 0;
		shapeCountsine = 0;
		shapeCountcusp = 0;
		shapeIdentity = 0;
		shapeCount = 0;
	/*	shapeCountstippled1h = 0;
		shapeCountstippled1v = 0;
		shapeCountstippled2h = 0;
		shapeCountstippled2v = 0;
		shapeCount2circle = 0;
		shapeCount2semi = 0;*/
}

void ABCSketchManager::InitShaders()
{
	colorShader.Initialize(".//Shaders//diffuseShader.vert", ".//Shaders//diffuseShader.frag");
	textureShader.Initialize(".//Shaders//textureShader.vert", ".//Shaders//textureShader.frag");
}

//bool ABCSketchManager::RotationOn()
//{	
//	if (!Sketch.empty())
//	{
//		Curve3 t;
//		Traj.push_back(t);
//		mode = MODE_ROTATION;		
//		SortSketchZ();
//		return true;
//	}
//}

//void ABCSketchManager::ReadMesh(const char*fName)
//{
//	if (meshEvent != NULL)
//	{
//		meshEvent->DeleteMesh();
//		delete meshEvent;
//	}
//	meshEvent = new Mesh();
//	meshEvent->InitMesh();
//	meshEvent->FromPly((char*)fName);
//	meshEvent->TranslateTo(Origin);
//	//mesh->ScaleToUnitBox();
//	float xRng[] = { -0.5,0.5 }; float yRng[] = { -0.5, 0.5 }; float zRng[] = { -0.5, 0.5 };
//	float xLen = xRng[1] - xRng[0]; float yLen = yRng[1] - yRng[0]; float zLen = zRng[1] - zRng[0];
//
//	float newRng[] = { -0.12, 0.12 };
//	float Rng = newRng[1] - newRng[0];
//
//	for (int i = 0; i < meshEvent->GetNumVert(); i++)
//	{
//		float temp[3];
//		meshEvent->GetVertPosition(i, temp);
//		temp[0] = Rng*((temp[0] - xRng[0]) / xLen) + newRng[0];
//		temp[1] = Rng*((temp[1] - yRng[0]) / yLen) + newRng[0];
//		temp[2] = Rng*((temp[2] - zRng[0]) / zLen) + newRng[0];	
//		meshEvent->SetVertPosition(temp, i);
//	}
//
//}

//void ABCSketchManager::DrawRefMesh()
//{
//	DrawMesh((*meshEvent), Magenta3f, MESH_DISPLAY::SOLID_SMOOTH);
//}

void ABCSketchManager::UpdatePointToPlaneDist()
{
	float newmat[9];
	float newOrigin[] = { 0.02,-0.31,0.25 };	
	float planeNorm[] = { Zaxis[0], Zaxis[1], Zaxis[2] };

	float degAngle = -1*planeAngle;
	float radAngle = (PI / 180)*(degAngle);
	//cerr << "angle->" << radangle << endl;
	AxisAngle(Xaxis, radAngle, newmat);
	RotateVec3(planeNorm, newmat);
	Normalize3(planeNorm);

	Zdistance = PointToPlaneDist(curr_stylus, newOrigin, planeNorm);
	//cerr << "MDist->" << Zdistance << endl;	
}

bool ABCSketchManager::SketchOn()
{
	isSketchOn = true;
	cerr << "On" << endl;
	return isSketchOn;
}
bool ABCSketchManager::SketchOff()
{
	isSketchOn = false;
	return isSketchOn;
}

//void ABCSketchManager::ManipulationOff()
//{
//	mode = MODE_SKETCH;
//}

//bool ABCSketchManager::TranslationOn()
//{
//	mode = MODE_TRANSLATION;	
//	return true;
//}

bool ABCSketchManager::SetHaptics()
{
	needForce = true;
	return true;
}

bool ABCSketchManager::CheckHapticsForce()
{
	return needForce;
}

//float ABCSketchManager::SetPlaneCenter(float *newCenter)
//{
//	newCenter[0] = planeCenter[0];
//	newCenter[1] = planeCenter[1];
//	newCenter[2] = planeCenter[2];
//
//	return newCenter[3];
//}

//float ABCSketchManager::SetPivot(float *pivot)
//{
//	pivot[0] = _pivot[0];
//	pivot[1] = _pivot[1];
//	pivot[2] = _pivot[2];
//
//	return pivot[3];
//}

string ABCSketchManager::PlaneFeedback()
{
	return option;
}

bool ABCSketchManager::UndoSketch()
{
	if (!Sketch.empty())
	{
		mode = UNDO;
		currentMode.push_back(mode);
		undoPress++;

		Undo.push_back(Sketch[Sketch.size() - 1]);
		Sketch[Sketch.size() - 1].Clear();
		Sketch.erase(Sketch.begin()+Sketch.size()-1);
		return true;
	}
	else return false;
}

bool ABCSketchManager::RedoSketch()
{
	if (!Undo.empty())
	{
		mode = REDO;
		currentMode.push_back(mode);
		redoPress++;
		
		Curve3 newCrv;
		Undo.back().CopyTo(newCrv);
		Sketch.push_back(newCrv);
		DrawCurve(newCrv);
		Undo.back().Clear();
		Undo.erase(Undo.begin() + Undo.size()-1);
		return true;		
	}
	else return false;	
}

void ABCSketchManager::Render()
{

	RenderSampleShape();
	//Render the 3D Curves
	RenderSketch();

	//Render the 3D Depth Grid
	//RenderGrid();	


}

int ABCSketchManager::Update()
{
	UpdateSketch();	
	UpdatePointToPlaneDist();
	return mode;
}

int ABCSketchManager::Listen(float *stylus)
{
	UpdateStylus(stylus);
	return Update();
}

int ABCSketchManager::HapListen(float *stylus)
{
	UpdateHapticStylus(stylus);

	return 0;
}

void  ABCSketchManager::ComputeError()
{
	vector<float>deviation;

	for (int i = 0; i < Sketch.size(); i++)
	{
		for (int j = 0; j < Sketch[i].GetNumVertices(); j++)
		{
			float temp[3];
			Sketch[i].GetVertex(j, temp);

			if (shapeIdentity == 1) //|| count == 5)
			{
				for (int k = 0; k < edges.size(); k++)
				{
					Tuple3f t;
					t = edges[k];
					float dev = PointToLineDist3(temp, vertices[k].data, vertices[k + 1].data);
					deviation.push_back(dev);
				}

				//Find the closest edge
				int closest = -1; float tempDist = FLT_MAX;
				for (int j = 0; j < deviation.size(); j++)
				{
					if (deviation[j] < tempDist)
					{
						tempDist = deviation[j]; closest = j;
					}
				}
				//cerr << "closest edge->" << closest << endl;
				if (closest > -1) //Found closest edge
				{
					min_deviation.push_back(deviation[closest]);
					//skdeviation.push_back(deviation[closest]);
				}
				deviation.clear();
			}

			else if (shapeIdentity == 2)
			{
				float center[] = { 0.0,-0.3,-2.5 };
				//vector<float>tempdist;
				float _dev[3];
				SubVectors3(temp, center, _dev);
				float dev = Norm3(_dev) - 0.5;
				//cerr << "CircDev->" << dev << endl;
				//if (dev < 0)dev = -1 * dev;
				deviation.push_back(dev);
			}

		/*	else if (count == 10)
			{
				float center[] = { 0.0,0.0,-2.5 };
				vector<float>tempdist;
				float _dev1[3], _dev2[3];
				SubVectors3(temp, center, _dev1);
				SubVectors3(temp, center, _dev2);
				float dev1 = Norm3(_dev1) - 0.7;
				float dev2 = Norm3(_dev1) - 0.35;
				 if (dev1 < dev2)deviation.push_back(dev1);
				 else deviation.push_back(dev2);				
			}*/

			else if (shapeIdentity == 3 || shapeIdentity == 4 )
			{
				for (int k = 0; k < vertices.size(); k++)
				{
					float _dev[3];
					SubVectors3(temp, vertices[k].data, _dev);
					float dev = Norm3(_dev);
					deviation.push_back(dev);
				}
			}
		}
	}

	//Calculate the RMS error
	float numerator, denominator;
	numerator = 0.0;
	if (shapeIdentity == 1)// || count == 5 )
	{
		for (int i = 0; i < min_deviation.size(); i++)
		{
			//cerr << "mindevsize" << min_deviation.size();
			numerator += (min_deviation[i] * min_deviation[i]);
		}
		denominator = min_deviation.size();
		RMS = sqrt(numerator / denominator);
	}
	else if (shapeIdentity == 2 || shapeIdentity == 3 || shapeIdentity == 4 )
	{
		for (int i = 0; i < deviation.size(); i++)
		{
			//cerr << "devsize" << deviation.size();
			numerator += (deviation[i] * deviation[i]);
		}
		denominator = deviation.size();
		RMS = sqrt(numerator / denominator);
	}
	

	
	cerr << "Error->" << RMS << endl;	/*for (int d = 0; d < deviation.size(); d++)
										{
										if (!deviation.empty())
										{
										float numerator, denominator;
										numerator += NormSq3(deviation.data[d]);
										denominator = deviation.size();
										float RMS = sqrt(numerator / denominator);
										}
										}*/

}

bool ABCSketchManager::shapeCounts(int shape)
{
	if (shape == 1 && shapeCountsquare < 5)
	{
		shapeCountsquare++;
		shapeIteration = to_string(shapeCountsquare);
	}
	else if (shape == 2 && shapeCountcircle < 5)
	{
		shapeCountcircle++;
		shapeIteration = to_string(shapeCountcircle);
	}
	else if (shape == 3 && shapeCountsine < 5)
	{
		shapeCountsine++;
		shapeIteration = to_string(shapeCountsine);
	}
	else if (shape == 4 && shapeCountcusp < 5)
	{
		shapeCountcusp++;
		shapeIteration = to_string(shapeCountcusp);
	}
		
	/*	shapesize = "0";
	else if (count == 1) shapesize = "1";
	else if (count == 2) shapesize = "2";
	else if (count == 3) shapesize = "3";
	else if (count == 4) shapesize = "4";*/

	return true;
}
bool ABCSketchManager::SaveLog()
{
	if (!Sketch.empty())
	{
		ofstream myfile;
		myfile.open("User_" + userID + "_Log_" + shapeName + "_" + shapeIteration + ".txt");
		myfile << "Discontinuity->" << Sketch.size() << endl;
		myfile << "RMS Error->" << RMS << endl;
		time_elapsed = float(stylusmov[stylusmov.size() - 1] - stylusmov[0]) / CLOCKS_PER_SEC;
		myfile << "Time Elapsed->" << time_elapsed << " " << "secs" << endl;
		myfile << "Mode"<<"StyX" << " " << "StyY" << " " << "StyZ" << " " << "HapStyX" << " " << "HapStyY" << " " << "HapStyZ" << " " << "Depth"<<" "<<"Stylus_TimeStamp" << endl;
		for (int i = 0; i < currentMode.size(); i++)
		{
			/*string mode;
			if (currentMode[i] == -1) mode = 'Idle';
			else if (currentMode[i] == 0) mode = 'Skch';
			else if (currentMode[i] == 1) mode = 'Trns';
			else if (currentMode[i] == 2) mode = 'Rot';
			else if (currentMode[i] == 3) mode = 'Undo';
			else if (currentMode[i] == 4) mode = 'Redo';*/

			myfile << currentMode[i]<<" "<<sty[i].data[0] << " " << sty[i].data[1] << " " << sty[i].data[2] << " " << hapsty[i].data[0] << " " << hapsty[i].data[1] << " " << hapsty[i].data[2] << " " << Zdistance<<" "<< stylusmov[i] << endl;

		}
		
	}
	return true;
}

bool ABCSketchManager::SaveSketchData()
{
	if (!Sketch.empty())
	{
		ofstream myfile;
		myfile.open("User_" + userID + "_Sketch_" + shapeName + "_" + shapeIteration + ".txt");
		int t = 0;

		for (int i = 0; i < Sketch.size(); i++)
		{
			myfile << "Sketch->" << i << endl;
			for (int j = 0; j < Sketch[i].GetNumVertices(); j++)
			{
				float temp[3];
				Sketch[i].GetVertex(j, temp);
				myfile << temp[0] << " " << temp[1] << " " << temp[2] << endl;
			}
		}
	}
	return true;
}

//bool ABCSketchManager::SaveMeshData()
//{
//	if (!Sketch.empty())
//	{
//		ofstream myfile;
//		myfile.open("Global_MeshData.txt");
//		int t = 0;
//		myfile << "X" << " " << "Y" << " " << "Z" << endl;
//		for (int i = 0; i < meshvert.size(); i++)
//		{
//			myfile << meshvert[i].data[0] << " " << meshvert[i].data[1] << " " << meshvert[i].data[2] << endl;
//		}
//	}
//	return true;
//}

bool ABCSketchManager::SaveMetric()
{
	if (!Sketch.empty())
	{
		ComputeError();
		ofstream myfile;
		myfile.open("User_" + userID + "_Metric_" + shapeName + "_" + shapesize +  ".txt");
		myfile << "Discontinuity->" << Sketch.size() << endl;
		myfile << "RMS Error->" << RMS << endl;
		time_elapsed = float(stylusmov[stylusmov.size() - 1] - stylusmov[0]) / CLOCKS_PER_SEC;
		myfile << "Time Elapsed->" << time_elapsed << " " << "secs" << endl;
		/*for (int i = 0; i < 9; i++)
		{
			myfile << "matrix" << "[" << i << "]" << "->" << matrix[i] << endl;
		}*/
		/*for (int j = 0; j < min_deviation.size(); j++)
		{
			myfile << "Minimum Deviations" << ":[" << j << "]->" << min_deviation[j] << endl;
		}*/

		
	}
	return true;
}

