/*
 *  PolyVertex.cpp
 *  TAU
 *
 *  Created by Ivan Safrin on 3/14/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "PolyVertex.h"

using namespace Polycode;

Vertex::Vertex() : Vector3(0,0,0) {
	texCoord = new Vector2(0,0);	
	normal = new Vector3(0,0,0);
	useVertexColor = false;
}

Vertex::Vertex(float pos_x, float pos_y, float pos_z, float nor_x, float nor_y, float nor_z) : Vector3(pos_x, pos_y, pos_z) {
	normal = new Vector3(nor_x, nor_y, nor_z);
	texCoord = new Vector2(0,0);
	useVertexColor = false;
	restPosition.set(pos_x, pos_y, pos_z);
}

Vertex::Vertex(float pos_x, float pos_y, float pos_z, float nor_x, float nor_y, float nor_z, float u, float v): Vector3(pos_x, pos_y, pos_z) {
	normal = new Vector3(nor_x, nor_y, nor_z);
	texCoord = new Vector2(u,v);
	useVertexColor = false;
	restPosition.set(pos_x, pos_y, pos_z);	
}

Vertex::Vertex(float x, float y, float z) : Vector3(x,y,z) {
	texCoord = new Vector2(0,0);
	normal = new Vector3(0,0,0);
	useVertexColor = false;
	restPosition.set(x, y, z);
}

Vertex::Vertex(float x, float y, float z, float u, float v) : Vector3(x,y,z) {
	texCoord = new Vector2(u,v);	
	normal = new Vector3(0,0,0);
	useVertexColor = false;
	restPosition.set(x, y, z);
}

void Vertex::addBoneAssignment(unsigned int boneID, float boneWeight) {
	BoneAssignment *newBas = new BoneAssignment();
	newBas->boneID = boneID;
	if(boneWeight > 1)
		boneWeight = 1;
	if(boneWeight < 0)
		boneWeight = 0;
		
	newBas->weight = boneWeight;
	boneAssignments.push_back(newBas);
}

void Vertex::setNormal(float x, float y, float z) {
	normal->x = x;
	normal->y = y;
	normal->z = z;	
}

void Vertex::normalizeWeights() {
	float allWeights = 0;
//	if(boneAssignments.size() == 1)
//		if(boneAssignments[0]->weight < 1)
//			return;
			
	for(int i =0 ;i < boneAssignments.size(); i++) {
		allWeights += boneAssignments[i]->weight;
	}
	
	for(int i =0 ;i < boneAssignments.size(); i++) {
		boneAssignments[i]->weight *= 1.0f/allWeights;
	}	
}

int Vertex::getNumBoneAssignments() {
	return boneAssignments.size();
}

BoneAssignment *Vertex::getBoneAssignment(unsigned int index) {
	return boneAssignments[index];
}

Vertex::~Vertex() {

}

Vector2 *Vertex::getTexCoord() {
	return texCoord;
}

void Vertex::setTexCoord(float u, float v) {
	texCoord->x = u;
	texCoord->y = v;
}