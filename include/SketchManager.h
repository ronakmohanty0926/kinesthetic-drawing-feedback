#pragma once

#include <queue>
#include <deque>
#include "Core.h"
#include "Renderer.h"
#include "Curve.h"
#include "Mesh.h"
#include "MeshRenderer.h"
#include "HapticsEventManager.h"

#define MODE_IDLE 0
#define MODE_SKETCH 1
//#define MODE_TRANSLATION 1
//#define MODE_ROTATION 2
#define UNDO 2
#define REDO 3

namespace midl {
	class Mesh;

	class ABCSketchManager
	{
	private:
		Shader colorShader, textureShader;
		int mode;
		float trailElasticity, Zdistance, Xdistance, Ydistance, planeCenter[3];
		float curr_stylus[3], prev_stylus[3], displacement[3], translation[3], cursor[3], _pivot[3], angle , axis[3], matrix[9];
			
		bool isCurrStytlusSketching;
		bool isPrevStytlusSketching;
		

		float minZ, maxZ;
		clock_t start, end;
		double time_elapsed;
		float mindeviation;

		

		vector<Tuple3f>meshvert;
		vector<Tuple3f>meshedge;
		vector<Tuple3f>edges;
		vector<Tuple3f>vertices;
		vector<Tuple3f>points;//ellipse
		Tuple3f vertex;

		vector<Curve3> Sketch;
		vector<Curve3> Traj;

		deque<Curve3>Undo;		

		vector<int> currentMode;

		vector<Tuple3f>sty;
		vector<Tuple3f>hapsty;

		void DrawCurve(Curve3 &C);
		void RenderSampleShape();
		void DrawShadow(Curve3 &C);
		void DrawStylusShadow();
		void DrawPlaneShadow(float width, float height, float *center);
		//void RenderGrid();
		void RenderSketch();

		void UpdateStylus(float *stylus);
		void UpdateHapticStylus(float *stylus);
		void UpdateSketch();
		void SortSketchZ();
	
		GLuint materialID;

		//Deviation vector
		vector<float> min_deviation;
		vector<Tuple2i> meshEdges;
		float RMS;
	
	public:
		//char *userID;

		ABCSketchManager();
		~ABCSketchManager();

		vector<clock_t>stylusmov;
		vector<clock_t>hapticstylusmov;

		Curve3 c;
		Mesh *meshEvent;
		int undoPress;
		int redoPress;
		string option;
		float planeAngle;

		void InitShaders();
		void Render();

		void UpdatePointToPlaneDist();
		//void ReadMesh(const char*fName);
		//void DrawRefMesh();

		bool SketchOn();
		bool SketchOff();
		bool isSketchOn;
		//bool RotationOn();
		//bool TranslationOn();
		//void ManipulationOff();	
				
		//float SetPlaneCenter(float *newCenter);
		//float SetPivot(float *pivot);
	
		int Update();
		int Listen(float *stylus);
		int HapListen(float *stylus);
		int count, shapeIdentity;
		int shapeCountsquare,shapeCountcircle, shapeCountsine, shapeCountcusp, shapeCount;
		string userID, shapeName, shapeIteration, shapesize;

		bool needForce = false;
		bool shapeCounts(int shape);
		bool isNewShape();
		bool isShapeVisible;
		bool CheckHapticsForce();
		bool SetHaptics();
		bool UndoSketch();
		bool RedoSketch();
		string PlaneFeedback();

		void ComputeError();
		bool SaveLog();
		bool SaveSketchData();
		//bool SaveMeshData();
		bool SaveMetric();

	};
}